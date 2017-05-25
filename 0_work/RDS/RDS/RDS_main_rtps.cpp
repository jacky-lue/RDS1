//project defines
#include "RDS_project.h"

//for VC program all forms
#include "RDS_main_Form.h"

//error message gobal table
#include "ErrMsg.h"

//using global variable which define in main_global.h
extern char* eMSG_Table[2][MAX_INDEX_OF_ERR_TABLE];
extern unsigned char AD_all_Cause[AUTO_DIAGNOSIS_MAX_CUASE];
extern unsigned char AD_all_Equip[AUTO_DIAGNOSIS_MAX_EQUIP];

using namespace System;
using namespace System::Windows::Forms;
using namespace System::IO;
// ----- my main..
using namespace RDS;

//The function body of class RDS_main_Form here --------------------------------------------

//=================//
// Report Save     //
//=================//
void  RDS_main_Form::RPT_save(String^ UID)
{
    String^ lindStr;
    String^ tmpStr;
    float tmpFp;
    int tmpIp;
    //======== prepare file name =============
    String^ fullfilename1;  //save to by UID directory
    String^ fullfilename2;  //save to by Date director
    String^ fullfilename3;  //save to OpenServiceCall
    fullfilename1=this->Base_dir+RDS_NAS_REPORT_DIR+RDS_NAS_BY_UID_DIR;
    fullfilename2=this->Base_dir+RDS_NAS_REPORT_DIR+RDS_NAS_BY_DATE_DIR;
    fullfilename3=this->Base_dir+RDS_NAS_SERVICE_DIR+"\\"+this->Cur_RDSreport_str+".csv";
    String^ curYear;
    String^ curMonth;
    String^ curDay;
    DateTime dt=DateTime::Now;
    curYear=dt.ToString("yyyy", DateTimeFormatInfo::InvariantInfo);
    curMonth=dt.ToString("MM", DateTimeFormatInfo::InvariantInfo);
    curDay=dt.ToString("dd", DateTimeFormatInfo::InvariantInfo);
    fullfilename2+=curYear+"\\";
    if(Directory::Exists(fullfilename2)==false) Directory::CreateDirectory(fullfilename2);
    fullfilename2+=curMonth+"\\";
    if(Directory::Exists(fullfilename2)==false) Directory::CreateDirectory(fullfilename2);
    fullfilename2+=curDay+"\\";
    if(Directory::Exists(fullfilename2)==false) Directory::CreateDirectory(fullfilename2);
    //
    String^ sub_UID;
    if(UID->Length!=RDS_UID_WHOLE_LENGTH)
    {
        MessageBox::Show(MSG_MAINRPT_UID_LENGTH_ERROR, "Error",
            MessageBoxButtons::OK,
            MessageBoxIcon::Information);
        return;
    }
    sub_UID=UID->Substring(0, RDS_NAS_UID_SUBDIR_1ST_PART);
    fullfilename1+=sub_UID+"\\";
    if(Directory::Exists(fullfilename1)==false) Directory::CreateDirectory(fullfilename1);
    fullfilename1+=UID+"\\";
    if(Directory::Exists(fullfilename1)==false) Directory::CreateDirectory(fullfilename1);
    //
    fullfilename1+=this->Cur_RDSreport_str+".csv";
    fullfilename2+=this->Cur_RDSreport_str+".csv";

    //remember it!!!!
    this->RDS_save_filename=fullfilename1;
    if(DEBUGGING_USEAGE==2)MsgMain2("f1="+fullfilename1);
    if(DEBUGGING_USEAGE==2)MsgMain2("f2="+fullfilename2);
    if(DEBUGGING_USEAGE==2)MsgMain2("f3="+fullfilename3);

    if(File::Exists(fullfilename1)==true)
    {
        MessageBox::Show(MSG_MAINRPT_FILE_EXISTED_HINT, "Message",
            MessageBoxButtons::OK,
            MessageBoxIcon::Information);
    }

    //===== creat file and write data ======= (file1 first)
    StreamWriter^ sw=gcnew StreamWriter(fullfilename1);
    sw->WriteLine(UID);      //-------------------------------- 1
    sw->WriteLine(this->RDS_rpt_date);  //--------------------- 2
    sw->WriteLine(this->RDS_rpt_time);  //--------------------- 3
    //sw->WriteLine(this->comboBox_Model_Name->SelectedIndex); //-4
    sw->WriteLine(this->comboBox_Model_Name->Text); //-4
    sw->WriteLine(this->textBox_spa_serial->Text); //-----------5
    sw->WriteLine(this->textBox_owner_in->Text); //-------------6
    sw->WriteLine(this->RDS_operator_name);      //-------------7
    sw->WriteLine(this->textBox_Cur_T->Text);    //-------------8
    sw->WriteLine(this->textBox_Set_T->Text);    //-------------9
    sw->WriteLine(this->textBox_HiLmt_T->Text);  //-------------10
    sw->WriteLine(this->textBox_PCB_T->Text);    //-------------11
    lindStr=gcnew String(eMSG_Table[this->ECset][this->StartErr_index1])+",";
    lindStr+=gcnew String(eMSG_Table[this->ECset][this->StartErr_index2])+",";
    lindStr+=gcnew String(eMSG_Table[this->ECset][this->StartErr_index3])+",";
    lindStr+=gcnew String(eMSG_Table[this->ECset][this->StartErr_index4]);
    sw->WriteLine(lindStr);                    //------------------------------12
    lindStr=gcnew String(eMSG_Table[this->ECset][this->iCmd.iSPA.msg_index_1])+",";
    lindStr+=gcnew String(eMSG_Table[this->ECset][this->iCmd.iSPA.msg_index_2])+",";
    lindStr+=gcnew String(eMSG_Table[this->ECset][this->iCmd.iSPA.msg_index_3])+",";
    lindStr+=gcnew String(eMSG_Table[this->ECset][this->iCmd.iSPA.msg_index_4]);
    sw->WriteLine(lindStr);                    //------------------------------13

    //Voltage MPM
    tmpFp=((float)this->iCmd.iSPA.VoltageADC_to_Volt(this->iCmd.iSPA.max_Adc_3)
        /(float)this->iCmd.iSPA.spa_w_Voltage)*100;
    tmpIp=(int)(tmpFp+0.5);
    lindStr=tmpIp+"%";
    sw->WriteLine(lindStr);                    //------------------------------14
    tmpFp=((float)this->iCmd.iSPA.VoltageADC_to_Volt(this->iCmd.iSPA.cur_Adc_3)
        /(float)this->iCmd.iSPA.spa_w_Voltage)*100;
    tmpIp=(int)(tmpFp+0.5);
    lindStr=tmpIp+"%";
    sw->WriteLine(lindStr);                    //------------------------------15
    tmpFp=((float)this->iCmd.iSPA.VoltageADC_to_Volt(this->iCmd.iSPA.min_Adc_3)
        /(float)this->iCmd.iSPA.spa_w_Voltage)*100;
    tmpIp=(int)(tmpFp+0.5);
    lindStr=tmpIp+"%";
    sw->WriteLine(lindStr);                    //------------------------------16

    //HighLimit MPM
    lindStr=this->iCmd.iSPA.TEMPADC_To_TEMP_F(this->iCmd.iSPA.max_Adc_1)+"F";
    sw->WriteLine(lindStr);                    //------------------------------17
    lindStr=this->iCmd.iSPA.TEMPADC_To_TEMP_F(this->iCmd.iSPA.cur_Adc_1)+"F";
    sw->WriteLine(lindStr);                    //------------------------------18
    lindStr=this->iCmd.iSPA.TEMPADC_To_TEMP_F(this->iCmd.iSPA.min_Adc_1)+"F";
    sw->WriteLine(lindStr);                    //------------------------------19

    //Water Temp. MPM
    lindStr=this->iCmd.iSPA.TEMPADC_To_TEMP_F(this->iCmd.iSPA.max_Adc_0)+"F";
    sw->WriteLine(lindStr);                    //------------------------------20
    lindStr=this->iCmd.iSPA.TEMPADC_To_TEMP_F(this->iCmd.iSPA.cur_Adc_0)+"F";
    sw->WriteLine(lindStr);                    //------------------------------21
    lindStr=this->iCmd.iSPA.TEMPADC_To_TEMP_F(this->iCmd.iSPA.min_Adc_0)+"F";
    sw->WriteLine(lindStr);                    //------------------------------22

    //PCB Temp. MPM
    lindStr=this->iCmd.iSPA.TEMPADC_To_TEMP_F(this->iCmd.iSPA.max_Adc_2)+"F";
    sw->WriteLine(lindStr);                    //------------------------------23
    lindStr=this->iCmd.iSPA.TEMPADC_To_TEMP_F(this->iCmd.iSPA.cur_Adc_2)+"F";
    sw->WriteLine(lindStr);                    //------------------------------24
    lindStr=this->iCmd.iSPA.TEMPADC_To_TEMP_F(this->iCmd.iSPA.min_Adc_2)+"F";
    sw->WriteLine(lindStr);                    //------------------------------25

    //comment
    lindStr=this->richTextBox_comment->Text;
    sw->WriteLine(lindStr);                    //------------------------------26

    //replaced parts
    lindStr="N/A";
    sw->WriteLine(lindStr);                    //------------------------------27

    //M0_HC
    if(this->has_M0_HC==false)
        lindStr="n/a";
    else
    {
        if(this->M0_HC_err==true)
            lindStr=""+this->M0_HC_current+"A,E";
        else
            lindStr=""+this->M0_HC_current+"A,N";
    }
    sw->WriteLine(lindStr);                    //------------------------------28

    //M0_C
    if(this->has_M0_C==false)
        lindStr="n/a";
    else
    {
        if(this->M0_C_err==true)
            lindStr=""+this->M0_C_current+"A,E";
        else
            lindStr=""+this->M0_C_current+"A,N";
    }
    sw->WriteLine(lindStr);                    //------------------------------29

    //M0
    if(this->M0_err==true)
        lindStr=""+this->M0_st+","+this->M0_current+"A,E";
    else
        lindStr=""+this->M0_st+","+this->M0_current+"A,N";
    sw->WriteLine(lindStr);                    //------------------------------30

    //M1
    if(this->M1_err==true)
        lindStr=""+this->M1_st+","+this->M1_current+"A,E";
    else
        lindStr=""+this->M1_st+","+this->M1_current+"A,N";
    sw->WriteLine(lindStr);                    //------------------------------31

    //M2
    if(this->M2_err==true)
        lindStr=""+this->M2_st+","+this->M2_current+"A,E";
    else
        lindStr=""+this->M2_st+","+this->M2_current+"A,N";
    sw->WriteLine(lindStr);                    //------------------------------32

    //M3
    if(this->M3_err==true)
        lindStr=""+this->M3_st+","+this->M3_current+"A,E";
    else
        lindStr=""+this->M3_st+","+this->M3_current+"A,N";
    sw->WriteLine(lindStr);                    //------------------------------33

    //M4
    if(this->M4_err==true)
        lindStr=""+this->M4_st+","+this->M4_current+"A,E";
    else
        lindStr=""+this->M4_st+","+this->M4_current+"A,N";
    sw->WriteLine(lindStr);                    //------------------------------34

    //M5
    if(this->M5_err==true)
        lindStr=""+this->M5_st+","+this->M5_current+"A,E";
    else
        lindStr=""+this->M5_st+","+this->M5_current+"A,N";
    sw->WriteLine(lindStr);                    //------------------------------35

    //M6
    if(this->M6_err==true)
        lindStr=""+this->M6_st+","+this->M6_current+"A,E";
    else
        lindStr=""+this->M6_st+","+this->M6_current+"A,N";
    sw->WriteLine(lindStr);                    //------------------------------36

    //M7
    if(this->M7_err==true)
        lindStr=""+this->M7_st+","+this->M7_current+"A,E";
    else
        lindStr=""+this->M7_st+","+this->M7_current+"A,N";
    sw->WriteLine(lindStr);                    //------------------------------37

    //AD_CauseEquip_TotalCnt
    lindStr=""+this->AD_CauseEquip_TotalCnt;
    sw->WriteLine(lindStr);                    //------------------------------38

    //Cuase number list
    if(this->AD_CauseEquip_TotalCnt==0) lindStr="N/A";
    else
    {
        lindStr="";
        for(int i=0; i<this->AD_CauseEquip_TotalCnt; i++)
        {
            lindStr+=AD_all_Cause[i]+",";
        }//end for loop i
    }
    sw->WriteLine(lindStr);                    //------------------------------39

    //Equipments number list
    if(this->AD_Equip_FinalCnt==0) lindStr="N/A";
    else
    {
        lindStr="";
        for(int j=0; j<this->AD_Equip_FinalCnt; j++)
        {
            lindStr+=AD_all_Equip[j]+",";
        }//end for loop i
    }
    sw->WriteLine(lindStr);                    //------------------------------40

    //end of file writing========================================================
    sw->Close();

    //===== Copy file to other directorys ====
    // (1) Must copy to by Date directory
    if(File::Exists(fullfilename2)==true)
    {
        File::Delete(fullfilename2);
    }
    File::Copy(fullfilename1, fullfilename2);

    // (2) if it has service call, it also be copy to OpenServiceCall directory
    if(this->RDS_SCno_produced==true)
    {
        if(File::Exists(fullfilename3)==true)
        {
            File::Delete(fullfilename3);
        }
        File::Copy(fullfilename1, fullfilename3);

        //remember SCno, for next generation
        this->RPT_saveSCno(this->RDS_SC_no);
    }
}

//=================//
// Report Delete   //
//=================//
void  RDS_main_Form::RPT_delete(String^ UID)
{
    String^ lindStr;
    String^ tmpStr;
    float tmpFp;
    int tmpIp;
    //======== prepare file name =============
    String^ fullfilename1;  //save to by UID directory
    String^ fullfilename2;  //save to by Date director
    fullfilename1=this->Base_dir+RDS_NAS_REPORT_DIR+RDS_NAS_BY_UID_DIR;
    fullfilename2=this->Base_dir+RDS_NAS_REPORT_DIR+RDS_NAS_BY_DATE_DIR;
    String^ curYear;
    String^ curMonth;
    String^ curDay;
    DateTime dt=DateTime::Now;
    curYear=dt.ToString("yyyy", DateTimeFormatInfo::InvariantInfo);
    curMonth=dt.ToString("MM", DateTimeFormatInfo::InvariantInfo);
    curDay=dt.ToString("dd", DateTimeFormatInfo::InvariantInfo);
    fullfilename2+=curYear+"\\";
    if(Directory::Exists(fullfilename2)==false) Directory::CreateDirectory(fullfilename2);
    fullfilename2+=curMonth+"\\";
    if(Directory::Exists(fullfilename2)==false) Directory::CreateDirectory(fullfilename2);
    fullfilename2+=curDay+"\\";
    if(Directory::Exists(fullfilename2)==false) Directory::CreateDirectory(fullfilename2);
    //
    String^ sub_UID;
    if(UID->Length!=RDS_UID_WHOLE_LENGTH)
    {
        MessageBox::Show(MSG_MAINRPT_UID_LENGTH_ERROR, "Error",
            MessageBoxButtons::OK,
            MessageBoxIcon::Information);
        return;
    }
    sub_UID=UID->Substring(0, RDS_NAS_UID_SUBDIR_1ST_PART);
    fullfilename1+=sub_UID+"\\";
    if(Directory::Exists(fullfilename1)==false) Directory::CreateDirectory(fullfilename1);
    fullfilename1+=UID+"\\";
    if(Directory::Exists(fullfilename1)==false) Directory::CreateDirectory(fullfilename1);
    //
    fullfilename1+=this->Cur_RDSreport_str+".csv";
    fullfilename2+=this->Cur_RDSreport_str+".csv";
    //------------------------------------------------------------------------------------- above, 2 file name ready
    //===== Delete files here ====
    File::Delete(fullfilename1);
    File::Delete(fullfilename2);
}

//=====================//
// check UID in Today  // (using LOG directory and UID directory)
//=====================//
Boolean RDS_main_Form::RPT_chkUID_today(String^ rptFileStr, String^ UID)
{
    int StartPos;
    String^ fullpath;  //go to LOG firectory
    fullpath=this->Base_dir+RDS_NAS_LOG_DIR+RDS_NAS_BY_UID_DIR;
    String^ sub_UID;
    if(UID->Length!=RDS_UID_WHOLE_LENGTH)
    {
        MessageBox::Show(MSG_MAINRPT_UID_LENGTH_ERROR, "Error",
            MessageBoxButtons::OK,
            MessageBoxIcon::Information);
        return false;
    }
    sub_UID=UID->Substring(0, RDS_NAS_UID_SUBDIR_1ST_PART);
    fullpath+=sub_UID;
    if(Directory::Exists(fullpath)==false)
        return false;
    fullpath+="\\"+UID;
    if(Directory::Exists(fullpath)==false)
        return false;
    //get all files in directory
    array<String^>^ fileAll=Directory::GetFiles(fullpath);
    for(int i=0; i<fileAll->Length; i++)
    {
        if(DEBUGGING_USEAGE==2)MsgMain2("f1="+fileAll[i]);
        StartPos=fileAll[i]->IndexOf(rptFileStr);
        if(StartPos!=-1) return true;
    }
    return false;
}

//==================//
// check UID before //  And read basic information
//==================//
Boolean RDS_main_Form::RPT_chkUID(String^ UID)
{
    int StartPos;
    int Modelindex;
    String^ readLineStr;
    String^ fullpath;  //save to by Date director
    fullpath=this->Base_dir+RDS_NAS_REPORT_DIR+RDS_NAS_BY_UID_DIR;
    String^ sub_UID;
    if(UID->Length!=RDS_UID_WHOLE_LENGTH)
    {
        MessageBox::Show(MSG_MAINRPT_UID_LENGTH_ERROR, "Error",
            MessageBoxButtons::OK,
            MessageBoxIcon::Information);
        return false;
    }
    sub_UID=UID->Substring(0, RDS_NAS_UID_SUBDIR_1ST_PART);
    fullpath+=sub_UID;
    if(Directory::Exists(fullpath)==false)
        return false;
    fullpath+="\\"+UID;
    if(Directory::Exists(fullpath)==false)
        return false;
    //get all files in directory
    array<String^>^ fileAll=Directory::GetFiles(fullpath);
    //get list of all filename
    for(int i=0; i<fileAll->Length; i++)
    {
        if(DEBUGGING_USEAGE==2)MsgMain2("f"+i+"="+fileAll[i]);
    }
    //Find CSV file
    Boolean found_csv=false;
    int csvIndex=fileAll->Length; //scan from last item in list
    do
    {
        csvIndex--;
        StartPos=fileAll[csvIndex]->IndexOf("csv");
        if(StartPos>0) found_csv=true;
    } while(found_csv==false&&csvIndex>0);
    if(found_csv==false)
    {
        return false;
    }
    //read basic information from last CSV file
    StreamReader^ din=File::OpenText(fileAll[csvIndex]);
    readLineStr=din->ReadLine(); //line1 = UID
    readLineStr=din->ReadLine(); //line2 = date
    readLineStr=din->ReadLine(); //line3 = time
    readLineStr=din->ReadLine(); //line4 = Hot Tub model name (selectIndex)
    //this->comboBox_Model_Name->SelectedIndex = Convert::ToInt32(readLineStr, 10);
    Modelindex=this->comboBox_Model_Name->Items->IndexOf(readLineStr);
    if(Modelindex<3&&Modelindex>=0) this->comboBox_Model_Name->SelectedIndex=Modelindex;
    else  this->comboBox_Model_Name->SelectedIndex=0;
    readLineStr=din->ReadLine(); //line5 = Spa serial number
    this->textBox_spa_serial->Text=readLineStr;
    readLineStr=din->ReadLine(); //line6 = Spa owner
    this->textBox_owner_in->Text=readLineStr;
    din->Close();
    return true;
}

//=======================//
// Get Service Scall No. //
//=======================//
void  RDS_main_Form::RPT_getSCno()
{
    int cYear;
    int cMonth;
    int cDay;
    Boolean isNewDay;
    int sYear;
    int sMonth;
    int sDay;
    int sSCno;
    String^ curYear;
    String^ curMonth;
    String^ curDay;
    DateTime dt=DateTime::Now;
    curYear=dt.ToString("yyyy", DateTimeFormatInfo::InvariantInfo);
    curMonth=dt.ToString("MM", DateTimeFormatInfo::InvariantInfo);
    curDay=dt.ToString("dd", DateTimeFormatInfo::InvariantInfo);
    cYear=Convert::ToInt32(curYear, 10);
    cMonth=Convert::ToInt32(curMonth, 10);
    cDay=Convert::ToInt32(curDay, 10);

    //check work file exist or not (for the first time)
    String^ fullfilename;  //save to OpenServiceCall
    fullfilename=this->Base_dir+RDS_NAS_SERVICE_DIR+"\\"+this->RDS_operator_No+".work";

    //if work file not exist, SC_No=1
    if(File::Exists(fullfilename)==false)
    {
        this->RDS_SC_no=1;
        return;
    }
    else
    {  //if work file exist, read the SC_No
  //read
        StreamReader^ din=File::OpenText(fullfilename);
        String^ str;
        str=din->ReadLine();  //line-1
        sYear=Convert::ToInt32(str, 10);
        str=din->ReadLine();  //line-2
        sMonth=Convert::ToInt32(str, 10);
        str=din->ReadLine();  //line-3
        sDay=Convert::ToInt32(str, 10);
        str=din->ReadLine();  //line-4
        sSCno=Convert::ToInt32(str, 10);
        din->Close();

        //check date & update SC-NO.
        isNewDay=false;
        if(cYear>sYear) isNewDay=true;
        else if(cYear==sYear && cMonth>sMonth) isNewDay=true;
        else if(cYear==sYear && cMonth==sMonth && cDay>sDay) isNewDay=true;
        else if(cYear==sYear && cMonth==sMonth && cDay==sDay) isNewDay=false;
        else  isNewDay=true; //something wrong, just overwrite it!!

        if(isNewDay==true)this->RDS_SC_no=1;
        else this->RDS_SC_no=sSCno+1;

        return;
    }
}

//=======================//
// Save Service Scall No.//
//=======================//
void  RDS_main_Form::RPT_saveSCno(int Scno)
{
    String^ curYear;
    String^ curMonth;
    String^ curDay;
    DateTime dt=DateTime::Now;
    curYear=dt.ToString("yyyy", DateTimeFormatInfo::InvariantInfo);
    curMonth=dt.ToString("MM", DateTimeFormatInfo::InvariantInfo);
    curDay=dt.ToString("dd", DateTimeFormatInfo::InvariantInfo);
    String^ fullfilename;  //save to OpenServiceCall directory
    fullfilename=this->Base_dir+RDS_NAS_SERVICE_DIR+"\\"+this->RDS_operator_No+".work";
    //write (overwrite)
    StreamWriter^ sw=gcnew StreamWriter(fullfilename);
    sw->WriteLine(curYear);
    sw->WriteLine(curMonth);
    sw->WriteLine(curDay);
    sw->WriteLine(Scno);
    sw->Close();
}

//===============//
// Save Log file //
//===============//
void RDS_main_Form::Log_save(String^ UID)
{
    //======== prepare file name =============
    String^ fullfilename1;  //save to by UID directory
    fullfilename1=this->Base_dir+RDS_NAS_LOG_DIR+RDS_NAS_BY_UID_DIR;
    //
    String^ sub_UID;
    if(UID->Length!=RDS_UID_WHOLE_LENGTH)
    {
        MessageBox::Show(MSG_MAINRPT_UID_LENGTH_ERROR, "Error",
            MessageBoxButtons::OK,
            MessageBoxIcon::Information);
        return;
    }
    sub_UID=UID->Substring(0, RDS_NAS_UID_SUBDIR_1ST_PART);
    fullfilename1+=sub_UID+"\\";
    if(Directory::Exists(fullfilename1)==false)
        Directory::CreateDirectory(fullfilename1);
    fullfilename1+=UID+"\\";
    if(Directory::Exists(fullfilename1)==false)
        Directory::CreateDirectory(fullfilename1);
    //
    fullfilename1+=this->Cur_RDSreport_str+".log";
    if(DEBUGGING_USEAGE==2)MsgMain2("log="+fullfilename1);

    //Save file to both directory
    this->richTextBox_ActLog->SaveFile(fullfilename1, RichTextBoxStreamType::PlainText);

    return;
}

//================//
// check UID Dir. //
//================//
Boolean RDS_main_Form::Check_UID_dir(String^ UID)
{
    String^ readLineStr;
    String^ fullpath;  //save to by Date director
    fullpath=this->Base_dir+RDS_NAS_REPORT_DIR+RDS_NAS_BY_UID_DIR;
    String^ sub_UID;
    if(UID->Length!=RDS_UID_WHOLE_LENGTH)
    {
        MessageBox::Show(MSG_MAINRPT_UID_LENGTH_ERROR, "Error",
            MessageBoxButtons::OK,
            MessageBoxIcon::Information);
        return false;
    }
    sub_UID=UID->Substring(0, RDS_NAS_UID_SUBDIR_1ST_PART);
    fullpath+=sub_UID;
    if(Directory::Exists(fullpath)==false)
        return false;
    fullpath+="\\"+UID;
    if(Directory::Exists(fullpath)==false)
        return false;
    return true;
}