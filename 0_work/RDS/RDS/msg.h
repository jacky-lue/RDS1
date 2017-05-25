//this file define all message incodes.
//excpt the Error emessage part.
//except some vriable related part.

//connect button
#define MSG_MAINFORM_CONNECT_UID_ERROR			"Wrong UID length. Please douebl-check."
#define MSG_MAINFORM_CONNECT_UID_FAIL			"Connection Fails. Please disconnect and reconnect again."

//Login button
#define MSG_MAINFORM_LOGIN_SAPMODEL_INI_ERR1	"Model_AD.ini file has data error. Application Abort."
#define MSG_MAINFORM_LOGIN_SAPMODEL_INI_ERR2	"Model_AD.ini file has format error. Application Abort."
#define MSG_MAINFORM_LOGIN_SAPMODEL_INI_ERR3	"Model_AD.ini file has ending error. Application Abort."
#define LOGIN_ERR_ALREADY_LOGINED				"User already login RDS.exe or RDSadmin.exe in another machine."
#define LOGIN_ERR_FILE_EXIST_BEF_LOCK			"Before produce lock file, another machine logined!!"
#define LOGIN_ERR_FILE_LOSS_BEF_UNLOCK			"Before delete lock file, file already loss !!!!"

//all button may happen
#define MSG_MAINFORM_NO_CONNECTION_HINT			"No connection, please try again."
#define MSG_MAINUI_ALL_CMD_LISTEN_TIMEOUT		"Listen Time out, please try again."

//error messages
#define MSG_MAINUI_70CMD_READ_TIMEOUT			"Time out when reading Spa EEPROM"

//DATE-TIME button
#define MSG_MAINFORM_DATETIME_CMD31_TIMEOUT		"Setting Date-Time 31H time out, please try again."
#define MSG_MAINFORM_DATETIME_OUT_RANGE			"Controller Date-Time Value is out of range, please try again."


//SF button
#define MSG_MAINFORM_SF_SCH_CMD36_TIMEOUT		"Setting SF schedule 36H time out, please try again."

//PF button
#define MSG_MAINFORM_PF_CMD35_TIMEOUT			"Setting PF schedule 35H time out, please try again."

//Filter schedule button
#define MSG_MAINFORM_FLT_SCH_CMD32_TIMEOUT		"Setting Filter schedule 32H time out, please try again."

//ECO Filter schedule button
#define MSG_MAINFORM_ECO_SCH_CMD33_TIMEOUT		"Setting ECO Filter schedule 33H time out, please try again."

//Service call button
#define MSG_MAINFORM_SERVICECALL_ALREADY_HAS	"Service call already generated."

//RDS report button
#define MSG_MAINFORM_RDSREPORT_NO_SPA_OWNER		"Blank Spa Owner, please enter it."
#define MSG_MAINFORM_RDSREPORT_NO_SPA_SERIAL	"Blank Spa Serial, please enter it."
#define MSG_MAINFORM_RDSREPORT_NO_AUTODIAGNOSIS	"No Auto-diagnostic is done, please double-check."
#define MSG_MAINRPT_UID_LENGTH_ERROR			"Wrong UID length."
#define MSG_MAINRPT_FILE_EXISTED_HINT			"Already has same report name, overwrite it."

//History button
#define MSG_MAINFORM_HISTORY_NO_UID_ERROR		"Blank UID. Please enter it."
#define MSG_MAINFORM_HISTORY_UID_FAIL_ERROR		"Wrong UID, or this UID has not serviced before. Please double-check."

//Auto-Diagnosis button
#define MSG_MAINFORM_AD_START_LINE				">>>>>>>>>>>>>>>>>>>>>>>>"
#define MSG_MAINFORM_AD_START_TEXT				"Auto-Diagnostic starts..."
#define MSG_MAINFORM_AD_CANNOT_START_TEXT		"Cannot run Auto-Diagnostic..."
#define MSG_BLK_OUT_CYC_AD_CANNOT_START_TEXT	"Cannot run Auto-Diagnostic, due to block out cycle, please wait..."
#define MSG_CLEAN_CYC_AD_CANNOT_START_TEXT		"Cannot run Auto-Diagnostic, due to clean cycle, please wait..."
#define MSG_MAINAD_AD_HINT_SAVE_SETTING			">> Save current setting..."
#define MSG_MAINAD_AD_HINT_SAVE_F_SCHEDULE		">> Save current filter schedule..."
#define MSG_MAINAD_AD_HINT_TRUN_OFF_ALL			">> Turn off all pumps & blowers..."
#define MSG_MAINAD_AD_HINT_TRUN_OFF_ALL_HC		">> Turn off all pumps / blowers..."
#define MSG_MAINAD_AD_HINT_TRUN_OFF_ALL_C		">> Turn off all pumps and blowers..."
#define MSG_MAINAD_AD_HINT_TURN_OFF_HEATER		">> Turn off heater..."
#define MSG_MAINAD_AD_HINT_WAIT_CIRC_OFF		">> Waiting 1 min for circulation off ..."
#define MSG_MAINAD_AD_HINT_WAIT_HEATER_ON		">> Turn on circulation and wait 1 min for heater on..."
#define MSG_MAINAD_AD_HINT_HEATER_ON_OKAY		">> Heater turns on..."
#define MSG_MAINAD_AD_HINT_RESTORE_SETTING		">> Restoring original setting..."
#define MSG_MAINAD_AD_HINT_RESTORE_F_SCHEDULE	">> Restoring original filter schedule..."
#define MSG_MAINAD_AD_HINT_M0_HC				">> Heater + CP + UV"
#define MSG_MAINAD_AD_HINT_M0_C					">> CP + UV"
#define MSG_MAINAD_AD_HINT_M0					">> all off"
#define MSG_MAINAD_AD_HINT_M1					">> Pump-1 Hi"
#define MSG_MAINAD_AD_HINT_M1_C					">> Pump-1 Hi + Circ + UV "
#define MSG_MAINAD_AD_HINT_M1_HC				">> Pump-1 Hi + Heater + Circ + UV "
#define MSG_MAINAD_AD_HINT_M2					">> Pump-1 Lo"
#define MSG_MAINAD_AD_HINT_M2_C					">> Pump-1 Lo + Circ + UV "
#define MSG_MAINAD_AD_HINT_M2_HC				">> Pump-1 Lo + Heater + Circ + UV "
#define MSG_MAINAD_AD_HINT_M3					">> Pump-2 Hi"
#define MSG_MAINAD_AD_HINT_M3_HC				">> Pump-2 Hi + Heater + Circ + UV "
#define MSG_MAINAD_AD_HINT_M4					">> Pump-2 Lo"
#define MSG_MAINAD_AD_HINT_M4_HC				">> Pump-2 Lo + Heater + Circ + UV "
#define MSG_MAINAD_AD_HINT_M5					">> Pump-3 Hi"
#define MSG_MAINAD_AD_HINT_M5_HC				">> Pump-3 Hi + Heater + Circ + UV "
#define MSG_MAINAD_AD_HINT_M6					">> Pump-3 Lo"
#define MSG_MAINAD_AD_HINT_M6_HC				">> Pump-3 Lo + Heater + Circ + UV "
#define MSG_MAINAD_AD_HINT_M7					">> Blower"
#define MSG_MAINAD_AD_HINT_M7_HC				">> Blower + Heater + Circ + UV "
#define MSG_MAINAD_AD_HINT_FINISHED				">>>>>>>>>>>>>>>>>>>>>>>>>>>> completed"
//
#define MSG_AD_MODEL_INDEX_WRONG				"Spa Model index is wrong, can not do current compare"
//

//
#define MSG_MAINAD_SET_TIME_CDM_TIMEOUT			"Auto-diagnosis process: set time=23:00 but time out!"
#define MSG_MAINAD_SET_SF0_CDM_TIMEOUT			"Auto-diagnosis process: set SF0 but time out!"
#define MSG_MAINAD_SET_PFOFF_CDM_TIMEOUT		"Auto-diagnosis process: set PF off but time out!"
#define MSG_MAINAD_TEMP_F_SCHEDULE_TIMEOUT		"Auto-diagnosis process: setup a temp Filter schedule but time out!"
#define MSG_MAINAD_SET_NOW_TIME_TIMEOUT			"Auto-diagnosis process: set now DateTime but time out!"
#define MSG_MAINAD_RESTORE_SF_TIMEOUT			"Auto-diagnosis process: restore SF but time out!"
#define MSG_MAINAD_RESTORE_PF_TIMEOUT			"Auto-diagnosis process: restore PF but time out!"
#define MSG_MAINAD_RESTORE_F_SCHEDULE_TIMEOUT	"Auto-diagnostic process: restore f-schedule but time out!"
//

//Error code related
#define MSG_MAINUI_ERRCODE_START_LINE			"============================================"
#define MSG_MAINUI_ERRCODE_CHANGE_HINT			">> Error Message changes: "
#define MSG_MAINUI_ERRCODE_ONE_CODE_START		"--------------------------------------"
#define MSG_MAINUI_ERRCODE_DEFINITION_HEADER	"Definition of error "
#define MSG_MAINUI_ERRCODE_SOLUTION_TITLE		"Solution"
#define MSG_MAINUI_ERRCODE_FOLLOWUP_TITLE		"Please follow below steps to troubleshoot error"
#define MSG_MAINUI_ERRCODE_CAUSE_TITLE			"Possible cause of error"
#define MSG_MAINUI_ERRCODE_EQUIPMENT_TITLE		"Equipment for on-site service"
#define MSG_MAINUI_ERRCODE_MUST_EQUIPEMNT		"Voltmeter / Ohmeter / Ammeter"

//------------
// set_UVday_form.cpp
#define MSG_UVDAYFORM_ERROR_NAGTIVE_NUMBER		"UV days should be a positive number."
#define MSG_UVDAYFORM_ERROR_OVER_MAX_NUMBER		"UV days inputed is higher than maximum value."
#define MSG_UVDAYFORM_ERROR_NOT_A_NUMBER		"String is not a number."

// set_Fltday_form.cpp
#define MSG_FLTDAYFORM_ERROR_NAGTIVE_NUMBER		"Filter days should be a positive number."
#define MSG_FLTDAYFORM_ERROR_OVER_MAX_NUMBER	"Filter days inputed is higher than maximum value."
#define MSG_FLTDAYFORM_ERROR_NOT_A_NUMBER		"String is not a number."


// set_T_form.cpp
#define MSG_SET_T_FORM_ERROR_LOWER_MIN_NUMBER	"Temperature is lower than minimum value."
#define MSG_SET_T_FORM_ERROR_OVER_MAX_NUMBER	"Temperature is higher than maximum value."
#define MSG_SET_T_FORM_ERROR_NOT_A_NUMBER		"String is not a number."

//rptDisp.cpp

//Login.cpp
#define MSG_LOGIN_SPA_COM_ADMIN_INI_NOT_FOUND	"Company Admin.ini file not found, please exit program."
#define MSG_LOGIN_SPA_COM_ADMIN_INI_FAILED		"Company Admin.ini file has a problem, please exit program."
#define MSG_LOGIN_ERR_USER_INI_FILE_NOT_FOUD	"Users.ini file not found. Please check your Z: driver content. Application Exits."
#define MSG_LOGIN_ERR_MODELAD_INI_FILE_NOT_FOUD	"Model_AD.ini file not found. Please check your Z: driver content. Application Exits."
#define MSG_LOGIN_ERR_NO_ACCOUNT				"Blank account ID, please enter it."
#define MSG_LOGIN_ERR_NO_PASSWORD				"Blank Password, please enter it."
#define MSG_LOGIN_ERR_USERID_NOT_FOUND			"User ID not found. Please double-check."
#define MSG_LOGIN_ERR_WRONG_PASSWORD			"User ID is correct, but password is wrong. Please double-check."
#define MSG_LOGIN_COMPANY_CODE_EMPTY			"Blank Company Code, please entry it."
#define MSG_LOGIN_COMPANY_CODE_NOT_VALID		"Company Code not valid, please double-chek."
#define MSG_LOGIN_DEALER_ADMIN_CORRUPTED		"Dealer company Admin.ini file corrupted, please double-check."

//HistoryForm.cpp
#define MSG_HISTORYFORM_UID_NOT_MATCH			"The UID in file does not match to filename's UID."
#define MSG_HISTORYFORM_NO_LIST_ITEMS			"Currently, no any RDS report files."
#define MSG_HISTORY_LOG_NO_LIST_ITEMS			"Currently, no any Log files."


//Open SC Form
#define MSG_OPENSCFORM_CLOSE_CONFIRM			"Are you sure you want to close this Open Service Call?"
#define MSG_OPENSCFORM_NO_LIST_ITEMS			"Currently, no any Open Service Calls."

//common
#define MSG_REPORT_CAUSE_NUMBER_OVER_RANGE		"Cause number NOT in Table, contact S/W provider."
#define MSG_REPORT_FILE_NOT_FOUND_ERROR			"File not found."
#define MSG_REPORT_MODELNAME_NOT_FOUND_ERROR	"Model Name not found. it may be old model. Use first modle setting..."



