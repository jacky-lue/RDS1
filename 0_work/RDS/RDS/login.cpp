#include "login.h"
#include "RDS_project.h"

using namespace RDS;
using namespace System;
using namespace System::Windows::Forms;
using namespace RDS_NAS;

//-----------------//
// Login form Load //
//-----------------//
System::Void login::login_Load(System::Object^  sender, System::EventArgs^  e)
{
    //checking files
    this->iNas.HasAdminIni=this->iNas.Check_Admin_Ini();
    this->iNas.HasUsersIni=this->iNas.Check_User_Ini();
    this->iNas.HasDealerIni=this->iNas.Check_Dealer_Ini();
    this->iNas.Has_Model_AD_Ini=this->iNas.Check_Model_AD_Ini();

    //Admin.ini checking & reading
    if(this->iNas.HasAdminIni==false)
    {
        MessageBox::Show(MSG_LOGIN_SPA_COM_ADMIN_INI_NOT_FOUND, "ERROR",
            MessageBoxButtons::OK, MessageBoxIcon::Information);
        this->button_login->Enabled=false;
    }
    else
    {
        if(-1==this->iNas.get_SpaComapny())
        {
            MessageBox::Show(MSG_LOGIN_SPA_COM_ADMIN_INI_FAILED, "ERROR",
                MessageBoxButtons::OK, MessageBoxIcon::Information);
            this->button_login->Enabled=false;
        }
    }

    //UI-display
    this->label_ComName->Text="";
    this->textBox_ID->Focus();
}

//---------------------//
// CompanyCode_change  //
//---------------------//
System::Void login::textBox_CompanyCode_TextChanged(System::Object^  sender, System::EventArgs^  e)
{
    String^ CompanyCode;
    String^ CompanyName;

    //get code
    CompanyCode=this->textBox_CompanyCode->Text;

    //check spa company code? (alread read @ form load)
    if(CompanyCode==this->iNas.SpaCompanyCode)
    {
        CompanyName=this->iNas.SpaCompanyName;
    }
    else
    {
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
    Boolean chk=true;
    String^ ComCode;
    String^ TmpComName;
    int rtn;
    //checking... users.ini in NAS directory
    if(this->iNas.HasUsersIni==false)
    {
        MessageBox::Show(MSG_LOGIN_ERR_USER_INI_FILE_NOT_FOUD, "Error",
            MessageBoxButtons::OK,
            MessageBoxIcon::Information);
        this->Close();
        m_MainForm->LoginResult(false, 255, "");
        return;
    }
    //checking... Model_AD.ini in NAS directory
    if(this->iNas.Has_Model_AD_Ini==false)
    {
        MessageBox::Show(MSG_LOGIN_ERR_MODELAD_INI_FILE_NOT_FOUD, "ERROR",
            MessageBoxButtons::OK,
            MessageBoxIcon::Information);
        this->Close();
        m_MainForm->LoginResult(false, 255, "");
        return;
    }
    //----------------------------------------------------------
    //checking Commany Code
    if(this->textBox_CompanyCode->Text=="")
    {
        MessageBox::Show(MSG_LOGIN_COMPANY_CODE_EMPTY, "ERROR",
            MessageBoxButtons::OK,
            MessageBoxIcon::Information);
        this->textBox_CompanyCode->Focus();
        return;
    }
    ComCode=this->textBox_CompanyCode->Text;

    //Parse the Company Code, get the working base directory =============
    if(ComCode==this->iNas.SpaCompanyCode)
    {
        //is Spa Company!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        this->iNas.Base_dir=RDS_NAS_ROOT_DIR;
    }
    else
    {
        //is Dealer? check this code is vaild dealer....
        TmpComName=this->iNas.Get_Dealer_ComName(ComCode);
        if(TmpComName==NO_DEALER_COM_CODE||TmpComName==DEFAULT_SPA_COM_NAME)
        {
            MessageBox::Show(MSG_LOGIN_COMPANY_CODE_NOT_VALID, "ERROR",
                MessageBoxButtons::OK, MessageBoxIcon::Information);
            this->textBox_CompanyCode->Focus();
            return;
        }
        //is dealer !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        this->iNas.Base_dir=RDS_NAS_ROOT_DIR+ComCode+"\\";
        //check files in Dealer sub-directory
        this->iNas.HasAdminIni=this->iNas.Check_Admin_Ini();
        this->iNas.HasUsersIni=this->iNas.Check_User_Ini();
        this->iNas.Has_Model_AD_Ini=this->iNas.Check_Model_AD_Ini();
    }

    //checking ID field ---------------------------------------
    if(this->textBox_ID->Text=="")
    {
        chk=false;
        MessageBox::Show(MSG_LOGIN_ERR_NO_ACCOUNT, "ERROR",
            MessageBoxButtons::OK,
            MessageBoxIcon::Information);
        return;
    }

    //checking PW field
    if(this->textBox_PW->Text=="")
    {
        chk=false;
        MessageBox::Show(MSG_LOGIN_ERR_NO_PASSWORD, "ERROR",
            MessageBoxButtons::OK,
            MessageBoxIcon::Information);
        return;
    }

    //trying user login ============================================================
    if(chk==true)
    {
        rtn=this->iNas.user_Login(
            this->textBox_ID->Text,
            this->textBox_PW->Text
        );
        //checking login result
        if(rtn==-1)
        {
            MessageBox::Show(MSG_LOGIN_ERR_USERID_NOT_FOUND, "ERROR",
                MessageBoxButtons::OK,
                MessageBoxIcon::Information);
            this->textBox_ID->Text="";
            this->textBox_PW->Text="";
            this->textBox_ID->Focus();
            return;
        }
        if(rtn==-2)
        {
            MessageBox::Show(MSG_LOGIN_ERR_WRONG_PASSWORD, "ERROR",
                MessageBoxButtons::OK,
                MessageBoxIcon::Information);
            this->textBox_PW->Text="";
            this->textBox_PW->Focus();
            return;
        }
        if(rtn==-3)
        {
            MessageBox::Show(LOGIN_ERR_ALREADY_LOGINED, "ERROR",
                MessageBoxButtons::OK,
                MessageBoxIcon::Information);
            this->textBox_PW->Text="";
            this->textBox_PW->Focus();
            return;
        }
        if(rtn==0)
        {
            //lock person
            String^ TimeString;
            DateTime dt=DateTime::Now;
            TimeString=dt.ToString("yyyyMMdd-HH:mm", DateTimeFormatInfo::InvariantInfo);
            if(0>this->iNas.Lock_Person_Login(this->iNas.userNo, TimeString))
            {
                MessageBox::Show(LOGIN_ERR_FILE_EXIST_BEF_LOCK, "ERROR",
                    MessageBoxButtons::OK,
                    MessageBoxIcon::Information);
            }
            //return & login OK
            m_MainForm->iNas.Base_dir=this->iNas.Base_dir;
            m_MainForm->iNas.userNo=this->iNas.userNo;
            m_MainForm->iNas.userName=this->iNas.userName;
            m_MainForm->iNas.user_AuthLevel=this->iNas.user_AuthLevel;
            m_MainForm->Base_dir=this->iNas.Base_dir;
            m_MainForm->LoginResult(true, this->iNas.userNo, this->iNas.userName);
            this->Close();
            return;
        }
    }
}

//-----------------//
//  Exit button    //
//-----------------//
System::Void login::button_Exit_Click(System::Object^  sender, System::EventArgs^  e)
{
    //return cancel
    this->Close();
    m_MainForm->LoginResult(false, 255, "");
    return;
}