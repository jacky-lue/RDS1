#include "spa_cmd.h"
#include "SPA.h"
#include "IOTcommunicator.h"

using namespace SPAcmd_namespace;

//---------------------//
//  Global variables   //
//---------------------//
Byte CurrentPacket[MAX_PACKET_BYTES];

spa_cmd::spa_cmd()
{
    parseFail=false;
    cmdPktisValid=false;
    received_ValidPacket=0;
    CurrentPacket_State=PKST_Idle;
    LenCode_LessThan2_ErCnt=0;
    No_StopCode_ErCnt=0;
    LenCode_NotMatch_ErCnt=0;
    chkSum_Xor_ErCnt=0;
}

//==================//
// Method : Parse   //
//==================//
//one by one check packet format and Using state machine.
//Here only check packet format:
//   1)start/stop code
//   2)new protocol code
//   3)length code
//Didnt cehck Check-XOR, and the length defined in protocal
void spa_cmd::parse(array<unsigned char>^ buffer)
{
    parseFail=false;

    for(int i=0; i<buffer->Length; i++)
    {
        CurrentPacket[CurrentPacket_InputPtr]=buffer[i];
        CurrentPacket_InputPtr++;
        switch(CurrentPacket_State)
        {
        case PKST_Idle:   //-------------------------------------------Idel
            if(buffer[i]==START_CODE_WIFI_2_SMART)
            {
                CurrentPacket_State=PKST_StartCode;
            }
            else
            {
                CurrentPacket_State=PKST_Idle;
            }
            break;
        case PKST_StartCode:     //------------------Already has start code
            CurrentPacket_LengthCode=buffer[i];
            CurrentPacket_Cmd_length_in=0; //reset real-in length
            CurrentPacket_State=PKST_LengthCode;
            if(CurrentPacket_LengthCode<2)
            {
                //give-up current packet. keep scanning
                LenCode_LessThan2_ErCnt++;
                CurrentPacket_State=PKST_Idle;
                CurrentPacket_InputPtr=0;
            }
            break;
        case PKST_LengthCode:   //------------------Already has length code
            CurrentPacket_NPcode=buffer[i]; //old protocol cmooand code or new protocol code
            CurrentPacket_Cmd_length_in++;
            CurrentPacket_State=PKST_NewProtocolCode;
            break;
        case PKST_NewProtocolCode:   //------------------Already has new protocol code
            CurrentPacket_CmdCode=buffer[i];
            CurrentPacket_Cmd_length_in++;
            CurrentPacket_State=PKST_CommandCode;
            break;
        case PKST_CommandCode:  //------------------Already has command code
            CurrentPacket_Cmd_length_in++;
            if(CurrentPacket_Cmd_length_in==CurrentPacket_LengthCode)
            {
                CurrentPacket_State=PKST_DataField;
            }
            break;
        case PKST_DataField:   //------------------Already has data field inputed
            //get byte is Chcek-sum XOR value
            CurrentPacket_State=PKST_CheckCode;
            break;
        case PKST_CheckCode:  //-------------------Already has check byte inputed
            if(buffer[i]==STOP_CODE_ALL_DIRECTION)
            {
                //do commad here **********************
                //*************************************
                //*************************************
                dispose();
                //for next packet
                CurrentPacket_State=PKST_Idle;
                CurrentPacket_InputPtr=0;
                CurrentPacket_Cmd_length_in=0;
            }
            else
            {
                CurrentPacket_State=PKST_Idle;
                parseFail=true;
                //give-up current packet
                No_StopCode_ErCnt++;
                CurrentPacket_InputPtr=0;
                CurrentPacket_Cmd_length_in=0;
            }
            break;
        } //end of switch
    }//end for buffer-length
}

//==================//
// Method : dispose //
//==================//
//dispose readed command. According to command in Global CurrentPacket[]
// 1)copy to a buffer
// 2)check packet on check-XOr value
// 3)call each functions
void spa_cmd::dispose()
{
    unsigned char CmdCode;
    unsigned char NewCmdCode;
    unsigned char LengthCode;
    array<Byte>^ buffer;
    Array::Resize(buffer, CurrentPacket_InputPtr);
    for(int i=0; i<CurrentPacket_InputPtr; i++)
    {
        buffer[i]=CurrentPacket[i];
    }
    cmdPktisValid=IsValidPacket(buffer);
    if(cmdPktisValid==true)
    {
        CmdCode=buffer[2];
        NewCmdCode=buffer[3];
        LengthCode=buffer[1];
        if(CmdCode==NEW_2015_PROTOCOL_CODE)
        {
            received_ValidPacket++; //only new protocol count as packet
            switch(NewCmdCode)
            {
            case 0x30: do_cmd_30(buffer); break; //----3X
            case 0x31: do_cmd_31(buffer); break;
            case 0x32: do_cmd_32(buffer); break;
            case 0x33: do_cmd_33(buffer); break;
            case 0x34: do_cmd_34(buffer); break;
            case 0x35: do_cmd_35(buffer); break;
            case 0x36: do_cmd_36(buffer); break;
            case 0x37: do_cmd_37(buffer); break;
            case 0x38: do_cmd_38(buffer); break;
            case 0x40: do_cmd_40(buffer); break; //----4X
            case 0x41: do_cmd_41(buffer); break;
            case 0x42: do_cmd_42(buffer); break;
            case 0x43: do_cmd_43(buffer); break;
            case 0x44: do_cmd_44(buffer); break;
            case 0x45: do_cmd_45(buffer); break;
            case 0x46: do_cmd_46(buffer); break;
            case 0x70: do_cmd_70(buffer); break; //----7x
            case 0x81: do_cmd_81(buffer); break; //----8x
            case 0x82: do_cmd_82(buffer); break;
            case 0x83: do_cmd_83(buffer); break;
            case 0x87: do_cmd_87(buffer); break;
            case 0x96: do_cmd_96(buffer); break; //----9x
            case 0x99: do_cmd_99(buffer); break;
            default:   break;
            }
        }
    }
    else
    {
        //print out wrong command packet
        //if (ShowBadPacket){
        //	MsgShow(String::Format("{0} !", BitConverter::ToString(buffer)));
    }
}//end if isValidPacket

//========================//
// Method : isValidPacket //
//========================//
//check packet is valid or not
//2016/11/24 follow "smart-phone通訊協定_12", check all valid commands
Boolean spa_cmd::IsValidPacket(array<unsigned char>^ pktBuf)
{
    //initial  flag
    cmdIsBroadcast=false;
    //check start/stop code (already checked in parse();)
    if(pktBuf[0]!=START_CODE_WIFI_2_SMART) return false;
    if(pktBuf[pktBuf->Length-1]!=STOP_CODE_ALL_DIRECTION) return false;

    //check new protocol
    if(pktBuf[2]!=NEW_2015_PROTOCOL_CODE) return false;

    //check length .....
    unsigned char lengthCode=pktBuf[1];
    if(lengthCode!=(pktBuf->Length-4)) return false;
    //check protocal --> each command 's length  ******************************
    unsigned char len_in_protocol;
    unsigned char CmdCode=pktBuf[3];//2015,new protocol
    switch(CmdCode)
    { //checking length here...
    case 0x05: len_in_protocol=2; break;   //--------------------------------0x
    case 0x06: len_in_protocol=10; break;
    case 0x07: len_in_protocol=2; break;
    case 0x08: len_in_protocol=10; break;
    case 0x1A:                              //---------------------------------1x
        cmdIsBroadcast=true;
        if(pktBuf[4]==0x10)len_in_protocol=6;
        else if(pktBuf[4]==0x20)len_in_protocol=4;
        else if(pktBuf[4]==0x30)len_in_protocol=9;
        else if(pktBuf[4]==0x40)len_in_protocol=6;
        else if(pktBuf[4]==0x50)len_in_protocol=12;
        else                       len_in_protocol=0;//is error
        break;
    case 0x1B:
        cmdIsBroadcast=true;
        if(pktBuf[4]==0x0F)len_in_protocol=5;
        else if(pktBuf[4]==0x10)len_in_protocol=5;
        else if(pktBuf[4]==0x20)len_in_protocol=5;
        else                       len_in_protocol=0;//is error
        break;
    case 0x30: len_in_protocol=4; break;   //--------------------------------3x
    case 0x31: len_in_protocol=9; break;
    case 0x32:
    case 0x33: len_in_protocol=8; break;
    case 0x34: len_in_protocol=6; break;
    case 0x35: len_in_protocol=8; break;
    case 0x36: len_in_protocol=3; break;
    case 0x37: len_in_protocol=3; break;
    case 0x38: len_in_protocol=3; break;
    case 0x39: len_in_protocol=3; break;
    case 0x3A: len_in_protocol=3; break;
    case 0x3F: len_in_protocol=3; break;
    case 0x40: len_in_protocol=10;         //-------------------------------4x
        cmdIsBroadcast=true;
        break;
    case 0x41: len_in_protocol=12;
        cmdIsBroadcast=true;
        break;
    case 0x42: len_in_protocol=12; break;
    case 0x43: len_in_protocol=12; break;
    case 0x44: len_in_protocol=4; break;
    case 0x45: len_in_protocol=4; break;
    case 0x46: len_in_protocol=3; break;
    case 0x48: len_in_protocol=10;
        cmdIsBroadcast=true;
        break;
    case 0x49: len_in_protocol=10;
        cmdIsBroadcast=true;
        break;
    case 0x70: len_in_protocol=12; break;   //-------------------------------7x
    case 0x80: len_in_protocol=3; break;    //-------------------------------8x
    case 0x81: len_in_protocol=3; break;
    case 0x82: len_in_protocol=3; break;
    case 0x83: len_in_protocol=3; break;
    case 0x84: len_in_protocol=3; break;
    case 0x85: len_in_protocol=3; break;
    case 0x86: len_in_protocol=3; break;
    case 0x87: len_in_protocol=3; break;
    case 0x88: len_in_protocol=3; break;
    case 0x89: len_in_protocol=3; break;
    case 0x8A: len_in_protocol=3; break;
    case 0x8B: len_in_protocol=3; break;
    case 0x8C: len_in_protocol=3; break;
    case 0x8D: len_in_protocol=3; break;
    case 0x8E: len_in_protocol=3; break;
    case 0x8F: len_in_protocol=3; break;
    case 0x90: len_in_protocol=3; break;    //-------------------------------9x
    case 0x91: len_in_protocol=3; break;
    case 0x92: len_in_protocol=3; break;
    case 0x93: len_in_protocol=3; break;
    case 0x94: len_in_protocol=3; break;
    case 0x95: len_in_protocol=3; break;
    case 0x96: len_in_protocol=3; break;
    case 0x97: len_in_protocol=3; break;
    case 0x98: len_in_protocol=3; break;
    case 0x99: len_in_protocol=3; break;
    case 0xA0: len_in_protocol=6; break;    //-------------------------------Ax
    case 0xA1: len_in_protocol=6; break;
    case 0xA2: len_in_protocol=12; break;
    case 0xD0: len_in_protocol=4; break;    //-------------------------------Dx
    case 0xD1: len_in_protocol=4; break;
    case 0xD2: len_in_protocol=4; break;
    case 0xD3: len_in_protocol=4; break;
    case 0xD4: len_in_protocol=4; break;
    case 0xD5: len_in_protocol=4; break;
    case 0xD6: len_in_protocol=4; break;
    default:   len_in_protocol=0; break; // is error
    }
    if(lengthCode!=len_in_protocol)
    {
        LenCode_NotMatch_ErCnt++;
        return false;
    }

    //check checksum XOR value
    array<Byte>^ buffer;
    Array::Resize(buffer, lengthCode);
    for(int i=0; i<lengthCode; i++)
    {
        buffer[i]=pktBuf[2+i];
    }
    unsigned char XOR_value=get_XorValue(buffer, pktBuf[1]);
    if(pktBuf[pktBuf->Length-2]!=XOR_value)
    {
        chkSum_Xor_ErCnt++;
        return false;
    }

    ValidPacket_CmdCode=CmdCode;
    return true;
}

//========================//
// Method : get_XorValue  //
//========================//
// Get the Check-XOR value
// parameter FullBytes: byte array to produce XOR value
// parameter PreLoadValue : (optional) can load previous Xor-Value (from previous bytes) or a leading code
unsigned char spa_cmd::get_XorValue(array<unsigned char>^ FullBytes, unsigned char PreLoadValue)
{
    //unsigned char result = (unsigned char) 255;
    unsigned char result=(unsigned char)0;
    result=(unsigned char)(result ^ PreLoadValue);
    for(Int32 i=0; i<FullBytes->Length; i++)
    {
        result=(unsigned char)(result ^ FullBytes[i]);
    } // for loop (each FullBytes)
    return result;
}

//========================//
// Send command functions //
//========================/////////////////////////////////////////////////////////////////////////////////
// Input Command and Data bytes,not include start-code, length , check-Xor & stop-code.
//Return < 0 : error
//       > 0 : Ok, and it's how many byte sended.
int spa_cmd::SendCmdPacket(array<unsigned char>^ FullBytes)
{
    int rtn;
    char buf[MAX_PACKET_BYTES];
    buf[0]=START_CODE_SMART_2_WIFI;
    buf[1]=FullBytes->Length;
    unsigned char XOR_value=get_XorValue(FullBytes, buf[1]);
    for(int i=0; i<FullBytes->Length; i++)
    {
        buf[2+i]=FullBytes[i];
    } // for loop (each FullBytes)
    buf[FullBytes->Length+2]=XOR_value;
    buf[FullBytes->Length+3]=STOP_CODE_ALL_DIRECTION;
    //write IOTC action
    rtn=this->iIOTctrl.write_IOT(buf, buf[1]+4);
    return rtn;
}

int spa_cmd::SendSingleCmdPacket(unsigned char CmdCode)
{
    int rtn;
    char buf[6];
    array <unsigned char>^ toXorBuf;
    Array::Resize(toXorBuf, 2);
    buf[0]=START_CODE_SMART_2_WIFI;
    buf[1]=2;
    buf[2]=NEW_2015_PROTOCOL_CODE;
    buf[3]=CmdCode;
    toXorBuf[0]=NEW_2015_PROTOCOL_CODE;
    toXorBuf[1]=CmdCode;
    unsigned char XOR_value=get_XorValue(toXorBuf, 2);
    buf[4]=XOR_value;
    buf[5]=STOP_CODE_ALL_DIRECTION;
    //write IOTC action
    rtn=this->iIOTctrl.write_IOT(buf, 6);
    return rtn;
}

//---------------//
// Pump 1 on/off //
//---------------//
void spa_cmd::set_p1_hi_ON()
{
    array<unsigned char>^ buffer;
    Array::Resize(buffer, 3);
    buffer[0]=NEW_2015_PROTOCOL_CODE;
    buffer[1]=0x11; //Command  -- Pump1
    buffer[2]=0x02; //set p1-hi on
    this->SendCmdPacket(buffer);
}
void spa_cmd::set_p1_lo_ON()
{
    array<unsigned char>^ buffer;
    Array::Resize(buffer, 3);
    buffer[0]=NEW_2015_PROTOCOL_CODE;
    buffer[1]=0x11; //Command  -- Pump1
    buffer[2]=0x01; //set p1-Lo on
    this->SendCmdPacket(buffer);
}
void spa_cmd::set_p1_OFF()
{
    array<unsigned char>^ buffer;
    Array::Resize(buffer, 3);
    buffer[0]=NEW_2015_PROTOCOL_CODE;
    buffer[1]=0x11; //Command  -- Pump1
    buffer[2]=0x00; //set p1-off
    this->SendCmdPacket(buffer);
}

//---------------//
// Pump 2 on/off //
//---------------//
void spa_cmd::set_p2_hi_ON()
{
    array<unsigned char>^ buffer;
    Array::Resize(buffer, 3);
    buffer[0]=NEW_2015_PROTOCOL_CODE;
    buffer[1]=0x12; //Command  -- Pump2
    buffer[2]=0x02; //set p2-hi on
    this->SendCmdPacket(buffer);
}
void spa_cmd::set_p2_lo_ON()
{
    array<unsigned char>^ buffer;
    Array::Resize(buffer, 3);
    buffer[0]=NEW_2015_PROTOCOL_CODE;
    buffer[1]=0x12; //Command  -- Pump2
    buffer[2]=0x01; //set p2-Lo on
    this->SendCmdPacket(buffer);
}
void spa_cmd::set_p2_OFF()
{
    array<unsigned char>^ buffer;
    Array::Resize(buffer, 3);
    buffer[0]=NEW_2015_PROTOCOL_CODE;
    buffer[1]=0x12; //Command  -- Pump2
    buffer[2]=0x00; //set p2-off
    this->SendCmdPacket(buffer);
}

//---------------//
// Pump 3 on/off //
//---------------//
void spa_cmd::set_p3_hi_ON()
{
    array<unsigned char>^ buffer;
    Array::Resize(buffer, 3);
    buffer[0]=NEW_2015_PROTOCOL_CODE;
    buffer[1]=0x13; //Command  -- Pump3
    buffer[2]=0x02; //set p3-hi on
    this->SendCmdPacket(buffer);
}
void spa_cmd::set_p3_lo_ON()
{
    array<unsigned char>^ buffer;
    Array::Resize(buffer, 3);
    buffer[0]=NEW_2015_PROTOCOL_CODE;
    buffer[1]=0x13; //Command  -- Pump3
    buffer[2]=0x01; //set p3-Lo on
    this->SendCmdPacket(buffer);
}
void spa_cmd::set_p3_OFF()
{
    array<unsigned char>^ buffer;
    Array::Resize(buffer, 3);
    buffer[0]=NEW_2015_PROTOCOL_CODE;
    buffer[1]=0x13; //Command  -- Pump3
    buffer[2]=0x00; //set p3-off
    this->SendCmdPacket(buffer);
}

//---------------//
// Blower on/off //
//---------------//
void spa_cmd::set_blower_ON()
{
    array<unsigned char>^ buffer;
    Array::Resize(buffer, 3);
    buffer[0]=NEW_2015_PROTOCOL_CODE;
    buffer[1]=0x14; //Command  -- blower
    buffer[2]=0x01; //set on
    this->SendCmdPacket(buffer);
}
void spa_cmd::set_blower_OFF()
{
    array<unsigned char>^ buffer;
    Array::Resize(buffer, 3);
    buffer[0]=NEW_2015_PROTOCOL_CODE;
    buffer[1]=0x14; //Command  -- blower
    buffer[2]=0x00; //set off
    this->SendCmdPacket(buffer);
}

//=================//
// Lock functions  //
//=================//
void spa_cmd::set_unlock()
{
    array<unsigned char>^ buffer;
    Array::Resize(buffer, 3);
    buffer[0]=NEW_2015_PROTOCOL_CODE;
    buffer[1]=0x27; //Command  -- set lock....
    buffer[2]=0x00; //unlock
    this->SendCmdPacket(buffer);
}
void spa_cmd::set_Tlock()
{
    array<unsigned char>^ buffer;
    Array::Resize(buffer, 3);
    buffer[0]=NEW_2015_PROTOCOL_CODE;
    buffer[1]=0x27; //Command  -- set lock....
    buffer[2]=0x03; //lock temperature
    this->SendCmdPacket(buffer);
}
void spa_cmd::set_Plock()
{
    array<unsigned char>^ buffer;
    Array::Resize(buffer, 3);
    buffer[0]=NEW_2015_PROTOCOL_CODE;
    buffer[1]=0x27; //Command  -- set lock....
    buffer[2]=0x02; //lock Pumps
    this->SendCmdPacket(buffer);
}
void spa_cmd::set_Alock()
{
    array<unsigned char>^ buffer;
    Array::Resize(buffer, 3);
    buffer[0]=NEW_2015_PROTOCOL_CODE;
    buffer[1]=0x27; //Command  -- set lock....
    buffer[2]=0x01; //lock Panel all
    this->SendCmdPacket(buffer);
}
void spa_cmd::set_Slock()
{
    array<unsigned char>^ buffer;
    Array::Resize(buffer, 3);
    buffer[0]=NEW_2015_PROTOCOL_CODE;
    buffer[1]=0x27; //Command  -- set lock....
    buffer[2]=0x04; //service lock
    this->SendCmdPacket(buffer);
}

//===========//
// ECO modes //
//===========//
void spa_cmd::set_ECO_ON()
{
    array<unsigned char>^ buffer;
    Array::Resize(buffer, 3);
    buffer[0]=NEW_2015_PROTOCOL_CODE;
    buffer[1]=0x28; //Command  -- set mode....
    buffer[2]=0x01; //ECO on
    this->SendCmdPacket(buffer);
}
void spa_cmd::set_ECO_OFF()
{
    array<unsigned char>^ buffer;
    Array::Resize(buffer, 3);
    buffer[0]=NEW_2015_PROTOCOL_CODE;
    buffer[1]=0x28; //Command  -- set mode....
    buffer[2]=0x00; //ECO off
    this->SendCmdPacket(buffer);
}

//==========================//
// Readed command functions //
//==========================//////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------ 3X
void spa_cmd::do_cmd_30(array<unsigned char>^ pktBuf)
{
    this->iSPA.set_Adc=(pktBuf[4]<<8)|pktBuf[5];
    if(waitCmdCode==0x30) waitCmdCode=0; //reset waiting
}

void spa_cmd::do_cmd_31(array<unsigned char>^ pktBuf)
{
    //save value
    this->iSPA.time_year=pktBuf[4];
    this->iSPA.time_month=pktBuf[5];
    this->iSPA.time_day=pktBuf[6];
    this->iSPA.time_week=pktBuf[7];
    this->iSPA.time_hour=pktBuf[8];
    this->iSPA.time_min=pktBuf[9];
    //value checking & modify
    if(this->iSPA.time_month==0)this->iSPA.time_month=1;
    if(this->iSPA.time_day==0)this->iSPA.time_day=1;

    if(waitCmdCode==0x31)waitCmdCode=0; //reset waiting
}

void spa_cmd::do_cmd_32(array<unsigned char>^ pktBuf)
{
    //save value
    int group;
    group=pktBuf[4];
    this->iSPA.std_st_hour=pktBuf[5];
    this->iSPA.std_st_min=pktBuf[6];
    this->iSPA.std_dt_hour=pktBuf[7];
    this->iSPA.std_dt_min=pktBuf[8];
    this->iSPA.std_week=pktBuf[9];

    if(waitCmdCode==0x32)waitCmdCode=0; //reset waiting
}

void spa_cmd::do_cmd_33(array<unsigned char>^ pktBuf)
{
    //save value
    int group;
    group=pktBuf[4];
    if(group==1)
    {
        this->iSPA.eco_1_st_hour=pktBuf[5];
        this->iSPA.eco_1_st_min=pktBuf[6];
        this->iSPA.eco_1_dt_hour=pktBuf[7];
        this->iSPA.eco_1_dt_min=pktBuf[8];
        this->iSPA.eco_1_week=pktBuf[9];
        this->eco1_upated=true;
    }
    if(group==2)
    {
        this->iSPA.eco_2_st_hour=pktBuf[5];
        this->iSPA.eco_2_st_min=pktBuf[6];
        this->iSPA.eco_2_dt_hour=pktBuf[7];
        this->iSPA.eco_2_dt_min=pktBuf[8];
        this->iSPA.eco_2_week=pktBuf[9];
        this->eco2_upated=true;
    }
    if(group==3)
    {
        this->iSPA.eco_3_st_hour=pktBuf[5];
        this->iSPA.eco_3_st_min=pktBuf[6];
        this->iSPA.eco_3_dt_hour=pktBuf[7];
        this->iSPA.eco_3_dt_min=pktBuf[8];
        this->iSPA.eco_3_week=pktBuf[9];
        this->eco3_upated=true;
    }
    if(group==4)
    {
        this->iSPA.eco_4_st_hour=pktBuf[5];
        this->iSPA.eco_4_st_min=pktBuf[6];
        this->iSPA.eco_4_dt_hour=pktBuf[7];
        this->iSPA.eco_4_dt_min=pktBuf[8];
        this->iSPA.eco_4_week=pktBuf[9];
        this->eco4_upated=true;
    }
    if(waitCmdCode==0x33
        &&this->eco1_upated==true
        &&this->eco2_upated==true
        &&this->eco3_upated==true
        &&this->eco4_upated==true) waitCmdCode=0; //reset waiting
}

void spa_cmd::do_cmd_34(array<unsigned char>^ pktBuf)
{
    this->iSPA.uv_days=(pktBuf[4]<<8)|pktBuf[5];
    this->iSPA.filter_days=(pktBuf[6]<<8)|pktBuf[7];

    if(waitCmdCode==0x34)waitCmdCode=0; //reset waiting
}

void spa_cmd::do_cmd_35(array<unsigned char>^ pktBuf)
{
    //save value
    int fst_byte;
    fst_byte=pktBuf[4];
    this->iSPA.pf_value=fst_byte;
    this->iSPA.pf_st_hour=pktBuf[5];
    this->iSPA.pf_st_min=pktBuf[6];
    this->iSPA.pf_dt_hour=pktBuf[7];
    this->iSPA.pf_dt_min=pktBuf[8];

    if(waitCmdCode==0x35)waitCmdCode=0; //reset waiting
}

void spa_cmd::do_cmd_36(array<unsigned char>^ pktBuf)
{
    int sf_value;
    sf_value=pktBuf[4];
    this->iSPA.sf_value=sf_value;

    if(waitCmdCode==0x36)waitCmdCode=0; //reset waiting
}

void spa_cmd::do_cmd_37(array<unsigned char>^ pktBuf)
{
    int lock_value;
    lock_value=pktBuf[4];
    this->iSPA.lock_value=lock_value;
    if(lock_value==0)
    {
        this->iSPA.unlock=true;
        this->iSPA.lock_Tmpr=false;
        this->iSPA.lock_Pump=false;
        this->iSPA.lock_Panl=false;
        this->iSPA.lock_Func=false;
    }
    else if(lock_value==1)
    {     //panel all lock
        this->iSPA.unlock=false;
        this->iSPA.lock_Tmpr=false;
        this->iSPA.lock_Pump=false;
        this->iSPA.lock_Panl=true;
        this->iSPA.lock_Func=false;
    }
    else if(lock_value==2)
    {    //pump lock
        this->iSPA.unlock=false;
        this->iSPA.lock_Tmpr=false;
        this->iSPA.lock_Pump=true;
        this->iSPA.lock_Panl=false;
        this->iSPA.lock_Func=false;
    }
    else if(lock_value==3)
    {    //temperature lock
        this->iSPA.unlock=false;
        this->iSPA.lock_Tmpr=true;
        this->iSPA.lock_Pump=false;
        this->iSPA.lock_Panl=false;
        this->iSPA.lock_Func=false;
    }
    else
    {
        this->iSPA.unlock=false;
        this->iSPA.lock_Tmpr=false;
        this->iSPA.lock_Pump=false;
        this->iSPA.lock_Panl=false;
        this->iSPA.lock_Func=true;
    }
    if(waitCmdCode==0x37)waitCmdCode=0; //reset waiting
}

void spa_cmd::do_cmd_38(array<unsigned char>^ pktBuf)
{
    int eco_value;
    eco_value=pktBuf[4];
    if(eco_value==0)
        this->iSPA.ecoModeOn=false;
    else this->iSPA.ecoModeOn=true;

    if(waitCmdCode==0x38)waitCmdCode=0; //reset waiting
}
//------------------------------------------------------------------ 4X
void spa_cmd::do_cmd_40(array<unsigned char>^ pktBuf)
{
    unsigned int error_word;
    int i, j;
    //update values
    this->iSPA.state_H=pktBuf[4];
    this->iSPA.state_L=pktBuf[5];
    this->iSPA.err_B3=pktBuf[6];
    this->iSPA.err_B2=pktBuf[7];
    this->iSPA.err_B1=pktBuf[8];
    this->iSPA.err_B0=pktBuf[9];
    this->iSPA.water_T_state=pktBuf[10];
    this->iSPA.hiLmt_T_state=pktBuf[11];
    this->iSPA.waterLevel=pktBuf[12];
    //update UI values
    if((this->iSPA.state_L&0x01)!=0)this->iSPA.p1_lo_on=true; else this->iSPA.p1_lo_on=false;  //Bit 0 : Pump1_Lo ON/OFF
    if((this->iSPA.state_L&0x02)!=0)this->iSPA.p1_hi_on=true; else this->iSPA.p1_hi_on=false;  //Bit 1 : Pump1_Hi ON/OFF
    if((this->iSPA.state_L&0x04)!=0)this->iSPA.p2_lo_on=true; else this->iSPA.p2_lo_on=false;  //Bit 2 : Pump2_Lo ON/OFF
    if((this->iSPA.state_L&0x08)!=0)this->iSPA.p2_hi_on=true; else this->iSPA.p2_hi_on=false;  //Bit 3 : Pump2_Hi ON/OFF
    if((this->iSPA.state_L&0x10)!=0)this->iSPA.p3_lo_on=true; else this->iSPA.p3_lo_on=false;  //Bit 4 : Pump3_Lo ON/OFF
    if((this->iSPA.state_L&0x20)!=0)this->iSPA.p3_hi_on=true; else this->iSPA.p3_hi_on=false;  //Bit 5 : Pump3_Hi ON/OFF
    if((this->iSPA.state_L&0x40)!=0)this->iSPA.blower_on=true; else this->iSPA.blower_on=false;//Bit 6 : Blower ON/OFF
    if((this->iSPA.state_L&0x80)!=0)this->iSPA.circ_on=true; else this->iSPA.circ_on=false;    //Bit 7 : CIRC ON/OFF
    if((this->iSPA.state_H&0x01)!=0)this->iSPA.uv_on=true; else this->iSPA.uv_on=false;        //Bit 0 : UV ON/OFF
    if((this->iSPA.state_H&0x02)!=0)this->iSPA.uv_lock=true; else this->iSPA.uv_lock=false;    //Bit 1 : UV lock or not
    if((this->iSPA.state_H&0x04)!=0)this->iSPA.heater_on=true; else this->iSPA.heater_on=false;//Bit 2 : Heater ON/OFF
    if((this->iSPA.state_H&0x08)!=0)this->iSPA.ozon_on=true; else this->iSPA.ozon_on=false;    //Bit 3 : Ozon ON/OFF
    if((this->iSPA.state_H&0x40)!=0)this->iSPA.clean_cyc_on=true; else this->iSPA.clean_cyc_on=false;         //Bit 6 : clean cycle ON/OFF
    if((this->iSPA.state_H&0x80)!=0)this->iSPA.block_out_cyc_on=true; else this->iSPA.block_out_cyc_on=false; //Bit 7 : block-out cycle ON/OFF
    error_word=(this->iSPA.err_B3<<24)|(this->iSPA.err_B2<<16)|(this->iSPA.err_B1<<8)|this->iSPA.err_B0;
    //reset somethings before scan err-input
    this->iSPA.msg_index_1=SPA_NO_ERROR_DEFAULT_INDEX; //this value means no error code!
    this->iSPA.msg_index_2=SPA_NO_ERROR_DEFAULT_INDEX;
    this->iSPA.msg_index_3=SPA_NO_ERROR_DEFAULT_INDEX;
    this->iSPA.msg_index_4=SPA_NO_ERROR_DEFAULT_INDEX;
    this->iSPA.lock_Panl=false;
    this->iSPA.lock_Pump=false;
    this->iSPA.lock_Tmpr=false;
    this->iSPA.lock_Func=false;
    this->iSPA.relay_err_p1=false;
    this->iSPA.relay_err_p2=false;
    this->iSPA.relay_err_p3=false;
    this->iSPA.relay_err_ht=false;
    //scanning all bits..............................
    j=0;
    for(i=0; i<31; i++)
    { //scanning error bit
        if(((error_word>>i)&0x00000001)==0x00000001)
        { //some bit is 1....
//relays
            if(i==15)this->iSPA.relay_err_p1=true;
            if(i==16)this->iSPA.relay_err_p2=true;
            if(i==17)this->iSPA.relay_err_p3=true;
            if(i==18)this->iSPA.relay_err_ht=true;
            //recording locke related
            if(i==8) { this->iSPA.lock_Panl=true; this->iSPA.lock_value=1; }
            if(i==9) { this->iSPA.lock_Pump=true; this->iSPA.lock_value=2; }
            if(i==10) { this->iSPA.lock_Tmpr=true; this->iSPA.lock_value=3; }
            if(i==11) { this->iSPA.lock_Func=true; this->iSPA.lock_value=4; }
            //scan & save 4 error message
            if(j==0) this->iSPA.msg_index_1=i;
            if(j==1) this->iSPA.msg_index_2=i;
            if(j==2) this->iSPA.msg_index_3=i;
            if(j==3) this->iSPA.msg_index_4=i;
            if(j==4) this->iSPA.msg_more_than_4=true;
            j++;
        }
    }//for-loop
    //check something after scanning
    if(this->iSPA.lock_Func==false&&this->iSPA.lock_Panl==false&&
        this->iSPA.lock_Pump==false&&this->iSPA.lock_Tmpr==false)
        this->iSPA.unlock=true;
    else this->iSPA.unlock=false;
}

void spa_cmd::do_cmd_41(array<unsigned char>^ pktBuf)
{
    this->iSPA.cur_Adc_0=(pktBuf[4]<<8)|pktBuf[5];
    this->iSPA.cur_Adc_1=(pktBuf[6]<<8)|pktBuf[7];
    this->iSPA.cur_Adc_2=(pktBuf[8]<<8)|pktBuf[9];
    this->iSPA.cur_Adc_3=(pktBuf[10]<<8)|pktBuf[11];
    this->iSPA.cur_Adc_4=(pktBuf[12]<<8)|pktBuf[13];
    //test only
    //this->iSPA.cur_Adc_3 = 439;  //voltage 439=215V
}

void spa_cmd::do_cmd_42(array<unsigned char>^ pktBuf)
{
    this->iSPA.max_Adc_0=(pktBuf[4]<<8)|pktBuf[5];
    this->iSPA.max_Adc_1=(pktBuf[6]<<8)|pktBuf[7];
    this->iSPA.max_Adc_2=(pktBuf[8]<<8)|pktBuf[9];
    this->iSPA.max_Adc_3=(pktBuf[10]<<8)|pktBuf[11];
    this->iSPA.max_Adc_4=(pktBuf[12]<<8)|pktBuf[13];
    //test only
    //this->iSPA.max_Adc_3 = 484;  //voltage 484=235V
    //
    if(waitCmdCode==0x42) waitCmdCode=0;
}

void spa_cmd::do_cmd_43(array<unsigned char>^ pktBuf)
{
    this->iSPA.min_Adc_0=(pktBuf[4]<<8)|pktBuf[5];
    this->iSPA.min_Adc_1=(pktBuf[6]<<8)|pktBuf[7];
    this->iSPA.min_Adc_2=(pktBuf[8]<<8)|pktBuf[9];
    this->iSPA.min_Adc_3=(pktBuf[10]<<8)|pktBuf[11];
    this->iSPA.min_Adc_4=(pktBuf[12]<<8)|pktBuf[13];
    //test only
    //this->iSPA.min_Adc_3 = 417;  //voltage 417=205V
    //
    if(waitCmdCode==0x43) waitCmdCode=0;
}

void spa_cmd::do_cmd_44(array<unsigned char>^ pktBuf)
{
    this->iSPA.accumelate_power=(pktBuf[4]<<8)|pktBuf[5];
    if(waitCmdCode==0x44) waitCmdCode=0;
}

void spa_cmd::do_cmd_45(array<unsigned char>^ pktBuf)
{
    this->iSPA.accumelate_hour=(pktBuf[4]<<8)|pktBuf[5];
    if(waitCmdCode==0x45) waitCmdCode=0;
}

void spa_cmd::do_cmd_46(array<unsigned char>^ pktBuf)
{
    this->iSPA.operation_freq=pktBuf[4];
    if(waitCmdCode==0x46) waitCmdCode=0;
}

void spa_cmd::do_cmd_70(array<unsigned char>^ pktBuf)
{
    this->iSPA.eeprom_addr=(pktBuf[4]<<8)|pktBuf[5];
    this->iSPA.cmd70_B1=pktBuf[6];
    this->iSPA.cmd70_B2=pktBuf[7];
    this->iSPA.cmd70_B3=pktBuf[8];
    this->iSPA.cmd70_B4=pktBuf[9];
    this->iSPA.cmd70_B5=pktBuf[10];
    this->iSPA.cmd70_B6=pktBuf[11];
    this->iSPA.cmd70_B7=pktBuf[12];
    this->iSPA.cmd70_B8=pktBuf[13];
    this->iSPA.new_cmd70=true;
    if(waitCmdCode==0x70) waitCmdCode=0;
}

void spa_cmd::do_cmd_81(array<unsigned char>^ pktBuf)
{
    this->iSPA.p1_mode=pktBuf[4];
    if(waitCmdCode==0x81) waitCmdCode=0;
}

void spa_cmd::do_cmd_82(array<unsigned char>^ pktBuf)
{
    this->iSPA.p2_mode=pktBuf[4];
    if(waitCmdCode==0x82) waitCmdCode=0;
}

void spa_cmd::do_cmd_83(array<unsigned char>^ pktBuf)
{
    this->iSPA.p3_mode=pktBuf[4];
    if(waitCmdCode==0x83) waitCmdCode=0;
}

void spa_cmd::do_cmd_87(array<unsigned char>^ pktBuf)
{
    this->iSPA.spa_w_Voltage=pktBuf[4];
    if(waitCmdCode==0x87) waitCmdCode=0;
}

void spa_cmd::do_cmd_96(array<unsigned char>^ pktBuf)
{
    int blower_realy;
    blower_realy=pktBuf[4];
    if(blower_realy==0) this->iSPA.has_blower=false;
    else this->iSPA.has_blower=true;
    if(waitCmdCode==0x96) waitCmdCode=0;
}

void spa_cmd::do_cmd_99(array<unsigned char>^ pktBuf)
{
    int HiLoEnd;
    HiLoEnd=pktBuf[4];
    if(HiLoEnd==2) this->iSPA.is_HighEnd_Fsch=false;   //2=low-end, us PF/SF
    else this->iSPA.is_HighEnd_Fsch=true;                 //1 or others = high-end, use filter schedule
    if(waitCmdCode==0x99) waitCmdCode=0;
}