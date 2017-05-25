//project defines
#include "RDS_project.h"
//
#include "IOTcommunicator.h"
#include "IOTCAPIs.h"

using namespace IOTnamespace;

//---------------------//
//  Global variables   //
//---------------------//
struct errCode
{
    int no;
    char *meaning;
} IOTerrTable[MAX_NUMBER_OF_IOT_ERROR_TABLE]={
    { 0, "IOTC_ER_NoERROR" },
    { -1, "IOTC_ER_SERVER_NOT_RESPONSE" },
    { -2, "IOTC_ER_FAIL_RESOLVE_HOSTNAME" },
    { -3, "IOTC_ER_ALREADY_INITIALIZED" },
    { -4, "IOTC_ER_FAIL_CREATE_MUTEX" },
    { -5, "IOTC_ER_FAIL_CREATE_THREAD" },
    { -6, "IOTC_ER_FAIL_CREATE_SOCKET" },
    { -7, "IOTC_ER_FAIL_SOCKET_OPT" },
    { -8, "IOTC_ER_FAIL_SOCKET_BIND" },
    { -10, "IOTC_ER_UNLICENSE" },
    { -11, "IOTC_ER_LOGIN_ALREADY_CALLED" },
    { -12, "IOTC_ER_NOT_INITIALIZED" },
    { -13, "IOTC_ER_TIMEOUT" },
    { -14, "IOTC_ER_INVALID_SID" },
    { -15, "IOTC_ER_UNKNOWN_DEVICE" },
    { -16, "IOTC_ER_FAIL_GET_LOCAL_IP" },
    { -17, "IOTC_ER_LISTEN_ALREADY_CALLED" },
    { -18, "IOTC_ER_EXCEED_MAX_SESSION" },
    { -19, "IOTC_ER_CAN_NOT_FIND_DEVICE" },
    { -20, "IOTC_ER_CONNECT_IS_CALLING" },
    { -21, "IOTC_ER_SENDTO_FAILED" },
    { -22, "IOTC_ER_SESSION_CLOSE_BY_REMOTE" },
    { -23, "IOTC_ER_REMOTE_TIMEOUT_DISCONNECT" },
    { -24, "IOTC_ER_DEVICE_NOT_LISTENING" },
    { -25, "IOTC_ER_DEVICE_NOT_LOGIN" },
    { -26, "IOTC_ER_CH_NOT_ON" },
    { -27, "IOTC_ER_FAIL_CONNECT_SEARCH" },
    { -28, "IOTC_ER_MASTER_TOO_FEW" },
    { -29, "IOTC_ER_AES_CERTIFY_FAIL" },
    { -30, "IOTC_ER_DEVICE_NOT_SECURE_LISTEN" },
    { 9999, "RESERVED" },
    { 9999, "RESERVED" }
};

//==============================//
// Constructor IOTcommunicator  //
//==============================//
IOTcommunicator::IOTcommunicator()
{
    //first get version from IOTCapi.dll
    unsigned long version;
    //initial IOTC .....
    return_Code=IOTC_Initialize(mUDPPort, mMaster1, mMaster2, mMaster3, mMaster4);
    if((return_Code==IOTC_ER_NoERROR)||(return_Code==IOTC_ER_ALREADY_INITIALIZED))
    {
        PacketOkCount=0;
        PacketOkCount=0;
        PacketLostCount=0;
        PacketWriteCount=0;
        readTimeOutCount=0;
        writeTimeOutCount=0;
        initial_OK=true;
        connect_OK=false;
        packet_OK=false;
        sessionRead_OK=false;
        session_Fatal=false;
        IOTC_Get_Version(&version);
        versionStr_IOT="(IOTC Ver."+String::Format("{0}.{1}.{2}.{3})", (version&0xFF000000)>>24,
            (version&0xFF0000)>>16, (version&0xFF00)>>8, (version&0xFF)>>0);
    }
    else
    {
        initial_OK=false;
        versionStr_IOT="IOTC ver. --unknow--";
    }
}

//============================//
// Destructor IOTcommunicator //
//============================//
IOTcommunicator::~IOTcommunicator()
{
    if(HasSession=true)IOTC_Session_Close(mSID);
}

//==========================//
// Method : getIOTerrString //
//==========================//
String^ IOTcommunicator::getIOTerrString()
{
    //scaning IOTerrTable
    String^ rtnStr="no this Err Code !!";
    for(int i=0; i<MAX_NUMBER_OF_IOT_ERROR_TABLE; i++)
    {
        if(return_Code==IOTerrTable[i].no)
        {
            rtnStr=gcnew String(IOTerrTable[i].meaning);
        }
    }
    return rtnStr;
}

//===================//
// Method : connect  //
//===================//
// return < 0 : error code (already record in class member: return_Code
// return >=0 : seccion ID
int IOTcommunicator::connect(String^ strUID)
{
    mUID=(char*)(void*)Marshal::StringToHGlobalAnsi(strUID);
    return_Code=IOTC_Connect_ByUID(mUID);
    if(return_Code<0)
    { //Error case
        connect_OK=false;
        return return_Code;
    }
    PacketOkCount=0;
    savedPacketOkCount=0;
    PacketLostCount=0;
    PacketWriteCount=0;
    readTimeOutCount=0;
    writeTimeOutCount=0;
    connect_OK=true;
    HasSession=true;
    mSID=return_Code;

    //get session information
    st_SInfo Sinfo;
    IOTC_Session_Check(mSID, &Sinfo);
    session_Mode=Sinfo.Mode;
    session_CorD=Sinfo.CorD;
    session_RemoteIP=gcnew String(Sinfo.RemoteIP);
    session_RemotePort=Sinfo.RemotePort;
    session_NatType=Sinfo.NatType;
    return mSID;
}

//=====================//
// Method: disconnect  //
//=====================//
void IOTcommunicator::disconnect()
{
    if(HasSession==true)
    {
        IOTC_Session_Close(mSID);
        HasSession=false;
    }
    connect_OK=false;
    packet_OK=false;
    sessionRead_OK=false;
    session_Fatal=false;
}

//===================//
// Method: Read_IOT  //
//===================//
int  IOTcommunicator::read_IOT(char* Buf, int Buf_Size)
{
    unsigned short PSN;
    char lost;
    return_Code=IOTC_Session_Read_Check_Lost(mSID, Buf, Buf_Size,
        MAX_TIME_SESSION_READ_IOT, &PSN, &lost, SESSION_READ_USE_CHANNEL);
    PacketSN=PSN;
    if(lost==1)  packet_Loss=true;
    else packet_Loss=false;
    if(return_Code>0)
    {
        if(packet_Loss==true)
            PacketLostCount++;
        else
        {
            savedPacketOkCount=PacketOkCount;
            PacketOkCount++;
        }
    }
    if(return_Code<0)
    {
        sessionRead_OK=false;
        //count timeout case
        if(return_Code==IOTC_ER_TIMEOUT)
        {
            readTimeOutCount++;
            sessionRead_TimeOut=true;
            //check packetcount...
            if(savedPacketOkCount==0)
                packet_OK=false;  //first packet not coming....
            else if(readTimeOutCount % TIMEOUT_TIMES_BEFORE_CHECK==0)
            {
                if(savedPacketOkCount==PacketOkCount)
                    packet_OK=false;  //long time no packet in....
                else packet_OK=true;
            }
        }
        else
        {
            sessionRead_TimeOut=false;
        }
        //fatal error==>should disconnect IOT
        if(return_Code==IOTC_ER_REMOTE_TIMEOUT_DISCONNECT
            ||return_Code==IOTC_ER_SESSION_CLOSE_BY_REMOTE)
        {
            session_Fatal=true;
            packet_OK=false;
            connect_OK=false; //Calling thread will disconnect IOT
        }
        else
        {
            session_Fatal=false;
        }
    }
    else
    {
        sessionRead_OK=true;
        session_Fatal=false;
    }
    //pass return code
    return return_Code;
}

//====================//
// Method: write_IOT  //
//====================//
int  IOTcommunicator::write_IOT(char* Buf, int Buf_Size)
{
    unsigned short PSN;
    char lost;
    return_Code=IOTC_Session_Write(mSID, Buf, Buf_Size, SESSION_WRITE_USE_CHANNEL);

    if(return_Code>0)
    {
        PacketWriteCount++;
    }
    if(return_Code<0)
    {
        sessionWrite_OK=false;
        //count timeout case
        if(return_Code==IOTC_ER_TIMEOUT)
        {
            writeTimeOutCount++;
            sessionWrite_TimeOut=true;
        }
        else
        {
            sessionWrite_TimeOut=false;
        }
        //fatal error==>should idsconnect IOT
        if(return_Code==IOTC_ER_REMOTE_TIMEOUT_DISCONNECT
            ||return_Code==IOTC_ER_SESSION_CLOSE_BY_REMOTE)
        {
            session_Fatal=true;
            packet_OK=false;
            connect_OK=false; //Calling thread will disconnect IOT
        }
        else
        {
            session_Fatal=false;
        }
    }
    else
    {
        sessionWrite_OK=true;
        session_Fatal=false;
    }
    //pass return code
    return return_Code;
}