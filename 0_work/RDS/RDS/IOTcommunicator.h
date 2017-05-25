#pragma once

#define TIMEOUT_TIMES_BEFORE_CHECK		10
#define MAX_NUMBER_OF_IOT_ERROR_TABLE	32
#define MAX_PACKET_SIZE_OF_IOT          800   //In IOTCapi.h it's IOTC_MAX_PACKET_SIZE, we could define smaller
#define MAX_TIME_SESSION_READ_IOT		50
#define SESSION_READ_USE_CHANNEL		0
#define SESSION_WRITE_USE_CHANNEL		0


namespace IOTnamespace {
	using namespace System;
	using namespace System::Runtime::InteropServices;
	using namespace System::Threading;

	//=================//
	//   Main class    //
	//=================//
	ref class IOTcommunicator
	{
	public:
		String^ versionStr_IOT;
		int return_Code;
		Boolean initial_OK;
		Boolean connect_OK;
		Boolean packet_OK;
		int savedPacketOkCount;
		Boolean sessionWrite_OK;
		Boolean sessionRead_OK;
		Boolean sessionRead_TimeOut;
		Boolean sessionWrite_TimeOut;
		Boolean session_Fatal;
		Boolean packet_Loss;
		char* mUID = "FVC91WZP6JAUVN6PMXKJ";
		int mSID;
		int PacketOkCount;
		int PacketLostCount;
		int PacketWriteCount;
		int readTimeOutCount;
		int writeTimeOutCount;
		unsigned short PacketSN;
		char session_Mode; // 0:P2P mode,  1:Relay mode
		char session_CorD; // 0: As a Client, 1: As a Device
		String^ session_RemoteIP;
		unsigned short session_RemotePort;
		unsigned char session_NatType; //remote NAT type

	private:
		unsigned short  mUDPPort=9438;
		char* mMaster1 = "m1.iotcplatform.com";
		char* mMaster2 = "m2.iotcplatform.com";
		char* mMaster3 = "m3.iotcplatform.com";
		char* mMaster4 = "m4.iotcplatform.com";
		Boolean HasSession;
		char bFlagLost;
	//constructor,functions===========================
	public:
		IOTcommunicator();          //Constructor
		~IOTcommunicator();         //Destructor

		//get Error message
		String^ getIOTerrString();  

		//Connect function ----------
		// return < 0 : error code
		// return >=0 : seccion ID
		int connect(String^ strUID);

		//disconnect function -------
		void disconnect();

		//communication Read
		int  read_IOT(char* Buf, int Buf_Size);

		//communication Write
		int  write_IOT(char* Buf, int Buf_Size);


	};//end of Class: IOTcommunicator
}//end of namespace

