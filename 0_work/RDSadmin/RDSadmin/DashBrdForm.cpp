//project defines
#include "RDSadmin_project.h"
//
#include "RDSadminMainForm.h"
#include "nas_state.h"
#include "SupervisorForm.h"
#include "UserList_Form.h"
#include "DealerListForm.h"
#include "DashBrdForm.h"
#include "Dash2Form.h"

using namespace System;
using namespace System::Globalization;
using namespace System::Windows::Forms;
using namespace RDSadmin;
using namespace RDS_NAS;

//====================//
//  Form Load !!!     //
//====================//
System::Void DashBrdForm::DashBrdForm_Load(System::Object^  sender, System::EventArgs^  e)
{
    this->iNas.HasAdminIni=this->iNas.Check_Admin_Ini();
    this->iNas.HasUsersIni=this->iNas.Check_User_Ini();
    //checking...
    if(this->iNas.HasUsersIni==false){
        MessageBox::Show(FORM_LOAD_USERS_INI_LOST_WARN, "ERROR",
            MessageBoxButtons::OK,
            MessageBoxIcon::Information);
        //this->Close();  //for first time using, we cannot close!!!!!
    }

    //show Login-User
    this->label_LoginID->Text=this->iNas.LoginUser_ID;
    this->label_LoginAuthorLv->Text=this->iNas.LoginUser_AuthLevel;

    //Hide Buttons by authority_level
    if(this->iNas.LoginUser_AuthLevel!=RDS_NAS_AUTHORITY_LEVEL_0){
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
System::Void DashBrdForm::button_ServiceCall_Click(System::Object^  sender, System::EventArgs^  e)
{
    RDSadmin::RDSadminMainForm^ formRDSmain=gcnew RDSadminMainForm(0);
    formRDSmain->iNas.LoginUser_no=this->iNas.LoginUser_no;
    formRDSmain->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
    formRDSmain->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
    formRDSmain->iNas.Base_dir=this->iNas.Base_dir;
    formRDSmain->Show();
    this->Close();
}

System::Void DashBrdForm::button_Supervisor_Click(System::Object^  sender, System::EventArgs^  e)
{
    RDSadmin::SupervisorForm^ formSuper=gcnew SupervisorForm();
    formSuper->iNas.LoginUser_no=this->iNas.LoginUser_no;
    formSuper->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
    formSuper->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
    formSuper->iNas.Base_dir=this->iNas.Base_dir;
    formSuper->Show();
    this->Close();
}

System::Void DashBrdForm::button_RDSuser_Click(System::Object^  sender, System::EventArgs^  e)
{
    RDSadmin::UserList_Form^ formUser=gcnew UserList_Form();
    formUser->iNas.LoginUser_no=this->iNas.LoginUser_no;
    formUser->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
    formUser->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
    formUser->iNas.Base_dir=this->iNas.Base_dir;
    formUser->Show();
    this->Close();
}

System::Void DashBrdForm::button_Dealer_Click(System::Object^  sender, System::EventArgs^  e)
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
//  Next buttons  //
//----------------//
System::Void DashBrdForm::button_next_Click(System::Object^  sender, System::EventArgs^  e)
{
    RDSadmin::Dash2Form^ formDash2=gcnew Dash2Form();
    formDash2->iNas.LoginUser_no=this->iNas.LoginUser_no;
    formDash2->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
    formDash2->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
    formDash2->iNas.Base_dir=this->iNas.Base_dir;
    formDash2->Show();
    this->Close();
}