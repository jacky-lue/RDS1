#include "HistLogForm.h"
#include "RDS_main_Form.h"
#include "RDS_project.h"
#include "Log.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::IO;
// ----- my main..
using namespace RDS;

//====================//
// To operation List  //
//====================//
System::Void HistLogForm::btn_ToReportList_Click(System::Object^  sender, System::EventArgs^  e)
{
    m_MainForm->open_Report_History();
    this->Close();
}

//====================//
//  Form Load !!!     //
//====================//
System::Void HistLogForm::HistLogForm_Load(System::Object^  sender, System::EventArgs^  e)
{
    //Some initial
    pageNo=0;
    this->textBox_UID_in->Text=UID; //display!!

    //initial (clear all data)
    initial_display();

    //get page-0 (10 items)
    int retNo=this->getList(pageNo, UID);

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
    }
    else
    {
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
        MessageBox::Show(MSG_HISTORY_LOG_NO_LIST_ITEMS, "NOTICE",
            MessageBoxButtons::OK,
            MessageBoxIcon::Information);
    }
    if(this->hasPrePage==false) this->btn_PrePage->Visible=false;
    else this->btn_PrePage->Visible=true;
    if(this->hasNextPage==false) this->btn_NextPage->Visible=false;
    else this->btn_NextPage->Visible=true;
}

//====================//
//  Form Closed !!!   //
//====================//
System::Void HistLogForm::HistLogForm_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e)
{
    m_MainForm->enable_History_btn();
}

//=====================//
// Initial all display //
//=====================//
void HistLogForm::initial_display()
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
}

//==================//
//  Get page list   // (report & by-UID directory)
//==================//
//before open this form, already checking the directory exist...
int HistLogForm::getList(int page, String^ UID)
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
    String^ fullpath;  //go to LOG/UID directory
    fullpath=this->Base_dir+RDS_NAS_LOG_DIR+RDS_NAS_BY_UID_DIR;
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
    if(this->total_items_inDir<readEnd)
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
        if(i==0) { this->I0_filename=fileAll[pos]; this->I0_text="20"+str_Y+"/"+str_M+"/"+str_D+"_"+daily_No2; }
        if(i==1) { this->I1_filename=fileAll[pos]; this->I1_text="20"+str_Y+"/"+str_M+"/"+str_D+"_"+daily_No2; }
        if(i==2) { this->I2_filename=fileAll[pos]; this->I2_text="20"+str_Y+"/"+str_M+"/"+str_D+"_"+daily_No2; }
        if(i==3) { this->I3_filename=fileAll[pos]; this->I3_text="20"+str_Y+"/"+str_M+"/"+str_D+"_"+daily_No2; }
        if(i==4) { this->I4_filename=fileAll[pos]; this->I4_text="20"+str_Y+"/"+str_M+"/"+str_D+"_"+daily_No2; }
        if(i==5) { this->I5_filename=fileAll[pos]; this->I5_text="20"+str_Y+"/"+str_M+"/"+str_D+"_"+daily_No2; }
        if(i==6) { this->I6_filename=fileAll[pos]; this->I6_text="20"+str_Y+"/"+str_M+"/"+str_D+"_"+daily_No2; }
        if(i==7) { this->I7_filename=fileAll[pos]; this->I7_text="20"+str_Y+"/"+str_M+"/"+str_D+"_"+daily_No2; }
        if(i==8) { this->I8_filename=fileAll[pos]; this->I8_text="20"+str_Y+"/"+str_M+"/"+str_D+"_"+daily_No2; }
        if(i==9) { this->I9_filename=fileAll[pos]; this->I9_text="20"+str_Y+"/"+str_M+"/"+str_D+"_"+daily_No2; }
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
void HistLogForm::showBriefReport(String^ readFileName)
{
    //
    this->readFilename=readFileName; //save as a record for future usage

    //check file
    if(File::Exists(readFileName)==false)
    {
        MessageBox::Show("file was found when listing, but now not found!!", "Error",
            MessageBoxButtons::OK,
            MessageBoxIcon::Information);
        return;
    }

    //clear old content
    this->richTextBox_Log->Text="";

    //read file content & decode
    String^ readLineStr;
    String^ CodeStr;
    String^ MeaningStr;
    String^ dispLineStr;
    String^ paraStr;
    String^ paraMeaningStr;
    String^ tmpStr;
    array<Char>^sep=gcnew array<Char>{
        ':'
    };
    array<String^>^result;
    int charPos;
    StreamReader^ sr=File::OpenText(readFileName);
    while((readLineStr=sr->ReadLine())!=nullptr)
    {
        //get two char code
        charPos=readLineStr->IndexOf(">");
        if(charPos>=0)
        {
            //code
            CodeStr=readLineStr->Substring(charPos+2, 2);

            //parameter
            paraStr=readLineStr->Substring(charPos+2);
            if(paraStr->Length>2)
            {
                paraStr=paraStr->Substring(2);
            }
            else
            {
                paraStr="";
            }

            //get meaning of code.
            MeaningStr="*"+CodeStr; //ofr unknow code...
            if(CodeStr=="CC") { MeaningStr=LOG_CODE_MEANING_CC; paraMeaningStr=""; }
            if(CodeStr=="CF") { MeaningStr=LOG_CODE_MEANING_CF; paraMeaningStr=""; }
            if(CodeStr=="CK") { MeaningStr=LOG_CODE_MEANING_CK; paraMeaningStr=""; }
            if(CodeStr=="DC") { MeaningStr=LOG_CODE_MEANING_DC; paraMeaningStr=""; }
            if(CodeStr=="IK") { MeaningStr=LOG_CODE_MEANING_IK; paraMeaningStr=""; }
            if(CodeStr=="TT") { MeaningStr=LOG_CODE_MEANING_TT; paraMeaningStr=""; }
            if(CodeStr=="T2")
            {
                MeaningStr=LOG_CODE_MEANING_T2;
                result=paraStr->Split(sep, StringSplitOptions::RemoveEmptyEntries);
                paraMeaningStr=" 20"+result[0]+"/"+result[1]+"/"+result[2]+" week-day="+result[3]+", "+
                    result[4]+":"+result[5];
            }
            if(CodeStr=="TK") { MeaningStr=LOG_CODE_MEANING_TK; paraMeaningStr=""; }
            if(CodeStr=="EE") { MeaningStr=LOG_CODE_MEANING_EE; paraMeaningStr=""; }
            if(CodeStr=="E2")
            {
                MeaningStr=LOG_CODE_MEANING_E2;
                result=paraStr->Split(sep, StringSplitOptions::RemoveEmptyEntries);
                paraMeaningStr=
                    " ECO1: Strat time = "+result[0]+":"+result[1]+" Duration = "+result[2]+":"+result[3]+" week="+result[4]
                    +" ECO1: Strat time = "+result[5]+":"+result[6]+" Duration = "+result[7]+":"+result[8]+" week="+result[9]
                    +" ECO1: Strat time = "+result[10]+":"+result[11]+" Duration = "+result[12]+":"+result[13]+" week="+result[14]
                    +" ECO1: Strat time = "+result[15]+":"+result[16]+" Duration = "+result[17]+":"+result[18]+" week="+result[19];
            }
            if(CodeStr=="EK") { MeaningStr=LOG_CODE_MEANING_EK; paraMeaningStr=""; }
            if(CodeStr=="FF") { MeaningStr=LOG_CODE_MEANING_FF; paraMeaningStr=""; }
            if(CodeStr=="F2")
            {
                MeaningStr=LOG_CODE_MEANING_F2;
                result=paraStr->Split(sep, StringSplitOptions::RemoveEmptyEntries);
                paraMeaningStr=" Strat time = "+result[0]+":"+result[1]+", Duration = "+result[2]+":"+result[3]
                    +", week="+result[4];
            }
            if(CodeStr=="FK") { MeaningStr=LOG_CODE_MEANING_FK; paraMeaningStr=""; }
            if(CodeStr=="ST")
            {
                MeaningStr=LOG_CODE_MEANING_ST;
                paraMeaningStr=paraStr->Replace(":", "");
            }
            if(CodeStr=="FD")
            {
                MeaningStr=LOG_CODE_MEANING_FD;
                paraMeaningStr=paraStr->Replace(":", "")+"days";
            }
            if(CodeStr=="UD")
            {
                MeaningStr=LOG_CODE_MEANING_UD;
                paraMeaningStr=paraStr->Replace(":", "")+"days";
            }
            if(CodeStr=="1H") { MeaningStr=LOG_CODE_MEANING_1H; paraMeaningStr=""; }
            if(CodeStr=="1L") { MeaningStr=LOG_CODE_MEANING_1L; paraMeaningStr=""; }
            if(CodeStr=="1F") { MeaningStr=LOG_CODE_MEANING_1F; paraMeaningStr=""; }
            if(CodeStr=="2H") { MeaningStr=LOG_CODE_MEANING_2H; paraMeaningStr=""; }
            if(CodeStr=="2L") { MeaningStr=LOG_CODE_MEANING_2L; paraMeaningStr=""; }
            if(CodeStr=="2F") { MeaningStr=LOG_CODE_MEANING_2F; paraMeaningStr=""; }
            if(CodeStr=="3H") { MeaningStr=LOG_CODE_MEANING_3H; paraMeaningStr=""; }
            if(CodeStr=="3L") { MeaningStr=LOG_CODE_MEANING_3L; paraMeaningStr=""; }
            if(CodeStr=="3F") { MeaningStr=LOG_CODE_MEANING_3F; paraMeaningStr=""; }
            if(CodeStr=="B1") { MeaningStr=LOG_CODE_MEANING_B1; paraMeaningStr=""; }
            if(CodeStr=="B0") { MeaningStr=LOG_CODE_MEANING_B0; paraMeaningStr=""; }
            if(CodeStr=="UL") { MeaningStr=LOG_CODE_MEANING_UL; paraMeaningStr=""; }
            if(CodeStr=="LT") { MeaningStr=LOG_CODE_MEANING_LT; paraMeaningStr=""; }
            if(CodeStr=="LS") { MeaningStr=LOG_CODE_MEANING_LS; paraMeaningStr=""; }
            if(CodeStr=="LP") { MeaningStr=LOG_CODE_MEANING_LP; paraMeaningStr=""; }
            if(CodeStr=="LA") { MeaningStr=LOG_CODE_MEANING_LA; paraMeaningStr=""; }
            if(CodeStr=="E1") { MeaningStr=LOG_CODE_MEANING_E1; paraMeaningStr=""; }
            if(CodeStr=="E0") { MeaningStr=LOG_CODE_MEANING_E0; paraMeaningStr=""; }
            if(CodeStr=="EH") { MeaningStr=LOG_CODE_MEANING_EH; paraMeaningStr=""; }
            if(CodeStr=="AD") { MeaningStr=LOG_CODE_MEANING_AD; paraMeaningStr=""; }
            if(CodeStr=="AK") { MeaningStr=LOG_CODE_MEANING_AK; paraMeaningStr=""; }
            if(CodeStr=="HR") { MeaningStr=LOG_CODE_MEANING_HR; paraMeaningStr=""; }
            if(CodeStr=="HL") { MeaningStr=LOG_CODE_MEANING_HL; paraMeaningStr=""; }
            if(CodeStr=="SC") { MeaningStr=LOG_CODE_MEANING_SC; paraMeaningStr=""; }
            if(CodeStr=="SL") { MeaningStr=LOG_CODE_MEANING_SL; paraMeaningStr=""; }
            if(CodeStr=="RS") { MeaningStr=LOG_CODE_MEANING_RS; paraMeaningStr=""; }
            if(CodeStr=="RT") { MeaningStr=LOG_CODE_MEANING_RT; paraMeaningStr=""; }
            if(CodeStr=="RP") { MeaningStr=LOG_CODE_MEANING_RP; paraMeaningStr=""; }
            if(CodeStr=="AN")
            {
                MeaningStr=LOG_CODE_MEANING_AN;
                paraMeaningStr=paraStr->Replace(":", " ");
            }
            if(CodeStr=="AA")
            {
                MeaningStr=LOG_CODE_MEANING_AA;
                paraMeaningStr=paraStr->Replace(":", " ");
            }
            if(CodeStr=="AF")
            {
                MeaningStr=LOG_CODE_MEANING_AF;
                result=paraStr->Split(sep, StringSplitOptions::RemoveEmptyEntries);
                paraMeaningStr=" Strat time = "+result[0]+":"+result[1]+", Duration = "+result[2]+":"+result[3]
                    +", week="+result[4];
            }
            if(CodeStr=="SS") { MeaningStr=LOG_CODE_MEANING_SS; paraMeaningStr=""; }
            if(CodeStr=="S2")
            {
                MeaningStr=LOG_CODE_MEANING_S2;
                paraMeaningStr=paraStr->Replace(":", "");
            }
            if(CodeStr=="SK") { MeaningStr=LOG_CODE_MEANING_SK; paraMeaningStr=""; }
            if(CodeStr=="PP") { MeaningStr=LOG_CODE_MEANING_PP; paraMeaningStr=""; }
            if(CodeStr=="P2")
            {
                MeaningStr=LOG_CODE_MEANING_P2;
                result=paraStr->Split(sep, StringSplitOptions::RemoveEmptyEntries);
                paraMeaningStr=" Strat time = "+result[0]+":"+result[1]+", Duration = "+result[2]+":"+result[3];
            }
            if(CodeStr=="PK") { MeaningStr=LOG_CODE_MEANING_PK; paraMeaningStr=""; }
            if(CodeStr=="XX") { MeaningStr=LOG_CODE_MEANING_XX; paraMeaningStr=""; }

            //build new line strin.
            dispLineStr=readLineStr->Replace(CodeStr, MeaningStr);
            if(paraStr!="")
            {
                dispLineStr=dispLineStr->Replace(paraStr, paraMeaningStr);
            }
            //display it
            this->richTextBox_Log->Text+=dispLineStr+Environment::NewLine;
        }//end if found char">"
    }

    //--close file
    sr->Close();

    //enable/disable Pre/Next-Page button.
    this->btn_NextPage->Visible=this->hasNextPage;
    this->btn_PrePage->Visible=this->hasPrePage;
}

//==================//
// Pre-Page Button  //
//==================//
System::Void HistLogForm::btn_PrePage_Click(System::Object^  sender, System::EventArgs^  e)
{
    pageNo--;
    getList(pageNo, UID);

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
System::Void HistLogForm::btn_NextPage_Click(System::Object^  sender, System::EventArgs^  e)
{
    pageNo++;
    getList(pageNo, UID);

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

//===========================================================================================
//===========================================================================================
// List clicking

System::Void HistLogForm::label0_Click(System::Object^  sender, System::EventArgs^  e)
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

System::Void HistLogForm::label1_Click(System::Object^  sender, System::EventArgs^  e)
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

System::Void HistLogForm::label2_Click(System::Object^  sender, System::EventArgs^  e)
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

System::Void HistLogForm::label3_Click(System::Object^  sender, System::EventArgs^  e)
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

System::Void HistLogForm::label4_Click(System::Object^  sender, System::EventArgs^  e)
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

System::Void HistLogForm::label5_Click(System::Object^  sender, System::EventArgs^  e)
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

System::Void HistLogForm::label6_Click(System::Object^  sender, System::EventArgs^  e)
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

System::Void HistLogForm::label7_Click(System::Object^  sender, System::EventArgs^  e)
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

System::Void HistLogForm::label8_Click(System::Object^  sender, System::EventArgs^  e)
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

System::Void HistLogForm::label9_Click(System::Object^  sender, System::EventArgs^  e)
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