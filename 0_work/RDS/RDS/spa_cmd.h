#pragma once

#include "IOTcommunicator.h"
#include "SPA.h"

//Generic setting for cammand packet
#define START_CODE_SMART_2_WIFI		0x0A
#define START_CODE_WIFI_2_SMART		0x09
#define STOP_CODE_ALL_DIRECTION		0x0D
#define NEW_2015_PROTOCOL_CODE		0xE0
#define MAX_PACKET_BYTES			256
#define SPA_NO_ERROR_DEFAULT_INDEX	32

namespace SPAcmd_namespace {
	using namespace System;
	using namespace SPAnamespace;

	enum PacketState {
		PKST_Idle,
		PKST_StartCode,
		PKST_LengthCode,
		PKST_NewProtocolCode,
		PKST_CommandCode,
		PKST_DataField,
		PKST_CheckCode
	};

	ref class spa_cmd
	{
	public:
		IOTnamespace::IOTcommunicator iIOTctrl;
		Boolean parseFail;
		Boolean cmdPktisValid;
		Boolean cmdIsBroadcast;
		int received_ValidPacket;
		int CurrentPacket_InputPtr;
		Byte CurrentPacket_LengthCode;
		Byte CurrentPacket_Cmd_length_in;
		Byte CurrentPacket_NPcode;
		Byte CurrentPacket_CmdCode;
		Byte CurrentPacket_ChkSumCode;
		Byte CurrentPacket_Cmd_length;

		//error counters
		int LenCode_LessThan2_ErCnt;
		int No_StopCode_ErCnt;
		int LenCode_NotMatch_ErCnt;
		int chkSum_Xor_ErCnt;

		int ValidPacket_CmdCode;
		enum PacketState CurrentPacket_State;

		//for waiting command back
		unsigned char waitCmdCode; //set to some command, if waiting it.
		Boolean eco1_upated;
		Boolean eco2_upated;
		Boolean eco3_upated;
		Boolean eco4_upated;

		//include a object
		SPAnamespace::SPA iSPA;
	public:
		spa_cmd();
		//~spa_cmd();

		//==============//
		//parse command //
		//==============//
		void parse(array<unsigned char>^ buffer);

		//=========//
		// dispose //
		//=========//
		void dispose();

		//=============//
		//check packet //
		//=============//
		Boolean IsValidPacket(array<unsigned char>^ pktBuf);

		//==============//
		//get XOR value //
		//==============//
		unsigned char get_XorValue(array<unsigned char>^ FullBytes, unsigned char PreLoadValue);

		//========================//
		// Send command functions //
		//========================//
		int SendCmdPacket(array<unsigned char>^ FullBytes);
		int SendSingleCmdPacket(unsigned char CmdCode);
		void set_p1_hi_ON();
		void set_p1_lo_ON();
		void set_p1_OFF();
		void set_p2_hi_ON();
		void set_p2_lo_ON();
		void set_p2_OFF();
		void set_p3_hi_ON();
		void set_p3_lo_ON();
		void set_p3_OFF();
		void set_blower_ON();
		void set_blower_OFF();
		void set_unlock();
		void set_Tlock();
		void set_Plock();
		void set_Alock();
		void set_Slock();
		void set_ECO_ON();
		void set_ECO_OFF();


		//==========================//
		// readed command functions //
		//==========================//
		//3x
		void do_cmd_30(array<unsigned char>^ pktBuf);
		void do_cmd_31(array<unsigned char>^ pktBuf);
		void do_cmd_32(array<unsigned char>^ pktBuf);
		void do_cmd_33(array<unsigned char>^ pktBuf);
		void do_cmd_34(array<unsigned char>^ pktBuf);
		void do_cmd_35(array<unsigned char>^ pktBuf);
		void do_cmd_36(array<unsigned char>^ pktBuf);
		void do_cmd_37(array<unsigned char>^ pktBuf);
		void do_cmd_38(array<unsigned char>^ pktBuf);
		//4x
		void do_cmd_40(array<unsigned char>^ pktBuf);
		void do_cmd_41(array<unsigned char>^ pktBuf);
		void do_cmd_42(array<unsigned char>^ pktBuf);
		void do_cmd_43(array<unsigned char>^ pktBuf);
		void do_cmd_44(array<unsigned char>^ pktBuf);
		void do_cmd_45(array<unsigned char>^ pktBuf);
		void do_cmd_46(array<unsigned char>^ pktBuf);
		//7x
		void do_cmd_70(array<unsigned char>^ pktBuf);
		//8x
		void do_cmd_81(array<unsigned char>^ pktBuf);
		void do_cmd_82(array<unsigned char>^ pktBuf);
		void do_cmd_83(array<unsigned char>^ pktBuf);
		void do_cmd_87(array<unsigned char>^ pktBuf);
		//9x
		void do_cmd_96(array<unsigned char>^ pktBuf);
		void do_cmd_99(array<unsigned char>^ pktBuf);

	};
}
