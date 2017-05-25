
/**====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*

AVAPIs.h

Copyright (c) 2010 by TUTK Co.LTD. All Rights Reserved.
*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*/

/**===========================================================================

Version  		Name       	Date			Description
0.1.0.1			Joshua	  	12/06/2010		 Trial Version
0.1.0.4			joshua		2011-05-16		 modified avRecvFrameData2(.)
0.1.1.0			Kevin		2011-05-27		 Add send/resend audio capability
0.1.2.0			Kevin		2011-06-30		 Adapt to IOTC multi-channel session mechanism
1.0.0.0			Kevin		2011-07-12		 Formal version, stability testing
1.0.1.0			Kevin		2011-08-02		 Fix Bug : avServStart() when check IOTC error code(-14,-22,-23) not release AvInfo
1.0.2.0			Kevin		2011-08-08		 Fix Bug : 1.linux thread not reclaim so must detach thread 2.avoid avServStop() and avClientStop() to be called repeatedly
1.1.0.0			Kevin		2011-09-14		 Modify : 1.allow set send frame delay time to 0, when set 0 will delay 1ms in every 100 frame interval 2.Max fifo size 256KB->2MB, max frame divided 256->512. Fix Bug : avRecvFrameData() and avRecvAudioData() if pFrmNo is NULL will crash. Custom : reduce static memory usage for ARC
1.2.1.0			Kevin		2011-11-24		 Fix Bug : block_FifoExist() mutex dead lock. Add : 1.avServExit() to exit avServStart() anytime. 2.avClientExit() to exit avClientStart() anytime.
1.2.2.0			Kevin		2011-12-29		 Fix Bug : 1.avSendIOCtrl() packet lost because not judge ack by frameNo. 2.Success in avServStart() and failed in avClientStart() when packet lost. Add : 1.avServStart2() use call back function for authentication. 2.avRecvIOCtrl() error code AV_ER_INVALID_ARG means give buf size not enough. 3.avSendIOCtrl() error code AV_ER_SENDIOCTRL_ALREADY_CALLED means cant use the same avIndex to multi-call. 4.avSendIOCtrlExit() force to exit avSendIOCtrl().
*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*/

#ifndef _AVAPIs_joshua_H_
#define _AVAPIs_joshua_H_

#include "platform_Config.h"

#ifdef IOTC_Win32
#ifdef AVAPIS_EXPORTS
#define AVAPI_API __declspec(dllexport)
#else
#define AVAPI_API __declspec(dllimport)
#endif
#endif ////#ifdef IOTC_Win32

#ifdef IOTC_ARC_HOPE312
	#define AVAPI_API 
#endif ////#ifdef IOTC_ARC_HOPE312

#ifdef IOTC_Linux
#define AVAPI_API 
#endif ////#ifdef IOTC_Linux


#ifdef __cplusplus
extern "C" {
#endif //__cplusplus

//--{{inner iotype-----------------------------------------------------
#define IOTYPE_INNER_SND_DATA_DELAY		0xFF	//C--->D: avClient(AP) change time interval of sending packets by avSendFrameData(avServer)


//--}}inner iotype-----------------------------------------------------

	
//// --------------------- AV APIs ------------------------------------
AVAPI_API int avGetAVApiVer();	//save as Little endian

AVAPI_API int avInitialize(int nMaxNumAllowed);	//first called in all api

//ioType: 0x00---0xFF, used by inner of av module
//		  >0xFF		   used by user
AVAPI_API int avSendIOCtrl(int avIndex, unsigned int ioType, char *ioCtrlBuf, int ioCtrlBufSize); //block thread,wait ack
AVAPI_API int avRecvIOCtrl(int avIndex, unsigned int *pioType, char *ioCtrlBuf, int ioCtrlBufMaxSize, unsigned int timeout_ms);
AVAPI_API int avSendIOCtrlExit(int avIndex);

typedef int (*authFn)(char *viewAcc,char *viewPwd);
//D(Server side)=======================================================
AVAPI_API int  avServStart(int nSID,char *viewAcc,char *viewPwd,unsigned long timeout_sec,unsigned long servType, unsigned char ChID);
AVAPI_API int  avServStart2(int nSID,authFn pAuthFn,unsigned long timeout_sec,unsigned long servType, unsigned char ChID);
AVAPI_API void avServStop(int avIndex);
AVAPI_API int  avSendFrameData(int avIndex, char *data, int dataSize, void *pFrmInfo, int FrmInfoSize);
AVAPI_API int  avSendAudioData(int avIndex, char *data, int dataSize, void *pFrmInfo, int FrmInfoSize);
AVAPI_API void avServExit(int nSID, unsigned char ChID);

//C(AP side)===========================================================
AVAPI_API int  avClientStart(int nSID,char *viewAcc, char *viewPwd,unsigned long timeout_sec,unsigned long *pservType, unsigned char ChID);
AVAPI_API void avClientStop(int avIndex);
AVAPI_API void avClientExit(int nSID, unsigned char ChID);

AVAPI_API int avRecvFrameData(int avIndex,char *buf, int bufMaxSize,
							  char *pFrmInfo, int FrmInfoMaxSize, unsigned int *pFrmNo);
AVAPI_API int avRecvAudioData(int avIndex, char *buf, int bufMaxSize,
							  char *pFrmInfo,int FrmInfoMaxSize,unsigned int *pFrmNo);
AVAPI_API int avCheckAudioBuf(int avIndex);  //return buf count

AVAPI_API void avServSetMaxBufSize(unsigned long size); //unit is KB, for video frame, default 2MB
AVAPI_API void avClientSetMaxBufSize(unsigned long size); //unit is KB, for video frame, default 1MB

//// --------------------- Error Code ---------------------------------
#define		AV_ER_NoERROR						 0	// No Error
#define		AV_ER_INVALID_ARG					-1	
#define		AV_ER_BUFPARA_MAXSIZE_INFUFF		-2	//bufMaxSzie too small, can't contain one frame
#define		AV_ER_EXCEED_MAX_SESSION			-3 // Exceed the max handled session number
#define		AV_ER_MEM_INSUFF					-4

#define		AV_ER_FAIL_CREATE_THREAD			-5	//Thread Creation Failed.
#define		AV_ER_EXCEED_MAX_ALARM				-6	//cause this error when server send data too slow,but ipcam give data too quick. need reduce bit per sec
#define		AV_ER_EXCEED_MAX_SIZE				-7
#define		AV_ER_SERV_NO_RESPONSE				-8
#define		AV_ER_CLIENT_NO_AVLOGIN				-9	//av client don't call avClientStart()

#define		AV_ER_WRONG_VIEWACCorPWD			-10	//be inconsistent with viewAcc or viewPwd of the avServer when avClientStart
#define		AV_ER_INVALID_SID					-11 //The specified Session ID is not correct!!
#define		AV_ER_TIMEOUT						-13 

#define		AV_ER_DATA_NOREADY					-17
#define		AV_ER_INCOMPLETE_FRAME				-18
#define		AV_ER_LOSED_THIS_FRAME				-19

#define		AV_ER_SESSION_CLOSE_BY_REMOTE		-22 // the remote site already close this session, please call IOTC_Session_Close() to release session resource
#define		AV_ER_REMOTE_TIMEOUT_DISCONNECT		-23 // This session is disconnected due to remote site has no any response after a 'timrout' period of time. 15 sec.
#define		AV_ER_SERVER_EXIT		    		-101 // User force to exit avServStart()
#define		AV_ER_CLIENT_EXIT		    		-102 // User force to exit avClientStart()
#define		AV_ER_NOT_INITIALIZED	    		-103 // The avInitialize() function must be called.
#define		AV_ER_CLIENT_NOT_SUPPORT	   		-104 // Client not support avSendFrameData() and avSendAudioData()
#define		AV_ER_SENDIOCTRL_ALREADY_CALLED	   	-105 // cant use the same avIndex multi-call avSendIOCtrl()
#define		AV_ER_SENDIOCTRL_EXIT		    	-106 // User force to exit avSendIOCtrl()
#ifdef __cplusplus
}
#endif //__cplusplus


#endif // _AVAPIs_joshua_H_
