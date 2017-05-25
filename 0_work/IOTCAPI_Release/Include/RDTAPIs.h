
/**====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*

RDTAPIs.h

Copyright (c) 2010 by TUTK Co.LTD. All Rights Reserved.
*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*/

/**===========================================================================

Revisions of RDTAPIs.h
Version  		Name       	Date			Description
0.1  			Joshua	  	03/29/2011		 Trial Version
0.1.1.0			Kevin		06/07/2011		Workable Version
0.1.2.0			Kevin		2011-06-30		Adapt to IOTC multi-channel session mechanism
1.0.0.0			Kevin		2011-07-12		Formal version, stability testing
1.1.0.0	  Charlie & Kevin	2011-08-29		New formal version, can't be compatible with below version 1.1.0.0
1.2.0.0	  		Kevin		2011-10-03		Add : 1.RDTInfo_t struct member "ErrorCode" to report IOTC session error 2.RDT_Status_Check() to know timeout status etc. Fix Bug : ___ListItem_SendList_RemovebyType() function will cause double free or use memory already be freed. Improve : destroy procedure no need to wait until timeout
1.3.0.0			Kevin		2011-11-15		Add : Control network flow to fit bandwidth dynamically. Improve : when RDT_Destroy() call set timeout to 2 sec.
1.3.1.0			Kevin		2011-11-28		Fix Bug : RDT_Destroy() not add ID will cause ack to remove wrong packet. Improve : Send data via internet have good performance.
1.3.2.0			Kevin		2011-12-19		Fix Bug : RDT_Destroy() not release RDT_ID. Add : 1.Big-endian SOC suport. Improve : 1.Send data via Lan have good performance. 2.Reduce CPU usage.
1.3.3.0			Kevin		2012-02-04		Fix Bug : 1.Floating exception when WAN mode. 2.Access NULL pointer in send thread when WAN mode. 3.BufSizeInSendQueue info error.
*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*/

#ifndef _RDTAPIs_joshua_H_
#define _RDTAPIs_joshua_H_

#include "platform_Config.h"

#ifdef IOTC_Win32
#ifdef RDTAPIs_EXPORTS
#define RDTAPI_API __declspec(dllexport)
#else
#define RDTAPI_API __declspec(dllimport)
#endif
#endif ////#ifdef IOTC_Win32

#ifdef IOTC_ARC_HOPE312
	#define RDTAPI_API 
#endif ////#ifdef IOTC_ARC_HOPE312

#ifdef IOTC_Linux
#define RDTAPI_API 
#endif ////#ifdef IOTC_Linux


#ifdef __cplusplus
extern "C" {
#endif //__cplusplus

struct st_RDT_Status{
	unsigned short Timeout;  //Keepalive timeout for how many seconds
	unsigned short TimeoutThreshold;  //when timeout reach this value will break RDT connection
	unsigned long BufSizeInSendQueue; //byte
	unsigned long BufSizeInRecvQueue; //byte
};

//// --------------------- RDT APIs ------------------------------------
RDTAPI_API	int RDT_GetRDTApiVer();	//save as Little endian

RDTAPI_API	void RDT_Set_Max_Session_Number(unsigned long num);
RDTAPI_API	int RDT_Initialize();	//return max RDT_ID
RDTAPI_API	int RDT_DeInitialize();
RDTAPI_API	int RDT_Create(int nSessID, int TimeOut_ms, unsigned char ChID);
RDTAPI_API	int RDT_Destroy(int RDT_ID);
RDTAPI_API	int RDT_Write(int RDT_ID, char *data, int dataSize);
RDTAPI_API	int RDT_Read(int RDT_ID, char *buf, int *bufMaxSize, int Timeout_ms);
RDTAPI_API	int RDT_Status_Check(int RDT_ID, struct st_RDT_Status *pRDT_Status);

//// --------------------- Error Code ---------------------------------
#define		RDT_ER_NoERROR						 0 // No Error
#define		RDT_ER_INVALID_ARG					-1	
#define		RDT_ER_NOT_INITIALIZED				-2 //The RDT_Initialize function must be called.
#define		RDT_ER_ALREADY_INITIALIZED			-3 //Already Initialized. Reinitialization is not necessary.

#define		RDT_ER_EXCEED_MAX_CHANNEL			-5 //Exceed the max handled channel number
#define		RDT_ER_MEM_INSUFF					-6 //memory is insufficient
#define		RDT_ER_FAIL_CREATE_THREAD			-7	//Failed to create Thread
#define		RDT_ER_FAIL_CREATE_MUTEX			-8 // Mutex object create failed.

#define		RDT_ER_RDT_DESTROYED				-9 // RDT Service Stop, due to RDT_Destroy() called local or remote site called or remote close session.

#define		RDT_ER_TIMEOUT						-10
#define		RDT_ER_INVALID_RDT_ID				-11 //The specified RDT_ID is not correct or not available
#define		RDT_ER_IOTC_SENDTO_FAILED				-21 // the UDP sendto() function failed 
#define		RDT_ER_IOTC_SESSION_CLOSE_BY_REMOTE		-22 // the remote site already close this session, please call IOTC_Session_Close() to release session resource
#define		RDT_ER_IOTC_REMOTE_TIMEOUT_DISCONNECT	-23 // This session is disconnected due to remote site has no any response after a 'timrout' period of time. 15 sec.
#define		RDT_ER_IOTC_CH_NOT_ON					-26 // This channel not turn ON

#ifdef __cplusplus
}
#endif //__cplusplus


#endif // _RDTAPIs_joshua_H_
