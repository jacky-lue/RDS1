#pragma once

namespace SPAnamespace {
	using namespace System;

	ref class SPA
	{
	//Public variables -------------------------------
	public:
		//model configuration
		unsigned char p1_mode;
		unsigned char p2_mode;
		unsigned char p3_mode;
		Boolean has_blower;
		Boolean is_HighEnd_Fsch;
		//UI update use
		Boolean p1_hi_on;
		Boolean p2_hi_on;
		Boolean p3_hi_on;
		Boolean p1_lo_on;
		Boolean p2_lo_on;
		Boolean p3_lo_on;
		Boolean blower_on;
		Boolean circ_on;
		Boolean uv_on;
		Boolean uv_lock;
		Boolean heater_on;
		Boolean ozon_on;
		Boolean block_out_cyc_on; //20161125 add
		Boolean clean_cyc_on; //20161125 add
		Boolean unlock;
		Boolean lock_Tmpr;
		Boolean lock_Func;
		Boolean lock_Pump;
		Boolean lock_Panl;
		unsigned int msg_index_1;
		unsigned int msg_index_2;
		unsigned int msg_index_3;
		unsigned int msg_index_4;
		Boolean msg_more_than_4;
		Boolean relay_err_p1;
		Boolean relay_err_p2;
		Boolean relay_err_p3;
		Boolean relay_err_ht;
		
		//command-30
		unsigned int set_Adc;

		//time (command 31)
		unsigned char time_year;   //00~99 : 2000~2099
		unsigned char time_month;  //1~12
		unsigned char time_day;    //1~31
		unsigned char time_week;   //1=sun, 2=mon....7=Sat.
		unsigned char time_hour;
		unsigned char time_min;

		//STD (command 32)
		unsigned char std_st_hour;
		unsigned char std_st_min;
		unsigned char std_dt_hour;
		unsigned char std_dt_min;
		unsigned char std_week;

		//STD (command 33)
		unsigned char eco_1_st_hour;
		unsigned char eco_1_st_min;
		unsigned char eco_1_dt_hour;
		unsigned char eco_1_dt_min;
		unsigned char eco_2_st_hour;
		unsigned char eco_2_st_min;
		unsigned char eco_2_dt_hour;
		unsigned char eco_2_dt_min;
		unsigned char eco_3_st_hour;
		unsigned char eco_3_st_min;
		unsigned char eco_3_dt_hour;
		unsigned char eco_3_dt_min;
		unsigned char eco_4_st_hour;
		unsigned char eco_4_st_min;
		unsigned char eco_4_dt_hour;
		unsigned char eco_4_dt_min;
		unsigned char eco_1_week;
		unsigned char eco_2_week;
		unsigned char eco_3_week;
		unsigned char eco_4_week;
		
		//days (command 34)
		unsigned int uv_days;
		unsigned int filter_days;

		//PF (command 35)
		unsigned char pf_value;
		unsigned char pf_st_hour;
		unsigned char pf_st_min;
		unsigned char pf_dt_hour;
		unsigned char pf_dt_min;

		//SF (command 36)
		unsigned int sf_value;

		//lock (command 37)
		unsigned int lock_value; //0=unlock, 1=panel lock, 2=pump lock, 3=tempeature lock, 4=service lock

		//ECO (command 38)
		Boolean ecoModeOn;

		//command-40 
		unsigned char state_H;
		unsigned char state_L;
		unsigned char err_B3;
		unsigned char err_B2;
		unsigned char err_B1;
		unsigned char err_B0;
		unsigned char water_T_state;
		unsigned char hiLmt_T_state;
		unsigned char waterLevel;
		//command-41
		unsigned int cur_Adc_0;
		unsigned int cur_Adc_1;
		unsigned int cur_Adc_2;
		unsigned int cur_Adc_3;
		unsigned int cur_Adc_4;
		//command-42
		unsigned int max_Adc_0;
		unsigned int max_Adc_1;
		unsigned int max_Adc_2;
		unsigned int max_Adc_3;
		unsigned int max_Adc_4;
		//command-43
		unsigned int min_Adc_0;
		unsigned int min_Adc_1;
		unsigned int min_Adc_2;
		unsigned int min_Adc_3;
		unsigned int min_Adc_4;
		//command-44,45,46
		unsigned int accumelate_power;
		unsigned int accumelate_hour;
		unsigned int operation_freq;
		//command-70
		unsigned int eeprom_addr;
		unsigned char cmd70_B1;
		unsigned char cmd70_B2;
		unsigned char cmd70_B3;
		unsigned char cmd70_B4;
		unsigned char cmd70_B5;
		unsigned char cmd70_B6;
		unsigned char cmd70_B7;
		unsigned char cmd70_B8;
		Boolean  new_cmd70;
		//command-87
		unsigned int spa_w_Voltage;
	//constructor,functions===========================
	public:
		//constructor
		SPA();
		//Utiity
		unsigned int TEMP_F_To_TEMPADC(unsigned int Temperature);
		unsigned int TEMP_C_To_TEMPADC(unsigned int Temperature);
		unsigned int TEMPADC_To_TEMP_F(unsigned int TemperatureADC);
		unsigned int TEMPADC_To_TEMP_C(unsigned int TemperatureADC);
		unsigned int VoltageADC_to_Volt(unsigned int VoltageADC);
		unsigned int CurrentADC_to_Amp(unsigned int CurrentADC);
		unsigned int CurrentADC_to_Amp_dot1(unsigned int CurrentADC);
		//float CurrentADC_to_Amp(unsigned int CurrentADC);
	};
}//end of namespace

