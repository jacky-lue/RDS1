//this file define all message in codes.

#define FORM_LOAD_ADMIN_CORRUPTED		"Company Admin.ini file corrupted, please double-check."
#define FORM_LOAD_USERS_INI_LOST		"Users.ini file not found. Application Exits."
#define FORM_LOAD_DEALERS_INI_LOST		"No dealer list found."
#define FORM_LOAD_USERS_INI_LOST_WARN	"Users.ini file not found. please double-check."

#define SUPERVISOR_SECURITY_QUESTION_1  "What was your favorite place to visit as a child?"
#define SUPERVISOR_SECURITY_QUESTION_2  "In what city were you born?"
#define SUPERVISOR_SECURITY_QUESTION_3  "What is your father¡¦s middle name?"
#define SUPERVISOR_SECURITY_QUESTION_4  "What is your favorite actor, musician, or artist?"

//Login form------------------------
#define LOGIN_DRIVER_DIR_NOT_FOUND		"Driver or Directory not found (Z:\RDS\), please exit program."
#define LOGIN_MODEL_AD_INI_NOT_FOUND	"Model_AD.ini file not found, please re-install."
#define LOGIN_SPA_COM_ADMIN_NOT_FOUND	"Company Admin.ini file not found, use default account."
#define LOGIN_SPA_COM_ADMIN_CORRUPTED	"Company Admin.ini file corrupted, delete & use default account."
#define LOGIN_SPA_COM_USER_NOT_FOUND	"Company Users.ini file not found, use default account."
#define LOGIN_ADMIN_USERS_NOT_MATCH		"Admin.ini & Users.ini file not matched, please double-check."
#define LOGIN_DEALER_ADMIN_CORRUPTED	"Dealer company Admin.ini file corrupted, please double-check."
//
#define LOGIN_COMPANY_CODE_EMPTY		"Blank Company Code, please entry the 4-digit code."
#define LOGIN_COMPANY_CODE_LENGTH_ERR	"Wrong length of Company Code, please entry the 4-digit code."
#define LOGIN_COMPANY_CODE_NOT_VALID	"Company Code not Valid , please double-check."
#define LOGIN_NO_ACCOUNT_ID_INPUTED		"Blank account ID, please enter it."
#define LOGIN_NO_PASSWORD_INPUTED		"Blank password, please enter it."
#define LOGIN_ERR_USERID_NOT_FOUND		"User ID not found. Please double-check."
#define LOGIN_ERR_WRONG_PASSWORD		"User ID is correct, but password is wrong. Please double-check."
#define LOGIN_ERR_AUTHERORITY_FAIL		"User ID/PW are correct, but authority level not allowed."
#define LOGIN_ERR_ALREADY_LOGINED		"User already login RDS.exe or RDSadmin.exe in another machine."
#define LOGIN_ERR_FILE_EXIST_BEF_LOCK	"Before produce lock file, another machine logined!!"
#define LOGIN_ERR_FILE_LOSS_BEF_UNLOCK	"Before delete lock file, file already loss !!!!"
#define LOGIN_ERR_NO_PERSON_BEF_UNLOCK	"Before delete lock file, dont know who logined !!!!"
#define LOGIN_ERR_UNKNOW_RTN_FAIL		"User login failed with unknow error, please try again."
#define LOGIN_COMPANY_SQ_ANSWER_EMPTY	"Blank answer for security question. Please entry it."
//
#define LOGIN_FORGET_NO_ROOT_ADMIN_INI	"Admin.ini file not found in RDS root directory, Default ID=admin, PW=12345."

//Supervisor form -------------------
#define SUPERVISOR_SAVE_PW_EMPTY		"Blank password, please enter it."
#define SUPERVISOR_SAVE_PW_NOT_MATCH	"Re-enter Password mismatch, please try again."
#define SUPERVISOR_SAVE_NAME_EMPTY		"Blank Supervisor Name, please enter it."
#define SUPERVISOR_SAVE_NO_COMPANY_NAME	"Blank Company Name, please enter it."
#define SUPERVISOR_SAVE_ID_EMPTY		"Blank account ID, please enter it."
#define SUPERVISOR_SAVE_COM_CODE_EMPTY	"Blank Company Code, please enter it."
#define SUPERVISOR_SAVE_COM_CODE_FAIL	"Wrong length of Company Code. Please entry the 4-digit code."
#define SUPERVISOR_SAVE_ADMIN_OVERWRITE "Admin already exists, overwrite it?"
#define SUPERVISOR_SAVE_SQ_NOT_SETED	"Security question & answer not selected, please select."
#define SUPERVISOR_SAVE_MODIFY_OKAY		"Supervisor data modified and saved."
#define SUPERVISOR_SAVE_USERINI_WARNING "Has no admin.ini but users.ini exists. Please double-check."

//User List---------------------------
#define USER_LIST_NOT_DELETE_SUPERVISOR	"Cannot delete Supervisor account."
#define USER_LIST_DELETE_CONFIRMATION	"Are you sure to delete this user?"

//Add User ----------------------------
#define ADD_USER_NAME_FIELD_IS_EMPTY	"Blank user name, please enter it."
#define ADD_USER_ID_FIELD_IS_EMPTY		"Blank account ID, please enter it."
#define ADD_USER_PW_FIELD_IS_EMPTY		"Blank password, please enter it."
#define ADD_USER_AUTHORITY_IS_WRONG		"Wrong authority level, please double-check."
#define ADD_USER_SAVE_NEW_USER_OKAY		"A new user added and saved."
#define ADD_USER_SAVE_FAILE_SAME_ID		"This user ID already exists."

//User form (Edit/Save)
#define USER_FORM_AUTHORITY_IS_WRONG	"Wrong setting in use authority level, please double-check."
#define USER_SAVE_NAME_FIELD_IS_EMPTY	"Blank user name, please enter it."
#define USER_SAVE_ID_FIELD_IS_EMPTY		"Blank account ID, please enter it."
#define USER_SAVE_PW_FIELD_IS_EMPTY		"Blank password, please enter it."
#define USER_SAVE_AUTHORITY_IS_WRONG	"Wrong authority level, please double-check."

//Open service Call ------------------
#define SERVICE_CALL_CURRENT_NO_OSC		"No open service call exists."

//Add Dealer --------------------------
#define ADD_DEALER_SAVE_COM_CODE_EMPTY	"Blank Company Code, please enter the 4-digit code."
#define ADD_DEALER_SAVE_COM_CODE_FAIL	"Wrong length of Company Code, please double-check."
#define ADD_DEALER_SAVE_NO_COMPANY_NAME	"Blank Company Name, please enter it."
#define ADD_DEALER_SAVE_ZIP_CODE_EMPTY	"Blank state / ZIP Code, please enter it."
#define ADD_DEALER_SAVE_ZIP_CODE_FAIL	"State/ZIP Code should be 2 capital letters with 5-digit codes, please double-check."
#define ADD_DEALER_SAVE_NAME_EMPTY		"Blank Supervisor Name, please enter it."
#define ADD_DEALER_SAVE_ID_IS_EMPTY		"Blank account ID, please enter it."
#define ADD_DEALER_SAVE_PW_IS_EMPTY		"Blank password, please enter it."
#define ADD_DEALER_SAVE_PW_NOT_MATCH	"Re-enter Password mismatch, please double-chek."
#define ADD_DEALER_SAVE_SQ_NOT_SETED	"Security question & answer not selected, please select."
#define ADD_DEALER_SAVE_WRONG_BASE_DIR	"Not the root directory Z:\RDS\, only Spa company could add dealer!"
#define ADD_DEALER_SAVE_COM_CODE_SAME	"Company Code already exists, please double-check."
#define ADD_DEALER_SAVE_NEW_ADD_OKAY	"A new dealer is added and saved."
#define ADD_DEALER_SAVE_FAIL_SAME_ID	"Company Code already exists. Please try again."

//Dealer information ----------------
#define DEALER_DIR_ADMIN_CORRUPTED		"Delaer's  Admin.ini file corrupted, please double-check."
#define DEALER_ADMIN_INI_NOT_MATCH  	"Delaer information not match in Admin.ini file & Dealers.ini."
//
#define DEALER_SAVE_COM_CODE_EMPTY		"Blank Company Code, please enter the 4-digit code."
#define DEALER_SAVE_COM_CODE_FAIL		"Wrong length of Company Code, please double-check."
#define DEALER_SAVE_NO_COMPANY_NAME		"Blank Company Name, please enter it."
#define DEALER_SAVE_ZIP_CODE_EMPTY		"Blank state / ZIP Code, please enter it."
#define DEALER_SAVE_ZIP_CODE_FAIL		"State/ZIP Code should be 2 capial letters with 5-digit codes, please double-chek."
#define DEALER_SAVE_NAME_EMPTY			"Blank Supervisor Name, please enter it."
#define DEALER_SAVE_ID_IS_EMPTY			"Blank account ID, please enter it."
#define DEALER_SAVE_PW_IS_EMPTY			"No password inputed, please enter it."
#define DEALER_SAVE_PW_NOT_MATCH		"Re-enter Password mismatch, please double-check."
#define DEALER_SAVE_SQ_NOT_SETED		"Security question & answer not selected, please select."
#define DEALER_SAVE_WRONG_BASE_DIR		"Not the root directory Z:\RDS\, only Spa company could add dealers."
#define DEALER_SAVE_NEW_ADD_OKAY		"A new dealer is added and saved."
#define DEALER_SAVE_FAIL_SAME_ID		"Company Code already exists. Please try again."

//User List---------------------------
#define DEALER_LIST_DELETE_NO_SELECT	"Not select any dealer...."
#define DEALER_LIST_DELETE_NO_THIS		"Dealer information not found, please double-check."
#define DEALER_LIST_DELETE_CONFIRMATION	"Are you sure to delete this dealer? All related data will be deleted."

//RDS Brief/full report
#define RPT_LIST_ITEM_FILE_LOSTED		"file was found when listing, but cannot be found now."
#define RPT_DISP_CAUSE_INDEX_WRONG		"Cause number NOT in Table, contact S/W providor."
