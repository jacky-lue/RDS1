#include "HistoryForm.h"
#include "RDS_main_Form.h"
#include "RDS_project.h"

//error message gobal table
#include "ErrMsg.h"

extern struct Encode_Cause_Equpiment_type RPT_all_Cause[CUASE_RPT_TABLE_SIZE];
extern struct Encode_Equpiment_type RPT_all_Equip[EQUIP_RPT_TABLE_SIZE];

using namespace System;
using namespace System::Windows::Forms;
using namespace System::IO;
// ----- my main..
using namespace RDS;

//====================//
// To operation List  //
//====================//
System::Void HistoryForm::btn_ToOperationList_Click(System::Object^  sender, System::EventArgs^  e)
{
    m_MainForm->open_Log_History();
    this->Close();
}

//====================//
//  Form Load !!!     //
//====================//
System::Void HistoryForm::HistoryForm_Load(System::Object^  sender, System::EventArgs^  e)
{
    int retNo;
    //Some initial
    pageNo=0;
    this->textBox_UID_in->Text=UID; //display!!

    //initial (clear all data)
    initial_display();

    //get page-0 (10 items)
    retNo=this->getReportList(pageNo, UID);

    if(retNo>0)
    {
        //get item-0 content
        this->showBriefReport(I0_filename);
        this->panel0->BackColor=Color::Yellow;
        this->panel1->BackColor=Color::LightBlue;
        this->panel2->BackColor=Color::LightBlue;
        this->panel3->BackColor=Color::LightBlue;
        this->panel4->BackColor=Color::LightBlue;
        this->panel5->BackColor=Color::LightBlue;
        this->panel6->BackColor=Color::LightBlue;
        this->panel7->BackColor=Color::LightBlue;
        this->panel8->BackColor=Color::LightBlue;
        this->panel9->BackColor=Color::LightBlue;
        //
        this->button_fullReport->Enabled=true;
    }
    else
    {
        //
        this->button_fullReport->Enabled=false;
        //
        this->panel0->BackColor=Color::LightBlue;
        this->panel1->BackColor=Color::LightBlue;
        this->panel2->BackColor=Color::LightBlue;
        this->panel3->BackColor=Color::LightBlue;
        this->panel4->BackColor=Color::LightBlue;
        this->panel5->BackColor=Color::LightBlue;
        this->panel6->BackColor=Color::LightBlue;
        this->panel7->BackColor=Color::LightBlue;
        this->panel8->BackColor=Color::LightBlue;
        this->panel9->BackColor=Color::LightBlue;
        this->panel0->Enabled=false;
        this->panel1->Enabled=false;
        this->panel2->Enabled=false;
        this->panel3->Enabled=false;
        this->panel4->Enabled=false;
        this->panel5->Enabled=false;
        this->panel6->Enabled=false;
        this->panel7->Enabled=false;
        this->panel8->Enabled=false;
        this->panel9->Enabled=false;
        //
        MessageBox::Show(MSG_HISTORYFORM_NO_LIST_ITEMS, "NOTICE",
            MessageBoxButtons::OK,
            MessageBoxIcon::Information);
    }

    if(this->hasPrePage==false) this->btn_PrePage->Visible=false;
    else this->btn_PrePage->Visible=true;
    if(this->hasNextPage==false) this->btn_NextPage->Visible=false;
    else this->btn_NextPage->Visible=true;
}

//=====================//
// Initial all display //
//=====================//
void HistoryForm::initial_display()
{
    this->label0->Text="";
    this->label1->Text="";
    this->label2->Text="";
    this->label3->Text="";
    this->label4->Text="";
    this->label5->Text="";
    this->label6->Text="";
    this->label7->Text="";
    this->label8->Text="";
    this->label9->Text="";
    this->textBox_owner->Text="";
    this->textBox_SpaSerial->Text="";
    this->textBox_HotTub->Text="";
    this->textBox_Date->Text="";
    this->textBox_CRperson->Text="";
    this->textBox_ErrMsg->Text="";
    this->textBox_pCause->Text="";
    this->textBox_SCstr->Text="";
    this->richTextBox_equipments->Text="";
    this->richTextBox_replace->Text="";
    this->richTextBox_comment->Text="";
}

//====================//
//  Form Closed !!!   //
//====================//
System::Void HistoryForm::HistoryForm_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e)
{
    m_MainForm->enable_History_btn();
}

//==================//
//  Get page list   // (report & by-UID directory)
//==================//
//before open this form, already checking the directory exist...
int HistoryForm::getReportList(int page, String^ UID)
{
    int readStart;
    int readEnd;
    int StartPos;
    String^ NoDirFilename;
    String^ daily_No;
    String^ daily_No1;
    String^ daily_No2;
    String^ str_Y;
    String^ str_M;
    String^ str_D;
    String^ fullpath;  //go to Report/UID directory
    fullpath=this->Base_dir+RDS_NAS_REPORT_DIR+RDS_NAS_BY_UID_DIR;
    String^ sub_UID;
    sub_UID=UID->Substring(0, RDS_NAS_UID_SUBDIR_1ST_PART);
    fullpath+=sub_UID;
    fullpath+="\\"+UID;

    //first, check directory
    if(Directory::Exists(fullpath)==false)
    {
        this->hasPrePage=false;
        this->hasNextPage=false;
        return 0;
    }

    //get all files in directory
    array<String^>^ fileAll=Directory::GetFiles(fullpath);
    if(fileAll->Length==0)
    {
        this->hasPrePage=false;
        this->hasNextPage=false;
        return 0;
    }
    IComparer^ revComparer=gcnew ReverseComparer();
    Array::Sort(fileAll, revComparer);

    this->total_items_inDir=fileAll->Length;

    //defien reading range
    readStart=page * HIST_ITEMS_PER_PAGE;
    readEnd=(page+1) * HIST_ITEMS_PER_PAGE; //this one not read
    if(readStart>=HIST_ITEMS_PER_PAGE)
        this->hasPrePage=true;
    else this->hasPrePage=false;
    if(this->total_items_inDir<=readEnd)
    {
        readEnd=this->total_items_inDir;
        this->hasNextPage=false; //if so, upper layer cannot use next pageNo
    }
    else this->hasNextPage=true;

    //clear all before reading-scan
    this->I0_filename=""; this->I0_text="";
    this->I1_filename=""; this->I1_text="";
    this->I2_filename=""; this->I2_text="";
    this->I3_filename=""; this->I3_text="";
    this->I4_filename=""; this->I4_text="";
    this->I5_filename=""; this->I5_text="";
    this->I6_filename=""; this->I6_text="";
    this->I7_filename=""; this->I7_text="";
    this->I8_filename=""; this->I8_text="";
    this->I9_filename=""; this->I9_text="";
    //read filename list
    int pos=readStart;
    for(int i=0; i<HIST_ITEMS_PER_PAGE; i++)
    {
        StartPos=fileAll[pos]->LastIndexOf("\\");
        NoDirFilename=fileAll[pos]->Substring(StartPos+1);
        str_Y=NoDirFilename->Substring(21, 4);  //2016.0820. new
        str_M=NoDirFilename->Substring(25, 2);
        str_D=NoDirFilename->Substring(27, 2);
        StartPos=NoDirFilename->IndexOf("_");
        daily_No=NoDirFilename->Substring(StartPos+1);
        StartPos=daily_No->IndexOf("_");
        daily_No1=daily_No->Substring(StartPos+1);
        StartPos=daily_No1->LastIndexOf(".");
        daily_No2=daily_No1->Substring(0, StartPos);
        //get them first
        if(i==0) { this->I0_filename=fileAll[pos]; this->I0_text=str_Y+"/"+str_M+"/"+str_D+"_"+daily_No2; }
        if(i==1) { this->I1_filename=fileAll[pos]; this->I1_text=str_Y+"/"+str_M+"/"+str_D+"_"+daily_No2; }
        if(i==2) { this->I2_filename=fileAll[pos]; this->I2_text=str_Y+"/"+str_M+"/"+str_D+"_"+daily_No2; }
        if(i==3) { this->I3_filename=fileAll[pos]; this->I3_text=str_Y+"/"+str_M+"/"+str_D+"_"+daily_No2; }
        if(i==4) { this->I4_filename=fileAll[pos]; this->I4_text=str_Y+"/"+str_M+"/"+str_D+"_"+daily_No2; }
        if(i==5) { this->I5_filename=fileAll[pos]; this->I5_text=str_Y+"/"+str_M+"/"+str_D+"_"+daily_No2; }
        if(i==6) { this->I6_filename=fileAll[pos]; this->I6_text=str_Y+"/"+str_M+"/"+str_D+"_"+daily_No2; }
        if(i==7) { this->I7_filename=fileAll[pos]; this->I7_text=str_Y+"/"+str_M+"/"+str_D+"_"+daily_No2; }
        if(i==8) { this->I8_filename=fileAll[pos]; this->I8_text=str_Y+"/"+str_M+"/"+str_D+"_"+daily_No2; }
        if(i==9) { this->I9_filename=fileAll[pos]; this->I9_text=str_Y+"/"+str_M+"/"+str_D+"_"+daily_No2; }
        //increment & judgement
        pos++;
        if(pos==readEnd) break;
    }
    //update display list
    this->label0->Text=this->I0_text; this->panel0->Enabled=true; this->label0->Enabled=true;
    this->label1->Text=this->I1_text; this->panel1->Enabled=true; this->label1->Enabled=true;
    this->label2->Text=this->I2_text; this->panel2->Enabled=true; this->label2->Enabled=true;
    this->label3->Text=this->I3_text; this->panel3->Enabled=true; this->label3->Enabled=true;
    this->label4->Text=this->I4_text; this->panel4->Enabled=true; this->label4->Enabled=true;
    this->label5->Text=this->I5_text; this->panel5->Enabled=true; this->label5->Enabled=true;
    this->label6->Text=this->I6_text; this->panel6->Enabled=true; this->label6->Enabled=true;
    this->label7->Text=this->I7_text; this->panel7->Enabled=true; this->label7->Enabled=true;
    this->label8->Text=this->I8_text; this->panel8->Enabled=true; this->label8->Enabled=true;
    this->label9->Text=this->I9_text; this->panel9->Enabled=true; this->label9->Enabled=true;
    if(this->I0_text=="") { this->panel0->Enabled=false; this->label0->Enabled=false; }
    if(this->I1_text=="") { this->panel1->Enabled=false; this->label1->Enabled=false; }
    if(this->I2_text=="") { this->panel2->Enabled=false; this->label2->Enabled=false; }
    if(this->I3_text=="") { this->panel3->Enabled=false; this->label3->Enabled=false; }
    if(this->I4_text=="") { this->panel4->Enabled=false; this->label4->Enabled=false; }
    if(this->I5_text=="") { this->panel5->Enabled=false; this->label5->Enabled=false; }
    if(this->I6_text=="") { this->panel6->Enabled=false; this->label6->Enabled=false; }
    if(this->I7_text=="") { this->panel7->Enabled=false; this->label7->Enabled=false; }
    if(this->I8_text=="") { this->panel8->Enabled=false; this->label8->Enabled=false; }
    if(this->I9_text=="") { this->panel9->Enabled=false; this->label9->Enabled=false; }

    //return
    return this->total_items_inDir;
}

//===================//
// Show Brief report //
//===================//
void HistoryForm::showBriefReport(String^ readFileName)
{
    int StartPos;
    String^ NoDirFilename;
    //
    StartPos=readFileName->LastIndexOf("\\");
    NoDirFilename=readFileName->Substring(StartPos+1);
    StartPos=NoDirFilename->LastIndexOf(".");
    this->SC_no=NoDirFilename->Substring(0, StartPos);
    StartPos=this->SC_no->LastIndexOf("_P");
    if(StartPos>0)
        this->textBox_SCstr->Text=this->SC_no; //display
    else
        this->textBox_SCstr->Text="";

    this->readFilename=readFileName; //save as a record for future usage (display full report)

    //check file
    if(File::Exists(readFileName)==false)
    {
        MessageBox::Show(MSG_REPORT_FILE_NOT_FOUND_ERROR, "Error",
            MessageBoxButtons::OK,
            MessageBoxIcon::Information);
        return;
    }

    String^ readLineStr;
    String^ tmpStr;
    int tmpInt;
    StreamReader^ din=File::OpenText(readFileName);

    //read basic information
    readLineStr=din->ReadLine(); //line1 = UID
    if(this->UID!=readLineStr)
    {
        MessageBox::Show(MSG_HISTORYFORM_UID_NOT_MATCH, "Error",
            MessageBoxButtons::OK,
            MessageBoxIcon::Information);
    }

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
    this->textBox_Date->Text=this->RPT_date; //display!!

    readLineStr=din->ReadLine(); //line3 = time

    readLineStr=din->ReadLine(); //line4 = Hot Tub model name (selectIndex)
    //tmpInt = Convert::ToInt32(readLineStr, 10);
    //if (tmpInt == 0) this->spa_model_name = "Spa-1";
    //else if (tmpInt == 1) this->spa_model_name = "Spa-2";
    //else if (tmpInt == 2) this->spa_model_name = "Spa-3";
    //else this->spa_model_name = "unknow!!";
    this->spa_model_name=readLineStr;
    this->textBox_HotTub->Text=this->spa_model_name;

    readLineStr=din->ReadLine(); //line5 = Spa serial number
    this->spa_serial=readLineStr;
    this->textBox_SpaSerial->Text=this->spa_serial;

    readLineStr=din->ReadLine(); //line6 = Spa owner
    this->spa_owner=readLineStr;
    this->textBox_owner->Text=this->spa_owner;

    readLineStr=din->ReadLine(); //line7 = CR person (operator)
    this->cr_operatorName=readLineStr;
    this->textBox_CRperson->Text=this->cr_operatorName;

    readLineStr=din->ReadLine(); //line8 = current water temperature
    readLineStr=din->ReadLine(); //line9 = set temperature
    readLineStr=din->ReadLine(); //line10 = High Limit temperature
    readLineStr=din->ReadLine(); //line11 = PCB temperature
    readLineStr=din->ReadLine(); //line12 = Starting Error
    this->StartErr=readLineStr;
    readLineStr=din->ReadLine(); //line13 = Ending Error
    this->EndErr=readLineStr;
    this->textBox_ErrMsg->Text=this->StartErr; //display

    readLineStr=din->ReadLine(); //line14 = Voltage max
    readLineStr=din->ReadLine(); //line15 = Voltage cur
    readLineStr=din->ReadLine(); //line16 = Voltage min
    readLineStr=din->ReadLine(); //line17 = HiLimit max
    readLineStr=din->ReadLine(); //line18 = HiLimit cur
    readLineStr=din->ReadLine(); //line19 = HiLimit min
    readLineStr=din->ReadLine(); //line20 = Spa Temp max
    readLineStr=din->ReadLine(); //line21 = Spa Temp cur
    readLineStr=din->ReadLine(); //line22 = Spa Temp min
    readLineStr=din->ReadLine(); //line23 = PCB Temp max
    readLineStr=din->ReadLine(); //line24 = PCB Temp cur
    readLineStr=din->ReadLine(); //line25 = PCB Temp min

    readLineStr=din->ReadLine(); //line26 = CR comment
    this->CR_comment=readLineStr;
    this->richTextBox_comment->Text=this->CR_comment;

    readLineStr=din->ReadLine(); //line27 = Replace parts
    this->replaced_parts=readLineStr;
    this->richTextBox_replace->Text=this->replaced_parts;

    readLineStr=din->ReadLine(); //line28 = M0_HC current
    readLineStr=din->ReadLine(); //line29 = M0_C current
    readLineStr=din->ReadLine(); //line30 = M0 current
    readLineStr=din->ReadLine(); //line31 = M1 current
    readLineStr=din->ReadLine(); //line32 = M2 current
    readLineStr=din->ReadLine(); //line33 = M3 current
    readLineStr=din->ReadLine(); //line34 = M4 current
    readLineStr=din->ReadLine(); //line35 = M5 current
    readLineStr=din->ReadLine(); //line36 = M6 current
    readLineStr=din->ReadLine(); //line37 = M7 current
    readLineStr=din->ReadLine(); //line38 = AD_CauseEquio_TotalCnt

    //read possible cause
    readLineStr=din->ReadLine(); //line39
    this->textBox_pCause->Text=""; //reset it...
    int tmpNo;
    array<Char>^sep=gcnew array<Char>{','};
    array<String^>^result;
    if(readLineStr!="N/A")
    {
        result=readLineStr->Split(sep, StringSplitOptions::RemoveEmptyEntries);
        for(int i=0; i<result->Length; i++)
        {
            tmpNo=Convert::ToInt32(result[i], 10);
            if(tmpNo>=CUASE_RPT_TABLE_SIZE||tmpNo<0)
            {//error
                MessageBox::Show(MSG_REPORT_CAUSE_NUMBER_OVER_RANGE, "Error",
                    MessageBoxButtons::OK,
                    MessageBoxIcon::Information);
            }
            else
            {
                result[i]=gcnew String(RPT_all_Cause[tmpNo].CE_string);
            }
        }//end-for-loop i
        this->textBox_pCause->Text=result[0];
    }
    else this->textBox_pCause->Text=readLineStr;

    //read equipments
    readLineStr=din->ReadLine(); //line40
    this->richTextBox_equipments->Text=""; //reset it...
    if(readLineStr!="N/A")
    {
        result=readLineStr->Split(sep, StringSplitOptions::RemoveEmptyEntries);
        for(int i=0; i<result->Length; i++)
        {
            tmpNo=Convert::ToInt32(result[i], 10);
            if(tmpNo>=EQUIP_RPT_TABLE_SIZE||tmpNo<0)
            {//error
                MessageBox::Show(MSG_REPORT_CAUSE_NUMBER_OVER_RANGE, "Error",
                    MessageBoxButtons::OK,
                    MessageBoxIcon::Information);
            }
            else
            {
                result[i]=gcnew String(RPT_all_Equip[tmpNo].CE_string);
                this->richTextBox_equipments->Text+=result[i]+",";
            }
        }//end-for-loop i
    }
    else this->richTextBox_equipments->Text=readLineStr;

    //-------
    din->Close();

    //enable/disable Pre/Next-Page button.
    this->btn_NextPage->Visible=this->hasNextPage;
    this->btn_PrePage->Visible=this->hasPrePage;
}

//==================//
// Pre-Page Button  //
//==================//
System::Void HistoryForm::btn_PrePage_Click(System::Object^  sender, System::EventArgs^  e)
{
    pageNo--;
    getReportList(pageNo, UID);

    //get item-0 content
    this->showBriefReport(I0_filename);
    this->panel0->BackColor=Color::Yellow;
    this->panel1->BackColor=Color::LightBlue;
    this->panel2->BackColor=Color::LightBlue;
    this->panel3->BackColor=Color::LightBlue;
    this->panel4->BackColor=Color::LightBlue;
    this->panel5->BackColor=Color::LightBlue;
    this->panel6->BackColor=Color::LightBlue;
    this->panel7->BackColor=Color::LightBlue;
    this->panel8->BackColor=Color::LightBlue;
    this->panel9->BackColor=Color::LightBlue;
}

//==================//
// Next-Page Button //
//==================//
System::Void HistoryForm::btn_NextPage_Click(System::Object^  sender, System::EventArgs^  e)
{
    pageNo++;
    getReportList(pageNo, UID);

    //get item-0 content
    this->showBriefReport(I0_filename);
    this->panel0->BackColor=Color::Yellow;
    this->panel1->BackColor=Color::LightBlue;
    this->panel2->BackColor=Color::LightBlue;
    this->panel3->BackColor=Color::LightBlue;
    this->panel4->BackColor=Color::LightBlue;
    this->panel5->BackColor=Color::LightBlue;
    this->panel6->BackColor=Color::LightBlue;
    this->panel7->BackColor=Color::LightBlue;
    this->panel8->BackColor=Color::LightBlue;
    this->panel9->BackColor=Color::LightBlue;
}

//====================//
// full Report Button //
//====================//
System::Void HistoryForm::button_fullReport_Click(System::Object^  sender, System::EventArgs^  e)
{
    m_MainForm->open_Full_Report(this->readFilename);
}

//===========================================================================================
//===========================================================================================
// List clicking

System::Void HistoryForm::label0_Click(System::Object^  sender, System::EventArgs^  e)
{
    this->showBriefReport(I0_filename);
    this->panel0->BackColor=Color::Yellow;
    this->panel1->BackColor=Color::LightBlue;
    this->panel2->BackColor=Color::LightBlue;
    this->panel3->BackColor=Color::LightBlue;
    this->panel4->BackColor=Color::LightBlue;
    this->panel5->BackColor=Color::LightBlue;
    this->panel6->BackColor=Color::LightBlue;
    this->panel7->BackColor=Color::LightBlue;
    this->panel8->BackColor=Color::LightBlue;
    this->panel9->BackColor=Color::LightBlue;
}

System::Void HistoryForm::label1_Click(System::Object^  sender, System::EventArgs^  e)
{
    this->showBriefReport(I1_filename);
    this->panel0->BackColor=Color::LightBlue;
    this->panel1->BackColor=Color::Yellow;
    this->panel2->BackColor=Color::LightBlue;
    this->panel3->BackColor=Color::LightBlue;
    this->panel4->BackColor=Color::LightBlue;
    this->panel5->BackColor=Color::LightBlue;
    this->panel6->BackColor=Color::LightBlue;
    this->panel7->BackColor=Color::LightBlue;
    this->panel8->BackColor=Color::LightBlue;
    this->panel9->BackColor=Color::LightBlue;
}

System::Void HistoryForm::label2_Click(System::Object^  sender, System::EventArgs^  e)
{
    this->showBriefReport(I2_filename);
    this->panel0->BackColor=Color::LightBlue;
    this->panel1->BackColor=Color::LightBlue;
    this->panel2->BackColor=Color::Yellow;
    this->panel3->BackColor=Color::LightBlue;
    this->panel4->BackColor=Color::LightBlue;
    this->panel5->BackColor=Color::LightBlue;
    this->panel6->BackColor=Color::LightBlue;
    this->panel7->BackColor=Color::LightBlue;
    this->panel8->BackColor=Color::LightBlue;
    this->panel9->BackColor=Color::LightBlue;
}

System::Void HistoryForm::label3_Click(System::Object^  sender, System::EventArgs^  e)
{
    this->showBriefReport(I3_filename);
    this->panel0->BackColor=Color::LightBlue;
    this->panel1->BackColor=Color::LightBlue;
    this->panel2->BackColor=Color::LightBlue;
    this->panel3->BackColor=Color::Yellow;
    this->panel4->BackColor=Color::LightBlue;
    this->panel5->BackColor=Color::LightBlue;
    this->panel6->BackColor=Color::LightBlue;
    this->panel7->BackColor=Color::LightBlue;
    this->panel8->BackColor=Color::LightBlue;
    this->panel9->BackColor=Color::LightBlue;
}

System::Void HistoryForm::label4_Click(System::Object^  sender, System::EventArgs^  e)
{
    this->showBriefReport(I4_filename);
    this->panel0->BackColor=Color::LightBlue;
    this->panel1->BackColor=Color::LightBlue;
    this->panel2->BackColor=Color::LightBlue;
    this->panel3->BackColor=Color::LightBlue;
    this->panel4->BackColor=Color::Yellow;
    this->panel5->BackColor=Color::LightBlue;
    this->panel6->BackColor=Color::LightBlue;
    this->panel7->BackColor=Color::LightBlue;
    this->panel8->BackColor=Color::LightBlue;
    this->panel9->BackColor=Color::LightBlue;
}

System::Void HistoryForm::label5_Click(System::Object^  sender, System::EventArgs^  e)
{
    this->showBriefReport(I5_filename);
    this->panel0->BackColor=Color::LightBlue;
    this->panel1->BackColor=Color::LightBlue;
    this->panel2->BackColor=Color::LightBlue;
    this->panel3->BackColor=Color::LightBlue;
    this->panel4->BackColor=Color::LightBlue;
    this->panel5->BackColor=Color::Yellow;
    this->panel6->BackColor=Color::LightBlue;
    this->panel7->BackColor=Color::LightBlue;
    this->panel8->BackColor=Color::LightBlue;
    this->panel9->BackColor=Color::LightBlue;
}

System::Void HistoryForm::label6_Click(System::Object^  sender, System::EventArgs^  e)
{
    this->showBriefReport(I6_filename);
    this->panel0->BackColor=Color::LightBlue;
    this->panel1->BackColor=Color::LightBlue;
    this->panel2->BackColor=Color::LightBlue;
    this->panel3->BackColor=Color::LightBlue;
    this->panel4->BackColor=Color::LightBlue;
    this->panel5->BackColor=Color::LightBlue;
    this->panel6->BackColor=Color::Yellow;
    this->panel7->BackColor=Color::LightBlue;
    this->panel8->BackColor=Color::LightBlue;
    this->panel9->BackColor=Color::LightBlue;
}

System::Void HistoryForm::label7_Click(System::Object^  sender, System::EventArgs^  e)
{
    this->showBriefReport(I7_filename);
    this->panel0->BackColor=Color::LightBlue;
    this->panel1->BackColor=Color::LightBlue;
    this->panel2->BackColor=Color::LightBlue;
    this->panel3->BackColor=Color::LightBlue;
    this->panel4->BackColor=Color::LightBlue;
    this->panel5->BackColor=Color::LightBlue;
    this->panel6->BackColor=Color::LightBlue;
    this->panel7->BackColor=Color::Yellow;
    this->panel8->BackColor=Color::LightBlue;
    this->panel9->BackColor=Color::LightBlue;
}

System::Void HistoryForm::label8_Click(System::Object^  sender, System::EventArgs^  e)
{
    this->showBriefReport(I8_filename);
    this->panel0->BackColor=Color::LightBlue;
    this->panel1->BackColor=Color::LightBlue;
    this->panel2->BackColor=Color::LightBlue;
    this->panel3->BackColor=Color::LightBlue;
    this->panel4->BackColor=Color::LightBlue;
    this->panel5->BackColor=Color::LightBlue;
    this->panel6->BackColor=Color::LightBlue;
    this->panel7->BackColor=Color::LightBlue;
    this->panel8->BackColor=Color::Yellow;
    this->panel9->BackColor=Color::LightBlue;
}

System::Void HistoryForm::label9_Click(System::Object^  sender, System::EventArgs^  e)
{
    this->showBriefReport(I9_filename);
    this->panel0->BackColor=Color::LightBlue;
    this->panel1->BackColor=Color::LightBlue;
    this->panel2->BackColor=Color::LightBlue;
    this->panel3->BackColor=Color::LightBlue;
    this->panel4->BackColor=Color::LightBlue;
    this->panel5->BackColor=Color::LightBlue;
    this->panel6->BackColor=Color::LightBlue;
    this->panel7->BackColor=Color::LightBlue;
    this->panel8->BackColor=Color::LightBlue;
    this->panel9->BackColor=Color::Yellow;
}