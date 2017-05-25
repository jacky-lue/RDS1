#include "FltSchedule_Form.h"

using namespace RDS;
using namespace System;

System::Void FltSchedule_Form::FltSchedule_Form_Load(System::Object^  sender, System::EventArgs^  e)
{
    this->cmbx_Fltr_ST_hour->SelectedIndex=std_st_hour;
    this->cmbx_Fltr_ST_min->SelectedIndex=std_st_min;
    this->cmbx_fltr_DT_hour->SelectedIndex=std_dt_hour;
    if(std_dt_min==0)this->cmbx_fltr_DT_min->SelectedIndex=0;
    if(std_dt_min==15)this->cmbx_fltr_DT_min->SelectedIndex=1;
    if(std_dt_min==30)this->cmbx_fltr_DT_min->SelectedIndex=2;
    if(std_dt_min==45)this->cmbx_fltr_DT_min->SelectedIndex=3;
    if((std_week&0x01)==0) this->cb_sun->Checked=false;
    else                        this->cb_sun->Checked=true;
    if((std_week&0x02)==0) this->cb_mon->Checked=false;
    else                        this->cb_mon->Checked=true;
    if((std_week&0x04)==0) this->cb_Tsu->Checked=false;
    else                        this->cb_Tsu->Checked=true;
    if((std_week&0x08)==0) this->cb_wed->Checked=false;
    else                        this->cb_wed->Checked=true;
    if((std_week&0x10)==0) this->cb_thu->Checked=false;
    else                        this->cb_thu->Checked=true;
    if((std_week&0x20)==0) this->cb_fri->Checked=false;
    else                        this->cb_fri->Checked=true;
    if((std_week&0x40)==0) this->cb_sat->Checked=false;
    else                        this->cb_sat->Checked=true;
}

System::Void FltSchedule_Form::button_Save_Click(System::Object^  sender, System::EventArgs^  e)
{
    //get value from UI
    std_st_hour=this->cmbx_Fltr_ST_hour->SelectedIndex;
    std_st_min=this->cmbx_Fltr_ST_min->SelectedIndex;
    std_dt_hour=this->cmbx_fltr_DT_hour->SelectedIndex;
    if(this->cmbx_fltr_DT_min->SelectedIndex==0) std_dt_min=0;
    if(this->cmbx_fltr_DT_min->SelectedIndex==1) std_dt_min=15;
    if(this->cmbx_fltr_DT_min->SelectedIndex==2) std_dt_min=30;
    if(this->cmbx_fltr_DT_min->SelectedIndex==3) std_dt_min=45;
    std_week=0;
    if(this->cb_sun->Checked==true) std_week=std_week|0x01;
    if(this->cb_mon->Checked==true) std_week=std_week|0x02;
    if(this->cb_Tsu->Checked==true) std_week=std_week|0x04;
    if(this->cb_wed->Checked==true) std_week=std_week|0x08;
    if(this->cb_thu->Checked==true) std_week=std_week|0x10;
    if(this->cb_fri->Checked==true) std_week=std_week|0x20;
    if(this->cb_sat->Checked==true) std_week=std_week|0x40;

    //then,call main-from function (set std filteration schedule)
    m_MainForm->enable_FilterSchedule_btn();
    m_MainForm->set_StdFilterSchedule(
        std_st_hour,
        std_st_min,
        std_dt_hour,
        std_dt_min,
        std_week
    );
    this->Close();
}

System::Void FltSchedule_Form::FltSchedule_Form_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e)
{
    m_MainForm->enable_FilterSchedule_btn();
}