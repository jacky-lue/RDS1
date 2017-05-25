#include "set_PF_Form.h"

using namespace RDS;
using namespace System;

System::Void set_PF_Form::set_PF_Form_Load(System::Object^  sender, System::EventArgs^  e)
{
    this->cmbx_Fltr_ST_hour->SelectedIndex=pf_st_hour;
    this->cmbx_Fltr_ST_min->SelectedIndex=pf_st_min;
    this->cmbx_fltr_DT_hour->SelectedIndex=pf_dt_hour;
    if(pf_dt_min==0)this->cmbx_fltr_DT_min->SelectedIndex=0;
    if(pf_dt_min==15)this->cmbx_fltr_DT_min->SelectedIndex=1;
    if(pf_dt_min==30)this->cmbx_fltr_DT_min->SelectedIndex=2;
    if(pf_dt_min==45)this->cmbx_fltr_DT_min->SelectedIndex=3;
}
System::Void set_PF_Form::button_Save_Click(System::Object^  sender, System::EventArgs^  e)
{
    //get value from UI
    pf_st_hour=this->cmbx_Fltr_ST_hour->SelectedIndex;
    pf_st_min=this->cmbx_Fltr_ST_min->SelectedIndex;
    pf_dt_hour=this->cmbx_fltr_DT_hour->SelectedIndex;
    if(this->cmbx_fltr_DT_min->SelectedIndex==0) pf_dt_min=0;
    if(this->cmbx_fltr_DT_min->SelectedIndex==1) pf_dt_min=15;
    if(this->cmbx_fltr_DT_min->SelectedIndex==2) pf_dt_min=30;
    if(this->cmbx_fltr_DT_min->SelectedIndex==3) pf_dt_min=45;

    //then,call main-from function (set std filteration schedule)
    m_MainForm->enable_PF_btn();
    m_MainForm->set_PF(
        pf_value,
        pf_st_hour,
        pf_st_min,
        pf_dt_hour,
        pf_dt_min
    );
    this->Close();
}

System::Void set_PF_Form::set_PF_Form_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e)
{
    m_MainForm->enable_PF_btn();
}