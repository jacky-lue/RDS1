/**====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*

FTAPIs.h

Copyright (c) 2010 by TUTK Co.LTD. All Rights Reserved.
*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*/

/**===========================================================================

Revisions of FTAPIs.h
Version                 Name            Date                    Description
1.0.0.0                 Ting                                    First version
1.1.0.0                 Ting            2011-10-12              Bug fix: FT_Get/Put can send an empty file successfully.
                                                                FT_Server_Start() only process one request now, instead of loop until connection ternimate
                                                                New api: FT_Get_Status()
1.2.0.0					Kevin			2011-10-25				Call 
*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*/

#ifndef _FTAPIs_H_
#define _FTAPIs_H_

#if defined _MSC_VER && _MSC_VER < 1600 // older than VS.net 2010, no stdint.h
typedef unsigned __int64 uint64_t;
#elif defined __cplusplus
#include <cstdint>
#else 
#include <stdint.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

#include "platform_Config.h"

#ifdef IOTC_Win32
    #ifdef FTAPI_EXPORTS
        #define FTAPI_API __declspec(dllexport)
    #else
        #define FTAPI_API __declspec(dllimport)
    #endif
#else
    #define FTAPI_API
#endif

static const int FT_ER_PARAM_TOO_LONG = -3000;
static const int FT_ER_UNAUTHORIZED = -3001;
static const int FT_ER_NO_MEMORY = -3002;
static const int FT_ER_BAD_REQUEST = -3003;
static const int FT_ER_BAD_RESPONSE = -3004;
static const int FT_ER_LOCAL_FILE_ACCESS_FAILED = -3005;
static const int FT_ER_REMOTE_FILE_ACCESS_FAILED = -3006;
static const int FT_ER_UNKNOWN_ERROR = -3007;

struct _FT_Server;
typedef struct _FT_Server *FT_Handle;

enum FT_Get_Status_Option {
    FT_GET_STATUS_COMMAND = 1003,
    FT_GET_STATUS_START_TIME = 1004,
    FT_GET_STATUS_FILE_NAME = 1005,
    FT_GET_STATUS_FILE_SIZE = 1006,
    FT_GET_STATUS_TRANSFERRED_COUNT = 1007
};

typedef struct _FT_FileStat {
    uint64_t size;
    char type; /* There's only two different types now, 'D': directory, 'R': other. Other types may add in the future */
    char name[256];
} FT_FileStat;

//int Is_Dir(const FT_FileStat* f) {return f->type == 'D';}

FTAPI_API unsigned long FT_ApiVersion();

/**
 * Initialize a FT server or client
 *
 * Parameters:
 *  handle(out) - Pointer to a FT_Handle object
 *  SessID - A valid Session ID
 *  RDTChID - Channel ID for FT command transfer
 *  DataChID - Channel ID for data transfer
 *
 * Return:
 *  0 - Success, a valid FT_Handle object is stored in *handle
 *  FT_ER_NO_MEMORY - malloc() failed
 *  other - Error codes specified in RDT_Create
 */
FTAPI_API int FT_Init(FT_Handle *handle, int SessID, unsigned char RDTChID, unsigned char DataChID);

/**
 * Start a FT server on session id given by FT_Init
 * This function blocks until the client sends a BYE command, connection closed, or error occurs
 *
 * Parameters:
 *  handle - A valid FT handler
 *  password - Password for client login
 *
 * Return Code:
 *  0 - Exit because client calls FT_Bye()
 *  FT_ER_BAD_REQUEST - Bad request
 *  < 0 - Error codes specified in IOTC_Session_Read/Write RDT_Read/Write
 */
FTAPI_API int FT_Server_Start(FT_Handle handle, const char *password);

/**
 * Send password for login
 *
 * Parameters:
 *  handle - A valid FT_Handle
 *  password - The password used to login
 *
 * Return Code:
 *  0 - No error
 *  FT_ER_PARAM_TOO_LONG - password length > 1024 bytes
 *  FT_ER_UNAUTHORIZED - Password incorrect
 *  FT_ER_BAD_RESPONSE - The data sent by remote server/client was malformed
 *  other - Error codes specified in IOTC_Session_Read/Write RDT_Read/Write
 */
FTAPI_API int FT_Pass(FT_Handle handle, const char *password);

/**
 * Receive file from remote server
 *
 * Parameters:
 *  handle - A valid FT_Handle
 *  local_path - Local path
 *  remote_path - Remote path
 *
 * Return Code:
 *  0 - No error
 *  FT_ER_PARAM_TOO_LONG - remote server/client_path length > 1024 bytes
 *  FT_ER_UNAUTHORIZED - Haven't call FT_Auth() yet, or last FT_Auth() call failed
 *  FT_ER_BAD_RESPONSE - The data sent by remote server/client was malformed
 *  FT_ER_LOCAL_FILE_ACCESS_FAILED - Local file access failed
 *  FT_ER_REMOTE_FILE_ACCESS_FAILED - Remote file access failed
 *  other - Error codes specified in IOTC_Session_Read/Write RDT_Read/Write
 */
FTAPI_API int FT_Get(FT_Handle handle, const char *local_path, const char *remote_path);

/**
 * Send file to remote server
 *
 * Parameters:
 *  handle - A valid FT_Handle
 *  local_path - Local path
 *  remote_path - Remote path
 *
 * Return Code:
 *  0 - No error
 *  FT_ER_PARAM_TOO_LONG - remote server/client_path length > 1024 bytes
 *  FT_ER_UNAUTHORIZED - Haven't call FT_Auth() yet, or last FT_Auth() call failed
 *  FT_ER_BAD_RESPONSE - The data sent by remote server/client was malformed
 *  FT_ER_LOCAL_FILE_ACCESS_FAILED - Local file access failed
 *  FT_ER_REMOTE_FILE_ACCESS_FAILED - Remote file access failed
 *  other - Error codes specified in IOTC_Session_Read/Write RDT_Read/Write
 */
FTAPI_API int FT_Put(FT_Handle handle, const char *local_path, const char *remote_path);

/**
 * List contents of remote directory
 *
 * Parameters:
 *  handle - A valid FT_Handle
 *  remote_path - Remote directory path
 *  file_list (out) - Pointer to an array which stored the file records
 *  num (out) - Number of records stored in file_list
 *
 * Return Code:
 *  0 - No error
 *  FT_ER_PARAM_TOO_LONG - remote server/client_path length > 1024 bytes
 *  FT_ER_UNAUTHORIZED - Haven't call FT_Auth() yet, or last FT_Auth() call failed
 *  FT_ER_BAD_RESPONSE - The data sent by remote server/client was malformed
 *  FT_ER_REMOTE_FILE_ACCESS_FAILED - Remote dir access failed
 *  FT_ER_NO_MEMORY - malloc() failed
 *  other - Error codes specified in IOTC_Session_Read/Write RDT_Read/Write
 *
 * Note:
 *  If return value is zero, caller have to call FT_FreeDir(*file_list) to release the allocated memory block.
 */
FTAPI_API int FT_Dir(FT_Handle handle, const char *remote_path, FT_FileStat **file_list, int* num);


/**
 * Release the memory lock allocated by FT_Dir()
 * 
 * Parameters:
 *   file_list (in) - The parameter file_list used in FT_Dir()
 */
FTAPI_API void FT_FreeDir(const FT_FileStat *file_list);

/**
 * Terminate the FT session
 *
 * Return Code:
 *  0 - No error
 *  other - Error codes specified in IOTC_Session_Read/Write RDT_Read/Write
 */
FTAPI_API int FT_Close(FT_Handle handle);

/**
 * Get FT Transfer Status
 * Parameters:
 *   handle - A valid FT_Handle
 *   name - An enum described below
 *
 *     FT_GET_STATUS_COMMAND = 1003,
 *         FT_GET_STATUS_START_TIME = 1004,
 *             FT_GET_STATUS_FILE_NAME = 1005,
 *                 FT_GET_STATUS_FILE_SIZE = 1006,
 *                     FT_GET_STATUS_TRANSFERRED_COUNT = 1007
 *
 * Return:
 *   The actual type of return value depends on the "name" parameter
 *   if arg == FT_GET_STATUS_COMMAND: 
 *       a char* indicates last command is returned, only works when the handle is a server
 *   if arg == FT_GET_STATUS_START_TIME: 
 *       a pointer to time_t indicates the time of last command received is returned, only works when the handle is a server
 *   if arg == FT_GET_STATUS_FILE_NAME:
 *       a char* indicates the requested filename is returned, only works when the handle is a server when last command is get or put.
 *   if arg == FT_GET_STATUS_FILE_SIZE:
 *       a pointer to uint64_t indicates the size of requested file is returned, works for both client and server when last command is get or put.
 *   if arg == FT_GET_STATUS_TRANSFERRED_COUNT:
 *       a pointer to uint64_t indicates the size of already transferred date is returned, works for both client and server during transfer phase.
 */
FTAPI_API const void* FT_Get_Status(const FT_Handle handle, enum FT_Get_Status_Option arg);

/**
 * Deinitialize the given handler.
 */
FTAPI_API void FT_DeInit(FT_Handle handle);

#ifdef __cplusplus
}
#endif

#endif /* _FTAPIs_H_ */
