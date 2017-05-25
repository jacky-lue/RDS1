#include "set_SF_Form.h"

using namespace RDS;
using namespace System;

System::Void set_SF_Form::set_SF_Form_Load(System::Object^  sender, System::EventArgs^  e)
{
    if(sf_value==0)
    {
        this->radioButton_SF0->Checked=true;
    }
    else if(sf_value==1)
    {
        this->radioButton_SF1->Checked=true;
    }
    else if(sf_value==2)
    {
        this->radioButton_SF2->Checked=true;
    }
    else
    {
        this->radioButton_SF3->Checked=true;
    }
}

System::Void set_SF_Form::button_Save_Click(System::Object^  sender, System::EventArgs^  e)
{
    //then,call main-from function (set SFx)
    m_MainForm->enable_SF_btn();
    m_MainForm->set_SF(this->sf_value);
    this->Close();
}

System::Void set_SF_Form::set_SF_Form_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e)
{
    m_MainForm->enable_SF_btn();
}

System::Void set_SF_Form::radioButton_SF0_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
    if(this->radioButton_SF0->Checked==true)
    {
        sf_value=0;
    }
}

System::Void set_SF_Form::radioButton_SF1_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
    if(this->radioButton_SF1->Checked==true)
    {
        sf_value=1;
    }
}

System::Void set_SF_Form::radioButton_SF2_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
    if(this->radioButton_SF2->Checked==true)
    {
        sf_value=2;
    }
}

System::Void set_SF_Form::radioButton_SF3_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
    if(this->radioButton_SF3->Checked==true)
    {
        sf_value=3;
    }
}