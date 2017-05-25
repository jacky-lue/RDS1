//----------------------------------------------------
// Only for RDA_main_Form, global variables part.
// 
// For those not objectlize data. (not good idea, but workable...)

#include "ErrMsg.h"

//For total error cause (writeing)
unsigned char AD_all_Cause[AUTO_DIAGNOSIS_MAX_CUASE];
unsigned char AD_all_Equip[AUTO_DIAGNOSIS_MAX_EQUIP];

//for SpaModel name and AD information
struct SpaModel_ADcurrnt SpaModels[MAX_HOT_TUV_MODELS]; //for AD current
char* ModelNames[MAX_HOT_TUV_MODELS];
char* PartNoList[MAX_HOT_TUV_MODELS][PART_NO_LINES_PER_MODEL];

//for display 4 error code area
char* eMSG_Table[2][MAX_INDEX_OF_ERR_TABLE] = {
	{
		"SN1",  	// 00  org=SN1
		"SN2",  	// 01  org=SN2
		"SN3",  	// 02  org=SN3
		"SN4",  	// 03  org=SN4
		"SN5",  	// 04  org=SN5
		"SN6",  	// 05  org=SN6
		"SN7",  	// 06
		"SN8",  	// 07
		"L1",  		// 08  org=L1
		"L2",  		// 09  org=L2
		"L3",  		// 10  org=L3
		"L4",  		// 11  org=L4
		"FL1",  	// 12  org=FL1
		"FL2",  	// 13  org=FL2
		"FLO2",  	// 14  org=FLO2
		"R1",		// 15
		"R2",  		// 16
		"R3",  		// 17
		"RH",  		// 18  
		"OH", 		// 19  org=OH
		"COOL",  	// 20  org=COOL
		"ICE",  	// 21  org=ICE
		"WD", 		// 22  org=WD
		"BLB",  	// 23  org=BLB
		"CF",  	    // 24  org=CF
		"HOT",     	// 25  org=HOT
		"TPD",  	// 26  2016.10.28
		"",  		// 27  reserved
		"",  		// 28  reserved
		"",  		// 29  reserved
		"",  		// 30  reserved
		"",  		// 31  reserved
		"",			//SPA_NO_ERROR_DEFAULT_INDEX
	},
	{
		"WSO",  	// 00  org=SN1
		"WSS",  	// 01  org=SN2
		"HSO",  	// 02  org=SN3
		"HSS",  	// 03  org=SN4
		"PSO",  	// 04  org=SN5
		"PSS",  	// 05  org=SN6
		"SN7",  	// 06
		"SN8",  	// 07
		"LOKA",  	// 08  org=L1
		"LOKP",  	// 09  org=L2
		"LOKE",  	// 10  org=L3
		"LOKS",  	// 11  org=L4
		"FSO",  	// 12  org=FL1
		"FSC",  	// 13  org=FL2
		"FSC1",  	// 14  org=FLO2
		"R1",		// 15
		"R2",  		// 16
		"R3",  		// 17
		"RH",  		// 18  
		"WOH", 		// 19  org=OH
		"WCL",  	// 20  org=COOL
		"WICE",  	// 21  org=ICE
		"WWD", 		// 22  org=WWD
		"CBB",  	// 23  org=BLB
		"FEX",  	// 24  org=CF
		"PCBH",     // 25  org=HOT
		"TPD",  	// 26  2016.10.28
		"",  		// 27  reserved
		"",  		// 28  reserved
		"",  		// 29  reserved
		"",  		// 30  reserved
		"",  		// 31  reserved
		"",			//SPA_NO_ERROR_DEFAULT_INDEX
	}
};

//Using types from ErrMsg.h 
//For reading error history from SPA
struct err_History_record SPA_ERR_HIST_TABLE[RECORDS_IN_ERROR_HISTORY];

//for display error related information in main message area
struct err_Info SPA_ERR_TABLE[MAX_NUMBER_OF_ERR_CODE] = {
	{//-------------------------------------------------------[0] SN1
		{ "SN1", "WSO" },
		"Water temperature sensor OPEN",
		0, //sol
		{ "", "" },
		0, //follow
		{ "", "", "", "", "", "", "" },
		3, //cause
		{
			 1,"Water temperature sensor defect",  //1
			10,"Board defect",  //2
			11,"Topside defect",  //3
			 0,"",  //4
			 0,"",  //5
			 0,"",  //6
			 0,"",  //7
		},
		3, //equipment
		{
			 1,"Water temperature sensor",  //1
			10,"Board",  //2
			11,"Topside",  //3
			 0,"",  //4
			 0,"",  //5
			 0,"",  //6
			 0,"",  //7
		},
	},
	{//-------------------------------------------------------[1] SN2
		{ "SN2", "WSS" },
		"Water temperature sensor SHORT",
		0, //sol
		{ "", "" },
		0, //follow
		{ "", "", "", "", "", "", "" },
		3, //cause
		{
			 1,"Water temperature sensor defect",  //1
			10,"Board defect",  //2
			11,"Topside defect",  //3
			 0,"",  //4
			 0,"",  //5
			 0,"",  //6
			 0,"",  //7
		},
		3, //equipment
		{
			 1,"Water temperature sensor",  //1
			10,"Board",  //2
			11,"Topside",  //3
			 0,"",  //4
			 0,"",  //5
			 0,"",  //6
			 0,"",  //7
		},
	},
	{//-------------------------------------------------------[2] SN3
		{ "SN3", "HSO" },
		"Hi-limit temperature sensor OPEN",
		0, //sol
		{ "", "" },
		0, //follow
		{ "", "", "", "", "", "", "" },
		2, //cause
		{
			 2,"Hi-limit temperature sensor defect",  //1
			10,"Board defect",  //2
			 0,"",  //3
			 0,"",  //4
			 0,"",  //5
			 0,"",  //6
			 0,"",  //7
		},
		2, //equipment
		{
			 2,"Hi-limit temperature sensor",  //1
			10,"Board",  //2
			 0,"",  //3
			 0,"",  //4
			 0,"",  //5
			 0,"",  //6
			 0,"",  //7
		},
	},
	{//-------------------------------------------------------[3] SN4
		{ "SN4", "HSS" },
		"Hi-Limit temperature sensor SHORT",
		0, //sol
		{ "", "" },
		0, //follow
		{ "", "", "", "", "", "", "" },
		2, //cause
		{
			 2,"Hi-limit temperature sensor defect",  //1
			10,"Board defect",  //2
			 0,"",  //3
			 0,"",  //4
			 0,"",  //5
			 0,"",  //6
			 0,"",  //7
		},
		2, //equipment
		{
			 2,"Hi-limit temperature sensor",  //1
			10,"Board",  //2
			 0,"",  //3
			 0,"",  //4
			 0,"",  //5
			 0,"",  //6
			 0,"",  //7
		},
	},
	{//-------------------------------------------------------[4] SN5
		{ "SN5", "PSO" },
		"PCB temperature sensor OPEN",
		0, //sol
		{ "", "" },
		0, //follow
		{ "", "", "", "", "", "", "" },
		1, //cause
		{
			10,"Board defect",  //1
			 0,"",  //2
			 0,"",  //3
			 0,"",  //4
			 0,"",  //5
			 0,"",  //6
			 0,"",  //7
		},
		1, //equipment
		{
			10,"Board",  //1
			 0,"",  //2
			 0,"",  //3
			 0,"",  //4
			 0,"",  //5
			 0,"",  //6
			 0,"",  //7
		},
	},
	{//-------------------------------------------------------[5] SN6
		{ "SN6", "PSS" },
		"PCB temperature sensor SHORT",
		0, //sol
		{ "", "" },
		0, //follow
		{ "", "", "", "", "", "", "" },
		1, //casue
		{
			10,"Board defect",  //1
			 0,"",  //2
			 0,"",  //3
			 0,"",  //4
			 0,"",  //5
			 0,"",  //6
			 0,"",  //7
		},
		1, //equipment
		{
			10,"Board",  //1
			 0,"",  //2
			 0,"",  //3
			 0,"",  //4
			 0,"",  //5
			 0,"",  //6
			 0,"",  //7
		},
	},
	{//-------------------------------------------------------[6] SN7  reseved
		{ "SN7", "SN7" },
		"Reserved message....",
		0, //sol
		{ "", "" },
		0, //follow
		{ "", "", "", "", "", "", "" },
		1,
		{
			10,"Board defect",  //1
			 0,"",  //2
			 0,"",  //3
			 0,"",  //4
			 0,"",  //5
			 0,"",  //6
			 0,"",  //7
		},
		1,
		{
			10,"Board",  //1
			 0,"",  //2
			 0,"",  //3
			 0,"",  //4
			 0,"",  //5
		 	 0,"",  //6
			 0,"",  //7
		},
	},
	{//-------------------------------------------------------[7] SN8  reseved
		{ "SN8", "SN8" },
		"Reserved message....",
		0, //sol
		{ "", "" },
		0, //follow
		{ "", "", "", "", "", "", "" },
		1,
		{
			10,"Board defect",  //1
			 0,"",  //2
			 0,"",  //3
			 0,"",  //4
			 0,"",  //5
			 0,"",  //6
			 0,"",  //7
		},
		1,
		{
			10,"Board",  //1
			 0,"",  //2
			 0,"",  //3
			 0,"",  //4
			 0,"",  //5
			 0,"",  //6
			 0,"",  //7
		},
	},
	{//-------------------------------------------------------[8] LOCK1  (not error)
		{ "L1", "LOKA" },
		"Panel is locked. All functions locked.",
		1, //sol
		{ "Please manually unlock to operate", 
		 "" },
		0, //follow
		{ "", "", "", "", "", "", "" },
		0,
		{
			0,"",  //1
			0,"",  //2
			0,"",  //3
			0,"",  //4
			0,"",  //5
			0,"",  //6
			0,"",  //7
		},
		0,
		{
			0,"",  //1
			0,"",  //2
			0,"",  //3
			0,"",  //4
			0,"",  //5
			0,"",  //6
			0,"",  //7
		},
	},
	{//-------------------------------------------------------[9] LOCK2  (not error)
		{ "L2", "LOKP" },
		"Pump is locked.",
		1, //sol
		{ "Please manually unlock to operate pump",
		"" },
		0, //follow
		{ "", "", "", "", "", "", "" },
		0,
		{
			0,"",  //1
			0,"",  //2
			0,"",  //3
			0,"",  //4
			0,"",  //5
			0,"",  //6
			0,"",  //7
		},
		0,
		{
			0,"",  //1
			0,"",  //2
			0,"",  //3
			0,"",  //4
			0,"",  //5
			0,"",  //6
			0,"",  //7
		},
	},
	{//-------------------------------------------------------[10] LOCK3  (not error)
		{ "L3", "LOKE" },
		"Temperature is locked.",
		1, //sol
		{ "Please manually unlock to adjust temperature",
		"" },
		0, //follow
		{ "", "", "", "", "", "", "" },
		0,
		{
			0,"",  //1
			0,"",  //2
			0,"",  //3
			0,"",  //4
			0,"",  //5
			0,"",  //6
			0,"",  //7
		},
		0,
		{
			0,"",  //1
			0,"",  //2
			0,"",  //3
			0,"",  //4
			0,"",  //5
			0,"",  //6
			0,"",  //7
		},
	},
	{//-------------------------------------------------------[11] LOCK4  (not error)
		{ "L4", "LOKS" },
		"Service lock. All pumps including circ. pump and heater are locked for 120 minutes for any service or filter replacement.",
		1, //sol
		{ "Please manually unlock to operate ",
		"" },
		0, //follow
		{ "", "", "", "", "", "", "" },
		0,
		{
			 0,"",  //1
			 0,"",  //2
			 0,"",  //3
			 0,"",  //4
			 0,"",  //5
			 0,"",  //6
			 0,"",  //7
		},
		0,
		{
			 0,"",  //1
			 0,"",  //2
			 0,"",  //3
			 0,"",  //4
			 0,"",  //5
			 0,"",  //6
			 0,"",  //7
		},
	},
	{//-------------------------------------------------------[12] FLOW1
		{ "FL1", "FSO" },
		"Flow switch OPEN",
		0, //sol
		{ "", "" },
		5, //follow
		{	"Is water level above every jets?", //1
			"Dirty filter can cause this error.Is filter cartridge replaced?", //2
			"Are all jets opened and water flow appears normal? Air locked pump is common when a spa has been drained and re-filled.", //3
			"Are all pumps plugged in? and fuse is not blown? ", //4
			"Is flow switch replaced recently?", //5
			"", 
			"" },
		5, //cuase
		{
			10,"Board defect",  //1
			3,"Circ Pump defect",  //2
			4,"Fuse on board defect",  //3
			5,"Pipe Blockage",  //4
			6,"Dirty Filter",  //5
			0,"",  //6
			0,"",  //7
		},
		5, //equipment
		{
			10,"Board",  //1
			3,"Circ Pump",  //2
			4,"Fuse",  //3
			5,"Pipe",  //4
			6,"Filter cartridge",  //5
			0,"",  //6
			0,"",  //7
		},
	},
	{//-------------------------------------------------------[13] FLOW2
		{ "FL2", "FSC" },
		"Flow switch CLOSE",
		0, //sol
		{ "", "" },
		1, //follow
		{	"Is flow switch adjusted correctly?", 
			"", "", "", "", "", "" },
		3, //cause
		{
			 7,"Flow Switch defect",  //1
			10,"Board defect",  //2
			 3,"Circ. Pump defect",  //3
			 0,"",  //4
			 0,"",  //5
			 0,"",  //6
			 0,"",  //7
		},
		3, //equipment
		{
			 7,"Flow Switch",  //1
			10,"Board",  //2
			 3,"Circ. Pump",  //3
			 0,"",  //4
			 0,"",  //5
			 0,"",  //6
			 0,"",  //7
		},
	},
	{//-------------------------------------------------------[14] FLOW3
		{ "FLO2", "FSC1" },
		"Flow switch CLOSE",
		0, //sol
		{ "", "" },
		1, //follow
		{	"Is flow switch adjusted correctly?", 
			"", "", "", "", "", "" },
		3, //cause
		{
			 7,"Flow Switch defect",  //1
			10,"Board defect",  //2
			 3,"Circ. Pump defect",  //3
			 0,"",  //4
			 0,"",  //5
			 0,"",  //6
			 0,"",  //7
		},
		3, //equipment
		{
			 7,"Flow Switch",  //1
			10,"Board",  //2
			 3,"Circ. Pump",  //3
			 0,"",  //4
			 0,"",  //5
			 0,"",  //6
			 0,"",  //7
		},
	},
	{//-------------------------------------------------------[15] P1R
		{ "R1", "R1" },
		"Pump 1 high speed relay defect",
		0, //sol
		{ "", "" },
		0, //follow
		{ "", "", "", "", "", "", "" },
		1,
		{
			10,"Board defect",  //1
			 0,"",  //2
			 0,"",  //3
			 0,"",  //4
			 0,"",  //5
			 0,"",  //6
			 0,"",  //7
		},
		1,
		{
			10,"Board",  //1
			 0,"",  //2
			 0,"",  //3
			 0,"",  //4
			 0,"",  //5
			 0,"",  //6
			 0,"",  //7
		},
	},
	{//-------------------------------------------------------[16] P2R
		{ "R2", "R2" },
		"Pump 2 high speed relay defect",
		0, //sol
		{ "", "" },
		0, //follow
		{ "", "", "", "", "", "", "" },
		1,
		{
			10,"Board defect",  //1
			 0,"",  //2
			 0,"",  //3
			 0,"",  //4
			 0,"",  //5
			 0,"",  //6
			 0,"",  //7
		},
		1,
		{
			10,"Board",  //1
			 0,"",  //2
			 0,"",  //3
			 0,"",  //4
			 0,"",  //5
			 0,"",  //6
			 0,"",  //7
		},
	},
	{//-------------------------------------------------------[17] P3R
		{ "R3", "R3" },
		"Pump 3 high speed relay defect",
		0, //sol
		{ "", "" },
		0, //follow
		{ "", "", "", "", "", "", "" },
		1,
		{
			10,"Board defect",  //1
			 0,"",  //2
			 0,"",  //3
			 0,"",  //4
			 0,"",  //5
			 0,"",  //6
			 0,"",  //7
		},
		1,
		{
			10,"Board",  //1
			 0,"",  //2
			 0,"",  //3
			 0,"",  //4
			 0,"",  //5
			 0,"",  //6
			 0,"",  //7
		},
	},
	{//-------------------------------------------------------[18] HR
		{ "RH", "RH" },
		"Heater relay defect",
		0, //sol
		{ "", "" },
		0, //follow
		{ "", "", "", "", "", "", "" },
		1,
		{
			10,"Board defect",  //1
			 0,"",  //2
			 0,"",  //3
			 0,"",  //4
			 0,"",  //5
			 0,"",  //6
			 0,"",  //7
		},
		1,
		{
			10,"Board",  //1
			 0,"",  //2
			 0,"",  //3
			 0,"",  //4
			 0,"",  //5
			 0,"",  //6
			 0,"",  //7
		},
	},
	{//-------------------------------------------------------[19] OH
		{ "OH", "WOH" },
		"Water temperature is too high. Water temperature is equal or exceed 112F, or Hi-limit temperature is equal or exceed 116F.",
		0, //sol
		{ "", "" },
		3, //follow
		{	"Is hot tub just filled with hot water? If yes, please allow water to cool.", //1
			"Heat may be caused by excessive filtration, please turn filtration down to 2-4 hours a day.", //2
			"Heat may be caused by extreme hot weather, need a summer door for cabinet to cool down.", //3
			"", "", "", "" },
		4, //cause
		{
			 1,"Water temperature sensor defect",  //1
			 2,"Hi-limit temperature sensor defect",  //2
			10,"Board defect",  //3
			11,"Topside defect",  //4
			 0,"",  //5
			 0,"",  //6
			 0,"",  //7
		},
		4, //equipment
		{
			 1,"Water temperature sensor",  //1
			 2,"Hi-limit temperature sensor",  //2
			10,"Board",  //3
			11,"Topside",  //4
			 0,"",  //5
			 0,"",  //6
			 0,"",  //7
		},
	},
	{//-------------------------------------------------------[20] COOL
		{ "COOL", "WCL" },
		"Water is cool. Actual water temperature is 20F lower than set temperature.",
		0, //sol
		{ "", "" },
		3, //follow
		{	"Is hot tub just filled with cold water?", //1
			"Is circulation pump on?", //2
			"Is weather too cold?", //3
			"", "", "", "" },
		4,
		{
			 2,"Hi-limit temperature sensor defect",  //1
			 1,"Water temperature sensor defect",  //2
			 3,"Circ. Pump defect",  //3
			10,"Board defect",  //4
			 0,"",  //5
			 0,"",  //6
			 0,"",  //7
		},
		4,
		{
			 2,"Hi-limit temperature sensor",  //1
			 1,"Water temperature sensor",  //2
			 3,"Circ. Pump",  //3
			10,"Board",  //4
			 0,"",  //5
			 0,"",  //6
			 0,"",  //7
		},
	},
	{//-------------------------------------------------------[21] ICE
		{ "ICE", "WICE" },
		"Water is too cold. Water temperature or hi-limit temperature is lower than 65F",
		0, //sol
		{ "", "" },
		3, //follow
		{	"Is Spa just filled with cold water?", //1
			"Is circulation pump on? ", //2
			"Is weather too cold? ", //3
			"", "", "", "" },
		4, //cause
		{
			 2,"Hi-limit temperature sensor defect",  //1
			 1,"Water temperature sensor defect",  //2
			 3,"Circ. Pump defect",  //3
			10,"Board defect",  //4
			 0,"",  //5
			 0,"",  //6
			 0,"",  //7
		},
		4, //equipment
		{
			 2,"Hi-limit temperature sensor",  //1
			 1,"Water temperature sensor",  //2
			 3,"Circ. Pump",  //3
			10,"Board",  //4
			 0,"",  //5
			 0,"",  //6
			 0,"",  //7
		},
	},
	{//-------------------------------------------------------[22] WD
		{ "WD", "WWD" },
		"Water temperature is too high. Hi-limit temperature is equal or exceed 120F",
		0, //sol
		{ "", "" },
		3, //follow
		{	"Is spa just filled with hot water? If yes, please allow water to cool.", //1
			"Heat may be caused by excessive filtration, please turn filtration down to 2-4 hours a day.", //2
			"Heat may caused by extreme hot weather, need a summer door for cabinet to cool down.", //3
			"", "", "", "" },
		4, //cause
		{
			 1,"Water temperature sensor defect",  //1
			 2,"Hi-limit temperature sensor defect",  //2
			10,"Board defect",  //3
			11,"Topside defect",  //4
			 0,"",  //5
			 0,"",  //6
			 0,"",  //7
		},
		4, //equipment
		{
			 1,"Water temperature sensor",  //1
			 2,"Hi-Limit temperature sensor",  //2
			10,"Board",  //3
			11,"Topside",  //4
			 0,"",  //5
			 0,"",  //6
			 0,"",  //7
		},
	},
	{//-------------------------------------------------------[23] BLB
		{ "BLB", "CBB" },
		"UV  light usage expired",
		0, //sol
		{ "", "" },
		0, //follow
		{ "", "", "", "", "", "", "" },
		3,
		{
			 8,"UV light usage expired",  //1
			10,"Board defect",  //2
			11,"Topside defect",  //3
			0,"",  //4
			0,"",  //5
			0,"",  //6
			0,"",  //7
		},
		3,
		{
			 8,"UV light",  //1
			10,"Board",  //2
			11,"Topside",  //3
			 0,"",  //4
			 0,"",  //5
			 0,"",  //6
			 0,"",  //7
		},
	},
	{//-------------------------------------------------------[24] CF
		{ "CF", "FEX" },
		"Filter usage expired",
		0, //sol
		{ "", "" },
		0, //follow
		{ "", "", "", "", "", "", "" },
		3,
		{
			 9,"Filter Cartridge expired",  //1
			10,"Board defect",  //2
			11,"Topside defect",  //3
			 0,"",  //4
			 0,"",  //5
			 0,"",  //6
			 0,"",  //7
		},
		3,
		{
			 6,"Filter Cartridge",  //1     //use 6 as only one for filter 
			10,"Board",  //2
			11,"Topside",  //3
			 0,"",  //4
			 0,"",  //5
			 0,"",  //6
			 0,"",  //7
		},
	},
	{//-------------------------------------------------------[25] HOT
		{ "HOT", "PCBH" },
		"PCB temperature is too high. Temperature exceeds 180F",
		0, //sol
		{ "", "" },
		0, //follow
		{ "", "", "", "", "", "", "" },
		1,
		{
			10,"Board defect",  //1
			 0,"",  //2
			 0,"",  //3
			 0,"",  //4
			 0,"",  //5
			 0,"",  //6
			 0,"",  //7
		},
		1,
		{
			10,"Board",  //1
			 0,"",  //2
			 0,"",  //3
			 0,"",  //4
			 0,"",  //5
			 0,"",  //6
			 0,"",  //7
		},
	},
	{//-------------------------------------------------------[26] PAL ??
		{ "PAL", "NO_P" },
		"TopSide Panel dont exist.",
		0, //sol
		{ "", "" },
		0, //follow
		{ "", "", "", "", "", "", "" },
		1,
		{
			11, "Topside defect", //1
			10, "Board defect",   //2
			0, "",  //3
			0, "",  //4
			0, "",  //5
			0, "",  //6
			0, "",  //7
		},
		1,
		{
			11, "Topside", //1
			10, "Board",   //2
			0, "",  //3
			0, "",  //4
			0, "",  //5
			0, "",  //6
			0, "",  //7
		},
	}
};

//For total error cause (Reading)
struct Encode_Cause_Equpiment_type RPT_all_Cause[CUASE_RPT_TABLE_SIZE] = {
	0, "reserved",
	1, "Water temp sensor defect",
	2, "Hi-limit temp sensor defect",
	3, "Circ. Pump defect",
	4, "Fuse on board defect",
	5, "Pipe Blockage",
	6, "Dirty Filter",
	7, "Flow Switch defect",
	8, "UV light usage expired",
	9, "Filter Cartridge expired",
	10, "Board defect",
	11, "Topside defect",
	12, "Pump-1 Hi (wire) defect",
	13, "Pump-1 Lo (wire) defect",
	14, "Pump-2 Hi (wire) defect",
	15, "Pump-2 Lo (wire) defect",
	16, "Pump-3 Hi (wire) defect",
	17, "Pump-3 Lo (wire) defect",
	18, "Blower (wire) defect",
	19, "Circ. Pump + UV (wire) defect",
	20, "Heater (wire) defect"
};

struct Encode_Equpiment_type RPT_all_Equip[EQUIP_RPT_TABLE_SIZE] = {
	0, "Reserved", 0,
	1, "Water temp sensor", 9,
	2, "Hi-limit sensor", 10,
	3, "Circ. Pump", 4,
	4, "Fuse", 12,
	5, "Pipe",  15,
	6, "Filter cartridge", 14,
	7, "Flow Switch",  11,
	8, "UV light", 13,
	9, "Filter Cartridge", 14,
	10, "Board", 8,
	11, "Topside", 7,
	12, "Pump-1", 1,
	13, "Pump-1", 1,
	14, "Pump-2", 2,
	15, "Pump-2", 2,
	16, "Pump-3", 3,
	17, "Pump-3", 3,
	18, "Blower", 5,
	19, "Circ. Pump + UV light", 4,
	20, "Heater", 6,
};