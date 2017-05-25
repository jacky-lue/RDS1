//project defines
#include "RDS_project.h"

//for VC program all forms
#include "RDS_main_Form.h"

//error message gobal table
#include "ErrMsg.h"

//global variable........
extern struct err_Info SPA_ERR_TABLE[MAX_NUMBER_OF_ERR_CODE];
extern unsigned char AD_all_Cause[AUTO_DIAGNOSIS_MAX_CUASE];
extern unsigned char AD_all_Equip[AUTO_DIAGNOSIS_MAX_EQUIP];
extern struct SpaModel_ADcurrnt SpaModels[MAX_HOT_TUV_MODELS];

//related objects
#include "IOTcommunicator.h"
#include "spa_cmd.h"
#include "SPA.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Threading;
// ----- my main..
using namespace RDS;

//The function body of class RDS_main_Form here --------------------------------------------

//==================//
// checking status  //
//==================//
void  RDS_main_Form::AD_start_status_save()
{
    this->Start_with_Heat=this->iCmd.iSPA.heater_on;
    this->Start_with_UV=this->iCmd.iSPA.uv_on;
    this->Start_with_CIRC=this->iCmd.iSPA.circ_on;
    if(this->Start_with_Heat==true&&this->Start_with_CIRC==true&&this->Start_with_UV==true)
        this->M0_with_HeatCirc=true;
    else this->M0_with_HeatCirc=false;
}
Boolean RDS_main_Form::AD_status_change()
{
    if(this->Start_with_Heat!=this->iCmd.iSPA.heater_on) return true;
    if(this->Start_with_UV!=this->iCmd.iSPA.uv_on) return true;
    if(this->Start_with_CIRC!=this->iCmd.iSPA.circ_on) return true;
    return false;
}

Boolean RDS_main_Form::AD_status_changeM1M2()
{
    if(this->iCmd.iSPA.circ_on==true&&this->iCmd.iSPA.uv_on==true)this->M1M2_with_Circ=true;
    else this->M1M2_with_Circ=false;
    if(this->Start_with_Heat!=this->iCmd.iSPA.heater_on) return true;
    return false;
}

//===============//
//    Main AD    //
//===============//
void RDS_main_Form::AD_Diagnosis()
{
    Boolean chk_rtn;
    int adc_value;
    array<unsigned char>^ buffer;
    DateTime dt=DateTime::Now;
    unsigned int weekday;
    String^ CurYear=dt.ToString("yy", DateTimeFormatInfo::InvariantInfo);
    String^ CurMont=dt.ToString("MM", DateTimeFormatInfo::InvariantInfo);
    String^ Cur_Day=dt.ToString("dd", DateTimeFormatInfo::InvariantInfo);
    String^ CurHour=dt.ToString("HH", DateTimeFormatInfo::InvariantInfo);
    String^ Cur_min=dt.ToString("mm", DateTimeFormatInfo::InvariantInfo);
    if(dt.DayOfWeek==DayOfWeek::Sunday) weekday=1;
    if(dt.DayOfWeek==DayOfWeek::Monday) weekday=2;
    if(dt.DayOfWeek==DayOfWeek::Tuesday) weekday=3;
    if(dt.DayOfWeek==DayOfWeek::Wednesday) weekday=4;
    if(dt.DayOfWeek==DayOfWeek::Thursday) weekday=5;
    if(dt.DayOfWeek==DayOfWeek::Friday) weekday=6;
    if(dt.DayOfWeek==DayOfWeek::Saturday) weekday=7;

    //update state
    Current_AD_State=Next_AD_State;
    AD_wait_count++;

    //process by state -------------------------------
    switch(Current_AD_State)
    {
    case S_idel:
        if(DEBUGGING_USEAGE==1)MsgMain("---- S_idel ---");
        if(this->doing_AutoD==true)
        {
            AD_start_status_save();  //remember status for futire checking

            //Next_AD_State = S_setDT0; AD_wait_count = 0;
            //20161125, we chage to broadcasting block-out/clean cycle, so dont need to set time!!!
            Next_AD_State=S_mode; AD_wait_count=0;
            resend_31=0;
            //disable some buttons
            this->button_Err_Msg->Enabled=false;
            this->button_Filtration_sch->Enabled=false;
            this->button_PF->Enabled=false;
            this->button_SF->Enabled=false;
            this->button_Date_Time->Enabled=false;
            this->button_Func_Lock->Enabled=false;
            this->button_Pump_Lock->Enabled=false;
            this->button_Panel_Lock->Enabled=false;
            this->button_unlock->Enabled=false;
            this->button_T_Lock->Enabled=false;
            this->button_mode->Enabled=false;
            this->button_P1_Hi->Enabled=false;
            this->button_P1_Lo->Enabled=false;
            this->button_P2_Hi->Enabled=false;
            this->button_P2_Lo->Enabled=false;
            this->button_P3_Hi->Enabled=false;
            this->button_P3_Lo->Enabled=false;
            this->button_Blower_OnOff->Enabled=false;
            this->textBox_Set_T->Enabled=false;
        }
        break;
    case S_setDT0:
        if(DEBUGGING_USEAGE==1)MsgMain("S_setDT0");
        //setting Date & Time as today 23:00
        if(resend_31<COMMAND_RESEND_TIMES)
        {
            Array::Resize(buffer, 9);
            buffer[0]=NEW_2015_PROTOCOL_CODE;
            buffer[1]=0x21; //Command  -- Set Date & Time (23:00)
            buffer[2]=Convert::ToInt32(CurYear, 10);
            buffer[3]=Convert::ToInt32(CurMont, 10);
            buffer[4]=Convert::ToInt32(Cur_Day, 10);
            buffer[5]=weekday;
            buffer[6]=RDS_AD_WORKING_DATE_TIME_H;  //hour
            buffer[7]=RDS_AD_WORKING_DATE_TIME_M;  //min
            buffer[8]=0;  //set default seconds
            this->iCmd.SendCmdPacket(buffer);
            SetWaitingCmd(0x31);
            //
            this->set_ADcmd31=true;
        }
        else
        {
            //time-out Error!!!
            this->set_ADcmd31=false;
            MessageBox::Show(MSG_MAINAD_SET_TIME_CDM_TIMEOUT, "TimeOut AD01",
                MessageBoxButtons::OK,
                MessageBoxIcon::Information);
        }
        Next_AD_State=C_setDT0; AD_wait_count=0;
        break;
    case C_setDT0:
        if(AD_wait_count>RDS_AUTO_DIAGNOSIS_WAIT_F)
        {
            if(DEBUGGING_USEAGE==1)MsgMain("C_setDT0");
            if(this->set_ADcmd31==true)
            { //not done, go back
                Next_AD_State=S_setDT0; AD_wait_count=0;
                resend_31++;
            }
            else
            {
                //okay, go next
                Next_AD_State=S_mode; AD_wait_count=0;
            }
        }
        break;
    case S_mode:
        if(DEBUGGING_USEAGE==1)MsgMain("S_mode");
        //save
        this->starting_setT=this->iCmd.iSPA.TEMPADC_To_TEMP_F(this->iCmd.iSPA.set_Adc);
        this->starting_lock=this->iCmd.iSPA.lock_value;
        this->starting_ECO_on=this->iCmd.iSPA.ecoModeOn;
        //set
        this->iCmd.set_unlock();
        this->iCmd.set_ECO_OFF();
        this->iCmd.SendSingleCmdPacket(0x38); //get ECO mode
        Next_AD_State=C_mode; AD_wait_count=0;
        break;
    case C_mode:
        if(AD_wait_count>RDS_AUTO_DIAGNOSIS_WAIT_M)
        {
            if(DEBUGGING_USEAGE==1)MsgMain("C_mode");
            if(this->iCmd.iSPA.ecoModeOn!=false||this->iCmd.iSPA.unlock!=true)
            {
                //go back
                Next_AD_State=S_mode; AD_wait_count=0;
            }
            else
            {
                if(DISP_AUTO_DIAGNOSIS_HINT==1)MsgMain2(MSG_MAINAD_AD_HINT_SAVE_SETTING);
                if(this->iCmd.iSPA.is_HighEnd_Fsch==true)
                {
                    Next_AD_State=S_saveFsch; AD_wait_count=0;
                }
                else
                {
                    Next_AD_State=S_saveSF; AD_wait_count=0;
                }
            }
        }
        break;
    case S_saveSF:
        if(DEBUGGING_USEAGE==1)MsgMain("S_saveSF");
        //read SFx setting
        this->iCmd.SendSingleCmdPacket(0x36); //get SF filter schedule
        this->starting_AD_cmd36=true;
        SetWaitingCmd(0x36);
        Next_AD_State=C_saveSF; AD_wait_count=0;
        break;
    case C_saveSF:
        if(AD_wait_count>RDS_AUTO_DIAGNOSIS_WAIT_C)
        {
            if(DEBUGGING_USEAGE==1)MsgMain("C_saveSF");
            if(this->starting_AD_cmd36==true)
            { //not done, go back
                Next_AD_State=S_saveSF; AD_wait_count=0;
            }
            else
            {
                //okay, go next
                if(DISP_AUTO_DIAGNOSIS_HINT==1)MsgMain2(MSG_MAINAD_AD_HINT_SAVE_F_SCHEDULE);
                Next_AD_State=S_setSF; AD_wait_count=0;
                resend_36=0;
            }
        }
        break;
    case S_setSF:
        if(DEBUGGING_USEAGE==1)MsgMain("S_setSF ");
        if(resend_36<COMMAND_RESEND_TIMES)
        {
            //Set std mode filter schedule AS RDS use (let SPA in not Circ mode)
            Array::Resize(buffer, 3);
            buffer[0]=NEW_2015_PROTOCOL_CODE;
            buffer[1]=0x26; //Command  -- Set SF
            buffer[2]=0; //SF0 !!!!!!!!!!!!!!
            this->iCmd.SendCmdPacket(buffer);
            SetWaitingCmd(0x36);
            //
            this->set_ADcmd36=true;
        }
        else
        {
            //time-out Error!!!
            this->set_ADcmd36=false;
            MessageBox::Show(MSG_MAINAD_SET_SF0_CDM_TIMEOUT, "TimeOut",
                MessageBoxButtons::OK,
                MessageBoxIcon::Information);
        }
        Next_AD_State=C_setSF; AD_wait_count=0;
        break;
    case C_setSF:
        if(AD_wait_count>RDS_AUTO_DIAGNOSIS_WAIT_C)
        {
            if(DEBUGGING_USEAGE==1)MsgMain("C_setSF");
            if(this->set_ADcmd36==true)
            { //not done, go back
                Next_AD_State=S_setSF; AD_wait_count=0;
                resend_36++;
            }
            else
            {
                //okay, go next
                Next_AD_State=S_savePF; AD_wait_count=0;
            }
        }
        break;
    case S_savePF:
        if(DEBUGGING_USEAGE==1)MsgMain("S_savePF");
        //read PF setting
        this->iCmd.SendSingleCmdPacket(0x35); //get PF filter schedule
        this->starting_AD_cmd35=true;
        SetWaitingCmd(0x35);
        Next_AD_State=C_savePF; AD_wait_count=0;
        break;
    case C_savePF:
        if(AD_wait_count>RDS_AUTO_DIAGNOSIS_WAIT_C)
        {
            if(DEBUGGING_USEAGE==1)MsgMain("C_savePF");
            if(this->starting_AD_cmd35==true)
            { //not done, go back
                Next_AD_State=S_savePF; AD_wait_count=0;
            }
            else
            {
                //okay, go next
                Next_AD_State=S_setPF; AD_wait_count=0;
                resend_35=0;
            }
        }
        break;
    case S_setPF:
        if(DEBUGGING_USEAGE==1)MsgMain("S_setPF");
        if(resend_35<COMMAND_RESEND_TIMES)
        {
            //Set std mode filter schedule AS RDS use (let SPA in not Circ mode)
            Array::Resize(buffer, 8);
            buffer[0]=NEW_2015_PROTOCOL_CODE;
            buffer[1]=0x25; //Command  -- Set PF
            buffer[2]=0x80; //programmable PF
            buffer[3]=RDS_AD_WORK_STD_PF_FSCH_ST_H; // pf_st_hour;
            buffer[4]=RDS_AD_WORK_STD_PF_FSCH_ST_M; // pf_st_min;
            buffer[5]=RDS_AD_WORK_STD_PF_FSCH_DT_H; // pf_dt_hour; /////// 0: means trun off !!!!!!
            buffer[6]=RDS_AD_WORK_STD_PF_FSCH_DT_M; // pf_dt_min;
            buffer[7]=0x7f;
            this->iCmd.SendCmdPacket(buffer);
            SetWaitingCmd(0x35);
            //
            this->set_ADcmd35=true;
        }
        else
        {
            //time-out Error!!!
            this->set_ADcmd35=false;
            MessageBox::Show(MSG_MAINAD_SET_PFOFF_CDM_TIMEOUT, "TimeOut",
                MessageBoxButtons::OK,
                MessageBoxIcon::Information);
        }
        Next_AD_State=C_setPF; AD_wait_count=0;
        break;
    case C_setPF:
        if(AD_wait_count>RDS_AUTO_DIAGNOSIS_WAIT_F)
        {
            if(DEBUGGING_USEAGE==1)MsgMain("C_setPF");
            if(this->set_ADcmd35==true)
            { //not done, go back
                Next_AD_State=S_setPF; AD_wait_count=0;
                resend_35++;
            }
            else
            {
                //okay, go next
                if(this->iCmd.iSPA.heater_on==false&&this->iCmd.iSPA.circ_on==false&&this->iCmd.iSPA.uv_on==false)
                {
                    this->has_M0_HC=false;
                    this->has_M0_C=false;
                    if(DISP_AUTO_DIAGNOSIS_HINT==1)MsgMain2(MSG_MAINAD_AD_HINT_TRUN_OFF_ALL);
                    Next_AD_State=S0_all_off; AD_wait_count=0;
                }
                else
                {
                    if(this->iCmd.iSPA.heater_on==true&&this->iCmd.iSPA.circ_on==true&&this->iCmd.iSPA.uv_on==true)
                    {
                        this->has_M0_HC=true;
                        this->has_M0_C=true;
                        if(DISP_AUTO_DIAGNOSIS_HINT==1)MsgMain2(MSG_MAINAD_AD_HINT_TRUN_OFF_ALL_HC);
                        Next_AD_State=S_HC_all_off; AD_wait_count=0;
                    }
                    else
                    {
                        //currently, only possible is: Heater=Off, Circ=On when pump1 on...
                        if(DISP_AUTO_DIAGNOSIS_HINT==1)MsgMain2(MSG_MAINAD_AD_HINT_TRUN_OFF_ALL_C);
                        this->has_M0_HC=false;
                        this->has_M0_C=false;
                        Next_AD_State=S0_all_off; AD_wait_count=0;
                    }
                }//end-if (go next)
            }
        }
        break;
    case S_saveFsch:
        if(DEBUGGING_USEAGE==1)MsgMain("S_saveFsch");
        //read std mode filter schedule...
        this->iCmd.SendSingleCmdPacket(0x32); //get std filter schedule
        this->starting_AD_cmd32=true;
        SetWaitingCmd(0x32);
        //
        Next_AD_State=C_saveFsch; AD_wait_count=0;
        break;
    case C_saveFsch:
        if(AD_wait_count>RDS_AUTO_DIAGNOSIS_WAIT_C)
        {
            if(DEBUGGING_USEAGE==1)MsgMain("C_saveFsch");
            if(this->starting_AD_cmd32==true)
            { //not done, go back
                Next_AD_State=S_saveFsch; AD_wait_count=0;
            }
            else
            {
                //okay, go next
                if(DISP_AUTO_DIAGNOSIS_HINT==1)MsgMain2(MSG_MAINAD_AD_HINT_SAVE_F_SCHEDULE);
                Next_AD_State=S_setFsch; AD_wait_count=0; resend_32=0;
            }
        }
        break;
    case S_setFsch:
        if(DEBUGGING_USEAGE==1)MsgMain("S_setFsch");
        if(resend_32<COMMAND_RESEND_TIMES)
        {
            //Set std mode filter schedule AS RDS use (let SPA in not Circ mode)
            Array::Resize(buffer, 8);
            buffer[0]=NEW_2015_PROTOCOL_CODE;
            buffer[1]=0x22; //Command  -- Set std filter schedule
            buffer[2]=1; //group
            buffer[3]=RDS_AD_WORK_STD_PF_FSCH_ST_H; //std_st_hour
            buffer[4]=RDS_AD_WORK_STD_PF_FSCH_ST_M; //std_st_min
            buffer[5]=RDS_AD_WORK_STD_PF_FSCH_DT_H; //std_dt_hour
            buffer[6]=RDS_AD_WORK_STD_PF_FSCH_DT_M; //std_dt_min
            buffer[7]=0x7F; //std_week
            this->iCmd.SendCmdPacket(buffer);
            SetWaitingCmd(0x32);
            //
            this->set_ADcmd32=true;
        }
        else
        {
            //time-out Error!!!
            this->set_ADcmd32=false;
            MessageBox::Show(MSG_MAINAD_TEMP_F_SCHEDULE_TIMEOUT, "TimeOut",
                MessageBoxButtons::OK,
                MessageBoxIcon::Information);
        }
        if(DEBUGGING_USEAGE==1)MsgMain("to C_setFsch");
        Next_AD_State=C_setFsch; AD_wait_count=0;
        break;
    case C_setFsch:
        if(AD_wait_count>RDS_AUTO_DIAGNOSIS_WAIT_F)
        {
            if(this->set_ADcmd32==true)
            { //not done, go back
                if(DEBUGGING_USEAGE==1)MsgMain("to S_setFsch ");
                Next_AD_State=S_setFsch; AD_wait_count=0;
                resend_32++;
            }
            else
            {
                //okay, go next
                if(this->iCmd.iSPA.heater_on==false&&this->iCmd.iSPA.circ_on==false&&this->iCmd.iSPA.uv_on==false)
                {
                    this->has_M0_HC=false;
                    this->has_M0_C=false;
                    if(DISP_AUTO_DIAGNOSIS_HINT==1)MsgMain2(MSG_MAINAD_AD_HINT_TRUN_OFF_ALL);
                    Next_AD_State=S0_all_off; AD_wait_count=0;
                }
                else
                {
                    if(this->iCmd.iSPA.heater_on==true&&this->iCmd.iSPA.circ_on==true&&this->iCmd.iSPA.uv_on==true)
                    {
                        this->has_M0_HC=true;
                        this->has_M0_C=true;
                        if(DISP_AUTO_DIAGNOSIS_HINT==1)MsgMain2(MSG_MAINAD_AD_HINT_TRUN_OFF_ALL_HC);
                        Next_AD_State=S_HC_all_off; AD_wait_count=0;
                    }
                    else
                    {
                        //currently, only possible is: Heater=Off, Circ=On when pump1 on...
                        if(DISP_AUTO_DIAGNOSIS_HINT==1)MsgMain2(MSG_MAINAD_AD_HINT_TRUN_OFF_ALL_C);
                        this->has_M0_HC=false;
                        this->has_M0_C=false;
                        Next_AD_State=S0_all_off; AD_wait_count=0;
                    }
                }//end-if (go next)
            }
        }
        break;
    case S_HC_all_off:
        if(DEBUGGING_USEAGE==1)MsgMain("S_HC_all_off");
        //close all pump when Heat+Circ on
        if(this->iCmd.iSPA.p1_hi_on||this->iCmd.iSPA.p1_lo_on)
        {
            this->iCmd.set_p1_OFF();
        }
        if(this->iCmd.iSPA.p2_hi_on||this->iCmd.iSPA.p2_lo_on)
        {
            this->iCmd.set_p2_OFF();
        }
        if(this->iCmd.iSPA.p3_hi_on||this->iCmd.iSPA.p3_lo_on)
        {
            this->iCmd.set_p3_OFF();
        }
        if(this->iCmd.iSPA.blower_on)
        {
            this->iCmd.set_blower_OFF();
        }
        Next_AD_State=C_HC_all_off; AD_wait_count=0;
        break;
    case C_HC_all_off:     //close all pump when Heater+Cire on
        if(AD_wait_count>RDS_AUTO_DIAGNOSIS_WAIT_C)
        {
            if(DEBUGGING_USEAGE==1)MsgMain("C_HC_all_off");
            if(this->iCmd.iSPA.p1_hi_on||this->iCmd.iSPA.p1_lo_on
                ||this->iCmd.iSPA.p2_hi_on||this->iCmd.iSPA.p2_lo_on
                ||this->iCmd.iSPA.p3_hi_on||this->iCmd.iSPA.p3_lo_on
                ||this->iCmd.iSPA.blower_on)
            {
                //not close all okay, re-try them
                Next_AD_State=S_HC_all_off; AD_wait_count=0;
            }
            else
            {
                Next_AD_State=M_HC_all_off; AD_wait_count=0;
            }
        }
        break;
    case M_HC_all_off:
        if(AD_wait_count>RDS_AUTO_DIAGNOSIS_WAIT_M)
        {
            if(DEBUGGING_USEAGE==1)MsgMain("M_HC_all_off, iCmd.iSPA.cur_Adc_0 ="+this->iCmd.iSPA.cur_Adc_0);
            this->has_M0_HC=true;
            M0_HC_current=this->iCmd.iSPA.CurrentADC_to_Amp(this->iCmd.iSPA.cur_Adc_4);
            this->textBox_Heater_Amp->Text=""+M0_HC_current;
            AD_judge_M0_HC();

            //next.....
            //get current water temperature
            this->curWaterT=this->iCmd.iSPA.TEMPADC_To_TEMP_F(this->iCmd.iSPA.cur_Adc_0);
            if(this->curWaterT<SET_TEMP_F_MIN+RDS_AD_INC_DEC_TEMPATURE_F)
            {
                this->TooCold_HeatOn=true;   //water too cold and keep heater on
                this->has_M0_C=false;
                Next_AD_State=S0_all_off; AD_wait_count=0;
            }
            else
            {
                this->TooCold_HeatOn=false;
                if(DISP_AUTO_DIAGNOSIS_HINT==1)MsgMain2(MSG_MAINAD_AD_HINT_TURN_OFF_HEATER);
                Next_AD_State=S_HeatOff; AD_wait_count=0;
            }
        }
        break;
    case S_HeatOff:
        if(DEBUGGING_USEAGE==1)MsgMain("S_HeatOff, curWaterT="+this->curWaterT);
        //let SetT lower 2 degree_F than current water temperature
        adc_value=this->iCmd.iSPA.TEMP_F_To_TEMPADC(this->curWaterT-RDS_AD_INC_DEC_TEMPATURE_F);
        Array::Resize(buffer, 4);
        buffer[0]=NEW_2015_PROTOCOL_CODE;
        buffer[1]=0x20; //Command  -- Set Temperature ADC
        buffer[2]=(adc_value>>8)&0x000000FF;
        buffer[3]=adc_value&0x000000FF;
        this->iCmd.SendCmdPacket(buffer);
        SetWaitingCmd(0x30);
        //next
        Next_AD_State=C_HeatOff; AD_wait_count=0;
        break;
    case C_HeatOff:
        if(AD_wait_count>RDS_AUTO_DIAGNOSIS_WAIT_C)
        {
            if(DEBUGGING_USEAGE==1)MsgMain("C_HeatOff");
            if(this->iCmd.iSPA.heater_on==true)
            {
                //not close all okay, re-try them
                Next_AD_State=S_HeatOff; AD_wait_count=0;
            }
            else
            {
                //2016/03/03, after heater off, it should be has 1 min before circ off.
                Next_AD_State=M_HeatOff_CircOnly; AD_wait_count=0;
            }
        }
        break;
    case M_HeatOff_CircOnly:
        //measure M0_C_current!
        if(AD_wait_count>RDS_AUTO_DIAGNOSIS_WAIT_M_CR)
        {
            if(DEBUGGING_USEAGE==1)MsgMain("M_HeatOff_CircOnly");
            this->has_M0_C=true;
            M0_C_current=this->iCmd.iSPA.CurrentADC_to_Amp(this->iCmd.iSPA.cur_Adc_4);
            this->textBox_Heater_Amp->Text=""+M0_HC_current+", "+M0_C_current;
            AD_judge_M0_C();
            //next
            if(DISP_AUTO_DIAGNOSIS_HINT==1)MsgMain2(MSG_MAINAD_AD_HINT_WAIT_CIRC_OFF);
            Next_AD_State=W_CircOff; AD_wait_count=0;
        }
        break;
    case W_CircOff:
        if(AD_wait_count>RDS_AUTO_DIAGNOSIS_WAIT_M_WCR)
        {
            if(DEBUGGING_USEAGE==1)MsgMain("W_CircOff");
            if(this->iCmd.iSPA.circ_on==false)
            {
                Next_AD_State=S0_all_off; AD_wait_count=0; //go next
            }
            else
            {
                Next_AD_State=W_CircOff; AD_wait_count=0;  //keep waiting
            }
        }
        break;
    case S0_all_off:
        if(DEBUGGING_USEAGE==1)MsgMain("S0_all_off");
        //close all pump
        if(this->iCmd.iSPA.p1_hi_on||this->iCmd.iSPA.p1_lo_on)
        {
            this->iCmd.set_p1_OFF();
        }
        if(this->iCmd.iSPA.p2_hi_on||this->iCmd.iSPA.p2_lo_on)
        {
            this->iCmd.set_p2_OFF();
        }
        if(this->iCmd.iSPA.p3_hi_on||this->iCmd.iSPA.p3_lo_on)
        {
            this->iCmd.set_p3_OFF();
        }
        if(this->iCmd.iSPA.blower_on)
        {
            this->iCmd.set_blower_OFF();
        }
        AD_start_status_save();  //remember status for futire checking
        Next_AD_State=C0_all_off; AD_wait_count=0;
        break;
    case C0_all_off:     //close all pump
        if(AD_wait_count>RDS_AUTO_DIAGNOSIS_WAIT_C)
        {
            if(DEBUGGING_USEAGE==1)MsgMain("C0_all_off");
            if(this->iCmd.iSPA.p1_hi_on||this->iCmd.iSPA.p1_lo_on
                ||this->iCmd.iSPA.p2_hi_on||this->iCmd.iSPA.p2_lo_on
                ||this->iCmd.iSPA.p3_hi_on||this->iCmd.iSPA.p3_lo_on
                ||this->iCmd.iSPA.blower_on)
            {
                //not close all okay, re-try them
                Next_AD_State=S0_all_off; AD_wait_count=0;
            }
            else
            {
                Next_AD_State=M0_all_off; AD_wait_count=0;
            }
        }
        break;
    case M0_all_off:
        if(AD_wait_count>RDS_AUTO_DIAGNOSIS_WAIT_M)
        {
            if(DEBUGGING_USEAGE==1)MsgMain("M0_all_off");
            M0_current=this->iCmd.iSPA.CurrentADC_to_Amp(this->iCmd.iSPA.cur_Adc_4);;
            this->textBox_Heater_Amp->Text=""+M0_current;
            AD_judge_M0();
            //next
            if(this->iCmd.iSPA.p1_mode==0)
            {
                if(this->iCmd.iSPA.p2_mode==0)
                {
                    if(this->iCmd.iSPA.p3_mode==0)
                    {
                        if(this->iCmd.iSPA.has_blower==false)
                        {
                            if(DEBUGGING_USEAGE==1)MsgMain("no any pump...");
                            Next_AD_State=S_Over; AD_wait_count=0;
                        }
                        else
                        {
                            Next_AD_State=S7_blower; AD_wait_count=0;
                        }
                    }
                    else
                    {
                        Next_AD_State=S5_P3_hi; AD_wait_count=0;
                    }
                }
                else
                {
                    Next_AD_State=S3_P2_hi;  AD_wait_count=0;
                }
            }
            else
            {
                Next_AD_State=S1_P1_hi; AD_wait_count=0;
            }//if next...
        }
        break;
    case S1_P1_hi:
        if(DEBUGGING_USEAGE==1)MsgMain("S1_P1_hi");
        this->iCmd.set_p1_hi_ON();
        Next_AD_State=C1_P1_hi; AD_wait_count=0;
        break;
    case C1_P1_hi:
        if(AD_wait_count>RDS_AUTO_DIAGNOSIS_WAIT_C)
        {
            if(DEBUGGING_USEAGE==1)MsgMain("C1_P1_hi");
            if(this->iCmd.iSPA.p1_hi_on)
            {
                if((!this->iCmd.iSPA.blower_on)
                    &&(!this->iCmd.iSPA.p2_hi_on)&&(!this->iCmd.iSPA.p2_lo_on)
                    &&(!this->iCmd.iSPA.p3_hi_on)&&(!this->iCmd.iSPA.p3_lo_on))
                {
                    Next_AD_State=M1_P1_hi; AD_wait_count=0;
                }
                else
                {
                    Next_AD_State=S0_all_off; AD_wait_count=0;
                }
            }
            else
            {
                Next_AD_State=S1_P1_hi; AD_wait_count=0;
            }
        }
        break;
    case M1_P1_hi:
        if(AD_wait_count>RDS_AUTO_DIAGNOSIS_WAIT_M)
        {
            if(DEBUGGING_USEAGE==1)MsgMain("M1_P1_hi");
            M1_current=this->iCmd.iSPA.CurrentADC_to_Amp(this->iCmd.iSPA.cur_Adc_4);
            //
            this->textBox_P1_Amp->Text=""+M1_current;
            AD_judge_M1();
            this->iCmd.set_p1_OFF();
            Next_AD_State=M1off; AD_wait_count=0;
        }
        break;
    case M1off:
        if(DEBUGGING_USEAGE==1)MsgMain("M1off");
        this->iCmd.set_p1_OFF();
        Next_AD_State=M1AC; AD_wait_count=0;
        break;
    case M1AC:
        if(AD_wait_count>RDS_AUTO_DIAGNOSIS_WAIT_C)
        {
            if(DEBUGGING_USEAGE==1)MsgMain("M1AC");
            //next
            chk_rtn=this->AD_status_changeM1M2();
            if(chk_rtn==true)
            { //heater change...
                Next_AD_State=S0_all_off; AD_wait_count=0;
                if(DEBUGGING_USEAGE==1)MsgMain("AD status change");
            }
            else
            {
                if(this->iCmd.iSPA.p1_hi_on)
                {
                    Next_AD_State=M1off; AD_wait_count=0;
                }
                else
                {
                    if(this->iCmd.iSPA.p1_mode==2)
                    {
                        Next_AD_State=S2_P1_lo; AD_wait_count=0;
                    }
                    else
                    {
                        if(this->iCmd.iSPA.p2_mode==0)
                        {
                            if(this->iCmd.iSPA.p3_mode==0)
                            {
                                if(this->iCmd.iSPA.has_blower==false)
                                {
                                    if(this->has_M0_HC==false&&this->TooCold_HeatOn==false&&this->Start_with_Heat==false&&this->Start_with_CIRC==false)
                                    {
                                        if(DISP_AUTO_DIAGNOSIS_HINT==1)MsgMain2(MSG_MAINAD_AD_HINT_WAIT_HEATER_ON);
                                        Next_AD_State=S_HeatOn; AD_wait_count=0;
                                    }
                                    else
                                    {
                                        if(DISP_AUTO_DIAGNOSIS_HINT==1)MsgMain2(MSG_MAINAD_AD_HINT_RESTORE_SETTING);
                                        Next_AD_State=S_Over; AD_wait_count=0;
                                    }
                                }
                                else
                                {
                                    Next_AD_State=S7_blower; AD_wait_count=0;
                                }
                            }
                            else
                            {
                                Next_AD_State=S5_P3_hi; AD_wait_count=0;
                            }
                        }
                        else
                        {
                            Next_AD_State=S3_P2_hi;  AD_wait_count=0;
                        }
                    }
                }
            }
        }
        break;
    case S2_P1_lo:
        if(DEBUGGING_USEAGE==1)MsgMain("S2_P1_lo");
        this->iCmd.set_p1_lo_ON();
        Next_AD_State=C2_P1_lo; AD_wait_count=0;
        break;
    case C2_P1_lo:
        if(AD_wait_count>RDS_AUTO_DIAGNOSIS_WAIT_C)
        {
            if(DEBUGGING_USEAGE==1)MsgMain("C2_P1_lo");
            if(this->iCmd.iSPA.p1_lo_on)
            {
                if((!this->iCmd.iSPA.blower_on)
                    &&(!this->iCmd.iSPA.p2_hi_on)&&(!this->iCmd.iSPA.p2_lo_on)
                    &&(!this->iCmd.iSPA.p3_hi_on)&&(!this->iCmd.iSPA.p3_lo_on))
                {
                    Next_AD_State=M2_P1_lo; AD_wait_count=0;
                }
                else
                {
                    Next_AD_State=S0_all_off; AD_wait_count=0;
                }
            }
            else
            {
                Next_AD_State=S2_P1_lo; AD_wait_count=0;
            }
        }
        break;
    case M2_P1_lo:
        if(AD_wait_count>RDS_AUTO_DIAGNOSIS_WAIT_M)
        {
            if(DEBUGGING_USEAGE==1)MsgMain("M2_P1_lo");
            M2_current=this->iCmd.iSPA.CurrentADC_to_Amp(this->iCmd.iSPA.cur_Adc_4);
            //M2_current = M2_current - M0_current;
            this->textBox_P1_Amp->Text=""+M1_current+", "+M2_current;
            AD_judge_M2();
            Next_AD_State=M2off; AD_wait_count=0;
        }
        break;
    case M2off:
        if(DEBUGGING_USEAGE==1)MsgMain("M2off");
        this->iCmd.set_p1_OFF();
        Next_AD_State=M2AC; AD_wait_count=0;
        break;
    case M2AC:
        if(AD_wait_count>RDS_AUTO_DIAGNOSIS_WAIT_C)
        {
            if(DEBUGGING_USEAGE==1)MsgMain("M2AC");
            //next
            chk_rtn=this->AD_status_changeM1M2();
            if(chk_rtn==true)
            {
                Next_AD_State=S0_all_off; AD_wait_count=0;
                if(DEBUGGING_USEAGE==1)MsgMain("AD status change");
            }
            else
            {
                if(this->iCmd.iSPA.p1_lo_on)
                {
                    Next_AD_State=M2off; AD_wait_count=0;
                }
                else
                {
                    if(this->iCmd.iSPA.p2_mode==0)
                    {
                        if(this->iCmd.iSPA.p3_mode==0)
                        {
                            if(this->iCmd.iSPA.has_blower==false)
                            {
                                if(this->has_M0_HC==false&&this->TooCold_HeatOn==false&&this->Start_with_Heat==false&&this->Start_with_CIRC==false)
                                {
                                    if(DISP_AUTO_DIAGNOSIS_HINT==1)MsgMain2(MSG_MAINAD_AD_HINT_WAIT_HEATER_ON);
                                    Next_AD_State=S_HeatOn; AD_wait_count=0;
                                }
                                else
                                {
                                    if(DISP_AUTO_DIAGNOSIS_HINT==1)MsgMain2(MSG_MAINAD_AD_HINT_RESTORE_SETTING);
                                    Next_AD_State=S_Over; AD_wait_count=0;
                                }
                            }
                            else
                            {
                                Next_AD_State=S7_blower; AD_wait_count=0;
                            }
                        }
                        else
                        {
                            Next_AD_State=S5_P3_hi; AD_wait_count=0;
                        }
                    }
                    else
                    {
                        Next_AD_State=S3_P2_hi;  AD_wait_count=0;
                    }
                }
            }
        }
        break;
    case S3_P2_hi:
        if(DEBUGGING_USEAGE==1)MsgMain("S3_P2_hi");
        this->iCmd.set_p2_hi_ON();
        Next_AD_State=C3_P2_hi; AD_wait_count=0;
        break;
    case C3_P2_hi:
        if(AD_wait_count>RDS_AUTO_DIAGNOSIS_WAIT_C)
        {
            if(DEBUGGING_USEAGE==1)MsgMain("C3_P2_hi");
            if(this->iCmd.iSPA.p2_hi_on)
            {
                if((!this->iCmd.iSPA.blower_on)
                    &&(!this->iCmd.iSPA.p1_hi_on)&&(!this->iCmd.iSPA.p1_lo_on)
                    &&(!this->iCmd.iSPA.p3_hi_on)&&(!this->iCmd.iSPA.p3_lo_on))
                {
                    Next_AD_State=M3_P2_hi; AD_wait_count=0;
                }
                else
                {
                    Next_AD_State=S0_all_off; AD_wait_count=0;
                }
            }
            else
            {
                Next_AD_State=S3_P2_hi; AD_wait_count=0;
            }
        }
        break;
    case M3_P2_hi:
        if(AD_wait_count>RDS_AUTO_DIAGNOSIS_WAIT_M)
        {
            if(DEBUGGING_USEAGE==1)MsgMain("M3_P2_hi");
            M3_current=this->iCmd.iSPA.CurrentADC_to_Amp(this->iCmd.iSPA.cur_Adc_4);
            this->textBox_P2_Amp->Text=""+M3_current;
            AD_judge_M3();
            Next_AD_State=M3off; AD_wait_count=0;
        }
        break;
    case M3off:
        if(DEBUGGING_USEAGE==1)MsgMain("M3off");
        this->iCmd.set_p2_OFF();
        Next_AD_State=M3AC; AD_wait_count=0;
        break;
    case M3AC:
        if(AD_wait_count>RDS_AUTO_DIAGNOSIS_WAIT_C)
        {
            if(DEBUGGING_USEAGE==1)MsgMain("M3AC");

            //next
            if(this->AD_status_change())
            {
                Next_AD_State=S0_all_off; AD_wait_count=0;
                if(DEBUGGING_USEAGE==1)MsgMain("AD status change");
            }
            else
            {
                if(this->iCmd.iSPA.p2_hi_on)
                {
                    Next_AD_State=M3off; AD_wait_count=0;
                }
                else
                {
                    if(this->iCmd.iSPA.p2_mode==2)
                    {
                        Next_AD_State=S4_P2_lo; AD_wait_count=0;
                    }
                    else
                    {
                        if(this->iCmd.iSPA.p3_mode==0)
                        {
                            if(this->iCmd.iSPA.has_blower==false)
                            {
                                if(this->has_M0_HC==false&&this->TooCold_HeatOn==false&&this->Start_with_Heat==false&&this->Start_with_CIRC==false)
                                {
                                    if(DISP_AUTO_DIAGNOSIS_HINT==1)MsgMain2(MSG_MAINAD_AD_HINT_WAIT_HEATER_ON);
                                    Next_AD_State=S_HeatOn; AD_wait_count=0;
                                }
                                else
                                {
                                    if(DISP_AUTO_DIAGNOSIS_HINT==1)MsgMain2(MSG_MAINAD_AD_HINT_RESTORE_SETTING);
                                    Next_AD_State=S_Over; AD_wait_count=0;
                                }
                            }
                            else
                            {
                                Next_AD_State=S7_blower; AD_wait_count=0;
                            }
                        }
                        else
                        {
                            Next_AD_State=S5_P3_hi; AD_wait_count=0;
                        }
                    }
                }
            }
        }
        break;
    case S4_P2_lo:
        if(DEBUGGING_USEAGE==1)MsgMain("S4_P2_lo");
        this->iCmd.set_p2_lo_ON();
        Next_AD_State=C4_P2_lo; AD_wait_count=0;
        break;
    case C4_P2_lo:
        if(AD_wait_count>RDS_AUTO_DIAGNOSIS_WAIT_C)
        {
            if(DEBUGGING_USEAGE==1)MsgMain("C4_P2_lo");
            if(this->iCmd.iSPA.p2_lo_on)
            {
                if((!this->iCmd.iSPA.blower_on)
                    &&(!this->iCmd.iSPA.p1_hi_on)&&(!this->iCmd.iSPA.p1_lo_on)
                    &&(!this->iCmd.iSPA.p3_hi_on)&&(!this->iCmd.iSPA.p3_lo_on))
                {
                    Next_AD_State=M4_P2_lo; AD_wait_count=0;
                }
                else
                {
                    Next_AD_State=S0_all_off; AD_wait_count=0;
                }
            }
            else
            {
                Next_AD_State=S4_P2_lo; AD_wait_count=0;
            }
        }
        break;
    case M4_P2_lo:
        if(AD_wait_count>RDS_AUTO_DIAGNOSIS_WAIT_M)
        {
            if(DEBUGGING_USEAGE==1)MsgMain("M4_P2_lo");
            M4_current=this->iCmd.iSPA.CurrentADC_to_Amp(this->iCmd.iSPA.cur_Adc_4);
            this->textBox_P2_Amp->Text=""+M3_current+", "+M4_current;
            AD_judge_M4();
            Next_AD_State=M4off; AD_wait_count=0;
        }
        break;
    case M4off:
        if(DEBUGGING_USEAGE==1)MsgMain("M4off");
        this->iCmd.set_p1_OFF();
        Next_AD_State=M4AC; AD_wait_count=0;
        break;
    case M4AC:
        if(AD_wait_count>RDS_AUTO_DIAGNOSIS_WAIT_C)
        {
            if(DEBUGGING_USEAGE==1)MsgMain("M4AC");
            //next
            if(this->AD_status_change())
            {
                Next_AD_State=S0_all_off; AD_wait_count=0;
                if(DEBUGGING_USEAGE==1)MsgMain("AD status change");
            }
            else
            {
                if(this->iCmd.iSPA.p1_lo_on)
                {
                    Next_AD_State=M4off; AD_wait_count=0;
                }
                else
                {
                    if(this->iCmd.iSPA.p3_mode==0)
                    {
                        if(this->iCmd.iSPA.has_blower==false)
                        {
                            if(this->has_M0_HC==false&&this->TooCold_HeatOn==false&&this->Start_with_Heat==false&&this->Start_with_CIRC==false)
                            {
                                if(DISP_AUTO_DIAGNOSIS_HINT==1)MsgMain2(MSG_MAINAD_AD_HINT_WAIT_HEATER_ON);
                                Next_AD_State=S_HeatOn; AD_wait_count=0;
                            }
                            else
                            {
                                if(DISP_AUTO_DIAGNOSIS_HINT==1)MsgMain2(MSG_MAINAD_AD_HINT_RESTORE_SETTING);
                                Next_AD_State=S_Over; AD_wait_count=0;
                            }
                        }
                        else
                        {
                            Next_AD_State=S7_blower; AD_wait_count=0;
                        }
                    }
                    else
                    {
                        Next_AD_State=S5_P3_hi; AD_wait_count=0;
                    }
                }
            }
        }
        break;
    case S5_P3_hi:
        if(DEBUGGING_USEAGE==1)MsgMain("S5_P3_hi");
        this->iCmd.set_p3_hi_ON();
        Next_AD_State=C5_P3_hi; AD_wait_count=0;
        break;
    case C5_P3_hi:
        if(AD_wait_count>RDS_AUTO_DIAGNOSIS_WAIT_C)
        {
            if(DEBUGGING_USEAGE==1)MsgMain("C5_P3_hi");
            if(this->iCmd.iSPA.p3_hi_on)
            {
                if((!this->iCmd.iSPA.blower_on)
                    &&(!this->iCmd.iSPA.p1_hi_on)&&(!this->iCmd.iSPA.p1_lo_on)
                    &&(!this->iCmd.iSPA.p2_hi_on)&&(!this->iCmd.iSPA.p2_lo_on))
                {
                    Next_AD_State=M5_P3_hi; AD_wait_count=0;
                }
                else
                {
                    Next_AD_State=S0_all_off; AD_wait_count=0;
                }
            }
            else
            {
                Next_AD_State=S5_P3_hi; AD_wait_count=0;
            }
        }
        break;
    case M5_P3_hi:
        if(AD_wait_count>RDS_AUTO_DIAGNOSIS_WAIT_M)
        {
            if(DEBUGGING_USEAGE==1)MsgMain("M5_P3_hi");
            M5_current=this->iCmd.iSPA.CurrentADC_to_Amp(this->iCmd.iSPA.cur_Adc_4);
            this->textBox_P3_Amp->Text=""+M5_current;
            AD_judge_M5();
            Next_AD_State=M5off; AD_wait_count=0;
        }
        break;
    case M5off:
        if(DEBUGGING_USEAGE==1)MsgMain("M5off");
        this->iCmd.set_p3_OFF();
        Next_AD_State=M5AC; AD_wait_count=0;
        break;
    case M5AC:
        if(AD_wait_count>RDS_AUTO_DIAGNOSIS_WAIT_C)
        {
            if(DEBUGGING_USEAGE==1)MsgMain("M5AC");
            //next
            if(this->AD_status_change())
            {
                Next_AD_State=S0_all_off; AD_wait_count=0;
                if(DEBUGGING_USEAGE==1)MsgMain("AD status change");
            }
            else
            {
                if(this->iCmd.iSPA.p3_hi_on)
                {
                    Next_AD_State=M5off; AD_wait_count=0;
                }
                else
                {
                    if(this->iCmd.iSPA.p3_mode==2)
                    {
                        Next_AD_State=S6_P3_lo; AD_wait_count=0;
                    }
                    else
                    {
                        if(this->iCmd.iSPA.has_blower==false)
                        {
                            if(this->has_M0_HC==false&&this->TooCold_HeatOn==false&&this->Start_with_Heat==false&&this->Start_with_CIRC==false)
                            {
                                if(DISP_AUTO_DIAGNOSIS_HINT==1)MsgMain2(MSG_MAINAD_AD_HINT_WAIT_HEATER_ON);
                                Next_AD_State=S_HeatOn; AD_wait_count=0;
                            }
                            else
                            {
                                if(DISP_AUTO_DIAGNOSIS_HINT==1)MsgMain2(MSG_MAINAD_AD_HINT_RESTORE_SETTING);
                                Next_AD_State=S_Over; AD_wait_count=0;
                            }
                        }
                        else
                        {
                            Next_AD_State=S7_blower; AD_wait_count=0;
                        }
                    }
                }
            }
        }
        break;
    case S6_P3_lo:
        if(DEBUGGING_USEAGE==1)MsgMain("S6_P3_lo");
        this->iCmd.set_p3_lo_ON();
        Next_AD_State=C6_P3_lo; AD_wait_count=0;
        break;
    case C6_P3_lo:
        if(AD_wait_count>RDS_AUTO_DIAGNOSIS_WAIT_C)
        {
            if(DEBUGGING_USEAGE==1)MsgMain("C6_P3_lo");
            if(this->iCmd.iSPA.p3_lo_on)
            {
                if((!this->iCmd.iSPA.blower_on)
                    &&(!this->iCmd.iSPA.p1_hi_on)&&(!this->iCmd.iSPA.p1_lo_on)
                    &&(!this->iCmd.iSPA.p2_hi_on)&&(!this->iCmd.iSPA.p2_lo_on))
                {
                    Next_AD_State=M6_P3_lo; AD_wait_count=0;
                }
                else
                {
                    Next_AD_State=S0_all_off; AD_wait_count=0;
                }
            }
            else
            {
                Next_AD_State=S6_P3_lo; AD_wait_count=0;
            }
        }
        break;
    case M6_P3_lo:
        if(AD_wait_count>RDS_AUTO_DIAGNOSIS_WAIT_M)
        {
            if(DEBUGGING_USEAGE==1)MsgMain("M6_P3_lo");
            M6_current=this->iCmd.iSPA.CurrentADC_to_Amp(this->iCmd.iSPA.cur_Adc_4);
            this->textBox_P2_Amp->Text=""+M5_current+", "+M6_current;
            AD_judge_M6();
            Next_AD_State=M6off; AD_wait_count=0;
        }
        break;
    case M6off:
        if(DEBUGGING_USEAGE==1)MsgMain("M6off");
        this->iCmd.set_p3_OFF();
        Next_AD_State=M6AC; AD_wait_count=0;
        break;
    case M6AC:
        if(AD_wait_count>RDS_AUTO_DIAGNOSIS_WAIT_C)
        {
            if(DEBUGGING_USEAGE==1)MsgMain("M6AC");
            //next
            if(this->AD_status_change())
            {
                Next_AD_State=S0_all_off; AD_wait_count=0;
                if(DEBUGGING_USEAGE==1)MsgMain("AD status change");
            }
            else
            {
                if(this->iCmd.iSPA.p3_lo_on)
                {
                    Next_AD_State=M6off; AD_wait_count=0;
                }
                else
                {
                    if(this->iCmd.iSPA.has_blower==false)
                    {
                        if(this->has_M0_HC==false&&this->TooCold_HeatOn==false&&this->Start_with_Heat==false&&this->Start_with_CIRC==false)
                        {
                            if(DISP_AUTO_DIAGNOSIS_HINT==1)MsgMain2(MSG_MAINAD_AD_HINT_WAIT_HEATER_ON);
                            Next_AD_State=S_HeatOn; AD_wait_count=0;
                        }
                        else
                        {
                            if(DISP_AUTO_DIAGNOSIS_HINT==1)MsgMain2(MSG_MAINAD_AD_HINT_RESTORE_SETTING);
                            Next_AD_State=S_Over; AD_wait_count=0;
                        }
                    }
                    else
                    {
                        Next_AD_State=S7_blower; AD_wait_count=0;
                    }
                }
            }
        }
        break;
    case S7_blower:
        if(DEBUGGING_USEAGE==1)MsgMain("S7_blower");
        this->iCmd.set_blower_ON();
        Next_AD_State=C7_blower; AD_wait_count=0;
        break;
    case C7_blower:
        if(AD_wait_count>RDS_AUTO_DIAGNOSIS_WAIT_C)
        {
            if(DEBUGGING_USEAGE==1)MsgMain("C7_blower");
            if(this->iCmd.iSPA.blower_on)
            {
                if((!this->iCmd.iSPA.p1_hi_on)&&(!this->iCmd.iSPA.p1_lo_on)
                    &&(!this->iCmd.iSPA.p2_hi_on)&&(!this->iCmd.iSPA.p2_lo_on)
                    &&(!this->iCmd.iSPA.p3_hi_on)&&(!this->iCmd.iSPA.p3_lo_on))
                {
                    Next_AD_State=M7_blower; AD_wait_count=0;
                }
                else
                {
                    Next_AD_State=S0_all_off; AD_wait_count=0;
                }
            }
            else
            {
                Next_AD_State=S7_blower; AD_wait_count=0;
            }
        }
        break;
    case M7_blower:
        if(AD_wait_count>RDS_AUTO_DIAGNOSIS_WAIT_M)
        {
            if(DEBUGGING_USEAGE==1)MsgMain("M7_blower");
            M7_current=this->iCmd.iSPA.CurrentADC_to_Amp(this->iCmd.iSPA.cur_Adc_4);
            this->textBox_Blower_Amp->Text=""+M7_current;
            AD_judge_M7();
            Next_AD_State=M7off; AD_wait_count=0;
        }
        break;
    case M7off:
        if(DEBUGGING_USEAGE==1)MsgMain("M7off");
        this->iCmd.set_blower_OFF();
        Next_AD_State=M7AC; AD_wait_count=0;
        break;
    case M7AC:
        if(AD_wait_count>RDS_AUTO_DIAGNOSIS_WAIT_C)
        {
            if(DEBUGGING_USEAGE==1)MsgMain("M7AC");
            //next...
            if(this->iCmd.iSPA.blower_on)
            {
                Next_AD_State=M7off; AD_wait_count=0;
            }
            else
            {
                if(this->has_M0_HC==false&&this->TooCold_HeatOn==false&&this->Start_with_Heat==false&&this->Start_with_CIRC==false)
                {
                    if(DISP_AUTO_DIAGNOSIS_HINT==1)MsgMain2(MSG_MAINAD_AD_HINT_WAIT_HEATER_ON);
                    Next_AD_State=S_HeatOn; AD_wait_count=0;
                }
                else
                {
                    if(DISP_AUTO_DIAGNOSIS_HINT==1)MsgMain2(MSG_MAINAD_AD_HINT_RESTORE_SETTING);
                    Next_AD_State=S_Over; AD_wait_count=0;
                }
            }
        }
        break;
    case S_HeatOn:
        if(DEBUGGING_USEAGE==1)MsgMain("S_HeatOn");
        //get current water temperature
        this->curWaterT=this->iCmd.iSPA.TEMPADC_To_TEMP_F(this->iCmd.iSPA.cur_Adc_0);
        //let setT is 2 degree-F higher than water temperature 2 degree-F
        adc_value=this->iCmd.iSPA.TEMP_F_To_TEMPADC(this->curWaterT+RDS_AD_INC_DEC_TEMPATURE_F);
        Array::Resize(buffer, 4);
        buffer[0]=NEW_2015_PROTOCOL_CODE;
        buffer[1]=0x20; //Command  -- Set Temperature ADC
        buffer[2]=(adc_value>>8)&0x000000FF;
        buffer[3]=adc_value&0x000000FF;
        this->iCmd.SendCmdPacket(buffer);
        SetWaitingCmd(0x30);
        //next
        Next_AD_State=C_HeatOn_CircOnly; AD_wait_count=0;
        break;
    case C_HeatOn_CircOnly:
        if(AD_wait_count>RDS_AUTO_DIAGNOSIS_WAIT_C)
        {
            if(DEBUGGING_USEAGE==1)MsgMain("C_HeatOn_CircOnly");
            if(this->iCmd.iSPA.heater_on==false&&this->iCmd.iSPA.circ_on==true)
            {
                Next_AD_State=M_HeatOn_CircOnly; AD_wait_count=0;
            }
            else
            {
                Next_AD_State=S_HeatOn; AD_wait_count=0;
            }
        }
        break;
    case M_HeatOn_CircOnly:
        //measure M0_C_current!
        if(AD_wait_count>RDS_AUTO_DIAGNOSIS_WAIT_M_CR)
        {
            if(DEBUGGING_USEAGE==1)MsgMain("M_HeatOn_CircOnly");
            this->has_M0_C=true;
            M0_C_current=this->iCmd.iSPA.CurrentADC_to_Amp(this->iCmd.iSPA.cur_Adc_4);
            this->textBox_Heater_Amp->Text=""+M0_C_current;
            AD_judge_M0_C();
            //next
            Next_AD_State=W_HeatON_CircOn; AD_wait_count=0;
        }
        break;
    case W_HeatON_CircOn:
        if(AD_wait_count>RDS_AUTO_DIAGNOSIS_WAIT_M_WCR)
        {
            if(DEBUGGING_USEAGE==1)MsgMain("W_HeatON_CircOn");
            if(this->iCmd.iSPA.heater_on==true)
            {
                if(DISP_AUTO_DIAGNOSIS_HINT==1)MsgMain2(MSG_MAINAD_AD_HINT_HEATER_ON_OKAY);
                Next_AD_State=M_HeatOn_CircOn; AD_wait_count=0; //go next
            }
            else
            {
                //checking if has flow switch error
                if(iCmd.iSPA.msg_index_1==12||iCmd.iSPA.msg_index_2==12||
                    iCmd.iSPA.msg_index_3==12||iCmd.iSPA.msg_index_4==12)
                {
                    //FL1 (FSO), it should has water flow & FS closed, but now opened.
                    this->Flow_err=true;
                    Next_AD_State=S_Over; AD_wait_count=0;  //keep waiting
                }
                else
                {
                    Next_AD_State=W_HeatON_CircOn; AD_wait_count=0;  //keep waiting
                }
            }
        }
        break;
    case M_HeatOn_CircOn:
        if(AD_wait_count>RDS_AUTO_DIAGNOSIS_WAIT_M)
        {
            if(DEBUGGING_USEAGE==1)MsgMain("M_HeatOn_CircOn");
            this->has_M0_HC=true;
            M0_HC_current=this->iCmd.iSPA.CurrentADC_to_Amp(this->iCmd.iSPA.cur_Adc_4);
            this->textBox_Heater_Amp->Text=""+M0_HC_current+", "+M0_C_current;
            AD_judge_M0_HC();
            //next.....
            if(DISP_AUTO_DIAGNOSIS_HINT==1)MsgMain2(MSG_MAINAD_AD_HINT_RESTORE_SETTING);
            Next_AD_State=S_Over; AD_wait_count=0;
        }
        break;
    case S_Over:
        if(DEBUGGING_USEAGE==1)MsgMain("S_Over");
        //ECO mode back
        if(this->starting_ECO_on==true) this->iCmd.set_ECO_ON();
        else this->iCmd.set_ECO_OFF();
        this->iCmd.SendSingleCmdPacket(0x38); //get ECO mode
        //next
        Next_AD_State=C_Over; AD_wait_count=0;
        break;
    case C_Over:
        if(AD_wait_count>RDS_AUTO_DIAGNOSIS_WAIT_C)
        {
            if(DEBUGGING_USEAGE==1)MsgMain("C_Over");
            if(this->starting_ECO_on==this->iCmd.iSPA.ecoModeOn)
            {
                Next_AD_State=S_Over_SetLK; AD_wait_count=0; //go next...
            }
            else
            {
                Next_AD_State=S_Over; AD_wait_count=0; //go back try again
            }
        }
        break;
    case S_Over_SetLK:
        if(DEBUGGING_USEAGE==1)MsgMain("S_Over_SetLK");
        //Lock mode back
        if(this->starting_lock==1) this->iCmd.set_Alock();
        if(this->starting_lock==2) this->iCmd.set_Plock();
        if(this->starting_lock==3) this->iCmd.set_Tlock();
        if(this->starting_lock==4) this->iCmd.set_Slock();
        //next
        Next_AD_State=C_Over_SetLK; AD_wait_count=0;
        break;
    case C_Over_SetLK:
        if(AD_wait_count>RDS_AUTO_DIAGNOSIS_WAIT_C)
        {
            if(DEBUGGING_USEAGE==1)MsgMain("C_Over_SetLK");
            if(this->starting_lock==this->iCmd.iSPA.lock_value)
            {
                Next_AD_State=S_Over_SetT; AD_wait_count=0; //go next...
            }
            else
            {
                Next_AD_State=S_Over_SetLK; AD_wait_count=0; //go back try again
            }
        }
        break;
    case S_Over_SetT:
        //setT back
        if(DEBUGGING_USEAGE==1)MsgMain("S_Over_SetT, setT as "+this->starting_setT);
        adc_value=this->iCmd.iSPA.TEMP_F_To_TEMPADC(this->starting_setT);
        Array::Resize(buffer, 4);
        buffer[0]=NEW_2015_PROTOCOL_CODE;
        buffer[1]=0x20; //Command  -- Set Temperature ADC
        buffer[2]=(adc_value>>8)&0x000000FF;
        buffer[3]=adc_value&0x000000FF;
        this->iCmd.SendCmdPacket(buffer);
        SetWaitingCmd(0x30);
        restore_AD_setT=true;
        //next...
        Next_AD_State=C_Over_SetT; AD_wait_count=0;
        break;
    case C_Over_SetT:
        if(AD_wait_count>RDS_AUTO_DIAGNOSIS_WAIT_C)
        {
            if(DEBUGGING_USEAGE==1)MsgMain("C_Over_SetT");
            if(restore_AD_setT==true)
            {
                Next_AD_State=S_Over_SetT; AD_wait_count=0; //try again
            }
            else
            {
                //ok, go next
                if(DISP_AUTO_DIAGNOSIS_HINT==1)MsgMain2(MSG_MAINAD_AD_HINT_RESTORE_F_SCHEDULE);
                //Next_AD_State = S_setDTnow; AD_wait_count = 0; //20161125, change to broadcasting Block-out/Clean cycle
                //
                //ok, go next (20161125 new modify.
                if(this->iCmd.iSPA.is_HighEnd_Fsch==true)
                { //high-end f-schedule
                    Next_AD_State=S_bkFsch; AD_wait_count=0;
                    resend_32=0;
                }
                else
                {   //low-end f-schedule
                    Next_AD_State=S_bkSF; AD_wait_count=0;
                    resend_36=0;
                }
                //
                resend_31=0;
            }
        }
        break;
    case S_setDTnow:
        if(DEBUGGING_USEAGE==1)MsgMain("S_setDTnow");
        //setting Date & Time as today 01:00
        if(resend_31<COMMAND_RESEND_TIMES)
        {
            dt=DateTime::Now;
            CurHour=dt.ToString("HH", DateTimeFormatInfo::InvariantInfo);
            Cur_min=dt.ToString("mm", DateTimeFormatInfo::InvariantInfo);
            Array::Resize(buffer, 9);
            buffer[0]=NEW_2015_PROTOCOL_CODE;
            buffer[1]=0x21; //Command  -- Set Date & Time (01:00)
            buffer[2]=Convert::ToInt32(CurYear, 10);  //assume after AD, it's the same day
            buffer[3]=Convert::ToInt32(CurMont, 10);
            buffer[4]=Convert::ToInt32(Cur_Day, 10);
            buffer[5]=weekday;
            buffer[6]=Convert::ToInt32(CurHour, 10);;  //hour
            buffer[7]=Convert::ToInt32(Cur_min, 10);;  //min
            buffer[8]=0;  //set default seconds
            this->iCmd.SendCmdPacket(buffer);
            SetWaitingCmd(0x31);
            //
            this->restore_ADcmd31=true;
        }
        else
        {
            //time-out Error!!!
            this->restore_ADcmd31=false;
            MessageBox::Show(MSG_MAINAD_SET_NOW_TIME_TIMEOUT, "TimeOut",
                MessageBoxButtons::OK,
                MessageBoxIcon::Information);
        }
        Next_AD_State=C_setDTnow; AD_wait_count=0;
        break;
    case C_setDTnow:
        if(AD_wait_count>RDS_AUTO_DIAGNOSIS_WAIT_F)
        {
            if(DEBUGGING_USEAGE==1)MsgMain("C_setDTnow");
            if(restore_ADcmd31==true)
            {
                Next_AD_State=S_setDTnow; AD_wait_count=0; //try again
                resend_31++;
            }
            else
            {
                //ok, go next
                if(this->iCmd.iSPA.is_HighEnd_Fsch==true)
                { //high-end f-schedule
                    Next_AD_State=S_bkFsch; AD_wait_count=0;
                    resend_32=0;
                }
                else
                {   //low-end f-schedule
                    Next_AD_State=S_bkSF; AD_wait_count=0;
                    resend_36=0;
                }
            }
        }
        break;
    case S_bkSF:
        if(DEBUGGING_USEAGE==1)MsgMain("to S_bkSF ");
        if(resend_36<COMMAND_RESEND_TIMES)
        {
            //Set std mode filter schedule AS RDS use (let SPA in not Circ mode)
            Array::Resize(buffer, 3);
            buffer[0]=NEW_2015_PROTOCOL_CODE;
            buffer[1]=0x26; //Command  -- Set SF
            buffer[2]=this->AD_sf_value;
            this->iCmd.SendCmdPacket(buffer);
            SetWaitingCmd(0x36);
            //
            this->restore_ADcmd36=true;
        }
        else
        {
            //time-out Error!!!
            this->restore_ADcmd36=false;
            MessageBox::Show(MSG_MAINAD_RESTORE_SF_TIMEOUT, "TimeOut",
                MessageBoxButtons::OK,
                MessageBoxIcon::Information);
        }
        Next_AD_State=C_bkSF; AD_wait_count=0;
        break;
    case C_bkSF:
        if(AD_wait_count>RDS_AUTO_DIAGNOSIS_WAIT_C)
        {
            if(DEBUGGING_USEAGE==1)MsgMain("C_bkSF");
            if(this->restore_ADcmd36==true)
            { //not done, go back
                Next_AD_State=S_bkSF; AD_wait_count=0;
                resend_36++;
            }
            else
            {
                //okay, go next
                Next_AD_State=S_bkPF; AD_wait_count=0;
                resend_35=0;
            }
        }
        break;
    case S_bkPF:
        if(DEBUGGING_USEAGE==1)MsgMain("S_bkPF");
        if(resend_35<COMMAND_RESEND_TIMES)
        {
            //Set std mode filter schedule AS RDS use (let SPA in not Circ mode)
            Array::Resize(buffer, 8);
            buffer[0]=NEW_2015_PROTOCOL_CODE;
            buffer[1]=0x25; //Command  -- Set PF
            buffer[2]=0x80; //programmable PF
            buffer[3]=this->AD_pf_st_hour; // pf_st_hour;
            buffer[4]=this->AD_pf_st_min;  // pf_st_min;
            buffer[5]=this->AD_pf_dt_hour; // pf_dt_hour;
            buffer[6]=this->AD_pf_dt_min;  // pf_dt_min;
            buffer[7]=0x7f;
            this->iCmd.SendCmdPacket(buffer);
            SetWaitingCmd(0x35);
            //
            this->restore_ADcmd35=true;
        }
        else
        {
            //time-out Error!!!
            this->restore_ADcmd35=false;
            MessageBox::Show(MSG_MAINAD_RESTORE_PF_TIMEOUT, "TimeOut",
                MessageBoxButtons::OK,
                MessageBoxIcon::Information);
        }
        Next_AD_State=C_bkPF; AD_wait_count=0;
        break;
    case C_bkPF:
        if(AD_wait_count>RDS_AUTO_DIAGNOSIS_WAIT_C)
        {
            if(DEBUGGING_USEAGE==1)MsgMain("C_bkPF");
            if(this->restore_ADcmd35==true)
            { //not done, go back
                Next_AD_State=S_bkPF; AD_wait_count=0;
                resend_35++;
            }
            else
            {
                //okay, go next
                Next_AD_State=S_Over_end; AD_wait_count=0;
            }
        }
        break;
    case S_bkFsch:
        if(DEBUGGING_USEAGE==1)MsgMain("S_bkFsch");
        if(resend_32<COMMAND_RESEND_TIMES)
        {
            Array::Resize(buffer, 8);
            buffer[0]=NEW_2015_PROTOCOL_CODE;
            buffer[1]=0x22; //Command  -- Set std filter schedule
            buffer[2]=1; //group
            buffer[3]=this->AF_std_st_hour;
            buffer[4]=this->AF_std_st_min;
            buffer[5]=this->AF_std_dt_hour;
            buffer[6]=this->AF_std_dt_min;
            buffer[7]=this->AF_std_week;
            this->iCmd.SendCmdPacket(buffer);
            SetWaitingCmd(0x32);
            this->restore_ADcmd32=true;
        }
        else
        {
            //time-out Error!!!
            this->restore_ADcmd32=false;
            MessageBox::Show(MSG_MAINAD_RESTORE_F_SCHEDULE_TIMEOUT, "TimeOut",
                MessageBoxButtons::OK,
                MessageBoxIcon::Information);
        }
        //
        Next_AD_State=C_bkFsch; AD_wait_count=0;
        break;
    case C_bkFsch:
        if(AD_wait_count>RDS_AUTO_DIAGNOSIS_WAIT_F)
        {
            if(DEBUGGING_USEAGE==1)MsgMain("C_bkFsch");
            if(restore_ADcmd32==true)
            {
                Next_AD_State=S_bkFsch; AD_wait_count=0; //try again
                resend_32++;
            }
            else
            {
                //ok, go next
                Next_AD_State=S_Over_end; AD_wait_count=0;
            }
        }
        break;
    case S_Over_end:
        MsgMain2(MSG_MAINAD_AD_HINT_FINISHED);
        MsgLog("AK");

        //enable buttons
        this->button_Err_Msg->Enabled=true;
        this->button_Filtration_sch->Enabled=true;
        this->button_PF->Enabled=true;
        this->button_SF->Enabled=true;
        this->button_Date_Time->Enabled=true;
        this->button_Func_Lock->Enabled=true;
        this->button_Pump_Lock->Enabled=true;
        this->button_Panel_Lock->Enabled=true;
        this->button_unlock->Enabled=true;
        this->button_T_Lock->Enabled=true;
        this->button_mode->Enabled=true;
        this->button_P1_Hi->Enabled=true;
        this->button_P1_Lo->Enabled=true;
        this->button_P2_Hi->Enabled=true;
        this->button_P2_Lo->Enabled=true;
        this->button_P3_Hi->Enabled=true;
        this->button_P3_Lo->Enabled=true;
        this->button_Blower_OnOff->Enabled=true;
        this->textBox_Set_T->Enabled=true;

        //the analysis part)
        AD_judge_CauseEquip(); //judge both measure result and starting/current Errors

        this->doing_AutoD=false;
        this->RDS_AD_finish=true;
        Next_AD_State=S_idel; AD_wait_count=0;
        break;
    }
}

//============================//
// Auto Diagnosis judgements  //
//============================//
//  M0, M0_C, M0_HC
//------------------------
void RDS_main_Form::AD_judge_M0()
{
    int mNo=this->comboBox_Model_Name->SelectedIndex;
    if(this->Start_with_Heat==true&&this->Start_with_CIRC==true&&this->Start_with_UV==true)
    {
        this->M0_st=3;
        MsgMain3FS(MSG_MAINAD_AD_HINT_M0_HC, FontStyle::Regular);
        MsgMain3FS(" : "+this->M0_current+"A", FontStyle::Bold);
        if(DEBUGGING_USEAGE==4)
            MsgMain3CS(".... ("+SpaModels[mNo].AllOff_Heater_Circ_UV_max+","+SpaModels[mNo].AllOff_Heater_Circ_UV_min+")", Color::Black);
        if(this->M0_current>SpaModels[mNo].AllOff_Heater_Circ_UV_max||this->M0_current<SpaModels[mNo].AllOff_Heater_Circ_UV_min)
        {
            MsgMain3CS(" (Error)"+Environment::NewLine, Color::Red);
            this->M0_err=true;
        }
        else
        {
            MsgMain3CS(" (Normal)"+Environment::NewLine, Color::Black);
            this->M0_err=false;
        }
    }
    else if(this->Start_with_Heat==false&&this->Start_with_CIRC==true&&this->Start_with_UV==true)
    {
        this->M0_st=2;
        MsgMain3FS(MSG_MAINAD_AD_HINT_M0_C, FontStyle::Regular);
        MsgMain3FS(" : "+this->M0_current+"A", FontStyle::Bold);
        if(DEBUGGING_USEAGE==4)
            MsgMain3CS(".... ("+SpaModels[mNo].AllOff_Circ_UV_max+","+SpaModels[mNo].AllOff_Circ_UV_min+")", Color::Black);
        if(this->M0_current>SpaModels[mNo].AllOff_Circ_UV_max||this->M0_current<SpaModels[mNo].AllOff_Circ_UV_min)
        {
            MsgMain3CS(" (Error)"+Environment::NewLine, Color::Red);
            this->M0_err=true;
        }
        else
        {
            MsgMain3CS(" (Normal)"+Environment::NewLine, Color::Black);
            this->M0_err=false;
        }
    }
    else if(this->Start_with_Heat==false&&this->Start_with_CIRC==false&&this->Start_with_UV==false)
    {
        this->M0_st=1;
        MsgMain3FS(MSG_MAINAD_AD_HINT_M0, FontStyle::Regular);
        MsgMain3FS(" : "+this->M0_current+"A", FontStyle::Bold);
        if(DEBUGGING_USEAGE==4)
            MsgMain3CS(".... ("+SpaModels[mNo].AllOff_max+","+SpaModels[mNo].AllOff_min+")", Color::Black);
        if(this->M0_current>SpaModels[mNo].AllOff_max||this->M0_current<SpaModels[mNo].AllOff_min)
        {
            MsgMain3CS(" (Error)"+Environment::NewLine, Color::Red);
            this->M0_err=true;
        }
        else
        {
            MsgMain3CS(" (Normal)"+Environment::NewLine, Color::Black);
            this->M0_err=false;
        }
    }
    else
    {
        MsgMain3CS(" wrong HeaT/Circ/UV states (Error!!!) "+Environment::NewLine, Color::Red);
    }

    //save errors
    this->M0_all_Err=this->textBox_eMsg1->Text+","+this->textBox_eMsg2->Text+","+this->textBox_eMsg3->Text+","+this->textBox_eMsg4->Text;
}

void RDS_main_Form::AD_judge_M0_HC()
{
    int mNo=this->comboBox_Model_Name->SelectedIndex;
    MsgMain3FS(MSG_MAINAD_AD_HINT_M0_HC, FontStyle::Regular);
    MsgMain3FS(" : "+this->M0_HC_current+"A", FontStyle::Bold);
    if(DEBUGGING_USEAGE==4)
        MsgMain3CS(".... ("+SpaModels[mNo].AllOff_Heater_Circ_UV_max+","+SpaModels[mNo].AllOff_Heater_Circ_UV_min+")", Color::Black);
    if(this->M0_HC_current>SpaModels[mNo].AllOff_Heater_Circ_UV_max||this->M0_HC_current<SpaModels[mNo].AllOff_Heater_Circ_UV_min)
    {
        MsgMain3CS(" (Error)"+Environment::NewLine, Color::Red);
        this->M0_HC_err=true;
    }
    else
    {
        MsgMain3CS(" (Normal)"+Environment::NewLine, Color::Black);
        this->M0_HC_err=false;
    }
    //save errors
    this->M0_HC_all_Err=this->textBox_eMsg1->Text+","+this->textBox_eMsg2->Text+","+this->textBox_eMsg3->Text+","+this->textBox_eMsg4->Text;
}

void RDS_main_Form::AD_judge_M0_C()
{
    int mNo=this->comboBox_Model_Name->SelectedIndex;
    if(mNo<0)
    {
        MessageBox::Show(MSG_AD_MODEL_INDEX_WRONG, "NOTICE",
            MessageBoxButtons::OK,
            MessageBoxIcon::Information);
    }
    MsgMain3FS(MSG_MAINAD_AD_HINT_M0_C, FontStyle::Regular);
    MsgMain3FS(" : "+this->M0_C_current+"A", FontStyle::Bold);
    if(DEBUGGING_USEAGE==4)
        MsgMain3CS(".... ("+SpaModels[mNo].AllOff_Circ_UV_max+","+SpaModels[mNo].AllOff_Circ_UV_min+")", Color::Black);
    if(this->M0_C_current>SpaModels[mNo].AllOff_Circ_UV_max||this->M0_C_current<SpaModels[mNo].AllOff_Circ_UV_min)
    {
        MsgMain3CS(" (Error)"+Environment::NewLine, Color::Red);
        this->M0_C_err=true;
    }
    else
    {
        MsgMain3CS(" (Normal)"+Environment::NewLine, Color::Black);
        this->M0_C_err=false;
    }
    //save errors
    this->M0_C_all_Err=this->textBox_eMsg1->Text+","+this->textBox_eMsg2->Text+","+this->textBox_eMsg3->Text+","+this->textBox_eMsg4->Text;
}

//------//
//  M1  //
//------//
void RDS_main_Form::AD_judge_M1()
{
    int mNo=this->comboBox_Model_Name->SelectedIndex;
    if(mNo<0)
    {
        MessageBox::Show(MSG_AD_MODEL_INDEX_WRONG, "NOTICE",
            MessageBoxButtons::OK,
            MessageBoxIcon::Information);
    }
    if(this->M1M2_with_Circ==false)
    {
        this->M1_st=1;
        MsgMain3FS(MSG_MAINAD_AD_HINT_M1, FontStyle::Regular);
        MsgMain3FS(" : "+this->M1_current+"A", FontStyle::Bold);
        if(DEBUGGING_USEAGE==4)
            MsgMain3CS(".... ("+SpaModels[mNo].Pump1_Hi_max+","+SpaModels[mNo].Pump1_Hi_min+")", Color::Black);
        if(this->M1_current>SpaModels[mNo].Pump1_Hi_max||this->M1_current<SpaModels[mNo].Pump1_Hi_min)
        {
            MsgMain3CS(" (Error)"+Environment::NewLine, Color::Red);
            this->M1_err=true;
        }
        else
        {
            MsgMain3CS(" (Normal)"+Environment::NewLine, Color::Black);
            this->M1_err=false;
        }
    }
    else
    {
        if(this->M0_with_HeatCirc==false)
        {
            this->M1_st=2;
            MsgMain3FS(MSG_MAINAD_AD_HINT_M1_C, FontStyle::Regular);
            MsgMain3FS(" : "+this->M1_current+"A", FontStyle::Bold);
            if(DEBUGGING_USEAGE==4)
                MsgMain3CS(".... ("+SpaModels[mNo].Pump1_Hi_Circ_UV_max+","+SpaModels[mNo].Pump1_Hi_Circ_UV_min+")", Color::Black);
            if(this->M1_current>SpaModels[mNo].Pump1_Hi_Circ_UV_max||this->M1_current<SpaModels[mNo].Pump1_Hi_Circ_UV_min)
            {
                MsgMain3CS(" (Error)"+Environment::NewLine, Color::Red);
                this->M1_err=true;
            }
            else
            {
                MsgMain3CS(" (Normal)"+Environment::NewLine, Color::Black);
                this->M1_err=false;
            }
        }
        else
        {
            this->M1_st=3;
            MsgMain3FS(MSG_MAINAD_AD_HINT_M1_HC, FontStyle::Regular);
            MsgMain3FS(" : "+this->M1_current+"A", FontStyle::Bold);
            if(DEBUGGING_USEAGE==4)
                MsgMain3CS(".... ("+SpaModels[mNo].Pump1_Hi_Heater_Circ_UV_max+","+SpaModels[mNo].Pump1_Hi_Heater_Circ_UV_min+")", Color::Black);
            if(this->M1_current>SpaModels[mNo].Pump1_Hi_Heater_Circ_UV_max||this->M1_current<SpaModels[mNo].Pump1_Hi_Heater_Circ_UV_min)
            {
                MsgMain3CS(" (Error)"+Environment::NewLine, Color::Red);
                this->M1_err=true;
            }
            else
            {
                MsgMain3CS(" (Normal)"+Environment::NewLine, Color::Black);
                this->M1_err=false;
            }
        }
    }
    //save errors
    this->M1_all_Err=this->textBox_eMsg1->Text+","+this->textBox_eMsg2->Text+","+this->textBox_eMsg3->Text+","+this->textBox_eMsg4->Text;
}

//------//
//  M2  //
//------//
void RDS_main_Form::AD_judge_M2()
{
    int mNo=this->comboBox_Model_Name->SelectedIndex;
    if(mNo<0)
    {
        MessageBox::Show(MSG_AD_MODEL_INDEX_WRONG, "NOTICE",
            MessageBoxButtons::OK,
            MessageBoxIcon::Information);
    }
    if(this->M1M2_with_Circ==false)
    {
        this->M2_st=1;
        MsgMain3FS(MSG_MAINAD_AD_HINT_M2, FontStyle::Regular);
        MsgMain3FS(" : "+this->M2_current+"A", FontStyle::Bold);
        if(DEBUGGING_USEAGE==4)
            MsgMain3CS(".... ("+SpaModels[mNo].Pump1_Lo_max+","+SpaModels[mNo].Pump1_Lo_min+")", Color::Black);
        if(this->M2_current>SpaModels[mNo].Pump1_Lo_max||this->M2_current<SpaModels[mNo].Pump1_Lo_min)
        {
            MsgMain3CS(" (Error)"+Environment::NewLine, Color::Red);
            this->M2_err=true;
        }
        else
        {
            MsgMain3CS(" (Normal)"+Environment::NewLine, Color::Black);
            this->M2_err=false;
        }
    }
    else
    {
        if(this->M0_with_HeatCirc==false)
        {
            this->M2_st=2;
            MsgMain3FS(MSG_MAINAD_AD_HINT_M2_C, FontStyle::Regular);
            MsgMain3FS(" : "+this->M2_current+"A", FontStyle::Bold);
            if(DEBUGGING_USEAGE==4)
                MsgMain3CS(".... ("+SpaModels[mNo].Pump1_Lo_Circ_UV_max+","+SpaModels[mNo].Pump1_Lo_Circ_UV_min+")", Color::Black);
            if(this->M2_current>SpaModels[mNo].Pump1_Lo_Circ_UV_max||this->M2_current<SpaModels[mNo].Pump1_Lo_Circ_UV_min)
            {
                MsgMain3CS(" (Error)"+Environment::NewLine, Color::Red);
                this->M2_err=true;
            }
            else
            {
                MsgMain3CS(" (Normal)"+Environment::NewLine, Color::Black);
                this->M2_err=false;
            }
        }
        else
        {
            this->M2_st=3;
            MsgMain3FS(MSG_MAINAD_AD_HINT_M2_HC, FontStyle::Regular);
            MsgMain3FS(" : "+this->M2_current+"A", FontStyle::Bold);
            if(DEBUGGING_USEAGE==4)
                MsgMain3CS(".... ("+SpaModels[mNo].Pump1_Lo_Heater_Circ_UV_max+","+SpaModels[mNo].Pump1_Lo_Heater_Circ_UV_min+")", Color::Black);
            if(this->M2_current>SpaModels[mNo].Pump1_Lo_Heater_Circ_UV_max||this->M2_current<SpaModels[mNo].Pump1_Lo_Heater_Circ_UV_min)
            {
                MsgMain3CS(" (Error)"+Environment::NewLine, Color::Red);
                this->M2_err=true;
            }
            else
            {
                MsgMain3CS(" (Normal)"+Environment::NewLine, Color::Black);
                this->M2_err=false;
            }
        }
    }
    //save errors
    this->M2_all_Err=this->textBox_eMsg1->Text+","+this->textBox_eMsg2->Text+","+this->textBox_eMsg3->Text+","+this->textBox_eMsg4->Text;
}

//------//
//  M3  //
//------//
void RDS_main_Form::AD_judge_M3()
{
    int mNo=this->comboBox_Model_Name->SelectedIndex;
    if(mNo<0)
    {
        MessageBox::Show(MSG_AD_MODEL_INDEX_WRONG, "NOTICE",
            MessageBoxButtons::OK,
            MessageBoxIcon::Information);
    }
    if(this->M0_with_HeatCirc==false)
    {
        this->M3_st=1;
        MsgMain3FS(MSG_MAINAD_AD_HINT_M3, FontStyle::Regular);
        MsgMain3FS(" : "+this->M3_current+"A", FontStyle::Bold);
        if(DEBUGGING_USEAGE==4)
            MsgMain3CS(".... ("+SpaModels[mNo].Pump2_Hi_max+","+SpaModels[mNo].Pump2_Hi_min+")", Color::Black);
        if(this->M3_current>SpaModels[mNo].Pump2_Hi_max||this->M3_current<SpaModels[mNo].Pump2_Hi_min)
        {
            MsgMain3CS(" (Error)"+Environment::NewLine, Color::Red);
            this->M3_err=true;
        }
        else
        {
            MsgMain3CS(" (Normal)"+Environment::NewLine, Color::Black);
            this->M3_err=false;
        }
    }
    else
    {
        MsgMain3FS(MSG_MAINAD_AD_HINT_M3_HC, FontStyle::Regular);
        this->M3_st=3;
        MsgMain3FS(" : "+this->M3_current+"A", FontStyle::Bold);
        if(DEBUGGING_USEAGE==4)
            MsgMain3CS(".... ("+SpaModels[mNo].Pump2_Hi_Heater_Circ_UV_max+","+SpaModels[mNo].Pump2_Hi_Heater_Circ_UV_min+")", Color::Black);
        if(this->M3_current>SpaModels[mNo].Pump2_Hi_Heater_Circ_UV_max||this->M3_current<SpaModels[mNo].Pump2_Hi_Heater_Circ_UV_min)
        {
            MsgMain3CS(" (Error)"+Environment::NewLine, Color::Red);
            this->M3_err=true;
        }
        else
        {
            MsgMain3CS(" (Normal)"+Environment::NewLine, Color::Black);
            this->M3_err=false;
        }
    }
    //save errors
    this->M3_all_Err=this->textBox_eMsg1->Text+","+this->textBox_eMsg2->Text+","+this->textBox_eMsg3->Text+","+this->textBox_eMsg4->Text;
}

//------//
//  M4  //
//------//
void RDS_main_Form::AD_judge_M4()
{
    int mNo=this->comboBox_Model_Name->SelectedIndex;
    if(mNo<0)
    {
        MessageBox::Show(MSG_AD_MODEL_INDEX_WRONG, "NOTICE",
            MessageBoxButtons::OK,
            MessageBoxIcon::Information);
    }
    if(this->M0_with_HeatCirc==false)
    {
        this->M4_st=1;
        MsgMain3FS(">> Pump-2 Lo", FontStyle::Regular);
        MsgMain3FS(" : "+this->M4_current+"A", FontStyle::Bold);
        if(DEBUGGING_USEAGE==4)
            MsgMain3CS(".... ("+SpaModels[mNo].Pump2_Lo_max+","+SpaModels[mNo].Pump2_Lo_min+")", Color::Black);
        if(this->M4_current>SpaModels[mNo].Pump2_Lo_max||this->M4_current<SpaModels[mNo].Pump2_Lo_min)
        {
            MsgMain3CS(" (Error)"+Environment::NewLine, Color::Red);
            this->M4_err=true;
        }
        else
        {
            MsgMain3CS(" (Normal)"+Environment::NewLine, Color::Black);
            this->M4_err=false;
        }
    }
    else
    {
        this->M4_st=3;
        MsgMain3FS(">> Pump-2 Lo + Heater + Circ + UV", FontStyle::Regular);
        MsgMain3FS(" : "+this->M4_current+"A", FontStyle::Bold);
        if(DEBUGGING_USEAGE==4)
            MsgMain3CS(".... ("+SpaModels[mNo].Pump2_Lo_Heater_Circ_UV_max+","+SpaModels[mNo].Pump2_Lo_Heater_Circ_UV_min+")", Color::Black);
        if(this->M4_current>SpaModels[mNo].Pump2_Lo_Heater_Circ_UV_max||this->M4_current<SpaModels[mNo].Pump2_Lo_Heater_Circ_UV_min)
        {
            MsgMain3CS(" (Error)"+Environment::NewLine, Color::Red);
            this->M4_err=true;
        }
        else
        {
            MsgMain3CS(" (Normal)"+Environment::NewLine, Color::Black);
            this->M4_err=false;
        }
    }
    //save errors
    this->M4_all_Err=this->textBox_eMsg1->Text+","+this->textBox_eMsg2->Text+","+this->textBox_eMsg3->Text+","+this->textBox_eMsg4->Text;
}

//------//
//  M5  //
//------//
void RDS_main_Form::AD_judge_M5()
{
    int mNo=this->comboBox_Model_Name->SelectedIndex;
    if(mNo<0)
    {
        MessageBox::Show(MSG_AD_MODEL_INDEX_WRONG, "NOTICE",
            MessageBoxButtons::OK,
            MessageBoxIcon::Information);
    }
    if(this->M0_with_HeatCirc==false)
    {
        this->M5_st=1;
        MsgMain3FS(MSG_MAINAD_AD_HINT_M5, FontStyle::Regular);
        MsgMain3FS(" : "+this->M5_current+"A", FontStyle::Bold);
        if(DEBUGGING_USEAGE==4)
            MsgMain3CS(".... ("+SpaModels[mNo].Pump3_Hi_max+","+SpaModels[mNo].Pump3_Hi_min+")", Color::Black);
        if(this->M5_current>SpaModels[mNo].Pump3_Hi_max||this->M5_current<SpaModels[mNo].Pump3_Hi_min)
        {
            MsgMain3CS(" (Error)"+Environment::NewLine, Color::Red);
            this->M5_err=true;
        }
        else
        {
            MsgMain3CS(" (Normal)"+Environment::NewLine, Color::Black);
            this->M5_err=false;
        }
    }
    else
    {
        this->M5_st=3;
        MsgMain3FS(MSG_MAINAD_AD_HINT_M5_HC, FontStyle::Regular);
        MsgMain3FS(" : "+this->M5_current+"A", FontStyle::Bold);
        if(DEBUGGING_USEAGE==4)
            MsgMain3CS(".... ("+SpaModels[mNo].Pump3_Hi_Heater_Circ_UV_max+","+SpaModels[mNo].Pump3_Hi_Heater_Circ_UV_min+")", Color::Black);
        if(this->M5_current>SpaModels[mNo].Pump3_Hi_Heater_Circ_UV_max||this->M5_current<SpaModels[mNo].Pump3_Hi_Heater_Circ_UV_min)
        {
            MsgMain3CS(" (Error)"+Environment::NewLine, Color::Red);
            this->M5_err=true;
        }
        else
        {
            MsgMain3CS(" (Normal)"+Environment::NewLine, Color::Black);
            this->M5_err=false;
        }
    }
    //save errors
    this->M5_all_Err=this->textBox_eMsg1->Text+","+this->textBox_eMsg2->Text+","+this->textBox_eMsg3->Text+","+this->textBox_eMsg4->Text;
}

//------//
//  M6  //
//------//
void RDS_main_Form::AD_judge_M6()
{
    int mNo=this->comboBox_Model_Name->SelectedIndex;
    if(mNo<0)
    {
        MessageBox::Show(MSG_AD_MODEL_INDEX_WRONG, "NOTICE",
            MessageBoxButtons::OK,
            MessageBoxIcon::Information);
    }
    if(this->M0_with_HeatCirc==false)
    {
        this->M6_st=1;
        MsgMain3FS(MSG_MAINAD_AD_HINT_M6, FontStyle::Regular);
        MsgMain3FS(" : "+this->M6_current+"A", FontStyle::Bold);
        if(DEBUGGING_USEAGE==4)
            MsgMain3CS(".... ("+SpaModels[mNo].Pump3_Lo_max+","+SpaModels[mNo].Pump3_Lo_min+")", Color::Black);
        if(this->M6_current>SpaModels[mNo].Pump3_Lo_max||this->M6_current<SpaModels[mNo].Pump3_Lo_min)
        {
            MsgMain3CS(" (Error)"+Environment::NewLine, Color::Red);
            this->M6_err=true;
        }
        else
        {
            MsgMain3CS(" (Normal)"+Environment::NewLine, Color::Black);
            this->M6_err=false;
        }
    }
    else
    {
        this->M6_st=3;
        MsgMain3FS(MSG_MAINAD_AD_HINT_M6_HC, FontStyle::Regular);
        MsgMain3FS(" : "+this->M6_current+"A", FontStyle::Bold);
        if(DEBUGGING_USEAGE==4)
            MsgMain3CS(".... ("+SpaModels[mNo].Pump3_Lo_Heater_Circ_UV_max+","+SpaModels[mNo].Pump3_Lo_Heater_Circ_UV_min+")", Color::Black);
        if(this->M6_current>SpaModels[mNo].Pump3_Lo_Heater_Circ_UV_max||this->M6_current<SpaModels[mNo].Pump3_Lo_Heater_Circ_UV_min)
        {
            MsgMain3CS(" (Error)"+Environment::NewLine, Color::Red);
            this->M6_err=true;
        }
        else
        {
            MsgMain3CS(" (Normal)"+Environment::NewLine, Color::Black);
            this->M6_err=false;
        }
    }
    //save errors
    this->M6_all_Err=this->textBox_eMsg1->Text+","+this->textBox_eMsg2->Text+","+this->textBox_eMsg3->Text+","+this->textBox_eMsg4->Text;
}

//------//
//  M7  //
//------//
void RDS_main_Form::AD_judge_M7()
{
    int mNo=this->comboBox_Model_Name->SelectedIndex;
    if(mNo<0)
    {
        MessageBox::Show(MSG_AD_MODEL_INDEX_WRONG, "NOTICE",
            MessageBoxButtons::OK,
            MessageBoxIcon::Information);
    }
    this->M7_st=1;
    if(this->M0_with_HeatCirc==false)
    {
        MsgMain3FS(MSG_MAINAD_AD_HINT_M7, FontStyle::Regular);
        MsgMain3FS(" : "+this->M7_current+"A", FontStyle::Bold);
        if(DEBUGGING_USEAGE==4)
            MsgMain3CS(".... ("+SpaModels[mNo].Blower_max+","+SpaModels[mNo].Blower_min+")", Color::Black);
        if(this->M7_current>SpaModels[mNo].Blower_max||this->M7_current<SpaModels[mNo].Blower_min)
        {
            MsgMain3CS(" (Error)"+Environment::NewLine, Color::Red);
            this->M7_err=true;
        }
        else
        {
            MsgMain3CS(" (Normal)"+Environment::NewLine, Color::Black);
            this->M7_err=false;
        }
    }
    else
    {
        this->M7_st=3;
        MsgMain3FS(MSG_MAINAD_AD_HINT_M7_HC, FontStyle::Regular);
        MsgMain3FS(" : "+this->M7_current+"A", FontStyle::Bold);
        if(DEBUGGING_USEAGE==4)
            MsgMain3CS(".... ("+SpaModels[mNo].Blower_Heater_Circ_UV_max+","+SpaModels[mNo].Blower_Heater_Circ_UV_min+")", Color::Black);
        if(this->M7_current>SpaModels[mNo].Blower_Heater_Circ_UV_max||this->M7_current<SpaModels[mNo].Blower_Heater_Circ_UV_min)
        {
            MsgMain3CS(" (Error)"+Environment::NewLine, Color::Red);
            this->M7_err=true;
        }
        else
        {
            MsgMain3CS(" (Normal)"+Environment::NewLine, Color::Black);
            this->M7_err=false;
        }
    }
    //save errors
    this->M7_all_Err=this->textBox_eMsg1->Text+","+this->textBox_eMsg2->Text+","+this->textBox_eMsg3->Text+","+this->textBox_eMsg4->Text;
}

//===========================//
//  Judge Error Cause Equip  // for doing AD case
//===========================//
void RDS_main_Form::AD_judge_CauseEquip()
{
    int No_in_CE;
    int IndexArry[8];
    Boolean iFound;
    unsigned char TmpEquip[AUTO_DIAGNOSIS_MAX_EQUIP];

    //Step-1: all current measure
    AD_CauseEquip_TotalCnt=0;
    if(M0_HC_err==true)
    {
        AD_all_Cause[AD_CauseEquip_TotalCnt]=20; //heater error
        TmpEquip[AD_CauseEquip_TotalCnt]=20;
        AD_CauseEquip_TotalCnt++;
    }
    if(M0_C_err==true)
    {
        AD_all_Cause[AD_CauseEquip_TotalCnt]=19; //Circ+UV error
        TmpEquip[AD_CauseEquip_TotalCnt]=19;
        AD_CauseEquip_TotalCnt++;
    }
    if(M0_C_err==false&&M0_C_all_Err->IndexOf("FSO")!=-1)
    { //get FSO error when measure Circ+UV
        AD_all_Cause[AD_CauseEquip_TotalCnt]=7;    //flow swicth defect!!1
        TmpEquip[AD_CauseEquip_TotalCnt]=7;
        AD_CauseEquip_TotalCnt++;
    }
    if(M1_err==true)
    {
        AD_all_Cause[AD_CauseEquip_TotalCnt]=12; //Pump-1 Hi
        TmpEquip[AD_CauseEquip_TotalCnt]=12;
        AD_CauseEquip_TotalCnt++;
    }
    if(M2_err==true)
    {
        AD_all_Cause[AD_CauseEquip_TotalCnt]=13; //Pump-1 Lo
        TmpEquip[AD_CauseEquip_TotalCnt]=12;
        AD_CauseEquip_TotalCnt++;
    }
    if(M3_err==true)
    {
        AD_all_Cause[AD_CauseEquip_TotalCnt]=14; //Pump-2 Hi
        TmpEquip[AD_CauseEquip_TotalCnt]=14;
        AD_CauseEquip_TotalCnt++;
    }
    if(M4_err==true)
    {
        AD_all_Cause[AD_CauseEquip_TotalCnt]=15; //Pump-2 Lo
        TmpEquip[AD_CauseEquip_TotalCnt]=14;
        AD_CauseEquip_TotalCnt++;
    }
    if(M5_err==true)
    {
        AD_all_Cause[AD_CauseEquip_TotalCnt]=16; //Pump-3 Hi
        TmpEquip[AD_CauseEquip_TotalCnt]=16;
        AD_CauseEquip_TotalCnt++;
    }
    if(M6_err==true)
    {
        AD_all_Cause[AD_CauseEquip_TotalCnt]=17; //Pump-3 Lo
        TmpEquip[AD_CauseEquip_TotalCnt]=16;
        AD_CauseEquip_TotalCnt++;
    }
    if(M7_err==true)
    {
        AD_all_Cause[AD_CauseEquip_TotalCnt]=18; //blower
        TmpEquip[AD_CauseEquip_TotalCnt]=18;
        AD_CauseEquip_TotalCnt++;
    }

    if(Flow_err==true)
    {
        AD_all_Cause[AD_CauseEquip_TotalCnt]=7; //flow switch
        TmpEquip[AD_CauseEquip_TotalCnt]=7;
        AD_CauseEquip_TotalCnt++;
    }

    //step-2: starting 4 error code and current 4 error
    IndexArry[0]=this->StartErr_index1;
    IndexArry[1]=this->StartErr_index2;
    IndexArry[2]=this->StartErr_index3;
    IndexArry[3]=this->StartErr_index4;
    IndexArry[4]=this->iCmd.iSPA.msg_index_1;
    IndexArry[5]=this->iCmd.iSPA.msg_index_2;
    IndexArry[6]=this->iCmd.iSPA.msg_index_3;
    IndexArry[7]=this->iCmd.iSPA.msg_index_4;

    for(int i=0; i<8; i++)
    {
        if(IndexArry[i]!=SPA_NO_ERROR_DEFAULT_INDEX)
        {  //if 31, means no error
            No_in_CE=SPA_ERR_TABLE[IndexArry[i]].cause_no;
            if(No_in_CE!=0)
            {
                for(int j=0; j<No_in_CE; j++)
                {
                    if(AD_CauseEquip_TotalCnt==0)
                    { //just copy
                        AD_all_Cause[AD_CauseEquip_TotalCnt]=SPA_ERR_TABLE[IndexArry[i]].cause[j].code;
                        TmpEquip[AD_CauseEquip_TotalCnt]=SPA_ERR_TABLE[IndexArry[i]].equipment[j].code;
                        AD_CauseEquip_TotalCnt++;
                    }
                    else
                    { //comapre first, if it's new, then add-in
                        iFound=false;
                        for(int k=0; k<AD_CauseEquip_TotalCnt; k++)
                        { //scan old items
                            if(AD_all_Cause[k]==SPA_ERR_TABLE[IndexArry[i]].cause[j].code)
                            {
                                iFound=true;
                                break;  //exit this for-loop k
                            }
                        }//end for k
                        if(iFound==false)
                        {//it's new,add it!
                            AD_all_Cause[AD_CauseEquip_TotalCnt]=SPA_ERR_TABLE[IndexArry[i]].cause[j].code;
                            TmpEquip[AD_CauseEquip_TotalCnt]=SPA_ERR_TABLE[IndexArry[i]].equipment[j].code;
                            AD_CauseEquip_TotalCnt++;
                        }
                    }//end-if
                }//end for j
            }//end-if-------------------------No_in_CE !=0-----
        }//ned-if==== index!=SPA_NO_ERROR_DEFAULT_INDEX
    }//end for i

    //step-3, combine duplicate items in equpiments
    AD_Equip_FinalCnt=0;
    if(AD_CauseEquip_TotalCnt!=0)
    {
        //scan TmpEquip[]..
        for(int m=0; m<AD_CauseEquip_TotalCnt; m++)
        {
            if(m==0)
            {
                //just copy
                AD_all_Equip[AD_Equip_FinalCnt]=TmpEquip[0];
                AD_Equip_FinalCnt++;
            }
            else
            {
                //scan all previous items
                Boolean dFound=false;
                int n=0;
                while(n<m)
                {
                    if(TmpEquip[m]==TmpEquip[n]) dFound=true;
                    n++;
                }//end while loop n
                if(dFound==false)
                { //copy
                    AD_all_Equip[AD_Equip_FinalCnt]=TmpEquip[m];
                    AD_Equip_FinalCnt++;
                }
            }//end if m=0
        }//end for loop m
    }//end if zero
}

//===========================//
//  Judge Error Cause Equip  // for not doing AD case
//===========================//
void RDS_main_Form::noneAD_judge_CauseEquip()
{
    int No_in_CE;
    int IndexArry[8];
    Boolean iFound;
    unsigned char TmpEquip[AUTO_DIAGNOSIS_MAX_EQUIP];

    AD_CauseEquip_TotalCnt=0;

    //no step1 measure current....

    //step-2: starting 4 error code and current 4 error
    IndexArry[0]=this->StartErr_index1;
    IndexArry[1]=this->StartErr_index2;
    IndexArry[2]=this->StartErr_index3;
    IndexArry[3]=this->StartErr_index4;
    IndexArry[4]=this->iCmd.iSPA.msg_index_1;
    IndexArry[5]=this->iCmd.iSPA.msg_index_2;
    IndexArry[6]=this->iCmd.iSPA.msg_index_3;
    IndexArry[7]=this->iCmd.iSPA.msg_index_4;

    for(int i=0; i<8; i++)
    {
        if(IndexArry[i]!=SPA_NO_ERROR_DEFAULT_INDEX)
        {  //if 31, means no error
            No_in_CE=SPA_ERR_TABLE[IndexArry[i]].cause_no;
            if(No_in_CE!=0)
            {
                for(int j=0; j<No_in_CE; j++)
                {
                    if(AD_CauseEquip_TotalCnt==0)
                    { //just copy
                        AD_all_Cause[AD_CauseEquip_TotalCnt]=SPA_ERR_TABLE[IndexArry[i]].cause[j].code;
                        TmpEquip[AD_CauseEquip_TotalCnt]=SPA_ERR_TABLE[IndexArry[i]].equipment[j].code;
                        AD_CauseEquip_TotalCnt++;
                    }
                    else
                    { //comapre first, if it's new, then add-in
                        iFound=false;
                        for(int k=0; k<AD_CauseEquip_TotalCnt; k++)
                        { //scan old items
                            if(AD_all_Cause[k]==SPA_ERR_TABLE[IndexArry[i]].cause[j].code)
                            {
                                iFound=true;
                                break;  //exit this for-loop k
                            }
                        }//end for k
                        if(iFound==false)
                        {//it's new,add it!
                            AD_all_Cause[AD_CauseEquip_TotalCnt]=SPA_ERR_TABLE[IndexArry[i]].cause[j].code;
                            TmpEquip[AD_CauseEquip_TotalCnt]=SPA_ERR_TABLE[IndexArry[i]].equipment[j].code;
                            AD_CauseEquip_TotalCnt++;
                        }
                    }//end-if
                }//end for j
            }//end-if-------------------------No_in_CE !=0-----
        }//ned-if==== index!=SPA_NO_ERROR_DEFAULT_INDEX
    }//end for i

    //step-3, combine duplicate items in equpiments
    AD_Equip_FinalCnt=0;
    if(AD_CauseEquip_TotalCnt!=0)
    {
        //scan TmpEquip[]..
        for(int m=0; m<AD_CauseEquip_TotalCnt; m++)
        {
            if(m==0)
            {
                //just copy
                AD_all_Equip[AD_Equip_FinalCnt]=TmpEquip[0];
                AD_Equip_FinalCnt++;
            }
            else
            {
                //scan all previous items
                Boolean dFound=false;
                int n=0;
                while(n<m)
                {
                    if(TmpEquip[m]==TmpEquip[n]) dFound=true;
                    n++;
                }//end while loop n
                if(dFound==false)
                { //copy
                    AD_all_Equip[AD_Equip_FinalCnt]=TmpEquip[m];
                    AD_Equip_FinalCnt++;
                }
            }//end if m=0
        }//end for loop m
    }//end if zero
}