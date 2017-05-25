//project defines
#include "RDS_project.h"

//for VC program all forms
#include "RDS_main_Form.h"

//related objects
#include "IOTcommunicator.h"
#include "spa_cmd.h"
#include "SPA.h"

//error message gobal table
#include "ErrMsg.h"

//global variable........
#include "main_global.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Threading;
// ----- my main..
using namespace RDS;

//The function body of class RDS_main_Form here --------------------------------------------
//------------- UI update display related functions

//============================//
// Update UI from SPA status  //
//============================//
System::Void RDS_main_Form::UpdateUIfromSPA()
{
    //SPA configruation
    //P1 mode
    if(this->iCmd.iSPA.p1_mode==2)
    {
        this->button_P1_Hi->Visible=true;
        this->button_P1_Lo->Visible=true;
    }
    else if(this->iCmd.iSPA.p1_mode==1)
    {
        this->button_P1_Hi->Visible=true;
        this->button_P1_Lo->Visible=false;
    }
    else
    {
        this->button_P1_Hi->Visible=false;
        this->button_P1_Lo->Visible=false;
    }
    //P2 mode
    if(this->iCmd.iSPA.p2_mode==2)
    {
        this->button_P2_Hi->Visible=true;
        this->button_P2_Lo->Visible=true;
    }
    else if(this->iCmd.iSPA.p2_mode==1)
    {
        this->button_P2_Hi->Visible=true;
        this->button_P2_Lo->Visible=false;
    }
    else
    {
        this->button_P2_Hi->Visible=false;
        this->button_P2_Lo->Visible=false;
    }
    //P3 mode
    if(this->iCmd.iSPA.p3_mode==2)
    {
        this->button_P3_Hi->Visible=true;
        this->button_P3_Lo->Visible=true;
    }
    else if(this->iCmd.iSPA.p3_mode==1)
    {
        this->button_P3_Hi->Visible=true;
        this->button_P3_Lo->Visible=false;
    }
    else
    {
        this->button_P3_Hi->Visible=false;
        this->button_P3_Lo->Visible=false;
    }
    //Blower mode
    if(this->iCmd.iSPA.has_blower==true) this->button_Blower_OnOff->Visible=true;
    else   this->button_Blower_OnOff->Visible=false;

    //High-end or low-end filter scheduel
    if(this->iCmd.iSPA.is_HighEnd_Fsch==true)
    {
        this->button_Filtration_sch->Visible=true;
        this->button_PF->Visible=false;
        this->button_SF->Visible=false;
    }
    else
    {
        this->button_Filtration_sch->Visible=false;
        this->button_PF->Visible=true;
        this->button_SF->Visible=true;
    }

    //============================================
    //        show light and color....
    //============================================
    //P1
    if(this->iCmd.iSPA.p1_hi_on==true)
    {
        this->button_P1_Hi->Image=Image::FromFile("button_on.png");
    }
    else
    {
        this->button_P1_Hi->Image=Image::FromFile("button_off.png");
    }
    if(this->iCmd.iSPA.p1_lo_on==true)
    {
        this->button_P1_Lo->Image=Image::FromFile("button_on.png");
    }
    else
    {
        this->button_P1_Lo->Image=Image::FromFile("button_off.png");
    }
    if(this->iCmd.iSPA.p1_hi_on==true||this->iCmd.iSPA.p1_lo_on==true)
    {
        this->pictureBox_P1_MCU->Image=Image::FromFile("light_on_yellow.png");
    }
    else
    {
        this->pictureBox_P1_MCU->Image=Image::FromFile("light_off.png");
    }
    //P2
    if(this->iCmd.iSPA.p2_hi_on==true)
    {
        this->button_P2_Hi->Image=Image::FromFile("button_on.png");
    }
    else
    {
        this->button_P2_Hi->Image=Image::FromFile("button_off.png");
    }
    if(this->iCmd.iSPA.p2_lo_on==true)
    {
        this->button_P2_Lo->Image=Image::FromFile("button_on.png");
    }
    else
    {
        this->button_P2_Lo->Image=Image::FromFile("button_off.png");
    }
    if(this->iCmd.iSPA.p2_hi_on==true||this->iCmd.iSPA.p2_lo_on==true)
    {
        this->pictureBox_P2_MCU->Image=Image::FromFile("light_on_yellow.png");
    }
    else
    {
        this->pictureBox_P2_MCU->Image=Image::FromFile("light_off.png");
    }
    //P3
    if(this->iCmd.iSPA.p3_hi_on==true)
    {
        this->button_P3_Hi->Image=Image::FromFile("button_on.png");
    }
    else
    {
        this->button_P3_Hi->Image=Image::FromFile("button_off.png");
    }
    if(this->iCmd.iSPA.p3_lo_on==true)
    {
        this->button_P3_Lo->Image=Image::FromFile("button_on.png");
    }
    else
    {
        this->button_P3_Lo->Image=Image::FromFile("button_off.png");
    }
    if(this->iCmd.iSPA.p3_hi_on==true||this->iCmd.iSPA.p3_lo_on==true)
    {
        this->pictureBox_P3_MCU->Image=Image::FromFile("light_on_yellow.png");
    }
    else
    {
        this->pictureBox_P3_MCU->Image=Image::FromFile("light_off.png");
    }
    //blower
    if(this->iCmd.iSPA.blower_on==true)
    {
        this->button_Blower_OnOff->Image=Image::FromFile("button_on.png");
        this->pictureBox_Blower_MCU->Image=Image::FromFile("light_on_yellow.png");
    }
    else
    {
        this->button_Blower_OnOff->Image=Image::FromFile("button_off.png");
        this->pictureBox_Blower_MCU->Image=Image::FromFile("light_off.png");
    }
    //CIRC
    if(this->iCmd.iSPA.circ_on==true)
    {
        this->pictureBox_CIRC_MCU->Image=Image::FromFile("light_on_yellow.png");
    }
    else
    {
        this->pictureBox_CIRC_MCU->Image=Image::FromFile("light_off.png");
    }
    //UV
    if(this->iCmd.iSPA.uv_on==true)
    {
        this->pictureBox_UV_MCU->Image=Image::FromFile("light_on_yellow.png");
    }
    else
    {
        this->pictureBox_UV_MCU->Image=Image::FromFile("light_off.png");
    }
    //Heater
    if(this->iCmd.iSPA.heater_on==true)
    {
        this->pictureBox_HT_MCU->Image=Image::FromFile("light_on_yellow.png");
    }
    else
    {
        this->pictureBox_HT_MCU->Image=Image::FromFile("light_off.png");
    }

    //error message area
    this->textBox_eMsg1->Text=gcnew String(eMSG_Table[this->ECset][this->iCmd.iSPA.msg_index_1]);
    this->textBox_eMsg2->Text=gcnew String(eMSG_Table[this->ECset][this->iCmd.iSPA.msg_index_2]);
    this->textBox_eMsg3->Text=gcnew String(eMSG_Table[this->ECset][this->iCmd.iSPA.msg_index_3]);
    this->textBox_eMsg4->Text=gcnew String(eMSG_Table[this->ECset][this->iCmd.iSPA.msg_index_4]);
    if(this->iCmd.iSPA.msg_index_1>=8&&this->iCmd.iSPA.msg_index_1<=11) this->textBox_eMsg1->ForeColor=Color::ForestGreen;
    else                                                                       this->textBox_eMsg1->ForeColor=Color::Maroon;
    if(this->iCmd.iSPA.msg_index_2>=8&&this->iCmd.iSPA.msg_index_2<=11) this->textBox_eMsg2->ForeColor=Color::ForestGreen;
    else                                                                       this->textBox_eMsg2->ForeColor=Color::Maroon;
    if(this->iCmd.iSPA.msg_index_3>=8&&this->iCmd.iSPA.msg_index_3<=11) this->textBox_eMsg3->ForeColor=Color::ForestGreen;
    else                                                                       this->textBox_eMsg3->ForeColor=Color::Maroon;
    if(this->iCmd.iSPA.msg_index_4>=8&&this->iCmd.iSPA.msg_index_4<=11) this->textBox_eMsg4->ForeColor=Color::ForestGreen;
    else                                                                       this->textBox_eMsg4->ForeColor=Color::Maroon;
    if(this->iCmd.iSPA.msg_more_than_4==true) this->panel_Err_Msg->BackColor=Color::MistyRose;
    else this->panel_Err_Msg->BackColor=Color::PowderBlue;

    //Temperature display
    if(Display_initial_OK==true)
    {
        if(this->Display_F==true)
        {
            this->textBox_Cur_T->Text=this->iCmd.iSPA.TEMPADC_To_TEMP_F(this->iCmd.iSPA.cur_Adc_0)+"F";
            this->textBox_HiLmt_T->Text=this->iCmd.iSPA.TEMPADC_To_TEMP_F(this->iCmd.iSPA.cur_Adc_1)+"F";
            this->textBox_PCB_T->Text=this->iCmd.iSPA.TEMPADC_To_TEMP_F(this->iCmd.iSPA.cur_Adc_2)+"F";
            this->textBox_Set_T->Text=this->iCmd.iSPA.TEMPADC_To_TEMP_F(this->iCmd.iSPA.set_Adc)+"F";
        }
        else
        {
            System::Single sv1=this->iCmd.iSPA.TEMPADC_To_TEMP_C(this->iCmd.iSPA.cur_Adc_0)/10.0;
            System::Single sv2=this->iCmd.iSPA.TEMPADC_To_TEMP_C(this->iCmd.iSPA.cur_Adc_1)/10.0;
            System::Single sv3=this->iCmd.iSPA.TEMPADC_To_TEMP_C(this->iCmd.iSPA.cur_Adc_2)/10.0;
            System::Single sv4=this->iCmd.iSPA.TEMPADC_To_TEMP_C(this->iCmd.iSPA.set_Adc)/10.0;
            this->textBox_Cur_T->Text=Convert::ToString(sv1)+"C";
            this->textBox_HiLmt_T->Text=Convert::ToString(sv2)+"C";
            this->textBox_PCB_T->Text=Convert::ToString(sv3)+"C";
            this->textBox_Set_T->Text=Convert::ToString(sv4)+"C";
        }
    }

    //voltage & current measurement
    if(Display_initial_OK==true)
    {
        int Amp_int=this->iCmd.iSPA.CurrentADC_to_Amp(this->iCmd.iSPA.cur_Adc_4);
        this->textBox_Current_Amp->Text=""+Amp_int;
        if(Amp_int==0)
        {
            //show 1 more digit after dot.
            this->textBox_Current_Amp->Text=""+Amp_int+"."+this->iCmd.iSPA.CurrentADC_to_Amp_dot1(this->iCmd.iSPA.cur_Adc_4);
        }
        if(this->iCmd.iSPA.VoltageADC_to_Volt(this->iCmd.iSPA.cur_Adc_3)==-1)
        {
            this->textBox4_System_Voltage->Text="---";
        }
        else
        {
            this->textBox4_System_Voltage->Text=this->iCmd.iSPA.VoltageADC_to_Volt(this->iCmd.iSPA.cur_Adc_3)+"V";
        }
    }

    //relays display area
    //Pump1 relay
    if(this->iCmd.iSPA.relay_err_p1==true)
    {
        this->pictureBox_P1R_status->Image=Image::FromFile("light_on_red.png");
        this->panel_P1R_status->BackColor=Color::MistyRose;
    }
    else
    {
        this->pictureBox_P1R_status->Image=Image::FromFile("light_off.png");
        this->panel_P1R_status->BackColor=Color::LightSteelBlue;
    }
    //Pump2 relay
    if(this->iCmd.iSPA.relay_err_p2==true)
    {
        this->pictureBox_P2R_status->Image=Image::FromFile("light_on_red.png");
        this->panel_P2R_status->BackColor=Color::MistyRose;
    }
    else
    {
        this->pictureBox_P2R_status->Image=Image::FromFile("light_off.png");
        this->panel_P2R_status->BackColor=Color::LightSteelBlue;
    }
    //Pump3 relay
    if(this->iCmd.iSPA.relay_err_p3==true)
    {
        this->pictureBox_P3R_status->Image=Image::FromFile("light_on_red.png");
        this->panel_P3R_status->BackColor=Color::MistyRose;
    }
    else
    {
        this->pictureBox_P3R_status->Image=Image::FromFile("light_off.png");
        this->panel_P3R_status->BackColor=Color::LightSteelBlue;
    }
    //Heater relay
    if(this->iCmd.iSPA.relay_err_ht==true)
    {
        this->pictureBox_RH_status->Image=Image::FromFile("light_on_red.png");
        this->panel_RH_status->BackColor=Color::MistyRose;
    }
    else
    {
        this->pictureBox_RH_status->Image=Image::FromFile("light_off.png");
        this->panel_RH_status->BackColor=Color::LightSteelBlue;
    }
    //Lock buttons
    if(this->iCmd.iSPA.unlock==true)
        this->button_unlock->Image=Image::FromFile("button_on.png");
    else this->button_unlock->Image=Image::FromFile("button_off.png");
    if(this->iCmd.iSPA.lock_Tmpr==true)
        this->button_T_Lock->Image=Image::FromFile("button_on.png");
    else this->button_T_Lock->Image=Image::FromFile("button_off.png");
    if(this->iCmd.iSPA.lock_Pump==true)
        this->button_Pump_Lock->Image=Image::FromFile("button_on.png");
    else this->button_Pump_Lock->Image=Image::FromFile("button_off.png");
    if(this->iCmd.iSPA.lock_Panl==true)
        this->button_Panel_Lock->Image=Image::FromFile("button_on.png");
    else this->button_Panel_Lock->Image=Image::FromFile("button_off.png");
    if(this->iCmd.iSPA.lock_Func==true)
        this->button_Func_Lock->Image=Image::FromFile("button_on.png");
    else this->button_Func_Lock->Image=Image::FromFile("button_off.png");
    //eco mode
    if(this->iCmd.iSPA.ecoModeOn==true)
        this->pictureBox_ECO->Image=Image::FromFile("light_on_yellow.png");
    else this->pictureBox_ECO->Image=Image::FromFile("light_off.png");

    //days
    if(Display_initial_OK==true)
    {
        this->textBox_UV_Days->Text=""+this->iCmd.iSPA.uv_days;
        this->textBox_Filter_Days->Text=""+this->iCmd.iSPA.filter_days;
    }

    //auto-diagnosis area
    if(this->RDS_AD_finish==true) this->button_auto_diag->Image=Image::FromFile("button_on.png");
    else this->button_auto_diag->Image=Image::FromFile("button_off.png");

    if(this->Cannot_AutoD==true)
    {
        this->pictureBox_auto_diag->Image=Image::FromFile("light_on_red.png");
        this->panel_auto_diag->BackColor=Color::MistyRose;
    }
    else
    {
        this->panel_auto_diag->BackColor=Color::CadetBlue;
        if(this->doing_AutoD==true)
        {
            //2016/03/23 for blinking light when A.D.
            if(this->iCmd.ValidPacket_CmdCode==0x40)
                this->pictureBox_auto_diag->Image=Image::FromFile("light_on_green.png");
            if(this->iCmd.ValidPacket_CmdCode==0x41)
                this->pictureBox_auto_diag->Image=Image::FromFile("light_off.png");
        }
        else
        {
            if(this->RDS_AD_finish==true)
                this->pictureBox_auto_diag->Image=Image::FromFile("light_on_yellow.png");
            else
                this->pictureBox_auto_diag->Image=Image::FromFile("light_off.png");
        }
    }

    //TBD....

    //Update the Error/cause/equipment information
    UpdateErrCuaseEquip();

    //extra, enrineer area,----------------------------------------------------------
    //water state
    //this->lbl_WTstate->Text = "WTst=" + this->iCmd.iSPA.water_T_state;
    if(this->iCmd.iSPA.water_T_state==0) this->lbl_WTstate->Text="HTst=Normal";
    else if(this->iCmd.iSPA.water_T_state==1) this->lbl_WTstate->Text="WTst=Summer";
    else if(this->iCmd.iSPA.water_T_state==2) this->lbl_WTstate->Text="WTst=SouthWeat";
    else if(this->iCmd.iSPA.water_T_state==3) this->lbl_WTstate->Text="WTst=OverHeat";
    else if(this->iCmd.iSPA.water_T_state==4) this->lbl_WTstate->Text="WTst=Cool";
    else if(this->iCmd.iSPA.water_T_state==5) this->lbl_WTstate->Text="WTst=IceJet";
    else if(this->iCmd.iSPA.water_T_state==6) this->lbl_WTstate->Text="WTst=IceHeat";
    else if(this->iCmd.iSPA.water_T_state==7) this->lbl_WTstate->Text="WTst=Hot";
    else if(this->iCmd.iSPA.water_T_state==8) this->lbl_WTstate->Text="WTst=Circ";
    else if(this->iCmd.iSPA.water_T_state==9) this->lbl_WTstate->Text="WTst=WatchDog";
    else if(this->iCmd.iSPA.water_T_state==10) this->lbl_WTstate->Text="WTst=WatchDogProtect";
    else if(this->iCmd.iSPA.water_T_state==11) this->lbl_WTstate->Text="WTst=Frozen";
    else if(this->iCmd.iSPA.water_T_state==12) this->lbl_WTstate->Text="WTst=PowerUp";
    else if(this->iCmd.iSPA.water_T_state==13) this->lbl_WTstate->Text="WTst=Flow";
    else this->lbl_WTstate->Text="WTst=??";
    //High-limit state
    //this->lbl_HTstate->Text = "HTst=" + this->iCmd.iSPA.hiLmt_T_state;
    if(this->iCmd.iSPA.hiLmt_T_state==0) this->lbl_HTstate->Text="HTst=Normal";
    else if(this->iCmd.iSPA.hiLmt_T_state==1) this->lbl_HTstate->Text="HTst=Summer";
    else if(this->iCmd.iSPA.hiLmt_T_state==2) this->lbl_HTstate->Text="HTst=SouthWeat";
    else if(this->iCmd.iSPA.hiLmt_T_state==3) this->lbl_HTstate->Text="HTst=OverHeat";
    else if(this->iCmd.iSPA.hiLmt_T_state==4) this->lbl_HTstate->Text="HTst=Cool";
    else if(this->iCmd.iSPA.hiLmt_T_state==5) this->lbl_HTstate->Text="HTst=IceJet";
    else if(this->iCmd.iSPA.hiLmt_T_state==6) this->lbl_HTstate->Text="HTst=IceHeat";
    else if(this->iCmd.iSPA.hiLmt_T_state==7) this->lbl_HTstate->Text="HTst=Hot";
    else if(this->iCmd.iSPA.hiLmt_T_state==8) this->lbl_HTstate->Text="HTst=Circ";
    else if(this->iCmd.iSPA.hiLmt_T_state==9) this->lbl_HTstate->Text="HTst=WatchDog";
    else if(this->iCmd.iSPA.hiLmt_T_state==10) this->lbl_HTstate->Text="HTst=WatchDogProtect";
    else if(this->iCmd.iSPA.hiLmt_T_state==11) this->lbl_HTstate->Text="HTst=Frozen";
    else if(this->iCmd.iSPA.hiLmt_T_state==12) this->lbl_HTstate->Text="HTst=PowerUp";
    else if(this->iCmd.iSPA.hiLmt_T_state==13) this->lbl_HTstate->Text="HTst=Flow";
    else this->lbl_HTstate->Text="HTst=??";
    //water level
    this->lbl_WLv->Text="WLv="+this->iCmd.iSPA.waterLevel;
}

//============================//
// Update Error Information   //
//============================//
System::Void RDS_main_Form::UpdateErrCuaseEquip()
{
    Boolean chk1, chk2, chk3, chk4;
    String^ tmpStr;
    //checking connection okay and display okay
    if(Display_initial_OK==true)
    {
        //checking it was not showed
        if(Err_showed==false)
        {
            //first time show err. and save it
            MsgMain2(MSG_MAINUI_ERRCODE_START_LINE);
            if(this->iCmd.iSPA.msg_index_1==SPA_NO_ERROR_DEFAULT_INDEX
                && this->iCmd.iSPA.msg_index_2==SPA_NO_ERROR_DEFAULT_INDEX
                && this->iCmd.iSPA.msg_index_3==SPA_NO_ERROR_DEFAULT_INDEX
                && this->iCmd.iSPA.msg_index_4==SPA_NO_ERROR_DEFAULT_INDEX
                )
            {
                //MsgMain(" received Error codes: None");
            }
            else
            {
                //MsgMain(" received Error codes:");
                showErrCuaseEquip(this->iCmd.iSPA.msg_index_1);
                showErrCuaseEquip(this->iCmd.iSPA.msg_index_2);
                showErrCuaseEquip(this->iCmd.iSPA.msg_index_3);
                showErrCuaseEquip(this->iCmd.iSPA.msg_index_4);
                this->Some_MsgIndex_AD_fail=false; //after all 4 index checked, we reset it
            }
            this->err_msg_index_1=this->iCmd.iSPA.msg_index_1; //save error, for future checking
            this->err_msg_index_2=this->iCmd.iSPA.msg_index_2;
            this->err_msg_index_3=this->iCmd.iSPA.msg_index_3;
            this->err_msg_index_4=this->iCmd.iSPA.msg_index_4;
            Err_showed=true;
        }
        else
        {
            //checking it is different Codes or not
            if(this->err_msg_index_1!=this->iCmd.iSPA.msg_index_1) chk1=true;
            else                                                      chk1=false;
            if(this->err_msg_index_2!=this->iCmd.iSPA.msg_index_2) chk2=true;
            else                                                      chk2=false;
            if(this->err_msg_index_3!=this->iCmd.iSPA.msg_index_3) chk3=true;
            else                                                      chk3=false;
            if(this->err_msg_index_4!=this->iCmd.iSPA.msg_index_4) chk4=true;
            else                                                      chk4=false;

            //update message when different
            if(chk1||chk2||chk3||chk4)
            {
                if(this->doing_AutoD==true)
                {
                    tmpStr=MSG_MAINUI_ERRCODE_CHANGE_HINT+
                        this->textBox_eMsg1->Text+this->textBox_eMsg2->Text+this->textBox_eMsg3->Text+this->textBox_eMsg4->Text;
                    MsgMain2(tmpStr);
                }
                else
                {
                    MsgMain2(MSG_MAINUI_ERRCODE_START_LINE);
                    if(this->iCmd.iSPA.msg_index_1==SPA_NO_ERROR_DEFAULT_INDEX
                        && this->iCmd.iSPA.msg_index_2==SPA_NO_ERROR_DEFAULT_INDEX
                        && this->iCmd.iSPA.msg_index_3==SPA_NO_ERROR_DEFAULT_INDEX
                        && this->iCmd.iSPA.msg_index_4==SPA_NO_ERROR_DEFAULT_INDEX
                        )
                    {
                        //MsgMain(" received Error codes: None");
                    }
                    else
                    {
                        //MsgMain(" received Error codes:");
                        showErrCuaseEquip(this->iCmd.iSPA.msg_index_1);
                        showErrCuaseEquip(this->iCmd.iSPA.msg_index_2);
                        showErrCuaseEquip(this->iCmd.iSPA.msg_index_3);
                        showErrCuaseEquip(this->iCmd.iSPA.msg_index_4);
                        this->Some_MsgIndex_AD_fail=false; //after all 4 index checked, we reset it
                    }
                }//end-if it's doing Auto-Diagnosis
                this->err_msg_index_1=this->iCmd.iSPA.msg_index_1; //save new errors
                this->err_msg_index_2=this->iCmd.iSPA.msg_index_2;
                this->err_msg_index_3=this->iCmd.iSPA.msg_index_3;
                this->err_msg_index_4=this->iCmd.iSPA.msg_index_4;
            }//end-if message changed
        }//end-if it is firsttime show error
    } //end-if display initial ok
}

System::Void RDS_main_Form::showErrCuaseEquip(unsigned int msg_index)
{
    String^ disp_Str;
    int total_No, i;
    //dont process when code is non error
    if(msg_index==SPA_NO_ERROR_DEFAULT_INDEX) return;

    //check the index over current reall max....
    if(msg_index>=MAX_NUMBER_OF_ERR_CODE) return;

    //dont process Lock message
    //if (msg_index == 8 || msg_index == 9 || msg_index == 10  || msg_index == 11) return;

    //display code & definition
    MsgMain2(MSG_MAINUI_ERRCODE_ONE_CODE_START);
    MsgMain2UL(MSG_MAINUI_ERRCODE_DEFINITION_HEADER+gcnew String(SPA_ERR_TABLE[msg_index].err_code[this->ECset]));
    MsgMain2(" "+gcnew String(SPA_ERR_TABLE[msg_index].definition));
    MsgMain2("");
    if(SPA_ERR_TABLE[msg_index].sol_no!=0)
    { //----------sol part
        MsgMain2UL(MSG_MAINUI_ERRCODE_SOLUTION_TITLE);
        total_No=SPA_ERR_TABLE[msg_index].sol_no;
        i=0;
        do
        {
            MsgMain2(""+gcnew String(SPA_ERR_TABLE[msg_index].sol[i]));
            i++;
        } while(i<total_No);
        //MsgMain2("");
    }
    if(SPA_ERR_TABLE[msg_index].follow_no!=0)
    { //----------follow part
        MsgMain2UL(MSG_MAINUI_ERRCODE_FOLLOWUP_TITLE);
        total_No=SPA_ERR_TABLE[msg_index].follow_no;
        i=0;
        do
        {
            MsgMain2(" ("+(i+1)+")"+gcnew String(SPA_ERR_TABLE[msg_index].follow[i]));
            i++;
        } while(i<total_No);
        MsgMain2("");
    }
    if(SPA_ERR_TABLE[msg_index].cause_no!=0)
    { //----------cause part
        MsgMain2UL(MSG_MAINUI_ERRCODE_CAUSE_TITLE);
        total_No=SPA_ERR_TABLE[msg_index].cause_no;
        disp_Str="";
        i=0;
        do
        {
            //MsgMain2(" (" + (i+1) + ")" + gcnew String(SPA_ERR_TABLE[msg_index].cause[i]));
            disp_Str=disp_Str+gcnew String(SPA_ERR_TABLE[msg_index].cause[i].CE_string)+" / ";
            i++;
        } while(i<total_No);
        MsgMain2(disp_Str);
        MsgMain2("");
    }
    if(SPA_ERR_TABLE[msg_index].equip_no!=0)
    { //-----------equipment part
        MsgMain2UL(MSG_MAINUI_ERRCODE_EQUIPMENT_TITLE);
        total_No=SPA_ERR_TABLE[msg_index].equip_no;
        disp_Str=MSG_MAINUI_ERRCODE_MUST_EQUIPEMNT;
        i=0;
        do
        {
            //MsgMain2(" (" + (i+1) + ")" + gcnew String(SPA_ERR_TABLE[msg_index].equipment[i]));
            disp_Str=disp_Str+" / "+gcnew String(SPA_ERR_TABLE[msg_index].equipment[i].CE_string);
            i++;
        } while(i<total_No);
        MsgMain2(disp_Str);
    }

    //check some error codes which can not do Auto-diagnosis
    if(msg_index==22||msg_index==14||msg_index==26    //WD, FLO2, TPD
        ||msg_index==0||msg_index==1||msg_index==2||msg_index==3    //SN1,SN2,SN3,SN4
        ||msg_index==15||msg_index==16||msg_index==17||msg_index==18)   //R1,R2,R3,RH
    {
        Show_NeedService();
        this->Cannot_AutoD=true;
        this->Some_MsgIndex_AD_fail=true; //we set flag for this scanning index already be cannot A.D.
        MsgLog("AN:"+gcnew String(SPA_ERR_TABLE[msg_index].err_code[this->ECset]));
        this->doing_AutoD=false;
        this->button_auto_diag->Enabled=true;
    }
    else
    {
        if(this->Cannot_AutoD==true&&this->Some_MsgIndex_AD_fail==false)
        {
            //if and only if, when first index scanning and last tine is cannot-A.D.
            this->Cannot_AutoD=false;
            MsgLog("AA");
            this->button_auto_diag->Enabled=true;
        }
    }
}

//============================//
// Update UI from IOT status  //
//============================//
System::Void RDS_main_Form::UpdateUIfromIOT()
{
    //Connection area
    if(this->iCmd.iIOTctrl.initial_OK=false)
    {
        //can not running (DLL problem..., it should not happened)
        this->button_connect->Image=Image::FromFile("button_off.png");
        this->pictureBox_connect_light->Image=Image::FromFile("light_on_red.png");
        this->pictureBox_packet_sign->Image=Image::FromFile("light_off.png");
        this->panel_connect->BackColor=Color::MistyRose;
    }
    else
    {
        //Normally, initial Okay....
        //Here only change & light. The background will changed when fail to connect
        if(this->iCmd.iIOTctrl.connect_OK==true)
        {
            this->button_connect->Image=Image::FromFile("button_on.png");
            this->pictureBox_connect_light->Image=Image::FromFile("light_on_yellow.png");
            this->panel_connect->BackColor=Color::CadetBlue;
        }
        else
        {  //connect fail
            this->button_connect->Image=Image::FromFile("button_off.png");
            if(this->iCmd.iIOTctrl.session_Fatal==true)
            {
                MsgEngr("Lost connection... please check & re-connect...");
                this->panel_connect->BackColor=Color::MistyRose;   //something wrong, please check!! (success first, then fail)
            }
            else
            {
                if(this->tryConnect==true)
                {
                    this->pictureBox_connect_light->Image=Image::FromFile("light_on_red.png");
                    this->panel_connect->BackColor=Color::MistyRose;  //fail case
                }
                else
                {
                    MsgEngr("just UI update.....");
                    this->panel_connect->BackColor=Color::CadetBlue;  //normal waiting case.
                    this->pictureBox_connect_light->Image=Image::FromFile("light_off.png");
                }
            }
        }
        //
        if(this->iCmd.iIOTctrl.packet_OK==true&&Display_initial_OK==true)
            this->pictureBox_packet_sign->Image=Image::FromFile("light_on_yellow.png");
        else this->pictureBox_packet_sign->Image=Image::FromFile("light_off.png");
    }
    //Engineer area
    this->lbl_PktLoss->Text=""+this->iCmd.iIOTctrl.PacketLostCount;
    this->lbl_PSN->Text=""+this->iCmd.iIOTctrl.PacketSN;
    this->lbl_PktTimeOut->Text=""+this->iCmd.iIOTctrl.readTimeOutCount;
    this->lbl_writeTimeout->Text="wTO="+this->iCmd.iIOTctrl.writeTimeOutCount;
    this->lbl_writePktCount->Text="wPkt="+this->iCmd.iIOTctrl.PacketWriteCount;
    this->lb_wait_pkt->Text="wait_Pkt="+this->packets_during_wait;
    this->lb_wait_cmd->Text="wait_cmd="+this->Cmd_during_wait;
    this->lb_wait_NBcmd->Text="wait_NBcmd="+this->NotBroadcastCmd_during_wait;
    if(this->iCmd.iIOTctrl.sessionRead_OK==true)
    {
        float PacketRate=(float)this->iCmd.iIOTctrl.PacketOkCount/
            (this->iCmd.iIOTctrl.PacketOkCount
                +this->iCmd.iIOTctrl.readTimeOutCount
                +this->iCmd.iIOTctrl.PacketLostCount);
        this->lbl_pktRate->Text=String::Format("{0:P}", PacketRate);
    }
}

//======================//
// UI Update (all)      //
//======================//
System::Void RDS_main_Form::UpdateUI()
{
    Thread::Sleep(WAIT_BEFORE_UI_UPDATE);
    UpdateUIfromIOT();
    UpdateUIfromSPA();
    //Update RDS related UI
    if(this->RDS_SCno_produced==true) this->button_Service_Call->Image=Image::FromFile("button_on.png");
    else this->button_Service_Call->Image=Image::FromFile("button_off.png");
    if(this->RDS_rpt_saved==true) this->button_RDS_report->Image=Image::FromFile("button_on.png");
    else this->button_RDS_report->Image=Image::FromFile("button_off.png");
}

//======================//
// for Waiting Command  //
//======================//
System::Void RDS_main_Form::SetWaitingCmd(unsigned char cmd)
{
    this->iCmd.waitCmdCode=cmd;
    WaitCmd=cmd;
    dt=DateTime::Now; //save current time for checking
    retry_times=0;
    packets_during_wait=0;
    Cmd_during_wait=0;
    NotBroadcastCmd_during_wait=0;
    this->Cursor=Cursors::WaitCursor; //it may take time....
}
System::Void RDS_main_Form::ClearWaitingCmd()
{
    this->iCmd.waitCmdCode=0;
    WaitCmd=0;
    retry_times=0;
    packets_during_wait=0;
    Cmd_during_wait=0;
    NotBroadcastCmd_during_wait=0;
    this->Cursor=Cursors::Default; //reset cursor
}

//======================//
// Display (Delegate)   //
//======================//
void RDS_main_Form::DisplayText(array<unsigned char>^ buffer)
{
    if(this->iCmd.iIOTctrl.sessionRead_OK==true)
    {
        if(this->iCmd.iIOTctrl.packet_Loss==true)
        {
            MsgEngr("Packet Lost!!");
        }

        //***********************************************************
        //  Parse command here   ************************************
        this->iCmd.parse(buffer);

        //To reduce message, we only show message after parse command.
        //Mark-out following line to show every packet received
        //if (this->iCmd.parseFail == true || this->iCmd.cmdPktisValid == false)
        //	MsgEngr(String::Format("{0}:", BitConverter::ToString(buffer)));
        if(this->iCmd.cmdPktisValid==true)
            MsgEngr(String::Format("{0}:OK,{1}", BitConverter::ToString(buffer), this->iCmd.CurrentPacket_InputPtr));
        else MsgEngr(String::Format("{0}:NG,{1}", BitConverter::ToString(buffer), this->iCmd.CurrentPacket_InputPtr));
    }
    else
    {
        if(this->iCmd.iIOTctrl.sessionRead_TimeOut==false)
        {
            //time-out is ok, The others is error
            MsgEngr("IOTC session read fail !!!");
            MsgEngr_IOT_error();
        }
    }
    //show valid comand ....
    if(this->iCmd.cmdPktisValid==true)
    {
        this->lbl_validCMDcode->Text=String::Format("CMD={0:X00} ({1})", this->iCmd.ValidPacket_CmdCode, this->iCmd.received_ValidPacket);
        //Overall, first command !!!!!!!!!!!!!!!!!!!!!!!!!!!
        if(this->iCmd.received_ValidPacket==3)
        {
            //doing the first reading 30/34/37/38... for important information
            //Only one time
            this->iCmd.SendSingleCmdPacket(0x30); //set_T
            SetWaitingCmd(0x30);
        }
    }
    //Waiting command & re-try
    Wait_Retry();
    //UpdateUI
    UpdateUI();
    //doing auto-diagnosis
    if(this->doing_AutoD)//////////////////////////////////////// doing auto-diagnosis here!!!
        AD_Diagnosis();
}

//======================//
// Waiting command..... //
//======================//
void RDS_main_Form::Wait_Retry()
{
    int tt;
    if(this->iCmd.waitCmdCode!=0)
    { //has waiting command
        new_dt=DateTime::Now;
        diff=new_dt-dt;
        packets_during_wait++;
        if(this->iCmd.cmdPktisValid==true)
            Cmd_during_wait++;
        if(this->iCmd.cmdPktisValid==true&&this->iCmd.cmdIsBroadcast==false)
            NotBroadcastCmd_during_wait++;
        if(NotBroadcastCmd_during_wait>MAX_PACKETS_FOR_RETRY||diff.Seconds>MAX_PACKETS_SECONDS)
        {
            //then re-try the wait command
            if(this->iCmd.waitCmdCode==0x70)
            {  //special resend command
                if(this->cmd70_Rd_EH_start==true) this->Read_EEP_1st_page();  //resend read 1st page of EEPROM
                if(this->cmd70_Rd_EH_page==true)  this->Read_Err_Hist_page(); //resend command... (didnt change address)
                SetWaitingCmd(0x70);
                packets_during_wait=0;
                Cmd_during_wait=0;
                NotBroadcastCmd_during_wait=0;
                dt=DateTime::Now;
                retry_times++;
                if(retry_times==CMD_LISTEN_RETRY_TIMES)
                {
                    MessageBox::Show(MSG_MAINUI_70CMD_READ_TIMEOUT, "TimeOut",
                        MessageBoxButtons::OK,
                        MessageBoxIcon::Information);
                    this->RdEEP_going=false;
                    ClearWaitingCmd();
                }
            }
            else
            {
                //note: in SPA protocol, request data & data send back is the same command code
                this->iCmd.SendSingleCmdPacket(WaitCmd);
                MsgEngr(String::Format("resend cmd={0:X00}", WaitCmd));
                packets_during_wait=0;
                Cmd_during_wait=0;
                NotBroadcastCmd_during_wait=0;
                dt=DateTime::Now;
                retry_times++;
                if(retry_times==CMD_LISTEN_RETRY_TIMES)
                {
                    MessageBox::Show(MSG_MAINUI_ALL_CMD_LISTEN_TIMEOUT, "TimeOut",
                        MessageBoxButtons::OK,
                        MessageBoxIcon::Information);
                    ClearWaitingCmd();
                }
            }
        }
    }
    else
    {
        //here, finish waiting....
        //waitCmd will be set non-zero value When someone wait for command.
        switch(WaitCmd)
        {
        case 0x30:   //for first time connection & change Set-T
            ClearWaitingCmd();
            if(Display_initial_OK==false)
            { //Initial steps: 30,34,37,38, 81, 82, 83, 87, 42, 43, 96, 99
                this->iCmd.SendSingleCmdPacket(0x34);
                SetWaitingCmd(0x34);
                if(DEBUGGING_USEAGE==3)MsgMain2("30H");
            }
            if(this->restore_AD_setT==true)
            {//for AD, restoreing starting_setT
//int ttt = this->iCmd.iSPA.TEMP_F_To_TEMPADC(this->starting_setT);
                if(this->iCmd.iSPA.set_Adc==this->iCmd.iSPA.TEMP_F_To_TEMPADC(this->starting_setT))
                {
                    this->restore_AD_setT=false;
                }
            }
            break;
        case 0x31:   //for DateTime window
            if(toOpenChildWin==true)
            {
                openDataTimeWin();
                toOpenChildWin=false;
            }
            if(SettingCmd_31==true)
            {
                checkingDateTime();
            }
            if(set_ADcmd31==true)
            { //for AD set DateTime as 01:00
                if(this->iCmd.iSPA.time_hour==RDS_AD_WORKING_DATE_TIME_H &&
                    this->iCmd.iSPA.time_min==RDS_AD_WORKING_DATE_TIME_M)
                {
                    set_ADcmd31=false;
                }
            }
            if(restore_ADcmd31==true)
            {  //restore ...time, set current time!!
                DateTime dt=DateTime::Now;
                String^ CurHour=dt.ToString("HH", DateTimeFormatInfo::InvariantInfo);
                String^ Cur_min=dt.ToString("mm", DateTimeFormatInfo::InvariantInfo);
                if(this->iCmd.iSPA.time_hour==Convert::ToInt32(CurHour, 10)&&
                    this->iCmd.iSPA.time_min==Convert::ToInt32(Cur_min, 10))
                {
                    restore_ADcmd31=false;
                }
            }
            ClearWaitingCmd();
            break;
        case 0x32:   //for STD Circ chedule window
            if(toOpenChildWin==true)
            { //for read and display
                openStdCircScheduleWin();
                toOpenChildWin=false;
            }
            if(SettingCmd_32==true)
            { //for change setting okay or not
                checkingStdFilterSchedule();
            }
            if(starting_AD_cmd32==true)
            { //for AD, save std schedule...
                this->AF_std_st_hour=this->iCmd.iSPA.std_st_hour;
                this->AF_std_st_min=this->iCmd.iSPA.std_st_min;
                this->AF_std_dt_hour=this->iCmd.iSPA.std_dt_hour;
                this->AF_std_dt_min=this->iCmd.iSPA.std_dt_min;
                this->AF_std_week=this->iCmd.iSPA.std_week;
                MsgLog("AF:"+this->AF_std_st_hour+":"+this->AF_std_st_min+":"+this->AF_std_dt_hour+":"+this->AF_std_dt_min+":"+this->AF_std_week);
                starting_AD_cmd32=false;
            }
            if(set_ADcmd32==true)
            { //for AD set RDS f-schedule
                if(this->iCmd.iSPA.std_st_hour==RDS_AD_WORK_STD_PF_FSCH_ST_H &&
                    this->iCmd.iSPA.std_st_min==RDS_AD_WORK_STD_PF_FSCH_ST_M &&
                    this->iCmd.iSPA.std_dt_hour==RDS_AD_WORK_STD_PF_FSCH_DT_H &&
                    this->iCmd.iSPA.std_dt_min==RDS_AD_WORK_STD_PF_FSCH_DT_M &&
                    this->iCmd.iSPA.std_week==0x7F)
                {
                    set_ADcmd32=false;
                }
            }
            if(restore_ADcmd32==true)
            { //for AD restore RDS f-schedule
                if(this->iCmd.iSPA.std_st_hour==this->AF_std_st_hour &&
                    this->iCmd.iSPA.std_st_min==this->AF_std_st_min &&
                    this->iCmd.iSPA.std_dt_hour==this->AF_std_dt_hour &&
                    this->iCmd.iSPA.std_dt_min==this->AF_std_dt_min &&
                    this->iCmd.iSPA.std_week==this->AF_std_week)
                {
                    restore_ADcmd32=false;
                }
            }
            ClearWaitingCmd();
            break;
        case 0x33:   //for ECO Circ chedule window
            if(toOpenChildWin==true)
            {  //for read and display
                openEcoCircScheduleWin();
                toOpenChildWin=false;
            }
            if(SettingCmd_33==true)
            { //for change setting okay or not
                checkingEcoFilterSchedule();
            }
            ClearWaitingCmd();
            break;
        case 0x34:   //for UV/Filter days update
            ClearWaitingCmd();
            if(Display_initial_OK==false)
            { //Initial steps: 30,34,37,38, 81, 82, 83, 87, 42, 43, 96, 99
                this->iCmd.SendSingleCmdPacket(0x37);
                SetWaitingCmd(0x37);
                if(DEBUGGING_USEAGE==3)MsgMain2("34H");
            }
            break;
        case 0x35:   //for PF window
            if(toOpenChildWin==true)
            {
                open_PF_Win();
                toOpenChildWin=false;
            }
            if(SettingCmd_35==true)
            {
                checkingPF();
            }
            if(starting_AD_cmd35==true)
            { //for AD, save PFx ...
                this->AD_pf_value=this->iCmd.iSPA.pf_value;
                this->AD_pf_st_hour=this->iCmd.iSPA.pf_st_hour;
                this->AD_pf_st_min=this->iCmd.iSPA.pf_st_min;
                this->AD_pf_dt_hour=this->iCmd.iSPA.pf_dt_hour;
                this->AD_pf_dt_min=this->iCmd.iSPA.pf_dt_min;
                starting_AD_cmd35=false;
            }
            if(set_ADcmd35==true)
            { //for AD set RDS f-schedule
                if(this->iCmd.iSPA.pf_st_hour==RDS_AD_WORK_STD_PF_FSCH_ST_H &&
                    this->iCmd.iSPA.pf_st_min==RDS_AD_WORK_STD_PF_FSCH_ST_M &&
                    this->iCmd.iSPA.pf_dt_hour==RDS_AD_WORK_STD_PF_FSCH_DT_H &&
                    this->iCmd.iSPA.pf_dt_min==RDS_AD_WORK_STD_PF_FSCH_DT_M)
                {
                    set_ADcmd35=false;
                }
            }
            if(restore_ADcmd35==true)
            {
                if(this->iCmd.iSPA.pf_st_hour==this->AD_pf_st_hour &&
                    this->iCmd.iSPA.pf_st_min==this->AD_pf_st_min &&
                    this->iCmd.iSPA.pf_dt_hour==this->AD_pf_dt_hour &&
                    this->iCmd.iSPA.pf_dt_min==this->AD_pf_dt_min)
                {
                    restore_ADcmd35=false;
                }
            }
            ClearWaitingCmd();
            break;
        case 0x36:   //for SF window
            if(toOpenChildWin==true)
            {
                open_SF_Win();
                toOpenChildWin=false;
            }
            if(SettingCmd_36==true)
            {
                checkingSF();
            }
            if(starting_AD_cmd36==true)
            { //for AD, save SFx ...
                this->AD_sf_value=this->iCmd.iSPA.sf_value;
                starting_AD_cmd36=false;
            }
            if(set_ADcmd36==true)
            { //for AD set SF0
                if(this->iCmd.iSPA.sf_value==0)
                {
                    set_ADcmd36=false;
                }
            }
            if(restore_ADcmd36==true)
            {
                if(this->iCmd.iSPA.sf_value==this->AD_sf_value)
                {
                    restore_ADcmd36=false;
                }
            }
            ClearWaitingCmd();
            break;
        case 0x37:   //for Lock update
            ClearWaitingCmd();
            if(Display_initial_OK==false)
            { //Initial steps: 30,34,37,38, 81, 82, 83, 87, 42, 43, 96, 99
                this->iCmd.SendSingleCmdPacket(0x38);
                SetWaitingCmd(0x38);
                if(DEBUGGING_USEAGE==3)MsgMain2("37H");
            }
            break;
        case 0x38:   //for ECO update
            ClearWaitingCmd();
            if(Display_initial_OK==false)
            { //Initial steps: 30,34,37,38, 81, 82, 83, 87, 42, 43, 96, 99
                this->iCmd.SendSingleCmdPacket(0x81);
                SetWaitingCmd(0x81);
                if(DEBUGGING_USEAGE==3)MsgMain2("38H");
            }
            break;
        case 0x42:
            ClearWaitingCmd();
            //this->cmd42_readed = true;
            if(Display_initial_OK==false)
            { //Initial steps: 30,34,37,38, 81, 82, 83, 87, 42, 43, 96, 99
                this->iCmd.SendSingleCmdPacket(0x43);
                SetWaitingCmd(0x43);
                if(DEBUGGING_USEAGE==3)MsgMain2("42H");
            }
            break;
        case 0x43:
            ClearWaitingCmd();
            //this->cmd43_readed = true;
            if(Display_initial_OK==false)
            { //Initial steps: 30,34,37,38, 81, 82, 83, 87, 42, 43, 96, 99
                this->iCmd.SendSingleCmdPacket(0x96);
                SetWaitingCmd(0x96);
                if(DEBUGGING_USEAGE==3)MsgMain2("43H");
            }
            break;
        case 0x70:   //read EEPROM ()
            if(this->cmd70_Rd_EH_start==true)
            {  //only the first time cmd-70
                this->RdEEP_total_records=this->iCmd.iSPA.cmd70_B5;
                this->RdEEP_start_record=this->iCmd.iSPA.cmd70_B6;
                this->cmd70_Rd_EH_start=false;

                //for Eng. nessage
                //MsgMain2("total=" + this->RdEEP_total_records  + " Record, start record =" + this->RdEEP_start_record);
                this->lbl_EH_Total_page->Text="EH.Tr="+this->RdEEP_total_records;
                this->lbl_EH_S_page->Text="EH.Sr="+this->RdEEP_start_record;

                //start to read EH record..
                this->RdEEP_save_record_no=0;
                this->RdEEP_page_count=this->RdEEP_total_records * PAGES_PER_RECORD_ERR_HIST;
                this->RdEEP_RQ_page_no=((this->RdEEP_start_record-1) * PAGES_PER_RECORD_ERR_HIST)+1;  //start from odd page then down count !
                this->start_addr=FIRST_RECORD_ADDRRESS+(this->RdEEP_RQ_page_no * BYTES_PER_PAGE_OF_EEPROM);
                this->end_addr=this->start_addr+BYTES_PER_PAGE_OF_EEPROM-1;  //fix to read 1 page per time.

                ///////////////////////
                this->Read_Err_Hist_page(); //send command-70 !!!!!!!!!!

                SetWaitingCmd(0x70);
            }
            else
            {
                if(this->cmd70_Rd_EH_page==true)
                {
                    /////////////////////
                    this->Save_Err_Hist_page(); //save data to global  (will update RdEEP_page_no)

                    this->iCmd.iSPA.new_cmd70=false;
                    if(this->RdEEP_going==true)
                    {  //send next request cmd-70 until all pages (100 pages) readed
                        this->RdEEP_page_count--;
                        if(this->RdEEP_page_count==0)
                        {  //normally closed
                            openErrHistWin();            //open Err-History window
                            toOpenChildWin=false;
                            //all down, close the waiting of cmd-70
                            this->RdEEP_going=false;
                            ClearWaitingCmd();
                        }
                        else
                        {
                            this->RdEEP_RQ_page_no--; //next page
                            if(this->RdEEP_RQ_page_no<0)
                            {
                                this->RdEEP_RQ_page_no=(RECORDS_IN_ERROR_HISTORY * PAGES_PER_RECORD_ERR_HIST)-1;
                                this->start_addr=FIRST_RECORD_ADDRRESS+((this->RdEEP_RQ_page_no)  * BYTES_PER_PAGE_OF_EEPROM);
                            }
                            else
                            {
                                this->start_addr=this->start_addr-BYTES_PER_PAGE_OF_EEPROM;
                            }
                            this->end_addr=this->start_addr+BYTES_PER_PAGE_OF_EEPROM-1;

                            ////////////////////////////////
                            this->Read_Err_Hist_page(); //send command...
                            SetWaitingCmd(0x70);
                        }
                    }
                    else
                    {  //if someting wrong, RdEEP_going may change to false
                        ClearWaitingCmd();
                    }
                }
                else
                {
                    //not read 1st page, nether read error-history records
                    ClearWaitingCmd();
                }
            }
            break;
        case 0x81:   //read P1 mode
            ClearWaitingCmd();
            if(Display_initial_OK==false)
            { //Initial steps: 30,34,37,38, 81, 82, 83, 87, 42, 43, 96, 99
                this->iCmd.SendSingleCmdPacket(0x82);
                SetWaitingCmd(0x82);
                if(DEBUGGING_USEAGE==3)MsgMain2("81H");
            }
            break;
        case 0x82:   //read P2 mode
            ClearWaitingCmd();
            if(Display_initial_OK==false)
            { //Initial steps: 30,34,37,38, 81, 82, 83, 87, 42, 43, 96, 99
                this->iCmd.SendSingleCmdPacket(0x83);
                SetWaitingCmd(0x83);
                if(DEBUGGING_USEAGE==3)MsgMain2("82H");
            }
            break;
        case 0x83: //read P3 mode
            ClearWaitingCmd();
            if(Display_initial_OK==false)
            { //Initial steps: 30,34,37,38, 81, 82, 83, 87, 42, 43, 96, 99
                this->iCmd.SendSingleCmdPacket(0x87);
                SetWaitingCmd(0x87);
                if(DEBUGGING_USEAGE==3)MsgMain2("83H");
            }
            break;
        case 0x87: //read working Voltage
            ClearWaitingCmd();
            if(Display_initial_OK==false)
            { //Initial steps: 30,34,37,38, 81, 82, 83, 87, 42, 43, 96, 99
                this->iCmd.SendSingleCmdPacket(0x42);
                SetWaitingCmd(0x42);
                if(DEBUGGING_USEAGE==3)MsgMain2("87H");
            }
            break;
        case 0x96: //read working Voltage
            ClearWaitingCmd();
            if(Display_initial_OK==false)
            { //Initial steps: 30,34,37,38, 81, 82, 83, 87, 42, 43, 96, 99
                this->iCmd.SendSingleCmdPacket(0x99);
                SetWaitingCmd(0x99);
                if(DEBUGGING_USEAGE==3)MsgMain2("96H");
            }
            break;
        case 0x99: //read blower mode
            ClearWaitingCmd();
            if(Display_initial_OK==false)
            { //Initial steps: 30,34,37,38, 81, 82, 83, 87, 42, 43, 96, 99
                Display_initial_OK=true;
                this->StartErr_index1=this->iCmd.iSPA.msg_index_1; //save starting error
                this->StartErr_index2=this->iCmd.iSPA.msg_index_2;
                this->StartErr_index3=this->iCmd.iSPA.msg_index_3;
                this->StartErr_index4=this->iCmd.iSPA.msg_index_4;
                if(DEBUGGING_USEAGE==3)
                {
                    if(this->iCmd.iSPA.is_HighEnd_Fsch==true) MsgMain2("High-end Spa model");
                    else MsgMain2("Low-end Spa model");
                }
                MsgLog("IK"); //initial OK
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
                //
                this->textBox_Filter_Days->Enabled=true;
                this->textBox_UV_Days->Enabled=true;
                this->button_RDS_report->Enabled=true;
                this->button_Service_Call->Enabled=true;
                this->button_History->Enabled=true;  //can run without connection
                this->button_OSC_list->Enabled=true; //can run without connection
                this->button_auto_diag->Enabled=true;
            }
            break;
        default: break;
        }
    }
}

//======================//
// Client (receive IOT) //
//======================//
void RDS_main_Form::ClientThread()
{
    array<Byte>^ buffer;
    Array::Resize(buffer, MAX_PACKET_SIZE_OF_IOT);
    char ReadBuf[MAX_PACKET_SIZE_OF_IOT];
    int nByte;

    //initial global var.
    //SecondReflashCount = 0;
    this->iCmd.iIOTctrl.PacketOkCount=0;
    this->iCmd.iIOTctrl.PacketLostCount=0;
    this->iCmd.iIOTctrl.readTimeOutCount=0;
    //CurrentPacket_InputPtr = 0;

    Display^ myDelegate=gcnew  Display(this, &RDS_main_Form::DisplayText);

    //Main loop
    do
    {
        nByte=this->iCmd.iIOTctrl.read_IOT(ReadBuf, MAX_PACKET_SIZE_OF_IOT);
        if(nByte>0)
        {
            //copy to buffer
            Array::Resize(buffer, nByte);
            for(int count=0; count<nByte; count++)
            {
                buffer[count]=ReadBuf[count];
            }
            //invoke to display rountine
            this->Invoke(myDelegate, buffer);
            Array::Resize(buffer, MAX_PACKET_SIZE_OF_IOT);
        }
        else
        {
            //invoke to display rountine
            this->Invoke(myDelegate, buffer);
            Array::Resize(buffer, MAX_PACKET_SIZE_OF_IOT);
            if(this->iCmd.iIOTctrl.session_Fatal==true     //fatal error when doing read_IOT
                ||this->iCmd.iIOTctrl.connect_OK==false   //fatal, if press idsconnect button
                )
                break;
        }
        Thread::Sleep(WAIT_AFTER_IOT_READ);
    } while(this->MyClientThreadRuning==true);
    //if exit with Fatal error...IOT disconnect
    this->iCmd.iIOTctrl.disconnect();
}

//=========================//
//Error History related    //
//=========================//
void RDS_main_Form::Read_EEP_1st_page()
{
    array<unsigned char>^ buffer;
    Array::Resize(buffer, 7);
    this->cmd70_Rd_EH_start=true;
    this->cmd70_Rd_EH_page=false;
    buffer[0]=NEW_2015_PROTOCOL_CODE;
    buffer[1]=0x70; //Command -- Read EEPROM
    buffer[2]=0x00;  //00h=external EEPROM, 80h=MCU internal EEPROM
    buffer[3]=0x00;
    buffer[4]=0x00;
    buffer[5]=0x00;
    buffer[6]=0x07;
    this->iCmd.SendCmdPacket(buffer);
    //MsgMain2("Read EEPROM 1st page..." );
}
void RDS_main_Form::Read_Err_Hist_page()
{
    array<unsigned char>^ buffer;
    Array::Resize(buffer, 7);
    this->cmd70_Rd_EH_start=false;
    this->cmd70_Rd_EH_page=true;
    buffer[0]=NEW_2015_PROTOCOL_CODE;
    buffer[1]=0x70; //Command -- Read EEPROM
    buffer[2]=0x00;  //00h=external EEPROM, 80h=MCU internal EEPROM
    buffer[3]=(this->start_addr>>8)&0x00FF;
    buffer[4]=this->start_addr&0x00FF;
    buffer[5]=(this->end_addr>>8)&0x00FF;
    buffer[6]=this->end_addr&0x00FF;
    this->iCmd.SendCmdPacket(buffer);
    //MsgMain2("RQ page=" + this->RdEEP_RQ_page_no
    //	+ ",SA=" + String::Format("{0:X0000}H", this->start_addr)
    //	+ ",EA=" + String::Format("{0:X0000}H", this->end_addr)
    //	);
}
void RDS_main_Form::Save_Err_Hist_page()
{
    //get the page no from received cmd-70 eeprom-address
    this->RdEEP_page_no=(this->iCmd.iSPA.eeprom_addr-FIRST_RECORD_ADDRRESS)/BYTES_PER_PAGE_OF_EEPROM;
    //MsgMain2("read page =" + this->RdEEP_page_no
    //	+ ",SA=" + String::Format("{0:X0000}H", this->iCmd.iSPA.eeprom_addr)
    //	);

    //judge what we readed page is same as we requested page?
    if(this->RdEEP_page_no==this->RdEEP_RQ_page_no)
    {
        //for eng. message...
        this->lbl_EH_page->Text=""+this->RdEEP_page_no;
        this->lbl_EH_pageCnt->Text=""+this->RdEEP_page_count;

        //display
        this->lbl_disp_EH_page->Text=""+this->RdEEP_page_count;

        if(this->RdEEP_page_no%2==0)
        {  //even page
            SPA_ERR_HIST_TABLE[this->RdEEP_save_record_no].err_Bit=this->iCmd.iSPA.cmd70_B1;
            SPA_ERR_HIST_TABLE[this->RdEEP_save_record_no].state_H=this->iCmd.iSPA.cmd70_B2;
            SPA_ERR_HIST_TABLE[this->RdEEP_save_record_no].state_L=this->iCmd.iSPA.cmd70_B3;
            SPA_ERR_HIST_TABLE[this->RdEEP_save_record_no].hili_temp=this->iCmd.iSPA.cmd70_B4;
            SPA_ERR_HIST_TABLE[this->RdEEP_save_record_no].watr_temp=this->iCmd.iSPA.cmd70_B5;
            SPA_ERR_HIST_TABLE[this->RdEEP_save_record_no].pcba_temp=this->iCmd.iSPA.cmd70_B6;
            this->RdEEP_save_record_no++;
        }
        else
        {  //odd page  (start from 0, so odd page first)
            SPA_ERR_HIST_TABLE[this->RdEEP_save_record_no].st_year=this->iCmd.iSPA.cmd70_B1>>1;
            SPA_ERR_HIST_TABLE[this->RdEEP_save_record_no].st_month=(this->iCmd.iSPA.cmd70_B1&0x01)*8+((this->iCmd.iSPA.cmd70_B2&0xE0)>>5);
            SPA_ERR_HIST_TABLE[this->RdEEP_save_record_no].st_day=this->iCmd.iSPA.cmd70_B2&0x1F;
            SPA_ERR_HIST_TABLE[this->RdEEP_save_record_no].st_hour=this->iCmd.iSPA.cmd70_B3;
            SPA_ERR_HIST_TABLE[this->RdEEP_save_record_no].st_min=this->iCmd.iSPA.cmd70_B4;
            SPA_ERR_HIST_TABLE[this->RdEEP_save_record_no].et_year=this->iCmd.iSPA.cmd70_B5>>1;
            SPA_ERR_HIST_TABLE[this->RdEEP_save_record_no].et_month=(this->iCmd.iSPA.cmd70_B5&0x01)*8+((this->iCmd.iSPA.cmd70_B6&0xE0)>>5);
            SPA_ERR_HIST_TABLE[this->RdEEP_save_record_no].et_day=this->iCmd.iSPA.cmd70_B6&0x1F;
            SPA_ERR_HIST_TABLE[this->RdEEP_save_record_no].et_hour=this->iCmd.iSPA.cmd70_B7;
            SPA_ERR_HIST_TABLE[this->RdEEP_save_record_no].et_min=this->iCmd.iSPA.cmd70_B8;
        }
    }
    else
    { //sometimes, CTR+WiFi slow response, we will re-send many times, but all re-send commands maybe in FIFO order come back,
  //and, our control logic will go next when receive 1st data back. for following data-back they are not match page-no. so it's not error
        this->lbl_EH_page->Text="*"+this->RdEEP_page_no;
        //MessageBox::Show("Command 70 read error, report to developer", "Error",
        //	MessageBoxButtons::OK,
        //	MessageBoxIcon::Information);
        //this->RdEEP_going = false;
    }
}