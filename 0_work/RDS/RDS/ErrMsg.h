
#include "spa_cmd.h"

#ifndef USE_ERROR_HISTOR_HEADER

#define USE_ERROR_HISTOR_HEADER		1

//For error related information table
#define MAX_NUMBER_OF_ERR_CODE		31
#define MAX_INDEX_OF_ERR_TABLE		SPA_NO_ERROR_DEFAULT_INDEX+1
#define MAX_NUMBER_OF_SOL_ITEMS		2
#define MAX_NUMBER_OF_SUB_ITEMS		7

//For reading 50 history error from SPA
#define FIRST_RECORD_ADDRRESS		0x0100
#define BYTES_PER_PAGE_OF_EEPROM	8
#define PAGES_PER_RECORD_ERR_HIST	2
#define RECORDS_IN_ERROR_HISTORY	50

//For Auto-diagnosis combing final cause/equipments
#define AUTO_DIAGNOSIS_MAX_CUASE	12
#define AUTO_DIAGNOSIS_MAX_EQUIP	12
#define CUASE_RPT_TABLE_SIZE		26
#define EQUIP_RPT_TABLE_SIZE		26

struct err_History_record{
	unsigned char err_Bit;
	unsigned char state_H;
	unsigned char state_L;
	unsigned char hili_temp;
	unsigned char watr_temp;
	unsigned char pcba_temp;
	unsigned char st_year;
	unsigned char st_month;
	unsigned char st_day;
	unsigned char st_hour;
	unsigned char st_min;
	unsigned char et_year;
	unsigned char et_month;
	unsigned char et_day;
	unsigned char et_hour;
	unsigned char et_min;
};

struct Encode_Equpiment_type{
	unsigned char code;    //0=none, encoding from 1,2,3...
	char* CE_string;
	unsigned char partListIndex;
};

struct Encode_Cause_Equpiment_type{
	unsigned char code;    //0=none, encoding from 1,2,3...
	char* CE_string;
};

struct err_Info {      	
	char* err_code[2];
	char* definition;  
	unsigned int sol_no;
	char* sol[MAX_NUMBER_OF_SOL_ITEMS];
	unsigned int follow_no;
	char* follow[MAX_NUMBER_OF_SUB_ITEMS];
	unsigned int cause_no;
	struct Encode_Cause_Equpiment_type cause[MAX_NUMBER_OF_SUB_ITEMS];
	unsigned int equip_no;
	struct Encode_Cause_Equpiment_type equipment[MAX_NUMBER_OF_SUB_ITEMS];
};

//for Every model AD current measure comparing
struct SpaModel_ADcurrnt {
	unsigned int AllOff_max;
	unsigned int AllOff_min;
	unsigned int AllOff_Heater_Circ_UV_max;
	unsigned int AllOff_Heater_Circ_UV_min;
	unsigned int AllOff_Circ_UV_max;
	unsigned int AllOff_Circ_UV_min;
	unsigned int Pump1_Hi_max;
	unsigned int Pump1_Hi_min;
	unsigned int Pump1_Hi_Circ_UV_max;
	unsigned int Pump1_Hi_Circ_UV_min;
	unsigned int Pump1_Hi_Heater_Circ_UV_max;
	unsigned int Pump1_Hi_Heater_Circ_UV_min;
	unsigned int Pump1_Lo_max;
	unsigned int Pump1_Lo_min;
	unsigned int Pump1_Lo_Circ_UV_max;
	unsigned int Pump1_Lo_Circ_UV_min;
	unsigned int Pump1_Lo_Heater_Circ_UV_max;
	unsigned int Pump1_Lo_Heater_Circ_UV_min;
	unsigned int Pump2_Hi_max;
	unsigned int Pump2_Hi_min;
	unsigned int Pump2_Hi_Heater_Circ_UV_max;
	unsigned int Pump2_Hi_Heater_Circ_UV_min;
	unsigned int Pump2_Lo_max;
	unsigned int Pump2_Lo_min;
	unsigned int Pump2_Lo_Heater_Circ_UV_max;
	unsigned int Pump2_Lo_Heater_Circ_UV_min;
	unsigned int Pump3_Hi_max;
	unsigned int Pump3_Hi_min;
	unsigned int Pump3_Hi_Heater_Circ_UV_max;
	unsigned int Pump3_Hi_Heater_Circ_UV_min;
	unsigned int Pump3_Lo_max;
	unsigned int Pump3_Lo_min;
	unsigned int Pump3_Lo_Heater_Circ_UV_max;
	unsigned int Pump3_Lo_Heater_Circ_UV_min;
	unsigned int Blower_max;
	unsigned int Blower_min;
	unsigned int Blower_Heater_Circ_UV_max;
	unsigned int Blower_Heater_Circ_UV_min;
/*	char* Pump_1;
	char* Pump_2;
	char* Pump_3;
	char* Circ_Pump;
	char* Blower;
	char* Heater;
	char* Topside;
	char* CTR_Borad;
	char* Water_Temp_Sensor;
	char* Hi_limit_Sensor;
	char* Flow_Switch;
	char* Fuse;
	char* UV_Light;
	char* Filter_Cartridge;
	char* Pipe;
*/
};

#endif