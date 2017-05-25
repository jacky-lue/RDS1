#pragma once

//for Internal objects
#include "IOTcommunicator.h"
#include "SPA.h"
#include "spa_cmd.h"
#include "nas_user.h"
#include "msg.h"

//sub-form

namespace RDS {
	#include "RDS_AD.h"
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Text;
	using namespace System::Drawing;
	using namespace System::Threading;
	using namespace System::Globalization;
	using namespace IOTnamespace;
	using namespace SPAnamespace;
	using namespace SPAcmd_namespace;

	/// <summary>
	/// Summary for RDS_main_Form
	/// </summary>
	public ref class RDS_main_Form : public System::Windows::Forms::Form
	{
	public:
		RDS_main_Form(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~RDS_main_Form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  panel_UID;
	protected:
	private: System::Windows::Forms::TextBox^  textBox_UID_in;
	private: System::Windows::Forms::Label^  label_UID;
	private: System::Windows::Forms::Panel^  panel_owner;
	private: System::Windows::Forms::TextBox^  textBox_owner_in;
	private: System::Windows::Forms::Label^  label_owner;
	private: System::Windows::Forms::Panel^  panel_spa_serial;
	private: System::Windows::Forms::TextBox^  textBox_spa_serial;
	private: System::Windows::Forms::Label^  label_spa_serial;
	private: System::Windows::Forms::Panel^  panel_disconnect;
	private: System::Windows::Forms::Button^  button_disconnect;
	private: System::Windows::Forms::Panel^  panel_connect;
	private: System::Windows::Forms::Label^  label_slash;
	private: System::Windows::Forms::Button^  button_connect;
	private: System::Windows::Forms::PictureBox^  pictureBox_connect_light;
	private: System::Windows::Forms::PictureBox^  pictureBox_packet_sign;
	private: System::Windows::Forms::Panel^  panel_auto_diag;
	private: System::Windows::Forms::Button^  button_auto_diag;
	private: System::Windows::Forms::PictureBox^  pictureBox_auto_diag;
	private: System::Windows::Forms::Panel^  panel_temperature;
	private: System::Windows::Forms::Label^  label_Set;
	private: System::Windows::Forms::Label^  label_current;
	private: System::Windows::Forms::Button^  button_degree_C;
	private: System::Windows::Forms::Button^  button_degree_F;
	private: System::Windows::Forms::Label^  label_PCB;
	private: System::Windows::Forms::Label^  label_HiLmt;
	private: System::Windows::Forms::Label^  label_temperature_4;
	private: System::Windows::Forms::Panel^  panel_mcu_HCV;
	private: System::Windows::Forms::PictureBox^  pictureBox_HT_MCU;
	private: System::Windows::Forms::Label^  label_MCU_Heater_status;
	private: System::Windows::Forms::Panel^  panel_lock;
	private: System::Windows::Forms::Button^  button_unlock;
	private: System::Windows::Forms::Button^  button_Panel_Lock;
	private: System::Windows::Forms::Button^  button_Pump_Lock;
	private: System::Windows::Forms::Button^  button_Func_Lock;
	private: System::Windows::Forms::Button^  button_T_Lock;
	private: System::Windows::Forms::Panel^  panel_Err_area;
	private: System::Windows::Forms::Button^  button_Err_Msg;
	private: System::Windows::Forms::Panel^  panel_Err_Msg;
	private: System::Windows::Forms::TextBox^  textBox_eMsg4;
	private: System::Windows::Forms::TextBox^  textBox_eMsg3;
	private: System::Windows::Forms::TextBox^  textBox_eMsg2;
	private: System::Windows::Forms::TextBox^  textBox_eMsg1;
	private: System::Windows::Forms::Panel^  panel_measure;
	private: System::Windows::Forms::TextBox^  textBox4_System_Voltage;
	private: System::Windows::Forms::TextBox^  textBox_Current_Amp;
	private: System::Windows::Forms::Label^  label_sysVoltage;
	private: System::Windows::Forms::Label^  label_totalAmp;
	private: System::Windows::Forms::Label^  label_Relay;
	private: System::Windows::Forms::Panel^  panel_Relay;
	private: System::Windows::Forms::Panel^  panel_Relay_status;
	private: System::Windows::Forms::Label^  label_Relay_Status;
	private: System::Windows::Forms::Panel^  panel_Device;
	private: System::Windows::Forms::Label^  label_Device_1;
	private: System::Windows::Forms::Panel^  panel_Operation;
	private: System::Windows::Forms::Label^  label_Operation;
	private: System::Windows::Forms::Panel^  panel_P1R;
	private: System::Windows::Forms::Label^  label_P1R;
	private: System::Windows::Forms::Panel^  panel_P1R_status;
	private: System::Windows::Forms::PictureBox^  pictureBox_P1R_status;
	private: System::Windows::Forms::Panel^  panel_Pump1;
	private: System::Windows::Forms::Label^  label_Pum1;
	private: System::Windows::Forms::Panel^  panel_P1_HiLo;
	private: System::Windows::Forms::Button^  button_P1_Lo;
	private: System::Windows::Forms::Button^  button_P1_Hi;
	private: System::Windows::Forms::Panel^  panel_MCU_status;
	private: System::Windows::Forms::Label^  label_MCU_status;
	private: System::Windows::Forms::Panel^  panel_P1_MCU;
	private: System::Windows::Forms::PictureBox^  pictureBox_P1_MCU;
	private: System::Windows::Forms::Panel^  panel_Device_Amp;
	private: System::Windows::Forms::Label^  label_Device_Amp;
	private: System::Windows::Forms::Panel^  panel_P1_Amp;
	private: System::Windows::Forms::TextBox^  textBox_P1_Amp;
	private: System::Windows::Forms::Panel^  panel_P2_Amp;
	private: System::Windows::Forms::TextBox^  textBox_P2_Amp;
	private: System::Windows::Forms::Panel^  panel_P2_MCU;
	private: System::Windows::Forms::PictureBox^  pictureBox_P2_MCU;
	private: System::Windows::Forms::Panel^  panel_P2_HiLo;
	private: System::Windows::Forms::Button^  button_P2_Lo;
	private: System::Windows::Forms::Button^  button_P2_Hi;
	private: System::Windows::Forms::Panel^  panel_Pump2;
	private: System::Windows::Forms::Label^  label_Pump2;
	private: System::Windows::Forms::Panel^  panel_P2R_status;
	private: System::Windows::Forms::PictureBox^  pictureBox_P2R_status;
	private: System::Windows::Forms::Panel^  panel_p2R;
	private: System::Windows::Forms::Label^  label_P2R;
	private: System::Windows::Forms::Panel^  panel_P3_Amp;
	private: System::Windows::Forms::TextBox^  textBox_P3_Amp;
	private: System::Windows::Forms::Panel^  panel_P3_MCU;
	private: System::Windows::Forms::PictureBox^  pictureBox_P3_MCU;
	private: System::Windows::Forms::Panel^  panel_P3_HiLo;
	private: System::Windows::Forms::Button^  button_P3_Lo;
	private: System::Windows::Forms::Button^  button_P3_Hi;
	private: System::Windows::Forms::Panel^  panel_Pump3;
	private: System::Windows::Forms::Label^  label_Pum3;
	private: System::Windows::Forms::Panel^  panel_P3R_status;
	private: System::Windows::Forms::PictureBox^  pictureBox_P3R_status;
	private: System::Windows::Forms::Panel^  panel_P3R;
	private: System::Windows::Forms::Label^  label_P3R;
	private: System::Windows::Forms::Panel^  panel_Blower_Amp;
	private: System::Windows::Forms::TextBox^  textBox_Blower_Amp;
	private: System::Windows::Forms::Panel^  panel_Blower_MCU;
	private: System::Windows::Forms::PictureBox^  pictureBox_Blower_MCU;
	private: System::Windows::Forms::Panel^  panel_Blower_OnOff;
	private: System::Windows::Forms::Button^  button_Blower_OnOff;
	private: System::Windows::Forms::Panel^  panel_Blower;
	private: System::Windows::Forms::Label^  label_Blower;
	private: System::Windows::Forms::Panel^  panel_RH_status;
	private: System::Windows::Forms::PictureBox^  pictureBox_RH_status;
	private: System::Windows::Forms::Panel^  panel_RH;
	private: System::Windows::Forms::Label^  label_RH;
	private: System::Windows::Forms::Panel^  panel_Filter;
	private: System::Windows::Forms::Label^  label_Days_1;
	private: System::Windows::Forms::TextBox^  textBox_Filter_Days;
	private: System::Windows::Forms::Label^  label_Filter;
	private: System::Windows::Forms::Panel^  panel_UV;
	private: System::Windows::Forms::Label^  label_Days_2;
	private: System::Windows::Forms::TextBox^  textBox_UV_Days;
	private: System::Windows::Forms::Label^  label_UV;
	private: System::Windows::Forms::PictureBox^  pictureBox_CIRC_MCU;
	private: System::Windows::Forms::Label^  label_MCU_CIRCstatus;
	private: System::Windows::Forms::Button^  button_mode;
	private: System::Windows::Forms::PictureBox^  pictureBox_ECO;
	private: System::Windows::Forms::Label^  label_ECO_mode;
	private: System::Windows::Forms::PictureBox^  pictureBox_UV_MCU;
	private: System::Windows::Forms::Label^  label_MCU_UVstatus;
	private: System::Windows::Forms::Button^  button_Date_Time;
	private: System::Windows::Forms::Button^  button_Filtration_sch;
	private: System::Windows::Forms::Panel^  panel_ECO_mode;
	private: System::Windows::Forms::Panel^  panel_control;
	private: System::Windows::Forms::Button^  button_History;
	private: System::Windows::Forms::Button^  button_Service_Call;
	private: System::Windows::Forms::Button^  button_RDS_report;
	private: System::Windows::Forms::RichTextBox^  richTextBox_main_output;
	private: System::Windows::Forms::RichTextBox^  richTextBox_EngMsg;
	private: System::Windows::Forms::Panel^  panel_EngArea;
	private: System::Windows::Forms::Label^  label_packetSN;
	private: System::Windows::Forms::Label^  lbl_PSN;
	private: System::Windows::Forms::Label^  label_pktLoss;
	private: System::Windows::Forms::Label^  lbl_PktLoss;
	private: System::Windows::Forms::Label^  lbl_pktRate;
	private: System::Windows::Forms::Label^  label_pktRate;
	private: System::Windows::Forms::Button^  button_update;
	private: System::Windows::Forms::Label^  lbl_PktTimeOut;
	private: System::Windows::Forms::Label^  label_pktTimeOut;
	private: System::Windows::Forms::Label^  lbl_remoteIP;
	private: System::Windows::Forms::Label^  lbl_sCorD;
	private: System::Windows::Forms::Label^  lbl_sMode;
	private: System::Windows::Forms::Label^  lbl_NAT_type;
	private: System::Windows::Forms::Label^  lbl_remotePort;
	private: System::Windows::Forms::Label^  lbl_validCMDcode;
	private: System::Windows::Forms::Label^  lbl_HTstate;
	private: System::Windows::Forms::Label^  lbl_WTstate;
	private: System::Windows::Forms::Label^  lbl_WLv;
	private: System::Windows::Forms::Label^  lbl_writePktCount;
	private: System::Windows::Forms::Label^  lbl_writeTimeout;
	private: System::Windows::Forms::Button^  button_blue;
	private: System::Windows::Forms::Button^  button_red;
	private: System::Windows::Forms::Button^  button_yellow;
	private: System::Windows::Forms::Button^  button_green;

	public:
		/// <summary> ===========================================================
		/// Required designer variable.
		/// =====================================================================
		/// </summary> ==========================================================
		//objects
		System::ComponentModel::Container ^components;
		SPAcmd_namespace::spa_cmd iCmd;
		RDS_NAS::nas_user iNas;

		//program threading
		Boolean MyClientThreadRuning;

		//for two-set of ErrorCode
		unsigned char ECset;

		//for RDS report/ service call...
		String^ Base_dir;
		String^ Cur_RDSreport_str;
		String^ RDS_save_filename;
		String^ RDS_rpt_date;
		String^ RDS_rpt_time;
		unsigned char RDS_report_No;    //this UID call-in thimes in today
		unsigned char RDS_operator_No;  //operator No, p0=supervisor, p1, p2....
		String^ RDS_operator_name;
		unsigned int RDS_SC_no;
		Boolean RDS_SCno_produced;
		Boolean RDS_rpt_saved;
		Boolean RDS_log_saved;
		String^	RDS_rpt_SpaSerial;
		unsigned int RDS_rpt_HTmodel;
		String^ RDS_rpt_Owner;
		unsigned int StartErr_index1;
		unsigned int StartErr_index2;
		unsigned int StartErr_index3;
		unsigned int StartErr_index4;

		//for Auto-Diagnosis
		Boolean Start_with_Heat;
		Boolean Start_with_UV;
		Boolean Start_with_CIRC;
		Boolean TooCold_HeatOn;
		Boolean M0_with_HeatCirc;
		Boolean M1M2_with_Circ;
		Boolean starting_AD_cmd32;
		Boolean starting_AD_cmd36;
		Boolean starting_AD_cmd35;
		Boolean set_ADcmd31;
		Boolean set_ADcmd32;
		unsigned char AD_std_st_hour;
		unsigned char AF_std_st_hour;
		unsigned char AF_std_st_min;
		unsigned char AF_std_dt_hour;
		unsigned char AF_std_dt_min;
		unsigned char AF_std_week;
		Boolean set_ADcmd36;
		unsigned int AD_sf_value;
		Boolean set_ADcmd35;
		unsigned char AD_pf_value;
		unsigned char AD_pf_st_hour;
		unsigned char AD_pf_st_min;
		unsigned char AD_pf_dt_hour;
		unsigned char AD_pf_dt_min;
		Boolean restore_ADcmd31;
		Boolean restore_ADcmd32;
		Boolean restore_ADcmd35;
		Boolean restore_ADcmd36;
		Boolean restore_AD_setT;
		Boolean starting_ECO_on;
		unsigned int starting_setT;
		unsigned int starting_lock;
		enum AD_State Current_AD_State;
		enum AD_State Next_AD_State;
		unsigned int curWaterT;
		Boolean has_M0_HC;
		Boolean has_M0_C;
		unsigned int M0_HC_current;
		unsigned int M0_C_current;
		unsigned int M0_current;
		unsigned int M1_current;
		unsigned int M2_current;
		unsigned int M3_current;
		unsigned int M4_current;
		unsigned int M5_current;
		unsigned int M6_current;
		unsigned int M7_current;
		unsigned char M0_st; //when measure Mx current, the status of Heat+Circ+UV
		unsigned char M1_st; // 3:Heat+Circ+ UV 
		unsigned char M2_st; // 2:Circ+ UV 
		unsigned char M3_st; // 1:none
		unsigned char M4_st; // 0: reserved for no this device
		unsigned char M5_st;
		unsigned char M6_st;
		unsigned char M7_st;
		Boolean M0_HC_err;
		Boolean M0_C_err;
		Boolean M0_err;
		Boolean M1_err;
		Boolean M2_err;
		Boolean M3_err;
		Boolean M4_err;
		Boolean M5_err;
		Boolean M6_err;
		Boolean M7_err;
		Boolean Flow_err;
		String^ M0_HC_all_Err;
		String^ M0_C_all_Err;
		String^ M0_all_Err;
		String^ M1_all_Err;
		String^ M2_all_Err;
		String^ M3_all_Err;
		String^ M4_all_Err;
		String^ M5_all_Err;
		String^ M6_all_Err;
		String^ M7_all_Err;
		Boolean RDS_AD_finish;
		unsigned int AD_wait_count;
		unsigned int AD_CauseEquip_TotalCnt;
		unsigned int AD_Equip_FinalCnt;

		//for display
		Boolean tryConnect;
		Boolean Display_initial_OK;
		Boolean Display_F;
		Boolean Err_showed;
		Boolean Cannot_AutoD;
		Boolean Some_MsgIndex_AD_fail;
		Boolean doing_AutoD;
		unsigned int err_msg_index_1;
		unsigned int err_msg_index_2;
		unsigned int err_msg_index_3;
		unsigned int err_msg_index_4;

		//for waiting command & open other form
		unsigned char WaitCmd;
		DateTime dt;
		DateTime new_dt;
		TimeSpan diff;
		Boolean toOpenChildWin;
		int SaveCursorX;
		int SaveCursorY;
		int retry_times;
		int packets_during_wait;
		int Cmd_during_wait;
		int NotBroadcastCmd_during_wait;

		//for those child window SPA values
		//save another copy when UI setting values to SPA.
		//We will use this copy to check the action is fail or successed
		//time (command 31)
		Boolean SettingCmd_31;
		unsigned int resend_31;
		unsigned char time_year;   //00~99 : 2000~2099
		unsigned char time_month;  //1~12
		unsigned char time_day;    //1~31
		unsigned char time_week;   //1=sun, 2=mon....7=Sat.
		unsigned char time_hour;
		unsigned char time_min;
		//STD filter schedule (command 32)
		Boolean SettingCmd_32;
		unsigned int resend_32;
		unsigned char std_st_hour;
		unsigned char std_st_min;
		unsigned char std_dt_hour;
		unsigned char std_dt_min;
		unsigned char std_week;
		//STD filter schedule (command 33)
		Boolean SettingCmd_33;
		unsigned int resend_33;
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
		//PF filter scheduel (command=35)
		Boolean SettingCmd_35;
		unsigned int resend_35;
		unsigned int pf_value;
		unsigned char pf_st_hour;
		unsigned char pf_st_min;
		unsigned char pf_dt_hour;
		unsigned char pf_dt_min;
		//SF filter scheduel (command=36)
		Boolean SettingCmd_36;
		unsigned int resend_36;
		unsigned int sf_value;
		// READ EEPROM (command 70)
		Boolean RdEEP_going;
		Boolean cmd70_Rd_EH_start;
		Boolean cmd70_Rd_EH_page;
		unsigned int RdEEP_total_records;  //total records in SPA    (EEPROM address 0x004) (1~50)
		unsigned int RdEEP_start_record;   //start record no. in SPA (EEPROM address 0x005) (0~49)
		unsigned int RdEEP_save_record_no;   //for RDS t save received record
		int RdEEP_RQ_page_no;  //for send request page to read EEPROM 
		unsigned int RdEEP_page_no;     //for received page from cmd-70 back
		unsigned int RdEEP_page_count;  //count how many pages already received
		unsigned int start_addr;    //for sending cmd-70
		unsigned int end_addr;      //for sending cmd-70 
		DataTable dt_ErrHist;


public:
private: System::Windows::Forms::Label^  label_tube_model;
private: System::Windows::Forms::Panel^  panel_model;
private: System::Windows::Forms::RichTextBox^  richTextBox_ActLog;

private: System::Windows::Forms::RichTextBox^  richTextBox_comment;
private: System::Windows::Forms::Label^  lbl_EH_page;
private: System::Windows::Forms::Label^  lbl_disp_EH_page;
private: System::Windows::Forms::Panel^  panel_Service_Hint;

private: System::Windows::Forms::Label^  lbl_service_0;
private: System::Windows::Forms::Panel^  panel_Service_Hint_1;
private: System::Windows::Forms::Label^  lbl_service_1;
private: System::Windows::Forms::ComboBox^  comboBox_Model_Name;


private: System::Windows::Forms::Button^  button_OSC_list;
private: System::Windows::Forms::Label^  lbl_EH_pageCnt;
private: System::Windows::Forms::Label^  lbl_EH_S_page;
private: System::Windows::Forms::Label^  lbl_EH_Total_page;
private: System::Windows::Forms::Button^  button_SF;
private: System::Windows::Forms::Button^  button_PF;
private: System::Windows::Forms::TextBox^  textBox_PCB_T;
private: System::Windows::Forms::TextBox^  textBox_Set_T;
private: System::Windows::Forms::TextBox^  textBox_HiLmt_T;
private: System::Windows::Forms::TextBox^  textBox_Cur_T;

private: System::Windows::Forms::Panel^  panel_FilterSch;
private: System::Windows::Forms::Panel^  panel_DateTime;

private: System::Windows::Forms::Panel^  panel_heater_Amp;
private: System::Windows::Forms::TextBox^  textBox_Heater_Amp;
private: System::Windows::Forms::Label^  lb_wait_NBcmd;
private: System::Windows::Forms::Label^  lb_wait_cmd;
private: System::Windows::Forms::Label^  lb_wait_pkt;



		//for thread to dispaly...
		Thread^ mhClientThread;
		delegate void Display(array<unsigned char>^ buffer);

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(RDS_main_Form::typeid));
			this->panel_UID = (gcnew System::Windows::Forms::Panel());
			this->textBox_UID_in = (gcnew System::Windows::Forms::TextBox());
			this->label_UID = (gcnew System::Windows::Forms::Label());
			this->panel_owner = (gcnew System::Windows::Forms::Panel());
			this->textBox_owner_in = (gcnew System::Windows::Forms::TextBox());
			this->label_owner = (gcnew System::Windows::Forms::Label());
			this->panel_spa_serial = (gcnew System::Windows::Forms::Panel());
			this->textBox_spa_serial = (gcnew System::Windows::Forms::TextBox());
			this->label_spa_serial = (gcnew System::Windows::Forms::Label());
			this->panel_disconnect = (gcnew System::Windows::Forms::Panel());
			this->button_disconnect = (gcnew System::Windows::Forms::Button());
			this->panel_connect = (gcnew System::Windows::Forms::Panel());
			this->pictureBox_packet_sign = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox_connect_light = (gcnew System::Windows::Forms::PictureBox());
			this->label_slash = (gcnew System::Windows::Forms::Label());
			this->button_connect = (gcnew System::Windows::Forms::Button());
			this->panel_auto_diag = (gcnew System::Windows::Forms::Panel());
			this->pictureBox_auto_diag = (gcnew System::Windows::Forms::PictureBox());
			this->button_auto_diag = (gcnew System::Windows::Forms::Button());
			this->panel_temperature = (gcnew System::Windows::Forms::Panel());
			this->label_PCB = (gcnew System::Windows::Forms::Label());
			this->label_HiLmt = (gcnew System::Windows::Forms::Label());
			this->label_temperature_4 = (gcnew System::Windows::Forms::Label());
			this->textBox_PCB_T = (gcnew System::Windows::Forms::TextBox());
			this->textBox_Set_T = (gcnew System::Windows::Forms::TextBox());
			this->textBox_HiLmt_T = (gcnew System::Windows::Forms::TextBox());
			this->textBox_Cur_T = (gcnew System::Windows::Forms::TextBox());
			this->label_Set = (gcnew System::Windows::Forms::Label());
			this->label_current = (gcnew System::Windows::Forms::Label());
			this->button_degree_C = (gcnew System::Windows::Forms::Button());
			this->button_degree_F = (gcnew System::Windows::Forms::Button());
			this->panel_mcu_HCV = (gcnew System::Windows::Forms::Panel());
			this->label_MCU_CIRCstatus = (gcnew System::Windows::Forms::Label());
			this->pictureBox_CIRC_MCU = (gcnew System::Windows::Forms::PictureBox());
			this->label_MCU_UVstatus = (gcnew System::Windows::Forms::Label());
			this->pictureBox_UV_MCU = (gcnew System::Windows::Forms::PictureBox());
			this->label_MCU_Heater_status = (gcnew System::Windows::Forms::Label());
			this->pictureBox_HT_MCU = (gcnew System::Windows::Forms::PictureBox());
			this->panel_lock = (gcnew System::Windows::Forms::Panel());
			this->button_Panel_Lock = (gcnew System::Windows::Forms::Button());
			this->button_Pump_Lock = (gcnew System::Windows::Forms::Button());
			this->button_Func_Lock = (gcnew System::Windows::Forms::Button());
			this->button_T_Lock = (gcnew System::Windows::Forms::Button());
			this->button_unlock = (gcnew System::Windows::Forms::Button());
			this->panel_Err_area = (gcnew System::Windows::Forms::Panel());
			this->panel_Err_Msg = (gcnew System::Windows::Forms::Panel());
			this->lbl_disp_EH_page = (gcnew System::Windows::Forms::Label());
			this->textBox_eMsg4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_eMsg3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_eMsg2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_eMsg1 = (gcnew System::Windows::Forms::TextBox());
			this->button_Err_Msg = (gcnew System::Windows::Forms::Button());
			this->panel_Service_Hint = (gcnew System::Windows::Forms::Panel());
			this->lbl_service_0 = (gcnew System::Windows::Forms::Label());
			this->panel_Service_Hint_1 = (gcnew System::Windows::Forms::Panel());
			this->lbl_service_1 = (gcnew System::Windows::Forms::Label());
			this->richTextBox_main_output = (gcnew System::Windows::Forms::RichTextBox());
			this->panel_measure = (gcnew System::Windows::Forms::Panel());
			this->textBox4_System_Voltage = (gcnew System::Windows::Forms::TextBox());
			this->textBox_Current_Amp = (gcnew System::Windows::Forms::TextBox());
			this->label_sysVoltage = (gcnew System::Windows::Forms::Label());
			this->label_totalAmp = (gcnew System::Windows::Forms::Label());
			this->label_Relay = (gcnew System::Windows::Forms::Label());
			this->panel_Relay = (gcnew System::Windows::Forms::Panel());
			this->panel_Relay_status = (gcnew System::Windows::Forms::Panel());
			this->label_Relay_Status = (gcnew System::Windows::Forms::Label());
			this->panel_Device = (gcnew System::Windows::Forms::Panel());
			this->label_Device_1 = (gcnew System::Windows::Forms::Label());
			this->panel_Operation = (gcnew System::Windows::Forms::Panel());
			this->label_Operation = (gcnew System::Windows::Forms::Label());
			this->panel_P1R = (gcnew System::Windows::Forms::Panel());
			this->label_P1R = (gcnew System::Windows::Forms::Label());
			this->panel_P1R_status = (gcnew System::Windows::Forms::Panel());
			this->pictureBox_P1R_status = (gcnew System::Windows::Forms::PictureBox());
			this->panel_Pump1 = (gcnew System::Windows::Forms::Panel());
			this->label_Pum1 = (gcnew System::Windows::Forms::Label());
			this->panel_P1_HiLo = (gcnew System::Windows::Forms::Panel());
			this->button_P1_Lo = (gcnew System::Windows::Forms::Button());
			this->button_P1_Hi = (gcnew System::Windows::Forms::Button());
			this->panel_MCU_status = (gcnew System::Windows::Forms::Panel());
			this->label_MCU_status = (gcnew System::Windows::Forms::Label());
			this->panel_P1_MCU = (gcnew System::Windows::Forms::Panel());
			this->pictureBox_P1_MCU = (gcnew System::Windows::Forms::PictureBox());
			this->panel_Device_Amp = (gcnew System::Windows::Forms::Panel());
			this->label_Device_Amp = (gcnew System::Windows::Forms::Label());
			this->panel_P1_Amp = (gcnew System::Windows::Forms::Panel());
			this->textBox_P1_Amp = (gcnew System::Windows::Forms::TextBox());
			this->panel_P2_Amp = (gcnew System::Windows::Forms::Panel());
			this->textBox_P2_Amp = (gcnew System::Windows::Forms::TextBox());
			this->panel_P2_MCU = (gcnew System::Windows::Forms::Panel());
			this->pictureBox_P2_MCU = (gcnew System::Windows::Forms::PictureBox());
			this->panel_P2_HiLo = (gcnew System::Windows::Forms::Panel());
			this->button_P2_Lo = (gcnew System::Windows::Forms::Button());
			this->button_P2_Hi = (gcnew System::Windows::Forms::Button());
			this->panel_Pump2 = (gcnew System::Windows::Forms::Panel());
			this->label_Pump2 = (gcnew System::Windows::Forms::Label());
			this->panel_P2R_status = (gcnew System::Windows::Forms::Panel());
			this->pictureBox_P2R_status = (gcnew System::Windows::Forms::PictureBox());
			this->panel_p2R = (gcnew System::Windows::Forms::Panel());
			this->label_P2R = (gcnew System::Windows::Forms::Label());
			this->panel_P3_Amp = (gcnew System::Windows::Forms::Panel());
			this->textBox_P3_Amp = (gcnew System::Windows::Forms::TextBox());
			this->panel_P3_MCU = (gcnew System::Windows::Forms::Panel());
			this->pictureBox_P3_MCU = (gcnew System::Windows::Forms::PictureBox());
			this->panel_P3_HiLo = (gcnew System::Windows::Forms::Panel());
			this->button_P3_Lo = (gcnew System::Windows::Forms::Button());
			this->button_P3_Hi = (gcnew System::Windows::Forms::Button());
			this->panel_Pump3 = (gcnew System::Windows::Forms::Panel());
			this->label_Pum3 = (gcnew System::Windows::Forms::Label());
			this->panel_P3R_status = (gcnew System::Windows::Forms::Panel());
			this->pictureBox_P3R_status = (gcnew System::Windows::Forms::PictureBox());
			this->panel_P3R = (gcnew System::Windows::Forms::Panel());
			this->label_P3R = (gcnew System::Windows::Forms::Label());
			this->panel_Blower_Amp = (gcnew System::Windows::Forms::Panel());
			this->textBox_Blower_Amp = (gcnew System::Windows::Forms::TextBox());
			this->panel_Blower_MCU = (gcnew System::Windows::Forms::Panel());
			this->pictureBox_Blower_MCU = (gcnew System::Windows::Forms::PictureBox());
			this->panel_Blower_OnOff = (gcnew System::Windows::Forms::Panel());
			this->button_Blower_OnOff = (gcnew System::Windows::Forms::Button());
			this->panel_Blower = (gcnew System::Windows::Forms::Panel());
			this->label_Blower = (gcnew System::Windows::Forms::Label());
			this->panel_RH_status = (gcnew System::Windows::Forms::Panel());
			this->pictureBox_RH_status = (gcnew System::Windows::Forms::PictureBox());
			this->panel_RH = (gcnew System::Windows::Forms::Panel());
			this->label_RH = (gcnew System::Windows::Forms::Label());
			this->panel_Filter = (gcnew System::Windows::Forms::Panel());
			this->label_Days_1 = (gcnew System::Windows::Forms::Label());
			this->textBox_Filter_Days = (gcnew System::Windows::Forms::TextBox());
			this->label_Filter = (gcnew System::Windows::Forms::Label());
			this->panel_UV = (gcnew System::Windows::Forms::Panel());
			this->label_Days_2 = (gcnew System::Windows::Forms::Label());
			this->textBox_UV_Days = (gcnew System::Windows::Forms::TextBox());
			this->label_UV = (gcnew System::Windows::Forms::Label());
			this->button_SF = (gcnew System::Windows::Forms::Button());
			this->button_PF = (gcnew System::Windows::Forms::Button());
			this->button_Date_Time = (gcnew System::Windows::Forms::Button());
			this->button_Filtration_sch = (gcnew System::Windows::Forms::Button());
			this->button_mode = (gcnew System::Windows::Forms::Button());
			this->pictureBox_ECO = (gcnew System::Windows::Forms::PictureBox());
			this->label_ECO_mode = (gcnew System::Windows::Forms::Label());
			this->panel_ECO_mode = (gcnew System::Windows::Forms::Panel());
			this->panel_control = (gcnew System::Windows::Forms::Panel());
			this->button_OSC_list = (gcnew System::Windows::Forms::Button());
			this->richTextBox_comment = (gcnew System::Windows::Forms::RichTextBox());
			this->button_History = (gcnew System::Windows::Forms::Button());
			this->button_Service_Call = (gcnew System::Windows::Forms::Button());
			this->button_RDS_report = (gcnew System::Windows::Forms::Button());
			this->richTextBox_EngMsg = (gcnew System::Windows::Forms::RichTextBox());
			this->panel_EngArea = (gcnew System::Windows::Forms::Panel());
			this->lbl_EH_pageCnt = (gcnew System::Windows::Forms::Label());
			this->lbl_EH_S_page = (gcnew System::Windows::Forms::Label());
			this->lbl_EH_Total_page = (gcnew System::Windows::Forms::Label());
			this->lbl_EH_page = (gcnew System::Windows::Forms::Label());
			this->richTextBox_ActLog = (gcnew System::Windows::Forms::RichTextBox());
			this->button_blue = (gcnew System::Windows::Forms::Button());
			this->button_red = (gcnew System::Windows::Forms::Button());
			this->button_yellow = (gcnew System::Windows::Forms::Button());
			this->button_green = (gcnew System::Windows::Forms::Button());
			this->lbl_writePktCount = (gcnew System::Windows::Forms::Label());
			this->lbl_writeTimeout = (gcnew System::Windows::Forms::Label());
			this->lbl_WLv = (gcnew System::Windows::Forms::Label());
			this->lbl_HTstate = (gcnew System::Windows::Forms::Label());
			this->lbl_WTstate = (gcnew System::Windows::Forms::Label());
			this->lbl_validCMDcode = (gcnew System::Windows::Forms::Label());
			this->lbl_NAT_type = (gcnew System::Windows::Forms::Label());
			this->lbl_remotePort = (gcnew System::Windows::Forms::Label());
			this->lbl_remoteIP = (gcnew System::Windows::Forms::Label());
			this->lbl_sCorD = (gcnew System::Windows::Forms::Label());
			this->lbl_sMode = (gcnew System::Windows::Forms::Label());
			this->lbl_PktTimeOut = (gcnew System::Windows::Forms::Label());
			this->label_pktTimeOut = (gcnew System::Windows::Forms::Label());
			this->button_update = (gcnew System::Windows::Forms::Button());
			this->lbl_pktRate = (gcnew System::Windows::Forms::Label());
			this->label_pktRate = (gcnew System::Windows::Forms::Label());
			this->lbl_PktLoss = (gcnew System::Windows::Forms::Label());
			this->label_pktLoss = (gcnew System::Windows::Forms::Label());
			this->lbl_PSN = (gcnew System::Windows::Forms::Label());
			this->label_packetSN = (gcnew System::Windows::Forms::Label());
			this->label_tube_model = (gcnew System::Windows::Forms::Label());
			this->panel_model = (gcnew System::Windows::Forms::Panel());
			this->comboBox_Model_Name = (gcnew System::Windows::Forms::ComboBox());
			this->panel_FilterSch = (gcnew System::Windows::Forms::Panel());
			this->panel_DateTime = (gcnew System::Windows::Forms::Panel());
			this->panel_heater_Amp = (gcnew System::Windows::Forms::Panel());
			this->textBox_Heater_Amp = (gcnew System::Windows::Forms::TextBox());
			this->lb_wait_pkt = (gcnew System::Windows::Forms::Label());
			this->lb_wait_cmd = (gcnew System::Windows::Forms::Label());
			this->lb_wait_NBcmd = (gcnew System::Windows::Forms::Label());
			this->panel_UID->SuspendLayout();
			this->panel_owner->SuspendLayout();
			this->panel_spa_serial->SuspendLayout();
			this->panel_disconnect->SuspendLayout();
			this->panel_connect->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_packet_sign))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_connect_light))->BeginInit();
			this->panel_auto_diag->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_auto_diag))->BeginInit();
			this->panel_temperature->SuspendLayout();
			this->panel_mcu_HCV->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_CIRC_MCU))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_UV_MCU))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_HT_MCU))->BeginInit();
			this->panel_lock->SuspendLayout();
			this->panel_Err_area->SuspendLayout();
			this->panel_Err_Msg->SuspendLayout();
			this->panel_Service_Hint->SuspendLayout();
			this->panel_Service_Hint_1->SuspendLayout();
			this->panel_measure->SuspendLayout();
			this->panel_Relay->SuspendLayout();
			this->panel_Relay_status->SuspendLayout();
			this->panel_Device->SuspendLayout();
			this->panel_Operation->SuspendLayout();
			this->panel_P1R->SuspendLayout();
			this->panel_P1R_status->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_P1R_status))->BeginInit();
			this->panel_Pump1->SuspendLayout();
			this->panel_P1_HiLo->SuspendLayout();
			this->panel_MCU_status->SuspendLayout();
			this->panel_P1_MCU->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_P1_MCU))->BeginInit();
			this->panel_Device_Amp->SuspendLayout();
			this->panel_P1_Amp->SuspendLayout();
			this->panel_P2_Amp->SuspendLayout();
			this->panel_P2_MCU->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_P2_MCU))->BeginInit();
			this->panel_P2_HiLo->SuspendLayout();
			this->panel_Pump2->SuspendLayout();
			this->panel_P2R_status->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_P2R_status))->BeginInit();
			this->panel_p2R->SuspendLayout();
			this->panel_P3_Amp->SuspendLayout();
			this->panel_P3_MCU->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_P3_MCU))->BeginInit();
			this->panel_P3_HiLo->SuspendLayout();
			this->panel_Pump3->SuspendLayout();
			this->panel_P3R_status->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_P3R_status))->BeginInit();
			this->panel_P3R->SuspendLayout();
			this->panel_Blower_Amp->SuspendLayout();
			this->panel_Blower_MCU->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_Blower_MCU))->BeginInit();
			this->panel_Blower_OnOff->SuspendLayout();
			this->panel_Blower->SuspendLayout();
			this->panel_RH_status->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_RH_status))->BeginInit();
			this->panel_RH->SuspendLayout();
			this->panel_Filter->SuspendLayout();
			this->panel_UV->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_ECO))->BeginInit();
			this->panel_ECO_mode->SuspendLayout();
			this->panel_control->SuspendLayout();
			this->panel_EngArea->SuspendLayout();
			this->panel_model->SuspendLayout();
			this->panel_FilterSch->SuspendLayout();
			this->panel_DateTime->SuspendLayout();
			this->panel_heater_Amp->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel_UID
			// 
			this->panel_UID->AutoSize = true;
			this->panel_UID->BackColor = System::Drawing::Color::SteelBlue;
			this->panel_UID->Controls->Add(this->textBox_UID_in);
			this->panel_UID->Controls->Add(this->label_UID);
			this->panel_UID->Location = System::Drawing::Point(2, 1);
			this->panel_UID->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->panel_UID->Name = L"panel_UID";
			this->panel_UID->Size = System::Drawing::Size(260, 61);
			this->panel_UID->TabIndex = 0;
			// 
			// textBox_UID_in
			// 
			this->textBox_UID_in->Font = (gcnew System::Drawing::Font(L"AVGmdBU", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox_UID_in->Location = System::Drawing::Point(9, 28);
			this->textBox_UID_in->Name = L"textBox_UID_in";
			this->textBox_UID_in->Size = System::Drawing::Size(240, 24);
			this->textBox_UID_in->TabIndex = 1;
			this->textBox_UID_in->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label_UID
			// 
			this->label_UID->AutoSize = true;
			this->label_UID->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_UID->ForeColor = System::Drawing::Color::White;
			this->label_UID->Location = System::Drawing::Point(54, 5);
			this->label_UID->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_UID->Name = L"label_UID";
			this->label_UID->Size = System::Drawing::Size(128, 19);
			this->label_UID->TabIndex = 0;
			this->label_UID->Text = L"Spa Wireless UID";
			// 
			// panel_owner
			// 
			this->panel_owner->AutoSize = true;
			this->panel_owner->BackColor = System::Drawing::Color::SteelBlue;
			this->panel_owner->Controls->Add(this->textBox_owner_in);
			this->panel_owner->Controls->Add(this->label_owner);
			this->panel_owner->Location = System::Drawing::Point(650, 1);
			this->panel_owner->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->panel_owner->Name = L"panel_owner";
			this->panel_owner->Size = System::Drawing::Size(203, 61);
			this->panel_owner->TabIndex = 2;
			// 
			// textBox_owner_in
			// 
			this->textBox_owner_in->BackColor = System::Drawing::Color::LightBlue;
			this->textBox_owner_in->Font = (gcnew System::Drawing::Font(L"AVGmdBU", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox_owner_in->Location = System::Drawing::Point(14, 28);
			this->textBox_owner_in->Name = L"textBox_owner_in";
			this->textBox_owner_in->Size = System::Drawing::Size(169, 24);
			this->textBox_owner_in->TabIndex = 1;
			this->textBox_owner_in->Text = L"Mr. James Smith";
			this->textBox_owner_in->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label_owner
			// 
			this->label_owner->AutoSize = true;
			this->label_owner->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_owner->ForeColor = System::Drawing::Color::White;
			this->label_owner->Location = System::Drawing::Point(56, 5);
			this->label_owner->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_owner->Name = L"label_owner";
			this->label_owner->Size = System::Drawing::Size(99, 19);
			this->label_owner->TabIndex = 0;
			this->label_owner->Text = L"Owner Name";
			this->label_owner->Click += gcnew System::EventHandler(this, &RDS_main_Form::label_owner_Click);
			// 
			// panel_spa_serial
			// 
			this->panel_spa_serial->AutoSize = true;
			this->panel_spa_serial->BackColor = System::Drawing::Color::SteelBlue;
			this->panel_spa_serial->Controls->Add(this->textBox_spa_serial);
			this->panel_spa_serial->Controls->Add(this->label_spa_serial);
			this->panel_spa_serial->Location = System::Drawing::Point(460, 1);
			this->panel_spa_serial->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->panel_spa_serial->Name = L"panel_spa_serial";
			this->panel_spa_serial->Size = System::Drawing::Size(189, 61);
			this->panel_spa_serial->TabIndex = 3;
			// 
			// textBox_spa_serial
			// 
			this->textBox_spa_serial->BackColor = System::Drawing::Color::LightBlue;
			this->textBox_spa_serial->Font = (gcnew System::Drawing::Font(L"AVGmdBU", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox_spa_serial->Location = System::Drawing::Point(17, 28);
			this->textBox_spa_serial->Name = L"textBox_spa_serial";
			this->textBox_spa_serial->Size = System::Drawing::Size(154, 24);
			this->textBox_spa_serial->TabIndex = 1;
			this->textBox_spa_serial->Text = L"1234567890";
			this->textBox_spa_serial->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label_spa_serial
			// 
			this->label_spa_serial->AutoSize = true;
			this->label_spa_serial->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_spa_serial->ForeColor = System::Drawing::Color::White;
			this->label_spa_serial->Location = System::Drawing::Point(26, 5);
			this->label_spa_serial->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_spa_serial->Name = L"label_spa_serial";
			this->label_spa_serial->Size = System::Drawing::Size(138, 19);
			this->label_spa_serial->TabIndex = 0;
			this->label_spa_serial->Text = L"Spa Serial Number";
			this->label_spa_serial->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->label_spa_serial->Click += gcnew System::EventHandler(this, &RDS_main_Form::label_spa_serial_Click);
			// 
			// panel_disconnect
			// 
			this->panel_disconnect->AutoSize = true;
			this->panel_disconnect->BackColor = System::Drawing::Color::CadetBlue;
			this->panel_disconnect->Controls->Add(this->button_disconnect);
			this->panel_disconnect->Location = System::Drawing::Point(854, 1);
			this->panel_disconnect->Name = L"panel_disconnect";
			this->panel_disconnect->Size = System::Drawing::Size(132, 61);
			this->panel_disconnect->TabIndex = 4;
			// 
			// button_disconnect
			// 
			this->button_disconnect->Enabled = false;
			this->button_disconnect->ForeColor = System::Drawing::Color::Gray;
			this->button_disconnect->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_disconnect.Image")));
			this->button_disconnect->Location = System::Drawing::Point(15, 10);
			this->button_disconnect->Name = L"button_disconnect";
			this->button_disconnect->Size = System::Drawing::Size(106, 41);
			this->button_disconnect->TabIndex = 0;
			this->button_disconnect->Text = L"Disconnect";
			this->button_disconnect->UseVisualStyleBackColor = true;
			this->button_disconnect->Click += gcnew System::EventHandler(this, &RDS_main_Form::button_disconnect_Click);
			// 
			// panel_connect
			// 
			this->panel_connect->AutoSize = true;
			this->panel_connect->BackColor = System::Drawing::Color::CadetBlue;
			this->panel_connect->Controls->Add(this->pictureBox_packet_sign);
			this->panel_connect->Controls->Add(this->pictureBox_connect_light);
			this->panel_connect->Controls->Add(this->label_slash);
			this->panel_connect->Controls->Add(this->button_connect);
			this->panel_connect->Location = System::Drawing::Point(2, 63);
			this->panel_connect->Name = L"panel_connect";
			this->panel_connect->Size = System::Drawing::Size(260, 45);
			this->panel_connect->TabIndex = 5;
			// 
			// pictureBox_packet_sign
			// 
			this->pictureBox_packet_sign->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox_packet_sign.Image")));
			this->pictureBox_packet_sign->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox_packet_sign.InitialImage")));
			this->pictureBox_packet_sign->Location = System::Drawing::Point(221, 9);
			this->pictureBox_packet_sign->Name = L"pictureBox_packet_sign";
			this->pictureBox_packet_sign->Size = System::Drawing::Size(28, 26);
			this->pictureBox_packet_sign->TabIndex = 4;
			this->pictureBox_packet_sign->TabStop = false;
			// 
			// pictureBox_connect_light
			// 
			this->pictureBox_connect_light->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox_connect_light.Image")));
			this->pictureBox_connect_light->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox_connect_light.InitialImage")));
			this->pictureBox_connect_light->Location = System::Drawing::Point(173, 9);
			this->pictureBox_connect_light->Name = L"pictureBox_connect_light";
			this->pictureBox_connect_light->Size = System::Drawing::Size(28, 26);
			this->pictureBox_connect_light->TabIndex = 3;
			this->pictureBox_connect_light->TabStop = false;
			// 
			// label_slash
			// 
			this->label_slash->AutoSize = true;
			this->label_slash->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_slash->ForeColor = System::Drawing::Color::White;
			this->label_slash->Location = System::Drawing::Point(204, 9);
			this->label_slash->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_slash->Name = L"label_slash";
			this->label_slash->Size = System::Drawing::Size(14, 19);
			this->label_slash->TabIndex = 2;
			this->label_slash->Text = L"|";
			// 
			// button_connect
			// 
			this->button_connect->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_connect.Image")));
			this->button_connect->Location = System::Drawing::Point(12, 6);
			this->button_connect->Name = L"button_connect";
			this->button_connect->Size = System::Drawing::Size(150, 30);
			this->button_connect->TabIndex = 0;
			this->button_connect->Text = L"Connect / Packet";
			this->button_connect->UseVisualStyleBackColor = true;
			this->button_connect->Click += gcnew System::EventHandler(this, &RDS_main_Form::button_connect_Click);
			// 
			// panel_auto_diag
			// 
			this->panel_auto_diag->AutoSize = true;
			this->panel_auto_diag->BackColor = System::Drawing::Color::CadetBlue;
			this->panel_auto_diag->Controls->Add(this->pictureBox_auto_diag);
			this->panel_auto_diag->Controls->Add(this->button_auto_diag);
			this->panel_auto_diag->Location = System::Drawing::Point(2, 108);
			this->panel_auto_diag->Name = L"panel_auto_diag";
			this->panel_auto_diag->Size = System::Drawing::Size(260, 40);
			this->panel_auto_diag->TabIndex = 5;
			// 
			// pictureBox_auto_diag
			// 
			this->pictureBox_auto_diag->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox_auto_diag.Image")));
			this->pictureBox_auto_diag->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox_auto_diag.InitialImage")));
			this->pictureBox_auto_diag->Location = System::Drawing::Point(196, 6);
			this->pictureBox_auto_diag->Name = L"pictureBox_auto_diag";
			this->pictureBox_auto_diag->Size = System::Drawing::Size(28, 26);
			this->pictureBox_auto_diag->TabIndex = 5;
			this->pictureBox_auto_diag->TabStop = false;
			// 
			// button_auto_diag
			// 
			this->button_auto_diag->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_auto_diag.Image")));
			this->button_auto_diag->Location = System::Drawing::Point(12, 2);
			this->button_auto_diag->Name = L"button_auto_diag";
			this->button_auto_diag->Size = System::Drawing::Size(150, 30);
			this->button_auto_diag->TabIndex = 0;
			this->button_auto_diag->Text = L"Auto Diagnostic";
			this->button_auto_diag->UseVisualStyleBackColor = true;
			this->button_auto_diag->Click += gcnew System::EventHandler(this, &RDS_main_Form::button_auto_diag_Click);
			// 
			// panel_temperature
			// 
			this->panel_temperature->AutoSize = true;
			this->panel_temperature->BackColor = System::Drawing::Color::Navy;
			this->panel_temperature->Controls->Add(this->label_PCB);
			this->panel_temperature->Controls->Add(this->label_HiLmt);
			this->panel_temperature->Controls->Add(this->label_temperature_4);
			this->panel_temperature->Controls->Add(this->textBox_PCB_T);
			this->panel_temperature->Controls->Add(this->textBox_Set_T);
			this->panel_temperature->Controls->Add(this->textBox_HiLmt_T);
			this->panel_temperature->Controls->Add(this->textBox_Cur_T);
			this->panel_temperature->Controls->Add(this->label_Set);
			this->panel_temperature->Controls->Add(this->label_current);
			this->panel_temperature->Controls->Add(this->button_degree_C);
			this->panel_temperature->Controls->Add(this->button_degree_F);
			this->panel_temperature->Location = System::Drawing::Point(263, 63);
			this->panel_temperature->Name = L"panel_temperature";
			this->panel_temperature->Size = System::Drawing::Size(723, 85);
			this->panel_temperature->TabIndex = 5;
			// 
			// label_PCB
			// 
			this->label_PCB->AutoSize = true;
			this->label_PCB->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_PCB->ForeColor = System::Drawing::Color::White;
			this->label_PCB->Location = System::Drawing::Point(517, 2);
			this->label_PCB->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_PCB->Name = L"label_PCB";
			this->label_PCB->Size = System::Drawing::Size(131, 19);
			this->label_PCB->TabIndex = 13;
			this->label_PCB->Text = L"PCB Temperature";
			// 
			// label_HiLmt
			// 
			this->label_HiLmt->AutoSize = true;
			this->label_HiLmt->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_HiLmt->ForeColor = System::Drawing::Color::White;
			this->label_HiLmt->Location = System::Drawing::Point(336, 2);
			this->label_HiLmt->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_HiLmt->Name = L"label_HiLmt";
			this->label_HiLmt->Size = System::Drawing::Size(158, 19);
			this->label_HiLmt->TabIndex = 12;
			this->label_HiLmt->Text = L"Hi-Limit Temperature";
			// 
			// label_temperature_4
			// 
			this->label_temperature_4->AutoSize = true;
			this->label_temperature_4->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_temperature_4->ForeColor = System::Drawing::Color::White;
			this->label_temperature_4->Location = System::Drawing::Point(490, 16);
			this->label_temperature_4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_temperature_4->Name = L"label_temperature_4";
			this->label_temperature_4->Size = System::Drawing::Size(0, 19);
			this->label_temperature_4->TabIndex = 11;
			// 
			// textBox_PCB_T
			// 
			this->textBox_PCB_T->BackColor = System::Drawing::Color::LightSteelBlue;
			this->textBox_PCB_T->Font = (gcnew System::Drawing::Font(L"AVGmdBU", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->textBox_PCB_T->Location = System::Drawing::Point(508, 25);
			this->textBox_PCB_T->Name = L"textBox_PCB_T";
			this->textBox_PCB_T->Size = System::Drawing::Size(150, 57);
			this->textBox_PCB_T->TabIndex = 9;
			this->textBox_PCB_T->Text = L"xx.xC";
			this->textBox_PCB_T->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox_Set_T
			// 
			this->textBox_Set_T->BackColor = System::Drawing::Color::White;
			this->textBox_Set_T->Font = (gcnew System::Drawing::Font(L"AVGmdBU", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->textBox_Set_T->Location = System::Drawing::Point(177, 25);
			this->textBox_Set_T->Name = L"textBox_Set_T";
			this->textBox_Set_T->Size = System::Drawing::Size(150, 57);
			this->textBox_Set_T->TabIndex = 8;
			this->textBox_Set_T->Text = L"xx.xC";
			this->textBox_Set_T->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox_Set_T->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &RDS_main_Form::textBox_Set_T_MouseClick);
			// 
			// textBox_HiLmt_T
			// 
			this->textBox_HiLmt_T->BackColor = System::Drawing::Color::LightSteelBlue;
			this->textBox_HiLmt_T->Font = (gcnew System::Drawing::Font(L"AVGmdBU", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->textBox_HiLmt_T->Location = System::Drawing::Point(342, 25);
			this->textBox_HiLmt_T->Name = L"textBox_HiLmt_T";
			this->textBox_HiLmt_T->Size = System::Drawing::Size(150, 57);
			this->textBox_HiLmt_T->TabIndex = 7;
			this->textBox_HiLmt_T->Text = L"xx.xC";
			this->textBox_HiLmt_T->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox_Cur_T
			// 
			this->textBox_Cur_T->BackColor = System::Drawing::Color::LightSteelBlue;
			this->textBox_Cur_T->Font = (gcnew System::Drawing::Font(L"AVGmdBU", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->textBox_Cur_T->Location = System::Drawing::Point(12, 24);
			this->textBox_Cur_T->Name = L"textBox_Cur_T";
			this->textBox_Cur_T->Size = System::Drawing::Size(150, 57);
			this->textBox_Cur_T->TabIndex = 2;
			this->textBox_Cur_T->Text = L"xx.xC";
			this->textBox_Cur_T->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label_Set
			// 
			this->label_Set->AutoSize = true;
			this->label_Set->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_Set->ForeColor = System::Drawing::Color::White;
			this->label_Set->Location = System::Drawing::Point(191, 2);
			this->label_Set->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_Set->Name = L"label_Set";
			this->label_Set->Size = System::Drawing::Size(124, 19);
			this->label_Set->TabIndex = 5;
			this->label_Set->Text = L"Set Temperature";
			// 
			// label_current
			// 
			this->label_current->AutoSize = true;
			this->label_current->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_current->ForeColor = System::Drawing::Color::White;
			this->label_current->Location = System::Drawing::Point(9, 2);
			this->label_current->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_current->Name = L"label_current";
			this->label_current->Size = System::Drawing::Size(157, 19);
			this->label_current->TabIndex = 2;
			this->label_current->Text = L"Current Temperature";
			// 
			// button_degree_C
			// 
			this->button_degree_C->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_degree_C.Image")));
			this->button_degree_C->Location = System::Drawing::Point(671, 47);
			this->button_degree_C->Name = L"button_degree_C";
			this->button_degree_C->Size = System::Drawing::Size(41, 30);
			this->button_degree_C->TabIndex = 1;
			this->button_degree_C->Text = L"C";
			this->button_degree_C->UseVisualStyleBackColor = true;
			this->button_degree_C->Click += gcnew System::EventHandler(this, &RDS_main_Form::button_degree_C_Click);
			// 
			// button_degree_F
			// 
			this->button_degree_F->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_degree_F.Image")));
			this->button_degree_F->Location = System::Drawing::Point(671, 12);
			this->button_degree_F->Name = L"button_degree_F";
			this->button_degree_F->Size = System::Drawing::Size(41, 30);
			this->button_degree_F->TabIndex = 0;
			this->button_degree_F->Text = L"F";
			this->button_degree_F->UseVisualStyleBackColor = true;
			this->button_degree_F->Click += gcnew System::EventHandler(this, &RDS_main_Form::button_degree_F_Click);
			// 
			// panel_mcu_HCV
			// 
			this->panel_mcu_HCV->BackColor = System::Drawing::Color::CornflowerBlue;
			this->panel_mcu_HCV->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel_mcu_HCV->Controls->Add(this->label_MCU_CIRCstatus);
			this->panel_mcu_HCV->Controls->Add(this->pictureBox_CIRC_MCU);
			this->panel_mcu_HCV->Controls->Add(this->label_MCU_UVstatus);
			this->panel_mcu_HCV->Controls->Add(this->pictureBox_UV_MCU);
			this->panel_mcu_HCV->Controls->Add(this->label_MCU_Heater_status);
			this->panel_mcu_HCV->Controls->Add(this->pictureBox_HT_MCU);
			this->panel_mcu_HCV->Location = System::Drawing::Point(108, 453);
			this->panel_mcu_HCV->Name = L"panel_mcu_HCV";
			this->panel_mcu_HCV->Size = System::Drawing::Size(295, 45);
			this->panel_mcu_HCV->TabIndex = 6;
			// 
			// label_MCU_CIRCstatus
			// 
			this->label_MCU_CIRCstatus->AutoSize = true;
			this->label_MCU_CIRCstatus->BackColor = System::Drawing::Color::CornflowerBlue;
			this->label_MCU_CIRCstatus->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_MCU_CIRCstatus->ForeColor = System::Drawing::Color::White;
			this->label_MCU_CIRCstatus->Location = System::Drawing::Point(115, 12);
			this->label_MCU_CIRCstatus->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_MCU_CIRCstatus->Name = L"label_MCU_CIRCstatus";
			this->label_MCU_CIRCstatus->Size = System::Drawing::Size(42, 19);
			this->label_MCU_CIRCstatus->TabIndex = 3;
			this->label_MCU_CIRCstatus->Text = L"CIRC";
			this->label_MCU_CIRCstatus->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// pictureBox_CIRC_MCU
			// 
			this->pictureBox_CIRC_MCU->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox_CIRC_MCU.Image")));
			this->pictureBox_CIRC_MCU->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox_CIRC_MCU.InitialImage")));
			this->pictureBox_CIRC_MCU->Location = System::Drawing::Point(163, 9);
			this->pictureBox_CIRC_MCU->Name = L"pictureBox_CIRC_MCU";
			this->pictureBox_CIRC_MCU->Size = System::Drawing::Size(28, 26);
			this->pictureBox_CIRC_MCU->TabIndex = 6;
			this->pictureBox_CIRC_MCU->TabStop = false;
			// 
			// label_MCU_UVstatus
			// 
			this->label_MCU_UVstatus->AutoSize = true;
			this->label_MCU_UVstatus->BackColor = System::Drawing::Color::CornflowerBlue;
			this->label_MCU_UVstatus->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_MCU_UVstatus->ForeColor = System::Drawing::Color::White;
			this->label_MCU_UVstatus->Location = System::Drawing::Point(217, 11);
			this->label_MCU_UVstatus->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_MCU_UVstatus->Name = L"label_MCU_UVstatus";
			this->label_MCU_UVstatus->Size = System::Drawing::Size(29, 19);
			this->label_MCU_UVstatus->TabIndex = 7;
			this->label_MCU_UVstatus->Text = L"UV";
			this->label_MCU_UVstatus->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// pictureBox_UV_MCU
			// 
			this->pictureBox_UV_MCU->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox_UV_MCU.Image")));
			this->pictureBox_UV_MCU->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox_UV_MCU.InitialImage")));
			this->pictureBox_UV_MCU->Location = System::Drawing::Point(249, 8);
			this->pictureBox_UV_MCU->Name = L"pictureBox_UV_MCU";
			this->pictureBox_UV_MCU->Size = System::Drawing::Size(28, 26);
			this->pictureBox_UV_MCU->TabIndex = 8;
			this->pictureBox_UV_MCU->TabStop = false;
			// 
			// label_MCU_Heater_status
			// 
			this->label_MCU_Heater_status->AutoSize = true;
			this->label_MCU_Heater_status->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_MCU_Heater_status->ForeColor = System::Drawing::Color::White;
			this->label_MCU_Heater_status->Location = System::Drawing::Point(3, 10);
			this->label_MCU_Heater_status->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_MCU_Heater_status->Name = L"label_MCU_Heater_status";
			this->label_MCU_Heater_status->Size = System::Drawing::Size(56, 19);
			this->label_MCU_Heater_status->TabIndex = 14;
			this->label_MCU_Heater_status->Text = L"Heater";
			this->label_MCU_Heater_status->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// pictureBox_HT_MCU
			// 
			this->pictureBox_HT_MCU->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox_HT_MCU.Image")));
			this->pictureBox_HT_MCU->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox_HT_MCU.InitialImage")));
			this->pictureBox_HT_MCU->Location = System::Drawing::Point(66, 8);
			this->pictureBox_HT_MCU->Name = L"pictureBox_HT_MCU";
			this->pictureBox_HT_MCU->Size = System::Drawing::Size(28, 26);
			this->pictureBox_HT_MCU->TabIndex = 5;
			this->pictureBox_HT_MCU->TabStop = false;
			// 
			// panel_lock
			// 
			this->panel_lock->BackColor = System::Drawing::Color::LightSkyBlue;
			this->panel_lock->Controls->Add(this->button_Panel_Lock);
			this->panel_lock->Controls->Add(this->button_Pump_Lock);
			this->panel_lock->Controls->Add(this->button_Func_Lock);
			this->panel_lock->Controls->Add(this->button_T_Lock);
			this->panel_lock->Controls->Add(this->button_unlock);
			this->panel_lock->Location = System::Drawing::Point(2, 149);
			this->panel_lock->Name = L"panel_lock";
			this->panel_lock->Size = System::Drawing::Size(814, 45);
			this->panel_lock->TabIndex = 5;
			// 
			// button_Panel_Lock
			// 
			this->button_Panel_Lock->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_Panel_Lock.Image")));
			this->button_Panel_Lock->Location = System::Drawing::Point(171, 6);
			this->button_Panel_Lock->Name = L"button_Panel_Lock";
			this->button_Panel_Lock->Size = System::Drawing::Size(146, 33);
			this->button_Panel_Lock->TabIndex = 4;
			this->button_Panel_Lock->Text = L"Panel Lock";
			this->button_Panel_Lock->UseVisualStyleBackColor = true;
			this->button_Panel_Lock->Click += gcnew System::EventHandler(this, &RDS_main_Form::button_Panel_Lock_Click);
			// 
			// button_Pump_Lock
			// 
			this->button_Pump_Lock->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_Pump_Lock.Image")));
			this->button_Pump_Lock->Location = System::Drawing::Point(330, 6);
			this->button_Pump_Lock->Name = L"button_Pump_Lock";
			this->button_Pump_Lock->Size = System::Drawing::Size(146, 33);
			this->button_Pump_Lock->TabIndex = 3;
			this->button_Pump_Lock->Text = L"Pump Lock";
			this->button_Pump_Lock->UseVisualStyleBackColor = true;
			this->button_Pump_Lock->Click += gcnew System::EventHandler(this, &RDS_main_Form::button_Pump_Lock_Click);
			// 
			// button_Func_Lock
			// 
			this->button_Func_Lock->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_Func_Lock.Image")));
			this->button_Func_Lock->Location = System::Drawing::Point(652, 6);
			this->button_Func_Lock->Name = L"button_Func_Lock";
			this->button_Func_Lock->Size = System::Drawing::Size(146, 33);
			this->button_Func_Lock->TabIndex = 2;
			this->button_Func_Lock->Text = L"Service Lock";
			this->button_Func_Lock->UseVisualStyleBackColor = true;
			this->button_Func_Lock->Click += gcnew System::EventHandler(this, &RDS_main_Form::button_Func_Lock_Click);
			// 
			// button_T_Lock
			// 
			this->button_T_Lock->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_T_Lock.Image")));
			this->button_T_Lock->Location = System::Drawing::Point(489, 6);
			this->button_T_Lock->Name = L"button_T_Lock";
			this->button_T_Lock->Size = System::Drawing::Size(146, 33);
			this->button_T_Lock->TabIndex = 1;
			this->button_T_Lock->Text = L"Temperature Lock";
			this->button_T_Lock->UseVisualStyleBackColor = true;
			this->button_T_Lock->Click += gcnew System::EventHandler(this, &RDS_main_Form::button_T_Lock_Click);
			// 
			// button_unlock
			// 
			this->button_unlock->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_unlock.Image")));
			this->button_unlock->Location = System::Drawing::Point(10, 6);
			this->button_unlock->Name = L"button_unlock";
			this->button_unlock->Size = System::Drawing::Size(146, 33);
			this->button_unlock->TabIndex = 0;
			this->button_unlock->Text = L"Un-Lock";
			this->button_unlock->UseVisualStyleBackColor = true;
			this->button_unlock->Click += gcnew System::EventHandler(this, &RDS_main_Form::button_unlock_Click);
			// 
			// panel_Err_area
			// 
			this->panel_Err_area->BackColor = System::Drawing::Color::SteelBlue;
			this->panel_Err_area->Controls->Add(this->panel_Err_Msg);
			this->panel_Err_area->Controls->Add(this->button_Err_Msg);
			this->panel_Err_area->Location = System::Drawing::Point(2, 195);
			this->panel_Err_area->Name = L"panel_Err_area";
			this->panel_Err_area->Size = System::Drawing::Size(698, 79);
			this->panel_Err_area->TabIndex = 5;
			// 
			// panel_Err_Msg
			// 
			this->panel_Err_Msg->BackColor = System::Drawing::Color::PowderBlue;
			this->panel_Err_Msg->Controls->Add(this->lbl_disp_EH_page);
			this->panel_Err_Msg->Controls->Add(this->textBox_eMsg4);
			this->panel_Err_Msg->Controls->Add(this->textBox_eMsg3);
			this->panel_Err_Msg->Controls->Add(this->textBox_eMsg2);
			this->panel_Err_Msg->Controls->Add(this->textBox_eMsg1);
			this->panel_Err_Msg->Location = System::Drawing::Point(94, 8);
			this->panel_Err_Msg->Name = L"panel_Err_Msg";
			this->panel_Err_Msg->Size = System::Drawing::Size(594, 63);
			this->panel_Err_Msg->TabIndex = 1;
			// 
			// lbl_disp_EH_page
			// 
			this->lbl_disp_EH_page->AutoSize = true;
			this->lbl_disp_EH_page->Font = (gcnew System::Drawing::Font(L"Cambria", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_disp_EH_page->ForeColor = System::Drawing::Color::Black;
			this->lbl_disp_EH_page->Location = System::Drawing::Point(3, 3);
			this->lbl_disp_EH_page->Name = L"lbl_disp_EH_page";
			this->lbl_disp_EH_page->Size = System::Drawing::Size(59, 15);
			this->lbl_disp_EH_page->TabIndex = 56;
			this->lbl_disp_EH_page->Text = L"EH_pages";
			// 
			// textBox_eMsg4
			// 
			this->textBox_eMsg4->BackColor = System::Drawing::Color::PowderBlue;
			this->textBox_eMsg4->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox_eMsg4->Font = (gcnew System::Drawing::Font(L"AVGmdBU", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->textBox_eMsg4->ForeColor = System::Drawing::Color::Maroon;
			this->textBox_eMsg4->Location = System::Drawing::Point(449, 19);
			this->textBox_eMsg4->Name = L"textBox_eMsg4";
			this->textBox_eMsg4->Size = System::Drawing::Size(140, 39);
			this->textBox_eMsg4->TabIndex = 17;
			this->textBox_eMsg4->Text = L"FLOW4";
			this->textBox_eMsg4->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox_eMsg3
			// 
			this->textBox_eMsg3->BackColor = System::Drawing::Color::PowderBlue;
			this->textBox_eMsg3->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox_eMsg3->Font = (gcnew System::Drawing::Font(L"AVGmdBU", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->textBox_eMsg3->ForeColor = System::Drawing::Color::Maroon;
			this->textBox_eMsg3->Location = System::Drawing::Point(299, 19);
			this->textBox_eMsg3->Name = L"textBox_eMsg3";
			this->textBox_eMsg3->Size = System::Drawing::Size(142, 39);
			this->textBox_eMsg3->TabIndex = 16;
			this->textBox_eMsg3->Text = L"FLOW3";
			this->textBox_eMsg3->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox_eMsg2
			// 
			this->textBox_eMsg2->BackColor = System::Drawing::Color::PowderBlue;
			this->textBox_eMsg2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox_eMsg2->Font = (gcnew System::Drawing::Font(L"AVGmdBU", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->textBox_eMsg2->ForeColor = System::Drawing::Color::Maroon;
			this->textBox_eMsg2->Location = System::Drawing::Point(150, 19);
			this->textBox_eMsg2->Name = L"textBox_eMsg2";
			this->textBox_eMsg2->Size = System::Drawing::Size(141, 39);
			this->textBox_eMsg2->TabIndex = 15;
			this->textBox_eMsg2->Text = L"FLOW2";
			this->textBox_eMsg2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox_eMsg1
			// 
			this->textBox_eMsg1->BackColor = System::Drawing::Color::PowderBlue;
			this->textBox_eMsg1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox_eMsg1->Font = (gcnew System::Drawing::Font(L"AVGmdBU", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->textBox_eMsg1->ForeColor = System::Drawing::Color::Maroon;
			this->textBox_eMsg1->Location = System::Drawing::Point(3, 19);
			this->textBox_eMsg1->Name = L"textBox_eMsg1";
			this->textBox_eMsg1->Size = System::Drawing::Size(141, 39);
			this->textBox_eMsg1->TabIndex = 14;
			this->textBox_eMsg1->Text = L"FLOW1";
			this->textBox_eMsg1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// button_Err_Msg
			// 
			this->button_Err_Msg->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_Err_Msg.Image")));
			this->button_Err_Msg->Location = System::Drawing::Point(10, 7);
			this->button_Err_Msg->Name = L"button_Err_Msg";
			this->button_Err_Msg->Size = System::Drawing::Size(78, 64);
			this->button_Err_Msg->TabIndex = 0;
			this->button_Err_Msg->Text = L"Error Message";
			this->button_Err_Msg->UseVisualStyleBackColor = true;
			this->button_Err_Msg->Click += gcnew System::EventHandler(this, &RDS_main_Form::button_Err_Msg_Click);
			// 
			// panel_Service_Hint
			// 
			this->panel_Service_Hint->BackColor = System::Drawing::SystemColors::Control;
			this->panel_Service_Hint->Controls->Add(this->lbl_service_0);
			this->panel_Service_Hint->Location = System::Drawing::Point(507, 277);
			this->panel_Service_Hint->Name = L"panel_Service_Hint";
			this->panel_Service_Hint->Size = System::Drawing::Size(479, 20);
			this->panel_Service_Hint->TabIndex = 56;
			// 
			// lbl_service_0
			// 
			this->lbl_service_0->AutoSize = true;
			this->lbl_service_0->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_service_0->ForeColor = System::Drawing::Color::Maroon;
			this->lbl_service_0->Location = System::Drawing::Point(2, 0);
			this->lbl_service_0->Name = L"lbl_service_0";
			this->lbl_service_0->Size = System::Drawing::Size(136, 19);
			this->lbl_service_0->TabIndex = 0;
			this->lbl_service_0->Text = L"Service call label 0";
			// 
			// panel_Service_Hint_1
			// 
			this->panel_Service_Hint_1->BackColor = System::Drawing::SystemColors::Control;
			this->panel_Service_Hint_1->Controls->Add(this->lbl_service_1);
			this->panel_Service_Hint_1->Location = System::Drawing::Point(507, 297);
			this->panel_Service_Hint_1->Name = L"panel_Service_Hint_1";
			this->panel_Service_Hint_1->Size = System::Drawing::Size(479, 20);
			this->panel_Service_Hint_1->TabIndex = 57;
			// 
			// lbl_service_1
			// 
			this->lbl_service_1->AutoSize = true;
			this->lbl_service_1->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_service_1->ForeColor = System::Drawing::Color::Maroon;
			this->lbl_service_1->Location = System::Drawing::Point(2, -1);
			this->lbl_service_1->Name = L"lbl_service_1";
			this->lbl_service_1->Size = System::Drawing::Size(136, 19);
			this->lbl_service_1->TabIndex = 1;
			this->lbl_service_1->Text = L"Service call label 1";
			// 
			// richTextBox_main_output
			// 
			this->richTextBox_main_output->BackColor = System::Drawing::Color::Gainsboro;
			this->richTextBox_main_output->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->richTextBox_main_output->Location = System::Drawing::Point(507, 275);
			this->richTextBox_main_output->Name = L"richTextBox_main_output";
			this->richTextBox_main_output->ReadOnly = true;
			this->richTextBox_main_output->Size = System::Drawing::Size(482, 412);
			this->richTextBox_main_output->TabIndex = 30;
			this->richTextBox_main_output->Text = L"";
			// 
			// panel_measure
			// 
			this->panel_measure->BackColor = System::Drawing::Color::SteelBlue;
			this->panel_measure->Controls->Add(this->textBox4_System_Voltage);
			this->panel_measure->Controls->Add(this->textBox_Current_Amp);
			this->panel_measure->Controls->Add(this->label_sysVoltage);
			this->panel_measure->Controls->Add(this->label_totalAmp);
			this->panel_measure->Location = System::Drawing::Point(701, 195);
			this->panel_measure->Name = L"panel_measure";
			this->panel_measure->Size = System::Drawing::Size(286, 79);
			this->panel_measure->TabIndex = 14;
			// 
			// textBox4_System_Voltage
			// 
			this->textBox4_System_Voltage->BackColor = System::Drawing::Color::PowderBlue;
			this->textBox4_System_Voltage->Font = (gcnew System::Drawing::Font(L"AVGmdBU", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->textBox4_System_Voltage->ForeColor = System::Drawing::Color::MediumBlue;
			this->textBox4_System_Voltage->Location = System::Drawing::Point(147, 25);
			this->textBox4_System_Voltage->Name = L"textBox4_System_Voltage";
			this->textBox4_System_Voltage->Size = System::Drawing::Size(129, 46);
			this->textBox4_System_Voltage->TabIndex = 8;
			this->textBox4_System_Voltage->Text = L"220";
			this->textBox4_System_Voltage->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox_Current_Amp
			// 
			this->textBox_Current_Amp->BackColor = System::Drawing::Color::PowderBlue;
			this->textBox_Current_Amp->Font = (gcnew System::Drawing::Font(L"AVGmdBU", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->textBox_Current_Amp->ForeColor = System::Drawing::Color::MediumBlue;
			this->textBox_Current_Amp->Location = System::Drawing::Point(9, 25);
			this->textBox_Current_Amp->Name = L"textBox_Current_Amp";
			this->textBox_Current_Amp->Size = System::Drawing::Size(129, 46);
			this->textBox_Current_Amp->TabIndex = 2;
			this->textBox_Current_Amp->Text = L"00.0";
			this->textBox_Current_Amp->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label_sysVoltage
			// 
			this->label_sysVoltage->AutoSize = true;
			this->label_sysVoltage->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_sysVoltage->ForeColor = System::Drawing::Color::White;
			this->label_sysVoltage->Location = System::Drawing::Point(190, 4);
			this->label_sysVoltage->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_sysVoltage->Name = L"label_sysVoltage";
			this->label_sysVoltage->Size = System::Drawing::Size(36, 19);
			this->label_sysVoltage->TabIndex = 6;
			this->label_sysVoltage->Text = L"Volt";
			// 
			// label_totalAmp
			// 
			this->label_totalAmp->AutoSize = true;
			this->label_totalAmp->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_totalAmp->ForeColor = System::Drawing::Color::White;
			this->label_totalAmp->Location = System::Drawing::Point(50, 4);
			this->label_totalAmp->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_totalAmp->Name = L"label_totalAmp";
			this->label_totalAmp->Size = System::Drawing::Size(44, 19);
			this->label_totalAmp->TabIndex = 3;
			this->label_totalAmp->Text = L"Amp.";
			// 
			// label_Relay
			// 
			this->label_Relay->AutoSize = true;
			this->label_Relay->BackColor = System::Drawing::Color::LightSteelBlue;
			this->label_Relay->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_Relay->ForeColor = System::Drawing::Color::Black;
			this->label_Relay->Location = System::Drawing::Point(2, 10);
			this->label_Relay->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_Relay->Name = L"label_Relay";
			this->label_Relay->Size = System::Drawing::Size(47, 19);
			this->label_Relay->TabIndex = 2;
			this->label_Relay->Text = L"Relay";
			this->label_Relay->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel_Relay
			// 
			this->panel_Relay->BackColor = System::Drawing::Color::LightSteelBlue;
			this->panel_Relay->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel_Relay->Controls->Add(this->label_Relay);
			this->panel_Relay->Location = System::Drawing::Point(2, 275);
			this->panel_Relay->Name = L"panel_Relay";
			this->panel_Relay->Size = System::Drawing::Size(52, 43);
			this->panel_Relay->TabIndex = 3;
			// 
			// panel_Relay_status
			// 
			this->panel_Relay_status->BackColor = System::Drawing::Color::LightSteelBlue;
			this->panel_Relay_status->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel_Relay_status->Controls->Add(this->label_Relay_Status);
			this->panel_Relay_status->Location = System::Drawing::Point(54, 275);
			this->panel_Relay_status->Name = L"panel_Relay_status";
			this->panel_Relay_status->Size = System::Drawing::Size(54, 43);
			this->panel_Relay_status->TabIndex = 4;
			// 
			// label_Relay_Status
			// 
			this->label_Relay_Status->AutoSize = true;
			this->label_Relay_Status->BackColor = System::Drawing::Color::LightSteelBlue;
			this->label_Relay_Status->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_Relay_Status->ForeColor = System::Drawing::Color::Black;
			this->label_Relay_Status->Location = System::Drawing::Point(3, 1);
			this->label_Relay_Status->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_Relay_Status->Name = L"label_Relay_Status";
			this->label_Relay_Status->Size = System::Drawing::Size(51, 38);
			this->label_Relay_Status->TabIndex = 2;
			this->label_Relay_Status->Text = L"Relay\r\nStatus";
			this->label_Relay_Status->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel_Device
			// 
			this->panel_Device->BackColor = System::Drawing::Color::CornflowerBlue;
			this->panel_Device->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel_Device->Controls->Add(this->label_Device_1);
			this->panel_Device->Location = System::Drawing::Point(108, 275);
			this->panel_Device->Name = L"panel_Device";
			this->panel_Device->Size = System::Drawing::Size(64, 43);
			this->panel_Device->TabIndex = 4;
			// 
			// label_Device_1
			// 
			this->label_Device_1->AutoSize = true;
			this->label_Device_1->BackColor = System::Drawing::Color::CornflowerBlue;
			this->label_Device_1->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_Device_1->ForeColor = System::Drawing::Color::White;
			this->label_Device_1->Location = System::Drawing::Point(2, 12);
			this->label_Device_1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_Device_1->Name = L"label_Device_1";
			this->label_Device_1->Size = System::Drawing::Size(55, 19);
			this->label_Device_1->TabIndex = 2;
			this->label_Device_1->Text = L"Device";
			this->label_Device_1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel_Operation
			// 
			this->panel_Operation->BackColor = System::Drawing::Color::CornflowerBlue;
			this->panel_Operation->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel_Operation->Controls->Add(this->label_Operation);
			this->panel_Operation->Location = System::Drawing::Point(172, 275);
			this->panel_Operation->Name = L"panel_Operation";
			this->panel_Operation->Size = System::Drawing::Size(167, 43);
			this->panel_Operation->TabIndex = 5;
			// 
			// label_Operation
			// 
			this->label_Operation->AutoSize = true;
			this->label_Operation->BackColor = System::Drawing::Color::CornflowerBlue;
			this->label_Operation->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_Operation->ForeColor = System::Drawing::Color::White;
			this->label_Operation->Location = System::Drawing::Point(42, 12);
			this->label_Operation->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_Operation->Name = L"label_Operation";
			this->label_Operation->Size = System::Drawing::Size(78, 19);
			this->label_Operation->TabIndex = 2;
			this->label_Operation->Text = L"Operation";
			this->label_Operation->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel_P1R
			// 
			this->panel_P1R->BackColor = System::Drawing::Color::LightSteelBlue;
			this->panel_P1R->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel_P1R->Controls->Add(this->label_P1R);
			this->panel_P1R->Location = System::Drawing::Point(2, 318);
			this->panel_P1R->Name = L"panel_P1R";
			this->panel_P1R->Size = System::Drawing::Size(52, 45);
			this->panel_P1R->TabIndex = 4;
			// 
			// label_P1R
			// 
			this->label_P1R->AutoSize = true;
			this->label_P1R->BackColor = System::Drawing::Color::LightSteelBlue;
			this->label_P1R->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_P1R->ForeColor = System::Drawing::Color::Black;
			this->label_P1R->Location = System::Drawing::Point(5, 12);
			this->label_P1R->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_P1R->Name = L"label_P1R";
			this->label_P1R->Size = System::Drawing::Size(37, 19);
			this->label_P1R->TabIndex = 2;
			this->label_P1R->Text = L"P1R";
			this->label_P1R->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel_P1R_status
			// 
			this->panel_P1R_status->BackColor = System::Drawing::Color::LightSteelBlue;
			this->panel_P1R_status->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel_P1R_status->Controls->Add(this->pictureBox_P1R_status);
			this->panel_P1R_status->Location = System::Drawing::Point(54, 318);
			this->panel_P1R_status->Name = L"panel_P1R_status";
			this->panel_P1R_status->Size = System::Drawing::Size(54, 45);
			this->panel_P1R_status->TabIndex = 5;
			// 
			// pictureBox_P1R_status
			// 
			this->pictureBox_P1R_status->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox_P1R_status.Image")));
			this->pictureBox_P1R_status->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox_P1R_status.InitialImage")));
			this->pictureBox_P1R_status->Location = System::Drawing::Point(14, 10);
			this->pictureBox_P1R_status->Name = L"pictureBox_P1R_status";
			this->pictureBox_P1R_status->Size = System::Drawing::Size(28, 26);
			this->pictureBox_P1R_status->TabIndex = 6;
			this->pictureBox_P1R_status->TabStop = false;
			// 
			// panel_Pump1
			// 
			this->panel_Pump1->BackColor = System::Drawing::Color::CornflowerBlue;
			this->panel_Pump1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel_Pump1->Controls->Add(this->label_Pum1);
			this->panel_Pump1->Location = System::Drawing::Point(108, 318);
			this->panel_Pump1->Name = L"panel_Pump1";
			this->panel_Pump1->Size = System::Drawing::Size(64, 45);
			this->panel_Pump1->TabIndex = 5;
			// 
			// label_Pum1
			// 
			this->label_Pum1->AutoSize = true;
			this->label_Pum1->BackColor = System::Drawing::Color::CornflowerBlue;
			this->label_Pum1->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_Pum1->ForeColor = System::Drawing::Color::White;
			this->label_Pum1->Location = System::Drawing::Point(2, 13);
			this->label_Pum1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_Pum1->Name = L"label_Pum1";
			this->label_Pum1->Size = System::Drawing::Size(58, 19);
			this->label_Pum1->TabIndex = 2;
			this->label_Pum1->Text = L"Pump1";
			this->label_Pum1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel_P1_HiLo
			// 
			this->panel_P1_HiLo->BackColor = System::Drawing::Color::CornflowerBlue;
			this->panel_P1_HiLo->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel_P1_HiLo->Controls->Add(this->button_P1_Lo);
			this->panel_P1_HiLo->Controls->Add(this->button_P1_Hi);
			this->panel_P1_HiLo->Location = System::Drawing::Point(172, 318);
			this->panel_P1_HiLo->Name = L"panel_P1_HiLo";
			this->panel_P1_HiLo->Size = System::Drawing::Size(167, 45);
			this->panel_P1_HiLo->TabIndex = 6;
			// 
			// button_P1_Lo
			// 
			this->button_P1_Lo->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_P1_Lo.Image")));
			this->button_P1_Lo->Location = System::Drawing::Point(84, 7);
			this->button_P1_Lo->Name = L"button_P1_Lo";
			this->button_P1_Lo->Size = System::Drawing::Size(76, 30);
			this->button_P1_Lo->TabIndex = 15;
			this->button_P1_Lo->Text = L"Lo";
			this->button_P1_Lo->UseVisualStyleBackColor = true;
			this->button_P1_Lo->Click += gcnew System::EventHandler(this, &RDS_main_Form::button_P1_Lo_Click);
			// 
			// button_P1_Hi
			// 
			this->button_P1_Hi->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_P1_Hi.Image")));
			this->button_P1_Hi->Location = System::Drawing::Point(5, 7);
			this->button_P1_Hi->Name = L"button_P1_Hi";
			this->button_P1_Hi->Size = System::Drawing::Size(76, 30);
			this->button_P1_Hi->TabIndex = 14;
			this->button_P1_Hi->Text = L"Hi";
			this->button_P1_Hi->UseVisualStyleBackColor = true;
			this->button_P1_Hi->Click += gcnew System::EventHandler(this, &RDS_main_Form::button_P1_Hi_Click);
			// 
			// panel_MCU_status
			// 
			this->panel_MCU_status->BackColor = System::Drawing::Color::CornflowerBlue;
			this->panel_MCU_status->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel_MCU_status->Controls->Add(this->label_MCU_status);
			this->panel_MCU_status->Location = System::Drawing::Point(339, 275);
			this->panel_MCU_status->Name = L"panel_MCU_status";
			this->panel_MCU_status->Size = System::Drawing::Size(64, 43);
			this->panel_MCU_status->TabIndex = 5;
			// 
			// label_MCU_status
			// 
			this->label_MCU_status->AutoSize = true;
			this->label_MCU_status->BackColor = System::Drawing::Color::CornflowerBlue;
			this->label_MCU_status->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_MCU_status->ForeColor = System::Drawing::Color::White;
			this->label_MCU_status->Location = System::Drawing::Point(8, 1);
			this->label_MCU_status->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_MCU_status->Name = L"label_MCU_status";
			this->label_MCU_status->Size = System::Drawing::Size(51, 38);
			this->label_MCU_status->TabIndex = 2;
			this->label_MCU_status->Text = L"MCU\r\nStatus";
			this->label_MCU_status->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel_P1_MCU
			// 
			this->panel_P1_MCU->BackColor = System::Drawing::Color::CornflowerBlue;
			this->panel_P1_MCU->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel_P1_MCU->Controls->Add(this->pictureBox_P1_MCU);
			this->panel_P1_MCU->Location = System::Drawing::Point(339, 318);
			this->panel_P1_MCU->Name = L"panel_P1_MCU";
			this->panel_P1_MCU->Size = System::Drawing::Size(64, 45);
			this->panel_P1_MCU->TabIndex = 7;
			// 
			// pictureBox_P1_MCU
			// 
			this->pictureBox_P1_MCU->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox_P1_MCU.Image")));
			this->pictureBox_P1_MCU->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox_P1_MCU.InitialImage")));
			this->pictureBox_P1_MCU->Location = System::Drawing::Point(18, 10);
			this->pictureBox_P1_MCU->Name = L"pictureBox_P1_MCU";
			this->pictureBox_P1_MCU->Size = System::Drawing::Size(28, 26);
			this->pictureBox_P1_MCU->TabIndex = 6;
			this->pictureBox_P1_MCU->TabStop = false;
			// 
			// panel_Device_Amp
			// 
			this->panel_Device_Amp->BackColor = System::Drawing::Color::CornflowerBlue;
			this->panel_Device_Amp->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel_Device_Amp->Controls->Add(this->label_Device_Amp);
			this->panel_Device_Amp->Location = System::Drawing::Point(403, 275);
			this->panel_Device_Amp->Name = L"panel_Device_Amp";
			this->panel_Device_Amp->Size = System::Drawing::Size(102, 43);
			this->panel_Device_Amp->TabIndex = 6;
			// 
			// label_Device_Amp
			// 
			this->label_Device_Amp->AutoSize = true;
			this->label_Device_Amp->BackColor = System::Drawing::Color::CornflowerBlue;
			this->label_Device_Amp->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_Device_Amp->ForeColor = System::Drawing::Color::White;
			this->label_Device_Amp->Location = System::Drawing::Point(21, 1);
			this->label_Device_Amp->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_Device_Amp->Name = L"label_Device_Amp";
			this->label_Device_Amp->Size = System::Drawing::Size(55, 38);
			this->label_Device_Amp->TabIndex = 2;
			this->label_Device_Amp->Text = L"Device\r\nAmp.";
			this->label_Device_Amp->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel_P1_Amp
			// 
			this->panel_P1_Amp->BackColor = System::Drawing::Color::CornflowerBlue;
			this->panel_P1_Amp->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel_P1_Amp->Controls->Add(this->textBox_P1_Amp);
			this->panel_P1_Amp->Location = System::Drawing::Point(403, 318);
			this->panel_P1_Amp->Name = L"panel_P1_Amp";
			this->panel_P1_Amp->Size = System::Drawing::Size(102, 45);
			this->panel_P1_Amp->TabIndex = 7;
			// 
			// textBox_P1_Amp
			// 
			this->textBox_P1_Amp->BackColor = System::Drawing::Color::PowderBlue;
			this->textBox_P1_Amp->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox_P1_Amp->Font = (gcnew System::Drawing::Font(L"AVGmdBU", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->textBox_P1_Amp->ForeColor = System::Drawing::Color::MediumBlue;
			this->textBox_P1_Amp->Location = System::Drawing::Point(3, 5);
			this->textBox_P1_Amp->Name = L"textBox_P1_Amp";
			this->textBox_P1_Amp->Size = System::Drawing::Size(94, 35);
			this->textBox_P1_Amp->TabIndex = 9;
			this->textBox_P1_Amp->Text = L"00.0";
			this->textBox_P1_Amp->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// panel_P2_Amp
			// 
			this->panel_P2_Amp->BackColor = System::Drawing::Color::CornflowerBlue;
			this->panel_P2_Amp->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel_P2_Amp->Controls->Add(this->textBox_P2_Amp);
			this->panel_P2_Amp->Location = System::Drawing::Point(403, 363);
			this->panel_P2_Amp->Name = L"panel_P2_Amp";
			this->panel_P2_Amp->Size = System::Drawing::Size(102, 45);
			this->panel_P2_Amp->TabIndex = 14;
			// 
			// textBox_P2_Amp
			// 
			this->textBox_P2_Amp->BackColor = System::Drawing::Color::PowderBlue;
			this->textBox_P2_Amp->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox_P2_Amp->Font = (gcnew System::Drawing::Font(L"AVGmdBU", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->textBox_P2_Amp->ForeColor = System::Drawing::Color::MediumBlue;
			this->textBox_P2_Amp->Location = System::Drawing::Point(3, 5);
			this->textBox_P2_Amp->Name = L"textBox_P2_Amp";
			this->textBox_P2_Amp->Size = System::Drawing::Size(94, 35);
			this->textBox_P2_Amp->TabIndex = 9;
			this->textBox_P2_Amp->Text = L"00.0";
			this->textBox_P2_Amp->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// panel_P2_MCU
			// 
			this->panel_P2_MCU->BackColor = System::Drawing::Color::CornflowerBlue;
			this->panel_P2_MCU->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel_P2_MCU->Controls->Add(this->pictureBox_P2_MCU);
			this->panel_P2_MCU->Location = System::Drawing::Point(339, 363);
			this->panel_P2_MCU->Name = L"panel_P2_MCU";
			this->panel_P2_MCU->Size = System::Drawing::Size(64, 45);
			this->panel_P2_MCU->TabIndex = 15;
			// 
			// pictureBox_P2_MCU
			// 
			this->pictureBox_P2_MCU->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox_P2_MCU.Image")));
			this->pictureBox_P2_MCU->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox_P2_MCU.InitialImage")));
			this->pictureBox_P2_MCU->Location = System::Drawing::Point(18, 10);
			this->pictureBox_P2_MCU->Name = L"pictureBox_P2_MCU";
			this->pictureBox_P2_MCU->Size = System::Drawing::Size(28, 26);
			this->pictureBox_P2_MCU->TabIndex = 6;
			this->pictureBox_P2_MCU->TabStop = false;
			// 
			// panel_P2_HiLo
			// 
			this->panel_P2_HiLo->BackColor = System::Drawing::Color::CornflowerBlue;
			this->panel_P2_HiLo->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel_P2_HiLo->Controls->Add(this->button_P2_Lo);
			this->panel_P2_HiLo->Controls->Add(this->button_P2_Hi);
			this->panel_P2_HiLo->Location = System::Drawing::Point(172, 363);
			this->panel_P2_HiLo->Name = L"panel_P2_HiLo";
			this->panel_P2_HiLo->Size = System::Drawing::Size(167, 45);
			this->panel_P2_HiLo->TabIndex = 13;
			// 
			// button_P2_Lo
			// 
			this->button_P2_Lo->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_P2_Lo.Image")));
			this->button_P2_Lo->Location = System::Drawing::Point(84, 7);
			this->button_P2_Lo->Name = L"button_P2_Lo";
			this->button_P2_Lo->Size = System::Drawing::Size(76, 30);
			this->button_P2_Lo->TabIndex = 15;
			this->button_P2_Lo->Text = L"Lo";
			this->button_P2_Lo->UseVisualStyleBackColor = true;
			this->button_P2_Lo->Click += gcnew System::EventHandler(this, &RDS_main_Form::button_P2_Lo_Click);
			// 
			// button_P2_Hi
			// 
			this->button_P2_Hi->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_P2_Hi.Image")));
			this->button_P2_Hi->Location = System::Drawing::Point(5, 7);
			this->button_P2_Hi->Name = L"button_P2_Hi";
			this->button_P2_Hi->Size = System::Drawing::Size(76, 30);
			this->button_P2_Hi->TabIndex = 14;
			this->button_P2_Hi->Text = L"Hi";
			this->button_P2_Hi->UseVisualStyleBackColor = true;
			this->button_P2_Hi->Click += gcnew System::EventHandler(this, &RDS_main_Form::button_P2_Hi_Click);
			// 
			// panel_Pump2
			// 
			this->panel_Pump2->BackColor = System::Drawing::Color::CornflowerBlue;
			this->panel_Pump2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel_Pump2->Controls->Add(this->label_Pump2);
			this->panel_Pump2->Location = System::Drawing::Point(108, 363);
			this->panel_Pump2->Name = L"panel_Pump2";
			this->panel_Pump2->Size = System::Drawing::Size(64, 45);
			this->panel_Pump2->TabIndex = 11;
			// 
			// label_Pump2
			// 
			this->label_Pump2->AutoSize = true;
			this->label_Pump2->BackColor = System::Drawing::Color::CornflowerBlue;
			this->label_Pump2->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_Pump2->ForeColor = System::Drawing::Color::White;
			this->label_Pump2->Location = System::Drawing::Point(2, 13);
			this->label_Pump2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_Pump2->Name = L"label_Pump2";
			this->label_Pump2->Size = System::Drawing::Size(58, 19);
			this->label_Pump2->TabIndex = 2;
			this->label_Pump2->Text = L"Pump2";
			this->label_Pump2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel_P2R_status
			// 
			this->panel_P2R_status->BackColor = System::Drawing::Color::LightSteelBlue;
			this->panel_P2R_status->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel_P2R_status->Controls->Add(this->pictureBox_P2R_status);
			this->panel_P2R_status->Location = System::Drawing::Point(54, 363);
			this->panel_P2R_status->Name = L"panel_P2R_status";
			this->panel_P2R_status->Size = System::Drawing::Size(54, 45);
			this->panel_P2R_status->TabIndex = 12;
			// 
			// pictureBox_P2R_status
			// 
			this->pictureBox_P2R_status->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox_P2R_status.Image")));
			this->pictureBox_P2R_status->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox_P2R_status.InitialImage")));
			this->pictureBox_P2R_status->Location = System::Drawing::Point(14, 10);
			this->pictureBox_P2R_status->Name = L"pictureBox_P2R_status";
			this->pictureBox_P2R_status->Size = System::Drawing::Size(28, 26);
			this->pictureBox_P2R_status->TabIndex = 6;
			this->pictureBox_P2R_status->TabStop = false;
			// 
			// panel_p2R
			// 
			this->panel_p2R->BackColor = System::Drawing::Color::LightSteelBlue;
			this->panel_p2R->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel_p2R->Controls->Add(this->label_P2R);
			this->panel_p2R->Location = System::Drawing::Point(2, 363);
			this->panel_p2R->Name = L"panel_p2R";
			this->panel_p2R->Size = System::Drawing::Size(52, 45);
			this->panel_p2R->TabIndex = 10;
			// 
			// label_P2R
			// 
			this->label_P2R->AutoSize = true;
			this->label_P2R->BackColor = System::Drawing::Color::LightSteelBlue;
			this->label_P2R->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_P2R->ForeColor = System::Drawing::Color::Black;
			this->label_P2R->Location = System::Drawing::Point(5, 12);
			this->label_P2R->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_P2R->Name = L"label_P2R";
			this->label_P2R->Size = System::Drawing::Size(37, 19);
			this->label_P2R->TabIndex = 2;
			this->label_P2R->Text = L"P2R";
			this->label_P2R->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel_P3_Amp
			// 
			this->panel_P3_Amp->BackColor = System::Drawing::Color::CornflowerBlue;
			this->panel_P3_Amp->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel_P3_Amp->Controls->Add(this->textBox_P3_Amp);
			this->panel_P3_Amp->Location = System::Drawing::Point(403, 408);
			this->panel_P3_Amp->Name = L"panel_P3_Amp";
			this->panel_P3_Amp->Size = System::Drawing::Size(102, 45);
			this->panel_P3_Amp->TabIndex = 20;
			// 
			// textBox_P3_Amp
			// 
			this->textBox_P3_Amp->BackColor = System::Drawing::Color::PowderBlue;
			this->textBox_P3_Amp->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox_P3_Amp->Font = (gcnew System::Drawing::Font(L"AVGmdBU", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->textBox_P3_Amp->ForeColor = System::Drawing::Color::MediumBlue;
			this->textBox_P3_Amp->Location = System::Drawing::Point(3, 5);
			this->textBox_P3_Amp->Name = L"textBox_P3_Amp";
			this->textBox_P3_Amp->Size = System::Drawing::Size(94, 35);
			this->textBox_P3_Amp->TabIndex = 9;
			this->textBox_P3_Amp->Text = L"00.0";
			this->textBox_P3_Amp->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// panel_P3_MCU
			// 
			this->panel_P3_MCU->BackColor = System::Drawing::Color::CornflowerBlue;
			this->panel_P3_MCU->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel_P3_MCU->Controls->Add(this->pictureBox_P3_MCU);
			this->panel_P3_MCU->Location = System::Drawing::Point(339, 408);
			this->panel_P3_MCU->Name = L"panel_P3_MCU";
			this->panel_P3_MCU->Size = System::Drawing::Size(64, 45);
			this->panel_P3_MCU->TabIndex = 21;
			// 
			// pictureBox_P3_MCU
			// 
			this->pictureBox_P3_MCU->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox_P3_MCU.Image")));
			this->pictureBox_P3_MCU->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox_P3_MCU.InitialImage")));
			this->pictureBox_P3_MCU->Location = System::Drawing::Point(18, 10);
			this->pictureBox_P3_MCU->Name = L"pictureBox_P3_MCU";
			this->pictureBox_P3_MCU->Size = System::Drawing::Size(28, 26);
			this->pictureBox_P3_MCU->TabIndex = 6;
			this->pictureBox_P3_MCU->TabStop = false;
			// 
			// panel_P3_HiLo
			// 
			this->panel_P3_HiLo->BackColor = System::Drawing::Color::CornflowerBlue;
			this->panel_P3_HiLo->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel_P3_HiLo->Controls->Add(this->button_P3_Lo);
			this->panel_P3_HiLo->Controls->Add(this->button_P3_Hi);
			this->panel_P3_HiLo->Location = System::Drawing::Point(172, 408);
			this->panel_P3_HiLo->Name = L"panel_P3_HiLo";
			this->panel_P3_HiLo->Size = System::Drawing::Size(167, 45);
			this->panel_P3_HiLo->TabIndex = 19;
			// 
			// button_P3_Lo
			// 
			this->button_P3_Lo->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_P3_Lo.Image")));
			this->button_P3_Lo->Location = System::Drawing::Point(84, 7);
			this->button_P3_Lo->Name = L"button_P3_Lo";
			this->button_P3_Lo->Size = System::Drawing::Size(76, 30);
			this->button_P3_Lo->TabIndex = 15;
			this->button_P3_Lo->Text = L"Lo";
			this->button_P3_Lo->UseVisualStyleBackColor = true;
			this->button_P3_Lo->Click += gcnew System::EventHandler(this, &RDS_main_Form::button_P3_Lo_Click);
			// 
			// button_P3_Hi
			// 
			this->button_P3_Hi->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_P3_Hi.Image")));
			this->button_P3_Hi->Location = System::Drawing::Point(5, 7);
			this->button_P3_Hi->Name = L"button_P3_Hi";
			this->button_P3_Hi->Size = System::Drawing::Size(76, 30);
			this->button_P3_Hi->TabIndex = 14;
			this->button_P3_Hi->Text = L"Hi";
			this->button_P3_Hi->UseVisualStyleBackColor = true;
			this->button_P3_Hi->Click += gcnew System::EventHandler(this, &RDS_main_Form::button_P3_Hi_Click);
			// 
			// panel_Pump3
			// 
			this->panel_Pump3->BackColor = System::Drawing::Color::CornflowerBlue;
			this->panel_Pump3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel_Pump3->Controls->Add(this->label_Pum3);
			this->panel_Pump3->Location = System::Drawing::Point(108, 408);
			this->panel_Pump3->Name = L"panel_Pump3";
			this->panel_Pump3->Size = System::Drawing::Size(64, 45);
			this->panel_Pump3->TabIndex = 17;
			// 
			// label_Pum3
			// 
			this->label_Pum3->AutoSize = true;
			this->label_Pum3->BackColor = System::Drawing::Color::CornflowerBlue;
			this->label_Pum3->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_Pum3->ForeColor = System::Drawing::Color::White;
			this->label_Pum3->Location = System::Drawing::Point(2, 13);
			this->label_Pum3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_Pum3->Name = L"label_Pum3";
			this->label_Pum3->Size = System::Drawing::Size(58, 19);
			this->label_Pum3->TabIndex = 2;
			this->label_Pum3->Text = L"Pump3";
			this->label_Pum3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel_P3R_status
			// 
			this->panel_P3R_status->BackColor = System::Drawing::Color::LightSteelBlue;
			this->panel_P3R_status->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel_P3R_status->Controls->Add(this->pictureBox_P3R_status);
			this->panel_P3R_status->Location = System::Drawing::Point(54, 408);
			this->panel_P3R_status->Name = L"panel_P3R_status";
			this->panel_P3R_status->Size = System::Drawing::Size(54, 45);
			this->panel_P3R_status->TabIndex = 18;
			// 
			// pictureBox_P3R_status
			// 
			this->pictureBox_P3R_status->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox_P3R_status.Image")));
			this->pictureBox_P3R_status->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox_P3R_status.InitialImage")));
			this->pictureBox_P3R_status->Location = System::Drawing::Point(14, 10);
			this->pictureBox_P3R_status->Name = L"pictureBox_P3R_status";
			this->pictureBox_P3R_status->Size = System::Drawing::Size(28, 26);
			this->pictureBox_P3R_status->TabIndex = 6;
			this->pictureBox_P3R_status->TabStop = false;
			// 
			// panel_P3R
			// 
			this->panel_P3R->BackColor = System::Drawing::Color::LightSteelBlue;
			this->panel_P3R->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel_P3R->Controls->Add(this->label_P3R);
			this->panel_P3R->Location = System::Drawing::Point(2, 408);
			this->panel_P3R->Name = L"panel_P3R";
			this->panel_P3R->Size = System::Drawing::Size(52, 45);
			this->panel_P3R->TabIndex = 16;
			// 
			// label_P3R
			// 
			this->label_P3R->AutoSize = true;
			this->label_P3R->BackColor = System::Drawing::Color::LightSteelBlue;
			this->label_P3R->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_P3R->ForeColor = System::Drawing::Color::Black;
			this->label_P3R->Location = System::Drawing::Point(5, 12);
			this->label_P3R->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_P3R->Name = L"label_P3R";
			this->label_P3R->Size = System::Drawing::Size(37, 19);
			this->label_P3R->TabIndex = 2;
			this->label_P3R->Text = L"P3R";
			this->label_P3R->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel_Blower_Amp
			// 
			this->panel_Blower_Amp->BackColor = System::Drawing::Color::CornflowerBlue;
			this->panel_Blower_Amp->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel_Blower_Amp->Controls->Add(this->textBox_Blower_Amp);
			this->panel_Blower_Amp->Location = System::Drawing::Point(403, 498);
			this->panel_Blower_Amp->Name = L"panel_Blower_Amp";
			this->panel_Blower_Amp->Size = System::Drawing::Size(102, 45);
			this->panel_Blower_Amp->TabIndex = 26;
			// 
			// textBox_Blower_Amp
			// 
			this->textBox_Blower_Amp->BackColor = System::Drawing::Color::PowderBlue;
			this->textBox_Blower_Amp->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox_Blower_Amp->Font = (gcnew System::Drawing::Font(L"AVGmdBU", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->textBox_Blower_Amp->ForeColor = System::Drawing::Color::MediumBlue;
			this->textBox_Blower_Amp->Location = System::Drawing::Point(3, 5);
			this->textBox_Blower_Amp->Name = L"textBox_Blower_Amp";
			this->textBox_Blower_Amp->Size = System::Drawing::Size(94, 35);
			this->textBox_Blower_Amp->TabIndex = 9;
			this->textBox_Blower_Amp->Text = L"00.0";
			this->textBox_Blower_Amp->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// panel_Blower_MCU
			// 
			this->panel_Blower_MCU->BackColor = System::Drawing::Color::CornflowerBlue;
			this->panel_Blower_MCU->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel_Blower_MCU->Controls->Add(this->pictureBox_Blower_MCU);
			this->panel_Blower_MCU->Location = System::Drawing::Point(339, 498);
			this->panel_Blower_MCU->Name = L"panel_Blower_MCU";
			this->panel_Blower_MCU->Size = System::Drawing::Size(64, 45);
			this->panel_Blower_MCU->TabIndex = 27;
			// 
			// pictureBox_Blower_MCU
			// 
			this->pictureBox_Blower_MCU->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox_Blower_MCU.Image")));
			this->pictureBox_Blower_MCU->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox_Blower_MCU.InitialImage")));
			this->pictureBox_Blower_MCU->Location = System::Drawing::Point(18, 10);
			this->pictureBox_Blower_MCU->Name = L"pictureBox_Blower_MCU";
			this->pictureBox_Blower_MCU->Size = System::Drawing::Size(28, 26);
			this->pictureBox_Blower_MCU->TabIndex = 6;
			this->pictureBox_Blower_MCU->TabStop = false;
			// 
			// panel_Blower_OnOff
			// 
			this->panel_Blower_OnOff->BackColor = System::Drawing::Color::CornflowerBlue;
			this->panel_Blower_OnOff->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel_Blower_OnOff->Controls->Add(this->button_Blower_OnOff);
			this->panel_Blower_OnOff->Location = System::Drawing::Point(172, 498);
			this->panel_Blower_OnOff->Name = L"panel_Blower_OnOff";
			this->panel_Blower_OnOff->Size = System::Drawing::Size(167, 45);
			this->panel_Blower_OnOff->TabIndex = 25;
			// 
			// button_Blower_OnOff
			// 
			this->button_Blower_OnOff->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_Blower_OnOff.Image")));
			this->button_Blower_OnOff->Location = System::Drawing::Point(5, 8);
			this->button_Blower_OnOff->Name = L"button_Blower_OnOff";
			this->button_Blower_OnOff->Size = System::Drawing::Size(155, 30);
			this->button_Blower_OnOff->TabIndex = 14;
			this->button_Blower_OnOff->Text = L"On / Off";
			this->button_Blower_OnOff->UseVisualStyleBackColor = true;
			this->button_Blower_OnOff->Click += gcnew System::EventHandler(this, &RDS_main_Form::button_Blower_OnOff_Click);
			// 
			// panel_Blower
			// 
			this->panel_Blower->BackColor = System::Drawing::Color::CornflowerBlue;
			this->panel_Blower->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel_Blower->Controls->Add(this->label_Blower);
			this->panel_Blower->Location = System::Drawing::Point(108, 498);
			this->panel_Blower->Name = L"panel_Blower";
			this->panel_Blower->Size = System::Drawing::Size(64, 45);
			this->panel_Blower->TabIndex = 23;
			// 
			// label_Blower
			// 
			this->label_Blower->AutoSize = true;
			this->label_Blower->BackColor = System::Drawing::Color::CornflowerBlue;
			this->label_Blower->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_Blower->ForeColor = System::Drawing::Color::White;
			this->label_Blower->Location = System::Drawing::Point(2, 13);
			this->label_Blower->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_Blower->Name = L"label_Blower";
			this->label_Blower->Size = System::Drawing::Size(59, 19);
			this->label_Blower->TabIndex = 2;
			this->label_Blower->Text = L"Blower";
			this->label_Blower->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel_RH_status
			// 
			this->panel_RH_status->BackColor = System::Drawing::Color::MistyRose;
			this->panel_RH_status->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel_RH_status->Controls->Add(this->pictureBox_RH_status);
			this->panel_RH_status->Location = System::Drawing::Point(54, 453);
			this->panel_RH_status->Name = L"panel_RH_status";
			this->panel_RH_status->Size = System::Drawing::Size(54, 45);
			this->panel_RH_status->TabIndex = 24;
			// 
			// pictureBox_RH_status
			// 
			this->pictureBox_RH_status->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox_RH_status.Image")));
			this->pictureBox_RH_status->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox_RH_status.InitialImage")));
			this->pictureBox_RH_status->Location = System::Drawing::Point(14, 10);
			this->pictureBox_RH_status->Name = L"pictureBox_RH_status";
			this->pictureBox_RH_status->Size = System::Drawing::Size(28, 26);
			this->pictureBox_RH_status->TabIndex = 6;
			this->pictureBox_RH_status->TabStop = false;
			// 
			// panel_RH
			// 
			this->panel_RH->BackColor = System::Drawing::Color::LightSteelBlue;
			this->panel_RH->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel_RH->Controls->Add(this->label_RH);
			this->panel_RH->Location = System::Drawing::Point(2, 453);
			this->panel_RH->Name = L"panel_RH";
			this->panel_RH->Size = System::Drawing::Size(52, 45);
			this->panel_RH->TabIndex = 22;
			// 
			// label_RH
			// 
			this->label_RH->AutoSize = true;
			this->label_RH->BackColor = System::Drawing::Color::LightSteelBlue;
			this->label_RH->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_RH->ForeColor = System::Drawing::Color::Black;
			this->label_RH->Location = System::Drawing::Point(8, 12);
			this->label_RH->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_RH->Name = L"label_RH";
			this->label_RH->Size = System::Drawing::Size(30, 19);
			this->label_RH->TabIndex = 2;
			this->label_RH->Text = L"RH";
			this->label_RH->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel_Filter
			// 
			this->panel_Filter->BackColor = System::Drawing::Color::CadetBlue;
			this->panel_Filter->Controls->Add(this->label_Days_1);
			this->panel_Filter->Controls->Add(this->textBox_Filter_Days);
			this->panel_Filter->Controls->Add(this->label_Filter);
			this->panel_Filter->Location = System::Drawing::Point(262, 543);
			this->panel_Filter->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->panel_Filter->Name = L"panel_Filter";
			this->panel_Filter->Size = System::Drawing::Size(124, 45);
			this->panel_Filter->TabIndex = 2;
			// 
			// label_Days_1
			// 
			this->label_Days_1->AutoSize = true;
			this->label_Days_1->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_Days_1->ForeColor = System::Drawing::Color::White;
			this->label_Days_1->Location = System::Drawing::Point(6, 23);
			this->label_Days_1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_Days_1->Name = L"label_Days_1";
			this->label_Days_1->Size = System::Drawing::Size(43, 19);
			this->label_Days_1->TabIndex = 2;
			this->label_Days_1->Text = L"Days";
			// 
			// textBox_Filter_Days
			// 
			this->textBox_Filter_Days->Font = (gcnew System::Drawing::Font(L"AVGmdBU", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->textBox_Filter_Days->Location = System::Drawing::Point(54, 5);
			this->textBox_Filter_Days->Name = L"textBox_Filter_Days";
			this->textBox_Filter_Days->Size = System::Drawing::Size(55, 32);
			this->textBox_Filter_Days->TabIndex = 1;
			this->textBox_Filter_Days->Text = L"300";
			this->textBox_Filter_Days->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox_Filter_Days->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &RDS_main_Form::textBox_Filter_Days_MouseClick);
			// 
			// label_Filter
			// 
			this->label_Filter->AutoSize = true;
			this->label_Filter->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_Filter->ForeColor = System::Drawing::Color::White;
			this->label_Filter->Location = System::Drawing::Point(6, 5);
			this->label_Filter->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_Filter->Name = L"label_Filter";
			this->label_Filter->Size = System::Drawing::Size(46, 19);
			this->label_Filter->TabIndex = 0;
			this->label_Filter->Text = L"Filter";
			// 
			// panel_UV
			// 
			this->panel_UV->BackColor = System::Drawing::Color::CadetBlue;
			this->panel_UV->Controls->Add(this->label_Days_2);
			this->panel_UV->Controls->Add(this->textBox_UV_Days);
			this->panel_UV->Controls->Add(this->label_UV);
			this->panel_UV->Location = System::Drawing::Point(386, 543);
			this->panel_UV->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->panel_UV->Name = L"panel_UV";
			this->panel_UV->Size = System::Drawing::Size(119, 45);
			this->panel_UV->TabIndex = 3;
			// 
			// label_Days_2
			// 
			this->label_Days_2->AutoSize = true;
			this->label_Days_2->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_Days_2->ForeColor = System::Drawing::Color::White;
			this->label_Days_2->Location = System::Drawing::Point(8, 24);
			this->label_Days_2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_Days_2->Name = L"label_Days_2";
			this->label_Days_2->Size = System::Drawing::Size(43, 19);
			this->label_Days_2->TabIndex = 2;
			this->label_Days_2->Text = L"Days";
			// 
			// textBox_UV_Days
			// 
			this->textBox_UV_Days->Font = (gcnew System::Drawing::Font(L"AVGmdBU", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox_UV_Days->Location = System::Drawing::Point(52, 5);
			this->textBox_UV_Days->Name = L"textBox_UV_Days";
			this->textBox_UV_Days->Size = System::Drawing::Size(55, 32);
			this->textBox_UV_Days->TabIndex = 1;
			this->textBox_UV_Days->Text = L"300";
			this->textBox_UV_Days->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox_UV_Days->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &RDS_main_Form::textBox_UV_Days_MouseClick);
			// 
			// label_UV
			// 
			this->label_UV->AutoSize = true;
			this->label_UV->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_UV->ForeColor = System::Drawing::Color::White;
			this->label_UV->Location = System::Drawing::Point(14, 3);
			this->label_UV->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_UV->Name = L"label_UV";
			this->label_UV->Size = System::Drawing::Size(29, 19);
			this->label_UV->TabIndex = 0;
			this->label_UV->Text = L"UV";
			// 
			// button_SF
			// 
			this->button_SF->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_SF.Image")));
			this->button_SF->Location = System::Drawing::Point(83, 6);
			this->button_SF->Name = L"button_SF";
			this->button_SF->Size = System::Drawing::Size(64, 34);
			this->button_SF->TabIndex = 14;
			this->button_SF->Text = L"SF";
			this->button_SF->UseVisualStyleBackColor = true;
			this->button_SF->Click += gcnew System::EventHandler(this, &RDS_main_Form::button_SF_Click);
			// 
			// button_PF
			// 
			this->button_PF->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_PF.Image")));
			this->button_PF->Location = System::Drawing::Point(6, 6);
			this->button_PF->Name = L"button_PF";
			this->button_PF->Size = System::Drawing::Size(64, 34);
			this->button_PF->TabIndex = 12;
			this->button_PF->Text = L"PF";
			this->button_PF->UseVisualStyleBackColor = true;
			this->button_PF->Click += gcnew System::EventHandler(this, &RDS_main_Form::button_PF_Click);
			// 
			// button_Date_Time
			// 
			this->button_Date_Time->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_Date_Time.Image")));
			this->button_Date_Time->Location = System::Drawing::Point(27, 5);
			this->button_Date_Time->Name = L"button_Date_Time";
			this->button_Date_Time->Size = System::Drawing::Size(112, 33);
			this->button_Date_Time->TabIndex = 13;
			this->button_Date_Time->Text = L"Date/Time";
			this->button_Date_Time->UseVisualStyleBackColor = true;
			this->button_Date_Time->Click += gcnew System::EventHandler(this, &RDS_main_Form::button_Date_Time_Click);
			// 
			// button_Filtration_sch
			// 
			this->button_Filtration_sch->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_Filtration_sch.Image")));
			this->button_Filtration_sch->Location = System::Drawing::Point(2, 6);
			this->button_Filtration_sch->Name = L"button_Filtration_sch";
			this->button_Filtration_sch->Size = System::Drawing::Size(147, 35);
			this->button_Filtration_sch->TabIndex = 12;
			this->button_Filtration_sch->Text = L"Filtration Schedule";
			this->button_Filtration_sch->UseVisualStyleBackColor = true;
			this->button_Filtration_sch->Click += gcnew System::EventHandler(this, &RDS_main_Form::button_Filtration_sch_Click);
			// 
			// button_mode
			// 
			this->button_mode->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_mode.Image")));
			this->button_mode->Location = System::Drawing::Point(8, 50);
			this->button_mode->Name = L"button_mode";
			this->button_mode->Size = System::Drawing::Size(87, 34);
			this->button_mode->TabIndex = 11;
			this->button_mode->Text = L"Mode";
			this->button_mode->UseVisualStyleBackColor = true;
			this->button_mode->Click += gcnew System::EventHandler(this, &RDS_main_Form::button_mode_Click);
			// 
			// pictureBox_ECO
			// 
			this->pictureBox_ECO->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox_ECO.Image")));
			this->pictureBox_ECO->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox_ECO.InitialImage")));
			this->pictureBox_ECO->Location = System::Drawing::Point(65, 13);
			this->pictureBox_ECO->Name = L"pictureBox_ECO";
			this->pictureBox_ECO->Size = System::Drawing::Size(28, 26);
			this->pictureBox_ECO->TabIndex = 10;
			this->pictureBox_ECO->TabStop = false;
			// 
			// label_ECO_mode
			// 
			this->label_ECO_mode->AutoSize = true;
			this->label_ECO_mode->BackColor = System::Drawing::Color::SteelBlue;
			this->label_ECO_mode->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_ECO_mode->ForeColor = System::Drawing::Color::White;
			this->label_ECO_mode->Location = System::Drawing::Point(10, 4);
			this->label_ECO_mode->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_ECO_mode->Name = L"label_ECO_mode";
			this->label_ECO_mode->Size = System::Drawing::Size(48, 38);
			this->label_ECO_mode->TabIndex = 9;
			this->label_ECO_mode->Text = L"ECO\r\nMode\r\n";
			this->label_ECO_mode->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel_ECO_mode
			// 
			this->panel_ECO_mode->BackColor = System::Drawing::Color::SteelBlue;
			this->panel_ECO_mode->Controls->Add(this->label_ECO_mode);
			this->panel_ECO_mode->Controls->Add(this->pictureBox_ECO);
			this->panel_ECO_mode->Controls->Add(this->button_mode);
			this->panel_ECO_mode->Location = System::Drawing::Point(2, 498);
			this->panel_ECO_mode->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->panel_ECO_mode->Name = L"panel_ECO_mode";
			this->panel_ECO_mode->Size = System::Drawing::Size(106, 90);
			this->panel_ECO_mode->TabIndex = 4;
			// 
			// panel_control
			// 
			this->panel_control->BackColor = System::Drawing::Color::LightGray;
			this->panel_control->Controls->Add(this->button_OSC_list);
			this->panel_control->Controls->Add(this->richTextBox_comment);
			this->panel_control->Controls->Add(this->button_History);
			this->panel_control->Controls->Add(this->button_Service_Call);
			this->panel_control->Controls->Add(this->button_RDS_report);
			this->panel_control->Location = System::Drawing::Point(2, 588);
			this->panel_control->Name = L"panel_control";
			this->panel_control->Size = System::Drawing::Size(503, 100);
			this->panel_control->TabIndex = 29;
			// 
			// button_OSC_list
			// 
			this->button_OSC_list->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_OSC_list.Image")));
			this->button_OSC_list->Location = System::Drawing::Point(380, 64);
			this->button_OSC_list->Name = L"button_OSC_list";
			this->button_OSC_list->Size = System::Drawing::Size(116, 32);
			this->button_OSC_list->TabIndex = 57;
			this->button_OSC_list->Text = L"My S.C. List";
			this->button_OSC_list->UseVisualStyleBackColor = true;
			this->button_OSC_list->Click += gcnew System::EventHandler(this, &RDS_main_Form::button_OSC_list_Click);
			// 
			// richTextBox_comment
			// 
			this->richTextBox_comment->Location = System::Drawing::Point(3, 5);
			this->richTextBox_comment->Name = L"richTextBox_comment";
			this->richTextBox_comment->Size = System::Drawing::Size(496, 56);
			this->richTextBox_comment->TabIndex = 56;
			this->richTextBox_comment->Text = L"";
			// 
			// button_History
			// 
			this->button_History->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_History.Image")));
			this->button_History->Location = System::Drawing::Point(258, 64);
			this->button_History->Name = L"button_History";
			this->button_History->Size = System::Drawing::Size(116, 32);
			this->button_History->TabIndex = 17;
			this->button_History->Text = L"History";
			this->button_History->UseVisualStyleBackColor = true;
			this->button_History->Click += gcnew System::EventHandler(this, &RDS_main_Form::button_History_Click);
			// 
			// button_Service_Call
			// 
			this->button_Service_Call->Location = System::Drawing::Point(135, 64);
			this->button_Service_Call->Name = L"button_Service_Call";
			this->button_Service_Call->Size = System::Drawing::Size(118, 32);
			this->button_Service_Call->TabIndex = 16;
			this->button_Service_Call->Text = L"Service Call";
			this->button_Service_Call->UseVisualStyleBackColor = true;
			this->button_Service_Call->Click += gcnew System::EventHandler(this, &RDS_main_Form::button_Service_Call_Click);
			// 
			// button_RDS_report
			// 
			this->button_RDS_report->Location = System::Drawing::Point(7, 64);
			this->button_RDS_report->Name = L"button_RDS_report";
			this->button_RDS_report->Size = System::Drawing::Size(122, 32);
			this->button_RDS_report->TabIndex = 14;
			this->button_RDS_report->Text = L"RDS Report";
			this->button_RDS_report->UseVisualStyleBackColor = true;
			this->button_RDS_report->Click += gcnew System::EventHandler(this, &RDS_main_Form::button_RDS_report_Click);
			// 
			// richTextBox_EngMsg
			// 
			this->richTextBox_EngMsg->BackColor = System::Drawing::Color::LightGray;
			this->richTextBox_EngMsg->Font = (gcnew System::Drawing::Font(L"Cambria", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->richTextBox_EngMsg->Location = System::Drawing::Point(330, 3);
			this->richTextBox_EngMsg->Name = L"richTextBox_EngMsg";
			this->richTextBox_EngMsg->Size = System::Drawing::Size(654, 87);
			this->richTextBox_EngMsg->TabIndex = 31;
			this->richTextBox_EngMsg->Text = L"";
			// 
			// panel_EngArea
			// 
			this->panel_EngArea->AutoSize = true;
			this->panel_EngArea->BackColor = System::Drawing::Color::LightGray;
			this->panel_EngArea->Controls->Add(this->lb_wait_NBcmd);
			this->panel_EngArea->Controls->Add(this->lb_wait_cmd);
			this->panel_EngArea->Controls->Add(this->lb_wait_pkt);
			this->panel_EngArea->Controls->Add(this->lbl_EH_pageCnt);
			this->panel_EngArea->Controls->Add(this->lbl_EH_S_page);
			this->panel_EngArea->Controls->Add(this->lbl_EH_Total_page);
			this->panel_EngArea->Controls->Add(this->lbl_EH_page);
			this->panel_EngArea->Controls->Add(this->richTextBox_ActLog);
			this->panel_EngArea->Controls->Add(this->button_blue);
			this->panel_EngArea->Controls->Add(this->button_red);
			this->panel_EngArea->Controls->Add(this->button_yellow);
			this->panel_EngArea->Controls->Add(this->button_green);
			this->panel_EngArea->Controls->Add(this->lbl_writePktCount);
			this->panel_EngArea->Controls->Add(this->lbl_writeTimeout);
			this->panel_EngArea->Controls->Add(this->lbl_WLv);
			this->panel_EngArea->Controls->Add(this->lbl_HTstate);
			this->panel_EngArea->Controls->Add(this->lbl_WTstate);
			this->panel_EngArea->Controls->Add(this->lbl_validCMDcode);
			this->panel_EngArea->Controls->Add(this->lbl_NAT_type);
			this->panel_EngArea->Controls->Add(this->lbl_remotePort);
			this->panel_EngArea->Controls->Add(this->lbl_remoteIP);
			this->panel_EngArea->Controls->Add(this->lbl_sCorD);
			this->panel_EngArea->Controls->Add(this->lbl_sMode);
			this->panel_EngArea->Controls->Add(this->lbl_PktTimeOut);
			this->panel_EngArea->Controls->Add(this->label_pktTimeOut);
			this->panel_EngArea->Controls->Add(this->button_update);
			this->panel_EngArea->Controls->Add(this->lbl_pktRate);
			this->panel_EngArea->Controls->Add(this->label_pktRate);
			this->panel_EngArea->Controls->Add(this->lbl_PktLoss);
			this->panel_EngArea->Controls->Add(this->label_pktLoss);
			this->panel_EngArea->Controls->Add(this->lbl_PSN);
			this->panel_EngArea->Controls->Add(this->label_packetSN);
			this->panel_EngArea->Controls->Add(this->richTextBox_EngMsg);
			this->panel_EngArea->Location = System::Drawing::Point(2, 690);
			this->panel_EngArea->Name = L"panel_EngArea";
			this->panel_EngArea->Size = System::Drawing::Size(987, 137);
			this->panel_EngArea->TabIndex = 32;
			this->panel_EngArea->Visible = false;
			// 
			// lbl_EH_pageCnt
			// 
			this->lbl_EH_pageCnt->AutoSize = true;
			this->lbl_EH_pageCnt->Font = (gcnew System::Drawing::Font(L"Cambria", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_EH_pageCnt->ForeColor = System::Drawing::Color::DarkGreen;
			this->lbl_EH_pageCnt->Location = System::Drawing::Point(247, 51);
			this->lbl_EH_pageCnt->Name = L"lbl_EH_pageCnt";
			this->lbl_EH_pageCnt->Size = System::Drawing::Size(65, 15);
			this->lbl_EH_pageCnt->TabIndex = 58;
			this->lbl_EH_pageCnt->Text = L"EH pCount";
			// 
			// lbl_EH_S_page
			// 
			this->lbl_EH_S_page->AutoSize = true;
			this->lbl_EH_S_page->Font = (gcnew System::Drawing::Font(L"Cambria", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_EH_S_page->ForeColor = System::Drawing::Color::DarkGreen;
			this->lbl_EH_S_page->Location = System::Drawing::Point(247, 35);
			this->lbl_EH_S_page->Name = L"lbl_EH_S_page";
			this->lbl_EH_S_page->Size = System::Drawing::Size(63, 15);
			this->lbl_EH_S_page->TabIndex = 57;
			this->lbl_EH_S_page->Text = L"EH S. page";
			// 
			// lbl_EH_Total_page
			// 
			this->lbl_EH_Total_page->AutoSize = true;
			this->lbl_EH_Total_page->Font = (gcnew System::Drawing::Font(L"Cambria", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_EH_Total_page->ForeColor = System::Drawing::Color::DarkGreen;
			this->lbl_EH_Total_page->Location = System::Drawing::Point(247, 20);
			this->lbl_EH_Total_page->Name = L"lbl_EH_Total_page";
			this->lbl_EH_Total_page->Size = System::Drawing::Size(70, 15);
			this->lbl_EH_Total_page->TabIndex = 56;
			this->lbl_EH_Total_page->Text = L"EH T. pages";
			// 
			// lbl_EH_page
			// 
			this->lbl_EH_page->AutoSize = true;
			this->lbl_EH_page->Font = (gcnew System::Drawing::Font(L"Cambria", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_EH_page->ForeColor = System::Drawing::Color::DarkGreen;
			this->lbl_EH_page->Location = System::Drawing::Point(248, 3);
			this->lbl_EH_page->Name = L"lbl_EH_page";
			this->lbl_EH_page->Size = System::Drawing::Size(59, 15);
			this->lbl_EH_page->TabIndex = 55;
			this->lbl_EH_page->Text = L"EH_pages";
			// 
			// richTextBox_ActLog
			// 
			this->richTextBox_ActLog->BackColor = System::Drawing::Color::LightGray;
			this->richTextBox_ActLog->Font = (gcnew System::Drawing::Font(L"Cambria", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->richTextBox_ActLog->Location = System::Drawing::Point(330, 87);
			this->richTextBox_ActLog->Name = L"richTextBox_ActLog";
			this->richTextBox_ActLog->Size = System::Drawing::Size(654, 47);
			this->richTextBox_ActLog->TabIndex = 55;
			this->richTextBox_ActLog->Text = L"";
			// 
			// button_blue
			// 
			this->button_blue->BackColor = System::Drawing::Color::DeepSkyBlue;
			this->button_blue->Location = System::Drawing::Point(4, 63);
			this->button_blue->Name = L"button_blue";
			this->button_blue->Size = System::Drawing::Size(15, 18);
			this->button_blue->TabIndex = 54;
			this->button_blue->UseVisualStyleBackColor = false;
			this->button_blue->Click += gcnew System::EventHandler(this, &RDS_main_Form::button_blue_Click);
			// 
			// button_red
			// 
			this->button_red->BackColor = System::Drawing::Color::Red;
			this->button_red->Location = System::Drawing::Point(4, 44);
			this->button_red->Name = L"button_red";
			this->button_red->Size = System::Drawing::Size(15, 18);
			this->button_red->TabIndex = 53;
			this->button_red->UseVisualStyleBackColor = false;
			this->button_red->Click += gcnew System::EventHandler(this, &RDS_main_Form::button_red_Click);
			// 
			// button_yellow
			// 
			this->button_yellow->BackColor = System::Drawing::Color::Gold;
			this->button_yellow->Location = System::Drawing::Point(4, 23);
			this->button_yellow->Name = L"button_yellow";
			this->button_yellow->Size = System::Drawing::Size(15, 18);
			this->button_yellow->TabIndex = 52;
			this->button_yellow->UseVisualStyleBackColor = false;
			this->button_yellow->Click += gcnew System::EventHandler(this, &RDS_main_Form::button_yellow_Click);
			// 
			// button_green
			// 
			this->button_green->BackColor = System::Drawing::Color::OliveDrab;
			this->button_green->Location = System::Drawing::Point(4, 3);
			this->button_green->Name = L"button_green";
			this->button_green->Size = System::Drawing::Size(15, 18);
			this->button_green->TabIndex = 51;
			this->button_green->UseVisualStyleBackColor = false;
			this->button_green->Click += gcnew System::EventHandler(this, &RDS_main_Form::button_green_Click);
			// 
			// lbl_writePktCount
			// 
			this->lbl_writePktCount->AutoSize = true;
			this->lbl_writePktCount->Font = (gcnew System::Drawing::Font(L"Cambria", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_writePktCount->Location = System::Drawing::Point(247, 81);
			this->lbl_writePktCount->Name = L"lbl_writePktCount";
			this->lbl_writePktCount->Size = System::Drawing::Size(42, 15);
			this->lbl_writePktCount->TabIndex = 50;
			this->lbl_writePktCount->Text = L"wPkt=";
			// 
			// lbl_writeTimeout
			// 
			this->lbl_writeTimeout->AutoSize = true;
			this->lbl_writeTimeout->Font = (gcnew System::Drawing::Font(L"Cambria", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_writeTimeout->Location = System::Drawing::Point(247, 66);
			this->lbl_writeTimeout->Name = L"lbl_writeTimeout";
			this->lbl_writeTimeout->Size = System::Drawing::Size(41, 15);
			this->lbl_writeTimeout->TabIndex = 49;
			this->lbl_writeTimeout->Text = L"wTO=";
			// 
			// lbl_WLv
			// 
			this->lbl_WLv->AutoSize = true;
			this->lbl_WLv->Font = (gcnew System::Drawing::Font(L"Cambria", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_WLv->ForeColor = System::Drawing::Color::Blue;
			this->lbl_WLv->Location = System::Drawing::Point(20, 81);
			this->lbl_WLv->Name = L"lbl_WLv";
			this->lbl_WLv->Size = System::Drawing::Size(39, 15);
			this->lbl_WLv->TabIndex = 48;
			this->lbl_WLv->Text = L"WLv=";
			// 
			// lbl_HTstate
			// 
			this->lbl_HTstate->AutoSize = true;
			this->lbl_HTstate->Font = (gcnew System::Drawing::Font(L"Cambria", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_HTstate->ForeColor = System::Drawing::Color::Blue;
			this->lbl_HTstate->Location = System::Drawing::Point(20, 111);
			this->lbl_HTstate->Name = L"lbl_HTstate";
			this->lbl_HTstate->Size = System::Drawing::Size(40, 15);
			this->lbl_HTstate->TabIndex = 47;
			this->lbl_HTstate->Text = L"HTst=";
			// 
			// lbl_WTstate
			// 
			this->lbl_WTstate->AutoSize = true;
			this->lbl_WTstate->Font = (gcnew System::Drawing::Font(L"Cambria", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_WTstate->ForeColor = System::Drawing::Color::Blue;
			this->lbl_WTstate->Location = System::Drawing::Point(18, 96);
			this->lbl_WTstate->Name = L"lbl_WTstate";
			this->lbl_WTstate->Size = System::Drawing::Size(43, 15);
			this->lbl_WTstate->TabIndex = 46;
			this->lbl_WTstate->Text = L"WTst=";
			// 
			// lbl_validCMDcode
			// 
			this->lbl_validCMDcode->AutoSize = true;
			this->lbl_validCMDcode->Font = (gcnew System::Drawing::Font(L"Cambria", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_validCMDcode->ForeColor = System::Drawing::Color::Blue;
			this->lbl_validCMDcode->Location = System::Drawing::Point(18, 66);
			this->lbl_validCMDcode->Name = L"lbl_validCMDcode";
			this->lbl_validCMDcode->Size = System::Drawing::Size(41, 15);
			this->lbl_validCMDcode->TabIndex = 45;
			this->lbl_validCMDcode->Text = L"CMD=";
			// 
			// lbl_NAT_type
			// 
			this->lbl_NAT_type->AutoSize = true;
			this->lbl_NAT_type->Font = (gcnew System::Drawing::Font(L"Cambria", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_NAT_type->Location = System::Drawing::Point(120, 51);
			this->lbl_NAT_type->Name = L"lbl_NAT_type";
			this->lbl_NAT_type->Size = System::Drawing::Size(52, 15);
			this->lbl_NAT_type->TabIndex = 44;
			this->lbl_NAT_type->Text = L"nat-type";
			// 
			// lbl_remotePort
			// 
			this->lbl_remotePort->AutoSize = true;
			this->lbl_remotePort->Font = (gcnew System::Drawing::Font(L"Cambria", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_remotePort->Location = System::Drawing::Point(121, 35);
			this->lbl_remotePort->Name = L"lbl_remotePort";
			this->lbl_remotePort->Size = System::Drawing::Size(40, 15);
			this->lbl_remotePort->TabIndex = 43;
			this->lbl_remotePort->Text = L"r_port";
			// 
			// lbl_remoteIP
			// 
			this->lbl_remoteIP->AutoSize = true;
			this->lbl_remoteIP->Font = (gcnew System::Drawing::Font(L"Cambria", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_remoteIP->Location = System::Drawing::Point(121, 20);
			this->lbl_remoteIP->Name = L"lbl_remoteIP";
			this->lbl_remoteIP->Size = System::Drawing::Size(88, 15);
			this->lbl_remoteIP->TabIndex = 42;
			this->lbl_remoteIP->Text = L"IP1.IP2.IP3.IP4";
			// 
			// lbl_sCorD
			// 
			this->lbl_sCorD->AutoSize = true;
			this->lbl_sCorD->Font = (gcnew System::Drawing::Font(L"Cambria", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_sCorD->Location = System::Drawing::Point(121, 66);
			this->lbl_sCorD->Name = L"lbl_sCorD";
			this->lbl_sCorD->Size = System::Drawing::Size(41, 15);
			this->lbl_sCorD->TabIndex = 41;
			this->lbl_sCorD->Text = L"CoreD";
			// 
			// lbl_sMode
			// 
			this->lbl_sMode->AutoSize = true;
			this->lbl_sMode->Font = (gcnew System::Drawing::Font(L"Cambria", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_sMode->Location = System::Drawing::Point(120, 5);
			this->lbl_sMode->Name = L"lbl_sMode";
			this->lbl_sMode->Size = System::Drawing::Size(38, 15);
			this->lbl_sMode->TabIndex = 40;
			this->lbl_sMode->Text = L"Mode";
			// 
			// lbl_PktTimeOut
			// 
			this->lbl_PktTimeOut->AutoSize = true;
			this->lbl_PktTimeOut->Font = (gcnew System::Drawing::Font(L"Cambria", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_PktTimeOut->Location = System::Drawing::Point(65, 35);
			this->lbl_PktTimeOut->Name = L"lbl_PktTimeOut";
			this->lbl_PktTimeOut->Size = System::Drawing::Size(14, 15);
			this->lbl_PktTimeOut->TabIndex = 39;
			this->lbl_PktTimeOut->Text = L"0";
			// 
			// label_pktTimeOut
			// 
			this->label_pktTimeOut->AutoSize = true;
			this->label_pktTimeOut->Font = (gcnew System::Drawing::Font(L"Cambria", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_pktTimeOut->Location = System::Drawing::Point(18, 35);
			this->label_pktTimeOut->Name = L"label_pktTimeOut";
			this->label_pktTimeOut->Size = System::Drawing::Size(42, 15);
			this->label_pktTimeOut->TabIndex = 38;
			this->label_pktTimeOut->Text = L"P-T.O=";
			this->label_pktTimeOut->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// button_update
			// 
			this->button_update->Location = System::Drawing::Point(4, 87);
			this->button_update->Name = L"button_update";
			this->button_update->Size = System::Drawing::Size(15, 39);
			this->button_update->TabIndex = 12;
			this->button_update->Text = L".";
			this->button_update->UseVisualStyleBackColor = true;
			this->button_update->Click += gcnew System::EventHandler(this, &RDS_main_Form::button_update_Click);
			// 
			// lbl_pktRate
			// 
			this->lbl_pktRate->AutoSize = true;
			this->lbl_pktRate->Font = (gcnew System::Drawing::Font(L"Cambria", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_pktRate->Location = System::Drawing::Point(65, 50);
			this->lbl_pktRate->Name = L"lbl_pktRate";
			this->lbl_pktRate->Size = System::Drawing::Size(49, 15);
			this->lbl_pktRate->TabIndex = 37;
			this->lbl_pktRate->Text = L"000000";
			// 
			// label_pktRate
			// 
			this->label_pktRate->AutoSize = true;
			this->label_pktRate->Font = (gcnew System::Drawing::Font(L"Cambria", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_pktRate->Location = System::Drawing::Point(18, 50);
			this->label_pktRate->Name = L"label_pktRate";
			this->label_pktRate->Size = System::Drawing::Size(48, 15);
			this->label_pktRate->TabIndex = 36;
			this->label_pktRate->Text = L"P-Rate=";
			this->label_pktRate->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// lbl_PktLoss
			// 
			this->lbl_PktLoss->AutoSize = true;
			this->lbl_PktLoss->Font = (gcnew System::Drawing::Font(L"Cambria", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_PktLoss->Location = System::Drawing::Point(65, 20);
			this->lbl_PktLoss->Name = L"lbl_PktLoss";
			this->lbl_PktLoss->Size = System::Drawing::Size(14, 15);
			this->lbl_PktLoss->TabIndex = 35;
			this->lbl_PktLoss->Text = L"0";
			// 
			// label_pktLoss
			// 
			this->label_pktLoss->AutoSize = true;
			this->label_pktLoss->Font = (gcnew System::Drawing::Font(L"Cambria", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_pktLoss->Location = System::Drawing::Point(18, 20);
			this->label_pktLoss->Name = L"label_pktLoss";
			this->label_pktLoss->Size = System::Drawing::Size(50, 15);
			this->label_pktLoss->TabIndex = 34;
			this->label_pktLoss->Text = L"P-Loss=";
			this->label_pktLoss->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// lbl_PSN
			// 
			this->lbl_PSN->AutoSize = true;
			this->lbl_PSN->Font = (gcnew System::Drawing::Font(L"Cambria", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_PSN->Location = System::Drawing::Point(65, 5);
			this->lbl_PSN->Name = L"lbl_PSN";
			this->lbl_PSN->Size = System::Drawing::Size(49, 15);
			this->lbl_PSN->TabIndex = 33;
			this->lbl_PSN->Text = L"000000";
			// 
			// label_packetSN
			// 
			this->label_packetSN->AutoSize = true;
			this->label_packetSN->Font = (gcnew System::Drawing::Font(L"Cambria", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_packetSN->Location = System::Drawing::Point(19, 5);
			this->label_packetSN->Name = L"label_packetSN";
			this->label_packetSN->Size = System::Drawing::Size(35, 15);
			this->label_packetSN->TabIndex = 32;
			this->label_packetSN->Text = L"P-SN:";
			this->label_packetSN->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label_tube_model
			// 
			this->label_tube_model->AutoSize = true;
			this->label_tube_model->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_tube_model->ForeColor = System::Drawing::Color::White;
			this->label_tube_model->Location = System::Drawing::Point(24, 5);
			this->label_tube_model->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_tube_model->Name = L"label_tube_model";
			this->label_tube_model->Size = System::Drawing::Size(156, 19);
			this->label_tube_model->TabIndex = 0;
			this->label_tube_model->Text = L"Hot Tub Model Name";
			this->label_tube_model->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// panel_model
			// 
			this->panel_model->AutoSize = true;
			this->panel_model->BackColor = System::Drawing::Color::SteelBlue;
			this->panel_model->Controls->Add(this->comboBox_Model_Name);
			this->panel_model->Controls->Add(this->label_tube_model);
			this->panel_model->Location = System::Drawing::Point(263, 1);
			this->panel_model->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->panel_model->Name = L"panel_model";
			this->panel_model->Size = System::Drawing::Size(196, 61);
			this->panel_model->TabIndex = 4;
			// 
			// comboBox_Model_Name
			// 
			this->comboBox_Model_Name->BackColor = System::Drawing::Color::LightBlue;
			this->comboBox_Model_Name->FormattingEnabled = true;
			this->comboBox_Model_Name->Items->AddRange(gcnew cli::array< System::Object^  >(1) { L"Spa-1" });
			this->comboBox_Model_Name->Location = System::Drawing::Point(19, 27);
			this->comboBox_Model_Name->Name = L"comboBox_Model_Name";
			this->comboBox_Model_Name->Size = System::Drawing::Size(157, 27);
			this->comboBox_Model_Name->TabIndex = 58;
			// 
			// panel_FilterSch
			// 
			this->panel_FilterSch->BackColor = System::Drawing::Color::SteelBlue;
			this->panel_FilterSch->Controls->Add(this->button_SF);
			this->panel_FilterSch->Controls->Add(this->button_PF);
			this->panel_FilterSch->Controls->Add(this->button_Filtration_sch);
			this->panel_FilterSch->Location = System::Drawing::Point(108, 543);
			this->panel_FilterSch->Name = L"panel_FilterSch";
			this->panel_FilterSch->Size = System::Drawing::Size(154, 45);
			this->panel_FilterSch->TabIndex = 60;
			// 
			// panel_DateTime
			// 
			this->panel_DateTime->BackColor = System::Drawing::Color::SteelBlue;
			this->panel_DateTime->Controls->Add(this->button_Date_Time);
			this->panel_DateTime->Location = System::Drawing::Point(817, 149);
			this->panel_DateTime->Name = L"panel_DateTime";
			this->panel_DateTime->Size = System::Drawing::Size(169, 45);
			this->panel_DateTime->TabIndex = 61;
			// 
			// panel_heater_Amp
			// 
			this->panel_heater_Amp->BackColor = System::Drawing::Color::CornflowerBlue;
			this->panel_heater_Amp->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel_heater_Amp->Controls->Add(this->textBox_Heater_Amp);
			this->panel_heater_Amp->Location = System::Drawing::Point(403, 453);
			this->panel_heater_Amp->Name = L"panel_heater_Amp";
			this->panel_heater_Amp->Size = System::Drawing::Size(102, 45);
			this->panel_heater_Amp->TabIndex = 62;
			// 
			// textBox_Heater_Amp
			// 
			this->textBox_Heater_Amp->BackColor = System::Drawing::Color::PowderBlue;
			this->textBox_Heater_Amp->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox_Heater_Amp->Font = (gcnew System::Drawing::Font(L"AVGmdBU", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->textBox_Heater_Amp->ForeColor = System::Drawing::Color::MediumBlue;
			this->textBox_Heater_Amp->Location = System::Drawing::Point(4, 4);
			this->textBox_Heater_Amp->Name = L"textBox_Heater_Amp";
			this->textBox_Heater_Amp->Size = System::Drawing::Size(94, 35);
			this->textBox_Heater_Amp->TabIndex = 10;
			this->textBox_Heater_Amp->Text = L"00.0";
			this->textBox_Heater_Amp->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// lb_wait_pkt
			// 
			this->lb_wait_pkt->AutoSize = true;
			this->lb_wait_pkt->Font = (gcnew System::Drawing::Font(L"Cambria", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lb_wait_pkt->ForeColor = System::Drawing::Color::Purple;
			this->lb_wait_pkt->Location = System::Drawing::Point(121, 81);
			this->lb_wait_pkt->Name = L"lb_wait_pkt";
			this->lb_wait_pkt->Size = System::Drawing::Size(54, 15);
			this->lb_wait_pkt->TabIndex = 59;
			this->lb_wait_pkt->Text = L"wait_pkt";
			// 
			// lb_wait_cmd
			// 
			this->lb_wait_cmd->AutoSize = true;
			this->lb_wait_cmd->Font = (gcnew System::Drawing::Font(L"Cambria", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lb_wait_cmd->ForeColor = System::Drawing::Color::Purple;
			this->lb_wait_cmd->Location = System::Drawing::Point(121, 96);
			this->lb_wait_cmd->Name = L"lb_wait_cmd";
			this->lb_wait_cmd->Size = System::Drawing::Size(60, 15);
			this->lb_wait_cmd->TabIndex = 60;
			this->lb_wait_cmd->Text = L"wait_cmd";
			// 
			// lb_wait_NBcmd
			// 
			this->lb_wait_NBcmd->AutoSize = true;
			this->lb_wait_NBcmd->Font = (gcnew System::Drawing::Font(L"Cambria", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lb_wait_NBcmd->ForeColor = System::Drawing::Color::Purple;
			this->lb_wait_NBcmd->Location = System::Drawing::Point(122, 111);
			this->lb_wait_NBcmd->Name = L"lb_wait_NBcmd";
			this->lb_wait_NBcmd->Size = System::Drawing::Size(77, 15);
			this->lb_wait_NBcmd->TabIndex = 61;
			this->lb_wait_NBcmd->Text = L"wait_NBcmd";
			// 
			// RDS_main_Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 19);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->AutoSize = true;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->ClientSize = System::Drawing::Size(990, 832);
			this->Controls->Add(this->panel_heater_Amp);
			this->Controls->Add(this->panel_DateTime);
			this->Controls->Add(this->panel_FilterSch);
			this->Controls->Add(this->panel_Filter);
			this->Controls->Add(this->panel_EngArea);
			this->Controls->Add(this->panel_Service_Hint_1);
			this->Controls->Add(this->panel_Service_Hint);
			this->Controls->Add(this->richTextBox_main_output);
			this->Controls->Add(this->panel_model);
			this->Controls->Add(this->panel_control);
			this->Controls->Add(this->panel_ECO_mode);
			this->Controls->Add(this->panel_UV);
			this->Controls->Add(this->panel_Blower_Amp);
			this->Controls->Add(this->panel_P3_Amp);
			this->Controls->Add(this->panel_Blower_MCU);
			this->Controls->Add(this->panel_P2_Amp);
			this->Controls->Add(this->panel_Blower_OnOff);
			this->Controls->Add(this->panel_P3_MCU);
			this->Controls->Add(this->panel_Blower);
			this->Controls->Add(this->panel_P1_Amp);
			this->Controls->Add(this->panel_RH_status);
			this->Controls->Add(this->panel_P3_HiLo);
			this->Controls->Add(this->panel_RH);
			this->Controls->Add(this->panel_P2_MCU);
			this->Controls->Add(this->panel_Pump3);
			this->Controls->Add(this->panel_Device_Amp);
			this->Controls->Add(this->panel_P3R_status);
			this->Controls->Add(this->panel_P2_HiLo);
			this->Controls->Add(this->panel_P3R);
			this->Controls->Add(this->panel_P1_MCU);
			this->Controls->Add(this->panel_Pump2);
			this->Controls->Add(this->panel_MCU_status);
			this->Controls->Add(this->panel_P2R_status);
			this->Controls->Add(this->panel_P1_HiLo);
			this->Controls->Add(this->panel_p2R);
			this->Controls->Add(this->panel_Pump1);
			this->Controls->Add(this->panel_P1R_status);
			this->Controls->Add(this->panel_P1R);
			this->Controls->Add(this->panel_Operation);
			this->Controls->Add(this->panel_Device);
			this->Controls->Add(this->panel_Relay_status);
			this->Controls->Add(this->panel_Relay);
			this->Controls->Add(this->panel_measure);
			this->Controls->Add(this->panel_Err_area);
			this->Controls->Add(this->panel_lock);
			this->Controls->Add(this->panel_mcu_HCV);
			this->Controls->Add(this->panel_temperature);
			this->Controls->Add(this->panel_auto_diag);
			this->Controls->Add(this->panel_connect);
			this->Controls->Add(this->panel_disconnect);
			this->Controls->Add(this->panel_spa_serial);
			this->Controls->Add(this->panel_owner);
			this->Controls->Add(this->panel_UID);
			this->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"RDS_main_Form";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = resources->GetString(L"$this.Text");
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &RDS_main_Form::RDS_main_Form_FormClosing);
			this->Load += gcnew System::EventHandler(this, &RDS_main_Form::RDS_main_Form_Load);
			this->panel_UID->ResumeLayout(false);
			this->panel_UID->PerformLayout();
			this->panel_owner->ResumeLayout(false);
			this->panel_owner->PerformLayout();
			this->panel_spa_serial->ResumeLayout(false);
			this->panel_spa_serial->PerformLayout();
			this->panel_disconnect->ResumeLayout(false);
			this->panel_connect->ResumeLayout(false);
			this->panel_connect->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_packet_sign))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_connect_light))->EndInit();
			this->panel_auto_diag->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_auto_diag))->EndInit();
			this->panel_temperature->ResumeLayout(false);
			this->panel_temperature->PerformLayout();
			this->panel_mcu_HCV->ResumeLayout(false);
			this->panel_mcu_HCV->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_CIRC_MCU))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_UV_MCU))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_HT_MCU))->EndInit();
			this->panel_lock->ResumeLayout(false);
			this->panel_Err_area->ResumeLayout(false);
			this->panel_Err_Msg->ResumeLayout(false);
			this->panel_Err_Msg->PerformLayout();
			this->panel_Service_Hint->ResumeLayout(false);
			this->panel_Service_Hint->PerformLayout();
			this->panel_Service_Hint_1->ResumeLayout(false);
			this->panel_Service_Hint_1->PerformLayout();
			this->panel_measure->ResumeLayout(false);
			this->panel_measure->PerformLayout();
			this->panel_Relay->ResumeLayout(false);
			this->panel_Relay->PerformLayout();
			this->panel_Relay_status->ResumeLayout(false);
			this->panel_Relay_status->PerformLayout();
			this->panel_Device->ResumeLayout(false);
			this->panel_Device->PerformLayout();
			this->panel_Operation->ResumeLayout(false);
			this->panel_Operation->PerformLayout();
			this->panel_P1R->ResumeLayout(false);
			this->panel_P1R->PerformLayout();
			this->panel_P1R_status->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_P1R_status))->EndInit();
			this->panel_Pump1->ResumeLayout(false);
			this->panel_Pump1->PerformLayout();
			this->panel_P1_HiLo->ResumeLayout(false);
			this->panel_MCU_status->ResumeLayout(false);
			this->panel_MCU_status->PerformLayout();
			this->panel_P1_MCU->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_P1_MCU))->EndInit();
			this->panel_Device_Amp->ResumeLayout(false);
			this->panel_Device_Amp->PerformLayout();
			this->panel_P1_Amp->ResumeLayout(false);
			this->panel_P1_Amp->PerformLayout();
			this->panel_P2_Amp->ResumeLayout(false);
			this->panel_P2_Amp->PerformLayout();
			this->panel_P2_MCU->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_P2_MCU))->EndInit();
			this->panel_P2_HiLo->ResumeLayout(false);
			this->panel_Pump2->ResumeLayout(false);
			this->panel_Pump2->PerformLayout();
			this->panel_P2R_status->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_P2R_status))->EndInit();
			this->panel_p2R->ResumeLayout(false);
			this->panel_p2R->PerformLayout();
			this->panel_P3_Amp->ResumeLayout(false);
			this->panel_P3_Amp->PerformLayout();
			this->panel_P3_MCU->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_P3_MCU))->EndInit();
			this->panel_P3_HiLo->ResumeLayout(false);
			this->panel_Pump3->ResumeLayout(false);
			this->panel_Pump3->PerformLayout();
			this->panel_P3R_status->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_P3R_status))->EndInit();
			this->panel_P3R->ResumeLayout(false);
			this->panel_P3R->PerformLayout();
			this->panel_Blower_Amp->ResumeLayout(false);
			this->panel_Blower_Amp->PerformLayout();
			this->panel_Blower_MCU->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_Blower_MCU))->EndInit();
			this->panel_Blower_OnOff->ResumeLayout(false);
			this->panel_Blower->ResumeLayout(false);
			this->panel_Blower->PerformLayout();
			this->panel_RH_status->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_RH_status))->EndInit();
			this->panel_RH->ResumeLayout(false);
			this->panel_RH->PerformLayout();
			this->panel_Filter->ResumeLayout(false);
			this->panel_Filter->PerformLayout();
			this->panel_UV->ResumeLayout(false);
			this->panel_UV->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_ECO))->EndInit();
			this->panel_ECO_mode->ResumeLayout(false);
			this->panel_ECO_mode->PerformLayout();
			this->panel_control->ResumeLayout(false);
			this->panel_EngArea->ResumeLayout(false);
			this->panel_EngArea->PerformLayout();
			this->panel_model->ResumeLayout(false);
			this->panel_model->PerformLayout();
			this->panel_FilterSch->ResumeLayout(false);
			this->panel_DateTime->ResumeLayout(false);
			this->panel_heater_Amp->ResumeLayout(false);
			this->panel_heater_Amp->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

//folowing is add-on function -------------------------------------
public: void initial_All(void);

//display message...
public: System::Void MsgMain(String^ InStr);    //has date/time, new-line
public: System::Void MsgMain2(String^ InStr);   //dont has date/time; has new-line
public: System::Void MsgMain2UL(String^ InStr); //dont has date/time; has new-line & under-line style
public: System::Void MsgMain3CS(String^ InStr, Color textColor);   //No new-line, no DateTime; with color setting
public: System::Void MsgMain3FS(String^ InStr, FontStyle textFontStyle);   //No new-line, no DateTime; with font styel setting
//
public: System::Void MsgEngr(String^ InStr);
public:	System::Void MsgEngr_IOT_error();
public: System::Void MsgLog(String^ InStr);

//display UI
public: System::Void showErrCuaseEquip(unsigned int msg_index);
public: System::Void UpdateErrCuaseEquip();
public: System::Void UpdateUIfromSPA();
public: System::Void UpdateUIfromIOT();
public: System::Void UpdateUI();
public: System::Void SetWaitingCmd(unsigned char cmd);
public: System::Void ClearWaitingCmd();

//for sub-windows (set/change sometings ...)
public: System::Void set_textBox_Set_T(String^ InStr);
public: System::Void set_textBox_FltDay(String^ InStr);
public: System::Void set_textBox_UVday(String^ InStr);
public: void enable_SetT_area();
public: void enable_FltDay_area();
public: void enable_UVday_area();
//
public: System::Void openDataTimeWin();
public: System::Void openStdCircScheduleWin();
public: System::Void openEcoCircScheduleWin();
public: System::Void open_SF_Win();
public: System::Void open_PF_Win();
//
public: void enable_DateTime_btn();
public: System::Void set_DateTime(
	unsigned char time_year,   //00~99 : 2000~2099
	unsigned char time_month,  //1~12
	unsigned char time_day,    //1~31
	unsigned char time_week,   //1=sun, 2=mon....7=Sat
	unsigned char time_hour,
	unsigned char time_min
		);
public: System::Void checkingDateTime();

//
public: void enable_FilterSchedule_btn();
public: System::Void set_StdFilterSchedule(
	unsigned char std_st_hour,
	unsigned char std_st_min,
	unsigned char std_dt_hour,
	unsigned char std_dt_min,
	unsigned char std_week
	);
public: System::Void checkingStdFilterSchedule();
public: System::Void set_EcoFilterSchedule(
	unsigned char eco_1_st_hour,
	unsigned char eco_1_st_min,
	unsigned char eco_1_dt_hour,
	unsigned char eco_1_dt_min,
	unsigned char eco_2_st_hour,
	unsigned char eco_2_st_min,
	unsigned char eco_2_dt_hour,
	unsigned char eco_2_dt_min,
	unsigned char eco_3_st_hour,
	unsigned char eco_3_st_min,
	unsigned char eco_3_dt_hour,
	unsigned char eco_3_dt_min,
	unsigned char eco_4_st_hour,
	unsigned char eco_4_st_min,
	unsigned char eco_4_dt_hour,
	unsigned char eco_4_dt_min,
	unsigned char eco_1_week,
	unsigned char eco_2_week,
	unsigned char eco_3_week,
	unsigned char eco_4_week
	);
public: System::Void checkingEcoFilterSchedule();

//
public: void enable_SF_btn();
public: System::Void set_SF(
	unsigned int sf_value
	);
public: System::Void checkingSF();

//
public: void enable_PF_btn();
public: System::Void set_PF(
	unsigned int pf_value,
	unsigned char pf_st_hour,
	unsigned char pf_st_min,
	unsigned char pf_dt_hour,
	unsigned char pf_dt_min
	);
public: System::Void checkingPF();

//For login-in precess
public: System::Void LoginResult(
	Boolean LoginOk,
	unsigned char userNo,
	String^ Name
	);
public:  int read_SpaModel_setting();

//DisplayText() work with client thread
public: void DisplayText(array<unsigned char>^ buffer);
public: void Wait_Retry();

//read Error History
public: void Read_EEP_1st_page();
public: void Read_Err_Hist_page();
public: void Save_Err_Hist_page();
public: System::Void openErrHistWin();
public: void enable_ErrHistory_btn();

//service hint area
public: void Show_NeedService();
public: void Show_ServiceCommited(String^ Service_No);

//clinet thread   *****
private: void ClientThread();

//for auto-diagnosis
private: void  AD_start_status_save();
private: Boolean AD_status_change();
private: Boolean AD_status_changeM1M2();
private: void AD_Diagnosis();
private: void AD_judge_M0_HC();
private: void AD_judge_M0_C();
private: void AD_judge_M0();
private: void AD_judge_M1();
private: void AD_judge_M2();
private: void AD_judge_M3();
private: void AD_judge_M4();
private: void AD_judge_M5();
private: void AD_judge_M6();
private: void AD_judge_M7();
private: void AD_judge_CauseEquip();
private: void noneAD_judge_CauseEquip();

//for RDS report
private: void  RPT_save(String^ UID);
private: void  RPT_delete(String^ UID);
private: Boolean RPT_chkUID(String^ UID);
private: Boolean RPT_chkUID_today(String^ rptFileStr, String^ UID);
private: void  RPT_getSCno();
private: void  RPT_saveSCno(int Scno);
public: void open_Full_Report(String^ ReadFileName_in);
public: void enable_Report_btn();

//for Log file
private: void Log_save(String^ UID);

//for history (&report)
public: void open_Report_History();
public: void open_Log_History();
private: Boolean Check_UID_dir(String^ UID);
public: void enable_History_btn();

//SC list
public: void enable_SClist_btn();

//following is produce by VS2013 ----------------------------------
private: System::Void RDS_main_Form_Load(System::Object^  sender, System::EventArgs^  e);
private: System::Void label_owner_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void button_connect_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void button_Date_Time_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void button_Filtration_sch_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void textBox_Set_T_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
private: System::Void textBox_Filter_Days_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
private: System::Void textBox_UV_Days_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
private: System::Void button_disconnect_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void button_update_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void button_green_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void button_yellow_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void button_red_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void button_blue_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void button_degree_F_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void button_degree_C_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void RDS_closing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e);
private: System::Void button_P1_Hi_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void button_P1_Lo_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void button_P2_Hi_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void button_P2_Lo_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void button_P3_Hi_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void button_P3_Lo_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void button_Blower_OnOff_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void button_unlock_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void button_T_Lock_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void button_Func_Lock_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void button_Pump_Lock_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void button_Panel_Lock_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void button_mode_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void button_Err_Msg_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void button_Service_Call_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void button_RDS_report_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void button_History_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void button_auto_diag_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void button_OSC_list_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void button_SF_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void button_PF_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void label_spa_serial_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void RDS_main_Form_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
	int rtn;
	if (this->iNas.userNo != 0){
		rtn = this->iNas.Unlock_Person_Login(this->iNas.userNo);
		if (rtn < 0){
			MessageBox::Show(LOGIN_ERR_FILE_LOSS_BEF_UNLOCK, "ERROR",
				MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
	}
}
}; //end of class RDS_main_Form

	//small class for sorting string array... 
	public ref class ReverseComparer : IComparer
	{
	public:
		// Call CaseInsensitiveComparer::Compare with the parameters reversed.
		virtual int Compare(Object^ x, Object^ y) = IComparer::Compare
		{
			return ((gcnew CaseInsensitiveComparer)->Compare(y, x));
		}
	};
} //end of namespace RDS
//--- end of file ----
