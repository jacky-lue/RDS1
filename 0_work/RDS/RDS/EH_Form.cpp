#include "EH_Form.h"

#include "ErrMsg.h"
extern struct err_History_record SPA_ERR_HIST_TABLE[RECORDS_IN_ERROR_HISTORY];
extern char* eMSG_Table[2][MAX_INDEX_OF_ERR_TABLE];

using namespace RDS;
using namespace System;

System::Void EH_Form::EH_Form_Load(System::Object^  sender, System::EventArgs^  e)
{
    //(1) build 50 record datatable
    unsigned int index_R;
    String^ err_Code;
    String^ err_StartTime;
    String^ err_EndTime;
    String^ err_HiLimit_Temp;
    String^ err_Water_temp;
    String^ err_PCBA_Temp;
    Boolean err_P1_Lo;
    Boolean err_P1_Hi;
    Boolean err_P2_Lo;
    Boolean err_P2_Hi;
    Boolean err_P3_Lo;
    Boolean err_P3_Hi;
    Boolean err_Blower;
    Boolean err_Circ;
    Boolean err_UV;
    Boolean err_Heater;
    Boolean err_Ozon;

    for(index_R=0; index_R<m_MainForm->RdEEP_total_records; index_R++)
    {
        //read from global variable
        err_Code=gcnew String(eMSG_Table[this->ECset][SPA_ERR_HIST_TABLE[index_R].err_Bit]);
        err_StartTime=Convert::ToString(SPA_ERR_HIST_TABLE[index_R].st_year+2000)+"/"
            +Convert::ToString(SPA_ERR_HIST_TABLE[index_R].st_month)+"/"
            +Convert::ToString(SPA_ERR_HIST_TABLE[index_R].st_day)+"_"
            +Convert::ToString(SPA_ERR_HIST_TABLE[index_R].st_hour)+":"
            +Convert::ToString(SPA_ERR_HIST_TABLE[index_R].st_min);
        if(SPA_ERR_HIST_TABLE[index_R].et_min==0xff)
        {
            err_EndTime="-- -- -- -- --";
        }
        else
        {
            err_EndTime=Convert::ToString(SPA_ERR_HIST_TABLE[index_R].et_year+2000)+"/"
                +Convert::ToString(SPA_ERR_HIST_TABLE[index_R].et_month)+"/"
                +Convert::ToString(SPA_ERR_HIST_TABLE[index_R].et_day)+"_"
                +Convert::ToString(SPA_ERR_HIST_TABLE[index_R].et_hour)+":"
                +Convert::ToString(SPA_ERR_HIST_TABLE[index_R].et_min);
        }
        err_HiLimit_Temp=Convert::ToString(SPA_ERR_HIST_TABLE[index_R].hili_temp);
        err_Water_temp=Convert::ToString(SPA_ERR_HIST_TABLE[index_R].watr_temp);
        err_PCBA_Temp=Convert::ToString(SPA_ERR_HIST_TABLE[index_R].hili_temp);
        if((SPA_ERR_HIST_TABLE[index_R].state_L&0x01)==0x01) err_P1_Lo=true; else err_P1_Lo=false;
        if((SPA_ERR_HIST_TABLE[index_R].state_L&0x02)==0x02) err_P1_Hi=true; else err_P1_Hi=false;
        if((SPA_ERR_HIST_TABLE[index_R].state_L&0x04)==0x04) err_P2_Lo=true; else err_P2_Lo=false;
        if((SPA_ERR_HIST_TABLE[index_R].state_L&0x08)==0x08) err_P2_Hi=true; else err_P2_Hi=false;
        if((SPA_ERR_HIST_TABLE[index_R].state_L&0x10)==0x10) err_P3_Lo=true; else err_P3_Lo=false;
        if((SPA_ERR_HIST_TABLE[index_R].state_L&0x20)==0x20) err_P3_Hi=true; else err_P3_Hi=false;
        if((SPA_ERR_HIST_TABLE[index_R].state_L&0x40)==0x40) err_Blower=true; else err_Blower=false;
        if((SPA_ERR_HIST_TABLE[index_R].state_L&0x80)==0x80) err_Circ=true; else err_Circ=false;
        if((SPA_ERR_HIST_TABLE[index_R].state_H&0x01)==0x01) err_UV=true; else err_UV=false;
        if((SPA_ERR_HIST_TABLE[index_R].state_H&0x02)==0x02) err_Heater=true; else err_Heater=false;
        if((SPA_ERR_HIST_TABLE[index_R].state_H&0x04)==0x04) err_Ozon=true; else err_Ozon=false;
        //add row to DataGridView
        dataGridView_EH->Rows->Add(
            index_R+1,
            err_Code,
            err_StartTime,
            err_EndTime,
            err_HiLimit_Temp,
            err_Water_temp,
            err_PCBA_Temp,
            err_P1_Lo,
            err_P1_Hi,
            err_P2_Lo,
            err_P2_Hi,
            err_P3_Lo,
            err_P3_Hi,
            err_Blower,
            err_Circ,
            err_UV,
            err_Heater,
            err_Ozon);
    }
}

System::Void EH_Form::EH_Form_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e)
{
    m_MainForm->enable_ErrHistory_btn();
}