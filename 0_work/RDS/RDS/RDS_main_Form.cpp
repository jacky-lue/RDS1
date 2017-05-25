//project defines
#include "RDS_project.h"
//for VC program all forms
#include "RDS_main_Form.h"
#include "DateTime_Form.h"
#include "FltSchedule_Form.h"
#include "EcoSchedule_Form.h"
#include "set_T_form.h"
#include "set_FltDay_form.h"
#include "set_UVday_form.h"
#include "set_SF_Form.h"
#include "set_PF_Form.h"
#include "EH_Form.h"
#include "login.h"
#include "rptDisp.h"
#include "HistoryForm.h"
#include "HistLogForm.h"
#include "OpenSCForm.h"

//related objects
#include "IOTcommunicator.h"
#include "spa_cmd.h"
#include "SPA.h"

#include "ErrMsg.h"
extern struct SpaModel_ADcurrnt SpaModels[MAX_HOT_TUV_MODELS];
extern char* ModelNames[MAX_HOT_TUV_MODELS];
extern char* PartNoList[MAX_HOT_TUV_MODELS][PART_NO_LINES_PER_MODEL];

using namespace System;
using namespace System::IO;
using namespace System::Windows::Forms;
using namespace System::Threading;

[STAThread]
void Main(array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    RDS::RDS_main_Form form;
    Application::Run(%form);
}

//==========================================================================================
//  Functions in RDS_main_Form
//==========================================================================================
using namespace RDS;  //which declear class RDS_main_Form

//The function body of class RDS_main_Form here --------------------------------------------
//--------- all buttons and all sub-windown related functions

//======================//
//  Load Main form !!   //
//======================//
System::Void RDS_main_Form::RDS_main_Form_Load(System::Object^  sender, System::EventArgs^  e)
{
    int rtn;

    //initial some variable
    this->MyClientThreadRuning=false;
    initial_All();
    // IOTCapi initial ...
    if(this->iCmd.iIOTctrl.initial_OK=true) {
        MsgEngr("IOTC initial Ok...");
    }
    else {
        MsgEngr("IOTC initial fail !!!");
        MsgEngr_IOT_error();
    }
    //modify title of form and show IOTC version
    this->Text=VersionString+this->iCmd.iIOTctrl.versionStr_IOT;

    //read Model_AD.ini, and prepare all model-name
    this->iNas.Has_Model_AD_Ini=this->iNas.Check_Model_AD_Ini();
    if(this->iNas.Has_Model_AD_Ini==false) {
        MessageBox::Show(MSG_LOGIN_ERR_MODELAD_INI_FILE_NOT_FOUD, "ERROR",
            MessageBoxButtons::OK,
            MessageBoxIcon::Information);
        this->Close();
        return;    ///if didnt have Model_AD.ini, then close program here !!!!!!!!!!!!!!!!!!!!
    }
    //if has Model_AD.ini file, then read it and test....
    rtn=read_SpaModel_setting();
    if(rtn<0) {
        this->Close();
        return;
    }
    this->comboBox_Model_Name->SelectedIndex=0;

    //UpdateUI
    UpdateUI();

    //login form ....
    RDS::login^ formLogin=gcnew login(this);
    formLogin->ShowDialog();
    this->Hide();
}

//==================//
// system initial   //
//==================//
void RDS_main_Form::initial_All(void)
{
    //for two-set od error code
    this->ECset=0; //0=original set (J-comapny), 1=new set

    //for programming control
    this->tryConnect=false;
    this->Display_initial_OK=false;
    this->Display_F=true;
    this->button_degree_F->Image=Image::FromFile("button_on.png");
    this->button_degree_C->Image=Image::FromFile("button_off.png");
    this->Err_showed=false;
    this->Cannot_AutoD=false;
    this->Some_MsgIndex_AD_fail=false;
    this->doing_AutoD=false;

    //UI buttons (for not connected case)
    this->button_Err_Msg->Enabled=false;
    this->button_Filtration_sch->Enabled=false;
    this->button_PF->Enabled=false;
    this->button_SF->Enabled=false;
    this->button_Date_Time->Enabled=false;
    this->button_Func_Lock->Enabled=false;
    this->button_Pump_Lock->Enabled=false;
    this->button_Panel_Lock->Enabled=false;
    this->button_unlock->Enabled=false;
    this->button_T_Lock->Enabled=false;
    this->button_mode->Enabled=false;
    this->button_P1_Hi->Enabled=false;
    this->button_P1_Lo->Enabled=false;
    this->button_P2_Hi->Enabled=false;
    this->button_P2_Lo->Enabled=false;
    this->button_P3_Hi->Enabled=false;
    this->button_P3_Lo->Enabled=false;
    this->button_Blower_OnOff->Enabled=false;
    this->textBox_Set_T->Enabled=false;
    //
    this->textBox_Filter_Days->Enabled=false;
    this->textBox_UV_Days->Enabled=false;
    this->button_RDS_report->Enabled=false;
    this->button_Service_Call->Enabled=false;
    this->button_History->Enabled=true;  //can run without connection
    this->button_OSC_list->Enabled=true; //can run without connection
    this->button_auto_diag->Enabled=false;
    this->button_connect->Enabled=true;
    this->button_disconnect->Enabled=false;

    // UI Textbox
    //if (DEBUGGING_USEAGE != 0)this->textBox_UID_in->Text = DEFAULT_UID_TEXT_INPUT;  //for develop/debug only
    //if (DEBUGGING_USEAGE == 0)this->textBox_UID_in->Text = "";
    this->textBox_owner_in->Text="";
    this->textBox_spa_serial->Text="";
    this->comboBox_Model_Name->SelectedIndex=0;
    this->textBox_Cur_T->Text="";
    this->textBox_Set_T->Text="";
    this->textBox_HiLmt_T->Text="";
    this->textBox_PCB_T->Text="";
    this->textBox4_System_Voltage->Text="--";
    this->textBox_Current_Amp->Text="--";
    this->textBox_P1_Amp->Text="--";
    this->textBox_P2_Amp->Text="--";
    this->textBox_P3_Amp->Text="--";
    this->textBox_Heater_Amp->Text="--";
    this->textBox_Blower_Amp->Text="--";
    this->textBox_Filter_Days->Text="";
    this->textBox_UV_Days->Text="";
    this->textBox_eMsg1->Text="";
    this->textBox_eMsg2->Text="";
    this->textBox_eMsg3->Text="";
    this->textBox_eMsg4->Text="";
    if(DEBUGGING_USEAGE==0)this->richTextBox_main_output->Text="";   //Main Text area
    if(this->panel_EngArea->Visible!=true)this->richTextBox_EngMsg->Text="";        //Engineer Text area
    if(DEBUGGING_USEAGE==0)this->richTextBox_ActLog->Text="";        //Log Text area
    this->richTextBox_comment->Text="";
    this->lbl_disp_EH_page->Text="";
    this->lbl_disp_EH_page->Visible=false;
    this->panel_Service_Hint->Visible=false;
    this->panel_Service_Hint_1->Visible=false;

    //UI textbox enable
    this->textBox_Cur_T->ReadOnly=true;
    this->textBox_HiLmt_T->ReadOnly=true;
    this->textBox_PCB_T->ReadOnly=true;
    this->textBox_eMsg1->ReadOnly=true;
    this->textBox_eMsg2->ReadOnly=true;
    this->textBox_eMsg3->ReadOnly=true;
    this->textBox_eMsg4->ReadOnly=true;
    this->textBox4_System_Voltage->ReadOnly=true;
    this->textBox_Current_Amp->ReadOnly=true;
    this->textBox_P1_Amp->ReadOnly=true;
    this->textBox_P2_Amp->ReadOnly=true;
    this->textBox_P3_Amp->ReadOnly=true;
    this->textBox_Blower_Amp->ReadOnly=true;

    //IOT commander
    this->iCmd.parseFail=false;
    this->iCmd.cmdPktisValid=false;
    this->iCmd.received_ValidPacket=0;
    this->iCmd.CurrentPacket_State=PKST_Idle;
    this->iCmd.LenCode_LessThan2_ErCnt=0;
    this->iCmd.No_StopCode_ErCnt=0;
    this->iCmd.LenCode_NotMatch_ErCnt=0;
    this->iCmd.chkSum_Xor_ErCnt=0;
    WaitCmd=0;  //no waitting command
    SettingCmd_31=false;
    SettingCmd_32=false;
    SettingCmd_33=false;
    RdEEP_going=false;

    //SPA status...
    this->iCmd.iSPA.p1_hi_on=false;
    this->iCmd.iSPA.p2_hi_on=false;
    this->iCmd.iSPA.p3_hi_on=false;
    this->iCmd.iSPA.p1_lo_on=false;
    this->iCmd.iSPA.p2_lo_on=false;
    this->iCmd.iSPA.p3_lo_on=false;
    this->iCmd.iSPA.blower_on=false;
    this->iCmd.iSPA.circ_on=false;
    this->iCmd.iSPA.uv_on=false;
    this->iCmd.iSPA.heater_on=false;
    this->iCmd.iSPA.ozon_on=false;
    this->iCmd.iSPA.block_out_cyc_on=false;
    this->iCmd.iSPA.clean_cyc_on=false;
    this->iCmd.iSPA.unlock=false;
    this->iCmd.iSPA.lock_Tmpr=false;
    this->iCmd.iSPA.lock_Func=false;
    this->iCmd.iSPA.lock_Pump=false;
    this->iCmd.iSPA.lock_Panl=false;
    this->iCmd.iSPA.ecoModeOn=false;
    this->iCmd.iSPA.msg_index_1=SPA_NO_ERROR_DEFAULT_INDEX;
    this->iCmd.iSPA.msg_index_2=SPA_NO_ERROR_DEFAULT_INDEX;
    this->iCmd.iSPA.msg_index_3=SPA_NO_ERROR_DEFAULT_INDEX;
    this->iCmd.iSPA.msg_index_4=SPA_NO_ERROR_DEFAULT_INDEX;
    this->iCmd.iSPA.relay_err_p1=false;
    this->iCmd.iSPA.relay_err_p2=false;
    this->iCmd.iSPA.relay_err_p3=false;
    this->iCmd.iSPA.relay_err_ht=false;
    this->iCmd.iSPA.new_cmd70=false;

    //for different SPA model...
    this->iCmd.iSPA.p1_mode=0;
    this->iCmd.iSPA.p2_mode=0;
    this->iCmd.iSPA.p3_mode=0;
    this->iCmd.iSPA.has_blower=false;
    this->iCmd.iSPA.is_HighEnd_Fsch=false;

    //for auto-diagnosis
    this->Current_AD_State=S_idel;
    this->M0_current=0;
    this->M1_current=0;
    this->M2_current=0;
    this->M3_current=0;
    this->M4_current=0;
    this->M5_current=0;
    this->M6_current=0;
    this->M7_current=0;
    this->starting_AD_cmd32=false;

    //for RDS report, service call
    this->RDS_SCno_produced=false;
    this->RDS_rpt_saved=false;
    this->Cur_RDSreport_str="";

    //For AD
    this->RDS_AD_finish=false;
    this->set_ADcmd32=false;
    this->starting_AD_cmd32=false;
    this->restore_AD_setT=false;
    this->TooCold_HeatOn=false;
    this->has_M0_HC=false;
    this->has_M0_C=false;
    this->M0_st=0;
    this->M1_st=0;
    this->M2_st=0;
    this->M3_st=0;
    this->M4_st=0;
    this->M5_st=0;
    this->M6_st=0;
    this->M7_st=0;
    this->M0_HC_all_Err="";
    this->M0_C_all_Err="";
    this->M0_all_Err="";
    this->M1_all_Err="";
    this->M2_all_Err="";
    this->M3_all_Err="";
    this->M4_all_Err="";
    this->M5_all_Err="";
    this->M6_all_Err="";
    this->M7_all_Err="";
    this->AD_CauseEquip_TotalCnt=0;
    this->AD_Equip_FinalCnt=0;
    this->M0_HC_err=false;
    this->M0_C_err=false;
    this->M0_err=false;
    this->M1_err=false;
    this->M2_err=false;
    this->M3_err=false;
    this->M4_err=false;
    this->M5_err=false;
    this->M6_err=false;
    this->M7_err=false;
    this->Flow_err=false;
}

//======================//
// EngineerArea show up //
//======================//
System::Void RDS_main_Form::label_owner_Click(System::Object^  sender, System::EventArgs^  e)
{
    if(this->textBox_owner_in->Text==EnginerModePW) {
        this->panel_EngArea->Visible=true;
    }
    else {
        this->panel_EngArea->Visible=false;
    }
}

//=================//
// Connect button  //
//=================//
System::Void RDS_main_Form::button_connect_Click(System::Object^  sender, System::EventArgs^  e)
{
    Boolean chk_result;

    if(this->button_disconnect->Enabled==true) {
        //already connected, so press again will do nothing
        MsgEngr("press Connect AGAIN !!!");
        return;
    }

    //checking UID length, if wrong length, do nothing & return
    if(this->textBox_UID_in->Text->Length!=RDS_UID_WHOLE_LENGTH) {
        MessageBox::Show(MSG_MAINFORM_CONNECT_UID_ERROR, "Error",
            MessageBoxButtons::OK,
            MessageBoxIcon::Information);
        return;
    }

    this->tryConnect=true;
    MsgLog("CC");
    this->textBox_UID_in->Enabled=false; //dont let user change in accident
    this->Cursor=Cursors::WaitCursor; //sometimes, it take time....
    if(this->iCmd.iIOTctrl.connect(this->textBox_UID_in->Text)<0) {
        MsgEngr("Using UID to connect.... Failed !!!");
        MsgLog("CF");
        this->Cursor=Cursors::Default;
        this->button_disconnect->Enabled=false;  //disable Disconnect button
        this->textBox_UID_in->Enabled=true; //user could change UID
        this->button_disconnect->ForeColor=Color::Gray;
        MsgEngr_IOT_error();
        //add an pop-out Notification
        MessageBox::Show(MSG_MAINFORM_CONNECT_UID_FAIL, "Fail",
            MessageBoxButtons::OK,
            MessageBoxIcon::Information);
    }
    else {
        this->Cursor=Cursors::Default;
        MsgEngr("Using UID to connect.... OK");
        MsgLog("CK");
        this->RDS_log_saved=false;
        this->button_disconnect->Enabled=true;  //enable Disconnect button
        this->button_disconnect->ForeColor=SystemColors::ControlText;

        //prepare RDS-report en-codeing string
        DateTime dt=DateTime::Now;
        //this->RDS_rpt_date = dt.ToString("MMddyy", DateTimeFormatInfo::InvariantInfo);
        this->RDS_rpt_date=dt.ToString("yyyyMMdd", DateTimeFormatInfo::InvariantInfo);
        this->RDS_rpt_time=dt.ToString("HH:mm", DateTimeFormatInfo::InvariantInfo);
        this->RDS_report_No=1;
        this->Cur_RDSreport_str=this->textBox_UID_in->Text+"_"+this->RDS_rpt_date
            +"_"+this->RDS_report_No;

        //if already has this UID before, and read basic information (RPT directory)
        this->RPT_chkUID(this->textBox_UID_in->Text);

        //if already has this report# in today, change report_No....(LOG directory)
        do {
            chk_result=this->RPT_chkUID_today(this->Cur_RDSreport_str, this->textBox_UID_in->Text);
            if(chk_result==true) {
                this->RDS_report_No++;
                this->Cur_RDSreport_str=this->textBox_UID_in->Text+"_"+this->RDS_rpt_date
                    +"_"+this->RDS_report_No;
            }
        } while(chk_result==true);

        // create a thread to reveive data and each back
        mhClientThread=gcnew Thread(gcnew ThreadStart(this, &RDS_main_Form::ClientThread));
        mhClientThread->IsBackground=true;
        mhClientThread->Start();
        this->MyClientThreadRuning=true;
        MsgEngr("Communication Start...");
    }
    UpdateUIfromIOT();
    //show session information on engineer area
    if(this->iCmd.iIOTctrl.session_Mode==0) this->lbl_sMode->Text="P2P";
    else this->lbl_sMode->Text="Relay";
    if(this->iCmd.iIOTctrl.session_CorD==0) this->lbl_sCorD->Text="Client";
    else this->lbl_sCorD->Text="Device";
    if(this->iCmd.iIOTctrl.session_NatType==0) this->lbl_NAT_type->Text="Unknow";
    if(this->iCmd.iIOTctrl.session_NatType==1) this->lbl_NAT_type->Text="IP Restricted";
    if(this->iCmd.iIOTctrl.session_NatType==2) this->lbl_NAT_type->Text="Port Restricted";
    if(this->iCmd.iIOTctrl.session_NatType==3) this->lbl_NAT_type->Text="Symmetric";
    this->lbl_remoteIP->Text=this->iCmd.iIOTctrl.session_RemoteIP;
    this->lbl_remotePort->Text=String::Format("{0}", this->iCmd.iIOTctrl.session_RemotePort);

    //than update UI again
    UpdateUI();
}

//====================//
// Disconnect button  //
//====================//
System::Void RDS_main_Form::button_disconnect_Click(System::Object^  sender, System::EventArgs^  e)
{
    //checking all sub-Windows
    HWND DestHandle;
    DestHandle=FindWindowA(NULL, "UV Days");
    if(DestHandle!=NULL)SendMessage(DestHandle, WM_CLOSE, 0, 0);
    DestHandle=FindWindowA(NULL, "Set Temperature");
    if(DestHandle!=NULL)SendMessage(DestHandle, WM_CLOSE, 0, 0);
    DestHandle=FindWindowA(NULL, "SF Filteration");
    if(DestHandle!=NULL)SendMessage(DestHandle, WM_CLOSE, 0, 0);
    DestHandle=FindWindowA(NULL, "PF Filteration");
    if(DestHandle!=NULL)SendMessage(DestHandle, WM_CLOSE, 0, 0);
    DestHandle=FindWindowA(NULL, "Fliter Days");
    if(DestHandle!=NULL)SendMessage(DestHandle, WM_CLOSE, 0, 0);
    DestHandle=FindWindowA(NULL, "History of Operation Records");
    if(DestHandle!=NULL)SendMessage(DestHandle, WM_CLOSE, 0, 0);
    DestHandle=FindWindowA(NULL, "History of Service");
    if(DestHandle!=NULL)SendMessage(DestHandle, WM_CLOSE, 0, 0);
    DestHandle=FindWindowA(NULL, "My Open Service Call List");
    if(DestHandle!=NULL)SendMessage(DestHandle, WM_CLOSE, 0, 0);
    DestHandle=FindWindowA(NULL, "RDS report");
    if(DestHandle!=NULL)SendMessage(DestHandle, WM_CLOSE, 0, 0);
    DestHandle=FindWindowA(NULL, "Filteration Schedule");
    if(DestHandle!=NULL)SendMessage(DestHandle, WM_CLOSE, 0, 0);
    DestHandle=FindWindowA(NULL, "Error History");
    if(DestHandle!=NULL)SendMessage(DestHandle, WM_CLOSE, 0, 0);
    DestHandle=FindWindowA(NULL, "ECO filteration Schedule");
    if(DestHandle!=NULL)SendMessage(DestHandle, WM_CLOSE, 0, 0);
    DestHandle=FindWindowA(NULL, "Date / Time");
    if(DestHandle!=NULL)SendMessage(DestHandle, WM_CLOSE, 0, 0);

    //turn-off service-call message
    this->panel_Service_Hint->Visible=false;
    this->panel_Service_Hint_1->Visible=false;
    this->richTextBox_main_output->Location=Point(RDS_RICHTEXTBOX_LOCATION_1_X, RDS_RICHTEXTBOX_LOCATION_1_Y);
    this->richTextBox_main_output->Size=System::Drawing::Size(RDS_RICHTEXTBOX_LOCATION_1_W, RDS_RICHTEXTBOX_LOCATION_1_H);

    //Save RDS report (if not saved, & if connection okay.....)
    if(this->RDS_rpt_saved==false&&this->Display_initial_OK==true
        &&((this->RDS_AD_finish==true&&this->Cannot_AutoD==false)||(this->RDS_AD_finish==false&&this->Cannot_AutoD==true))
        &&this->iCmd.iIOTctrl.connect_OK==true&&this->iCmd.iIOTctrl.session_Fatal==false)
    {
        //modify & check the comment area length
        this->richTextBox_comment->Text=this->richTextBox_comment->Text->Replace("\r", "");  //delete CR
        this->richTextBox_comment->Text=this->richTextBox_comment->Text->Replace("\n", "");  //delete LF
        int len=this->richTextBox_comment->TextLength;
        if(this->richTextBox_comment->TextLength>RDS_COMMENT_MAX_CHARS) {
            MessageBox::Show(RDS_COMMENT_LENGTH_ERR_TEXT, "Error",
                MessageBoxButtons::OK,
                MessageBoxIcon::Information);
            return;
        }
        this->RPT_save(this->textBox_UID_in->Text);
        this->RDS_rpt_saved=true;
        MsgLog("RS");
    }

    if(this->MyClientThreadRuning==true) {
        this->MyClientThreadRuning=false;
        mhClientThread->Abort();
    }
    this->iCmd.iIOTctrl.disconnect();
    MsgEngr("disconnected...");
    MsgLog("DC");
    this->textBox_UID_in->Enabled=true;
    this->button_disconnect->Enabled=false;  //disable Disconnect button
    this->button_disconnect->ForeColor=Color::Gray;

    //save LOG file (should be last action in disconnect....)
    this->Log_save(this->textBox_UID_in->Text);
    this->RDS_log_saved=true;

    //reset....
    initial_All();
    //
    UpdateUI();
}

//====================////
// Form close button  ////
//====================////
System::Void RDS_main_Form::RDS_closing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e)
{
    if(this->MyClientThreadRuning==true) {
        this->MyClientThreadRuning=false;
        mhClientThread->Abort();
    }
    this->iCmd.iIOTctrl.disconnect();

    //Save RDS report (if not saved, & if connection okay.....)
    if(this->RDS_rpt_saved==false&&this->Display_initial_OK==true
        &&((this->RDS_AD_finish==true&&this->Cannot_AutoD==false)||(this->RDS_AD_finish==false&&this->Cannot_AutoD==true))
        &&this->iCmd.iIOTctrl.connect_OK==true&&this->iCmd.iIOTctrl.session_Fatal==false)
    {
        //modify & check the comment area length
        this->richTextBox_comment->Text=this->richTextBox_comment->Text->Replace("\r", "");  //delete CR
        this->richTextBox_comment->Text=this->richTextBox_comment->Text->Replace("\n", "");  //delete LF
        int len=this->richTextBox_comment->TextLength;
        if(this->richTextBox_comment->TextLength>RDS_COMMENT_MAX_CHARS) {
            MessageBox::Show(RDS_COMMENT_LENGTH_ERR_TEXT, "Error",
                MessageBoxButtons::OK,
                MessageBoxIcon::Information);
            return;
        }
        this->RPT_save(this->textBox_UID_in->Text);
        this->RDS_rpt_saved=true;
        MsgLog("RS");
    }
    MsgLog("XX");
    //save LOG file (if it was not saved by press disconnect button)
    if(this->RDS_log_saved==false&&this->textBox_UID_in->Text!="" && this->Cur_RDSreport_str!="") {
        this->Log_save(this->textBox_UID_in->Text);
    }
}

//================//
// system Login   //
//================//
System::Void RDS_main_Form::LoginResult(
    Boolean LoginOk,
    unsigned char userNo,
    String^ Name
)
{
    int rtn;
    if(LoginOk==false) {
        if(this->MyClientThreadRuning==true) {
            this->MyClientThreadRuning=false;
            mhClientThread->Abort();
        }
        this->Close(); //close RDS app (if press exit button at Login-form)!!!!!!!!!!!!!!
    }
    //login ok....
    this->RDS_operator_No=userNo;
    this->RDS_operator_name=Name;
    this->comboBox_Model_Name->SelectedIndex=0;
}

//=========================//
// Read spa Model setting  //
//=========================//
// return = 0 : means oaky
// return = -1 : means has error (not number), program should abort!!
// return = -2 : means has error (less number parameter), program should abort!!
int RDS_main_Form::read_SpaModel_setting()
{
    Boolean hasNewModel;
    Boolean ADcouurnt_done;
    unsigned int mNo;
    unsigned int cnt_in_model;
    String^ fullfilename;
    String^ str;
    array<Char>^sep=gcnew array<Char>{
        ':', '='
    };
    array<String^>^result;

    //remove the original only one.(ComboBox)
    this->comboBox_Model_Name->Items->RemoveAt(0);

    //read from file
    fullfilename=RDS_NAS_ROOT_DIR+RDS_NAS_SPA_MODEL_FILENAME;
    //(TBD) try--catch
    StreamReader^ din=File::OpenText(fullfilename);

    mNo=0;
    cnt_in_model=AD_SETTING_LINES_PER_MODEL+PART_NO_LINES_PER_MODEL;
    hasNewModel=false;
    ADcouurnt_done=false;
    do {
        str=din->ReadLine();
        if(str!=nullptr) {
            str=str->Replace(" ", "");
            result=str->Split(sep, StringSplitOptions::RemoveEmptyEntries);
            //check format: result[2] should be number
            System::Int32 number;
            if(hasNewModel==false) { //read model name
                if(cnt_in_model==AD_SETTING_LINES_PER_MODEL+PART_NO_LINES_PER_MODEL) {
                    if(result->Length==2) { //checking length
                        if(result[0]=="Model_Name") { //cehcking string
                            //save
                            ModelNames[mNo]=(char*)Marshal::StringToHGlobalAnsi(result[1]).ToPointer();
                            //add to UI
                            this->comboBox_Model_Name->Items->Add(result[1]);
                            hasNewModel=true;
                            cnt_in_model=0;
                        }
                    }
                }
            }
            else {
                if(hasNewModel==true&&ADcouurnt_done==false) {  ///////////////////////////////read AD setting for a model
                    if(result->Length==3) { //checking length & string
                        if(System::Int32::TryParse(result[2], number)) {
                            //ok, it's number
                            if(result[1]=="AllOff_max") {
                                SpaModels[mNo].AllOff_max=Convert::ToInt32(result[2], 10);
                                cnt_in_model++;
                            }
                            if(result[1]=="AllOff_min") {
                                SpaModels[mNo].AllOff_min=Convert::ToInt32(result[2], 10);
                                cnt_in_model++;
                            }
                            if(result[1]=="AllOff_Heater_Circ_UV_max") {
                                SpaModels[mNo].AllOff_Heater_Circ_UV_max=Convert::ToInt32(result[2], 10);
                                cnt_in_model++;
                            }
                            if(result[1]=="AllOff_Heater_Circ_UV_min") {
                                SpaModels[mNo].AllOff_Heater_Circ_UV_min=Convert::ToInt32(result[2], 10);
                                cnt_in_model++;
                            }
                            if(result[1]=="AllOff_Circ_UV_max") {
                                SpaModels[mNo].AllOff_Circ_UV_max=Convert::ToInt32(result[2], 10);
                                cnt_in_model++;
                            }
                            if(result[1]=="AllOff_Circ_UV_min") {
                                SpaModels[mNo].AllOff_Circ_UV_min=Convert::ToInt32(result[2], 10);
                                cnt_in_model++;
                            }
                            if(result[1]=="Pump1_Hi_max") {
                                SpaModels[mNo].Pump1_Hi_max=Convert::ToInt32(result[2], 10);
                                cnt_in_model++;
                            }
                            if(result[1]=="Pump1_Hi_min") {
                                SpaModels[mNo].Pump1_Hi_min=Convert::ToInt32(result[2], 10);
                                cnt_in_model++;
                            }
                            if(result[1]=="Pump1_Hi_Circ_UV_max") {
                                SpaModels[mNo].Pump1_Hi_Circ_UV_max=Convert::ToInt32(result[2], 10);
                                cnt_in_model++;
                            }
                            if(result[1]=="Pump1_Hi_Circ_UV_min") {
                                SpaModels[mNo].Pump1_Hi_Circ_UV_min=Convert::ToInt32(result[2], 10);
                                cnt_in_model++;
                            }
                            if(result[1]=="Pump1_Hi_Heater_Circ_UV_max") {
                                SpaModels[mNo].Pump1_Hi_Heater_Circ_UV_max=Convert::ToInt32(result[2], 10);
                                cnt_in_model++;
                            }
                            if(result[1]=="Pump1_Hi_Heater_Circ_UV_min") {
                                SpaModels[mNo].Pump1_Hi_Heater_Circ_UV_min=Convert::ToInt32(result[2], 10);
                                cnt_in_model++;
                            }
                            if(result[1]=="Pump1_Lo_max") {
                                SpaModels[mNo].Pump1_Lo_max=Convert::ToInt32(result[2], 10);
                                cnt_in_model++;
                            }
                            if(result[1]=="Pump1_Lo_min") {
                                SpaModels[mNo].Pump1_Lo_min=Convert::ToInt32(result[2], 10);
                                cnt_in_model++;
                            }
                            if(result[1]=="Pump1_Lo_Circ_UV_max") {
                                SpaModels[mNo].Pump1_Lo_Circ_UV_max=Convert::ToInt32(result[2], 10);
                                cnt_in_model++;
                            }
                            if(result[1]=="Pump1_Lo_Circ_UV_min") {
                                SpaModels[mNo].Pump1_Lo_Circ_UV_min=Convert::ToInt32(result[2], 10);
                                cnt_in_model++;
                            }
                            if(result[1]=="Pump1_Lo_Heater_Circ_UV_max") {
                                SpaModels[mNo].Pump1_Lo_Heater_Circ_UV_max=Convert::ToInt32(result[2], 10);
                                cnt_in_model++;
                            }
                            if(result[1]=="Pump1_Lo_Heater_Circ_UV_min") {
                                SpaModels[mNo].Pump1_Lo_Heater_Circ_UV_min=Convert::ToInt32(result[2], 10);
                                cnt_in_model++;
                            }
                            if(result[1]=="Pump2_Hi_max") {
                                SpaModels[mNo].Pump2_Hi_max=Convert::ToInt32(result[2], 10);
                                cnt_in_model++;
                            }
                            if(result[1]=="Pump2_Hi_min") {
                                SpaModels[mNo].Pump2_Hi_min=Convert::ToInt32(result[2], 10);
                                cnt_in_model++;
                            }
                            if(result[1]=="Pump2_Hi_Heater_Circ_UV_max") {
                                SpaModels[mNo].Pump2_Hi_Heater_Circ_UV_max=Convert::ToInt32(result[2], 10);
                                cnt_in_model++;
                            }
                            if(result[1]=="Pump2_Hi_Heater_Circ_UV_min") {
                                SpaModels[mNo].Pump2_Hi_Heater_Circ_UV_min=Convert::ToInt32(result[2], 10);
                                cnt_in_model++;
                            }
                            if(result[1]=="Pump2_Lo_max") {
                                SpaModels[mNo].Pump2_Lo_max=Convert::ToInt32(result[2], 10);
                                cnt_in_model++;
                            }
                            if(result[1]=="Pump2_Lo_min") {
                                SpaModels[mNo].Pump2_Lo_min=Convert::ToInt32(result[2], 10);
                                cnt_in_model++;
                            }
                            if(result[1]=="Pump2_Lo_Heater_Circ_UV_max") {
                                SpaModels[mNo].Pump2_Lo_Heater_Circ_UV_max=Convert::ToInt32(result[2], 10);
                                cnt_in_model++;
                            }
                            if(result[1]=="Pump2_Lo_Heater_Circ_UV_min") {
                                SpaModels[mNo].Pump2_Lo_Heater_Circ_UV_min=Convert::ToInt32(result[2], 10);
                                cnt_in_model++;
                            }
                            if(result[1]=="Pump3_Hi_max") {
                                SpaModels[mNo].Pump3_Hi_max=Convert::ToInt32(result[2], 10);
                                cnt_in_model++;
                            }
                            if(result[1]=="Pump3_Hi_min") {
                                SpaModels[mNo].Pump3_Hi_min=Convert::ToInt32(result[2], 10);
                                cnt_in_model++;
                            }
                            if(result[1]=="Pump3_Hi_Heater_Circ_UV_max") {
                                SpaModels[mNo].Pump3_Hi_Heater_Circ_UV_max=Convert::ToInt32(result[2], 10);
                                cnt_in_model++;
                            }
                            if(result[1]=="Pump3_Hi_Heater_Circ_UV_min") {
                                SpaModels[mNo].Pump3_Hi_Heater_Circ_UV_min=Convert::ToInt32(result[2], 10);
                                cnt_in_model++;
                            }
                            if(result[1]=="Pump3_Lo_max") {
                                SpaModels[mNo].Pump3_Lo_max=Convert::ToInt32(result[2], 10);
                                cnt_in_model++;
                            }
                            if(result[1]=="Pump3_Lo_min") {
                                SpaModels[mNo].Pump3_Lo_min=Convert::ToInt32(result[2], 10);
                                cnt_in_model++;
                            }
                            if(result[1]=="Pump3_Lo_Heater_Circ_UV_max") {
                                SpaModels[mNo].Pump3_Lo_Heater_Circ_UV_max=Convert::ToInt32(result[2], 10);
                                cnt_in_model++;
                            }
                            if(result[1]=="Pump3_Lo_Heater_Circ_UV_min") {
                                SpaModels[mNo].Pump3_Lo_Heater_Circ_UV_min=Convert::ToInt32(result[2], 10);
                                cnt_in_model++;
                            }
                            if(result[1]=="Blower_max") {
                                SpaModels[mNo].Blower_max=Convert::ToInt32(result[2], 10);
                                cnt_in_model++;
                            }
                            if(result[1]=="Blower_min") {
                                SpaModels[mNo].Blower_min=Convert::ToInt32(result[2], 10);
                                cnt_in_model++;
                            }
                            if(result[1]=="Blower_Heater_Circ_UV_max") {
                                SpaModels[mNo].Blower_Heater_Circ_UV_max=Convert::ToInt32(result[2], 10);
                                cnt_in_model++;
                            }
                            if(result[1]=="Blower_Heater_Circ_UV_min") {
                                SpaModels[mNo].Blower_Heater_Circ_UV_min=Convert::ToInt32(result[2], 10);
                                cnt_in_model++;
                                if(cnt_in_model!=AD_SETTING_LINES_PER_MODEL) {
                                    //it's not total 38 lines, ERROR case...
                                    MessageBox::Show(MSG_MAINFORM_LOGIN_SAPMODEL_INI_ERR1, "Error",
                                        MessageBoxButtons::OK,
                                        MessageBoxIcon::Information);
                                    //ending and exit
                                    din->Close();
                                    return -2;
                                }
                                else { //Okay case
                                    ADcouurnt_done=true;
                                }
                            }
                        }
                        else {
                            //resullt[2] is not a number
                            MessageBox::Show(MSG_MAINFORM_LOGIN_SAPMODEL_INI_ERR2, "Error",
                                MessageBoxButtons::OK,
                                MessageBoxIcon::Information);
                            //ending and exit
                            din->Close();
                            return -1;
                        }
                    }//end-if length==3
                }//end-----hasNewModel == true && ADcouurnt_done ==false
                else {
                    if(hasNewModel==true&&ADcouurnt_done==true) { ///////////////////////////////////// Part-No part
                        //reading Part-No string.
                        if(result->Length==3) { //checking length & string
                            if(result[1]=="Pump_1") {
                                PartNoList[mNo][0]=(char*)Marshal::StringToHGlobalAnsi(result[2]).ToPointer();
                                cnt_in_model++;
                            }
                            if(result[1]=="Pump_2") {
                                PartNoList[mNo][1]=(char*)Marshal::StringToHGlobalAnsi(result[2]).ToPointer();
                                cnt_in_model++;
                            }
                            if(result[1]=="Pump_3") {
                                PartNoList[mNo][2]=(char*)Marshal::StringToHGlobalAnsi(result[2]).ToPointer();
                                cnt_in_model++;
                            }
                            if(result[1]=="Circ_Pump") {
                                PartNoList[mNo][3]=(char*)Marshal::StringToHGlobalAnsi(result[2]).ToPointer();
                                cnt_in_model++;
                            }
                            if(result[1]=="Blower") {
                                PartNoList[mNo][4]=(char*)Marshal::StringToHGlobalAnsi(result[2]).ToPointer();
                                cnt_in_model++;
                            }
                            if(result[1]=="Heater") {
                                PartNoList[mNo][5]=(char*)Marshal::StringToHGlobalAnsi(result[2]).ToPointer();
                                cnt_in_model++;
                            }
                            if(result[1]=="Topside") {
                                PartNoList[mNo][6]=(char*)Marshal::StringToHGlobalAnsi(result[2]).ToPointer();
                                cnt_in_model++;
                            }
                            if(result[1]=="CTR_Borad") {
                                PartNoList[mNo][7]=(char*)Marshal::StringToHGlobalAnsi(result[2]).ToPointer();
                                cnt_in_model++;
                            }
                            if(result[1]=="Water_Temp_Sensor") {
                                PartNoList[mNo][8]=(char*)Marshal::StringToHGlobalAnsi(result[2]).ToPointer();
                                cnt_in_model++;
                            }
                            if(result[1]=="Hi_limit_Sensor") {
                                PartNoList[mNo][9]=(char*)Marshal::StringToHGlobalAnsi(result[2]).ToPointer();
                                cnt_in_model++;
                            }
                            if(result[1]=="Flow_Switch") {
                                PartNoList[mNo][10]=(char*)Marshal::StringToHGlobalAnsi(result[2]).ToPointer();
                                cnt_in_model++;
                            }
                            if(result[1]=="Fuse") {
                                PartNoList[mNo][11]=(char*)Marshal::StringToHGlobalAnsi(result[2]).ToPointer();
                                cnt_in_model++;
                            }
                            if(result[1]=="UV_Light") {
                                PartNoList[mNo][12]=(char*)Marshal::StringToHGlobalAnsi(result[2]).ToPointer();
                                cnt_in_model++;
                            }
                            if(result[1]=="Filter_Cartridge") {
                                PartNoList[mNo][13]=(char*)Marshal::StringToHGlobalAnsi(result[2]).ToPointer();
                                cnt_in_model++;
                            }
                            if(result[1]=="Pipe") {
                                PartNoList[mNo][14]=(char*)Marshal::StringToHGlobalAnsi(result[2]).ToPointer();
                                cnt_in_model++;

                                //checking .....
                                if(cnt_in_model!=AD_SETTING_LINES_PER_MODEL+PART_NO_LINES_PER_MODEL) {
                                    //it's not total 38 lines, ERROR case...
                                    MessageBox::Show(MSG_MAINFORM_LOGIN_SAPMODEL_INI_ERR1, "Error",
                                        MessageBoxButtons::OK,
                                        MessageBoxIcon::Information);
                                    //ending and exit
                                    din->Close();
                                    return -2;
                                }
                                else { //Okay case
                                    //next Model....
                                    hasNewModel=false;
                                    ADcouurnt_done=false;
                                    mNo++;
                                    //finish all model?
                                    if(mNo==MAX_HOT_TUV_MODELS) {
                                        break;  //will not read more lines in INI file. (exit While loop)
                                    }
                                }
                            }
                        }//end-if length==3
                    }//end if---hasNewModel == true && ADcouurnt_done ==true
                }//end if---hasNewModel == true && ADcouurnt_done ==false
            }//end-f-------------------------------------- two part
        }//end-if string is not null
    } while(str!=nullptr);

    //checking ending....
    if(cnt_in_model!=AD_SETTING_LINES_PER_MODEL+PART_NO_LINES_PER_MODEL) {
        //it's not total 38 lines
        MessageBox::Show(MSG_MAINFORM_LOGIN_SAPMODEL_INI_ERR3, "Error",
            MessageBoxButtons::OK,
            MessageBoxIcon::Information);
        //ending and exit
        din->Close();
        return -2;
    }
    else {
        //ending of file reading
        din->Close();
        return 0;
    }
}

//========================//
// Date/Time Form show up //
//========================//
System::Void RDS_main_Form::button_Date_Time_Click(System::Object^  sender, System::EventArgs^  e)
{
    this->Cursor=Cursors::WaitCursor; //it may take time....
    SaveCursorX=Cursor->Position.X;
    SaveCursorY=Cursor->Position.Y-120;
    if(this->iCmd.iIOTctrl.packet_OK==true&&this->iCmd.received_ValidPacket>2) {
        //connection okay
        toOpenChildWin=true;
        this->iCmd.SendSingleCmdPacket(0x31); //get DateTime
        SetWaitingCmd(0x31);
        MsgLog("TT");
    }
    else {
        this->Cursor=Cursors::Default; //reset cursor
        MessageBox::Show(MSG_MAINFORM_NO_CONNECTION_HINT, "Message",
            MessageBoxButtons::OK,
            MessageBoxIcon::Information);
    }
}

//only receiving command=0x31 then call this function ==> checking DisplayText() & Wait_Retry()
System::Void RDS_main_Form::openDataTimeWin()
{
    /* Checking value....
    time_year,   //00~99 : 2000~2099
    time_month,  //1~12
    time_day,    //1~31
    time_week,   //1=sun, 2=mon....7=Sat
    time_hour,	 //0~23
    time_min	 //0~59
    */
    if(this->iCmd.iSPA.time_year<0||this->iCmd.iSPA.time_year > 99||
        this->iCmd.iSPA.time_month<1||this->iCmd.iSPA.time_month > 12||
        this->iCmd.iSPA.time_day<1||this->iCmd.iSPA.time_day > 31||
        this->iCmd.iSPA.time_week<1||this->iCmd.iSPA.time_week > 7||
        this->iCmd.iSPA.time_hour<0||this->iCmd.iSPA.time_hour > 23||
        this->iCmd.iSPA.time_min<0||this->iCmd.iSPA.time_min > 59) {
        MessageBox::Show(MSG_MAINFORM_DATETIME_OUT_RANGE, "TimeOut",
            MessageBoxButtons::OK,
            MessageBoxIcon::Information);
    }
    else {
        this->button_Date_Time->Enabled=false;
        RDS::DateTime_Form^ formDateTime=gcnew DateTime_Form(this);
        formDateTime->time_year=this->iCmd.iSPA.time_year;
        formDateTime->time_month=this->iCmd.iSPA.time_month;
        formDateTime->time_day=this->iCmd.iSPA.time_day;
        formDateTime->time_week=this->iCmd.iSPA.time_week;
        formDateTime->time_hour=this->iCmd.iSPA.time_hour;
        formDateTime->time_min=this->iCmd.iSPA.time_min;
        formDateTime->SetDesktopLocation(SaveCursorX, SaveCursorY);
        formDateTime->Show();
    }
}

void RDS_main_Form::enable_DateTime_btn()
{
    this->button_Date_Time->Enabled=true;
}

//after child-window press "save to SPA" button. it will call this function
//this function will send IOT command, als svae the setting vallue (in RDS_main_Form object)
//than wait CTR response back.....
System::Void RDS_main_Form::set_DateTime(
    unsigned char time_year,   //00~99 : 2000~2099
    unsigned char time_month,  //1~12
    unsigned char time_day,    //1~31
    unsigned char time_week,   //1=sun, 2=mon....7=Sat
    unsigned char time_hour,
    unsigned char time_min
)
{
    //save an copy for future checking
    this->time_year=time_year;
    this->time_month=time_month;
    this->time_day=time_day;
    this->time_week=time_week;
    this->time_hour=time_hour;
    this->time_min=time_min;
    MsgLog("T2:"+time_year+":"+time_month+":"+time_day+":"+time_week+":"+time_hour+":"+time_min);
    //send command...
    array<unsigned char>^ buffer;
    Array::Resize(buffer, 9);
    buffer[0]=NEW_2015_PROTOCOL_CODE;
    buffer[1]=0x21; //Command  -- Set Date & Time
    buffer[2]=time_year;
    buffer[3]=time_month;
    buffer[4]=time_day;
    buffer[5]=time_week;
    buffer[6]=time_hour;
    buffer[7]=time_min;
    buffer[8]=0;  //set default seconds
    this->iCmd.SendCmdPacket(buffer);
    SettingCmd_31=true; //set flage, later will check it successful or not
    resend_31=0;
    SetWaitingCmd(0x31);
}

//after child-window close & already send IOT command(cmd=21),
//Use this function to checking the read-back (cmd=31) is same as saved copy or not
//if not match, re-send cmd=21
System::Void RDS_main_Form::checkingDateTime()
{
    array<unsigned char>^ buffer;
    Array::Resize(buffer, 9);
    Boolean same=true;
    //compare values
    if(this->time_year!=this->iCmd.iSPA.time_year)  same=false;
    if(this->time_month!=this->iCmd.iSPA.time_month) same=false;
    if(this->time_day!=this->iCmd.iSPA.time_day)   same=false;
    if(this->time_week!=this->iCmd.iSPA.time_week)  same=false;
    if(this->time_hour!=this->iCmd.iSPA.time_hour)  same=false;
    if(this->time_min!=this->iCmd.iSPA.time_min)   same=false;
    //re-send or close or time-out
    if(same==true) {
        //close checking
        SettingCmd_31=false;
        this->Cursor=Cursors::Default; //reset cursor
        MsgLog("TK");
    }
    else {
        if(resend_31<COMMAND_RESEND_TIMES) {
            //re-send command 21 from saved copy
            resend_31++;
            buffer[0]=NEW_2015_PROTOCOL_CODE;
            buffer[1]=0x21; //Command  -- Set Date & Time
            buffer[2]=this->time_year;
            buffer[3]=this->time_month;
            buffer[4]=this->time_day;
            buffer[5]=this->time_week;
            buffer[6]=this->time_hour;
            buffer[7]=this->time_min;
            buffer[8]=10;  //set default seconds
            this->iCmd.SendCmdPacket(buffer);
            SetWaitingCmd(0x31);
        }
        else {
            //time-out Error!!!
            SettingCmd_31=false;
            MessageBox::Show(MSG_MAINFORM_DATETIME_CMD31_TIMEOUT, "TimeOut",
                MessageBoxButtons::OK,
                MessageBoxIcon::Information);
        }
    }
}

//=========================//
// SF filter-sch show up   //
//=========================//
System::Void RDS_main_Form::button_SF_Click(System::Object^  sender, System::EventArgs^  e)
{
    this->Cursor=Cursors::WaitCursor; //it may take time....
    SaveCursorX=Cursor->Position.X;
    SaveCursorY=Cursor->Position.Y-120;
    if(this->iCmd.iIOTctrl.packet_OK==true&&this->iCmd.received_ValidPacket>2) {
        //connection okay
        toOpenChildWin=true;
        this->iCmd.SendSingleCmdPacket(0x36); //get SF
        SetWaitingCmd(0x36);
        MsgLog("SS");
    }
    else {
        this->Cursor=Cursors::Default; //reset cursor
        MessageBox::Show(MSG_MAINFORM_NO_CONNECTION_HINT, "Message",
            MessageBoxButtons::OK,
            MessageBoxIcon::Information);
    }
}

//only receiving command=0x36 then call this function ==> checking DisplayText() & Wait_Retry()
System::Void RDS_main_Form::open_SF_Win()
{
    this->button_SF->Enabled=false;
    RDS::set_SF_Form^ formSF=gcnew set_SF_Form(this);
    formSF->sf_value=this->iCmd.iSPA.sf_value;
    formSF->SetDesktopLocation(SaveCursorX, SaveCursorY);
    formSF->Show();
}

void RDS_main_Form::enable_SF_btn()
{
    this->button_SF->Enabled=true;
}

//after child-window press "save to SPA" button. it will call this function
//this function will send IOT command, als svae the setting vallue (in RDS_main_Form object)
//than wait CTR response back.....
System::Void RDS_main_Form::set_SF(
    unsigned int sf_value
)
{
    //save an copy for future checking
    this->sf_value=sf_value;
    MsgLog("S2:"+sf_value);
    //send command...
    array<unsigned char>^ buffer;
    Array::Resize(buffer, 3);
    buffer[0]=NEW_2015_PROTOCOL_CODE;
    buffer[1]=0x26; //Command  -- Set SF
    buffer[2]=sf_value;
    this->iCmd.SendCmdPacket(buffer);
    SettingCmd_36=true; //set flage, later will check it successful or not
    resend_36=0;
    SetWaitingCmd(0x36);
}

//after child-window close & already send IOT command(cmd=26),
//Use this function to checking the read-back (cmd=31) is same as saved copy or not
//if not match, re-send cmd=26
System::Void RDS_main_Form::checkingSF()
{
    array<unsigned char>^ buffer;
    Array::Resize(buffer, 3);
    Boolean same=true;
    //compare values
    if(this->sf_value!=this->iCmd.iSPA.sf_value)  same=false;
    //re-send or close or time-out
    if(same==true) {
        //close checking
        SettingCmd_36=false;
        this->Cursor=Cursors::Default; //reset cursor
        MsgLog("SK");
    }
    else {
        if(resend_36<COMMAND_RESEND_TIMES) {
            //re-send command 26 from saved copy
            resend_36++;
            buffer[0]=NEW_2015_PROTOCOL_CODE;
            buffer[1]=0x26; //Command  -- Set SF
            buffer[2]=this->sf_value;
            this->iCmd.SendCmdPacket(buffer);
            SetWaitingCmd(0x36);
        }
        else {
            //time-out Error!!!
            SettingCmd_36=false;
            MessageBox::Show(MSG_MAINFORM_SF_SCH_CMD36_TIMEOUT, "TimeOut",
                MessageBoxButtons::OK,
                MessageBoxIcon::Information);
        }
    }
}

//=========================//
// PF filter-sch show up   //
//=========================//
System::Void RDS_main_Form::button_PF_Click(System::Object^  sender, System::EventArgs^  e)
{
    this->Cursor=Cursors::WaitCursor; //it may take time....
    SaveCursorX=Cursor->Position.X;
    SaveCursorY=Cursor->Position.Y-120;
    if(this->iCmd.iIOTctrl.packet_OK==true&&this->iCmd.received_ValidPacket>2) {
        //connection okay
        toOpenChildWin=true;
        this->iCmd.SendSingleCmdPacket(0x35); //get PF
        SetWaitingCmd(0x35);
        MsgLog("PP");
    }
    else {
        this->Cursor=Cursors::Default; //reset cursor
        MessageBox::Show(MSG_MAINFORM_NO_CONNECTION_HINT, "Message",
            MessageBoxButtons::OK,
            MessageBoxIcon::Information);
    }
}

//only receiving command=0x36 then call this function ==> checking DisplayText() & Wait_Retry()
System::Void RDS_main_Form::open_PF_Win()
{
    this->button_PF->Enabled=false;
    RDS::set_PF_Form^ formPF=gcnew set_PF_Form(this);
    formPF->pf_value=this->iCmd.iSPA.pf_value;
    formPF->pf_st_hour=this->iCmd.iSPA.pf_st_hour;
    formPF->pf_st_min=this->iCmd.iSPA.pf_st_min;
    formPF->pf_dt_hour=this->iCmd.iSPA.pf_dt_hour;
    formPF->pf_dt_min=this->iCmd.iSPA.pf_dt_min;
    formPF->SetDesktopLocation(SaveCursorX, SaveCursorY);
    formPF->Show();
}

void RDS_main_Form::enable_PF_btn()
{
    this->button_PF->Enabled=true;
}

//after child-window press "save to SPA" button. it will call this function
//this function will send IOT command, als svae the setting vallue (in RDS_main_Form object)
//than wait CTR response back.....
System::Void RDS_main_Form::set_PF(
    unsigned int pf_value,
    unsigned char pf_st_hour,
    unsigned char pf_st_min,
    unsigned char pf_dt_hour,
    unsigned char pf_dt_min
)
{
    //save an copy for future checking
    this->pf_value=pf_value;
    this->pf_st_hour=pf_st_hour;
    this->pf_st_min=pf_st_min;
    this->pf_dt_hour=pf_dt_hour;
    this->pf_dt_min=pf_dt_min;
    MsgLog("P2:"+pf_st_hour+":"+pf_st_min+":"+pf_dt_hour+":"+pf_dt_min);
    //send command...
    array<unsigned char>^ buffer;
    Array::Resize(buffer, 8);
    buffer[0]=NEW_2015_PROTOCOL_CODE;
    buffer[1]=0x25; //Command  -- Set PF
    buffer[2]=pf_value;
    buffer[3]=pf_st_hour;
    buffer[4]=pf_st_min;
    buffer[5]=pf_dt_hour;
    buffer[6]=pf_dt_min;
    buffer[7]=0x7f;
    this->iCmd.SendCmdPacket(buffer);
    SettingCmd_35=true; //set flage, later will check it successful or not
    resend_35=0;
    SetWaitingCmd(0x35);
}

//after child-window close & already send IOT command(cmd=25),
//Use this function to checking the read-back (cmd=31) is same as saved copy or not
//if not match, re-send cmd=25
System::Void RDS_main_Form::checkingPF()
{
    array<unsigned char>^ buffer;
    Array::Resize(buffer, 8);
    Boolean same=true;
    //compare values
    if(this->pf_value!=this->iCmd.iSPA.pf_value)   same=false;
    if(this->pf_st_hour!=this->iCmd.iSPA.pf_st_hour) same=false;
    if(this->pf_st_min!=this->iCmd.iSPA.pf_st_min)  same=false;
    if(this->pf_dt_hour!=this->iCmd.iSPA.pf_dt_hour) same=false;
    if(this->pf_dt_min!=this->iCmd.iSPA.pf_dt_min)  same=false;
    //re-send or close or time-out
    if(same==true) {
        //close checking
        SettingCmd_35=false;
        this->Cursor=Cursors::Default; //reset cursor
        MsgLog("PK");
    }
    else {
        if(resend_35<COMMAND_RESEND_TIMES) {
            //re-send command 26 from saved copy
            resend_35++;
            buffer[0]=NEW_2015_PROTOCOL_CODE;
            buffer[1]=0x25; //Command  -- Set PF
            buffer[2]=this->pf_value;
            buffer[3]=pf_st_hour;
            buffer[4]=pf_st_min;
            buffer[5]=pf_dt_hour;
            buffer[6]=pf_dt_min;
            buffer[7]=0x7f;
            this->iCmd.SendCmdPacket(buffer);
            SetWaitingCmd(0x35);
        }
        else {
            //time-out Error!!!
            SettingCmd_35=false;
            MessageBox::Show(MSG_MAINFORM_PF_CMD35_TIMEOUT, "TimeOut",
                MessageBoxButtons::OK,
                MessageBoxIcon::Information);
        }
    }
}

//=========================//
// Filter schedule show up //
//=========================//
System::Void RDS_main_Form::button_Filtration_sch_Click(System::Object^  sender, System::EventArgs^  e)
{
    if(this->iCmd.iIOTctrl.packet_OK==true&&this->iCmd.received_ValidPacket>2) {
        this->Cursor=Cursors::WaitCursor; //it may take time....
        //connection okay
        if(this->iCmd.iSPA.ecoModeOn==true) {
            SaveCursorX=Cursor->Position.X;
            SaveCursorY=Cursor->Position.Y-260;
            //get data from SPA (ECO)
            toOpenChildWin=true;
            this->iCmd.SendSingleCmdPacket(0x33); //get eco filter schedule
            this->iCmd.eco1_upated=false;
            this->iCmd.eco2_upated=false;
            this->iCmd.eco3_upated=false;
            this->iCmd.eco4_upated=false;
            SetWaitingCmd(0x33);
            MsgLog("EE");
        }
        else {
            SaveCursorX=Cursor->Position.X;
            SaveCursorY=Cursor->Position.Y-100;
            //get data from SPA (STD)
            toOpenChildWin=true;
            this->iCmd.SendSingleCmdPacket(0x32); //get std filter schedule
            SetWaitingCmd(0x32);
            MsgLog("FF");
        }
    }
    else {
        this->Cursor=Cursors::Default; //reset cursor
        MessageBox::Show(MSG_MAINFORM_NO_CONNECTION_HINT, "Message",
            MessageBoxButtons::OK,
            MessageBoxIcon::Information);
    }
}

//only receiving command=0x32 then call this function ==> checking DisplayText() & Wait_Retry()
System::Void RDS_main_Form::openStdCircScheduleWin()
{
    this->button_Filtration_sch->Enabled=false;
    RDS::FltSchedule_Form^ formFltSchedule=gcnew FltSchedule_Form(this);
    formFltSchedule->std_st_hour=this->iCmd.iSPA.std_st_hour;
    formFltSchedule->std_st_min=this->iCmd.iSPA.std_st_min;
    formFltSchedule->std_dt_hour=this->iCmd.iSPA.std_dt_hour;
    formFltSchedule->std_dt_min=this->iCmd.iSPA.std_dt_min;
    formFltSchedule->std_week=this->iCmd.iSPA.std_week;
    formFltSchedule->SetDesktopLocation(SaveCursorX, SaveCursorY);
    formFltSchedule->Show();
}

void RDS_main_Form::enable_FilterSchedule_btn()
{
    this->button_Filtration_sch->Enabled=true;
}

//after child-window press "save to SPA" button. it iwll can this function
//this function will send IOT command, also svae the setting vallue (in RDS_main_Form object)
//than wait CTR response back.....
System::Void RDS_main_Form::set_StdFilterSchedule(
    unsigned char std_st_hour,
    unsigned char std_st_min,
    unsigned char std_dt_hour,
    unsigned char std_dt_min,
    unsigned char std_week
)
{
    //save an copy for future checking
    this->std_st_hour=std_st_hour;
    this->std_st_min=std_st_min;
    this->std_dt_hour=std_dt_hour;
    this->std_dt_min=std_dt_min;
    this->std_week=std_week;
    MsgLog("F2:"+std_st_hour+":"+std_st_min+":"+std_dt_hour+":"+std_dt_min+":"+std_week);
    //send command...
    array<unsigned char>^ buffer;
    Array::Resize(buffer, 8);
    buffer[0]=NEW_2015_PROTOCOL_CODE;
    buffer[1]=0x22; //Command  -- Set std filter schedule
    buffer[2]=1; //group
    buffer[3]=std_st_hour;
    buffer[4]=std_st_min;
    buffer[5]=std_dt_hour;
    buffer[6]=std_dt_min;
    buffer[7]=std_week;
    this->iCmd.SendCmdPacket(buffer);
    SettingCmd_32=true; //set flage, later will check it successful or not
    resend_32=0;
    SetWaitingCmd(0x32);
}

//after child-window close & already send IOT command(cmd=22),
//Use this function to checking the read-back (cmd=32) is same as saved copy or not
//if not match, re-send cmd=22
System::Void RDS_main_Form::checkingStdFilterSchedule()
{
    array<unsigned char>^ buffer;
    Array::Resize(buffer, 8);
    Boolean same=true;
    //compare values
    if(this->std_st_hour!=this->iCmd.iSPA.std_st_hour) same=false;
    if(this->std_st_min!=this->iCmd.iSPA.std_st_min) same=false;
    if(this->std_dt_hour!=this->iCmd.iSPA.std_dt_hour) same=false;
    if(this->std_dt_min!=this->iCmd.iSPA.std_dt_min) same=false;
    if(this->std_week!=this->iCmd.iSPA.std_week) same=false;
    //re-send or close or time-out
    if(same==true) {
        //close checking
        SettingCmd_32=false;
        this->Cursor=Cursors::Default; //reset cursor
        MsgLog("FK");
    }
    else {
        if(resend_32<COMMAND_RESEND_TIMES) {
            //re-send command 21 from saved copy
            resend_32++;
            buffer[0]=NEW_2015_PROTOCOL_CODE;
            buffer[1]=0x22; //Command  -- Set std filter schedule
            buffer[2]=1; //group
            buffer[3]=std_st_hour;
            buffer[4]=std_st_min;
            buffer[5]=std_dt_hour;
            buffer[6]=std_dt_min;
            buffer[7]=std_week;
            this->iCmd.SendCmdPacket(buffer);
            SetWaitingCmd(0x32);
        }
        else {
            //time-out Error!!!
            SettingCmd_32=false;
            MessageBox::Show(MSG_MAINFORM_FLT_SCH_CMD32_TIMEOUT, "TimeOut",
                MessageBoxButtons::OK,
                MessageBoxIcon::Information);
        }
    }
}

//only receiving command=0x33 then call this function ==> checking DisplayText() & Wait_Retry()
System::Void RDS_main_Form::openEcoCircScheduleWin()
{
    this->button_Filtration_sch->Enabled=false;
    RDS::EcoSchedule_Form^ formEcoSchedule=gcnew EcoSchedule_Form(this);
    formEcoSchedule->eco_1_st_hour=this->iCmd.iSPA.eco_1_st_hour;
    formEcoSchedule->eco_2_st_hour=this->iCmd.iSPA.eco_2_st_hour;
    formEcoSchedule->eco_3_st_hour=this->iCmd.iSPA.eco_3_st_hour;
    formEcoSchedule->eco_4_st_hour=this->iCmd.iSPA.eco_4_st_hour;
    formEcoSchedule->eco_1_st_min=this->iCmd.iSPA.eco_1_st_min;
    formEcoSchedule->eco_2_st_min=this->iCmd.iSPA.eco_2_st_min;
    formEcoSchedule->eco_3_st_min=this->iCmd.iSPA.eco_3_st_min;
    formEcoSchedule->eco_4_st_min=this->iCmd.iSPA.eco_4_st_min;
    formEcoSchedule->eco_1_dt_hour=this->iCmd.iSPA.eco_1_dt_hour;
    formEcoSchedule->eco_2_dt_hour=this->iCmd.iSPA.eco_2_dt_hour;
    formEcoSchedule->eco_3_dt_hour=this->iCmd.iSPA.eco_3_dt_hour;
    formEcoSchedule->eco_4_dt_hour=this->iCmd.iSPA.eco_4_dt_hour;
    formEcoSchedule->eco_1_dt_min=this->iCmd.iSPA.eco_1_dt_min;
    formEcoSchedule->eco_2_dt_min=this->iCmd.iSPA.eco_2_dt_min;
    formEcoSchedule->eco_3_dt_min=this->iCmd.iSPA.eco_3_dt_min;
    formEcoSchedule->eco_4_dt_min=this->iCmd.iSPA.eco_4_dt_min;
    formEcoSchedule->eco_1_week=this->iCmd.iSPA.eco_1_week;
    formEcoSchedule->eco_2_week=this->iCmd.iSPA.eco_2_week;
    formEcoSchedule->eco_3_week=this->iCmd.iSPA.eco_3_week;
    formEcoSchedule->eco_4_week=this->iCmd.iSPA.eco_4_week;
    formEcoSchedule->SetDesktopLocation(SaveCursorX, SaveCursorY);
    formEcoSchedule->Show();
}

//after child-window press "save to SPA" button. it iwll can this function
//this function will send IOT command, also svae the setting vallue (in RDS_main_Form object)
//than wait CTR response back.....
System::Void RDS_main_Form::set_EcoFilterSchedule(
    unsigned char eco_1_st_hour,
    unsigned char eco_1_st_min,
    unsigned char eco_1_dt_hour,
    unsigned char eco_1_dt_min,
    unsigned char eco_2_st_hour,
    unsigned char eco_2_st_min,
    unsigned char eco_2_dt_hour,
    unsigned char eco_2_dt_min,
    unsigned char eco_3_st_hour,
    unsigned char eco_3_st_min,
    unsigned char eco_3_dt_hour,
    unsigned char eco_3_dt_min,
    unsigned char eco_4_st_hour,
    unsigned char eco_4_st_min,
    unsigned char eco_4_dt_hour,
    unsigned char eco_4_dt_min,
    unsigned char eco_1_week,
    unsigned char eco_2_week,
    unsigned char eco_3_week,
    unsigned char eco_4_week
)
{
    //save an copy for future checking
    this->eco_1_st_hour=eco_1_st_hour;
    this->eco_1_st_min=eco_1_st_min;
    this->eco_1_dt_hour=eco_1_dt_hour;
    this->eco_1_dt_min=eco_1_dt_min;
    this->eco_2_st_hour=eco_2_st_hour;
    this->eco_2_st_min=eco_2_st_min;
    this->eco_2_dt_hour=eco_2_dt_hour;
    this->eco_2_dt_min=eco_2_dt_min;
    this->eco_3_st_hour=eco_3_st_hour;
    this->eco_3_st_min=eco_3_st_min;
    this->eco_3_dt_hour=eco_3_dt_hour;
    this->eco_3_dt_min=eco_3_dt_min;
    this->eco_4_st_hour=eco_4_st_hour;
    this->eco_4_st_min=eco_4_st_min;
    this->eco_4_dt_hour=eco_4_dt_hour;
    this->eco_4_dt_min=eco_4_dt_min;
    this->eco_1_week=eco_1_week;
    this->eco_2_week=eco_2_week;
    this->eco_3_week=eco_3_week;
    this->eco_4_week=eco_4_week;
    MsgLog("E2:"+eco_1_st_hour+":"+eco_1_st_min+":"+eco_1_dt_hour+":"+eco_1_dt_min+":"+eco_1_week+":"
        +eco_2_st_hour+":"+eco_2_st_min+":"+eco_2_dt_hour+":"+eco_2_dt_min+":"+eco_2_week+":"
        +eco_3_st_hour+":"+eco_3_st_min+":"+eco_3_dt_hour+":"+eco_3_dt_min+":"+eco_3_week+":"
        +eco_4_st_hour+":"+eco_4_st_min+":"+eco_4_dt_hour+":"+eco_4_dt_min+":"+eco_4_week);
    //send command...
    array<unsigned char>^ buffer;
    Array::Resize(buffer, 8);
    buffer[0]=NEW_2015_PROTOCOL_CODE;
    buffer[1]=0x23; //Command  -- Set Eco filter schedule
    buffer[2]=1; //group
    buffer[3]=eco_1_st_hour;
    buffer[4]=eco_1_st_min;
    buffer[5]=eco_1_dt_hour;
    buffer[6]=eco_1_dt_min;
    buffer[7]=eco_1_week;
    this->iCmd.SendCmdPacket(buffer);
    SettingCmd_33=true; //set flage, later will check it successful or not
    resend_33=0;
    SetWaitingCmd(0x33);
    //
    buffer[2]=2; //group
    buffer[3]=eco_2_st_hour;
    buffer[4]=eco_2_st_min;
    buffer[5]=eco_2_dt_hour;
    buffer[6]=eco_2_dt_min;
    buffer[7]=eco_2_week;
    this->iCmd.SendCmdPacket(buffer);
    buffer[2]=3; //group
    buffer[3]=eco_3_st_hour;
    buffer[4]=eco_3_st_min;
    buffer[5]=eco_3_dt_hour;
    buffer[6]=eco_3_dt_min;
    buffer[7]=eco_3_week;
    this->iCmd.SendCmdPacket(buffer);
    buffer[2]=4; //group
    buffer[3]=eco_4_st_hour;
    buffer[4]=eco_4_st_min;
    buffer[5]=eco_4_dt_hour;
    buffer[6]=eco_4_dt_min;
    buffer[7]=eco_4_week;
    this->iCmd.SendCmdPacket(buffer);
}

//after child-window close & already send IOT command(cmd=23),
//Use this function to checking the read-back (cmd=32) is same as saved copy or not
//if not match, re-send cmd=23
System::Void RDS_main_Form::checkingEcoFilterSchedule()
{
    array<unsigned char>^ buffer;
    Array::Resize(buffer, 8);
    Boolean same=true;
    //compare values
    if(this->eco_1_st_hour!=this->iCmd.iSPA.eco_1_st_hour) same=false;
    if(this->eco_1_st_min!=this->iCmd.iSPA.eco_1_st_min) same=false;
    if(this->eco_1_dt_hour!=this->iCmd.iSPA.eco_1_dt_hour) same=false;
    if(this->eco_1_dt_min!=this->iCmd.iSPA.eco_1_dt_min) same=false;
    if(this->eco_2_st_hour!=this->iCmd.iSPA.eco_2_st_hour) same=false;
    if(this->eco_2_st_min!=this->iCmd.iSPA.eco_2_st_min) same=false;
    if(this->eco_2_dt_hour!=this->iCmd.iSPA.eco_2_dt_hour) same=false;
    if(this->eco_2_dt_min!=this->iCmd.iSPA.eco_2_dt_min) same=false;
    if(this->eco_3_st_hour!=this->iCmd.iSPA.eco_3_st_hour) same=false;
    if(this->eco_3_st_min!=this->iCmd.iSPA.eco_3_st_min) same=false;
    if(this->eco_3_dt_hour!=this->iCmd.iSPA.eco_3_dt_hour) same=false;
    if(this->eco_3_dt_min!=this->iCmd.iSPA.eco_3_dt_min) same=false;
    if(this->eco_4_st_hour!=this->iCmd.iSPA.eco_4_st_hour) same=false;
    if(this->eco_4_st_min!=this->iCmd.iSPA.eco_4_st_min) same=false;
    if(this->eco_4_dt_hour!=this->iCmd.iSPA.eco_4_dt_hour) same=false;
    if(this->eco_4_dt_min!=this->iCmd.iSPA.eco_4_dt_min) same=false;
    if(this->eco_1_week!=this->iCmd.iSPA.eco_1_week) same=false;
    if(this->eco_2_week!=this->iCmd.iSPA.eco_2_week) same=false;
    if(this->eco_3_week!=this->iCmd.iSPA.eco_3_week) same=false;
    if(this->eco_4_week!=this->iCmd.iSPA.eco_4_week) same=false;
    //re-send or close or time-out
    if(same==true) {
        //close checking
        SettingCmd_33=false;
        this->Cursor=Cursors::Default; //reset cursor
        MsgLog("EK");
    }
    else {
        if(resend_33<COMMAND_RESEND_TIMES*4) {
            //re-send command 21 from saved copy
            resend_33++;
            buffer[0]=NEW_2015_PROTOCOL_CODE;
            buffer[1]=0x23; //Command  -- Set std filter schedule
            buffer[2]=1; //group
            buffer[3]=std_st_hour;
            buffer[4]=std_st_min;
            buffer[5]=std_dt_hour;
            buffer[6]=std_dt_min;
            buffer[7]=std_week;
            this->iCmd.SendCmdPacket(buffer);
            SetWaitingCmd(0x33);
            //
            buffer[2]=2; //group
            buffer[3]=eco_2_st_hour;
            buffer[4]=eco_2_st_min;
            buffer[5]=eco_2_dt_hour;
            buffer[6]=eco_2_dt_min;
            this->iCmd.SendCmdPacket(buffer);
            buffer[2]=3; //group
            buffer[3]=eco_3_st_hour;
            buffer[4]=eco_3_st_min;
            buffer[5]=eco_3_dt_hour;
            buffer[6]=eco_3_dt_min;
            this->iCmd.SendCmdPacket(buffer);
            buffer[2]=4; //group
            buffer[3]=eco_4_st_hour;
            buffer[4]=eco_4_st_min;
            buffer[5]=eco_4_dt_hour;
            buffer[6]=eco_4_dt_min;
            this->iCmd.SendCmdPacket(buffer);
        }
        else {
            //time-out Error!!!
            SettingCmd_33=false;
            MessageBox::Show(MSG_MAINFORM_ECO_SCH_CMD33_TIMEOUT, "TimeOut",
                MessageBoxButtons::OK,
                MessageBoxIcon::Information);
        }
    }
}

//=================//
// Input Set Temp. //
//=================//
System::Void RDS_main_Form::textBox_Set_T_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
    unsigned int x, y;
    x=Cursor->Position.X;
    y=Cursor->Position.Y+10;
    this->textBox_Set_T->Enabled=false;
    RDS::set_T_form^ formSet_T=gcnew set_T_form(this);
    String^ pureNumber;
    pureNumber=this->textBox_Set_T->Text->Substring(0, this->textBox_Set_T->Text->Length-1);
    formSet_T->SetTempr_Msg=pureNumber;
    formSet_T->SetDesktopLocation(x, y);
    formSet_T->Show();
}

void RDS_main_Form::enable_SetT_area()
{
    this->textBox_Set_T->Enabled=true;
}

System::Void RDS_main_Form::set_textBox_Set_T(String^ InStr)
{
    int inValue=Convert::ToInt32(InStr, 10); //need error handling
    int adc_value;
    if(this->Display_F==true) {
        adc_value=this->iCmd.iSPA.TEMP_F_To_TEMPADC(inValue);
        MsgLog("ST:"+inValue+":F");
    }
    else {
        adc_value=this->iCmd.iSPA.TEMP_C_To_TEMPADC(inValue);
        MsgLog("ST:"+inValue+":C");
    }
    //this->iCmd.iSPA.set_Adc = adc_value; //this line only for testing
    //send command...
    array<unsigned char>^ buffer;
    Array::Resize(buffer, 4);
    buffer[0]=NEW_2015_PROTOCOL_CODE;
    buffer[1]=0x20; //Command  -- Set Temperature ADC
    buffer[2]=(adc_value>>8)&0x000000FF;
    buffer[3]=adc_value&0x000000FF;
    this->iCmd.SendCmdPacket(buffer);
    SetWaitingCmd(0x30);
}

//==================//
// Input Filter Day //
//==================//
System::Void RDS_main_Form::textBox_Filter_Days_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
    unsigned int x, y;
    x=Cursor->Position.X;
    y=Cursor->Position.Y-60;
    this->textBox_Filter_Days->Enabled=false;
    RDS::set_FltDay_form^ formSet_Fday=gcnew set_FltDay_form(this);
    formSet_Fday->SetFltDay_Msg=this->textBox_Filter_Days->Text;
    formSet_Fday->SetDesktopLocation(x, y);
    formSet_Fday->Show();
}

void RDS_main_Form::enable_FltDay_area()
{
    this->textBox_Filter_Days->Enabled=true;
}

System::Void RDS_main_Form::set_textBox_FltDay(String^ InStr)
{
    int inValue=Convert::ToInt32(InStr, 10); //need error handling
    MsgLog("FD:"+inValue);
    //send command...
    array<unsigned char>^ buffer;
    Array::Resize(buffer, 6);
    buffer[0]=NEW_2015_PROTOCOL_CODE;
    buffer[1]=0x24; //Command  -- Set UV & Filter days
    buffer[2]=(this->iCmd.iSPA.uv_days>>8)&0x000000FF;
    buffer[3]=this->iCmd.iSPA.uv_days&0x000000FF;
    buffer[4]=(inValue>>8)&0x000000FF; //set filter days
    buffer[5]=inValue&0x000000FF;
    this->iCmd.SendCmdPacket(buffer);
    SetWaitingCmd(0x34);
}

//==============//
// Input UV Day //
//==============//
System::Void RDS_main_Form::textBox_UV_Days_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
    unsigned int x, y;
    x=Cursor->Position.X;
    y=Cursor->Position.Y-80;
    this->textBox_UV_Days->Enabled=false;
    RDS::set_UVday_form^ formSet_UVday=gcnew set_UVday_form(this);
    formSet_UVday->SetUVday_Msg=textBox_UV_Days->Text;
    formSet_UVday->SetDesktopLocation(x, y);
    formSet_UVday->Show();
}

void RDS_main_Form::enable_UVday_area()
{
    this->textBox_UV_Days->Enabled=true;
}

System::Void RDS_main_Form::set_textBox_UVday(String^ InStr)
{
    int inValue=Convert::ToInt32(InStr, 10); //need error handling
    MsgLog("UD:"+inValue);
    //send command...
    array<unsigned char>^ buffer;
    Array::Resize(buffer, 6);
    buffer[0]=NEW_2015_PROTOCOL_CODE;
    buffer[1]=0x24; //Command  -- Set UV & Filter days
    buffer[2]=(inValue>>8)&0x000000FF; //set UV days
    buffer[3]=inValue&0x000000FF;
    buffer[4]=(this->iCmd.iSPA.filter_days>>8)&0x000000FF;
    buffer[5]=this->iCmd.iSPA.filter_days&0x000000FF;
    this->iCmd.SendCmdPacket(buffer);
    SetWaitingCmd(0x34);
}

//====================//
// Eng-Area buttons   //
//====================//
System::Void RDS_main_Form::button_update_Click(System::Object^  sender, System::EventArgs^  e)
{
    //UpdateUI
    UpdateUI();
}
System::Void RDS_main_Form::button_green_Click(System::Object^  sender, System::EventArgs^  e)
{
    this->iCmd.SendSingleCmdPacket(0x30); //set_T
    UpdateUI();
}

System::Void RDS_main_Form::button_yellow_Click(System::Object^  sender, System::EventArgs^  e)
{
    this->iCmd.SendSingleCmdPacket(0x31); //time
    UpdateUI();
}

System::Void RDS_main_Form::button_red_Click(System::Object^  sender, System::EventArgs^  e)
{
    this->iCmd.SendSingleCmdPacket(0x37); //LOCK
    UpdateUI();
}

System::Void RDS_main_Form::button_blue_Click(System::Object^  sender, System::EventArgs^  e)
{
    this->iCmd.SendSingleCmdPacket(0x38); //ECO
    UpdateUI();
}

//==================//
// Degree F button  //
//==================//
System::Void RDS_main_Form::button_degree_F_Click(System::Object^  sender, System::EventArgs^  e)
{
    Display_F=true;
    this->button_degree_F->Image=Image::FromFile("button_on.png");
    this->button_degree_C->Image=Image::FromFile("button_off.png");
}

//==================//
// Degree C button  //
//==================//
System::Void RDS_main_Form::button_degree_C_Click(System::Object^  sender, System::EventArgs^  e)
{
    Display_F=false;
    this->button_degree_F->Image=Image::FromFile("button_off.png");
    this->button_degree_C->Image=Image::FromFile("button_on.png");
}

//================//
// Pump 1 buttons //
//================//
System::Void RDS_main_Form::button_P1_Hi_Click(System::Object^  sender, System::EventArgs^  e)
{
    if(this->iCmd.iSPA.p1_hi_on==false) {
        this->iCmd.set_p1_hi_ON();
        MsgLog("1H");
    }
    else {
        this->iCmd.set_p1_OFF();
        MsgLog("1F");
    }

    UpdateUI();
}
System::Void RDS_main_Form::button_P1_Lo_Click(System::Object^  sender, System::EventArgs^  e)
{
    if(this->iCmd.iSPA.p1_lo_on==false) {
        this->iCmd.set_p1_lo_ON();
        MsgLog("1L");
    }
    else {
        this->iCmd.set_p1_OFF();
        MsgLog("1F");
    }
    UpdateUI();
}

//================//
// Pump 2 buttons //
//================//
System::Void RDS_main_Form::button_P2_Hi_Click(System::Object^  sender, System::EventArgs^  e)
{
    if(this->iCmd.iSPA.p2_hi_on==false) {
        this->iCmd.set_p2_hi_ON();
        MsgLog("2H");
    }
    else {
        this->iCmd.set_p2_OFF();
        MsgLog("2F");
    }
    UpdateUI();
}
System::Void RDS_main_Form::button_P2_Lo_Click(System::Object^  sender, System::EventArgs^  e)
{
    if(this->iCmd.iSPA.p2_lo_on==false) {
        this->iCmd.set_p2_lo_ON();
        MsgLog("2L");
    }
    else {
        this->iCmd.set_p2_OFF();
        MsgLog("2F");
    }
    UpdateUI();
}

//================//
// Pump 3 buttons //
//================//
System::Void RDS_main_Form::button_P3_Hi_Click(System::Object^  sender, System::EventArgs^  e)
{
    if(this->iCmd.iSPA.p3_hi_on==false) {
        this->iCmd.set_p3_hi_ON();
        MsgLog("3H");
    }
    else {
        this->iCmd.set_p3_OFF();
        MsgLog("3F");
    }
    UpdateUI();
}
System::Void RDS_main_Form::button_P3_Lo_Click(System::Object^  sender, System::EventArgs^  e)
{
    if(this->iCmd.iSPA.p3_lo_on==false) {
        this->iCmd.set_p3_lo_ON();
        MsgLog("3L");
    }
    else {
        this->iCmd.set_p3_OFF();
        MsgLog("3F");
    }
    UpdateUI();
}

//================//
// Blower button  //
//================//
System::Void RDS_main_Form::button_Blower_OnOff_Click(System::Object^  sender, System::EventArgs^  e)
{
    if(this->iCmd.iSPA.blower_on==false) {
        this->iCmd.set_blower_ON();
        MsgLog("B1");
    }
    else {
        this->iCmd.set_blower_OFF();
        MsgLog("B0");
    }
    UpdateUI();
}

//===============//
// Lock buttons  //
//===============//
System::Void RDS_main_Form::button_unlock_Click(System::Object^  sender, System::EventArgs^  e)
{
    this->iCmd.set_unlock();
    MsgLog("UL");
    UpdateUI();
}
System::Void RDS_main_Form::button_T_Lock_Click(System::Object^  sender, System::EventArgs^  e)
{
    this->iCmd.set_Tlock();
    MsgLog("LT");
    UpdateUI();
}
System::Void RDS_main_Form::button_Func_Lock_Click(System::Object^  sender, System::EventArgs^  e)
{
    this->iCmd.set_Slock();
    MsgLog("LS");
    UpdateUI();
}
System::Void RDS_main_Form::button_Pump_Lock_Click(System::Object^  sender, System::EventArgs^  e)
{
    this->iCmd.set_Plock();
    MsgLog("LP");
    UpdateUI();
}
System::Void RDS_main_Form::button_Panel_Lock_Click(System::Object^  sender, System::EventArgs^  e)
{
    this->iCmd.set_Alock();
    MsgLog("LA");
    UpdateUI();
}

//=================//
// Eco Mode button //
//=================//
System::Void RDS_main_Form::button_mode_Click(System::Object^  sender, System::EventArgs^  e)
{
    if(this->iCmd.iSPA.ecoModeOn==true) {
        this->iCmd.set_ECO_OFF(); //if org. is on, then turn off
        this->iCmd.iSPA.ecoModeOn=false;
        MsgLog("E0");
    }
    else {
        this->iCmd.set_ECO_ON();
        this->iCmd.iSPA.ecoModeOn=true;
        MsgLog("E1");
    }
    UpdateUI();
}

//======================//
// Error message button //
//======================//
System::Void RDS_main_Form::button_Err_Msg_Click(System::Object^  sender, System::EventArgs^  e)
{
    if(this->iCmd.iIOTctrl.packet_OK==true&&this->iCmd.received_ValidPacket>2) {
        //connection okay
        //read.. how many record and where is the start point
        MsgLog("EH");
        this->RdEEP_going=true;
        this->lbl_disp_EH_page->Visible=true;

        ///////////////
        this->Read_EEP_1st_page();

        toOpenChildWin=true; //remember we want to open child-win when ready...
        SetWaitingCmd(0x70);
    }
    else {
        //for testing purpose
        this->RdEEP_going=false;//reset all flages
        MessageBox::Show(MSG_MAINFORM_NO_CONNECTION_HINT, "Message",
            MessageBoxButtons::OK,
            MessageBoxIcon::Information);
        openErrHistWin();  //only for test......(to be removed...)
    }
}

System::Void RDS_main_Form::openErrHistWin()
{
    this->lbl_disp_EH_page->Visible=false;
    this->lbl_disp_EH_page->Text="";
    //show to another window............
    this->button_Err_Msg->Enabled=false;
    RDS::EH_Form^ formEH=gcnew EH_Form(this);
    formEH->ECset=this->ECset;
    formEH->Show();
}

void RDS_main_Form::enable_ErrHistory_btn()
{
    this->button_Err_Msg->Enabled=true;
}

//============================//
// Service Hint area related  //
//============================//
void RDS_main_Form::Show_NeedService()
{
    this->lbl_service_0->Text="Need Service call. Press \"Service Call\" button !";
    this->lbl_service_1->Text="";
    this->panel_Service_Hint->Visible=true;
    this->panel_Service_Hint_1->Visible=false;
    this->richTextBox_main_output->Location=Point(RDS_RICHTEXTBOX_LOCATION_2_X, RDS_RICHTEXTBOX_LOCATION_2_Y);
    this->richTextBox_main_output->Size=System::Drawing::Size(RDS_RICHTEXTBOX_LOCATION_2_W, RDS_RICHTEXTBOX_LOCATION_2_H);
}

void RDS_main_Form::Show_ServiceCommited(String^ Service_No)
{
    this->lbl_service_0->Text="Service Call: #"+Service_No;
    this->lbl_service_1->Text="Sumitted. Press and Print \"RDS Report\" for on-site service reference.";
    this->panel_Service_Hint->Visible=true;
    this->panel_Service_Hint_1->Visible=true;
    this->richTextBox_main_output->Location=Point(RDS_RICHTEXTBOX_LOCATION_3_X, RDS_RICHTEXTBOX_LOCATION_3_Y);
    this->richTextBox_main_output->Size=System::Drawing::Size(RDS_RICHTEXTBOX_LOCATION_3_W, RDS_RICHTEXTBOX_LOCATION_3_H);
}

//=====================//
// Service Call button //
//=====================//
System::Void RDS_main_Form::button_Service_Call_Click(System::Object^  sender, System::EventArgs^  e)
{
    String^ OldFileName;
    if(this->RDS_rpt_saved==false&&this->RDS_SCno_produced==false) {
        MsgLog("SC");

        //reading work file belong to current RDS-operator....)
        this->RDS_SC_no=1; //initial...
        this->RPT_getSCno();

        //show message...
        this->Cur_RDSreport_str+="_P"+this->RDS_operator_No+"S"+this->RDS_SC_no;
        Show_ServiceCommited(this->Cur_RDSreport_str);

        //flag
        this->RDS_SCno_produced=true;
    }
    else {
        if(this->RDS_SCno_produced==true) {
            MessageBox::Show(MSG_MAINFORM_SERVICECALL_ALREADY_HAS, "Message",
                MessageBoxButtons::OK,
                MessageBoxIcon::Information);
        }
        else {
            if(this->RDS_rpt_saved==true) {
                //use old Cur_RDSreport_str to delete old report
                this->RPT_delete(this->textBox_UID_in->Text);

                //produce new Cur_RDSreport_str
                this->RDS_SC_no=1; //initial...
                this->RPT_getSCno();
                this->Cur_RDSreport_str+="_P"+this->RDS_operator_No+"S"+this->RDS_SC_no;
                Show_ServiceCommited(this->Cur_RDSreport_str);
                this->RDS_SCno_produced=true;
                MsgLog("SC");

                //generate new report
                this->RPT_save(this->textBox_UID_in->Text);
                this->RDS_rpt_saved=true;
                MsgLog("RS");
            }
        }
    }
}

//=====================//
// RDS report  button  //
//=====================//
System::Void RDS_main_Form::button_RDS_report_Click(System::Object^  sender, System::EventArgs^  e)
{
    //turn-off service-call message
    //this->panel_Service_Hint->Visible = false;
    //this->panel_Service_Hint_1->Visible = false;

    //modify & check the comment area length
    this->richTextBox_comment->Text=this->richTextBox_comment->Text->Replace("\r", "");  //delete CR
    this->richTextBox_comment->Text=this->richTextBox_comment->Text->Replace("\n", "");  //delete LF
    int len=this->richTextBox_comment->TextLength;
    if(this->richTextBox_comment->TextLength>RDS_COMMENT_MAX_CHARS) {
        MessageBox::Show(RDS_COMMENT_LENGTH_ERR_TEXT, "Error",
            MessageBoxButtons::OK,
            MessageBoxIcon::Information);
        return;
    }

    //checking the main condition....
    if(this->Display_initial_OK==false||this->iCmd.iIOTctrl.connect_OK==false||this->iCmd.iIOTctrl.session_Fatal==true) {
        //when UID not connected, Or
        //only when first time service this UID, it must input basic information
        MessageBox::Show(MSG_MAINFORM_NO_CONNECTION_HINT, "Error",
            MessageBoxButtons::OK, MessageBoxIcon::Information);
    }
    else if(this->textBox_owner_in->Text=="") {
        MessageBox::Show(MSG_MAINFORM_RDSREPORT_NO_SPA_OWNER, "Error",
            MessageBoxButtons::OK, MessageBoxIcon::Information);
    }
    else if(this->textBox_spa_serial->Text=="") {
        MessageBox::Show(MSG_MAINFORM_RDSREPORT_NO_SPA_SERIAL, "Error",
            MessageBoxButtons::OK, MessageBoxIcon::Information);
    }
    else if(this->RDS_AD_finish==false&&this->Cannot_AutoD==false) {
        MessageBox::Show(MSG_MAINFORM_RDSREPORT_NO_AUTODIAGNOSIS, "Error",
            MessageBoxButtons::OK, MessageBoxIcon::Information);
    }
    else {  // do report
        if(DEBUGGING_USEAGE==1)MsgMain2("report time :"+this->RDS_rpt_time);
        //2016/0329, add for cannot AD case
        if(this->RDS_AD_finish==false&&this->Cannot_AutoD==true) {
            noneAD_judge_CauseEquip(); //judgement
        }

        //step-1: save report file   (2016/0323, always save again!!)
        //if (this->RDS_rpt_saved == false){
        this->RPT_save(this->textBox_UID_in->Text); //when okay, this will save RDS_save_filename (string)
        this->RDS_rpt_saved=true;
        MsgLog("RS");
        //}

        //Step-2: read file and display to Form.
        open_Full_Report(this->RDS_save_filename);  //MUST be call after report saved (has file name)
    }
}

void RDS_main_Form::open_Full_Report(String^ ReadFileName_in)
{
    MsgLog("RT"); //see & print RDS report in form.
    this->button_RDS_report->Enabled=false;
    RDS::rptDisp^ formRPT=gcnew rptDisp(this); //MUST be call after report saved (has file name)
    formRPT->readFilename=ReadFileName_in;
    formRPT->Show();
}

void RDS_main_Form::enable_Report_btn()
{
    this->button_RDS_report->Enabled=true;
}

//================//
// History button //
//================//
System::Void RDS_main_Form::button_History_Click(System::Object^  sender, System::EventArgs^  e)
{
    //turn-off service-call message
    //this->panel_Service_Hint->Visible = false;
    //this->panel_Service_Hint_1->Visible = false;

    //check UID input area
    if(this->textBox_UID_in->Text=="") {
        MessageBox::Show(MSG_MAINFORM_HISTORY_NO_UID_ERROR, "Error",
            MessageBoxButtons::OK,
            MessageBoxIcon::Information);
        return;
    }

    //check UID length
    if(this->textBox_UID_in->Text->Length!=RDS_UID_WHOLE_LENGTH) {
        MessageBox::Show(MSG_MAINRPT_UID_LENGTH_ERROR, "Error",
            MessageBoxButtons::OK,
            MessageBoxIcon::Information);
        return;
    }

    //open report-history
    open_Report_History();
}

void RDS_main_Form::open_Report_History()
{
    MsgLog("HR");
    this->button_History->Enabled=false;
    RDS::HistoryForm^ formHist=gcnew HistoryForm(this);
    formHist->Base_dir=this->Base_dir;
    formHist->UID=this->textBox_UID_in->Text;
    formHist->Show();
}

void RDS_main_Form::open_Log_History()
{
    MsgLog("HL");
    this->button_History->Enabled=false;
    RDS::HistLogForm^ formHistLog=gcnew HistLogForm(this);
    formHistLog->Base_dir=this->Base_dir;
    formHistLog->UID=this->textBox_UID_in->Text;
    formHistLog->Show();
}

void RDS_main_Form::enable_History_btn()
{
    this->button_History->Enabled=true;
}

//===================//
// My-SC-List button //
//===================//
System::Void RDS_main_Form::button_OSC_list_Click(System::Object^  sender, System::EventArgs^  e)
{
    MsgLog("HL");
    RDS::OpenSCForm^ formOSClist=gcnew OpenSCForm(this);
    formOSClist->Base_dir=this->Base_dir;
    formOSClist->RDS_operator_No=this->RDS_operator_No;
    formOSClist->RDS_operator_name=this->RDS_operator_name;
    //
    this->button_OSC_list->Enabled=false;
    formOSClist->Show();
}

void RDS_main_Form::enable_SClist_btn()
{
    this->button_OSC_list->Enabled=true;
}

//=======================//
// Auto-diagnosis button //
//=======================//
System::Void RDS_main_Form::button_auto_diag_Click(System::Object^  sender, System::EventArgs^  e)
{
    if(this->doing_AutoD==true) {
        //already AD pressed & doing, then can not re-start uring it.
        MsgEngr("press Auto-diagnostic AGAIN !!!");
        return;
    }
    if(this->Cannot_AutoD==true) {
        MsgMain2(MSG_MAINFORM_AD_START_LINE);
        MsgMain2(MSG_MAINFORM_AD_CANNOT_START_TEXT);
        AD_judge_CauseEquip(); //required. for judge starting Errors.
    }
    else if(this->iCmd.iSPA.block_out_cyc_on==true) {
        MsgMain2(MSG_MAINFORM_AD_START_LINE);
        MsgMain2(MSG_BLK_OUT_CYC_AD_CANNOT_START_TEXT);
    }
    else if(this->iCmd.iSPA.clean_cyc_on==true) {
        MsgMain2(MSG_MAINFORM_AD_START_LINE);
        MsgMain2(MSG_CLEAN_CYC_AD_CANNOT_START_TEXT);
    }
    else {
        this->doing_AutoD=true;
        Next_AD_State=S_idel;
        Current_AD_State=S_idel;
        this->AD_wait_count=0;
        MsgMain2(MSG_MAINFORM_AD_START_LINE);
        MsgMain2(MSG_MAINFORM_AD_START_TEXT);
        MsgLog("AD");
        AD_Diagnosis();
        //
    }
    return;
}

//=======================//
// toggle Error code set //
//=======================//
System::Void RDS_main_Form::label_spa_serial_Click(System::Object^  sender, System::EventArgs^  e)
{
    if(this->ECset==0) {
        this->ECset=1;
    }
    else {
        this->ECset=0;
    }
}

//---------------------------------------------------------------------