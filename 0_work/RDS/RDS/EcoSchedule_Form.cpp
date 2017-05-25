#include "EcoSchedule_Form.h"

using namespace RDS;
using namespace System;

System::Void EcoSchedule_Form::EcoSchedule_Form_Load(System::Object^  sender, System::EventArgs^  e)
{
    this->cmbx_EC1_ST_hour->SelectedIndex=eco_1_st_hour;
    this->cmbx_EC2_ST_hour->SelectedIndex=eco_2_st_hour;
    this->cmbx_EC3_ST_hour->SelectedIndex=eco_3_st_hour;
    this->cmbx_EC4_ST_hour->SelectedIndex=eco_4_st_hour;
    this->cmbx_EC1_ST_min->SelectedIndex=eco_1_st_min;
    this->cmbx_EC2_ST_min->SelectedIndex=eco_2_st_min;
    this->cmbx_EC3_ST_min->SelectedIndex=eco_3_st_min;
    this->cmbx_EC4_ST_min->SelectedIndex=eco_4_st_min;
    this->cmbx_EC1_DT_hour->SelectedIndex=eco_1_dt_hour;
    this->cmbx_EC2_DT_hour->SelectedIndex=eco_2_dt_hour;
    this->cmbx_EC3_DT_hour->SelectedIndex=eco_3_dt_hour;
    this->cmbx_EC4_DT_hour->SelectedIndex=eco_4_dt_hour;
    this->cmbx_EC1_DT_min->SelectedIndex=eco_1_dt_min/15;
    this->cmbx_EC2_DT_min->SelectedIndex=eco_2_dt_min/15;
    this->cmbx_EC3_DT_min->SelectedIndex=eco_3_dt_min/15;
    this->cmbx_EC4_DT_min->SelectedIndex=eco_4_dt_min/15;
    //
    if((eco_1_week&0x01)==0) this->cb1_sun->Checked=false;
    else                          this->cb1_sun->Checked=true;
    if((eco_1_week&0x02)==0) this->cb1_mon->Checked=false;
    else                          this->cb1_mon->Checked=true;
    if((eco_1_week&0x04)==0) this->cb1_tue->Checked=false;
    else                          this->cb1_tue->Checked=true;
    if((eco_1_week&0x08)==0) this->cb1_wed->Checked=false;
    else                          this->cb1_wed->Checked=true;
    if((eco_1_week&0x10)==0) this->cb1_thu->Checked=false;
    else                          this->cb1_thu->Checked=true;
    if((eco_1_week&0x20)==0) this->cb1_fri->Checked=false;
    else                          this->cb1_fri->Checked=true;
    if((eco_1_week&0x40)==0) this->cb1_sat->Checked=false;
    else                          this->cb1_sat->Checked=true;
    //
    if((eco_2_week&0x01)==0) this->cb2_sun->Checked=false;
    else                          this->cb2_sun->Checked=true;
    if((eco_2_week&0x02)==0) this->cb2_mon->Checked=false;
    else                          this->cb2_mon->Checked=true;
    if((eco_2_week&0x04)==0) this->cb2_tue->Checked=false;
    else                          this->cb2_tue->Checked=true;
    if((eco_2_week&0x08)==0) this->cb2_wed->Checked=false;
    else                          this->cb2_wed->Checked=true;
    if((eco_2_week&0x10)==0) this->cb2_thu->Checked=false;
    else                          this->cb2_thu->Checked=true;
    if((eco_2_week&0x20)==0) this->cb2_fri->Checked=false;
    else                          this->cb2_fri->Checked=true;
    if((eco_2_week&0x40)==0) this->cb2_sat->Checked=false;
    else                          this->cb2_sat->Checked=true;
    //
    if((eco_3_week&0x01)==0) this->cb3_sun->Checked=false;
    else                          this->cb3_sun->Checked=true;
    if((eco_3_week&0x02)==0) this->cb3_mon->Checked=false;
    else                          this->cb3_mon->Checked=true;
    if((eco_3_week&0x04)==0) this->cb3_tue->Checked=false;
    else                          this->cb3_tue->Checked=true;
    if((eco_3_week&0x08)==0) this->cb3_wed->Checked=false;
    else                          this->cb3_wed->Checked=true;
    if((eco_3_week&0x10)==0) this->cb3_thu->Checked=false;
    else                          this->cb3_thu->Checked=true;
    if((eco_3_week&0x20)==0) this->cb3_fri->Checked=false;
    else                          this->cb3_fri->Checked=true;
    if((eco_3_week&0x40)==0) this->cb3_sat->Checked=false;
    else                          this->cb3_sat->Checked=true;
    //
    if((eco_4_week&0x01)==0) this->cb4_sun->Checked=false;
    else                          this->cb4_sun->Checked=true;
    if((eco_4_week&0x02)==0) this->cb4_mon->Checked=false;
    else                          this->cb4_mon->Checked=true;
    if((eco_4_week&0x04)==0) this->cb4_tue->Checked=false;
    else                          this->cb4_tue->Checked=true;
    if((eco_4_week&0x08)==0) this->cb4_wed->Checked=false;
    else                          this->cb4_wed->Checked=true;
    if((eco_4_week&0x10)==0) this->cb4_thu->Checked=false;
    else                          this->cb4_thu->Checked=true;
    if((eco_4_week&0x20)==0) this->cb4_fri->Checked=false;
    else                          this->cb4_fri->Checked=true;
    if((eco_4_week&0x40)==0) this->cb4_sat->Checked=false;
    else                          this->cb4_sat->Checked=true;
}

System::Void EcoSchedule_Form::button_Save_Click(System::Object^  sender, System::EventArgs^  e)
{
    //get value from UI
    eco_1_st_hour=this->cmbx_EC1_ST_hour->SelectedIndex;
    eco_1_st_min=this->cmbx_EC1_ST_min->SelectedIndex;
    eco_1_dt_hour=this->cmbx_EC1_DT_hour->SelectedIndex;
    eco_1_dt_min=this->cmbx_EC1_DT_min->SelectedIndex*15;
    eco_2_st_hour=this->cmbx_EC2_ST_hour->SelectedIndex;
    eco_2_st_min=this->cmbx_EC2_ST_min->SelectedIndex;
    eco_2_dt_hour=this->cmbx_EC2_DT_hour->SelectedIndex;
    eco_2_dt_min=this->cmbx_EC2_DT_min->SelectedIndex*15;
    eco_3_st_hour=this->cmbx_EC3_ST_hour->SelectedIndex;
    eco_3_st_min=this->cmbx_EC3_ST_min->SelectedIndex;
    eco_3_dt_hour=this->cmbx_EC3_DT_hour->SelectedIndex;
    eco_3_dt_min=this->cmbx_EC3_DT_min->SelectedIndex*15;
    eco_4_st_hour=this->cmbx_EC4_ST_hour->SelectedIndex;
    eco_4_st_min=this->cmbx_EC4_ST_min->SelectedIndex;
    eco_4_dt_hour=this->cmbx_EC4_DT_hour->SelectedIndex;
    eco_4_dt_min=this->cmbx_EC4_DT_min->SelectedIndex*15;
    eco_1_week=0;
    if(this->cb1_sun->Checked==true) eco_1_week=eco_1_week|0x01;
    if(this->cb1_mon->Checked==true) eco_1_week=eco_1_week|0x02;
    if(this->cb1_tue->Checked==true) eco_1_week=eco_1_week|0x04;
    if(this->cb1_wed->Checked==true) eco_1_week=eco_1_week|0x08;
    if(this->cb1_thu->Checked==true) eco_1_week=eco_1_week|0x10;
    if(this->cb1_fri->Checked==true) eco_1_week=eco_1_week|0x20;
    if(this->cb1_sat->Checked==true) eco_1_week=eco_1_week|0x40;
    eco_2_week=0;
    if(this->cb2_sun->Checked==true) eco_2_week=eco_2_week|0x01;
    if(this->cb2_mon->Checked==true) eco_2_week=eco_2_week|0x02;
    if(this->cb2_tue->Checked==true) eco_2_week=eco_2_week|0x04;
    if(this->cb2_wed->Checked==true) eco_2_week=eco_2_week|0x08;
    if(this->cb2_thu->Checked==true) eco_2_week=eco_2_week|0x10;
    if(this->cb2_fri->Checked==true) eco_2_week=eco_2_week|0x20;
    if(this->cb2_sat->Checked==true) eco_2_week=eco_2_week|0x40;
    eco_3_week=0;
    if(this->cb3_sun->Checked==true) eco_3_week=eco_3_week|0x01;
    if(this->cb3_mon->Checked==true) eco_3_week=eco_3_week|0x02;
    if(this->cb3_tue->Checked==true) eco_3_week=eco_3_week|0x04;
    if(this->cb3_wed->Checked==true) eco_3_week=eco_3_week|0x08;
    if(this->cb3_thu->Checked==true) eco_3_week=eco_3_week|0x10;
    if(this->cb3_fri->Checked==true) eco_3_week=eco_3_week|0x20;
    if(this->cb3_sat->Checked==true) eco_3_week=eco_3_week|0x40;
    eco_4_week=0;
    if(this->cb4_sun->Checked==true) eco_4_week=eco_4_week|0x01;
    if(this->cb4_mon->Checked==true) eco_4_week=eco_4_week|0x02;
    if(this->cb4_tue->Checked==true) eco_4_week=eco_4_week|0x04;
    if(this->cb4_wed->Checked==true) eco_4_week=eco_4_week|0x08;
    if(this->cb4_thu->Checked==true) eco_4_week=eco_4_week|0x10;
    if(this->cb4_fri->Checked==true) eco_4_week=eco_4_week|0x20;
    if(this->cb4_sat->Checked==true) eco_4_week=eco_4_week|0x40;
    //then,call main-from function (set std filteration schedule)
    m_MainForm->enable_FilterSchedule_btn();
    m_MainForm->set_EcoFilterSchedule(
        eco_1_st_hour,
        eco_1_st_min,
        eco_1_dt_hour,
        eco_1_dt_min,
        eco_2_st_hour,
        eco_2_st_min,
        eco_2_dt_hour,
        eco_2_dt_min,
        eco_3_st_hour,
        eco_3_st_min,
        eco_3_dt_hour,
        eco_3_dt_min,
        eco_4_st_hour,
        eco_4_st_min,
        eco_4_dt_hour,
        eco_4_dt_min,
        eco_1_week,
        eco_2_week,
        eco_3_week,
        eco_4_week
    );
    this->Close();
}

System::Void EcoSchedule_Form::EcoSchedule_Form_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e)
{
    m_MainForm->enable_FilterSchedule_btn();
}