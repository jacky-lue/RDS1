#include "set_UVday_form.h"
#include "RDS_project.h"

using namespace RDS;
using namespace System;

System::Void set_UVday_form::set_UVday_form_Load(System::Object^  sender, System::EventArgs^  e)
{
    textBox_UV_Days->Text=SetUVday_Msg;
}

System::Void set_UVday_form::set_UVday_form_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e)
{
    SetUVday_Msg=textBox_UV_Days->Text;
    if(SetUVday_Msg!="")
    {
        if(e->KeyChar==0x0d) //when press Enter key
        {
            //checking value valid or not
            System::Int32 number;
            if(System::Int32::TryParse(SetUVday_Msg, number))
            {
                //ok, it;s number
                if(number<0)
                {
                    MessageBox::Show(MSG_UVDAYFORM_ERROR_NAGTIVE_NUMBER, "Error",
                        MessageBoxButtons::OK,
                        MessageBoxIcon::Information);
                    return;
                }
                if(number>SET_UV_DAYS_MAX)
                {
                    MessageBox::Show(MSG_UVDAYFORM_ERROR_OVER_MAX_NUMBER, "Error",
                        MessageBoxButtons::OK,
                        MessageBoxIcon::Information);
                    return;
                }
            }
            else
            {
                // problem : str isn't numeric
                MessageBox::Show(MSG_UVDAYFORM_ERROR_NOT_A_NUMBER, "Error",
                    MessageBoxButtons::OK,
                    MessageBoxIcon::Information);
                return;
            }
            //process and leave form
            m_MainForm->enable_UVday_area();
            m_MainForm->set_textBox_UVday(SetUVday_Msg);
            this->Close();
        }// if press enter key
    }// if not empty string
}

System::Void set_UVday_form::set_UVday_form_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e)
{
    m_MainForm->enable_UVday_area();
}