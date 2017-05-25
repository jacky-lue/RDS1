#ifndef USE_RDS_AUTO_DIAGNOSIS_HEADER

#define USE_RDS_AUTO_DIAGNOSIS_HEADER		1

//display Auto-diagnosis process hint or not
#define DISP_AUTO_DIAGNOSIS_HINT		1

//setting the waiting times (how many runing display/diahnosis)
#define RDS_AUTO_DIAGNOSIS_WAIT_C		18
#define RDS_AUTO_DIAGNOSIS_WAIT_M		20
#define RDS_AUTO_DIAGNOSIS_WAIT_F		30
#define RDS_AUTO_DIAGNOSIS_WAIT_M_CR	40
#define RDS_AUTO_DIAGNOSIS_WAIT_M_WCR	25

//for change spa date-time scheduel
#define RDS_AD_WORKING_DATE_TIME_H		23
#define RDS_AD_WORKING_DATE_TIME_M		0
#define RDS_AD_WORK_STD_PF_FSCH_ST_H	3
#define RDS_AD_WORK_STD_PF_FSCH_ST_M	0
#define RDS_AD_WORK_STD_PF_FSCH_DT_H	0
#define RDS_AD_WORK_STD_PF_FSCH_DT_M	0

//for AD to change set-temperature
#define RDS_AD_INC_DEC_TEMPATURE_F		3



//for M0~~ M7 current measure-result judgement 
//#define RDS_AD_M0_MAX_HT_CR_UV	30        //Heater + Circ + UV
//#define RDS_AD_M0_MIN_HT_CR_UV	5
//#define RDS_AD_M0_MAX_CR_UV		5         //Circ + UV
//#define RDS_AD_M0_MIN_CR_UV		1
//#define RDS_AD_M0_MAX			2         //all off
//#define RDS_AD_M0_MIN			0
//#define RDS_AD_M1_MAX			10        //P1-Hi
//#define RDS_AD_M1_MIN			2
//#define RDS_AD_M1_CV_MAX		10        //P1-Hi + circ + UV
//#define RDS_AD_M1_CV_MIN		2
//#define RDS_AD_M1_HCV_MAX		30        //P1-Hi + Heater + circ + UV
//#define RDS_AD_M1_HCV_MIN		2
//#define RDS_AD_M2_MAX			10        //P1-Lo
//#define RDS_AD_M2_MIN			2
//#define RDS_AD_M2_CV_MAX		10        //P1-Lo + Circ + UV
//#define RDS_AD_M2_CV_MIN		2
//#define RDS_AD_M2_HCV_MAX		30        //P1-Lo + Heater + Circ + UV
//#define RDS_AD_M2_HCV_MIN		2
//#define RDS_AD_M3_MAX			20        //P2-Hi
//#define RDS_AD_M3_MIN			2
//#define RDS_AD_M3_HCV_MAX		30        //P2-Hi + Heater + Circ +UV
//#define RDS_AD_M3_HCV_MIN		2
//#define RDS_AD_M4_MAX			10         //P2-Lo
//#define RDS_AD_M4_MIN			2
//#define RDS_AD_M4_HCV_MAX		30        //P2-Lo  + Heater + Circ +UV
//#define RDS_AD_M4_HCV_MIN		2
//#define RDS_AD_M5_MAX			10        //P3-Hi
//#define RDS_AD_M5_MIN			2
//#define RDS_AD_M5_HCV_MAX		30        //P3-Hi  + Heater + Circ +UV
//#define RDS_AD_M5_HCV_MIN		2
//#define RDS_AD_M6_MAX			5         //P3-Lo
//#define RDS_AD_M6_MIN			2
//#define RDS_AD_M6_HCV_MAX		30        //P3-Lo  + Heater + Circ +UV
//#define RDS_AD_M6_HCV_MIN		2
//#define RDS_AD_M7_MAX			5         //Blower
//#define RDS_AD_M7_MIN			0
//#define RDS_AD_M7_HCV_MAX		30        //Blower + Heater + Circ +UV
//#define RDS_AD_M7_HCV_MIN		2

enum AD_State {
	S_idel,
	S_setDT0,    //-----------(1)
	C_setDT0,
	S_mode,
	C_mode,      
	S_saveSF,  //Lo-end f-sch
	C_saveSF,
	S_setSF,
	C_setSF,
	S_savePF,
	C_savePF,
	S_setPF,
	C_setPF,
	S_saveFsch, //Hi-end f-sch
	C_saveFsch,
	S_setFsch,
	C_setFsch,
	S_HC_all_off,  //-----------(3)
	C_HC_all_off,
	M_HC_all_off,
	S_HeatOff,     //---------- (4)
	C_HeatOff,
	M_HeatOff_CircOnly,
	W_CircOff,
	S0_all_off,    //---------- (5)
	C0_all_off,
	M0_all_off,
	S1_P1_hi,
	C1_P1_hi,
	M1_P1_hi,
	M1off,
	M1AC,
	S2_P1_lo,
	C2_P1_lo,
	M2_P1_lo,
	M2off,
	M2AC,
	S3_P2_hi,
	C3_P2_hi,
	M3_P2_hi,
	M3off,
	M3AC,
	S4_P2_lo,
	C4_P2_lo,
	M4_P2_lo,
	M4off,
	M4AC,
	S5_P3_hi,
	C5_P3_hi,
	M5_P3_hi,
	M5off,
	M5AC,
	S6_P3_lo,
	C6_P3_lo,
	M6_P3_lo,
	M6off,
	M6AC,
	S7_blower,
	C7_blower,
	M7_blower,
	M7off,
	M7AC,
	S_HeatOn,     //---------- (6)(7) /////////////////////////
	C_HeatOn_CircOnly,
	M_HeatOn_CircOnly,
	W_HeatON_CircOn,
	M_HeatOn_CircOn,
	S_Over,   //-------------- (8)
	C_Over,
	S_Over_SetLK,
	C_Over_SetLK,
	S_Over_SetT,
	C_Over_SetT,
	S_setDTnow,
	C_setDTnow,
	S_bkSF,
	C_bkSF,
	S_bkPF,
	C_bkPF,
	S_bkFsch,
	C_bkFsch,
	S_Over_end,
};

#endif