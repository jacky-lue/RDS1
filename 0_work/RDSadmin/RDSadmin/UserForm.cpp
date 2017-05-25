//project defines
#include "RDSadmin_project.h"
//
#include "DashBrdForm.h"
#include "RDSadminMainForm.h"
#include "nas_state.h"
#include "SupervisorForm.h"
#include "UserList_Form.h"
#include "UserForm.h"
#include "DealerListForm.h"

using namespace System;
using namespace System::Globalization;
using namespace System::Windows::Forms;
using namespace RDSadmin;
using namespace RDS_NAS;

//====================//
//  Form Load !!!     //
//====================//
System::Void UserForm::UserForm_Load(System::Object^  sender, System::EventArgs^  e)
{
    //check files
    this->iNas.HasAdminIni=this->iNas.Check_Admin_Ini();
    this->iNas.HasUsersIni=this->iNas.Check_User_Ini();
    //
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
        //buttons
        this->button_Edit->Enabled=false;
        this->button_Save->Enabled=false;
        this->button_Edit->Visible=false;
        this->button_Save->Visible=false;
        //
        this->button_Supervisor->Visible=false;
        //
        this->label_ID->Visible=false;
        this->label_PW->Visible=false;
        this->label_ID->Visible=false;
        this->textBox_ID->Visible=false;
        this->textBox_PW->Visible=false;
    }

    //hide menu buttons when not root Spa Company
    if(this->iNas.Base_dir!=RDS_NAS_ROOT_DIR){
        this->button_Dealer->Visible=false;
        this->button_DashBoard->Visible=false;
    }

    //use iNas.current_user_no to show detail information
    int rtn, number;
    rtn=this->iNas.Get_User_Info();
    if(rtn==0){ //OK
        this->textBox_Name->Text=this->iNas.user_Name;
        this->textBox_ID->Text=this->iNas.user_ID;
        this->textBox_PW->Text=this->iNas.user_PW;
        if(this->iNas.user_AuthLevel==RDS_NAS_AUTHORITY_LEVEL_1)this->comboBox_ALevel->SelectedIndex=0;
        else if(this->iNas.user_AuthLevel==RDS_NAS_AUTHORITY_LEVEL_2)this->comboBox_ALevel->SelectedIndex=1;
        else if(this->iNas.user_AuthLevel==RDS_NAS_AUTHORITY_LEVEL_3)this->comboBox_ALevel->SelectedIndex=2;
        else {
            this->comboBox_ALevel->SelectedIndex=1;
            MessageBox::Show(USER_FORM_AUTHORITY_IS_WRONG, "ERROR",
                MessageBoxButtons::OK,
                MessageBoxIcon::Information);
        }
        this->comboBox_ALevel->BackColor=Color::LightYellow;
        this->textBox_Name->BackColor=Color::LightYellow;
        this->textBox_ID->BackColor=Color::LightYellow;
        this->textBox_PW->BackColor=Color::LightYellow;
        this->comboBox_ALevel->Enabled=false;
        this->textBox_Name->Enabled=false;
        this->textBox_ID->Enabled=false;
        this->textBox_PW->Enabled=false;
        number=this->iNas.current_user_no+1;
        this->label_Title->Text="User Account #"+number;
    }
}

//----------------//
//  Menu buttons  //
//----------------//
System::Void UserForm::button_DashBoard_Click(System::Object^  sender, System::EventArgs^  e)
{
    RDSadmin::DashBrdForm^ formDash=gcnew DashBrdForm();
    formDash->iNas.LoginUser_no=this->iNas.LoginUser_no;
    formDash->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
    formDash->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
    formDash->iNas.Base_dir=this->iNas.Base_dir;
    formDash->Show();
    this->Close();
}

System::Void UserForm::button_ServiceCall_Click(System::Object^  sender, System::EventArgs^  e)
{
    RDSadmin::RDSadminMainForm^ formRDSmain=gcnew RDSadminMainForm(0);
    formRDSmain->iNas.LoginUser_no=this->iNas.LoginUser_no;
    formRDSmain->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
    formRDSmain->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
    formRDSmain->iNas.Base_dir=this->iNas.Base_dir;
    formRDSmain->Show();
    this->Close();
}

System::Void UserForm::button_Supervisor_Click(System::Object^  sender, System::EventArgs^  e)
{
    RDSadmin::SupervisorForm^ formSuper=gcnew SupervisorForm();
    formSuper->iNas.LoginUser_no=this->iNas.LoginUser_no;
    formSuper->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
    formSuper->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
    formSuper->iNas.Base_dir=this->iNas.Base_dir;
    formSuper->Show();
    this->Close();
}

System::Void UserForm::button_RDSuser_Click(System::Object^  sender, System::EventArgs^  e)
{
    RDSadmin::UserList_Form^ formUser=gcnew UserList_Form();
    formUser->iNas.LoginUser_no=this->iNas.LoginUser_no;
    formUser->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
    formUser->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
    formUser->iNas.Base_dir=this->iNas.Base_dir;
    formUser->Show();
    this->Close();
}

System::Void UserForm::button_Dealer_Click(System::Object^  sender, System::EventArgs^  e)
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
// other buttons  //
//----------------//
System::Void UserForm::button_Edit_Click(System::Object^  sender, System::EventArgs^  e)
{
    this->comboBox_ALevel->BackColor=Color::White;
    this->textBox_Name->BackColor=Color::White;
    this->textBox_ID->BackColor=Color::White;
    this->textBox_PW->BackColor=Color::White;
    this->comboBox_ALevel->Enabled=true;
    this->textBox_Name->Enabled=true;
    this->textBox_ID->Enabled=true;
    this->textBox_PW->Enabled=true;
    //
    this->button_Save->Enabled=true;
    this->button_Edit->Image=Image::FromFile("button_on.png");
}

System::Void UserForm::button_Save_Click(System::Object^  sender, System::EventArgs^  e)
{
    Boolean chk=true;
    String^ user_ID;
    String^ user_Name;
    String^ user_PW;
    String^ user_AuthLevel;

    //checking name field
    if(this->textBox_Name->Text==""||this->textBox_Name->Text==DEFAULT_ADMIN_LOGIN_NAME){
        chk=false;
        MessageBox::Show(USER_SAVE_NAME_FIELD_IS_EMPTY, "ERROR",
            MessageBoxButtons::OK,
            MessageBoxIcon::Information);
        return;
    }
    //checking ID field
    if(this->textBox_ID->Text==""){
        chk=false;
        MessageBox::Show(USER_SAVE_ID_FIELD_IS_EMPTY, "ERROR",
            MessageBoxButtons::OK,
            MessageBoxIcon::Information);
        return;
    }
    //checking PW field
    if(this->textBox_PW->Text==""){
        chk=false;
        MessageBox::Show(USER_SAVE_PW_FIELD_IS_EMPTY, "ERROR",
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
        MessageBox::Show(USER_SAVE_AUTHORITY_IS_WRONG, "ERROR",
            MessageBoxButtons::OK,
            MessageBoxIcon::Information);
        return;
    }
    //overwrite it...by iNas object
    if(chk==true){
        user_Name=this->textBox_Name->Text;
        user_ID=this->textBox_ID->Text;
        user_PW=this->textBox_PW->Text;
        user_AuthLevel=this->comboBox_ALevel->Text;
        this->iNas.Overwrite_currentUser(user_ID, user_Name, user_PW, user_AuthLevel);
        //disable textbox...
        this->comboBox_ALevel->BackColor=Color::LightYellow;
        this->textBox_Name->BackColor=Color::LightYellow;
        this->textBox_ID->BackColor=Color::LightYellow;
        this->textBox_PW->BackColor=Color::LightYellow;
        this->comboBox_ALevel->Enabled=false;
        this->textBox_Name->Enabled=false;
        this->textBox_ID->Enabled=false;
        this->textBox_PW->Enabled=false;
        //buttons
        this->button_Save->Enabled=false;
        this->button_Edit->Image=nullptr;
    }
}