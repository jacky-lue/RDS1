//project defines
#include "RDSadmin_project.h"
//
#include "DashBrdForm.h"
#include "RDSadminMainForm.h"
#include "nas_state.h"
#include "SupervisorForm.h"
#include "UserList_Form.h"
#include "DealerListForm.h"

using namespace System;
using namespace System::Globalization;
using namespace System::Windows::Forms;
using namespace RDSadmin;
using namespace RDS_NAS;

//====================//
//  Form Load !!!     //
//====================//
System::Void SupervisorForm::SupervisorForm_Load(System::Object^  sender, System::EventArgs^  e)
{
    //check file again...
    this->iNas.HasAdminIni=this->iNas.Check_Admin_Ini();
    this->iNas.HasUsersIni=this->iNas.Check_User_Ini();
    if(this->iNas.HasAdminIni==false||this->iNas.HasUsersIni==false){
        this->iNas.Admin_ID=DEFAULT_ADMIN_LOGIN_ID;
        this->iNas.Admin_PW=DEFAULT_ADMIN_LOGIN_PW;
        this->iNas.Admin_Name=DEFAULT_ADMIN_LOGIN_NAME;
        this->iNas.Admin_AuthLevel=DEFAULT_ADMIN_LOGIN_ALEVEL;
        this->iNas.CompanyCode=DEFAULT_SPA_COM_CODE;
        this->iNas.CompanyName=DEFAULT_SPA_COM_NAME;
        this->iNas.Admin_SQ_index=DEFAULT_ADMIN_SQ_INDEX;
        this->iNas.Admin_SQanswer=DEFAULT_ADMIN_SQ_ANSWER;
    }
    else{
        //reading......and hcek admin.ini file
        if(-1==this->iNas.Read_Admin_ini()){
            this->iNas.Admin_ID=DEFAULT_ADMIN_LOGIN_ID;
            this->iNas.Admin_PW=DEFAULT_ADMIN_LOGIN_PW;
            this->iNas.Admin_Name=DEFAULT_ADMIN_LOGIN_NAME;
            this->iNas.Admin_AuthLevel=DEFAULT_ADMIN_LOGIN_ALEVEL;
            this->iNas.CompanyCode=DEFAULT_SPA_COM_CODE;
            this->iNas.CompanyName=DEFAULT_SPA_COM_NAME;
            this->iNas.Admin_SQ_index=DEFAULT_ADMIN_SQ_INDEX;
            this->iNas.Admin_SQanswer=DEFAULT_ADMIN_SQ_ANSWER;
            MessageBox::Show(FORM_LOAD_ADMIN_CORRUPTED, "ERROR",
                MessageBoxButtons::OK,
                MessageBoxIcon::Information);
        }
    }

    //initial SQ
    this->comboBox_SQ->Items->Clear();
    this->comboBox_SQ->Items->Add(SUPERVISOR_SECURITY_QUESTION_1);
    this->comboBox_SQ->Items->Add(SUPERVISOR_SECURITY_QUESTION_2);
    this->comboBox_SQ->Items->Add(SUPERVISOR_SECURITY_QUESTION_3);
    this->comboBox_SQ->Items->Add(SUPERVISOR_SECURITY_QUESTION_4);

    //show UI
    this->label_LoginID->Text=this->iNas.LoginUser_ID;
    this->label_LoginAuthorLv->Text=this->iNas.LoginUser_AuthLevel;
    //
    this->textBox_CompanyCode->Text=this->iNas.CompanyCode;
    this->textBox_CompanyName->Text=this->iNas.CompanyName;
    //
    this->textBox_CompanyCode->BackColor=Color::LightYellow;
    this->textBox_CompanyName->BackColor=Color::LightYellow;
    this->textBox_CompanyCode->Enabled=false;
    this->textBox_CompanyName->Enabled=false;
    //
    this->label_AuthLvCode->Text=this->iNas.Admin_AuthLevel;
    this->textBox_ID->Text=this->iNas.Admin_ID;
    this->textBox_PW->Text=this->iNas.Admin_PW;
    this->textBox_Name->Text=this->iNas.Admin_Name;
    this->comboBox_SQ->SelectedIndex=this->iNas.Admin_SQ_index;
    this->textBox_answer->Text=this->iNas.Admin_SQanswer;
    this->textBox_Name->BackColor=Color::LightYellow;
    this->textBox_ID->BackColor=Color::LightYellow;
    this->textBox_PW->BackColor=Color::LightYellow;
    this->textBox_PW2->BackColor=Color::LightYellow;
    this->comboBox_SQ->BackColor=Color::LightYellow;
    this->textBox_answer->BackColor=Color::LightYellow;
    this->textBox_Name->Enabled=false;
    this->textBox_ID->Enabled=false;
    this->textBox_PW->Enabled=false;
    this->textBox_PW2->Enabled=false;
    this->comboBox_SQ->Enabled=false;
    this->textBox_answer->Enabled=false;

    //Hide Buttons by authority_level
    if(this->iNas.LoginUser_AuthLevel!=RDS_NAS_AUTHORITY_LEVEL_0){
        this->button_Edit->Enabled=false;
        this->button_Save->Enabled=false;
        this->button_Edit->Visible=false;
        this->button_Save->Visible=false;
        //
        this->button_Supervisor->Visible=false;
        //
        this->label_ID->Visible=false;
        this->label_PW->Visible=false;
        this->label_PW2->Visible=false;
        this->label_SecurityQ->Visible=false;
        this->label_answer->Visible=false;
        this->label_ID->Visible=false;
        this->textBox_ID->Visible=false;
        this->textBox_PW->Visible=false;
        this->textBox_PW2->Visible=false;
        this->comboBox_SQ->Visible=false;
        this->textBox_answer->Visible=false;
    }

    //hide menu buttons when not root Spa Company
    if(this->iNas.Base_dir!=RDS_NAS_ROOT_DIR){
        this->button_Dealer->Visible=false;
        this->button_DashBoard->Visible=false;
    }
}

//----------------//
//  Menu buttons  //
//----------------//
System::Void SupervisorForm::button_DashBoard_Click(System::Object^  sender, System::EventArgs^  e)
{
    RDSadmin::DashBrdForm^ formDash=gcnew DashBrdForm();
    formDash->iNas.LoginUser_no=this->iNas.LoginUser_no;
    formDash->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
    formDash->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
    formDash->iNas.Base_dir=this->iNas.Base_dir;
    formDash->Show();
    this->Close();
}

System::Void SupervisorForm::button_ServiceCall_Click(System::Object^  sender, System::EventArgs^  e)
{
    RDSadmin::RDSadminMainForm^ formRDSmain=gcnew RDSadminMainForm(0);
    formRDSmain->iNas.LoginUser_no=this->iNas.LoginUser_no;
    formRDSmain->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
    formRDSmain->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
    formRDSmain->iNas.Base_dir=this->iNas.Base_dir;
    formRDSmain->Show();
    this->Close();
}

System::Void SupervisorForm::button_RDSuser_Click(System::Object^  sender, System::EventArgs^  e)
{
    RDSadmin::UserList_Form^ formUser=gcnew UserList_Form();
    formUser->iNas.LoginUser_no=this->iNas.LoginUser_no;
    formUser->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
    formUser->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
    formUser->iNas.Base_dir=this->iNas.Base_dir;
    formUser->Show();
    this->Close();
}

System::Void SupervisorForm::button_Dealer_Click(System::Object^  sender, System::EventArgs^  e)
{
    RDSadmin::DealerListForm^ formDealer=gcnew DealerListForm();
    formDealer->iNas.LoginUser_no=this->iNas.LoginUser_no;
    formDealer->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
    formDealer->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
    formDealer->iNas.Base_dir=this->iNas.Base_dir;
    formDealer->Show();
    this->Close();
}

//------------------//
//  Edit Supervisor //
//------------------//
System::Void SupervisorForm::button_Edit_Click(System::Object^  sender, System::EventArgs^  e)
{
    //
    this->textBox_CompanyCode->BackColor=Color::LightYellow;
    this->textBox_CompanyName->BackColor=Color::White;
    this->textBox_CompanyCode->Enabled=false; //2016.11.10, since CompanyCode==sub-Dir_Name, so dont let user change!
    this->textBox_CompanyName->Enabled=true;
    //
    this->textBox_Name->BackColor=Color::White;
    this->textBox_ID->BackColor=Color::White;
    this->textBox_PW->BackColor=Color::White;
    this->textBox_PW2->BackColor=Color::White;
    this->comboBox_SQ->BackColor=Color::White;
    this->textBox_answer->BackColor=Color::White;
    this->textBox_Name->Enabled=true;
    this->textBox_ID->Enabled=true;
    this->textBox_PW->Enabled=true;
    this->textBox_PW2->Enabled=true;
    this->comboBox_SQ->Enabled=true;
    this->textBox_answer->Enabled=true;
    //
    this->button_Save->Enabled=true;
    this->button_Edit->Image=Image::FromFile("button_on.png");
}

//------------------//
//  Save Supervisor //
//------------------//
System::Void SupervisorForm::button_Save_Click(System::Object^  sender, System::EventArgs^  e)
{
    Boolean chk=true;
    String^ Admin_ID;
    String^ Admin_Name;
    String^ Admin_PW;
    String^ Admin_AuthLevel;
    unsigned int Admin_SQ_index;
    String^ Admin_SQanswer;
    String^ CompanyCode;
    String^ CompanyName;
    int rtn;

    //check comapny code
    if(this->textBox_CompanyCode->Text==""){
        chk=false;
        MessageBox::Show(SUPERVISOR_SAVE_COM_CODE_EMPTY, "ERROR",
            MessageBoxButtons::OK,
            MessageBoxIcon::Information);
        return;
    }
    if(this->iNas.Is_com_code_fmt_OK(this->textBox_CompanyCode->Text)==false){
        chk=false;
        MessageBox::Show(SUPERVISOR_SAVE_COM_CODE_FAIL, "ERROR",
            MessageBoxButtons::OK,
            MessageBoxIcon::Information);
        return;
    }

    //checking company Name field
    if(this->textBox_CompanyName->Text==""
        ||this->textBox_CompanyName->Text==DEFAULT_SPA_COM_NAME){
        chk=false;
        MessageBox::Show(SUPERVISOR_SAVE_NO_COMPANY_NAME, "ERROR",
            MessageBoxButtons::OK,
            MessageBoxIcon::Information);
        return;
    }

    //checking name field (& company Name)
    if(this->textBox_Name->Text==""||this->textBox_Name->Text==DEFAULT_ADMIN_LOGIN_NAME){
        chk=false;
        MessageBox::Show(SUPERVISOR_SAVE_NAME_EMPTY, "ERROR",
            MessageBoxButtons::OK,
            MessageBoxIcon::Information);
        return;
    }

    //check ID field
    if(this->textBox_ID->Text==""){
        chk=false;
        MessageBox::Show(SUPERVISOR_SAVE_ID_EMPTY, "ERROR",
            MessageBoxButtons::OK,
            MessageBoxIcon::Information);
        return;
    }

    //checking PW & PW2
    if(this->textBox_PW->Text=="") {
        chk=false;
        MessageBox::Show(SUPERVISOR_SAVE_PW_EMPTY, "ERROR",
            MessageBoxButtons::OK,
            MessageBoxIcon::Information);
        return;
    }
    if(this->textBox_PW->Text!=this->textBox_PW2->Text) {
        chk=false;
        //show an message box...
        MessageBox::Show(SUPERVISOR_SAVE_PW_NOT_MATCH, "ERROR",
            MessageBoxButtons::OK,
            MessageBoxIcon::Information);
        return;
    }

    //checking if security question not set...
    if(this->textBox_answer->Text==""||this->comboBox_SQ->SelectedIndex<0){
        chk=false;
        MessageBox::Show(SUPERVISOR_SAVE_SQ_NOT_SETED, "ERROR",
            MessageBoxButtons::OK,
            MessageBoxIcon::Information);
        return;
    }

    //if overwrite... should remind...
    if(this->iNas.HasAdminIni==true){
        System::Windows::Forms::DialogResult result;
        result=MessageBox::Show(
            SUPERVISOR_SAVE_ADMIN_OVERWRITE, "NOTICE",
            MessageBoxButtons::YesNo,
            MessageBoxIcon::Question,
            MessageBoxDefaultButton::Button1,
            MessageBoxOptions::RightAlign);
        if(result!=::DialogResult::Yes){
            chk=false;
            return;
        }
    }

    //do write file.... by iNas object
    if(chk==true){
        Admin_Name=this->textBox_Name->Text;
        Admin_ID=this->textBox_ID->Text;
        Admin_PW=this->textBox_PW->Text;
        Admin_AuthLevel=this->label_AuthLvCode->Text;
        Admin_SQ_index=this->comboBox_SQ->SelectedIndex;
        Admin_SQanswer=this->textBox_answer->Text;
        CompanyCode=this->textBox_CompanyCode->Text;
        CompanyName=this->textBox_CompanyName->Text;

        if(this->iNas.HasAdminIni==true){
            //overwrite admin case
            //(1)overwrite admin.ini
            this->iNas.Delete_Admin_ini();
            this->iNas.Write_Admin_Ini(
                Admin_ID, Admin_Name, Admin_PW, Admin_AuthLevel, Admin_SQ_index, Admin_SQanswer,
                CompanyCode, CompanyName);
            //(2)overwrite admin in users.ini
            this->iNas.Overwrite_Admin_inUsers(Admin_ID, Admin_Name, Admin_PW, Admin_AuthLevel);
        }
        else{
            //first time case, initial it and made lock file
            this->iNas.Write_Admin_Ini(
                Admin_ID, Admin_Name, Admin_PW, Admin_AuthLevel, Admin_SQ_index, Admin_SQanswer,
                CompanyCode, CompanyName);

            //made it logined ...
            this->iNas.LoginUser_no=1;
            this->iNas.LoginUser_ID=Admin_ID;
            this->iNas.LoginUser_AuthLevel=Admin_AuthLevel;
            //nad lock person
            String^ TimeString;
            DateTime dt=DateTime::Now;
            TimeString=dt.ToString("yyyyMMdd-HH:mm", DateTimeFormatInfo::InvariantInfo);
            if(0>this->iNas.Lock_Person_Login(this->iNas.LoginUser_no, TimeString)){
                MessageBox::Show(LOGIN_ERR_FILE_EXIST_BEF_LOCK, "ERROR",
                    MessageBoxButtons::OK, MessageBoxIcon::Information);
            }

            //initial user.ini
            rtn=this->iNas.Add_Users_Ini(Admin_ID, Admin_Name, Admin_PW, Admin_AuthLevel);
            if(rtn==0) {
                MessageBox::Show(SUPERVISOR_SAVE_MODIFY_OKAY, "OK",
                    MessageBoxButtons::OK,
                    MessageBoxIcon::Information);
            }
            else{
                //error....
                MessageBox::Show(SUPERVISOR_SAVE_USERINI_WARNING, "WARNING",
                    MessageBoxButtons::OK,
                    MessageBoxIcon::Warning);
            }
        }

        //restore original UI.
        this->textBox_CompanyCode->BackColor=Color::LightYellow;
        this->textBox_CompanyName->BackColor=Color::LightYellow;
        this->textBox_CompanyCode->Enabled=false;
        this->textBox_CompanyName->Enabled=false;
        //
        this->textBox_Name->BackColor=Color::LightYellow;
        this->textBox_ID->BackColor=Color::LightYellow;
        this->textBox_PW->BackColor=Color::LightYellow;
        this->textBox_PW2->BackColor=Color::LightYellow;
        this->comboBox_SQ->BackColor=Color::LightYellow;
        this->textBox_answer->BackColor=Color::LightYellow;
        this->textBox_Name->Enabled=false;
        this->textBox_ID->Enabled=false;
        this->textBox_PW->Enabled=false;
        this->textBox_PW2->Enabled=false;
        this->comboBox_SQ->Enabled=false;
        this->textBox_answer->Enabled=false;
        //
        this->button_Save->Enabled=false;
        this->button_Edit->Image=nullptr;
    }//--------------end of do write file
}