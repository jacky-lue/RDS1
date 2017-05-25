//project defines
#include "RDSadmin_project.h"
//
#include "DashBrdForm.h"
#include "RDSadminMainForm.h"
#include "nas_state.h"
#include "SupervisorForm.h"
#include "UserList_Form.h"
#include "AddUserForm.h"
#include "DealerListForm.h"

using namespace System;
using namespace System::Globalization;
using namespace System::Windows::Forms;
using namespace RDSadmin;
using namespace RDS_NAS;

System::Void AddUserForm::AddUserForm_Load(System::Object^  sender, System::EventArgs^  e)
{
    //check file...
    this->iNas.HasAdminIni=this->iNas.Check_Admin_Ini();
    this->iNas.HasUsersIni=this->iNas.Check_User_Ini();
    if(this->iNas.HasAdminIni==false){
        this->iNas.CompanyCode=DEFAULT_SPA_COM_CODE;
        this->iNas.CompanyName=DEFAULT_SPA_COM_NAME;
    }
    else{
        //reading......
        if(-1==this->iNas.Read_Admin_ini()){
            this->iNas.CompanyCode=DEFAULT_SPA_COM_CODE;
            this->iNas.CompanyName=DEFAULT_SPA_COM_NAME;
            MessageBox::Show(FORM_LOAD_ADMIN_CORRUPTED, "ERROR",
                MessageBoxButtons::OK,
                MessageBoxIcon::Information);
        }
    }
    //show UI
    this->label_LoginID->Text=this->iNas.LoginUser_ID;
    this->label_LoginAuthorLv->Text=this->iNas.LoginUser_AuthLevel;

    //display company code
    this->label_ComCode_Show->Text=this->iNas.CompanyCode;
    this->label_ComName_show->Text=this->iNas.CompanyName;

    //Hide Buttons by authority_level
    if(this->iNas.LoginUser_AuthLevel!=RDS_NAS_AUTHORITY_LEVEL_0){
        this->button_Save->Enabled=false;
        this->button_Save->Visible=false;
        //
        this->button_Supervisor->Visible=false;
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
System::Void AddUserForm::button_DashBoard_Click(System::Object^  sender, System::EventArgs^  e)
{
    RDSadmin::DashBrdForm^ formDash=gcnew DashBrdForm();
    formDash->iNas.LoginUser_no=this->iNas.LoginUser_no;
    formDash->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
    formDash->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
    formDash->iNas.Base_dir=this->iNas.Base_dir;
    formDash->Show();
    this->Close();
}

System::Void AddUserForm::button_ServiceCall_Click(System::Object^  sender, System::EventArgs^  e)
{
    RDSadmin::RDSadminMainForm^ formRDSmain=gcnew RDSadminMainForm(0);
    formRDSmain->iNas.LoginUser_no=this->iNas.LoginUser_no;
    formRDSmain->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
    formRDSmain->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
    formRDSmain->iNas.Base_dir=this->iNas.Base_dir;
    formRDSmain->Show();
    this->Close();
}

System::Void AddUserForm::button_Supervisor_Click(System::Object^  sender, System::EventArgs^  e)
{
    RDSadmin::SupervisorForm^ formSuper=gcnew SupervisorForm();
    formSuper->iNas.LoginUser_no=this->iNas.LoginUser_no;
    formSuper->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
    formSuper->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
    formSuper->iNas.Base_dir=this->iNas.Base_dir;
    formSuper->Show();
    this->Close();
}

System::Void AddUserForm::button_RDSuser_Click(System::Object^  sender, System::EventArgs^  e)
{
    RDSadmin::UserList_Form^ formUser=gcnew UserList_Form();
    formUser->iNas.LoginUser_no=this->iNas.LoginUser_no;
    formUser->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
    formUser->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
    formUser->iNas.Base_dir=this->iNas.Base_dir;
    formUser->Show();
    this->Close();
}

System::Void AddUserForm::button_Dealer_Click(System::Object^  sender, System::EventArgs^  e)
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
// Other buttons  //
//----------------//
System::Void AddUserForm::button_Save_Click(System::Object^  sender, System::EventArgs^  e)
{
    Boolean chk=true;
    int rtn;
    //checking name field
    if(this->textBox_Name->Text==""||this->textBox_Name->Text==DEFAULT_ADMIN_LOGIN_NAME){
        chk=false;
        MessageBox::Show(ADD_USER_NAME_FIELD_IS_EMPTY, "ERROR",
            MessageBoxButtons::OK,
            MessageBoxIcon::Information);
        return;
    }
    //checking ID field
    if(this->textBox_ID->Text==""){
        chk=false;
        MessageBox::Show(ADD_USER_ID_FIELD_IS_EMPTY, "ERROR",
            MessageBoxButtons::OK,
            MessageBoxIcon::Information);
        return;
    }
    //checking PW field
    if(this->textBox_PW->Text==""){
        chk=false;
        MessageBox::Show(ADD_USER_PW_FIELD_IS_EMPTY, "ERROR",
            MessageBoxButtons::OK,
            MessageBoxIcon::Information);
        return;
    }
    //checking Authority field
    if(this->comboBox_ALevel->Text!=RDS_NAS_AUTHORITY_LEVEL_1 &&
        this->comboBox_ALevel->Text!=RDS_NAS_AUTHORITY_LEVEL_2 &&
        this->comboBox_ALevel->Text!=RDS_NAS_AUTHORITY_LEVEL_3)
    {
        chk=false;
        MessageBox::Show(ADD_USER_AUTHORITY_IS_WRONG, "ERROR",
            MessageBoxButtons::OK,
            MessageBoxIcon::Information);
        return;
    }
    //do write file.... by main form ------------------------------
    if(chk==true){
        user_Name=this->textBox_Name->Text;
        user_ID=this->textBox_ID->Text;
        user_PW=this->textBox_PW->Text;
        user_AuthLevel=this->comboBox_ALevel->Text;
        rtn=this->iNas.Add_Users_Ini(
            user_ID,
            user_Name,
            user_PW,
            user_AuthLevel
        );
        //check it sucessful or not
        if(rtn==0) {
            MessageBox::Show(ADD_USER_SAVE_NEW_USER_OKAY, "OK",
                MessageBoxButtons::OK,
                MessageBoxIcon::Information);
            RDSadmin::UserList_Form^ formUser=gcnew UserList_Form();
            formUser->iNas.LoginUser_no=this->iNas.LoginUser_no;
            formUser->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
            formUser->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
            formUser->iNas.Base_dir=this->iNas.Base_dir;
            formUser->Show();
            this->Close();
            return;
        }
        else{
            //rtn == -1
            //show messagebox....
            MessageBox::Show(ADD_USER_SAVE_FAILE_SAME_ID, "ERROR",
                MessageBoxButtons::OK,
                MessageBoxIcon::Information);
            return;
        }
    }
}