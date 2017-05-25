#include "RDS_project.h"
#include "nas_user.h"

using namespace RDS_NAS;

nas_user::nas_user()
{
    HasAdminIni=false;
    HasUsersIni=false;
    HasDealerIni=false;
    Has_Model_AD_Ini=false;
    Base_dir=RDS_NAS_ROOT_DIR;
}

//-----------------------//
//  checking admin file  //
//-----------------------//
Boolean nas_user::Check_Admin_Ini()
{
    String^ fullfilename;
    fullfilename=this->Base_dir+RDS_NAS_ADMIN_FILENAME;
    return File::Exists(fullfilename);
}

//----------------------//
//  checking user file  //
//----------------------//
Boolean nas_user::Check_User_Ini()
{
    String^ fullfilename;
    fullfilename=this->Base_dir+RDS_NAS_USERLIST_FILENAME;
    return File::Exists(fullfilename);
}

//--------------------------//
//  checking Model_AD file  //
//--------------------------//
Boolean nas_user::Check_Model_AD_Ini()
{
    String^ fullfilename;
    fullfilename=RDS_NAS_ROOT_DIR+RDS_NAS_SPA_MODEL_FILENAME;
    return File::Exists(fullfilename);
}

//------------------------//
//  checking Dealer file  //
//------------------------//
Boolean nas_user::Check_Dealer_Ini()
{
    String^ fullfilename;
    fullfilename=this->Base_dir+RDS_NAS_DEALER_LIST_FILENAME;
    return File::Exists(fullfilename);
}

//---------------------------------//
// checking person logined or not  //
//---------------------------------//
Boolean nas_user::Check_Person_Logined(unsigned int User_no, String^ LastAct, String^ LastTime)
{
    String^ fullfilename;
    fullfilename=this->Base_dir+"\\"+User_no+".lock";

    if(File::Exists(fullfilename)==false)
    {
        return false;
    }
    else
    {
        //read content of lock file.
        StreamReader^ din=File::OpenText(fullfilename);
        String^ str;
        LastAct=din->ReadLine();   //line-1
        LastTime=din->ReadLine();  //line-2
        din->Close();
        return true;
    }
}

//---------------------------//
// Lock person logined       //
//---------------------------//
//return 0  = OK
//      -1  = file existed, maybe already locked by another machine!!!
int nas_user::Lock_Person_Login(unsigned int User_no, String^ TimeString)
{
    String^ fullfilename;
    String^ ActString;
    fullfilename=this->Base_dir+"\\"+User_no+".lock";

    if(File::Exists(fullfilename)==true)
    {
        //Error!!!
        return -1;
    }
    else
    {
        //write (overwrite)
        StreamWriter^ sw=gcnew StreamWriter(fullfilename);
        ActString="login RDS";
        sw->WriteLine(ActString); //line-1
        sw->WriteLine(TimeString);//line-2
        sw->Close();
        return 0;
    }
}

//---------------------------//
// Unlock person logined     //
//---------------------------//
//return 0  = OK
//      -1  = file not found
int nas_user::Unlock_Person_Login(unsigned int User_no)
{
    String^ fullfilename;
    fullfilename=this->Base_dir+"\\"+User_no+".lock";

    if(File::Exists(fullfilename)==false)
    {
        //Error!!!
        return -1;
    }
    else
    {
        //delete lick file
        File::Delete(fullfilename);
    }
}

//-----------------//
//  Encode string  //
//-----------------//
String^ nas_user::nasStringEncode(String^ inStr)
{
    String^ outStr="";
    int i;
    for(i=0; i<inStr->Length; i++)
    {
        if(inStr->Substring(i, 1)=="a") outStr=outStr+"5";
        else if(inStr->Substring(i, 1)=="b") outStr=outStr+"S";
        else if(inStr->Substring(i, 1)=="c") outStr=outStr+"T";
        else if(inStr->Substring(i, 1)=="d") outStr=outStr+"U";
        else if(inStr->Substring(i, 1)=="e") outStr=outStr+"6";
        else if(inStr->Substring(i, 1)=="f") outStr=outStr+"V";
        else if(inStr->Substring(i, 1)=="g") outStr=outStr+"W";
        else if(inStr->Substring(i, 1)=="h") outStr=outStr+"z";
        else if(inStr->Substring(i, 1)=="i") outStr=outStr+"7";
        else if(inStr->Substring(i, 1)=="j") outStr=outStr+"u";
        else if(inStr->Substring(i, 1)=="k") outStr=outStr+"v";
        else if(inStr->Substring(i, 1)=="l") outStr=outStr+"w";
        else if(inStr->Substring(i, 1)=="m") outStr=outStr+"x";
        else if(inStr->Substring(i, 1)=="n") outStr=outStr+"y";
        else if(inStr->Substring(i, 1)=="o") outStr=outStr+"8";
        else if(inStr->Substring(i, 1)=="p") outStr=outStr+"E";
        else if(inStr->Substring(i, 1)=="q") outStr=outStr+"F";
        else if(inStr->Substring(i, 1)=="r") outStr=outStr+"G";
        else if(inStr->Substring(i, 1)=="s") outStr=outStr+"H";
        else if(inStr->Substring(i, 1)=="t") outStr=outStr+"I";
        else if(inStr->Substring(i, 1)=="u") outStr=outStr+"J";
        else if(inStr->Substring(i, 1)=="v") outStr=outStr+"K";
        else if(inStr->Substring(i, 1)=="w") outStr=outStr+"L";
        else if(inStr->Substring(i, 1)=="x") outStr=outStr+"M";
        else if(inStr->Substring(i, 1)=="y") outStr=outStr+"N";
        else if(inStr->Substring(i, 1)=="z") outStr=outStr+"O";
        else if(inStr->Substring(i, 1)=="0") outStr=outStr+"A";
        else if(inStr->Substring(i, 1)=="1") outStr=outStr+"B";
        else if(inStr->Substring(i, 1)=="2") outStr=outStr+"9";
        else if(inStr->Substring(i, 1)=="3") outStr=outStr+"C";
        else if(inStr->Substring(i, 1)=="4") outStr=outStr+"D";
        else if(inStr->Substring(i, 1)=="A") outStr=outStr+"0";
        else if(inStr->Substring(i, 1)=="B") outStr=outStr+"P";
        else if(inStr->Substring(i, 1)=="C") outStr=outStr+"Q";
        else if(inStr->Substring(i, 1)=="D") outStr=outStr+"R";
        else if(inStr->Substring(i, 1)=="E") outStr=outStr+"1";
        else if(inStr->Substring(i, 1)=="F") outStr=outStr+"X";
        else if(inStr->Substring(i, 1)=="G") outStr=outStr+"Y";
        else if(inStr->Substring(i, 1)=="H") outStr=outStr+"Z";
        else if(inStr->Substring(i, 1)=="I") outStr=outStr+"2";
        else if(inStr->Substring(i, 1)=="J") outStr=outStr+"e";
        else if(inStr->Substring(i, 1)=="K") outStr=outStr+"f";
        else if(inStr->Substring(i, 1)=="L") outStr=outStr+"g";
        else if(inStr->Substring(i, 1)=="M") outStr=outStr+"h";
        else if(inStr->Substring(i, 1)=="N") outStr=outStr+"i";
        else if(inStr->Substring(i, 1)=="O") outStr=outStr+"3";
        else if(inStr->Substring(i, 1)=="P") outStr=outStr+"j";
        else if(inStr->Substring(i, 1)=="Q") outStr=outStr+"k";
        else if(inStr->Substring(i, 1)=="R") outStr=outStr+"l";
        else if(inStr->Substring(i, 1)=="S") outStr=outStr+"m";
        else if(inStr->Substring(i, 1)=="T") outStr=outStr+"n";
        else if(inStr->Substring(i, 1)=="U") outStr=outStr+"o";
        else if(inStr->Substring(i, 1)=="V") outStr=outStr+"p";
        else if(inStr->Substring(i, 1)=="W") outStr=outStr+"q";
        else if(inStr->Substring(i, 1)=="X") outStr=outStr+"r";
        else if(inStr->Substring(i, 1)=="Y") outStr=outStr+"s";
        else if(inStr->Substring(i, 1)=="Z") outStr=outStr+"t";
        else if(inStr->Substring(i, 1)=="5") outStr=outStr+"a";
        else if(inStr->Substring(i, 1)=="6") outStr=outStr+"b";
        else if(inStr->Substring(i, 1)=="7") outStr=outStr+"4";
        else if(inStr->Substring(i, 1)=="8") outStr=outStr+"c";
        else if(inStr->Substring(i, 1)=="9") outStr=outStr+"d";
        else  outStr=outStr+inStr->Substring(i, 1);
    }
    return outStr;
}

//-----------------//
//  Decode string  //
//-----------------//
String^ nas_user::nasStringDecode(String^ inStr)
{
    String^ outStr="";
    int i;
    for(i=0; i<inStr->Length; i++)
    {
        if(inStr->Substring(i, 1)=="5") outStr=outStr+"a";
        else if(inStr->Substring(i, 1)=="S") outStr=outStr+"b";
        else if(inStr->Substring(i, 1)=="T") outStr=outStr+"c";
        else if(inStr->Substring(i, 1)=="U") outStr=outStr+"d";
        else if(inStr->Substring(i, 1)=="6") outStr=outStr+"e";
        else if(inStr->Substring(i, 1)=="V") outStr=outStr+"f";
        else if(inStr->Substring(i, 1)=="W") outStr=outStr+"g";
        else if(inStr->Substring(i, 1)=="z") outStr=outStr+"h";
        else if(inStr->Substring(i, 1)=="7") outStr=outStr+"i";
        else if(inStr->Substring(i, 1)=="u") outStr=outStr+"j";
        else if(inStr->Substring(i, 1)=="v") outStr=outStr+"k";
        else if(inStr->Substring(i, 1)=="w") outStr=outStr+"l";
        else if(inStr->Substring(i, 1)=="x") outStr=outStr+"m";
        else if(inStr->Substring(i, 1)=="y") outStr=outStr+"n";
        else if(inStr->Substring(i, 1)=="8") outStr=outStr+"o";
        else if(inStr->Substring(i, 1)=="E") outStr=outStr+"p";
        else if(inStr->Substring(i, 1)=="F") outStr=outStr+"q";
        else if(inStr->Substring(i, 1)=="G") outStr=outStr+"r";
        else if(inStr->Substring(i, 1)=="H") outStr=outStr+"s";
        else if(inStr->Substring(i, 1)=="I") outStr=outStr+"t";
        else if(inStr->Substring(i, 1)=="J") outStr=outStr+"u";
        else if(inStr->Substring(i, 1)=="K") outStr=outStr+"v";
        else if(inStr->Substring(i, 1)=="L") outStr=outStr+"w";
        else if(inStr->Substring(i, 1)=="M") outStr=outStr+"x";
        else if(inStr->Substring(i, 1)=="N") outStr=outStr+"y";
        else if(inStr->Substring(i, 1)=="O") outStr=outStr+"z";
        else if(inStr->Substring(i, 1)=="A") outStr=outStr+"0";
        else if(inStr->Substring(i, 1)=="B") outStr=outStr+"1";
        else if(inStr->Substring(i, 1)=="9") outStr=outStr+"2";
        else if(inStr->Substring(i, 1)=="C") outStr=outStr+"3";
        else if(inStr->Substring(i, 1)=="D") outStr=outStr+"4";
        else if(inStr->Substring(i, 1)=="0") outStr=outStr+"A";
        else if(inStr->Substring(i, 1)=="P") outStr=outStr+"B";
        else if(inStr->Substring(i, 1)=="Q") outStr=outStr+"C";
        else if(inStr->Substring(i, 1)=="R") outStr=outStr+"D";
        else if(inStr->Substring(i, 1)=="1") outStr=outStr+"E";
        else if(inStr->Substring(i, 1)=="X") outStr=outStr+"F";
        else if(inStr->Substring(i, 1)=="Y") outStr=outStr+"G";
        else if(inStr->Substring(i, 1)=="Z") outStr=outStr+"H";
        else if(inStr->Substring(i, 1)=="2") outStr=outStr+"I";
        else if(inStr->Substring(i, 1)=="e") outStr=outStr+"J";
        else if(inStr->Substring(i, 1)=="f") outStr=outStr+"K";
        else if(inStr->Substring(i, 1)=="g") outStr=outStr+"L";
        else if(inStr->Substring(i, 1)=="h") outStr=outStr+"M";
        else if(inStr->Substring(i, 1)=="i") outStr=outStr+"N";
        else if(inStr->Substring(i, 1)=="3") outStr=outStr+"O";
        else if(inStr->Substring(i, 1)=="j") outStr=outStr+"P";
        else if(inStr->Substring(i, 1)=="k") outStr=outStr+"Q";
        else if(inStr->Substring(i, 1)=="l") outStr=outStr+"R";
        else if(inStr->Substring(i, 1)=="m") outStr=outStr+"S";
        else if(inStr->Substring(i, 1)=="n") outStr=outStr+"T";
        else if(inStr->Substring(i, 1)=="o") outStr=outStr+"U";
        else if(inStr->Substring(i, 1)=="p") outStr=outStr+"V";
        else if(inStr->Substring(i, 1)=="q") outStr=outStr+"W";
        else if(inStr->Substring(i, 1)=="r") outStr=outStr+"X";
        else if(inStr->Substring(i, 1)=="s") outStr=outStr+"Y";
        else if(inStr->Substring(i, 1)=="t") outStr=outStr+"Z";
        else if(inStr->Substring(i, 1)=="a") outStr=outStr+"5";
        else if(inStr->Substring(i, 1)=="b") outStr=outStr+"6";
        else if(inStr->Substring(i, 1)=="4") outStr=outStr+"7";
        else if(inStr->Substring(i, 1)=="c") outStr=outStr+"8";
        else if(inStr->Substring(i, 1)=="d") outStr=outStr+"9";
        else  outStr=outStr+inStr->Substring(i, 1);
    }
    return outStr;
}

//-----------------------//
//  get Spa Company Info //   (from admin file)
//-----------------------//
// return 0 : normal case
// return -1 : error
int nas_user::get_SpaComapny()
{
    //
    String^ Admin_ID;
    String^ Admin_Name;
    String^ Admin_PW;
    unsigned int Admin_SQ_index;
    String^ Admin_SQanswer;
    String^ Admin_AuthLevel;
    //
    String^ fullfilename;
    String^ str;
    int count=0;
    fullfilename=this->Base_dir+RDS_NAS_ADMIN_FILENAME;
    //(TBD) try--catch
    StreamReader^ din=File::OpenText(fullfilename);
    do
    {
        count++;
        str=din->ReadLine();
        if(str!=nullptr)
        {
            if(count==1) Admin_Name=nasStringDecode(str);
            if(count==2) Admin_ID=nasStringDecode(str);
            if(count==3) Admin_PW=nasStringDecode(str);
            if(count==4) Admin_AuthLevel=nasStringDecode(str);
            if(count==5) Admin_SQ_index=Convert::ToInt32(str, 10);
            if(count==6) Admin_SQanswer=nasStringDecode(str);
            if(count==7) this->SpaCompanyCode=nasStringDecode(str);
            if(count==8) this->SpaCompanyName=nasStringDecode(str);
        }
        else
        {
            din->Close();
            return -1;
        }
    } while(count<8); //<<<<<<<<<<<<<<<<< Admin.ini total has only 8 lines !!!!!
    din->Close();
    return 0;
}

//---------------------------//
// Get Dealer's Company Name //
//---------------------------//
// Just return the company name if found Compamy code in Dealers.ini
// This function dont change iNas.base_dir (dont change any member of iNas)
String^ nas_user::Get_Dealer_ComName(String^ CompanyCode)
{
    String^ rtnString;
    Boolean found_Dealer=false;
    //normal process
    String^ fullfilename;
    String^ numberStr;
    String^ ComCode_inFile;
    String^ ComName_inFile;
    String^ ZipCode_inFile;
    fullfilename=RDS_NAS_ROOT_DIR+RDS_NAS_DEALER_LIST_FILENAME;

    //basic checking --------------
    if(this->Base_dir!=RDS_NAS_ROOT_DIR)
    {
        rtnString=NO_DEALER_COM_CODE;
        return rtnString;
    }
    if(this->HasDealerIni==false)
    {
        rtnString=DEFAULT_SPA_COM_NAME;
        return rtnString;
    }
    //reading dealers.ini
    StreamReader^ din=File::OpenText(fullfilename);

    //first, read the total dealer number
    numberStr=din->ReadLine();
    this->total_dealer_count=Convert::ToInt32(numberStr, 10);

    //scan for user 0,1,2,3.....
    int i=0;
    do
    {
        ComCode_inFile=this->nasStringDecode(din->ReadLine());
        ComName_inFile=this->nasStringDecode(din->ReadLine());
        ZipCode_inFile=this->nasStringDecode(din->ReadLine());
        if(CompanyCode==ComCode_inFile)
        { //found dealer!!!!!
            found_Dealer=true;
            break;
        }
        i++;
    } while(i<this->total_dealer_count);
    din->Close();

    //final checking
    if(found_Dealer==false)
    {
        rtnString=NO_DEALER_COM_CODE;
        return rtnString;
    }
    else
    {
        rtnString=ComName_inFile;
        return rtnString;
    }
}

//---------------//
//  user login   //
//---------------//
// PS: assume users.ini file exist
//return = 0  : ok, sucessful
//return = -1 : fail, ID not found
//return = -2 : fail, ID correct, but PW fail
//return = -3 : fail, ID/PW OK, but already logined !!!!
int nas_user::user_Login(
    String^ user_ID,
    String^ user_PW)
{
    Boolean found_ID=false;
    //normal process
    String^ fullfilename;
    String^ numberStr;
    String^ Name_inFile;
    String^ ID_inFile;
    String^ PW_inFile;
    String^ AuthLevel_inFile;
    Boolean HadLogined;
    String^ LastAct;
    String^ LastTime;
    fullfilename=this->Base_dir+RDS_NAS_USERLIST_FILENAME;
    StreamReader^ din=File::OpenText(fullfilename);

    //first, read the total user number
    numberStr=din->ReadLine();
    this->total_user_count=Convert::ToInt32(numberStr, 10);

    //scan for user 0,1,2,3.....
    int i=0;
    do
    {
        Name_inFile=this->nasStringDecode(din->ReadLine());
        ID_inFile=this->nasStringDecode(din->ReadLine());
        PW_inFile=this->nasStringDecode(din->ReadLine());
        AuthLevel_inFile=this->nasStringDecode(din->ReadLine());
        if(user_ID==ID_inFile)
        { //found user !!!!!
            found_ID=true;
            //checking he/she logined or not
            HadLogined=Check_Person_Logined(i+1, LastAct, LastTime);
            if(HadLogined==false)
            {
                this->userNo=i+1;
                this->userName=Name_inFile;
                this->user_AuthLevel=AuthLevel_inFile;
                break;
            }
        }
        i++;
    } while(i<this->total_user_count);
    din->Close();

    //final checking
    if(found_ID==false) { return -1; }
    else if(HadLogined==true) { return -3; }
    else if(user_PW!=PW_inFile) { return -2; }
    else { return  0; }
}