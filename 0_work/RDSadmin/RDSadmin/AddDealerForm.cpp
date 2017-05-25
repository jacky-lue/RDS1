//project defines
#include "RDSadmin_project.h"
//
#include "DashBrdForm.h"
#include "RDSadminMainForm.h"
#include "nas_state.h"
#include "SupervisorForm.h"
#include "UserList_Form.h"
#include "DealerListForm.h"
#include "AddDealerForm.h"

using namespace System;
using namespace System::Globalization;
using namespace System::Windows::Forms;
using namespace RDSadmin;
using namespace RDS_NAS;

//====================//
//  Form Load !!!     //
//====================//
System::Void AddDealerForm::AddDealerForm_Load(System::Object^  sender, System::EventArgs^  e)
{
    //check file...
    this->iNas.HasAdminIni=this->iNas.Check_Admin_Ini();
    this->iNas.HasDealerIni=this->iNas.Check_Dealer_Ini();
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
    //
    this->label_AuthLvCode->Text=RDS_NAS_AUTHORITY_LEVEL_0;
    //
    this->comboBox_SQ->Items->Clear();
    this->comboBox_SQ->Items->Add(SUPERVISOR_SECURITY_QUESTION_1);
    this->comboBox_SQ->Items->Add(SUPERVISOR_SECURITY_QUESTION_2);
    this->comboBox_SQ->Items->Add(SUPERVISOR_SECURITY_QUESTION_3);
    this->comboBox_SQ->Items->Add(SUPERVISOR_SECURITY_QUESTION_4);

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
System::Void AddDealerForm::button_DashBoard_Click(System::Object^  sender, System::EventArgs^  e)
{
    RDSadmin::DashBrdForm^ formDash=gcnew DashBrdForm();
    formDash->iNas.LoginUser_no=this->iNas.LoginUser_no;
    formDash->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
    formDash->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
    formDash->iNas.Base_dir=this->iNas.Base_dir;
    formDash->Show();
    this->Close();
}

System::Void AddDealerForm::button_ServiceCall_Click(System::Object^  sender, System::EventArgs^  e)
{
    RDSadmin::RDSadminMainForm^ formRDSmain=gcnew RDSadminMainForm(0);
    formRDSmain->iNas.LoginUser_no=this->iNas.LoginUser_no;
    formRDSmain->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
    formRDSmain->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
    formRDSmain->iNas.Base_dir=this->iNas.Base_dir;
    formRDSmain->Show();
    this->Close();
}

System::Void AddDealerForm::button_Supervisor_Click(System::Object^  sender, System::EventArgs^  e)
{
    RDSadmin::SupervisorForm^ formSuper=gcnew SupervisorForm();
    formSuper->iNas.LoginUser_no=this->iNas.LoginUser_no;
    formSuper->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
    formSuper->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
    formSuper->iNas.Base_dir=this->iNas.Base_dir;
    formSuper->Show();
    this->Close();
}

System::Void AddDealerForm::button_RDSuser_Click(System::Object^  sender, System::EventArgs^  e)
{
    RDSadmin::UserList_Form^ formUser=gcnew UserList_Form();
    formUser->iNas.LoginUser_no=this->iNas.LoginUser_no;
    formUser->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
    formUser->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
    formUser->iNas.Base_dir=this->iNas.Base_dir;
    formUser->Show();
    this->Close();
}

System::Void AddDealerForm::button_Dealer_Click(System::Object^  sender, System::EventArgs^  e)
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

System::Void AddDealerForm::button_Save_Click(System::Object^  sender, System::EventArgs^  e)
{
    String^ CompanyCode;
    String^ CompanyName;
    String^ ZipCode;
    String^ Admin_ID;
    String^ Admin_Name;
    String^ Admin_PW;
    String^ Admin_AuthLevel;
    unsigned int Admin_SQ_index;
    String^ Admin_SQanswer;
    //
    String^ dealerDir;
    Boolean chk=true;
    int rtn;
    int rtn2;

    //checking Company Code field
    if(this->textBox_CompanyCode->Text==""){
        chk=false;
        MessageBox::Show(ADD_DEALER_SAVE_COM_CODE_EMPTY, "ERROR",
            MessageBoxButtons::OK,
            MessageBoxIcon::Information);
        return;
    }
    else{
        if(this->iNas.Is_com_code_fmt_OK(this->textBox_CompanyCode->Text)==false){
            chk=false;
            MessageBox::Show(ADD_DEALER_SAVE_COM_CODE_FAIL, "ERROR",
                MessageBoxButtons::OK,
                MessageBoxIcon::Information);
            return;
        }
    }

    //checking Company Name field
    if(this->textBox_CompanyName->Text==""){
        chk=false;
        MessageBox::Show(ADD_DEALER_SAVE_NO_COMPANY_NAME, "ERROR",
            MessageBoxButtons::OK,
            MessageBoxIcon::Information);
        return;
    }

    //Checking Zip code field
    if(this->textBox_ZipCode->Text==""){
        chk=false;
        MessageBox::Show(ADD_DEALER_SAVE_ZIP_CODE_EMPTY, "ERROR",
            MessageBoxButtons::OK,
            MessageBoxIcon::Information);
        return;
    }
    else{
        if(this->iNas.Is_Zip_code_fmt_OK(this->textBox_ZipCode->Text)==false){
            chk=false;
            MessageBox::Show(ADD_DEALER_SAVE_ZIP_CODE_FAIL, "ERROR",
                MessageBoxButtons::OK,
                MessageBoxIcon::Information);
            return;
        }
    }

    //checking Admin Name field
    if(this->textBox_Name->Text==""){
        chk=false;
        MessageBox::Show(ADD_DEALER_SAVE_NAME_EMPTY, "ERROR",
            MessageBoxButtons::OK,
            MessageBoxIcon::Information);
        return;
    }

    //checking Admin ID field
    if(this->textBox_ID->Text==""){
        chk=false;
        MessageBox::Show(ADD_DEALER_SAVE_ID_IS_EMPTY, "ERROR",
            MessageBoxButtons::OK,
            MessageBoxIcon::Information);
        return;
    }

    //checking Admin PW field
    if(this->textBox_PW->Text==""){
        chk=false;
        MessageBox::Show(ADD_DEALER_SAVE_PW_IS_EMPTY, "ERROR",
            MessageBoxButtons::OK,
            MessageBoxIcon::Information);
        return;
    }
    else{
        if(this->textBox_PW->Text!=this->textBox_PW2->Text){
            chk=false;
            MessageBox::Show(ADD_DEALER_SAVE_PW_NOT_MATCH, "ERROR",
                MessageBoxButtons::OK,
                MessageBoxIcon::Information);
            return;
        }
    }

    //checking security question and answer
    if(this->textBox_answer->Text==""||this->comboBox_SQ->SelectedIndex<0){
        chk=false;
        MessageBox::Show(ADD_DEALER_SAVE_SQ_NOT_SETED, "ERROR",
            MessageBoxButtons::OK,
            MessageBoxIcon::Information);
        return;
    }

    //it should not happen, but we still check
    if(this->iNas.Base_dir!=RDS_NAS_ROOT_DIR){
        chk=false;
        MessageBox::Show(ADD_DEALER_SAVE_WRONG_BASE_DIR, "ERROR",
            MessageBoxButtons::OK,
            MessageBoxIcon::Information);
        return;
    }

    //checkif dealer Code (directory) already exist?
    dealerDir=RDS_NAS_ROOT_DIR+this->textBox_CompanyCode->Text+"\\";
    if(true==Directory::Exists(dealerDir)){
        chk=false;
        MessageBox::Show(ADD_DEALER_SAVE_COM_CODE_SAME, "ERROR",
            MessageBoxButtons::OK,
            MessageBoxIcon::Information);
        return;
    }

    //------------------------------------------------------------------------
    //do wriite files & build dealer dirctory
    if(chk==true){
        //prepare data
        CompanyCode=this->textBox_CompanyCode->Text;
        CompanyName=this->textBox_CompanyName->Text;
        ZipCode=this->textBox_ZipCode->Text;
        Admin_Name=this->textBox_Name->Text;
        Admin_ID=this->textBox_ID->Text;
        Admin_PW=this->textBox_PW->Text;
        Admin_AuthLevel=this->label_AuthLvCode->Text;
        Admin_SQ_index=this->comboBox_SQ->SelectedIndex;
        Admin_SQanswer=this->textBox_answer->Text;

        //add into Dealers.ini...
        rtn=this->iNas.Add_Dealers_Ini(
            CompanyCode,
            CompanyName,
            ZipCode
        );
        //check it sucessful or not
        if(rtn==0) {  //dealers.ini Add sucessful~
            //tempary change !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            this->iNas.Base_dir=RDS_NAS_ROOT_DIR+CompanyCode+"\\";

            //Build dealer sub-directories
            Directory::CreateDirectory(this->iNas.Base_dir);
            this->iNas.Build_All_Dir();

            //Write Admin.ini & users.ini inside of dealer base-directory
            this->iNas.Write_Admin_Ini(
                Admin_ID, Admin_Name, Admin_PW, Admin_AuthLevel, Admin_SQ_index, Admin_SQanswer,
                CompanyCode, CompanyName);
            rtn2=this->iNas.Add_Users_Ini(Admin_ID, Admin_Name, Admin_PW, Admin_AuthLevel);
            if(rtn2==0) {
                MessageBox::Show(SUPERVISOR_SAVE_MODIFY_OKAY, "OK",
                    MessageBoxButtons::OK,
                    MessageBoxIcon::Information);
            }
            else{
                //error....
                MessageBox::Show(SUPERVISOR_SAVE_USERINI_WARNING, "WARNING",
                    MessageBoxButtons::OK,
                    MessageBoxIcon::Warning);
                return;
            }

            //change back to Root directory !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            this->iNas.Base_dir=RDS_NAS_ROOT_DIR;

            //show message
            MessageBox::Show(ADD_DEALER_SAVE_NEW_ADD_OKAY, "OK",
                MessageBoxButtons::OK,
                MessageBoxIcon::Information);

            //back to dealer list form...
            RDSadmin::DealerListForm^ formDealer=gcnew DealerListForm();
            formDealer->iNas.LoginUser_no=this->iNas.LoginUser_no;
            formDealer->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
            formDealer->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
            formDealer->iNas.Base_dir=this->iNas.Base_dir;
            formDealer->Show();
            this->Close();
            //
            return;
        }
        else{
            //rtn=-1, has same CompanyCode Dealer
            MessageBox::Show(ADD_DEALER_SAVE_FAIL_SAME_ID, "ERROR",
                MessageBoxButtons::OK,
                MessageBoxIcon::Information);
            return;
        }
    }//----end----do write files & build dealer directory
}