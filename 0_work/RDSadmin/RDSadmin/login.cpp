//project defines
#include "RDSadmin_project.h"
//
#include "login.h"
#include "DashBrdForm.h"
#include "RDSadminMainForm.h"

using namespace System;
using namespace System::Globalization;
using namespace System::Windows::Forms;
using namespace RDSadmin;
using namespace RDS_NAS;

//-----------------//
// Login form Load //
//-----------------//
System::Void login::login_Load(System::Object^  sender, System::EventArgs^  e)
{
    int rtn;
    String^ tmpPath;
    this->panel_SQ->Visible=false;
    this->label_wrong->Visible=false;
    this->label_Disp_PW->Visible=false;
    this->iNas.HasRDSdir=this->iNas.Check_RDS_dir();
    this->iNas.HasRDS_driver=this->iNas.Check_RDS_driver();
    this->iNas.Default_moodel_file=Application::StartupPath+"\\"+RDS_NAS_SPA_MODEL_FILENAME;
    if(this->iNas.HasRDS_driver==false){
        //No Driver, only can Exit program...  (Only when first time use in Spa company)
        this->button_login->Enabled=false;
        this->button_Forget->Enabled=false;
        MessageBox::Show(LOGIN_DRIVER_DIR_NOT_FOUND, "ERROR",
            MessageBoxButtons::OK,
            MessageBoxIcon::Information);
    }
    else{
        //then check root directory structure, if not exist, then build directory for Spa Company
        String^ OSCpath=RDS_NAS_ROOT_DIR+RDS_NAS_SERVICE_DIR;
        if(Directory::Exists(OSCpath)==false&&this->iNas.HasRDS_driver==true){
            if(File::Exists(this->iNas.Default_moodel_file)==false)
                MessageBox::Show(LOGIN_MODEL_AD_INI_NOT_FOUND, "NOTICE!!",
                MessageBoxButtons::OK,
                MessageBoxIcon::Information);
            this->iNas.Build_All_Dir();
        }

        //check & remin Model_AD.ini
        this->iNas.Has_Model_AD_Ini=this->iNas.Check_Model_AD_Ini();
        if(this->iNas.Has_Model_AD_Ini==false){
            MessageBox::Show(LOGIN_MODEL_AD_INI_NOT_FOUND, "NOTICE",
                MessageBoxButtons::OK,
                MessageBoxIcon::Information);
        }

        //checking Spa company admin setting file
        this->iNas.HasAdminIni=this->iNas.Check_Admin_Ini();
        if(this->iNas.HasAdminIni==false){
            //(Only when first time use in Spa company) -------
            Root_Has_AdminIni=false;
            //use default admin account for Spa Comanpy Admin
            this->iNas.Admin_ID=DEFAULT_ADMIN_LOGIN_ID;
            this->iNas.Admin_PW=DEFAULT_ADMIN_LOGIN_PW;
            this->iNas.Admin_Name=DEFAULT_ADMIN_LOGIN_NAME;
            this->iNas.Admin_AuthLevel=DEFAULT_ADMIN_LOGIN_ALEVEL;
            this->iNas.CompanyCode=DEFAULT_SPA_COM_CODE;
            this->iNas.CompanyName=DEFAULT_SPA_COM_NAME;
            this->iNas.LoginUser_AuthLevel=RDS_NAS_AUTHORITY_LEVEL_0; //only in Login-form need
            MessageBox::Show(LOGIN_SPA_COM_ADMIN_NOT_FOUND, "ERROR",
                MessageBoxButtons::OK,
                MessageBoxIcon::Information);
        }
        else{
            //if admin.ini file exist, -----------------------
            Root_Has_AdminIni=true;
            //reading Admin.ini file.....
            if(-1==this->iNas.Read_Admin_ini()){
                Root_Has_AdminIni=false;
                this->iNas.Admin_ID=DEFAULT_ADMIN_LOGIN_ID;
                this->iNas.Admin_PW=DEFAULT_ADMIN_LOGIN_PW;
                this->iNas.Admin_Name=DEFAULT_ADMIN_LOGIN_NAME;
                this->iNas.Admin_AuthLevel=DEFAULT_ADMIN_LOGIN_ALEVEL;
                this->iNas.CompanyCode=DEFAULT_SPA_COM_CODE;
                this->iNas.CompanyName=DEFAULT_SPA_COM_NAME;
                this->iNas.LoginUser_AuthLevel=RDS_NAS_AUTHORITY_LEVEL_0; //only in Login-form need
                //if fail... (Only when first time use in Spa company)
                MessageBox::Show(LOGIN_SPA_COM_ADMIN_CORRUPTED, "ERROR",
                    MessageBoxButtons::OK, MessageBoxIcon::Information);
                this->iNas.Delete_Admin_ini();
            }
            //check dealers.ini file (just set variable)
            this->iNas.HasDealerIni=this->iNas.Check_Dealer_Ini();

            //checking User.ini file
            this->iNas.HasUsersIni=this->iNas.Check_User_Ini();
            if(this->iNas.HasUsersIni==false){
                this->iNas.Admin_ID=DEFAULT_ADMIN_LOGIN_ID;
                this->iNas.Admin_PW=DEFAULT_ADMIN_LOGIN_PW;
                this->iNas.Admin_Name=DEFAULT_ADMIN_LOGIN_NAME;
                this->iNas.Admin_AuthLevel=DEFAULT_ADMIN_LOGIN_ALEVEL;
                this->iNas.CompanyCode=DEFAULT_SPA_COM_CODE;
                this->iNas.CompanyName=DEFAULT_SPA_COM_NAME;
                this->iNas.LoginUser_AuthLevel=RDS_NAS_AUTHORITY_LEVEL_0; //only in Login-form need
                MessageBox::Show(LOGIN_SPA_COM_USER_NOT_FOUND, "ERROR",
                    MessageBoxButtons::OK, MessageBoxIcon::Information);
            }
            //else{
            //	//both Admin.ini & Users.ini existed......................
            //	//check admin account is also in Users.ini & allowed...
            //	rtn = this->iNas.user_Login(
            //		this->iNas.Admin_ID,
            //		this->iNas.Admin_PW,
            //		0x03	//allow  RDS_NAS_AUTHORITY_LEVEL_0
            //		);		//allow  RDS_NAS_AUTHORITY_LEVEL_1
            //	if (rtn != 0){
            //		MessageBox::Show(LOGIN_ADMIN_USERS_NOT_MATCH, "ERROR",
            //			MessageBoxButtons::OK, MessageBoxIcon::Information);
            //	}
            //} //end if has users.ini
        }// end if has admin.ini
    }//end if has RDS directory

    //remember Root directory admin.ini, the Spa comapny code/name
    this->Spa_Company_Code=this->iNas.CompanyCode;
    this->Spa_Company_Name=this->iNas.CompanyName;

    //Show company information...
    this->textBox_CompanyCode->Text=this->iNas.CompanyCode;
    this->label_ComName->Text=this->iNas.CompanyName;

    //default cursor position
    this->textBox_CompanyCode->Focus(); //also should notice the TabIndex
}

//---------------------//
// CompanyCode_change  //
//---------------------//
System::Void login::textBox_CompanyCode_TextChanged(System::Object^  sender, System::EventArgs^  e)
{
    String^ CompanyCode;
    String^ CompanyName;

    //if dealers.ini not existed, just return
    if(this->iNas.HasDealerIni==false){
        return;
    }

    //get code
    CompanyCode=this->textBox_CompanyCode->Text;

    //check spa company code? (alread read @ form load)
    if(CompanyCode==Spa_Company_Code){
        CompanyName=Spa_Company_Name;
    }
    else{
        //read & check code from dealers.ini
        CompanyName=this->iNas.Get_Dealer_ComName(CompanyCode);
    }
    this->label_ComName->Text=CompanyName;
}

//-----------------//
// Login button    //
//-----------------//
System::Void login::button_login_Click(System::Object^  sender, System::EventArgs^  e)
{
    String^ ComCode;
    String^ TmpComName;
    int rtn;
    //checking Commany Code format
    if(this->textBox_CompanyCode->Text==""){
        MessageBox::Show(LOGIN_COMPANY_CODE_EMPTY, "ERROR",
            MessageBoxButtons::OK,
            MessageBoxIcon::Information);
        this->textBox_CompanyCode->Focus();
        return;
    }
    ComCode=this->textBox_CompanyCode->Text;
    if(iNas.Is_com_code_fmt_OK(ComCode)==false){
        MessageBox::Show(LOGIN_COMPANY_CODE_LENGTH_ERR, "ERROR",
            MessageBoxButtons::OK,
            MessageBoxIcon::Information);
        this->textBox_CompanyCode->Focus();
        return;
    }

    //Parse the Company Code, get the working base directory =============
    if(ComCode==this->Spa_Company_Code){
        //is Spa Company!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        this->iNas.Base_dir=RDS_NAS_ROOT_DIR;
    }
    else{
        //is Dealer? check this code is vaild dealer....
        TmpComName=this->iNas.Get_Dealer_ComName(ComCode);
        if(TmpComName==NO_DEALER_COM_CODE||TmpComName==DEFAULT_SPA_COM_NAME){
            MessageBox::Show(LOGIN_COMPANY_CODE_NOT_VALID, "ERROR",
                MessageBoxButtons::OK,
                MessageBoxIcon::Information);
            this->textBox_CompanyCode->Focus();
            return;
        }
        //is dealer !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        this->iNas.Base_dir=RDS_NAS_ROOT_DIR+ComCode+"\\";
        //check files in Dealer sub-directory
        this->iNas.HasAdminIni=this->iNas.Check_Admin_Ini();
        this->iNas.HasUsersIni=this->iNas.Check_User_Ini();

        //Read admin.ini from Dealer Directory
        if(-1==this->iNas.Read_Admin_ini()){
            this->iNas.Admin_ID=DEFAULT_ADMIN_LOGIN_ID;
            this->iNas.Admin_PW=DEFAULT_ADMIN_LOGIN_PW;
            this->iNas.Admin_Name=DEFAULT_ADMIN_LOGIN_NAME;
            this->iNas.Admin_AuthLevel=DEFAULT_ADMIN_LOGIN_ALEVEL;
            this->iNas.CompanyCode=DEFAULT_SPA_COM_CODE;
            this->iNas.CompanyName=DEFAULT_SPA_COM_NAME;
            this->iNas.LoginUser_AuthLevel=RDS_NAS_AUTHORITY_LEVEL_0; //only in Login-form need
            //if fail... (Only when first time use in Spa company)
            MessageBox::Show(LOGIN_DEALER_ADMIN_CORRUPTED, "ERROR",
                MessageBoxButtons::OK,
                MessageBoxIcon::Information);
        }
    }

    //basic checking for ID & Password inputs.................................
    if(this->textBox_ID->Text==""){
        MessageBox::Show(LOGIN_NO_ACCOUNT_ID_INPUTED, "ERROR",
            MessageBoxButtons::OK,
            MessageBoxIcon::Information);
        this->textBox_ID->Focus();
        return;
    }
    if(this->textBox_PW->Text==""){
        MessageBox::Show(LOGIN_NO_PASSWORD_INPUTED, "ERROR",
            MessageBoxButtons::OK,
            MessageBoxIcon::Information);
        return;
    }

    //chek account ==========================================================
    if(this->iNas.HasUsersIni==true){
        rtn=this->iNas.user_Login(
            this->textBox_ID->Text,
            this->textBox_PW->Text,
            0x03                      //allow  RDS_NAS_AUTHORITY_LEVEL_0
        );                        //allow  RDS_NAS_AUTHORITY_LEVEL_1
    //checking login result
        if(rtn==-1){
            MessageBox::Show(LOGIN_ERR_USERID_NOT_FOUND, "ERROR",
                MessageBoxButtons::OK,
                MessageBoxIcon::Information);
            this->textBox_ID->Text="";
            this->textBox_PW->Text="";
            this->textBox_ID->Focus();
            return;
        }
        else if(rtn==-2){
            MessageBox::Show(LOGIN_ERR_WRONG_PASSWORD, "ERROR",
                MessageBoxButtons::OK,
                MessageBoxIcon::Information);
            this->textBox_PW->Text="";
            this->textBox_PW->Focus();
            return;
        }
        else if(rtn==-3){
            MessageBox::Show(LOGIN_ERR_AUTHERORITY_FAIL, "ERROR",
                MessageBoxButtons::OK,
                MessageBoxIcon::Information);
            this->textBox_ID->Text="";
            this->textBox_PW->Text="";
            this->textBox_ID->Focus();
            return;
        }
        else if(rtn==-4){ //already login in another machine
            MessageBox::Show(LOGIN_ERR_ALREADY_LOGINED, "ERROR",
                MessageBoxButtons::OK,
                MessageBoxIcon::Information);
            this->textBox_ID->Text="";
            this->textBox_PW->Text="";
            this->textBox_ID->Focus();
            return;
        }
        else if(rtn==0){
            //Normal case.....

            //lock person
            String^ TimeString;
            DateTime dt=DateTime::Now;
            TimeString=dt.ToString("yyyyMMdd-HH:mm", DateTimeFormatInfo::InvariantInfo);
            if(0>this->iNas.Lock_Person_Login(this->iNas.LoginUser_no, TimeString)){
                MessageBox::Show(LOGIN_ERR_FILE_EXIST_BEF_LOCK, "ERROR",
                    MessageBoxButtons::OK,
                    MessageBoxIcon::Information);
            }

            //login Okay, open main Form
            //20161012(mark-out), for standard version, delete dashboard function
            //if (ComCode == this->Spa_Company_Code){  //Spa company
            //	RDSadmin::DashBrdForm^ formDash = gcnew DashBrdForm();
            //	formDash->iNas.LoginUser_no = this->iNas.LoginUser_no;
            //	formDash->iNas.LoginUser_ID = this->iNas.LoginUser_ID;
            //	formDash->iNas.LoginUser_AuthLevel = this->iNas.LoginUser_AuthLevel;
            //	formDash->iNas.Base_dir = this->iNas.Base_dir;
            //	formDash->Show();
            //	this->Close();
            //	return;
            //}
            //else{   //Dealer
            RDSadmin::RDSadminMainForm^ formOSClist=gcnew RDSadminMainForm(0);
            formOSClist->iNas.LoginUser_no=this->iNas.LoginUser_no;
            formOSClist->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
            formOSClist->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
            formOSClist->iNas.Base_dir=this->iNas.Base_dir;
            formOSClist->Show();
            this->Close();
            return;
            //}
        }
        else{
            MessageBox::Show(LOGIN_ERR_UNKNOW_RTN_FAIL, "ERROR",
                MessageBoxButtons::OK,
                MessageBoxIcon::Information);
            this->textBox_ID->Text="";
            this->textBox_PW->Text="";
            this->textBox_ID->Focus();
            return;
        }
    }
    else{ //-------------------- if no Usersini (initial case)
        // May has or not has admin.ini
        //     1) maybe formload  already get admin setting
        //     2) maybe companycode .. already read base-directory admin.ini
        // Use admin to login....
        if(this->iNas.Admin_ID==this->textBox_ID->Text &&
            this->iNas.Admin_PW==this->textBox_PW->Text){
            //lgoin as admin, open main Form

            //20161012(mark-out), for standard version, delete dashboard function
            //if (ComCode == this->Spa_Company_Code){  //Spa company
            //	RDSadmin::DashBrdForm^ formDash = gcnew DashBrdForm();
            //	formDash->iNas.LoginUser_no = this->iNas.LoginUser_no;
            //	formDash->iNas.LoginUser_ID = this->iNas.LoginUser_ID;
            //	formDash->iNas.LoginUser_AuthLevel = this->iNas.LoginUser_AuthLevel;
            //	formDash->iNas.Base_dir = this->iNas.Base_dir;
            //	formDash->Show();
            //	this->Close();
            //	return;
            //}
            //else{   //Dealer
            RDSadmin::RDSadminMainForm^ formOSClist=gcnew RDSadminMainForm(0);
            formOSClist->iNas.LoginUser_no=this->iNas.LoginUser_no;
            formOSClist->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
            formOSClist->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
            formOSClist->iNas.Base_dir=this->iNas.Base_dir;
            formOSClist->Show();
            this->Close();
            return;
            //}
        }
        else{
            if(this->iNas.Admin_ID==this->textBox_ID->Text){
                MessageBox::Show(LOGIN_ERR_WRONG_PASSWORD, "ERROR",
                    MessageBoxButtons::OK,
                    MessageBoxIcon::Information);
                this->textBox_PW->Text="";
                this->textBox_PW->Focus();
            }
            else{
                MessageBox::Show(LOGIN_ERR_USERID_NOT_FOUND, "ERROR",
                    MessageBoxButtons::OK,
                    MessageBoxIcon::Information);
                this->textBox_ID->Text="";
                this->textBox_PW->Text="";
                this->textBox_ID->Focus();
                return;
            }
        }
    }
}

//-----------------//
// Exit  button    //
//-----------------//
System::Void login::button_Exit_Click(System::Object^  sender, System::EventArgs^  e)
{
    //unlock person
    int rtn;
    if(this->iNas.LoginUser_no!=0){ //if not the  first-time setting (admin/12345) case...
        rtn=this->iNas.Unlock_Person_Login(this->iNas.LoginUser_no);
        if(rtn<0){
            MessageBox::Show(LOGIN_ERR_FILE_LOSS_BEF_UNLOCK, "ERROR",
                MessageBoxButtons::OK,
                MessageBoxIcon::Information);
        }
    }
    //close login form and exit application (in main.cpp)
    this->Close();
    Application::Exit(); //!!!!!!!!!!!!!!!!!!!
}

//-----------------//
// Forget button   //
//-----------------//
System::Void login::button_Forget_Click(System::Object^  sender, System::EventArgs^  e)
{
    String^ ComCode;
    String^ TmpComName;

    //check Root directory has admin.ini?
    if(this->Root_Has_AdminIni==false){
        MessageBox::Show(LOGIN_FORGET_NO_ROOT_ADMIN_INI, "NOTICE",
            MessageBoxButtons::OK, MessageBoxIcon::Information);
    }
    else{
        //get code input
        ComCode=this->textBox_CompanyCode->Text;

        //company code format..(should always in root directory calling it)
        if(iNas.Is_com_code_fmt_OK(ComCode)==false){
            MessageBox::Show(LOGIN_COMPANY_CODE_LENGTH_ERR, "ERROR",
                MessageBoxButtons::OK,
                MessageBoxIcon::Information);
            this->textBox_CompanyCode->Focus();
            return;
        }

        //Parse the Company Code, get the working base directory =============
        if(ComCode==this->Spa_Company_Code){
            //is Spa Company!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            this->iNas.Base_dir=RDS_NAS_ROOT_DIR;
            //check files in root directory
            this->iNas.HasAdminIni=this->iNas.Check_Admin_Ini();
            this->iNas.HasUsersIni=this->iNas.Check_User_Ini();

            //Read admin.ini from Dealer Directory
            if(-1==this->iNas.Read_Admin_ini()){
                this->iNas.Admin_ID=DEFAULT_ADMIN_LOGIN_ID;
                this->iNas.Admin_PW=DEFAULT_ADMIN_LOGIN_PW;
                this->iNas.Admin_Name=DEFAULT_ADMIN_LOGIN_NAME;
                this->iNas.Admin_AuthLevel=DEFAULT_ADMIN_LOGIN_ALEVEL;
                this->iNas.CompanyCode=DEFAULT_SPA_COM_CODE;
                this->iNas.CompanyName=DEFAULT_SPA_COM_NAME;
                this->iNas.LoginUser_AuthLevel=RDS_NAS_AUTHORITY_LEVEL_0; //only in Login-form need
                //if fail... (Only when first time use in Spa company)
                MessageBox::Show(LOGIN_SPA_COM_ADMIN_CORRUPTED, "ERROR",
                    MessageBoxButtons::OK,
                    MessageBoxIcon::Information);
            }
        }
        else{
            //is Dealer? check this code is vaild dealer....
            TmpComName=this->iNas.Get_Dealer_ComName(ComCode);
            if(TmpComName==NO_DEALER_COM_CODE||TmpComName==DEFAULT_SPA_COM_NAME){
                MessageBox::Show(LOGIN_COMPANY_CODE_NOT_VALID, "ERROR",
                    MessageBoxButtons::OK,
                    MessageBoxIcon::Information);
                this->textBox_CompanyCode->Focus();
                return;
            }
            //is dealer !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            this->iNas.Base_dir=RDS_NAS_ROOT_DIR+ComCode+"\\";
            //check files in Dealer sub-directory
            this->iNas.HasAdminIni=this->iNas.Check_Admin_Ini();
            this->iNas.HasUsersIni=this->iNas.Check_User_Ini();

            //Read admin.ini from Dealer Directory
            if(-1==this->iNas.Read_Admin_ini()){
                this->iNas.Admin_ID=DEFAULT_ADMIN_LOGIN_ID;
                this->iNas.Admin_PW=DEFAULT_ADMIN_LOGIN_PW;
                this->iNas.Admin_Name=DEFAULT_ADMIN_LOGIN_NAME;
                this->iNas.Admin_AuthLevel=DEFAULT_ADMIN_LOGIN_ALEVEL;
                this->iNas.CompanyCode=DEFAULT_SPA_COM_CODE;
                this->iNas.CompanyName=DEFAULT_SPA_COM_NAME;
                this->iNas.LoginUser_AuthLevel=RDS_NAS_AUTHORITY_LEVEL_0; //only in Login-form need
                //if fail... (Only when first time use in Spa company)
                MessageBox::Show(LOGIN_DEALER_ADMIN_CORRUPTED, "ERROR",
                    MessageBoxButtons::OK,
                    MessageBoxIcon::Information);
            }
        } //end if code = Spa company code

        //display Security Questions & Answer area...
        if(this->iNas.Admin_SQ_index==0)
            this->label_SQuestion->Text=SUPERVISOR_SECURITY_QUESTION_1;
        else if(this->iNas.Admin_SQ_index==1)
            this->label_SQuestion->Text=SUPERVISOR_SECURITY_QUESTION_2;
        else if(this->iNas.Admin_SQ_index==2)
            this->label_SQuestion->Text=SUPERVISOR_SECURITY_QUESTION_3;
        else
            this->label_SQuestion->Text=SUPERVISOR_SECURITY_QUESTION_4;
        //UI
        this->panel_SQ->Visible=true;
        this->button_login->Enabled=false;
    } //end if Root directory has admin.ini
}

//-----------------//
// Answer button   //
//-----------------//
System::Void login::button_EnterAns_Click(System::Object^  sender, System::EventArgs^  e)
{
    if(this->textBox_answer->Text==""){
        MessageBox::Show(LOGIN_COMPANY_SQ_ANSWER_EMPTY, "ERROR",
            MessageBoxButtons::OK,
            MessageBoxIcon::Information);
    }
    else{
        //checking answer...........
        if(this->textBox_answer->Text==this->iNas.Admin_SQanswer){
            //correct
            this->textBox_ID->Text=this->iNas.Admin_ID;
            this->label_Disp_PW->Visible=true;
            this->label_Disp_PW->Text=this->iNas.Admin_PW;

            //back to root directiry Spa Company!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            this->iNas.Base_dir=RDS_NAS_ROOT_DIR;
            //check files in root directory
            this->iNas.HasAdminIni=this->iNas.Check_Admin_Ini();
            this->iNas.HasUsersIni=this->iNas.Check_User_Ini();

            //Read admin.ini from Dealer Directory
            if(-1==this->iNas.Read_Admin_ini()){
                this->iNas.Admin_ID=DEFAULT_ADMIN_LOGIN_ID;
                this->iNas.Admin_PW=DEFAULT_ADMIN_LOGIN_PW;
                this->iNas.Admin_Name=DEFAULT_ADMIN_LOGIN_NAME;
                this->iNas.Admin_AuthLevel=DEFAULT_ADMIN_LOGIN_ALEVEL;
                this->iNas.CompanyCode=DEFAULT_SPA_COM_CODE;
                this->iNas.CompanyName=DEFAULT_SPA_COM_NAME;
                this->iNas.LoginUser_AuthLevel=RDS_NAS_AUTHORITY_LEVEL_0; //only in Login-form need
                //if fail... (Only when first time use in Spa company)
                MessageBox::Show(LOGIN_SPA_COM_ADMIN_CORRUPTED, "ERROR",
                    MessageBoxButtons::OK,
                    MessageBoxIcon::Information);
            }
            //UI
            this->label_wrong->Visible=false;
            this->panel_SQ->Visible=false;
            this->button_login->Enabled=true;
        }
        else{
            //incorrect
            this->textBox_answer->Text="";
            this->label_wrong->Visible=true;
        }
    }
}