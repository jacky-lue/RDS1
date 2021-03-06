//for RDS report Graphic related setting
#define RPT_BMP_PAGE_WIDTH		790        //default PageSize = 827 x1169
#define RPT_BMP_PAGEHEIGHT		1120
#define RPT_TITLE_FONT			"Cambria"
#define RPT_TITLE_FONTZISE		20
#define RPT_TITLE_HIEGHT		32
#define RPT_TITLE2_FONT			"Cambria"
#define RPT_TITLE2_FONTZISE		16
#define RPT_TITLE2_HIEGHT		24
#define RPT_CONTENT_FONT		"Cambria"
#define RPT_CONTENT_FONTZISE	12
#define RPT_CONTENT_HIEGHT		20
//
#define RPT_PAGE_TITLE_X		30
#define RPT_PAGE_TITLE_Y		30                                             //2016/03/07, original 50
#define RPT_PAGE_TITLE_W		RPT_BMP_PAGE_WIDTH - (2*RPT_PAGE_TITLE_X)
#define RPT_PAGE_TITLE_TEXT		"Remote Diagnostic Report"
//-------------------------------------------------------------------------------------------------- //2016/03/07, delete this line
//#define RPT_LINE1_X				30
//#define RPT_LINE1_Y				RPT_PAGE_TITLE_Y+RPT_TITLE_HIEGHT + 10
//#define RPT_LINE1_W				RPT_BMP_PAGE_WIDTH - (2*RPT_LINE1_X)
//--------------------------------------------------------------------------------------------------
//#define RPT_SUBTITLE1_X			30                                         //2016/03/07, delete this sub_title (reserved)
//#define RPT_SUBTITLE1_Y			RPT_LINE1_Y + 10
//#define RPT_SUBTITLE1_W			RPT_BMP_PAGE_WIDTH - (2*RPT_SUBTITLE1_X)
//#define RPT_SUBTITLE1_TEXT		"Information"
//
#define RPT_SUB1_LINE_1_X		30
//#define RPT_SUB1_LINE_1_Y		RPT_SUBTITLE1_Y + RPT_TITLE_HIEGHT             //2016/03/07, delete line & sub-title-1
#define RPT_SUB1_LINE_1_Y		RPT_PAGE_TITLE_Y+RPT_TITLE_HIEGHT + 10
#define RPT_SUB1_LINE_1_W		(RPT_BMP_PAGE_WIDTH - (2*RPT_SUB1_LINE_1_X))/2
#define RPT_SUB1_LINE1M_X		RPT_SUB1_LINE_1_X + RPT_SUB1_LINE_1_W -50 
#define RPT_SUB1_LINE1M_Y		RPT_SUB1_LINE_1_Y
#define RPT_SUB1_LINE1M_W		RPT_SUB1_LINE_1_W +50
//
#define RPT_SUB1_LINE_2_X		30
#define RPT_SUB1_LINE_2_Y		RPT_SUB1_LINE_1_Y + RPT_CONTENT_HIEGHT 
#define RPT_SUB1_LINE_2_W		(RPT_BMP_PAGE_WIDTH - (2*RPT_SUB1_LINE_2_X))/2 
#define RPT_SUB1_LINE2M_X		RPT_SUB1_LINE_2_X + RPT_SUB1_LINE_2_W -50
#define RPT_SUB1_LINE2M_Y		RPT_SUB1_LINE_2_Y
#define RPT_SUB1_LINE2M_W		RPT_SUB1_LINE_2_W +50
//
#define RPT_SUB1_LINE_3_X		30
#define RPT_SUB1_LINE_3_Y		RPT_SUB1_LINE_2_Y + RPT_CONTENT_HIEGHT 
#define RPT_SUB1_LINE_3_W		(RPT_BMP_PAGE_WIDTH - (2*RPT_SUB1_LINE_3_X))/2
#define RPT_SUB1_LINE3M_X		RPT_SUB1_LINE_3_X + RPT_SUB1_LINE_3_W -50
#define RPT_SUB1_LINE3M_Y		RPT_SUB1_LINE_3_Y
#define RPT_SUB1_LINE3M_W		RPT_SUB1_LINE_3_W +50
//
#define RPT_SUB1_LINE_4_X		30
#define RPT_SUB1_LINE_4_Y		RPT_SUB1_LINE_3_Y + RPT_CONTENT_HIEGHT 
#define RPT_SUB1_LINE_4_W		(RPT_BMP_PAGE_WIDTH - (2*RPT_SUB1_LINE_4_X))/2
#define RPT_SUB1_LINE4M_X		RPT_SUB1_LINE_4_X + RPT_SUB1_LINE_4_W -50
#define RPT_SUB1_LINE4M_Y		RPT_SUB1_LINE_4_Y
#define RPT_SUB1_LINE4M_W		RPT_SUB1_LINE_4_W +50
//                                                            
#define RPT_SUB1_LINE_5_X		30                                                //2016/03/07, Add this text-line for system errors
#define RPT_SUB1_LINE_5_Y		RPT_SUB1_LINE_4_Y + RPT_CONTENT_HIEGHT 
#define RPT_SUB1_LINE_5_W		(RPT_BMP_PAGE_WIDTH - (2*RPT_SUB1_LINE_5_X))/2
#define RPT_SUB1_LINE5M_X		RPT_SUB1_LINE_5_X + RPT_SUB1_LINE_5_W -50
#define RPT_SUB1_LINE5M_Y		RPT_SUB1_LINE_5_Y
#define RPT_SUB1_LINE5M_W		RPT_SUB1_LINE_5_W +50
//--------------------------------------------------------------------------------------------------
#define RPT_LINE2_X				30
//#define RPT_LINE2_Y				RPT_SUB1_LINE_4_Y + RPT_CONTENT_HIEGHT + 10   //2016/03/07, Add this text-line for system errors
#define RPT_LINE2_Y				RPT_SUB1_LINE_5_Y + RPT_CONTENT_HIEGHT + 10
#define RPT_LINE2_W				RPT_BMP_PAGE_WIDTH - (2*RPT_LINE2_X)
////--------------------------------------------------------------------------------------------------- 
//#define RPT_SUBTITLE2_L_X			30                                           //2016/03/07 Change to 3 (L,M,R) positions per line, and for 12 causes
//#define RPT_SUBTITLE2_L_Y			RPT_LINE2_Y + 10
//#define RPT_SUBTITLE2_L_W			(RPT_BMP_PAGE_WIDTH - (2*RPT_SUBTITLE2_L_X))/2
//#define RPT_SUBTITLE2_L_TEXT		"System Error"
////
//#define RPT_SUBTITLE2_R_X			30 + RPT_SUBTITLE2_L_W        
//#define RPT_SUBTITLE2_R_Y			RPT_LINE2_Y + 5
//#define RPT_SUBTITLE2_R_W			RPT_SUBTITLE2_L_W
//#define RPT_SUBTITLE2_R_TEXT		"Possible Root Cause"
////
//#define RPT_SUB2_LINE_1_X		30
//#define RPT_SUB2_LINE_1_Y		RPT_SUBTITLE2_L_Y + RPT_TITLE_HIEGHT
//#define RPT_SUB2_LINE_1_W		(RPT_BMP_PAGE_WIDTH - (2*RPT_SUB2_LINE_1_X))/2
//#define RPT_SUB2_LINE1M_X		RPT_SUB2_LINE_1_X + RPT_SUB2_LINE_1_W
//#define RPT_SUB2_LINE1M_Y		RPT_SUB2_LINE_1_Y
//#define RPT_SUB2_LINE1M_W		RPT_SUB2_LINE_1_W
////
//#define RPT_SUB2_LINE_2_X		30     
//#define RPT_SUB2_LINE_2_Y		RPT_SUB2_LINE_1_Y + RPT_CONTENT_HIEGHT
//#define RPT_SUB2_LINE_2_W		(RPT_BMP_PAGE_WIDTH - (2*RPT_SUB2_LINE_2_X))/2
//#define RPT_SUB2_LINE2M_X		RPT_SUB2_LINE_2_X + RPT_SUB2_LINE_2_W
//#define RPT_SUB2_LINE2M_Y		RPT_SUB2_LINE_2_Y
//#define RPT_SUB2_LINE2M_W		RPT_SUB2_LINE_2_W

//2016/03/07 Change to 3 (L,M,R) positions per line, and for 12 causes
//--------------------------------------------------------------------------------------------------
#define RPT_SUBTITLE2_X			30           
#define RPT_SUBTITLE2_Y			RPT_LINE2_Y + 10
#define RPT_SUBTITLE2_W			RPT_BMP_PAGE_WIDTH - (2*RPT_SUBTITLE2_X)
#define RPT_SUBTITLE2_TEXT		"Possible Root Cause"
//
#define RPT_SUB2_LINE_1_X		30
#define RPT_SUB2_LINE_1_Y		RPT_SUBTITLE2_Y + RPT_TITLE_HIEGHT
#define RPT_SUB2_LINE_1_W		(RPT_BMP_PAGE_WIDTH - (2*RPT_SUB2_LINE_1_X))/3
#define RPT_SUB2_LINE1M_X		RPT_SUB2_LINE_1_X + RPT_SUB2_LINE_1_W
#define RPT_SUB2_LINE1M_Y		RPT_SUB2_LINE_1_Y
#define RPT_SUB2_LINE1M_W		RPT_SUB2_LINE_1_W
#define RPT_SUB2_LINE1R_X		RPT_SUB2_LINE1M_X + RPT_SUB2_LINE_1_W
#define RPT_SUB2_LINE1R_Y		RPT_SUB2_LINE_1_Y
#define RPT_SUB2_LINE1R_W		RPT_SUB2_LINE_1_W
//
#define RPT_SUB2_LINE_2_X		30
#define RPT_SUB2_LINE_2_Y		RPT_SUB2_LINE_1_Y + RPT_CONTENT_HIEGHT
#define RPT_SUB2_LINE_2_W		(RPT_BMP_PAGE_WIDTH - (2*RPT_SUB2_LINE_1_X))/3
#define RPT_SUB2_LINE2M_X		RPT_SUB2_LINE_2_X + RPT_SUB2_LINE_2_W
#define RPT_SUB2_LINE2M_Y		RPT_SUB2_LINE_2_Y
#define RPT_SUB2_LINE2M_W		RPT_SUB2_LINE_2_W
#define RPT_SUB2_LINE2R_X		RPT_SUB2_LINE2M_X + RPT_SUB2_LINE_2_W
#define RPT_SUB2_LINE2R_Y		RPT_SUB2_LINE_2_Y
#define RPT_SUB2_LINE2R_W		RPT_SUB2_LINE_2_W
//
#define RPT_SUB2_LINE_3_X		30
#define RPT_SUB2_LINE_3_Y		RPT_SUB2_LINE_2_Y + RPT_CONTENT_HIEGHT
#define RPT_SUB2_LINE_3_W		(RPT_BMP_PAGE_WIDTH - (2*RPT_SUB2_LINE_1_X))/3
#define RPT_SUB2_LINE3M_X		RPT_SUB2_LINE_3_X + RPT_SUB2_LINE_3_W
#define RPT_SUB2_LINE3M_Y		RPT_SUB2_LINE_3_Y
#define RPT_SUB2_LINE3M_W		RPT_SUB2_LINE_3_W
#define RPT_SUB2_LINE3R_X		RPT_SUB2_LINE3M_X + RPT_SUB2_LINE_3_W
#define RPT_SUB2_LINE3R_Y		RPT_SUB2_LINE_3_Y
#define RPT_SUB2_LINE3R_W		RPT_SUB2_LINE_3_W
//
#define RPT_SUB2_LINE_4_X		30
#define RPT_SUB2_LINE_4_Y		RPT_SUB2_LINE_3_Y + RPT_CONTENT_HIEGHT
#define RPT_SUB2_LINE_4_W		(RPT_BMP_PAGE_WIDTH - (2*RPT_SUB2_LINE_1_X))/3
#define RPT_SUB2_LINE4M_X		RPT_SUB2_LINE_4_X + RPT_SUB2_LINE_4_W
#define RPT_SUB2_LINE4M_Y		RPT_SUB2_LINE_4_Y
#define RPT_SUB2_LINE4M_W		RPT_SUB2_LINE_4_W
#define RPT_SUB2_LINE4R_X		RPT_SUB2_LINE4M_X + RPT_SUB2_LINE_4_W
#define RPT_SUB2_LINE4R_Y		RPT_SUB2_LINE_4_Y
#define RPT_SUB2_LINE4R_W		RPT_SUB2_LINE_4_W
//--------------------------------------------------------------------------------------------------
#define RPT_LINE3_X				30
//#define RPT_LINE3_Y				RPT_SUB2_LINE_2_Y + RPT_CONTENT_HIEGHT + 10
#define RPT_LINE3_Y				RPT_SUB2_LINE_4_Y + RPT_CONTENT_HIEGHT + 10            //2016/03/07 change for 12 causes in sub-2
#define RPT_LINE3_W				RPT_BMP_PAGE_WIDTH - (2*RPT_LINE3_X)
//--------------------------------------------------------------------------------------------------
#define RPT_SUBTITLE3_X			30           
#define RPT_SUBTITLE3_Y			RPT_LINE3_Y + 10
#define RPT_SUBTITLE3_W			RPT_BMP_PAGE_WIDTH - (2*RPT_SUBTITLE3_X)
#define RPT_SUBTITLE3_TEXT		"Equipments for On-Site Service"

////  //2016/03/07 change to 3 position per line, total 12 Equipments
//#define RPT_SUB3_LINE_1_X		30
//#define RPT_SUB3_LINE_1_Y		RPT_SUBTITLE3_Y + RPT_TITLE_HIEGHT
//#define RPT_SUB3_LINE_1_W		(RPT_BMP_PAGE_WIDTH - (2*RPT_SUB3_LINE_1_X))/2
//#define RPT_SUB3_LINE1M_X		RPT_SUB3_LINE_1_X + RPT_SUB3_LINE_1_W
//#define RPT_SUB3_LINE1M_Y		RPT_SUB3_LINE_1_Y
//#define RPT_SUB3_LINE1M_W		RPT_SUB3_LINE_1_W
////
//#define RPT_SUB3_LINE_2_X		30
//#define RPT_SUB3_LINE_2_Y		RPT_SUB3_LINE_1_Y + RPT_CONTENT_HIEGHT
//#define RPT_SUB3_LINE_2_W		(RPT_BMP_PAGE_WIDTH - (2*RPT_SUB3_LINE_2_X))/2
//#define RPT_SUB3_LINE2M_X		RPT_SUB3_LINE_2_X + RPT_SUB3_LINE_2_W
//#define RPT_SUB3_LINE2M_Y		RPT_SUB3_LINE_2_Y
//#define RPT_SUB3_LINE2M_W		RPT_SUB3_LINE_2_W
////
//#define RPT_SUB3_LINE_3_X		30
//#define RPT_SUB3_LINE_3_Y		RPT_SUB3_LINE_2_Y + RPT_CONTENT_HIEGHT
//#define RPT_SUB3_LINE_3_W		(RPT_BMP_PAGE_WIDTH - (2*RPT_SUB3_LINE_3_X))/2
//#define RPT_SUB3_LINE3M_X		RPT_SUB3_LINE_3_X + RPT_SUB3_LINE_3_W
//#define RPT_SUB3_LINE3M_Y		RPT_SUB3_LINE_3_Y
//#define RPT_SUB3_LINE3M_W		RPT_SUB3_LINE_3_W
////
//#define RPT_SUB3_LINE_4_X		30
//#define RPT_SUB3_LINE_4_Y		RPT_SUB3_LINE_3_Y + RPT_CONTENT_HIEGHT
//#define RPT_SUB3_LINE_4_W		(RPT_BMP_PAGE_WIDTH - (2*RPT_SUB3_LINE_4_X))/2
//#define RPT_SUB3_LINE4M_X		RPT_SUB3_LINE_4_X + RPT_SUB3_LINE_4_W
//#define RPT_SUB3_LINE4M_Y		RPT_SUB3_LINE_4_Y
//#define RPT_SUB3_LINE4M_W		RPT_SUB3_LINE_4_W
////
//#define RPT_SUB3_LINE_5_X		30
//#define RPT_SUB3_LINE_5_Y		RPT_SUB3_LINE_4_Y + RPT_CONTENT_HIEGHT
//#define RPT_SUB3_LINE_5_W		(RPT_BMP_PAGE_WIDTH - (2*RPT_SUB3_LINE_5_X))/2
//#define RPT_SUB3_LINE5M_X		RPT_SUB3_LINE_5_X + RPT_SUB3_LINE_5_W
//#define RPT_SUB3_LINE5M_Y		RPT_SUB3_LINE_5_Y
//#define RPT_SUB3_LINE5M_W		RPT_SUB3_LINE_5_W

//2016/03/07 Add position per line, total 12 Equipments
#define RPT_SUB3_LINE_1_X		30
#define RPT_SUB3_LINE_1_Y		RPT_SUBTITLE3_Y + RPT_TITLE_HIEGHT
#define RPT_SUB3_LINE_1_W		(RPT_BMP_PAGE_WIDTH - (2*RPT_SUB3_LINE_1_X))/3
#define RPT_SUB3_LINE1M_X		RPT_SUB3_LINE_1_X + RPT_SUB3_LINE_1_W
#define RPT_SUB3_LINE1M_Y		RPT_SUB3_LINE_1_Y
#define RPT_SUB3_LINE1M_W		RPT_SUB3_LINE_1_W
#define RPT_SUB3_LINE1R_X		RPT_SUB3_LINE1M_X + RPT_SUB3_LINE_1_W
#define RPT_SUB3_LINE1R_Y		RPT_SUB3_LINE_1_Y
#define RPT_SUB3_LINE1R_W		RPT_SUB3_LINE_1_W
//
#define RPT_SUB3_LINE_2_X		30
#define RPT_SUB3_LINE_2_Y		RPT_SUB3_LINE_1_Y + RPT_CONTENT_HIEGHT
#define RPT_SUB3_LINE_2_W		(RPT_BMP_PAGE_WIDTH - (2*RPT_SUB3_LINE_1_X))/3
#define RPT_SUB3_LINE2M_X		RPT_SUB3_LINE_2_X + RPT_SUB3_LINE_2_W
#define RPT_SUB3_LINE2M_Y		RPT_SUB3_LINE_2_Y
#define RPT_SUB3_LINE2M_W		RPT_SUB3_LINE_2_W
#define RPT_SUB3_LINE2R_X		RPT_SUB3_LINE2M_X + RPT_SUB3_LINE_2_W
#define RPT_SUB3_LINE2R_Y		RPT_SUB3_LINE_2_Y
#define RPT_SUB3_LINE2R_W		RPT_SUB3_LINE_2_W
//
#define RPT_SUB3_LINE_3_X		30
#define RPT_SUB3_LINE_3_Y		RPT_SUB3_LINE_2_Y + RPT_CONTENT_HIEGHT
#define RPT_SUB3_LINE_3_W		(RPT_BMP_PAGE_WIDTH - (2*RPT_SUB3_LINE_1_X))/3
#define RPT_SUB3_LINE3M_X		RPT_SUB3_LINE_3_X + RPT_SUB3_LINE_3_W
#define RPT_SUB3_LINE3M_Y		RPT_SUB3_LINE_3_Y
#define RPT_SUB3_LINE3M_W		RPT_SUB3_LINE_3_W
#define RPT_SUB3_LINE3R_X		RPT_SUB3_LINE3M_X + RPT_SUB3_LINE_3_W
#define RPT_SUB3_LINE3R_Y		RPT_SUB3_LINE_3_Y
#define RPT_SUB3_LINE3R_W		RPT_SUB3_LINE_3_W
//
#define RPT_SUB3_LINE_4_X		30
#define RPT_SUB3_LINE_4_Y		RPT_SUB3_LINE_3_Y + RPT_CONTENT_HIEGHT
#define RPT_SUB3_LINE_4_W		(RPT_BMP_PAGE_WIDTH - (2*RPT_SUB3_LINE_1_X))/3
#define RPT_SUB3_LINE4M_X		RPT_SUB3_LINE_4_X + RPT_SUB3_LINE_4_W
#define RPT_SUB3_LINE4M_Y		RPT_SUB3_LINE_4_Y
#define RPT_SUB3_LINE4M_W		RPT_SUB3_LINE_4_W
#define RPT_SUB3_LINE4R_X		RPT_SUB3_LINE4M_X + RPT_SUB3_LINE_4_W
#define RPT_SUB3_LINE4R_Y		RPT_SUB3_LINE_4_Y
#define RPT_SUB3_LINE4R_W		RPT_SUB3_LINE_4_W


//--------------------------------------------------------------------------------------------------
#define RPT_LINE4_X				30
//#define RPT_LINE4_Y				RPT_SUB3_LINE_5_Y + RPT_CONTENT_HIEGHT + 10  //2016/03/07 change to total 12 Equipments
#define RPT_LINE4_Y				RPT_SUB3_LINE_4_Y + RPT_CONTENT_HIEGHT + 10
#define RPT_LINE4_W				RPT_BMP_PAGE_WIDTH - (2*RPT_LINE4_X)
//--------------------------------------------------------------------------------------------------
#define RPT_SUBTITLE4_X			30           
#define RPT_SUBTITLE4_Y			RPT_LINE4_Y + 10
#define RPT_SUBTITLE4_W			RPT_BMP_PAGE_WIDTH - (2*RPT_SUBTITLE4_X)
#define RPT_SUBTITLE4_TEXT		"Trouble Log Reading"
//
#define RPT_SUB4_LINE_1_X		30
#define RPT_SUB4_LINE_1_Y		RPT_SUBTITLE4_Y + RPT_TITLE_HIEGHT
#define RPT_SUB4_LINE_1_W		(RPT_BMP_PAGE_WIDTH - (2*RPT_SUB4_LINE_1_X))/3
#define RPT_SUB4_LINE1M_X		RPT_SUB4_LINE_1_X + RPT_SUB4_LINE_1_W
#define RPT_SUB4_LINE1M_Y		RPT_SUB4_LINE_1_Y
#define RPT_SUB4_LINE1M_W		RPT_SUB4_LINE_1_W
#define RPT_SUB4_LINE1R_X		RPT_SUB4_LINE1M_X + RPT_SUB4_LINE_1_W
#define RPT_SUB4_LINE1R_Y		RPT_SUB4_LINE_1_Y
#define RPT_SUB4_LINE1R_W		RPT_SUB4_LINE_1_W
//
#define RPT_SUB4_LINE_2_X		30
#define RPT_SUB4_LINE_2_Y		RPT_SUB4_LINE_1_Y + RPT_CONTENT_HIEGHT
#define RPT_SUB4_LINE_2_W		(RPT_BMP_PAGE_WIDTH - (2*RPT_SUB4_LINE_1_X))/3
#define RPT_SUB4_LINE2M_X		RPT_SUB4_LINE_2_X + RPT_SUB4_LINE_2_W
#define RPT_SUB4_LINE2M_Y		RPT_SUB4_LINE_2_Y
#define RPT_SUB4_LINE2M_W		RPT_SUB4_LINE_2_W
#define RPT_SUB4_LINE2R_X		RPT_SUB4_LINE2M_X + RPT_SUB4_LINE_2_W
#define RPT_SUB4_LINE2R_Y		RPT_SUB4_LINE_2_Y
#define RPT_SUB4_LINE2R_W		RPT_SUB4_LINE_2_W
//
#define RPT_SUB4_LINE_3_X		30
#define RPT_SUB4_LINE_3_Y		RPT_SUB4_LINE_2_Y + RPT_CONTENT_HIEGHT
#define RPT_SUB4_LINE_3_W		(RPT_BMP_PAGE_WIDTH - (2*RPT_SUB4_LINE_1_X))/3
#define RPT_SUB4_LINE3M_X		RPT_SUB4_LINE_3_X + RPT_SUB4_LINE_3_W
#define RPT_SUB4_LINE3M_Y		RPT_SUB4_LINE_3_Y
#define RPT_SUB4_LINE3M_W		RPT_SUB4_LINE_3_W
#define RPT_SUB4_LINE3R_X		RPT_SUB4_LINE3M_X + RPT_SUB4_LINE_3_W
#define RPT_SUB4_LINE3R_Y		RPT_SUB4_LINE_3_Y
#define RPT_SUB4_LINE3R_W		RPT_SUB4_LINE_3_W
//
#define RPT_SUB4_LINE_4_X		30
#define RPT_SUB4_LINE_4_Y		RPT_SUB4_LINE_3_Y + RPT_CONTENT_HIEGHT
#define RPT_SUB4_LINE_4_W		(RPT_BMP_PAGE_WIDTH - (2*RPT_SUB4_LINE_1_X))/3
#define RPT_SUB4_LINE4M_X		RPT_SUB4_LINE_4_X + RPT_SUB4_LINE_4_W
#define RPT_SUB4_LINE4M_Y		RPT_SUB4_LINE_4_Y
#define RPT_SUB4_LINE4M_W		RPT_SUB4_LINE_4_W
#define RPT_SUB4_LINE4R_X		RPT_SUB4_LINE4M_X + RPT_SUB4_LINE_4_W
#define RPT_SUB4_LINE4R_Y		RPT_SUB4_LINE_4_Y
#define RPT_SUB4_LINE4R_W		RPT_SUB4_LINE_4_W
//--------------------------------------------------------------------------------------------------
#define RPT_LINE5_X				30
#define RPT_LINE5_Y				RPT_SUB4_LINE_4_Y + RPT_CONTENT_HIEGHT + 10
#define RPT_LINE5_W				RPT_BMP_PAGE_WIDTH - (2*RPT_LINE5_X)
//--------------------------------------------------------------------------------------------------
#define RPT_SUBTITLE5_X			30           
#define RPT_SUBTITLE5_Y			RPT_LINE5_Y + 10
#define RPT_SUBTITLE5_W			RPT_BMP_PAGE_WIDTH - (2*RPT_SUBTITLE5_X)
#define RPT_SUBTITLE5_TEXT		"Auto Diagnosis"
//
#define RPT_SUB5_LINE_1_X		30
#define RPT_SUB5_LINE_1_Y		RPT_SUBTITLE5_Y + RPT_TITLE_HIEGHT
#define RPT_SUB5_LINE_1_W		(RPT_BMP_PAGE_WIDTH - (2*RPT_SUB5_LINE_1_X))/2
#define RPT_SUB5_LINE1M_X		RPT_SUB5_LINE_1_X + RPT_SUB5_LINE_1_W
#define RPT_SUB5_LINE1M_Y		RPT_SUB5_LINE_1_Y
#define RPT_SUB5_LINE1M_W		RPT_SUB5_LINE_1_W
//
#define RPT_SUB5_LINE_2_X		30
#define RPT_SUB5_LINE_2_Y		RPT_SUB5_LINE_1_Y + RPT_CONTENT_HIEGHT
#define RPT_SUB5_LINE_2_W		(RPT_BMP_PAGE_WIDTH - (2*RPT_SUB5_LINE_2_X))/2
#define RPT_SUB5_LINE2M_X		RPT_SUB5_LINE_2_X + RPT_SUB5_LINE_2_W
#define RPT_SUB5_LINE2M_Y		RPT_SUB5_LINE_2_Y
#define RPT_SUB5_LINE2M_W		RPT_SUB5_LINE_2_W
//
#define RPT_SUB5_LINE_3_X		30
#define RPT_SUB5_LINE_3_Y		RPT_SUB5_LINE_2_Y + RPT_CONTENT_HIEGHT
#define RPT_SUB5_LINE_3_W		(RPT_BMP_PAGE_WIDTH - (2*RPT_SUB5_LINE_3_X))/2
#define RPT_SUB5_LINE3M_X		RPT_SUB5_LINE_3_X + RPT_SUB5_LINE_3_W
#define RPT_SUB5_LINE3M_Y		RPT_SUB5_LINE_3_Y
#define RPT_SUB5_LINE3M_W		RPT_SUB5_LINE_3_W
//
#define RPT_SUB5_LINE_4_X		30
#define RPT_SUB5_LINE_4_Y		RPT_SUB5_LINE_3_Y + RPT_CONTENT_HIEGHT
#define RPT_SUB5_LINE_4_W		(RPT_BMP_PAGE_WIDTH - (2*RPT_SUB5_LINE_4_X))/2
#define RPT_SUB5_LINE4M_X		RPT_SUB5_LINE_4_X + RPT_SUB5_LINE_4_W
#define RPT_SUB5_LINE4M_Y		RPT_SUB5_LINE_4_Y
#define RPT_SUB5_LINE4M_W		RPT_SUB5_LINE_4_W
//
#define RPT_SUB5_LINE_5_X		30
#define RPT_SUB5_LINE_5_Y		RPT_SUB5_LINE_4_Y + RPT_CONTENT_HIEGHT
#define RPT_SUB5_LINE_5_W		(RPT_BMP_PAGE_WIDTH - (2*RPT_SUB5_LINE_5_X))/2
#define RPT_SUB5_LINE5M_X		RPT_SUB5_LINE_5_X + RPT_SUB5_LINE_5_W
#define RPT_SUB5_LINE5M_Y		RPT_SUB5_LINE_5_Y
#define RPT_SUB5_LINE5M_W		RPT_SUB5_LINE_5_W
//--------------------------------------------------------------------------------------------------
#define RPT_LINE6_X				30
#define RPT_LINE6_Y				RPT_SUB5_LINE_5_Y + RPT_CONTENT_HIEGHT + 10
#define RPT_LINE6_W				RPT_BMP_PAGE_WIDTH - (2*RPT_LINE6_X)
//--------------------------------------------------------------------------------------------------
#define RPT_SUBTITLE6_X			30           
#define RPT_SUBTITLE6_Y			RPT_LINE6_Y + 10
#define RPT_SUBTITLE6_W			RPT_BMP_PAGE_WIDTH - (2*RPT_SUBTITLE6_X)
#define RPT_SUBTITLE6_TEXT		"Comment from Customer Represent"
//
#define RPT_SUB6_LINE_1_X		30
#define RPT_SUB6_LINE_1_Y		RPT_SUBTITLE6_Y + RPT_TITLE_HIEGHT
#define RPT_SUB6_LINE_1_W		RPT_BMP_PAGE_WIDTH - (2*RPT_SUB6_LINE_1_X)
//
#define RPT_SUB6_LINE_2_X		30
#define RPT_SUB6_LINE_2_Y		RPT_SUB6_LINE_1_Y + RPT_CONTENT_HIEGHT
#define RPT_SUB6_LINE_2_W		RPT_BMP_PAGE_WIDTH - (2*RPT_SUB6_LINE_2_X)
//
#define RPT_SUB6LINE_MAX_CHARS	77
//--------------------------------------------------------------------------------------------------
#define RPT_LINE7_X				30
#define RPT_LINE7_Y				RPT_SUB6_LINE_2_Y + RPT_CONTENT_HIEGHT + 10
#define RPT_LINE7_W				RPT_BMP_PAGE_WIDTH - (2*RPT_LINE7_X)
//--------------------------------------------------------------------------------------------------
#define RPT_SUB7_CONTENT_LINES	2
#define RPT_SUB7_SPACE1_H		100
#define RPT_SUB7_SPACE2_H		30
//--------------------------------------------------------------------------------------------------
#define RPT_SUB7_REC_X			50
#define RPT_SUB7_REC_Y			RPT_LINE7_Y + 20
#define RPT_SUB7_REC_W			RPT_BMP_PAGE_WIDTH - (2*RPT_SUB7_REC_X)
#define RPT_SUB7_REC_H			(RPT_TITLE_HIEGHT+20)+(RPT_CONTENT_HIEGHT*RPT_SUB7_CONTENT_LINES)+RPT_SUB7_SPACE1_H+RPT_SUB7_SPACE2_H
//--------------------------------------------------------------------------------------------------
#define RPT_SUBTITLE7_X			100           
#define RPT_SUBTITLE7_Y			RPT_SUB7_REC_Y + 10
#define RPT_SUBTITLE7_W			RPT_BMP_PAGE_WIDTH - (2*RPT_SUBTITLE7_X)
#define RPT_SUBTITLE7_TEXT		"Note"
//
#define RPT_SUB7_LINE_1_X		100
#define RPT_SUB7_LINE_1_Y		RPT_SUBTITLE7_Y + RPT_TITLE_HIEGHT + 10
#define RPT_SUB7_LINE_1_W		(RPT_BMP_PAGE_WIDTH - (2*RPT_SUB7_LINE_1_X))/2
#define RPT_SUB7_LINE1M_X		RPT_SUB7_LINE_1_X + RPT_SUB7_LINE_1_W
#define RPT_SUB7_LINE1M_Y		RPT_SUB7_LINE_1_Y
#define RPT_SUB7_LINE1M_W		RPT_SUB7_LINE_1_W
//
#define RPT_SUB7_LINE_2_X		100
#define RPT_SUB7_LINE_2_Y		RPT_SUB7_LINE_1_Y + RPT_CONTENT_HIEGHT + RPT_SUB7_SPACE1_H
#define RPT_SUB7_LINE_2_W		(RPT_BMP_PAGE_WIDTH - (2*RPT_SUB7_LINE_2_X))/2
#define RPT_SUB7_LINE2M_X		RPT_SUB7_LINE_2_X + RPT_SUB7_LINE_2_W
#define RPT_SUB7_LINE2M_Y		RPT_SUB7_LINE_2_Y
#define RPT_SUB7_LINE2M_W		RPT_SUB7_LINE_2_W


//----------------------------------------------------------------------------
//Others
#define RPT_NOTE_FIELD_1L		"Parts Replaced:"
#define RPT_NOTE_FIELD_2L		"Service Technician:"
#define RPT_NOTE_FIELD_1R		"Comment:"
#define RPT_NOTE_FIELD_2R		"Service Date:"



//================= Ed of file ======================