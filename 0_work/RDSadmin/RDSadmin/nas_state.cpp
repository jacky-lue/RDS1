//project defines
#include "RDSadmin_project.h"
//
#include "nas_state.h"

using namespace RDS_NAS;

nas_state::nas_state()
{
    HasAdminIni=false;
    HasUsersIni=false;
    HasRDSdir=false;
    Base_dir=RDS_NAS_ROOT_DIR;
    current_user_no=-1;
}

//--------------------------//
//  checking RDS Driver     //
//--------------------------//
Boolean nas_state::Check_RDS_driver()
{
    String^ RDSpath;
    RDSpath=RDS_NAS_DRIVER;
    return Directory::Exists(RDSpath);
}

//--------------------------//
//  checking RDS Directory  //
//--------------------------//
Boolean nas_state::Check_RDS_dir()
{
    String^ RDSpath;
    RDSpath=this->Base_dir;
    return Directory::Exists(RDSpath);
}

//-----------------------//
//  checking admin file  //
//-----------------------//
Boolean nas_state::Check_Admin_Ini()
{
    String^ fullfilename;
    fullfilename=this->Base_dir+RDS_NAS_ADMIN_FILENAME;
    return File::Exists(fullfilename);
}

//----------------------//
//  checking user file  //
//----------------------//
Boolean nas_state::Check_User_Ini()
{
    String^ fullfilename;
    fullfilename=this->Base_dir+RDS_NAS_USERLIST_FILENAME;
    return File::Exists(fullfilename);
}

//------------------------//
//  checking Dealer file  //
//------------------------//
Boolean nas_state::Check_Dealer_Ini()
{
    String^ fullfilename;
    fullfilename=this->Base_dir+RDS_NAS_DEALER_LIST_FILENAME;
    return File::Exists(fullfilename);
}

//--------------------------//
//  checking Model_AD file  //  //Only one file in Root Directory!!
//--------------------------//
Boolean nas_state::Check_Model_AD_Ini()
{
    String^ fullfilename;
    fullfilename=RDS_NAS_ROOT_DIR+RDS_NAS_SPA_MODEL_FILENAME;
    return File::Exists(fullfilename);
}

//--------------------------------//
//  checking Company Code format  //
//--------------------------------//
Boolean nas_state::Is_com_code_fmt_OK(String^ ComCode)
{
    if(ComCode->Length==RDS_NAS_COM_CODE_LENGTH){
        return true;
    }
    else{
        return false;
    }
}

//---------------------------------//
// checking person logined or not  //
//---------------------------------//
Boolean nas_state::Check_Person_Logined(unsigned int User_no, String^ LastAct, String^ LastTime)
{
    String^ fullfilename;
    fullfilename=this->Base_dir+"\\"+User_no+".lock";

    if(File::Exists(fullfilename)==false){
        return false;
    }
    else{
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
int nas_state::Lock_Person_Login(unsigned int User_no, String^ TimeString)
{
    String^ fullfilename;
    String^ ActString;
    fullfilename=this->Base_dir+"\\"+User_no+".lock";

    if(File::Exists(fullfilename)==true){
        //Error!!!
        return -1;
    }
    else{
        //write (overwrite)
        StreamWriter^ sw=gcnew StreamWriter(fullfilename);
        ActString="login RDSadmin";
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
int nas_state::Unlock_Person_Login(unsigned int User_no)
{
    String^ fullfilename;
    fullfilename=this->Base_dir+"\\"+User_no+".lock";

    if(File::Exists(fullfilename)==false){
        //Error!!!
        return -1;
    }
    else{
        //delete lick file
        File::Delete(fullfilename);
    }
}

//----------------------------------//
//  checking state/Zip Code format  //
//----------------------------------//
Boolean nas_state::Is_Zip_code_fmt_OK(String^ ZipCode)
{
    int i;
    if(ZipCode->Length==RDS_NAS_ZIP_CODE_LENGTH){
        for(i=0; i<RDS_NAS_ZIP_CODE_LENGTH; i++){
            if(i<RDS_NAS_ZIP_LEADING_CHAR){
                if(false==Char::IsUpper(ZipCode, i)) return false;
            }
            else{
                if(false==Char::IsDigit(ZipCode, i)) return false;
            }
        }
        return true; //all char are meet format.
    }
    else{
        return false; //Nt match string-length.
    }
}

//---------------------------------//
//  check current user authoriy OK //
//---------------------------------//
// input:
//     Authority_allow :  Bit0 ==> MIS
//                        Bit1 ==> Manager
//                        Bit2 ==> C.R.
//                        Bit3 ==> Engeer
Boolean nas_state::Authority_isOK(unsigned Authority_allow)
{
    if(this->LoginUser_AuthLevel==RDS_NAS_AUTHORITY_LEVEL_0
        &&(Authority_allow&0x01)==0x01){
        return true;
    }
    else if(this->LoginUser_AuthLevel==RDS_NAS_AUTHORITY_LEVEL_1
        &&(Authority_allow&0x02)==0x02){
        return true;
    }
    else if(this->LoginUser_AuthLevel==RDS_NAS_AUTHORITY_LEVEL_2
        &&(Authority_allow&0x04)==0x04){
        return true;
    }
    else if(this->LoginUser_AuthLevel==RDS_NAS_AUTHORITY_LEVEL_3
        &&(Authority_allow&0x08)==0x08){
        return true;
    }
    else{
        return false;
    }
}

//=============================================================================
//--------------------//
//  Build Dir tree    //
//--------------------//
void nas_state::Build_All_Dir()
{
    String^ tmpPath;
    tmpPath=this->Base_dir; //build root directory
    if(Directory::Exists(tmpPath)==false)
        Directory::CreateDirectory(tmpPath);
    tmpPath=this->Base_dir+RDS_NAS_REPORT_DIR;
    Directory::CreateDirectory(tmpPath);
    tmpPath=this->Base_dir+RDS_NAS_REPORT_DIR+RDS_NAS_BY_UID_DIR;
    Directory::CreateDirectory(tmpPath);
    tmpPath=this->Base_dir+RDS_NAS_REPORT_DIR+RDS_NAS_BY_DATE_DIR;
    Directory::CreateDirectory(tmpPath);
    tmpPath=this->Base_dir+RDS_NAS_LOG_DIR;
    Directory::CreateDirectory(tmpPath);
    tmpPath=this->Base_dir+RDS_NAS_SERVICE_DIR;
    Directory::CreateDirectory(tmpPath);
    tmpPath=this->Base_dir+RDS_NAS_SERVICE_DIR+RDS_NAS_CLOSE_DATE_DIR;
    Directory::CreateDirectory(tmpPath);
    //copy default Model_AD.ini file
    tmpPath=this->Base_dir+RDS_NAS_SPA_MODEL_FILENAME;
    File::Copy(this->Default_moodel_file, tmpPath);
}

//-----------------------//
//  Write to admin file  //
//-----------------------//
void nas_state::Write_Admin_Ini(
    String^ Admin_ID,
    String^ Admin_Name,
    String^ Admin_PW,
    String^ Admin_AuthLevel,
    unsigned int Admin_SQ_index,
    String^ Admin_SQanswer,
    String^ CompanyCode,
    String^ CompanyName
)
{
    String^ fullfilename;
    fullfilename=this->Base_dir+RDS_NAS_ADMIN_FILENAME;
    StreamWriter^ sw=gcnew StreamWriter(fullfilename);
    String^ str_1;
    String^ str_2;
    String^ str_3;
    String^ str_4;
    String^ str_5;
    String^ str_6;
    String^ str_7;
    str_1=nasStringEncode(Admin_Name);
    str_2=nasStringEncode(Admin_ID);
    str_3=nasStringEncode(Admin_PW);
    str_4=nasStringEncode(Admin_AuthLevel);
    str_5=nasStringEncode(Admin_SQanswer);
    str_6=nasStringEncode(CompanyCode);
    str_7=nasStringEncode(CompanyName);
    //
    sw->WriteLine(str_1);
    sw->WriteLine(str_2);
    sw->WriteLine(str_3);
    sw->WriteLine(str_4);
    sw->WriteLine(Admin_SQ_index);
    sw->WriteLine(str_5);
    sw->WriteLine(str_6);
    sw->WriteLine(str_7);
    sw->Close();
    //
    this->Admin_ID=Admin_ID;
    this->Admin_Name=Admin_Name;
    this->Admin_PW=Admin_PW;
    this->Admin_AuthLevel=Admin_AuthLevel;
    this->Admin_SQ_index=Admin_SQ_index;
    this->Admin_SQanswer=Admin_SQanswer;
    this->CompanyCode=CompanyCode;
    this->CompanyName=CompanyName;
}

//-----------------------//
//  Read from admin file //
//-----------------------//
// return 0 : normal case
// return -1 : error
int nas_state::Read_Admin_ini()
{
    String^ fullfilename;
    String^ str;
    int count=0;
    fullfilename=this->Base_dir+RDS_NAS_ADMIN_FILENAME;
    //(TBD) try--catch
    StreamReader^ din=File::OpenText(fullfilename);
    do{
        count++;
        str=din->ReadLine();
        if(str!=nullptr){
            if(count==1) this->Admin_Name=nasStringDecode(str);
            if(count==2) this->Admin_ID=nasStringDecode(str);
            if(count==3) this->Admin_PW=nasStringDecode(str);
            if(count==4) this->Admin_AuthLevel=nasStringDecode(str);
            if(count==5) this->Admin_SQ_index=Convert::ToInt32(str, 10);
            if(count==6) this->Admin_SQanswer=nasStringDecode(str);
            if(count==7) this->CompanyCode=nasStringDecode(str);
            if(count==8) this->CompanyName=nasStringDecode(str);
        }
        else{
            din->Close();
            return -1;
        }
    } while(count<8); //<<<<<<<<<<<<<<<<< Admin.ini total has only 8 lines !!!!!
    din->Close();
    return 0;
}

//--------------------//
//  Delete admin file //
//--------------------//
int nas_state::Delete_Admin_ini()
{
    String^ fullfilename;
    fullfilename=this->Base_dir+RDS_NAS_ADMIN_FILENAME;
    File::Delete(fullfilename);
    return 0;
}

//-----------------------//
//  Overwrite admin file //
//-----------------------//
//PS: assume users.ini file exist
void nas_state::Overwrite_Admin_inUsers(
    String^ Admin_ID,
    String^ Admin_Name,
    String^ Admin_PW,
    String^ Admin_AuthLevel
)
{
    String^ fullfilename1;
    String^ fullfilename2;
    String^ numberStr;
    String^ str_1;
    String^ str_2;
    String^ str_3;
    String^ str_4;
    String^ Line_inFile;
    str_1=nasStringEncode(Admin_Name);
    str_2=nasStringEncode(Admin_ID);
    str_3=nasStringEncode(Admin_PW);
    str_4=nasStringEncode(Admin_AuthLevel);
    fullfilename1=this->Base_dir+RDS_NAS_USERLIST_FILENAME;
    fullfilename2=this->Base_dir+RDS_NAS_USERLIST2_FILENAME;

    //copy to an temp user file2,
    File::Copy(fullfilename1, fullfilename2);
    File::Delete(fullfilename1);

    //read file2, modify or just copy to file1
    StreamReader^ sr=File::OpenText(fullfilename2);
    StreamWriter^ sw1=gcnew StreamWriter(fullfilename1);
    //read first line for total number of users & write N+1 to file1
    numberStr=sr->ReadLine();
    sw1->WriteLine(numberStr);
    //read 4 lines and drop them
    Line_inFile=sr->ReadLine();
    Line_inFile=sr->ReadLine();
    Line_inFile=sr->ReadLine();
    Line_inFile=sr->ReadLine();
    //write new admin
    sw1->WriteLine(str_1);
    sw1->WriteLine(str_2);
    sw1->WriteLine(str_3);
    sw1->WriteLine(str_4);

    //copy all the other users
    while((Line_inFile=sr->ReadLine())!=nullptr){
        sw1->WriteLine(Line_inFile);
    }
    sr->Close();
    sw1->Close();
    File::Delete(fullfilename2);
}

//-----------------------//
//  Read one page of User//
//-----------------------//
//return  -1  = no this page.
//return : n (1~9) = how many items activeis page
int nas_state::Read_UserName_byPage(
    int page     //page=0,1,2,3 (start from 0)
)
{
    String^ fullfilename;
    String^ numberStr;
    String^ tempStr;
    int count;
    int i_cnt, i;
    fullfilename=this->Base_dir+RDS_NAS_USERLIST_FILENAME;
    StreamReader^ din=File::OpenText(fullfilename);
    //first, read the total user number
    numberStr=din->ReadLine();
    this->total_user_count=Convert::ToInt32(numberStr, 10);
    this->total_page=((this->total_user_count-1)/RDS_NAS_USERS_PER_PAGE)+1;
    //check page
    if(page>=this->total_page){
        return -1;
    }
    //scan from page 0 & count 0
    count=0;
    for(int p=0; p<this->total_page; p++){
        //read from file: (1) skip previous pages
        if(p<page){
            for(int i=0; i<RDS_NAS_USERS_PER_PAGE; i++){
                tempStr=din->ReadLine(); //read 4 lines (name)
                tempStr=din->ReadLine(); //ID
                tempStr=din->ReadLine(); //PW
                tempStr=din->ReadLine(); //AuthLevel
                count++;
            }
        }
        //read from file: (2) target page !
        if(p==page){
            for(i=0; i<RDS_NAS_USERS_PER_PAGE; i++){
                tempStr=din->ReadLine(); //name
                if(i==0)      this->listName1=tempStr;
                else if(i==1) this->listName2=tempStr;
                else if(i==2) this->listName3=tempStr;
                else if(i==3) this->listName4=tempStr;
                else if(i==4) this->listName5=tempStr;
                else if(i==5) this->listName6=tempStr;
                else if(i==6) this->listName7=tempStr;
                else if(i==7) this->listName8=tempStr;
                else             this->listName9=tempStr;
                tempStr=din->ReadLine(); //ID
                tempStr=din->ReadLine(); //PW
                tempStr=din->ReadLine(); //AuthLevel
                count++;
                if(count==this->total_user_count)break;
            }
            i_cnt=i;
        }
        //exit after target page
        if(p>page) break;
    }
    din->Close();
    return i_cnt;
}

//-----------------------//
//  Add one in User file //
//-----------------------//
//return 0 = ok, sucessful
//return -1 = fail, already has same ID
int nas_state::Add_Users_Ini(
    String^ user_ID,
    String^ user_Name,
    String^ user_PW,
    String^ user_AuthLevel
)
{
    String^ fullfilename1;
    String^ fullfilename2;
    String^ numberStr;
    String^ str_1;
    String^ str_2;
    String^ str_3;
    String^ str_4;
    String^ Name_inFile;
    String^ ID_inFile;
    String^ PW_inFile;
    String^ AuthLevel_inFile;
    str_1=nasStringEncode(user_Name);
    str_2=nasStringEncode(user_ID);
    str_3=nasStringEncode(user_PW);
    str_4=nasStringEncode(user_AuthLevel);
    fullfilename1=this->Base_dir+RDS_NAS_USERLIST_FILENAME;
    fullfilename2=this->Base_dir+RDS_NAS_USERLIST2_FILENAME;
    //if file exist, normal case
    if(this->HasUsersIni==true){ //-------------------Normal case
        //copy to an temp user file2,
        File::Copy(fullfilename1, fullfilename2);
        File::Delete(fullfilename1);

        //read file2, modify or just copy to file1
        StreamReader^ sr=File::OpenText(fullfilename2);
        StreamWriter^ sw1=gcnew StreamWriter(fullfilename1);
        //read first line for total number of users & write N+1 to file1
        numberStr=sr->ReadLine();
        this->total_user_count=Convert::ToInt32(numberStr, 10)+1;  //N+1 here !!!!!!!!!!!!!!!!!
        this->total_page=((this->total_user_count-1)/RDS_NAS_USERS_PER_PAGE)+1;
        sw1->WriteLine(this->total_user_count);
        //copy all old users...
        while((Name_inFile=sr->ReadLine())!=nullptr){
            ID_inFile=sr->ReadLine();
            PW_inFile=sr->ReadLine();
            AuthLevel_inFile=sr->ReadLine();
            sw1->WriteLine(Name_inFile);
            sw1->WriteLine(ID_inFile);
            sw1->WriteLine(PW_inFile);
            sw1->WriteLine(AuthLevel_inFile);
            //check if input ID alread exist in file
            if(str_2==ID_inFile){
                //give up current operation, restore file1 (from file2)
                sr->Close();
                sw1->Close();
                File::Delete(fullfilename1);
                File::Copy(fullfilename2, fullfilename1);
                File::Delete(fullfilename2);
                //
                return -1;
            }
        }
        sr->Close();
        File::Delete(fullfilename2);
        //add new one user
        sw1->WriteLine(str_1);
        sw1->WriteLine(str_2);
        sw1->WriteLine(str_3);
        sw1->WriteLine(str_4);
        sw1->Close();
    }
    else{
        //initial case: creat a new user file   ----------------------------
        StreamWriter^ sw=gcnew StreamWriter(fullfilename1);
        this->total_user_count=1;
        sw->WriteLine(total_user_count); //Notice!! this number not encoded
        sw->WriteLine(str_1);
        sw->WriteLine(str_2);
        sw->WriteLine(str_3);
        sw->WriteLine(str_4);
        sw->Close();
    }
    return 0;
}

//------------------------//
//  Get User information  //
//------------------------//
//PS: assume users.ini file exist
//return 0 = ok, sucessful
//return -1 = fail, no valid current_user_no !!!
int nas_state::Get_User_Info()
{
    if(this->current_user_no==-1){
        //no valid number transfer in
        return -1;
    }

    //normal process
    String^ fullfilename;
    String^ numberStr;
    String^ tempStr;
    fullfilename=this->Base_dir+RDS_NAS_USERLIST_FILENAME;
    StreamReader^ din=File::OpenText(fullfilename);
    //first, read the total user number
    numberStr=din->ReadLine();
    this->total_user_count=Convert::ToInt32(numberStr, 10);
    this->total_page=((this->total_user_count-1)/RDS_NAS_USERS_PER_PAGE)+1;
    //scan for user 0
    int i=0;
    do{
        if(this->current_user_no==i){ //get information here !!!!!!!!
            this->user_Name=this->nasStringDecode(din->ReadLine());
            this->user_ID=this->nasStringDecode(din->ReadLine());
            this->user_PW=this->nasStringDecode(din->ReadLine());
            this->user_AuthLevel=this->nasStringDecode(din->ReadLine());
            break;
        }
        else{
            tempStr=din->ReadLine(); //read three lines (name)
            tempStr=din->ReadLine(); //ID
            tempStr=din->ReadLine(); //PW
            tempStr=din->ReadLine(); //AuthLevel
        }
        i++;
    } while(i<this->total_user_count);
    din->Close();
    return 0;
}

//-------------------------//
//  Overwrite current user //
//-------------------------//
//PS: assume users.ini file exist
//return 0 = ok, sucessful
//return -1 = fail, no valid current_user_no !!!
int nas_state::Overwrite_currentUser(
    String^ user_ID,
    String^ user_Name,
    String^ user_PW,
    String^ user_AuthLevel
)
{
    if(this->current_user_no==-1){
        //no valid number transfer in
        return -1;
    }
    String^ fullfilename1;
    String^ fullfilename2;
    String^ numberStr;
    String^ str_1;
    String^ str_2;
    String^ str_3;
    String^ str_4;
    String^ Name_inFile;
    String^ ID_inFile;
    String^ PW_inFile;
    String^ AuthLevel_inFile;
    str_1=nasStringEncode(user_Name);
    str_2=nasStringEncode(user_ID);
    str_3=nasStringEncode(user_PW);
    str_4=nasStringEncode(user_AuthLevel);
    fullfilename1=this->Base_dir+RDS_NAS_USERLIST_FILENAME;
    fullfilename2=this->Base_dir+RDS_NAS_USERLIST2_FILENAME;
    //copy to an temp user file2,
    File::Copy(fullfilename1, fullfilename2);
    File::Delete(fullfilename1);

    //read file2, modify or just copy to file1
    StreamReader^ sr=File::OpenText(fullfilename2);
    StreamWriter^ sw1=gcnew StreamWriter(fullfilename1);
    //read first line for total number of users & write N to file1
    numberStr=sr->ReadLine();
    this->total_user_count=Convert::ToInt32(numberStr, 10);
    this->total_page=((this->total_user_count-1)/RDS_NAS_USERS_PER_PAGE)+1;
    sw1->WriteLine(numberStr);
    //scan for user 0
    int i=0;
    do{
        Name_inFile=sr->ReadLine();      //read three lines (name)
        ID_inFile=sr->ReadLine();        //ID
        PW_inFile=sr->ReadLine();        //PW
        AuthLevel_inFile=sr->ReadLine(); //AuthLevel
        if(this->current_user_no==i){
            //overwrite it in file1
            sw1->WriteLine(str_1);
            sw1->WriteLine(str_2);
            sw1->WriteLine(str_3);
            sw1->WriteLine(str_4);
        }
        else{
            //copy to file1
            sw1->WriteLine(Name_inFile);
            sw1->WriteLine(ID_inFile);
            sw1->WriteLine(PW_inFile);
            sw1->WriteLine(AuthLevel_inFile);
        }
        i++;
    } while(i<this->total_user_count);
    sr->Close();
    sw1->Close();
    File::Delete(fullfilename2);
}

//----------------------//
//  Delete current user //
//----------------------//
//PS: assume users.ini file exist
//return 0 = ok, sucessful
//return -1 = fail, no valid current_user_no !!!
//return -2 = Can not delete admin!!
int nas_state::Delete_currentUser()
{
    if(this->current_user_no==-1){
        //no valid number transfer in
        return -1;
    }
    if(this->current_user_no==0){ //cannot delete admin !!
        return -2;
    }
    String^ fullfilename1;
    String^ fullfilename2;
    String^ numberStr;
    String^ Name_inFile;
    String^ ID_inFile;
    String^ PW_inFile;
    String^ AuthLevel_inFile;
    fullfilename1=this->Base_dir+RDS_NAS_USERLIST_FILENAME;
    fullfilename2=this->Base_dir+RDS_NAS_USERLIST2_FILENAME;
    //copy to an temp user file2,
    File::Copy(fullfilename1, fullfilename2);
    File::Delete(fullfilename1);

    //read file2, modify or just copy to file1
    StreamReader^ sr=File::OpenText(fullfilename2);
    StreamWriter^ sw1=gcnew StreamWriter(fullfilename1);
    //read first line for total number of users & write N-1 to file1
    numberStr=sr->ReadLine();
    this->total_user_count=Convert::ToInt32(numberStr, 10)-1;
    this->total_page=((this->total_user_count-1)/RDS_NAS_USERS_PER_PAGE)+1;
    sw1->WriteLine(this->total_user_count);
    //scan fro user 0
    int i=0;
    do{
        Name_inFile=sr->ReadLine();      //read three lines (name)
        ID_inFile=sr->ReadLine();        //ID
        PW_inFile=sr->ReadLine();        //PW
        AuthLevel_inFile=sr->ReadLine(); //AuthLevel
        if(this->current_user_no!=i){ //delete == not copy...
            //copy to file1
            sw1->WriteLine(Name_inFile);
            sw1->WriteLine(ID_inFile);
            sw1->WriteLine(PW_inFile);
            sw1->WriteLine(AuthLevel_inFile);
        }
        i++;
    } while(i<this->total_user_count+1); //use original count.
    sr->Close();
    sw1->Close();
    File::Delete(fullfilename2);
}

//-----------------------//
//  Read one page of OSC //
//-----------------------//
//return  -1  = no any file...
//return  -2  = no this page...
//return : 0  = no  OSC !!
//return : n (1~9) = how many items activeis page
int nas_state::Read_OSClist_byPage(
    int page     //page=0,1,2,3 (start from 0)
)
{
    int readStart;
    int readEnd;
    int StartPos;
    String^ NoDirFilename;
    String^ daily_No;
    String^ NoDirFilename2;
    String^ daily_No2;
    String^ NoDirExt_Filename;
    String^ Disp_name;
    String^ fullpath;  //go to OSC directory
    fullpath=this->Base_dir+RDS_NAS_SERVICE_DIR;

    //get all files in directory
    array<String^>^ fileAll=Directory::GetFiles(fullpath);
    IComparer^ revComparer=gcnew ReverseComparer();
    Array::Sort(fileAll, revComparer);

    if(fileAll->Length==0){
        return -1; //no any files
    }

    //screen out.. (only want *.csv file)
    array<String^>^ fileAll_my;
    Array::Resize(fileAll_my, fileAll->Length);
    int myIndex=0; //position for insert
    int myLength=0;
    int testIndex;
    for(int i=0; i<fileAll->Length; i++){
        //file name only (no path)
        StartPos=fileAll[i]->LastIndexOf("\\");
        NoDirFilename=fileAll[i]->Substring(StartPos+1);
        //delete UID
        StartPos=NoDirFilename->IndexOf("_");
        daily_No=NoDirFilename->Substring(StartPos+1);  // fileAll[i]
        //judge
        if(daily_No->IndexOf(".csv")>0){ //if it is .csv file ===========================
            //Add new one into fillAll_my[], and consider Sort!!
            if(myIndex==0){  //first one
                fileAll_my[myIndex]=fileAll[i];  //copy in last post
            }
            else if(myIndex==1){ //second one
                StartPos=fileAll_my[0]->LastIndexOf("\\");
                NoDirFilename2=fileAll_my[0]->Substring(StartPos+1);
                StartPos=NoDirFilename2->IndexOf("_");
                daily_No2=NoDirFilename2->Substring(StartPos+1);  //fileAll_my[0]
                if(String::CompareOrdinal(daily_No, daily_No2)>0){
                    fileAll_my[1]=fileAll[i]; //copy in last post
                }
                else{
                    fileAll_my[1]=fileAll_my[0]; //shift...
                    fileAll_my[0]=fileAll[i];    //copy in position
                }
            }
            else {  //for 3,4,5....
                //find position...
                testIndex=-1;
                do{
                    testIndex++;
                    StartPos=fileAll_my[testIndex]->LastIndexOf("\\");
                    NoDirFilename2=fileAll_my[testIndex]->Substring(StartPos+1);
                    StartPos=NoDirFilename2->IndexOf("_");
                    daily_No2=NoDirFilename2->Substring(StartPos+1);  //fileAll_my[testIndex]
                } while(String::CompareOrdinal(daily_No, daily_No2)>0&&testIndex<myIndex);
                //-----------
                if(testIndex==myIndex){
                    fileAll_my[myIndex]=fileAll[i];  //copy in last post
                }
                else{ //shift & insert
                    for(int j=myIndex; j>testIndex; j--){ //shift
                        fileAll_my[j]=fileAll_my[j-1];
                    }//end-for j
                    fileAll_my[testIndex]=fileAll[i];    //copy in position
                }
            }
            //for next one...
            myIndex++;
        }//end-if (.csv file) ================================================================
    } // end-for I
    myLength=myIndex;
    if(myLength==0){
        return 0; // no csv files
    }
    Array::Resize(fileAll_my, myLength);
    this->total_items_inDir=myLength;

    //cheking page relationship
    this->total_page=((this->total_items_inDir-1)/RDS_OSC_LIST_PER_PAGE)+1;
    //check page
    if(page>=this->total_page){
        return -2;
    }

    //defien reading range
    readStart=page * RDS_OSC_LIST_PER_PAGE;
    readEnd=(page+1) * RDS_OSC_LIST_PER_PAGE; //this one dont read
    if(this->total_items_inDir<readEnd){
        readEnd=this->total_items_inDir;
    }

    //clear all before reading-scan
    this->I1_filename=""; this->listName1="";
    this->I2_filename=""; this->listName2="";
    this->I3_filename=""; this->listName3="";
    this->I4_filename=""; this->listName4="";
    this->I5_filename=""; this->listName5="";
    this->I6_filename=""; this->listName6="";
    this->I7_filename=""; this->listName7="";
    this->I8_filename=""; this->listName8="";
    this->I9_filename=""; this->listName9="";

    //read filename list
    int pos=readStart;
    for(int i=0; i<RDS_OSC_LIST_PER_PAGE; i++){
        StartPos=fileAll_my[pos]->LastIndexOf("\\");
        NoDirFilename=fileAll_my[pos]->Substring(StartPos+1);
        StartPos=NoDirFilename->LastIndexOf(".");
        NoDirExt_Filename=NoDirFilename->Substring(0, StartPos);
        Disp_name=NoDirExt_Filename->Substring(RDS_OSC_DISPLAY_START_CHAR);
        //get them first
        if(i==0){ this->I1_filename=fileAll_my[pos]; this->listName1=Disp_name; }
        if(i==1){ this->I2_filename=fileAll_my[pos]; this->listName2=Disp_name; }
        if(i==2){ this->I3_filename=fileAll_my[pos]; this->listName3=Disp_name; }
        if(i==3){ this->I4_filename=fileAll_my[pos]; this->listName4=Disp_name; }
        if(i==4){ this->I5_filename=fileAll_my[pos]; this->listName5=Disp_name; }
        if(i==5){ this->I6_filename=fileAll_my[pos]; this->listName6=Disp_name; }
        if(i==6){ this->I7_filename=fileAll_my[pos]; this->listName7=Disp_name; }
        if(i==7){ this->I8_filename=fileAll_my[pos]; this->listName8=Disp_name; }
        if(i==8){ this->I9_filename=fileAll_my[pos]; this->listName9=Disp_name; }
        //increment
        pos++;
        if(pos==readEnd) break;
    }//end for i
    return readEnd-readStart;
}

//---------------//
//  user login   //
//---------------//
// input:
//     Authority_allow :  Bit0 ==> MIS
//                        Bit1 ==> Manager
//                        Bit2 ==> CR/Engeer
// PS: assume users.ini file exist
//return = 0  : ok, sucessful
//return = -1 : fail, ID not found
//return = -2 : fail, ID correct, but PW fail
//return = -3 : fail, ID/PW Ok, but authority not allow
//return = -4 : fail, ID/PW OK, but already logined !!!!
int nas_state::user_Login(
    String^ user_ID,
    String^ user_PW,
    unsigned char Authority_allow
)
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
    HadLogined=false;
    do{
        Name_inFile=this->nasStringDecode(din->ReadLine());
        ID_inFile=this->nasStringDecode(din->ReadLine());
        PW_inFile=this->nasStringDecode(din->ReadLine());
        AuthLevel_inFile=this->nasStringDecode(din->ReadLine());
        if(user_ID==ID_inFile){ //found user !!!!!
            found_ID=true;
            //checking he/she logined or not
            HadLogined=Check_Person_Logined(i+1, LastAct, LastTime);
            if(HadLogined==false){
                //not yet login.....
                this->LoginUser_no=i+1;
                this->LoginUser_ID=ID_inFile;
                this->LoginUser_AuthLevel=AuthLevel_inFile;
                break;
            }
        }
        i++;
    } while(i<this->total_user_count);
    din->Close();

    //final checking
    if(found_ID==false){
        return -1;
    }
    else if(HadLogined==true){
        return -4;
    }
    else if(user_PW!=PW_inFile){
        return -2;
    }
    else if(Authority_isOK(Authority_allow)!=true){
        return -3;
    }
    else {
        return 0;
    }
}

//--------------------------//
//  Add one in Dealers file //
//--------------------------//
//return 0 = ok, sucessful
//return -1 = fail, already has same ID
int nas_state::Add_Dealers_Ini(
    String^ CompanyCode,
    String^ CompanyName,
    String^ ZipCode
)
{
    String^ fullfilename1;
    String^ fullfilename2;
    String^ numberStr;
    String^ str_1;
    String^ str_2;
    String^ str_3;
    String^ ComCode_inFile;
    String^ ComName_inFile;
    String^ ZipCode_inFile;
    str_1=nasStringEncode(CompanyCode);
    str_2=nasStringEncode(CompanyName);
    str_3=nasStringEncode(ZipCode);
    fullfilename1=this->Base_dir+RDS_NAS_DEALER_LIST_FILENAME;
    fullfilename2=this->Base_dir+RDS_NAS_DEALERLIST2_FILENAME;
    //if file exist, normal case
    if(this->HasDealerIni==true){ //-------------------Normal case
        //copy to an temp user file2,
        File::Copy(fullfilename1, fullfilename2);
        File::Delete(fullfilename1);

        //read file2, modify or just copy to file1
        StreamReader^ sr=File::OpenText(fullfilename2);
        StreamWriter^ sw1=gcnew StreamWriter(fullfilename1);
        //read first line for total number of users & write N+1 to file1
        numberStr=sr->ReadLine();

        //N+1 here !!!!!!!!!!!!!!!!!
        this->total_dealer_count=Convert::ToInt32(numberStr, 10)+1;
        this->total_dealer_page=((this->total_dealer_count-1)/RDS_NAS_DEALERS_PER_PAGE)+1;
        sw1->WriteLine(this->total_dealer_count);

        //copy all old users...
        while((ComCode_inFile=sr->ReadLine())!=nullptr){
            ComName_inFile=sr->ReadLine();
            ZipCode_inFile=sr->ReadLine();
            sw1->WriteLine(ComCode_inFile);
            sw1->WriteLine(ComName_inFile);
            sw1->WriteLine(ZipCode_inFile);
            //check if Dealer alread exist in file
            if(str_1==ComCode_inFile){
                //give up current operation, restore file1 (from file2)
                sr->Close();
                sw1->Close();
                File::Delete(fullfilename1);
                File::Copy(fullfilename2, fullfilename1);
                File::Delete(fullfilename2);
                //
                return -1;
            }
        }
        sr->Close();
        File::Delete(fullfilename2);
        //add new one dealer
        sw1->WriteLine(str_1);
        sw1->WriteLine(str_2);
        sw1->WriteLine(str_3);
        sw1->Close();
    }
    else{
        //initial case: creat a new user file   --------------------
        StreamWriter^ sw=gcnew StreamWriter(fullfilename1);
        this->total_dealer_count=1;
        sw->WriteLine(total_dealer_count); //Notice!! this number not encoded
        sw->WriteLine(str_1);
        sw->WriteLine(str_2);
        sw->WriteLine(str_3);
        sw->Close();
    }
    return 0;
}

//---------------------------//
// Get Dealer's Company Name //
//---------------------------//
// Just return the company name if found Compamy code in Dealers.ini
// This function dont change iNas.base_dir (dont change any member of iNas)
String^ nas_state::Get_Dealer_ComName(String^ CompanyCode)
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
    if(this->Base_dir!=RDS_NAS_ROOT_DIR){
        rtnString=NO_DEALER_COM_CODE;
        return rtnString;
    }
    if(this->HasDealerIni==false){
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
    do{
        ComCode_inFile=this->nasStringDecode(din->ReadLine());
        ComName_inFile=this->nasStringDecode(din->ReadLine());
        ZipCode_inFile=this->nasStringDecode(din->ReadLine());
        if(CompanyCode==ComCode_inFile){ //found dealer!!!!!
            found_Dealer=true;
            break;
        }
        i++;
    } while(i<this->total_dealer_count);
    din->Close();

    //final checking
    if(found_Dealer==false) {
        rtnString=NO_DEALER_COM_CODE;
        return rtnString;
    }
    else{
        rtnString=ComName_inFile;
        return rtnString;
    }
}

//-----------------------//
// Read 1 page of Dealer //
//-----------------------//
//return  -1  = no this page.
//return : n (1~9) = how many items activeis page
int nas_state::Read_DealerName_byPage(
    int page     //page=0,1,2,3 (start from 0)
)
{
    String^ fullfilename;
    String^ numberStr;
    String^ tempStr;
    int count;
    int i_cnt, i;
    fullfilename=this->Base_dir+RDS_NAS_DEALER_LIST_FILENAME;
    StreamReader^ din=File::OpenText(fullfilename);
    //first, read the total user number
    numberStr=din->ReadLine();
    this->total_user_count=Convert::ToInt32(numberStr, 10);
    this->total_page=((this->total_user_count-1)/RDS_NAS_USERS_PER_PAGE)+1;
    //check page
    if(page>=this->total_page){
        return -1;
    }
    //scan from page 0 & count 0
    count=0;
    for(int p=0; p<this->total_page; p++){
        //read from file: (1) skip previous pages
        if(p<page){
            for(int i=0; i<RDS_NAS_USERS_PER_PAGE; i++){
                tempStr=din->ReadLine(); //read 3 lines (Company Code)
                tempStr=din->ReadLine(); //Company Name
                tempStr=din->ReadLine(); //Zip Code
                count++;
            }
        }
        //read from file: (2) target page !
        if(p==page){
            for(i=0; i<RDS_NAS_USERS_PER_PAGE; i++){
                tempStr=din->ReadLine(); //Company Code
                tempStr=din->ReadLine(); //Company Name
                if(i==0)      this->listName1=tempStr;
                else if(i==1) this->listName2=tempStr;
                else if(i==2) this->listName3=tempStr;
                else if(i==3) this->listName4=tempStr;
                else if(i==4) this->listName5=tempStr;
                else if(i==5) this->listName6=tempStr;
                else if(i==6) this->listName7=tempStr;
                else if(i==7) this->listName8=tempStr;
                else             this->listName9=tempStr;
                tempStr=din->ReadLine(); //Zip Code
                count++;
                if(count==this->total_user_count)break;
            }
            i_cnt=i;
        }
        //exit after target page
        if(p>page) break;
    }
    din->Close();
    return i_cnt;
}

//------------------------//
//  Get Delaer information  //
//------------------------//
//PS: assume dealers.ini file exist
//return 0 = ok, sucessful
//return -1 = fail, no valid current_user_no !!!
int nas_state::Get_Dealer_Info()
{
    Boolean found=false;

    if(this->cur_dealer_no==-1){
        //no valid number transfer in
        return -1;
    }

    //normal process
    String^ fullfilename;
    String^ numberStr;
    String^ tempStr;
    fullfilename=this->Base_dir+RDS_NAS_DEALER_LIST_FILENAME;
    StreamReader^ din=File::OpenText(fullfilename);
    //first, read the total user number
    numberStr=din->ReadLine();
    this->total_dealer_count=Convert::ToInt32(numberStr, 10);
    this->total_dealer_page=((this->total_dealer_count-1)/RDS_NAS_DEALERS_PER_PAGE)+1;
    //scan for user 0
    int i=0;
    do{
        if(this->cur_dealer_no==i){ //get information here !!!!!!!!
            found=true;
            this->dealer_ComCode=this->nasStringDecode(din->ReadLine());
            this->dealer_ComName=this->nasStringDecode(din->ReadLine());
            this->dealer_ZipCode=this->nasStringDecode(din->ReadLine());
            break;
        }
        else{
            tempStr=din->ReadLine(); //company code
            tempStr=din->ReadLine(); //company Name
            tempStr=din->ReadLine(); //Zip Code
        }
        i++;
    } while(i<this->total_dealer_count);
    din->Close();
    //
    if(found==true) return 0;
    else return -1;
}

//----------------------//
//  Delete Cur. dealer  //
//----------------------//
//PS: assume dealers.ini file exist
//return 0 = ok, sucessful
//return -1 = fail, no valid current dealer Numner !!!
int nas_state::Delete_cur_dealer()
{
    if(this->cur_dealer_no==-1){
        //no valid number transfer in
        return -1;
    }
    String^ fullfilename1;
    String^ fullfilename2;
    String^ numberStr;
    String^ ComCode_inFile;
    String^ ComName_inFile;
    String^ ZipCode_inFile;
    fullfilename1=this->Base_dir+RDS_NAS_DEALER_LIST_FILENAME;
    fullfilename2=this->Base_dir+RDS_NAS_DEALERLIST2_FILENAME;
    //copy to an temp user file2,
    File::Copy(fullfilename1, fullfilename2);
    File::Delete(fullfilename1);

    //read file2, modify or just copy to file1
    StreamReader^ sr=File::OpenText(fullfilename2);
    StreamWriter^ sw1=gcnew StreamWriter(fullfilename1);
    //read first line for total number of users & write N-1 to file1
    numberStr=sr->ReadLine();
    this->total_dealer_count=Convert::ToInt32(numberStr, 10)-1;
    this->total_dealer_page=((this->total_dealer_count-1)/RDS_NAS_DEALERS_PER_PAGE)+1;
    sw1->WriteLine(this->total_dealer_count);
    //scan fro dealer
    int i=0;
    do{
        ComCode_inFile=sr->ReadLine();   //company code
        ComName_inFile=sr->ReadLine();   //Company name
        ZipCode_inFile=sr->ReadLine();   //Zip
        if(this->cur_dealer_no!=i){ //delete == not copy...
            //copy to file1
            sw1->WriteLine(ComCode_inFile);
            sw1->WriteLine(ComName_inFile);
            sw1->WriteLine(ZipCode_inFile);
        }
        i++;
    } while(i<this->total_dealer_count+1); //use original count.
    sr->Close();
    sw1->Close();
    File::Delete(fullfilename2);
}

//-------------------------//
//  Overwrite cur. dealer //
//-------------------------//
//PS: assume users.ini file exist
//return 0 = ok, sucessful
//return -1 = fail, no valid cur_dealer_no !!!
int nas_state::Overwrite_currDealer( //using current_dealer_No
    String^ CompanyCode,
    String^ CompanyName,
    String^ ZipCode
)
{
    if(this->cur_dealer_no==-1){
        //no valid number transfer in
        return -1;
    }
    String^ fullfilename1;
    String^ fullfilename2;
    String^ numberStr;
    String^ str_1;
    String^ str_2;
    String^ str_3;
    String^ ComCode_inFile;
    String^ ComName_inFile;
    String^ ZipCode_inFile;
    str_1=nasStringEncode(CompanyCode);
    str_2=nasStringEncode(CompanyName);
    str_3=nasStringEncode(ZipCode);
    fullfilename1=this->Base_dir+RDS_NAS_DEALER_LIST_FILENAME;
    fullfilename2=this->Base_dir+RDS_NAS_DEALERLIST2_FILENAME;

    //copy to an temp user file2,
    File::Copy(fullfilename1, fullfilename2);
    File::Delete(fullfilename1);

    //read file2, modify or just copy to file1
    StreamReader^ sr=File::OpenText(fullfilename2);
    StreamWriter^ sw1=gcnew StreamWriter(fullfilename1);

    //read first line for total number of users & write N to file1
    numberStr=sr->ReadLine();
    this->total_dealer_count=Convert::ToInt32(numberStr, 10);
    this->total_dealer_page=((this->total_dealer_count-1)/RDS_NAS_DEALERS_PER_PAGE)+1;
    sw1->WriteLine(numberStr);

    //scan for user 0
    int i=0;
    do{
        ComCode_inFile=sr->ReadLine();      //Company Code
        ComName_inFile=sr->ReadLine();      //Company Name
        ZipCode_inFile=sr->ReadLine();      //Zip Code
        if(this->cur_dealer_no==i){
            //overwrite it in file1
            sw1->WriteLine(str_1);
            sw1->WriteLine(str_2);
            sw1->WriteLine(str_3);
        }
        else{
            //copy to file1
            sw1->WriteLine(ComCode_inFile);
            sw1->WriteLine(ComName_inFile);
            sw1->WriteLine(ZipCode_inFile);
        }
        i++;
    } while(i<this->total_dealer_count);
    sr->Close();
    sw1->Close();
    File::Delete(fullfilename2);
}

//-----------------------------------------------------------------------------------------------------------------------
//-----------------//
//  Encode string  //
//-----------------//
String^ nas_state::nasStringEncode(String^ inStr)
{
    String^ outStr="";
    int i;
    for(i=0; i<inStr->Length; i++){
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
String^ nas_state::nasStringDecode(String^ inStr)
{
    String^ outStr="";
    int i;
    for(i=0; i<inStr->Length; i++){
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