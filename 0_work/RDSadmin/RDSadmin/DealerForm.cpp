//project defines
#include "RDSadmin_project.h"
//
#include "DashBrdForm.h"
#include "RDSadminMainForm.h"
#include "nas_state.h"
#include "SupervisorForm.h"
#include "UserList_Form.h"
#include "DealerListForm.h"
#include "DealerForm.h"

using namespace System;
using namespace System::Globalization;
using namespace System::Windows::Forms;
using namespace RDSadmin;
using namespace RDS_NAS;

//====================//
//  Form Load !!!     //
//====================//
System::Void DealerForm::DealerForm_Load(System::Object^  sender, System::EventArgs^  e)
{
    //check files
    this->iNas.HasAdminIni=this->iNas.Check_Admin_Ini();
    this->iNas.HasUsersIni=this->iNas.Check_User_Ini();
    this->iNas.HasDealerIni=this->iNas.Check_Dealer_Ini();
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

    //initial SQ
    this->comboBox_SQ->Items->Clear();
    this->comboBox_SQ->Items->Add(SUPERVISOR_SECURITY_QUESTION_1);
    this->comboBox_SQ->Items->Add(SUPERVISOR_SECURITY_QUESTION_2);
    this->comboBox_SQ->Items->Add(SUPERVISOR_SECURITY_QUESTION_3);
    this->comboBox_SQ->Items->Add(SUPERVISOR_SECURITY_QUESTION_4);

    //show UI
    this->label_LoginID->Text=this->iNas.LoginUser_ID;
    this->label_LoginAuthorLv->Text=this->iNas.LoginUser_AuthLevel;
    this->label_AuthLvCode->Text=RDS_NAS_AUTHORITY_LEVEL_0;

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

    //use iNas.cur_dealer_no to show detail information
    int rtn, number;
    rtn=this->iNas.Get_Dealer_Info();
    if(rtn==0){ //Okay
        //tempary change base dir !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        this->iNas.Base_dir=RDS_NAS_ROOT_DIR+this->iNas.dealer_ComCode+"\\";
        //Get Dealer's admin.ini information
        if(-1==this->iNas.Read_Admin_ini()){
            MessageBox::Show(DEALER_DIR_ADMIN_CORRUPTED, "Message",
                MessageBoxButtons::OK,
                MessageBoxIcon::Information);
        }
        //check if company code & name are the same as in dealers.ini?
        if(this->iNas.dealer_ComCode!=this->iNas.CompanyCode||
            this->iNas.dealer_ComName!=this->iNas.CompanyName){
            MessageBox::Show(DEALER_ADMIN_INI_NOT_MATCH, "Message",
                MessageBoxButtons::OK,
                MessageBoxIcon::Information);
        }
        //change back to Root directory !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        this->iNas.Base_dir=RDS_NAS_ROOT_DIR;

        //Display Dealer
        this->textBox_CompanyCode->Text=this->iNas.dealer_ComCode;
        this->textBox_CompanyName->Text=this->iNas.dealer_ComName;
        this->textBox_ZipCode->Text=this->iNas.dealer_ZipCode;
        this->textBox_Name->Text=this->iNas.Admin_Name;
        this->textBox_ID->Text=this->iNas.Admin_ID;
        this->textBox_PW->Text=this->iNas.Admin_PW;
        this->comboBox_SQ->SelectedIndex=this->iNas.Admin_SQ_index;
        this->textBox_answer->Text=this->iNas.Admin_SQanswer;
        //UI control
        this->textBox_CompanyCode->BackColor=Color::LightYellow;
        this->textBox_CompanyName->BackColor=Color::LightYellow;
        this->textBox_ZipCode->BackColor=Color::LightYellow;
        this->textBox_Name->BackColor=Color::LightYellow;
        this->textBox_ID->BackColor=Color::LightYellow;
        this->textBox_PW->BackColor=Color::LightYellow;
        this->textBox_PW2->BackColor=Color::LightYellow;
        this->comboBox_SQ->BackColor=Color::LightYellow;
        this->textBox_answer->BackColor=Color::LightYellow;
        this->textBox_CompanyCode->Enabled=false;
        this->textBox_CompanyName->Enabled=false;
        this->textBox_ZipCode->Enabled=false;
        this->textBox_Name->Enabled=false;
        this->textBox_ID->Enabled=false;
        this->textBox_PW->Enabled=false;
        this->textBox_PW2->Enabled=false;
        this->comboBox_SQ->Enabled=false;
        this->textBox_answer->Enabled=false;

        //display Title
        number=this->iNas.cur_dealer_no+1;
        this->label_Title->Text="Dealer #"+number;
    }
}

//----------------//
//  Menu buttons  //
//----------------//
System::Void DealerForm::button_DashBoard_Click(System::Object^  sender, System::EventArgs^  e)
{
    RDSadmin::DashBrdForm^ formDash=gcnew DashBrdForm();
    formDash->iNas.LoginUser_no=this->iNas.LoginUser_no;
    formDash->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
    formDash->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
    formDash->iNas.Base_dir=this->iNas.Base_dir;
    formDash->Show();
    this->Close();
}

System::Void DealerForm::button_ServiceCall_Click(System::Object^  sender, System::EventArgs^  e)
{
    RDSadmin::RDSadminMainForm^ formRDSmain=gcnew RDSadminMainForm(0);
    formRDSmain->iNas.LoginUser_no=this->iNas.LoginUser_no;
    formRDSmain->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
    formRDSmain->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
    formRDSmain->iNas.Base_dir=this->iNas.Base_dir;
    formRDSmain->Show();
    this->Close();
}

System::Void DealerForm::button_Supervisor_Click(System::Object^  sender, System::EventArgs^  e)
{
    RDSadmin::SupervisorForm^ formSuper=gcnew SupervisorForm();
    formSuper->iNas.LoginUser_no=this->iNas.LoginUser_no;
    formSuper->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
    formSuper->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
    formSuper->iNas.Base_dir=this->iNas.Base_dir;
    formSuper->Show();
    this->Close();
}

System::Void DealerForm::button_RDSuser_Click(System::Object^  sender, System::EventArgs^  e)
{
    RDSadmin::UserList_Form^ formUser=gcnew UserList_Form();
    formUser->iNas.LoginUser_no=this->iNas.LoginUser_no;
    formUser->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
    formUser->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
    formUser->iNas.Base_dir=this->iNas.Base_dir;
    formUser->Show();
    this->Close();
}

System::Void DealerForm::button_Dealer_Click(System::Object^  sender, System::EventArgs^  e)
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
System::Void DealerForm::button_Edit_Click(System::Object^  sender, System::EventArgs^  e)
{
    //UI control
    //this->textBox_CompanyCode->BackColor = Color::White; //People can not modify company code !!
    this->textBox_CompanyName->BackColor=Color::White;
    this->textBox_ZipCode->BackColor=Color::White;
    this->textBox_Name->BackColor=Color::White;
    this->textBox_ID->BackColor=Color::White;
    this->textBox_PW->BackColor=Color::White;
    this->textBox_PW2->BackColor=Color::White;
    this->comboBox_SQ->BackColor=Color::White;
    this->textBox_answer->BackColor=Color::White;
    //this->textBox_CompanyCode->Enabled = true;
    this->textBox_CompanyName->Enabled=true;
    this->textBox_ZipCode->Enabled=true;
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

System::Void DealerForm::button_Save_Click(System::Object^  sender, System::EventArgs^  e)
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

    Boolean chk=true;
    int rtn;

    //checking Company Code field
    if(this->textBox_CompanyCode->Text==""){
        chk=false;
        MessageBox::Show(DEALER_SAVE_COM_CODE_EMPTY, "ERROR",
            MessageBoxButtons::OK,
            MessageBoxIcon::Information);
        return;
    }
    else{
        if(this->iNas.Is_com_code_fmt_OK(this->textBox_CompanyCode->Text)==false){
            chk=false;
            MessageBox::Show(DEALER_SAVE_COM_CODE_FAIL, "ERROR",
                MessageBoxButtons::OK,
                MessageBoxIcon::Information);
            return;
        }
    }

    //checking Company Name field
    if(this->textBox_CompanyName->Text==""){
        chk=false;
        MessageBox::Show(DEALER_SAVE_NO_COMPANY_NAME, "ERROR",
            MessageBoxButtons::OK,
            MessageBoxIcon::Information);
        return;
    }

    //Checking Zip code field
    if(this->textBox_ZipCode->Text==""){
        chk=false;
        MessageBox::Show(DEALER_SAVE_ZIP_CODE_EMPTY, "ERROR",
            MessageBoxButtons::OK,
            MessageBoxIcon::Information);
        return;
    }
    else{
        if(this->iNas.Is_Zip_code_fmt_OK(this->textBox_ZipCode->Text)==false){
            chk=false;
            MessageBox::Show(DEALER_SAVE_ZIP_CODE_FAIL, "ERROR",
                MessageBoxButtons::OK,
                MessageBoxIcon::Information);
            return;
        }
    }

    //checking Admin Name field
    if(this->textBox_Name->Text==""){
        chk=false;
        MessageBox::Show(DEALER_SAVE_NAME_EMPTY, "ERROR",
            MessageBoxButtons::OK,
            MessageBoxIcon::Information);
        return;
    }

    //checking Admin ID field
    if(this->textBox_ID->Text==""){
        chk=false;
        MessageBox::Show(DEALER_SAVE_ID_IS_EMPTY, "ERROR",
            MessageBoxButtons::OK,
            MessageBoxIcon::Information);
        return;
    }

    //checking Admin PW field
    if(this->textBox_PW->Text==""){
        chk=false;
        MessageBox::Show(DEALER_SAVE_PW_IS_EMPTY, "ERROR",
            MessageBoxButtons::OK,
            MessageBoxIcon::Information);
        return;
    }
    else{
        if(this->textBox_PW->Text!=this->textBox_PW2->Text){
            chk=false;
            MessageBox::Show(DEALER_SAVE_PW_NOT_MATCH, "ERROR",
                MessageBoxButtons::OK,
                MessageBoxIcon::Information);
            return;
        }
    }

    //checking security question and answer
    if(this->textBox_answer->Text==""||this->comboBox_SQ->SelectedIndex<0){
        chk=false;
        MessageBox::Show(DEALER_SAVE_SQ_NOT_SETED, "ERROR",
            MessageBoxButtons::OK,
            MessageBoxIcon::Information);
        return;
    }

    //it should not happen, but we still check
    if(this->iNas.Base_dir!=RDS_NAS_ROOT_DIR){
        MessageBox::Show(DEALER_SAVE_WRONG_BASE_DIR, "ERROR",
            MessageBoxButtons::OK,
            MessageBoxIcon::Information);
        return;
    }

    //-------------------------------------------------------------
    //do modify & overwrite...
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

        //overwrite Dealer
        rtn=this->iNas.Overwrite_currDealer( //using current_dealer_No
            CompanyCode,
            CompanyName,
            ZipCode
        );

        if(rtn==0){ //Okay
            //tempary change base dir !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            this->iNas.Base_dir=RDS_NAS_ROOT_DIR+CompanyCode+"\\";

            //overwrite Dealer admin.ini, users.ini
            //(1)overwrite admin.ini
            this->iNas.Delete_Admin_ini();
            this->iNas.Write_Admin_Ini(
                Admin_ID, Admin_Name, Admin_PW, Admin_AuthLevel, Admin_SQ_index, Admin_SQanswer,
                CompanyCode, CompanyName);
            //(2)overwrite admin in users.ini
            this->iNas.Overwrite_Admin_inUsers(Admin_ID, Admin_Name, Admin_PW, Admin_AuthLevel);

            //change back to Root directory !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            this->iNas.Base_dir=RDS_NAS_ROOT_DIR;
        } // end if over dealer okay

        //UI control
        this->textBox_CompanyCode->BackColor=Color::LightYellow;
        this->textBox_CompanyName->BackColor=Color::LightYellow;
        this->textBox_ZipCode->BackColor=Color::LightYellow;
        this->textBox_Name->BackColor=Color::LightYellow;
        this->textBox_ID->BackColor=Color::LightYellow;
        this->textBox_PW->BackColor=Color::LightYellow;
        this->textBox_PW2->BackColor=Color::LightYellow;
        this->comboBox_SQ->BackColor=Color::LightYellow;
        this->textBox_answer->BackColor=Color::LightYellow;
        this->textBox_CompanyCode->Enabled=false;
        this->textBox_CompanyName->Enabled=false;
        this->textBox_ZipCode->Enabled=false;
        this->textBox_Name->Enabled=false;
        this->textBox_ID->Enabled=false;
        this->textBox_PW->Enabled=false;
        this->textBox_PW2->Enabled=false;
        this->comboBox_SQ->Enabled=false;
        this->textBox_answer->Enabled=false;
        //buttons
        this->button_Save->Enabled=false;
        this->button_Edit->Image=nullptr;
    } //end if chk==true
}