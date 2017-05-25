//project defines
#include "RDSadmin_project.h"
//
#include "nas_state.h"
//
#include "DashBrdForm.h"
#include "RDSadminMainForm.h"
#include "SupervisorForm.h"
#include "UserList_Form.h"
#include "DealerListForm.h"
//
#include "rpt_b_Form.h"
#include "rptDisp.h"

#include "CauseEquip.h"
extern struct Encode_Cause_Equpiment_type RPT_all_Cause[CUASE_RPT_TABLE_SIZE];
extern struct Encode_Cause_Equpiment_type RPT_all_Equip[EQUIP_RPT_TABLE_SIZE];

using namespace System;
using namespace System::Globalization;
using namespace System::Windows::Forms;
using namespace RDSadmin;
using namespace RDS_NAS;

//====================//
//  Form Load !!!     //
//====================//
System::Void rpt_b_Form::rpt_b_Form_Load(System::Object^  sender, System::EventArgs^  e)
{
    showBriefReport(this->readFilename);

    //Hide Buttons by authority_level
    if(this->iNas.LoginUser_AuthLevel!=RDS_NAS_AUTHORITY_LEVEL_0){
        this->button_Supervisor->Visible=false;
    }

    //hide menu buttons when not root Spa Company
    if(this->iNas.Base_dir!=RDS_NAS_ROOT_DIR){
        this->button_Dealer->Visible=false;
        this->button_DashBoard->Visible=false;
    }

    //show UI
    this->label_LoginID->Text=this->iNas.LoginUser_ID;
    this->label_LoginAuthorLv->Text=this->iNas.LoginUser_AuthLevel;
}

//====================//
//  show brief report //
//====================//
void rpt_b_Form::showBriefReport(String^ readFileName)
{
    int StartPos;
    String^ NoDirFilename;
    //
    StartPos=readFileName->LastIndexOf("\\");
    NoDirFilename=readFileName->Substring(StartPos+1);

    this->readFilename=readFileName; //save as a record for future usage (display full report)

    //check file
    if(File::Exists(readFileName)==false){
        MessageBox::Show(RPT_LIST_ITEM_FILE_LOSTED, "ERROR",
            MessageBoxButtons::OK,
            MessageBoxIcon::Information);
        return;
    }

    String^ readLineStr;
    String^ tmpStr;
    int tmpInt;
    StreamReader^ din=File::OpenText(readFileName);

    //read basic information
    readLineStr=din->ReadLine(); //line1 = UID  !!!!!!!!!!!!!!!!!!!!!!!!!!!
    this->UID=readLineStr;
    this->textBox_UID->Text=this->UID;

    readLineStr=din->ReadLine(); //line2 = date
    tmpStr=readLineStr->Substring(4, 2); //get month
    tmpInt=Convert::ToInt32(tmpStr, 10);
    switch(tmpInt){
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
    //this->richTextBox_replace->Text = this->replaced_parts;

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
    if(readLineStr!="N/A"){
        result=readLineStr->Split(sep, StringSplitOptions::RemoveEmptyEntries);
        for(int i=0; i<result->Length; i++){
            tmpNo=Convert::ToInt32(result[i], 10);
            if(tmpNo>=CUASE_RPT_TABLE_SIZE||tmpNo<0){//error
                MessageBox::Show(RPT_DISP_CAUSE_INDEX_WRONG, "ERROR",
                    MessageBoxButtons::OK,
                    MessageBoxIcon::Information);
            }
            else{
                result[i]=gcnew String(RPT_all_Cause[tmpNo].CE_string);
            }
        }//end-for-loop i
        this->textBox_pCause->Text=result[0];
    }
    else
        this->textBox_pCause->Text=readLineStr;

    //read equipments
    readLineStr=din->ReadLine(); //line40
    this->richTextBox_equipments->Text=""; //reset it...
    if(readLineStr!="N/A"){
        result=readLineStr->Split(sep, StringSplitOptions::RemoveEmptyEntries);
        for(int i=0; i<result->Length; i++){
            tmpNo=Convert::ToInt32(result[i], 10);
            if(tmpNo>=EQUIP_RPT_TABLE_SIZE||tmpNo<0){//error
                MessageBox::Show(RPT_DISP_CAUSE_INDEX_WRONG, "ERROR",
                    MessageBoxButtons::OK,
                    MessageBoxIcon::Information);
            }
            else{
                result[i]=gcnew String(RPT_all_Equip[tmpNo].CE_string);
                this->richTextBox_equipments->Text+=result[i]+",";
            }
        }//end-for-loop i
    }
    else this->richTextBox_equipments->Text=readLineStr;

    //-------
    din->Close();
}

//----------------//
//  Menu buttons  //
//----------------//
System::Void rpt_b_Form::button_DashBoard_Click(System::Object^  sender, System::EventArgs^  e)
{
    RDSadmin::DashBrdForm^ formDash=gcnew DashBrdForm();
    formDash->iNas.LoginUser_no=this->iNas.LoginUser_no;
    formDash->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
    formDash->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
    formDash->iNas.Base_dir=this->iNas.Base_dir;
    formDash->Show();
    this->Close();
}

System::Void rpt_b_Form::button_ServiceCall_Click(System::Object^  sender, System::EventArgs^  e)
{
    RDSadmin::RDSadminMainForm^ formRDSmain=gcnew RDSadminMainForm(0);
    formRDSmain->iNas.LoginUser_no=this->iNas.LoginUser_no;
    formRDSmain->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
    formRDSmain->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
    formRDSmain->Show();
    formRDSmain->Show();
    this->Close();
}

System::Void rpt_b_Form::button_RDSuser_Click(System::Object^  sender, System::EventArgs^  e)
{
    RDSadmin::UserList_Form^ formUser=gcnew UserList_Form();
    formUser->iNas.LoginUser_no=this->iNas.LoginUser_no;
    formUser->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
    formUser->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
    formUser->Show();
    this->Close();
}

System::Void rpt_b_Form::button_Supervisor_Click(System::Object^  sender, System::EventArgs^  e)
{
    RDSadmin::SupervisorForm^ formSuper=gcnew SupervisorForm();
    formSuper->iNas.LoginUser_no=this->iNas.LoginUser_no;
    formSuper->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
    formSuper->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
    formSuper->Show();
    this->Close();
}

System::Void rpt_b_Form::button_Dealer_Click(System::Object^  sender, System::EventArgs^  e)
{
    RDSadmin::DealerListForm^ formDealer=gcnew DealerListForm();
    formDealer->iNas.LoginUser_no=this->iNas.LoginUser_no;
    formDealer->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
    formDealer->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
    formDealer->iNas.Base_dir=this->iNas.Base_dir;
    formDealer->Show();
    this->Close();
}

//----------------//
//  Back  buttons //
//----------------//
System::Void rpt_b_Form::button_back_Click(System::Object^  sender, System::EventArgs^  e)
{
    RDSadmin::RDSadminMainForm^ formRDSmain=gcnew RDSadminMainForm(this->belong_Page);
    formRDSmain->iNas.LoginUser_no=this->iNas.LoginUser_no;
    formRDSmain->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
    formRDSmain->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
    formRDSmain->Show();
    formRDSmain->Show();
    this->Close();
}

//------------------//
//  RDS full report //
//------------------//
System::Void rpt_b_Form::button_fullReport_Click(System::Object^  sender, System::EventArgs^  e)
{
    RDSadmin::rptDisp^ formRPT=gcnew rptDisp();
    formRPT->readFilename=this->readFilename;
    formRPT->ShowDialog();
}