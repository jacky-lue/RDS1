#include <windows.h>
#include <stdio.h>
#include <iomanip>
#include <sstream>

#include "msg.h"

//just for test (when release, MUST set 0 to DEBUGGING_USEAGE)
//     DEBUGGING_USEAGE == 1 : debug for Auto diagnosis
//     DEBUGGING_USEAGE == 2 : debug for RDS report
//     DEBUGGING_USEAGE == 3 : debug for initial sequence...
//     DEBUGGING_USEAGE == 4 : debug for Auto diagnosis Currents
#define DEBUGGING_USEAGE		1
//#define DEFAULT_UID_TEXT_INPUT	"FVC91WZP6JAUVN6PMXKJ"
//#define DEFAULT_UID_TEXT_INPUT	"CFCT1CYY7KUATN6PGX21"
#define DEFAULT_UID_TEXT_INPUT	"D3JT1SZP7CU29NPPMX6J"

//Main form
#define	VersionString		"Spa Remote Diagnostic & Service v1.02 ---"
#define EnginerModePW		"dart2015"

#define	WAIT_AFTER_IOT_READ		50       //for thread sleep, unit=ms
#define	WAIT_BEFORE_UI_UPDATE	50

#define	MAX_PACKETS_FOR_RETRY	10
#define	MAX_PACKETS_SECONDS		1
#define	CMD_LISTEN_RETRY_TIMES	3
#define	COMMAND_RESEND_TIMES	3

//set Temperature limit
#define SET_TEMP_C_MIN		18
#define SET_TEMP_C_MAX		40
#define SET_TEMP_F_MIN		65
#define SET_TEMP_F_MAX		104
#define SET_UV_DAYS_MAX		365
#define SET_FILTER_DAYS_MAX	180

//comment/replace area max lenght (unit= char)
#define RDS_COMMENT_MAX_CHARS			256
#define RDS_COMMENT_LENGTH_ERR_TEXT		"The length of Comment cannot be longer than 256..."
#define RDS_REPLACE_MAX_CHARS			256
#define RDS_REPLACE_LENGTH_ERR_TEXT		"The length of Comment cannot be longer than 256..."

//RDS- NAS setting
#define RDS_NAS_ROOT_DIR				"Z:\\RDS\\"

//for testing purpose....
//#define RDS_NAS_ROOT_DIR				"C:\\RDS\\"

#define RDS_NAS_ADMIN_FILENAME			"admin.ini"
#define RDS_NAS_USERLIST_FILENAME		"users.ini"
#define RDS_NAS_DEALER_LIST_FILENAME	"dealers.ini"
#define RDS_NAS_SPA_MODEL_FILENAME		"Model_AD.ini"
#define AD_SETTING_LINES_PER_MODEL		38
#define PART_NO_LINES_PER_MODEL			15
#define MAX_HOT_TUV_MODELS				3

//some default setting
#define DEFAULT_SPA_COM_NAME			"Not Initialed"
#define NO_DEALER_COM_CODE				"Code not existed."

//RDS directory structure in NAS
#define RDS_NAS_REPORT_DIR				"RPT\\"
#define RDS_NAS_SERVICE_DIR				"OSC\\"
#define RDS_NAS_CLOSE_DATE_DIR			"cDATE\\"
#define RDS_NAS_LOG_DIR					"LOG\\"
#define RDS_NAS_BY_UID_DIR				"UID\\"
#define RDS_NAS_BY_DATE_DIR				"DATE\\"
#define RDS_NAS_UID_SUBDIR_1ST_PART		4
#define RDS_UID_WHOLE_LENGTH			20

//for History (report/Log)
#define HIST_ITEMS_PER_PAGE				10

//for service-call display & richtextBoxs size/location
#define RDS_RICHTEXTBOX_LOCATION_1_X	507
#define RDS_RICHTEXTBOX_LOCATION_1_Y	275
#define RDS_RICHTEXTBOX_LOCATION_1_W	482
#define RDS_RICHTEXTBOX_LOCATION_1_H	412
//
#define RDS_RICHTEXTBOX_LOCATION_2_X	507
#define RDS_RICHTEXTBOX_LOCATION_2_Y	296
#define RDS_RICHTEXTBOX_LOCATION_2_W	482
#define RDS_RICHTEXTBOX_LOCATION_2_H	390
//
#define RDS_RICHTEXTBOX_LOCATION_3_X	507
#define RDS_RICHTEXTBOX_LOCATION_3_Y	318
#define RDS_RICHTEXTBOX_LOCATION_3_W	482
#define RDS_RICHTEXTBOX_LOCATION_3_H	370