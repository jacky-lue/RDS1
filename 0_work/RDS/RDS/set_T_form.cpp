#include "set_T_form.h"
#include "RDS_project.h"

using namespace RDS;
using namespace System;

System::Void set_T_form::set_T_form_Load(System::Object^  sender, System::EventArgs^  e)
{
    textBox_Set_T->Text=SetTempr_Msg;
}

System::Void set_T_form::set_T_form_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e)
{
    SetTempr_Msg=textBox_Set_T->Text;
    if(SetTempr_Msg!="")
    {
        if(e->KeyChar==0x0d) //when press Enter key
        {
            //checking value valid or not
            if(m_MainForm->Display_F==true)
            {  //degree F
                System::Int32 number;
                if(System::Int32::TryParse(SetTempr_Msg, number))
                {
                    /* ok, use number */
                    if(number<SET_TEMP_F_MIN)
                    {
                        MessageBox::Show(MSG_SET_T_FORM_ERROR_LOWER_MIN_NUMBER, "Error",
                            MessageBoxButtons::OK,
                            MessageBoxIcon::Information);
                        return;
                    }
                    if(number>SET_TEMP_F_MAX)
                    {
                        MessageBox::Show("Temperature is higher than maxnum value", "Error",
                            MessageBoxButtons::OK,
                            MessageBoxIcon::Information);
                        return;
                    }
                    //will go to call main-form....
                }
                else
                {
                    /* problem : str isn't numeric */
                    MessageBox::Show("String is not a number", "Error",
                        MessageBoxButtons::OK,
                        MessageBoxIcon::Information);
                    return;
                }
            }
            else
            {
                //degree C
                System::Single numberF;
                if(System::Single::TryParse(SetTempr_Msg, numberF))
                {
                    /* ok, use numberF */
                    if(numberF<SET_TEMP_C_MIN)
                    {
                        MessageBox::Show(MSG_SET_T_FORM_ERROR_LOWER_MIN_NUMBER, "Error",
                            MessageBoxButtons::OK,
                            MessageBoxIcon::Information);
                        return;
                    }
                    if(numberF>SET_TEMP_C_MAX)
                    {
                        MessageBox::Show(MSG_SET_T_FORM_ERROR_OVER_MAX_NUMBER, "Error",
                            MessageBoxButtons::OK,
                            MessageBoxIcon::Information);
                        return;
                    }
                    //modify String for transfer to main-form
                    int new_value=numberF*10;
                    SetTempr_Msg=Convert::ToString(new_value);
                    //will go to call main-form....
                }
                else
                {
                    /* problem : str isn't numeric */
                    MessageBox::Show(MSG_SET_T_FORM_ERROR_NOT_A_NUMBER, "Err.",
                        MessageBoxButtons::OK,
                        MessageBoxIcon::Information);
                    return;
                }
            }
            //call main-form function and close myself
            m_MainForm->enable_SetT_area();
            m_MainForm->set_textBox_Set_T(SetTempr_Msg);
            this->Close();
            return;
        } // if press enter key
    }// if not empty string
}

System::Void set_T_form::set_T_form_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e)
{
    m_MainForm->enable_SetT_area();
}