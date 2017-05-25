#include "set_FltDay_form.h"
#include "RDS_project.h"

using namespace RDS;
using namespace System;

System::Void set_FltDay_form::set_FltDay_form_Load
(System::Object^  sender, System::EventArgs^  e)
{
    textBox_Filter_Days->Text=SetFltDay_Msg;
}
System::Void set_FltDay_form::set_FltDay_form_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e)
{
    SetFltDay_Msg=textBox_Filter_Days->Text;
    if(SetFltDay_Msg!="")
    {
        if(e->KeyChar==0x0d) //when press Enter key
        {
            //checking value valid or not
            System::Int32 number;
            if(System::Int32::TryParse(SetFltDay_Msg, number))
            {
                //ok, it;s number
                if(number<0)
                {
                    MessageBox::Show(MSG_FLTDAYFORM_ERROR_NAGTIVE_NUMBER, "Error",
                        MessageBoxButtons::OK,
                        MessageBoxIcon::Information);
                    return;
                }
                if(number>SET_FILTER_DAYS_MAX)
                {
                    MessageBox::Show(MSG_FLTDAYFORM_ERROR_OVER_MAX_NUMBER, "Error",
                        MessageBoxButtons::OK,
                        MessageBoxIcon::Information);
                    return;
                }
            }
            else
            {
                // problem : str isn't numeric
                MessageBox::Show(MSG_FLTDAYFORM_ERROR_NOT_A_NUMBER, "Error",
                    MessageBoxButtons::OK,
                    MessageBoxIcon::Information);
                return;
            }
            //process and leave form
            m_MainForm->enable_FltDay_area();
            m_MainForm->set_textBox_FltDay(SetFltDay_Msg);
            this->Close();
        }// if press enter key
    }// if not empty string
}

System::Void set_FltDay_form::set_FltDay_form_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e)
{
    m_MainForm->enable_FltDay_area();
}