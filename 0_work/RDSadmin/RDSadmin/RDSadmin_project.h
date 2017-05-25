#include <windows.h>
#include <stdio.h>
#include <iomanip>
#include <sstream>

#include "msg.h"

//RDS- NAS setting ---------------------------------------------------
#define RDS_NAS_DRIVER				"Z:\\"
#define RDS_NAS_ROOT_DIR			"Z:\\RDS\\"
//for testing purpose....
//#define RDS_NAS_ROOT_DIR			"C:\\RDS\\"

//For Spa Company MIS administrator
//default account
#define DEFAULT_ADMIN_LOGIN_ID		"admin"
#define DEFAULT_ADMIN_LOGIN_PW		"12345"
#define DEFAULT_ADMIN_LOGIN_NAME	"Not Initialed"
#define DEFAULT_ADMIN_LOGIN_ALEVEL	"Supervisor"
#define DEFAULT_ADMIN_SQ_INDEX		0
#define DEFAULT_ADMIN_SQ_ANSWER		"My Home"
#define DEFAULT_SPA_COM_CODE		"0000"
#define DEFAULT_SPA_COM_NAME		"Not Initialed"
#define NO_DEALER_COM_CODE			"Code not found."

//Company Code definition
#define RDS_NAS_COM_CODE_LENGTH		4

//State/Zip code definition
#define RDS_NAS_ZIP_CODE_LENGTH		7
#define RDS_NAS_ZIP_LEADING_CHAR	2

//Authority Level Strings
#define RDS_NAS_AUTHORITY_LEVEL_0	"Supervisor"
#define RDS_NAS_AUTHORITY_LEVEL_1	"Manager"
#define RDS_NAS_AUTHORITY_LEVEL_2	"C.R."
#define RDS_NAS_AUTHORITY_LEVEL_3	"Engineer"

//setting file file names
#define RDS_NAS_ADMIN_FILENAME			"admin.ini"
#define RDS_NAS_USERLIST_FILENAME		"users.ini"
#define RDS_NAS_USERLIST2_FILENAME		"user2.ini"
#define RDS_NAS_DEALER_LIST_FILENAME	"dealers.ini"
#define RDS_NAS_DEALERLIST2_FILENAME	"dealer2.ini"
#define RDS_NAS_SPA_MODEL_FILENAME		"Model_AD.ini"

//RDS directory structure
#define RDS_NAS_REPORT_DIR			"RPT\\"
#define RDS_NAS_SERVICE_DIR			"OSC\\"
#define RDS_NAS_CLOSE_DATE_DIR		"cDATE\\"
#define RDS_NAS_LOG_DIR				"LOG\\"
#define RDS_NAS_BY_UID_DIR			"UID\\"
#define RDS_NAS_BY_DATE_DIR			"DATE\\"
#define RDS_NAS_UID_SUBDIR_1ST_PART	4