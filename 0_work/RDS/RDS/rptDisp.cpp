//project defines
#include "RDS_project.h"

//current form
#include "rptDisp.h"
#include "RDSreport.h"

//error message gobal table
#include "ErrMsg.h"

extern struct Encode_Cause_Equpiment_type RPT_all_Cause[CUASE_RPT_TABLE_SIZE];
extern struct Encode_Equpiment_type RPT_all_Equip[EQUIP_RPT_TABLE_SIZE];
extern char* ModelNames[MAX_HOT_TUV_MODELS];
extern char* PartNoList[MAX_HOT_TUV_MODELS][PART_NO_LINES_PER_MODEL];

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace System::IO;

// ----- my main..
using namespace RDS;

//============//
// Form load  //
//============//
System::Void rptDisp::rptDisp_Load(System::Object^  sender, System::EventArgs^  e)
{
    //initial Bitmap
    iBMP=gcnew Bitmap(RPT_BMP_PAGE_WIDTH, RPT_BMP_PAGEHEIGHT);

    //prepare Drawing related pen, Brush, Font....
    blackPen_w1=gcnew Pen(Color::Black, 1.0F);
    grayPen_w1=gcnew Pen(Color::Gray, 1.0F);
    //
    blackSolidBrush=gcnew SolidBrush(Color::Black);
    redSolidBrush=gcnew SolidBrush(Color::Red);
    //blueSolidBrush = gcnew SolidBrush(Color::Blue);
    //
    titleFont=gcnew System::Drawing::Font(RPT_TITLE_FONT, RPT_TITLE_FONTZISE, FontStyle::Bold);
    titleFont2=gcnew System::Drawing::Font(RPT_TITLE2_FONT, RPT_TITLE2_FONTZISE, FontStyle::Bold);
    contentFont=gcnew System::Drawing::Font(RPT_CONTENT_FONT, RPT_CONTENT_FONTZISE, FontStyle::Regular);
    //
    titleTextFormat=gcnew StringFormat(StringFormatFlags::NoWrap);
    titleTextFormat->Alignment=StringAlignment::Center;
    titleTextFormat->LineAlignment=StringAlignment::Center;
    //
    titleTextFormat_L=gcnew StringFormat(StringFormatFlags::NoWrap);
    titleTextFormat_L->Alignment=StringAlignment::Near;
    titleTextFormat_L->LineAlignment=StringAlignment::Center;
    //
    contentTextFormat=gcnew StringFormat(StringFormatFlags::NoWrap);
    contentTextFormat->Alignment=StringAlignment::Near;
    contentTextFormat->LineAlignment=StringAlignment::Center;
    //
    contentTextFormat_R=gcnew StringFormat(StringFormatFlags::NoWrap);
    contentTextFormat_R->Alignment=StringAlignment::Far;
    contentTextFormat_R->LineAlignment=StringAlignment::Center;
    //
    contentTextFormat_Wrap=gcnew StringFormat(StringFormatFlags::NoClip);
    contentTextFormat_Wrap->Alignment=StringAlignment::Near;
    contentTextFormat_Wrap->LineAlignment=StringAlignment::Center;

    //get read filename & read it
    //this->readFilename = m_MainForm->RDS_save_filename;
    RPT_read(this->readFilename);

    //Drawing all
    DrawRreportPage();
}

//==============//
// Form Closed  //
//==============//
System::Void rptDisp::rptDisp_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e)
{
    m_MainForm->enable_Report_btn();
}

//===================//
// Printing related  //
//===================//
System::Void rptDisp::printDocument1_PrintPage(System::Object^  sender, System::Drawing::Printing::PrintPageEventArgs^  e)
{
    //prepare graphics for printer
    Graphics^ pG;
    pG=e->Graphics;
    //pG->DrawImage(this->pictureBox1->Image, 0, 0, RecX, RecY);
    pG->DrawImage(this->pictureBox1->Image, 0, 0);
    pG->SmoothingMode=System::Drawing::Drawing2D::SmoothingMode::HighQuality;
    delete pG;
}

//================//
// Print button   //
//================//
System::Void rptDisp::btn_Print_Click(System::Object^  sender, System::EventArgs^  e)
{
    m_MainForm->MsgLog("RP");
    this->printDialog1->Document=this->printDocument1;
    if(this->printDialog1->ShowDialog()==Windows::Forms::DialogResult::OK)
    {
        //this->printDocument1->PrinterSettings = printDialog1->PrinterSettings;
        this->lbl_page_X->Text=""+this->printDocument1->DefaultPageSettings->PaperSize->Width;
        this->lbl_page_Y->Text=""+this->printDocument1->DefaultPageSettings->PaperSize->Height;
        this->printDocument1->Print();
    }
}

//=====================//
// Save Image button   //
//=====================//
System::Void rptDisp::btn_save_Click(System::Object^  sender, System::EventArgs^  e)
{
    // Displays a SaveFileDialog so the user can save the Image
    // assigned to Button2.
    //SaveFileDialog ^ saveFileDialog1 = gcnew SaveFileDialog();
    this->saveFileDialog1->Filter=
        "JPeg Image|*.jpg|Bitmap Image|*.bmp|Gif Image|*.gif";
    saveFileDialog1->Title="Save an Image File";
    saveFileDialog1->ShowDialog();
    // If the file name is not an empty string, open it for saving.
    if(saveFileDialog1->FileName!="")
    {
        // Saves the Image through a FileStream created by
        // the OpenFile method.
        Stream ^ fs=saveFileDialog1->OpenFile();

        // Saves the Image in the appropriate ImageFormat based on
        // the file type selected in the dialog box.
        // Note that the FilterIndex property is one based.
        switch(saveFileDialog1->FilterIndex)
        {
        case 1:
            this->iBMP->Save(fs, System::Drawing::Imaging::ImageFormat::Jpeg);
            break;
        case 2:
            this->iBMP->Save(fs, System::Drawing::Imaging::ImageFormat::Bmp);
            break;
        case 3:
            this->iBMP->Save(fs, System::Drawing::Imaging::ImageFormat::Gif);
            break;
        }
        fs->Close();
    }
}

//====================================================================================================
//====================================================================================================
// Main related procedures

//===================//
// Read Report file  //
//===================//
void rptDisp::RPT_read(String^ fullfilename)
{
    if(File::Exists(fullfilename)==false)
    {
        MessageBox::Show(MSG_REPORT_FILE_NOT_FOUND_ERROR, "Error",
            MessageBoxButtons::OK,
            MessageBoxIcon::Information);
        return;
    }

    String^ readLineStr;
    String^ tmpStr;
    int tmpInt;
    StreamReader^ din=File::OpenText(fullfilename);

    //read basic information
    readLineStr=din->ReadLine(); //line1 = UID
    this->UID=readLineStr;

    readLineStr=din->ReadLine(); //line2 = date
    tmpStr=readLineStr->Substring(4, 2); //get month
    tmpInt=Convert::ToInt32(tmpStr, 10);
    switch(tmpInt)
    {
    case 1: this->RPT_date="January"; break;
    case 2: this->RPT_date="February"; break;
    case 3: this->RPT_date="March"; break;
    case 4: this->RPT_date="April"; break;
    case 5: this->RPT_date="May"; break;
    case 6: this->RPT_date="June"; break;
    case 7: this->RPT_date="July"; break;
    case 8: this->RPT_date="August"; break;
    case 9: this->RPT_date="September"; break;
    case 10: this->RPT_date="October"; break;
    case 11: this->RPT_date="November"; break;
    case 12: this->RPT_date="December"; break;
    default: this->RPT_date="Month"; break;
    }
    tmpStr=readLineStr->Substring(6, 2); //get day
    this->RPT_date+=", "+tmpStr+"/";
    tmpStr=readLineStr->Substring(0, 4); //get year
    this->RPT_date+=tmpStr;

    readLineStr=din->ReadLine(); //line3 = time
    this->RPT_time=readLineStr;

    readLineStr=din->ReadLine(); //line4 = Hot Tub model name
    this->spa_model_name=readLineStr;

    readLineStr=din->ReadLine(); //line5 = Spa serial number
    this->spa_serial=readLineStr;

    readLineStr=din->ReadLine(); //line6 = Spa owner
    this->spa_owner=readLineStr;

    readLineStr=din->ReadLine(); //line7 = CR person (operator)
    this->cr_operatorName=readLineStr;

    readLineStr=din->ReadLine(); //line8 = current water temperature
    this->cur_WaterT=readLineStr;

    readLineStr=din->ReadLine(); //line9 = set temperature
    this->set_T=readLineStr;

    readLineStr=din->ReadLine(); //line10 = High Limit temperature
    this->highLimitT=readLineStr;

    readLineStr=din->ReadLine(); //line11 = PCB temperature
    this->PCB_T=readLineStr;

    readLineStr=din->ReadLine(); //line12 = Starting Error
    this->StartErr=readLineStr;

    readLineStr=din->ReadLine(); //line13 = Ending Error
    this->EndErr=readLineStr;

    readLineStr=din->ReadLine(); //line14 = Voltage max
    this->voltageMaxP=readLineStr;
    readLineStr=din->ReadLine(); //line15 = Voltage cur
    this->voltageCurP=readLineStr;
    readLineStr=din->ReadLine(); //line16 = Voltage min
    this->voltageMinP=readLineStr;

    readLineStr=din->ReadLine(); //line17 = HiLimit max
    this->HiLimit_Max=readLineStr;
    readLineStr=din->ReadLine(); //line18 = HiLimit cur
    this->HiLimit_Cur=readLineStr;
    readLineStr=din->ReadLine(); //line19 = HiLimit min
    this->HiLimit_Min=readLineStr;

    readLineStr=din->ReadLine(); //line20 = Spa Temp max
    this->SpaTemp_Max=readLineStr;
    readLineStr=din->ReadLine(); //line21 = Spa Temp cur
    this->SpaTemp_Cur=readLineStr;
    readLineStr=din->ReadLine(); //line22 = Spa Temp min
    this->SpaTemp_Min=readLineStr;

    readLineStr=din->ReadLine(); //line23 = PCB Temp max
    this->pcbTemp_Max=readLineStr;
    readLineStr=din->ReadLine(); //line24 = PCB Temp cur
    this->pcbTemp_Cur=readLineStr;
    readLineStr=din->ReadLine(); //line25 = PCB Temp min
    this->pcbTemp_Min=readLineStr;

    readLineStr=din->ReadLine(); //line26 = CR comment
    this->CR_comment=readLineStr;

    readLineStr=din->ReadLine(); //line27 = Replace Part
    this->replace_part=readLineStr;

    readLineStr=din->ReadLine(); //line28 = M0_HC
    this->M0_HC_state=readLineStr;

    readLineStr=din->ReadLine(); //line29 = M0_C
    this->M0_C_state=readLineStr;

    readLineStr=din->ReadLine(); //line30 = M0
    this->M0_state=readLineStr;

    readLineStr=din->ReadLine(); //line31 = M1
    this->M1_state=readLineStr;

    readLineStr=din->ReadLine(); //line32 = M2
    this->M2_state=readLineStr;

    readLineStr=din->ReadLine(); //line33 = M3
    this->M3_state=readLineStr;

    readLineStr=din->ReadLine(); //line34 = M4
    this->M4_state=readLineStr;

    readLineStr=din->ReadLine(); //line35 = M5
    this->M5_state=readLineStr;

    readLineStr=din->ReadLine(); //line36 = M6
    this->M6_state=readLineStr;

    readLineStr=din->ReadLine(); //line37 = M7
    this->M7_state=readLineStr;

    readLineStr=din->ReadLine(); //line38 = AD_CauseEquip_TotalCnt
    this->AD_CauseEquip_TotalCnt=Convert::ToInt32(readLineStr, 10);

    readLineStr=din->ReadLine(); //line39
    this->all_cause=readLineStr;

    readLineStr=din->ReadLine(); //line40
    this->all_equip=readLineStr;

    //-------
    din->Close();
}

//===================//
// Draw whole page   //
//===================//
void rptDisp::DrawRreportPage()
{
    //prepare
    this->pictureBox1->Image=iBMP;
    iG=Graphics::FromImage(iBMP);
    iG->Clear(Color::White);
    //iG->DrawRectangle(grayPen_w1, 1, 1, RPT_BMP_PAGE_WIDTH - 2, RPT_BMP_PAGEHEIGHT - 2); //border

    this->ShowBasicInfo();
    this->ShowErrCause();
    this->ShowEquipments();
    this->ShowBasicLog();
    this->ShowAutoDiagResult();
    this->ShowTechBack();
}

void rptDisp::ShowBasicInfo()
{
    String^ tmpStr;
    String^ dispStr1;
    String^ dispStr2;
    int startIndex;
    //Title
    rTitleText(RPT_PAGE_TITLE_X, RPT_PAGE_TITLE_Y, RPT_PAGE_TITLE_W, RPT_PAGE_TITLE_TEXT, false);

    //line-1  //2016/03/07, delete line & sub-title-1
    //rSplitLine(RPT_LINE1_X, RPT_LINE1_Y, RPT_LINE1_W);
    //sub-title-1
    //rTitle2Text(RPT_SUBTITLE1_X, RPT_SUBTITLE1_Y, RPT_SUBTITLE1_W, RPT_SUBTITLE1_TEXT, false);

    //spa information
    blackContentText(RPT_SUB1_LINE_1_X, RPT_SUB1_LINE_1_Y, RPT_SUB1_LINE_1_W, "UID # "+this->UID, false);
    blackContentText(RPT_SUB1_LINE_2_X, RPT_SUB1_LINE_2_Y, RPT_SUB1_LINE_2_W, "Spa Owner: "+this->spa_owner, false);
    blackContentText(RPT_SUB1_LINE_3_X, RPT_SUB1_LINE_3_Y, RPT_SUB1_LINE_3_W, "Spa Serial Number: "+this->spa_serial, false);
    blackContentText(RPT_SUB1_LINE_4_X, RPT_SUB1_LINE_4_Y, RPT_SUB1_LINE_4_W, "Hot Tub Model Name: "+this->spa_model_name, false);
    blackContentText(RPT_SUB1_LINE_5_X, RPT_SUB1_LINE_5_Y, RPT_SUB1_LINE_5_W, "Staring Error: "+this->StartErr, false); //2016/03/07 add
    //report informtion
    startIndex=this->readFilename->LastIndexOf('\\');
    tmpStr=this->readFilename->Substring(startIndex+1);
    startIndex=tmpStr->IndexOf(".csv");
    dispStr1=tmpStr->Substring(0, startIndex); //report_No + SC_No (if has SC_no)
    startIndex=tmpStr->IndexOf("_P");
    if(startIndex>0) dispStr2=tmpStr->Substring(0, startIndex); //report_No (without SC_no)
    else { dispStr2=dispStr1; dispStr1="N/A"; }//in case, ther is no SC_no
    blackContentText(RPT_SUB1_LINE1M_X, RPT_SUB1_LINE1M_Y, RPT_SUB1_LINE1M_W, "Report # "+dispStr2, false);
    blackContentText(RPT_SUB1_LINE2M_X, RPT_SUB1_LINE2M_Y, RPT_SUB1_LINE2M_W, "Service # "+dispStr1, false);
    blackContentText(RPT_SUB1_LINE3M_X, RPT_SUB1_LINE3M_Y, RPT_SUB1_LINE3M_W, "Date/Time: "+this->RPT_date+" "+this->RPT_time, false);
    blackContentText(RPT_SUB1_LINE4M_X, RPT_SUB1_LINE4M_Y, RPT_SUB1_LINE4M_W, "Customer Representative Name: "+this->cr_operatorName, false);
    blackContentText(RPT_SUB1_LINE5M_X, RPT_SUB1_LINE5M_Y, RPT_SUB1_LINE5M_W, "Ending Error: "+this->EndErr, false);  //2016/03/07 add
    //
    return;
}

void rptDisp::ShowErrCause()
{
    String^ dispStr1;
    String^ dispStr2;
    String^ dispStr3;
    String^ dispStr4;
    //line-2
    rSplitLine(RPT_LINE2_X, RPT_LINE2_Y, RPT_LINE2_W);

    //2016/03/07 modify: move system error to sub-1, and change to 3 (L,M,R) positions per line, and Cause for 12
    ////sub-title-2 (L/R)
    //rTitle2TextL(RPT_SUBTITLE2_L_X, RPT_SUBTITLE2_L_Y, RPT_SUBTITLE2_L_W, RPT_SUBTITLE2_L_TEXT, false);
    //rTitle2TextL(RPT_SUBTITLE2_R_X, RPT_SUBTITLE2_R_Y, RPT_SUBTITLE2_R_W, RPT_SUBTITLE2_R_TEXT, false);
    ////
    //blackContentText(RPT_SUB2_LINE_1_X, RPT_SUB2_LINE_1_Y, RPT_SUB2_LINE_1_W, "Staring Error: " + this->StartErr, false);
    //blackContentText(RPT_SUB2_LINE_2_X, RPT_SUB2_LINE_2_Y, RPT_SUB2_LINE_2_W, "Ending Error: " + this->EndErr, false);
    //dispStr1 = "Pump 2 Defect";
    //dispStr2 = "Board Defect";
    //blackContentText(RPT_SUB2_LINE1M_X, RPT_SUB2_LINE1M_Y, RPT_SUB2_LINE1M_W, "** " + dispStr1, false);
    //blackContentText(RPT_SUB2_LINE2M_X, RPT_SUB2_LINE2M_Y, RPT_SUB2_LINE2M_W, " * " + dispStr2, false);

    //2016/03/07 Add for 12 causes, and 3 (L,M,R) positions per line
    //sub-title-2
    rTitle2Text(RPT_SUBTITLE2_X, RPT_SUBTITLE2_Y, RPT_SUBTITLE2_W, RPT_SUBTITLE2_TEXT, false);

    //------------------get strings...
    int tmpNo;
    array<Char>^sep=gcnew array<Char>{','};
    array<String^>^result;
    if(this->all_cause!="N/A")
    {
        result=this->all_cause->Split(sep, StringSplitOptions::RemoveEmptyEntries);
        for(int i=0; i<result->Length; i++)
        {
            tmpNo=Convert::ToInt32(result[i], 10);
            if(tmpNo>=CUASE_RPT_TABLE_SIZE||tmpNo<0)
            {//error
                MessageBox::Show(MSG_REPORT_CAUSE_NUMBER_OVER_RANGE, "Error",
                    MessageBoxButtons::OK,
                    MessageBoxIcon::Information);
                return;
            }
            else
            {
                result[i]=gcnew String(RPT_all_Cause[tmpNo].CE_string);
            }
        }//end-for-loop i
    }

    //
    if(this->all_cause!="N/A")
    {
        if(result->Length>=1)  dispStr1=result[0]; else dispStr1=".";
        if(result->Length>=4)  dispStr2=result[3]; else dispStr2=".";
        if(result->Length>=7)  dispStr3=result[6]; else dispStr3=".";
        if(result->Length>=10)  dispStr4=result[9]; else dispStr4=".";
    }
    else
    {
        dispStr1=".";
        dispStr2=".";
        dispStr3=".";
        dispStr4=".";
    }
    blackContentText(RPT_SUB2_LINE_1_X, RPT_SUB2_LINE_1_Y, RPT_SUB2_LINE_1_W, dispStr1, false);
    blackContentText(RPT_SUB2_LINE_2_X, RPT_SUB2_LINE_2_Y, RPT_SUB2_LINE_2_W, dispStr2, false);
    blackContentText(RPT_SUB2_LINE_3_X, RPT_SUB2_LINE_3_Y, RPT_SUB2_LINE_3_W, dispStr3, false);
    blackContentText(RPT_SUB2_LINE_4_X, RPT_SUB2_LINE_4_Y, RPT_SUB2_LINE_4_W, dispStr4, false);
    //
    if(this->all_cause!="N/A")
    {
        if(result->Length>=2)  dispStr1=result[1]; else dispStr1=".";
        if(result->Length>=5)  dispStr2=result[4]; else dispStr2=".";
        if(result->Length>=8)  dispStr3=result[7]; else dispStr3=".";
        if(result->Length>=11)  dispStr4=result[10]; else dispStr4=".";
    }
    else
    {
        dispStr1=".";
        dispStr2=".";
        dispStr3=".";
        dispStr4=".";
    }
    blackContentText(RPT_SUB2_LINE1M_X, RPT_SUB2_LINE1M_Y, RPT_SUB2_LINE1M_W, dispStr1, false);
    blackContentText(RPT_SUB2_LINE2M_X, RPT_SUB2_LINE2M_Y, RPT_SUB2_LINE2M_W, dispStr2, false);
    blackContentText(RPT_SUB2_LINE3M_X, RPT_SUB2_LINE3M_Y, RPT_SUB2_LINE3M_W, dispStr3, false);
    blackContentText(RPT_SUB2_LINE4M_X, RPT_SUB2_LINE4M_Y, RPT_SUB2_LINE4M_W, dispStr4, false);
    //
    if(this->all_cause!="N/A")
    {
        if(result->Length>=3)  dispStr1=result[2]; else dispStr1=".";
        if(result->Length>=6)  dispStr2=result[5]; else dispStr2=".";
        if(result->Length>=9)  dispStr3=result[8]; else dispStr3=".";
        if(result->Length>=12)  dispStr4=result[11]; else dispStr4=".";
    }
    else
    {
        dispStr1=".";
        dispStr2=".";
        dispStr3=".";
        dispStr4=".";
    }
    blackContentText(RPT_SUB2_LINE1R_X, RPT_SUB2_LINE1R_Y, RPT_SUB2_LINE1R_W, dispStr1, false);
    blackContentText(RPT_SUB2_LINE2R_X, RPT_SUB2_LINE2R_Y, RPT_SUB2_LINE2R_W, dispStr2, false);
    blackContentText(RPT_SUB2_LINE3R_X, RPT_SUB2_LINE3R_Y, RPT_SUB2_LINE3R_W, dispStr3, false);
    blackContentText(RPT_SUB2_LINE4R_X, RPT_SUB2_LINE4R_Y, RPT_SUB2_LINE4R_W, dispStr4, false);
    //
    return;
}

void rptDisp::ShowEquipments()
{
    String^ dispStr1;
    String^ dispStr2;
    String^ dispStr3;
    String^ dispStr4;
    //String^ dispStr5;

    //line-3
    rSplitLine(RPT_LINE3_X, RPT_LINE3_Y, RPT_LINE3_W);
    //sub-title-3
    rTitle2Text(RPT_SUBTITLE3_X, RPT_SUBTITLE3_Y, RPT_SUBTITLE3_W, RPT_SUBTITLE3_TEXT, false);

    ////     //2016/03/07 change to 3 position per line, total 12 Equipments
    //dispStr1 = "(0)";
    //dispStr2 = "(1)";
    //dispStr3 = "(2)";
    //dispStr4 = "(3)";
    //dispStr5 = "(4)";
    //blackContentText(RPT_SUB3_LINE_1_X, RPT_SUB3_LINE_1_Y, RPT_SUB3_LINE_1_W, dispStr1, false);
    //blackContentText(RPT_SUB3_LINE_2_X, RPT_SUB3_LINE_2_Y, RPT_SUB3_LINE_2_W, dispStr2, false);
    //blackContentText(RPT_SUB3_LINE_3_X, RPT_SUB3_LINE_3_Y, RPT_SUB3_LINE_3_W, dispStr3, false);
    //blackContentText(RPT_SUB3_LINE_4_X, RPT_SUB3_LINE_4_Y, RPT_SUB3_LINE_4_W, dispStr4, false);
    //blackContentText(RPT_SUB3_LINE_5_X, RPT_SUB3_LINE_5_Y, RPT_SUB3_LINE_5_W, dispStr5, false);
    ////
    //dispStr1 = "(5)";
    //dispStr2 = "(6)";
    //dispStr3 = "(7)";
    //dispStr4 = "(8)";
    //dispStr5 = "(9)";
    //blackContentText(RPT_SUB3_LINE1M_X, RPT_SUB3_LINE1M_Y, RPT_SUB3_LINE1M_W, dispStr1, false);
    //blackContentText(RPT_SUB3_LINE2M_X, RPT_SUB3_LINE2M_Y, RPT_SUB3_LINE2M_W, dispStr2, false);
    //blackContentText(RPT_SUB3_LINE3M_X, RPT_SUB3_LINE3M_Y, RPT_SUB3_LINE3M_W, dispStr3, false);
    //blackContentText(RPT_SUB3_LINE4M_X, RPT_SUB3_LINE4M_Y, RPT_SUB3_LINE4M_W, dispStr4, false);
    //blackContentText(RPT_SUB3_LINE5M_X, RPT_SUB3_LINE5M_Y, RPT_SUB3_LINE5M_W, dispStr5, false);

    //------------------get strings...
    int tmpNo;
    int ModelIndex;
    array<Char>^sep=gcnew array<Char>{','};
    array<String^>^result;
    String^ tmpStr;

    //get Model-index
    ModelIndex=-1;
    do
    {
        ModelIndex++;
        if(ModelIndex==MAX_HOT_TUV_MODELS)
        { //not found!!
            MessageBox::Show(MSG_REPORT_MODELNAME_NOT_FOUND_ERROR, "Error",
                MessageBoxButtons::OK, MessageBoxIcon::Information);
            ModelIndex=0;
            break; //leave wgile loop
        }
        tmpStr=gcnew String(ModelNames[ModelIndex]);
    } while(this->spa_model_name!=tmpStr);

    //start checking
    if(this->all_equip!="N/A")
    {
        result=this->all_equip->Split(sep, StringSplitOptions::RemoveEmptyEntries);
        for(int i=0; i<result->Length; i++)
        {
            tmpNo=Convert::ToInt32(result[i], 10);
            if(tmpNo>=EQUIP_RPT_TABLE_SIZE||tmpNo<0)
            {//error
                MessageBox::Show(MSG_REPORT_CAUSE_NUMBER_OVER_RANGE, "Error",
                    MessageBoxButtons::OK,
                    MessageBoxIcon::Information);
                return;
            }
            else
            {
                result[i]=gcnew String(RPT_all_Equip[tmpNo].CE_string)+"("
                    +gcnew String(PartNoList[ModelIndex][RPT_all_Equip[tmpNo].partListIndex])+")";
            }
        }//end for-loop i
    }

    //
    if(this->all_equip!="N/A")
    {
        if(result->Length>=1)  dispStr1=result[0]; else dispStr1=".";
        if(result->Length>=4)  dispStr2=result[3]; else dispStr2=".";
        if(result->Length>=7)  dispStr3=result[6]; else dispStr3=".";
        if(result->Length>=10)  dispStr4=result[9]; else dispStr4=".";
    }
    else
    {
        dispStr1=".";
        dispStr2=".";
        dispStr3=".";
        dispStr4=".";
    }
    blackContentText(RPT_SUB3_LINE_1_X, RPT_SUB3_LINE_1_Y, RPT_SUB3_LINE_1_W, dispStr1, false);
    blackContentText(RPT_SUB3_LINE_2_X, RPT_SUB3_LINE_2_Y, RPT_SUB3_LINE_2_W, dispStr2, false);
    blackContentText(RPT_SUB3_LINE_3_X, RPT_SUB3_LINE_3_Y, RPT_SUB3_LINE_3_W, dispStr3, false);
    blackContentText(RPT_SUB3_LINE_4_X, RPT_SUB3_LINE_4_Y, RPT_SUB3_LINE_4_W, dispStr4, false);
    //
    if(this->all_equip!="N/A")
    {
        if(result->Length>=2)  dispStr1=result[1]; else dispStr1=".";
        if(result->Length>=5)  dispStr2=result[4]; else dispStr2=".";
        if(result->Length>=8)  dispStr3=result[7]; else dispStr3=".";
        if(result->Length>=11)  dispStr4=result[10]; else dispStr4=".";
    }
    else
    {
        dispStr1=".";
        dispStr2=".";
        dispStr3=".";
        dispStr4=".";
    }
    blackContentText(RPT_SUB3_LINE1M_X, RPT_SUB3_LINE1M_Y, RPT_SUB3_LINE1M_W, dispStr1, false);
    blackContentText(RPT_SUB3_LINE2M_X, RPT_SUB3_LINE2M_Y, RPT_SUB3_LINE2M_W, dispStr2, false);
    blackContentText(RPT_SUB3_LINE3M_X, RPT_SUB3_LINE3M_Y, RPT_SUB3_LINE3M_W, dispStr3, false);
    blackContentText(RPT_SUB3_LINE4M_X, RPT_SUB3_LINE4M_Y, RPT_SUB3_LINE4M_W, dispStr4, false);
    //
    if(this->all_equip!="N/A")
    {
        if(result->Length>=3)  dispStr1=result[2]; else dispStr1=".";
        if(result->Length>=6)  dispStr2=result[5]; else dispStr2=".";
        if(result->Length>=9)  dispStr3=result[8]; else dispStr3=".";
        if(result->Length>=12)  dispStr4=result[11]; else dispStr4=".";
    }
    else
    {
        dispStr1=".";
        dispStr2=".";
        dispStr3=".";
        dispStr4=".";
    }
    blackContentText(RPT_SUB2_LINE1R_X, RPT_SUB3_LINE1R_Y, RPT_SUB3_LINE1R_W, dispStr1, false);
    blackContentText(RPT_SUB3_LINE2R_X, RPT_SUB3_LINE2R_Y, RPT_SUB3_LINE2R_W, dispStr2, false);
    blackContentText(RPT_SUB3_LINE3R_X, RPT_SUB3_LINE3R_Y, RPT_SUB3_LINE3R_W, dispStr3, false);
    blackContentText(RPT_SUB3_LINE4R_X, RPT_SUB3_LINE4R_Y, RPT_SUB3_LINE4R_W, dispStr4, false);
    //
    return;
}

void rptDisp::ShowBasicLog()
{
    //line-4
    rSplitLine(RPT_LINE4_X, RPT_LINE4_Y, RPT_LINE4_W);
    //sub-title-4
    rTitle2Text(RPT_SUBTITLE4_X, RPT_SUBTITLE4_Y, RPT_SUBTITLE4_W, RPT_SUBTITLE4_TEXT, false);
    //
    blackContentText(RPT_SUB4_LINE_1_X, RPT_SUB4_LINE_1_Y, RPT_SUB4_LINE_1_W, "Voltage %:  Hi = "+this->voltageMaxP, false);
    blackContentText(RPT_SUB4_LINE_2_X, RPT_SUB4_LINE_2_Y, RPT_SUB4_LINE_2_W, "Hi-Limit :  Hi = "+this->HiLimit_Max, false);
    blackContentText(RPT_SUB4_LINE_3_X, RPT_SUB4_LINE_3_Y, RPT_SUB4_LINE_3_W, "Spa Temp :  Hi = "+this->SpaTemp_Max, false);
    blackContentText(RPT_SUB4_LINE_4_X, RPT_SUB4_LINE_4_Y, RPT_SUB4_LINE_4_W, "PCB Temp :  Hi = "+this->pcbTemp_Max, false);
    //
    blackContentText(RPT_SUB4_LINE1M_X, RPT_SUB4_LINE1M_Y, RPT_SUB4_LINE1M_W, "Present = "+this->voltageCurP, false);
    blackContentText(RPT_SUB4_LINE2M_X, RPT_SUB4_LINE2M_Y, RPT_SUB4_LINE2M_W, "Present = "+this->HiLimit_Cur, false);
    blackContentText(RPT_SUB4_LINE3M_X, RPT_SUB4_LINE3M_Y, RPT_SUB4_LINE3M_W, "Present = "+this->SpaTemp_Cur, false);
    blackContentText(RPT_SUB4_LINE4M_X, RPT_SUB4_LINE4M_Y, RPT_SUB4_LINE4M_W, "Present = "+this->pcbTemp_Cur, false);
    //
    blackContentText(RPT_SUB4_LINE1R_X, RPT_SUB4_LINE1R_Y, RPT_SUB4_LINE1R_W, "Low = "+this->voltageMinP, false);
    blackContentText(RPT_SUB4_LINE2R_X, RPT_SUB4_LINE2R_Y, RPT_SUB4_LINE2R_W, "Low = "+this->HiLimit_Min, false);
    blackContentText(RPT_SUB4_LINE3R_X, RPT_SUB4_LINE3R_Y, RPT_SUB4_LINE3R_W, "Low = "+this->SpaTemp_Min, false);
    blackContentText(RPT_SUB4_LINE4R_X, RPT_SUB4_LINE4R_Y, RPT_SUB4_LINE4R_W, "Low = "+this->pcbTemp_Min, false);
    //
    return;
}

void rptDisp::ShowAutoDiagResult()
{
    String^ dispStr1;
    String^ dispStr2;
    String^ dispStr3;
    String^ dispStr4;
    String^ dispStr5;
    //line-5
    rSplitLine(RPT_LINE5_X, RPT_LINE5_Y, RPT_LINE5_W);
    //sub-title-5
    rTitle2Text(RPT_SUBTITLE5_X, RPT_SUBTITLE5_Y, RPT_SUBTITLE5_W, RPT_SUBTITLE5_TEXT, false);
    //
    dispStr1=parse_M0_HC(M0_HC_state);
    dispStr2=parse_M0_C(M0_C_state);
    dispStr3=parse_M0(M0_state);
    dispStr4=parse_M1(M1_state);
    dispStr5=parse_M2(M2_state);
    blackContentText(RPT_SUB5_LINE_1_X, RPT_SUB5_LINE_1_Y, RPT_SUB5_LINE_1_W, dispStr1, false);
    blackContentText(RPT_SUB5_LINE_2_X, RPT_SUB5_LINE_2_Y, RPT_SUB5_LINE_2_W, dispStr2, false);
    blackContentText(RPT_SUB5_LINE_3_X, RPT_SUB5_LINE_3_Y, RPT_SUB5_LINE_3_W, dispStr3, false);
    blackContentText(RPT_SUB5_LINE_4_X, RPT_SUB5_LINE_4_Y, RPT_SUB5_LINE_4_W, dispStr4, false);
    blackContentText(RPT_SUB5_LINE_5_X, RPT_SUB5_LINE_5_Y, RPT_SUB5_LINE_5_W, dispStr5, false);
    //
    dispStr1=parse_M3(M3_state);
    dispStr2=parse_M4(M4_state);
    dispStr3=parse_M5(M5_state);
    dispStr4=parse_M6(M6_state);
    dispStr5=parse_M7(M7_state);
    blackContentText(RPT_SUB5_LINE1M_X, RPT_SUB5_LINE1M_Y, RPT_SUB5_LINE1M_W, dispStr1, false);
    blackContentText(RPT_SUB5_LINE2M_X, RPT_SUB5_LINE2M_Y, RPT_SUB5_LINE2M_W, dispStr2, false);
    blackContentText(RPT_SUB5_LINE3M_X, RPT_SUB5_LINE3M_Y, RPT_SUB5_LINE3M_W, dispStr3, false);
    blackContentText(RPT_SUB5_LINE4M_X, RPT_SUB5_LINE4M_Y, RPT_SUB5_LINE4M_W, dispStr4, false);
    blackContentText(RPT_SUB5_LINE5M_X, RPT_SUB5_LINE5M_Y, RPT_SUB5_LINE5M_W, dispStr5, false);
    //
    return;
}
void rptDisp::ShowTechBack()
{
    String^ dispStr1;
    String^ dispStr2;
    //line-6
    rSplitLine(RPT_LINE6_X, RPT_LINE6_Y, RPT_LINE6_W);
    //sub-title-6
    rTitle2Text(RPT_SUBTITLE6_X, RPT_SUBTITLE6_Y, RPT_SUBTITLE6_W, RPT_SUBTITLE6_TEXT, false);
    //comment
    if(this->CR_comment->Length<RPT_SUB6LINE_MAX_CHARS)
    {
        dispStr1=this->CR_comment;
        dispStr2="";
    }
    else
    {
        dispStr1=this->CR_comment->Substring(0, RPT_SUB6LINE_MAX_CHARS);
        if(this->CR_comment->Length<(RPT_SUB6LINE_MAX_CHARS*2))
            dispStr2=this->CR_comment->Substring(RPT_SUB6LINE_MAX_CHARS);
        else
            dispStr2=this->CR_comment->Substring(RPT_SUB6LINE_MAX_CHARS, RPT_SUB6LINE_MAX_CHARS);
    }
    blackContentTxtWrap(RPT_SUB6_LINE_1_X, RPT_SUB6_LINE_1_Y, RPT_SUB6_LINE_1_W, dispStr1, false);
    blackContentTxtWrap(RPT_SUB6_LINE_2_X, RPT_SUB6_LINE_2_Y, RPT_SUB6_LINE_2_W, dispStr2, false);

    //line-7
    //rSplitLine(RPT_LINE7_X, RPT_LINE7_Y, RPT_LINE7_W);
    // rectangle
    iG->DrawRectangle(blackPen_w1, RPT_SUB7_REC_X, RPT_SUB7_REC_Y, RPT_SUB7_REC_W, RPT_SUB7_REC_H);
    //sub-title-7
    rTitle2Text(RPT_SUBTITLE7_X, RPT_SUBTITLE7_Y, RPT_SUBTITLE7_W, RPT_SUBTITLE7_TEXT, false);
    //
    dispStr1=RPT_NOTE_FIELD_1L;
    dispStr2=RPT_NOTE_FIELD_2L;
    blackContentText(RPT_SUB7_LINE_1_X, RPT_SUB7_LINE_1_Y, RPT_SUB7_LINE_1_W, dispStr1, false);
    blackContentText(RPT_SUB7_LINE_2_X, RPT_SUB7_LINE_2_Y, RPT_SUB7_LINE_2_W, dispStr2, false);
    //
    dispStr1=RPT_NOTE_FIELD_1R;
    dispStr2=RPT_NOTE_FIELD_2R;
    blackContentText(RPT_SUB7_LINE1M_X, RPT_SUB7_LINE1M_Y, RPT_SUB7_LINE1M_W, dispStr1, false);
    blackContentText(RPT_SUB7_LINE2M_X, RPT_SUB7_LINE2M_Y, RPT_SUB7_LINE2M_W, dispStr2, false);
}

//-------------------------------------------------------
//-------------------------------------------------------
String^ rptDisp::parse_M0_HC(String^ InStr)
{
    array<Char>^sep=gcnew array<Char>{
        ','
    };
    array<String^>^result;
    if(InStr=="n/a") return "Heater + Circ + UV : N/A";
    else
    {
        result=InStr->Split(sep, StringSplitOptions::RemoveEmptyEntries);
        if(result[1]=="E")
            return "Heater + Circ + UV : "+result[0]+" (Error)";
        else
            return "Heater + Circ + UV : "+result[0]+" (Normal)";
    }
}

String^ rptDisp::parse_M0_C(String^ InStr)
{
    array<Char>^sep=gcnew array<Char>{
        ','
    };
    array<String^>^result;
    if(InStr=="n/a") return "Circ + UV : N/A";
    else
    {
        result=InStr->Split(sep, StringSplitOptions::RemoveEmptyEntries);
        if(result[1]=="E")
            return "Circ + UV : "+result[0]+" (Error)";
        else
            return "Circ + UV : "+result[0]+" (Normal)";
    }
}

String^ rptDisp::parse_M0(String^ InStr)
{
    array<Char>^sep=gcnew array<Char>{
        ','
    };
    array<String^>^result;
    result=InStr->Split(sep, StringSplitOptions::RemoveEmptyEntries);
    if(result[0]=="1")
    {
        if(result[2]=="E")
            return "all off: "+result[1]+" (Error)";
        else
            return "all off : "+result[1]+" (Normal)";
    }
    else if(result[0]=="2")
    {
        if(result[2]=="E")
            return "Circ + UV : "+result[1]+" (Error)";
        else
            return "Circ + UV : "+result[1]+" (Normal)";
    }
    else if(result[0]=="3")
    {
        if(result[2]=="E")
            return "Heater + Circ + UV : "+result[1]+" (Error)";
        else
            return "Heater + Circ + UV : "+result[1]+" (Normal)";
    }
    else
        return "N/A"; //it should not happen!!
}

String^ rptDisp::parse_M1(String^ InStr)
{
    array<Char>^sep=gcnew array<Char>{
        ','
    };
    array<String^>^result;
    result=InStr->Split(sep, StringSplitOptions::RemoveEmptyEntries);
    if(result[0]=="1")
    {   //it should not happen!! (circ aloway on with it)
        if(result[2]=="E")
            return "Pump-1 Hi: "+result[1]+" (Error)";
        else
            return "Pump-1 Hi: "+result[1]+" (Normal)";
    }
    else if(result[0]=="2")
    {
        if(result[2]=="E")
            return "Pump-1 Hi + Circ + UV : "+result[1]+" (Error)";
        else
            return "Pump-1 Hi + Circ + UV : "+result[1]+" (Normal)";
    }
    else if(result[0]=="3")
    {
        if(result[2]=="E")
            return "Pump-1 Hi + Heater + Circ + UV : "+result[1]+" (Error)";
        else
            return "Pump-1 Hi + Heater + Circ + UV : "+result[1]+" (Normal)";
    }
    else
        return "Pump-1 Hi : N/A"; //dont have this device
}

String^ rptDisp::parse_M2(String^ InStr)
{
    array<Char>^sep=gcnew array<Char>{
        ','
    };
    array<String^>^result;
    result=InStr->Split(sep, StringSplitOptions::RemoveEmptyEntries);
    if(result[0]=="1")
    {   //it should not happen!! (circ aloway on with it)
        if(result[2]=="E")
            return "Pump-1 Lo: "+result[1]+" (Error)";
        else
            return "Pump-1 Lo: "+result[1]+" (Normal)";
    }
    else if(result[0]=="2")
    {
        if(result[2]=="E")
            return "Pump-1 Lo + Circ + UV : "+result[1]+" (Error)";
        else
            return "Pump-1 Lo + Circ + UV : "+result[1]+" (Normal)";
    }
    else if(result[0]=="3")
    {
        if(result[2]=="E")
            return "Pump-1 Lo + Heater + Circ + UV : "+result[1]+" (Error)";
        else
            return "Pump-1 Lo + Heater + Circ + UV : "+result[1]+" (Normal)";
    }
    else
        return "Pump-1 Lo : N/A"; //dont have this device
}

String^ rptDisp::parse_M3(String^ InStr)
{
    array<Char>^sep=gcnew array<Char>{
        ','
    };
    array<String^>^result;
    result=InStr->Split(sep, StringSplitOptions::RemoveEmptyEntries);
    if(result[0]=="1")
    {   //it should not happen!! (circ aloway on with it)
        if(result[2]=="E")
            return "Pump-2 Hi: "+result[1]+" (Error)";
        else
            return "Pump-2 Hi: "+result[1]+" (Normal)";
    }
    else if(result[0]=="2")
    {
        if(result[2]=="E")
            return "Pump-2 Hi + Circ + UV : "+result[1]+" (Error)";
        else
            return "Pump-2 Hi + Circ + UV : "+result[1]+" (Normal)";
    }
    else if(result[0]=="3")
    {
        if(result[2]=="E")
            return "Pump-2 Hi + Heater + Circ + UV : "+result[1]+" (Error)";
        else
            return "Pump-2 Hi + Heater + Circ + UV : "+result[1]+" (Normal)";
    }
    else
        return "Pump-2 Hi : N/A"; //dont have this device
}

String^ rptDisp::parse_M4(String^ InStr)
{
    array<Char>^sep=gcnew array<Char>{
        ','
    };
    array<String^>^result;
    result=InStr->Split(sep, StringSplitOptions::RemoveEmptyEntries);
    if(result[0]=="1")
    {   //it should not happen!! (circ aloway on with it)
        if(result[2]=="E")
            return "Pump-2 Lo: "+result[1]+" (Error)";
        else
            return "Pump-2 Lo: "+result[1]+" (Normal)";
    }
    else if(result[0]=="2")
    {
        if(result[2]=="E")
            return "Pump-2 Lo + Circ + UV : "+result[1]+" (Error)";
        else
            return "Pump-2 Lo + Circ + UV : "+result[1]+" (Normal)";
    }
    else if(result[0]=="3")
    {
        if(result[2]=="E")
            return "Pump-2 Lo + Heater + Circ + UV : "+result[1]+" (Error)";
        else
            return "Pump-2 Lo + Heater + Circ + UV : "+result[1]+" (Normal)";
    }
    else
        return "Pump-2 Lo : N/A"; //dont have this device
}

String^ rptDisp::parse_M5(String^ InStr)
{
    array<Char>^sep=gcnew array<Char>{
        ','
    };
    array<String^>^result;
    result=InStr->Split(sep, StringSplitOptions::RemoveEmptyEntries);
    if(result[0]=="1")
    {   //it should not happen!! (circ aloway on with it)
        if(result[2]=="E")
            return "Pump-3 Hi: "+result[1]+" (Error)";
        else
            return "Pump-3 Hi: "+result[1]+" (Normal)";
    }
    else if(result[0]=="2")
    {
        if(result[2]=="E")
            return "Pump-3 Hi + Circ + UV : "+result[1]+" (Error)";
        else
            return "Pump-3 Hi + Circ + UV : "+result[1]+" (Normal)";
    }
    else if(result[0]=="3")
    {
        if(result[2]=="E")
            return "Pump-3 Hi + Heater + Circ + UV : "+result[1]+" (Error)";
        else
            return "Pump-3 Hi + Heater + Circ + UV : "+result[1]+" (Normal)";
    }
    else
        return "Pump-3 Hi : N/A"; //dont have this device
}

String^ rptDisp::parse_M6(String^ InStr)
{
    array<Char>^sep=gcnew array<Char>{
        ','
    };
    array<String^>^result;
    result=InStr->Split(sep, StringSplitOptions::RemoveEmptyEntries);
    if(result[0]=="1")
    {   //it should not happen!! (circ aloway on with it)
        if(result[2]=="E")
            return "Pump-3 Lo: "+result[1]+" (Error)";
        else
            return "Pump-3 Lo: "+result[1]+" (Normal)";
    }
    else if(result[0]=="2")
    {
        if(result[2]=="E")
            return "Pump-3 Lo + Circ + UV : "+result[1]+" (Error)";
        else
            return "Pump-3 Lo + Circ + UV : "+result[1]+" (Normal)";
    }
    else if(result[0]=="3")
    {
        if(result[2]=="E")
            return "Pump-3 Lo + Heater + Circ + UV : "+result[1]+" (Error)";
        else
            return "Pump-3 Lo + Heater + Circ + UV : "+result[1]+" (Normal)";
    }
    else
        return "Pump-3 Lo : N/A"; //dont have this device
}

String^ rptDisp::parse_M7(String^ InStr)
{
    array<Char>^sep=gcnew array<Char>{
        ','
    };
    array<String^>^result;
    result=InStr->Split(sep, StringSplitOptions::RemoveEmptyEntries);
    if(result[0]=="1")
    {   //it should not happen!! (circ aloway on with it)
        if(result[2]=="E")
            return "Blower: "+result[1]+" (Error)";
        else
            return "Blower: "+result[1]+" (Normal)";
    }
    else if(result[0]=="2")
    {
        if(result[2]=="E")
            return "Blower + Circ + UV : "+result[1]+" (Error)";
        else
            return "Blower + Circ + UV : "+result[1]+" (Normal)";
    }
    else if(result[0]=="3")
    {
        if(result[2]=="E")
            return "Blower + Heater + Circ + UV : "+result[1]+" (Error)";
        else
            return "Blower + Heater + Circ + UV : "+result[1]+" (Normal)";
    }
    else
        return "Blower : N/A"; //dont have this device
}

//====================================================================================================
//====================================================================================================
// Basic function for string/line  etc.

//Title (center)
void rptDisp::rTitleText(float X, float Y, float WD, String^ strText, Boolean hasBorder)
{
    System::Drawing::RectangleF RecArea=System::Drawing::RectangleF(X, Y, WD, (float)RPT_TITLE_HIEGHT);
    if(hasBorder)
    {
        iG->DrawRectangle(this->blackPen_w1, X, Y, WD, (float)RPT_TITLE_HIEGHT); //border
    }
    iG->DrawString(strText, this->titleFont, this->blackSolidBrush, RecArea, this->titleTextFormat);
}

//Sub-title (center)
void rptDisp::rTitle2Text(float X, float Y, float WD, String^ strText, Boolean hasBorder)
{
    System::Drawing::RectangleF RecArea=System::Drawing::RectangleF(X, Y, WD, (float)RPT_TITLE2_HIEGHT);
    if(hasBorder)
    {
        iG->DrawRectangle(this->blackPen_w1, X, Y, WD, (float)RPT_TITLE2_HIEGHT); //border
    }
    iG->DrawString(strText, this->titleFont2, this->blackSolidBrush, RecArea, this->titleTextFormat);
}

//Sub-title (Left)
void rptDisp::rTitle2TextL(float X, float Y, float WD, String^ strText, Boolean hasBorder)
{
    System::Drawing::RectangleF RecArea=System::Drawing::RectangleF(X, Y, WD, (float)RPT_TITLE2_HIEGHT);
    if(hasBorder)
    {
        iG->DrawRectangle(this->blackPen_w1, X, Y, WD, (float)RPT_TITLE2_HIEGHT); //border
    }
    iG->DrawString(strText, this->titleFont2, this->blackSolidBrush, RecArea, this->titleTextFormat_L);
}

//black font content
//alignment: left
void rptDisp::blackContentText(float X, float Y, float WD, String^ strText, Boolean hasBorder)
{
    System::Drawing::RectangleF RecArea=System::Drawing::RectangleF(X, Y, WD, (float)RPT_CONTENT_HIEGHT);
    if(hasBorder)
    {
        iG->DrawRectangle(this->grayPen_w1, X, Y, WD, (float)RPT_CONTENT_HIEGHT); //border
    }
    iG->DrawString(strText, this->contentFont, this->blackSolidBrush, RecArea, this->contentTextFormat);
}

//black font content
//alignment: right
void rptDisp::blackContentTxtR(float X, float Y, float WD, String^ strText, Boolean hasBorder)
{
    System::Drawing::RectangleF RecArea=System::Drawing::RectangleF(X, Y, WD, (float)RPT_CONTENT_HIEGHT);
    if(hasBorder)
    {
        iG->DrawRectangle(this->grayPen_w1, X, Y, WD, (float)RPT_CONTENT_HIEGHT); //border
    }
    iG->DrawString(strText, this->contentFont, this->blackSolidBrush, RecArea, this->contentTextFormat_R);
}

//black font content
//alignment: left, And it will wrap line when needed.
void rptDisp::blackContentTxtWrap(float X, float Y, float WD, String^ strText, Boolean hasBorder)
{
    System::Drawing::RectangleF RecArea=System::Drawing::RectangleF(X, Y, WD, (float)RPT_CONTENT_HIEGHT);
    if(hasBorder)
    {
        iG->DrawRectangle(this->grayPen_w1, X, Y, WD, (float)RPT_CONTENT_HIEGHT); //border
    }
    iG->DrawString(strText, this->contentFont, this->blackSolidBrush, RecArea, this->contentTextFormat_Wrap);
}

//read font content
void rptDisp::redContentText(float X, float Y, float WD, String^ strText, Boolean hasBorder)
{
    System::Drawing::RectangleF RecArea=System::Drawing::RectangleF(X, Y, WD, (float)RPT_CONTENT_HIEGHT);
    if(hasBorder)
    {
        iG->DrawRectangle(this->grayPen_w1, X, Y, WD, (float)RPT_CONTENT_HIEGHT); //border
    }
    iG->DrawString(strText, this->contentFont, this->redSolidBrush, RecArea, this->contentTextFormat);
}

void rptDisp::rSplitLine(float X, float Y, float WD)
{
    iG->DrawLine(this->blackPen_w1, X, Y, X+WD, Y);
}