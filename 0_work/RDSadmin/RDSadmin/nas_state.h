#pragma once

//User list page setting
#define RDS_NAS_USERS_PER_PAGE		9

//for OSC list
#define RDS_OSC_LIST_PER_PAGE		9
#define RDS_OSC_DISPLAY_START_CHAR	14

//Dealer list page setting
#define RDS_NAS_DEALERS_PER_PAGE	9

namespace RDS_NAS {
    using namespace System;
    using namespace System::IO;
    using namespace System::Collections;

    //small class for sorting string array...
    public ref class ReverseComparer: IComparer
    {
    public:
        // Call CaseInsensitiveComparer::Compare with the parameters reversed.
        virtual int Compare(Object^ x, Object^ y)=IComparer::Compare
        {
            return ((gcnew CaseInsensitiveComparer)->Compare(y, x));
        }
    };

    ref class nas_state
    {
    public:
        //-----------------------------class member (variable)
        Boolean HasAdminIni;
        Boolean HasUsersIni;
        Boolean HasDealerIni;
        Boolean Has_Model_AD_Ini;
        Boolean HasRDS_driver;
        Boolean HasRDSdir;

        //for user
        int total_user_count;
        int total_page;
        int current_user_no;

        //for dealer
        int total_dealer_count;
        int total_dealer_page;
        int cur_dealer_no;

        //for currentt logined company...
        String^ Base_dir;     //point to Dealer working-base directory
        String^ Default_moodel_file;     //point to Application install directory

        //admin account screen (or in dealer page)
        String^ Admin_ID;
        String^ Admin_Name;
        String^ Admin_PW;
        unsigned int Admin_SQ_index;
        String^ Admin_SQanswer;
        String^ Admin_AuthLevel;
        String^ CompanyCode;  //go with admin
        String^ CompanyName;  //go with admin

        //user logined
        unsigned int LoginUser_no;
        String^ LoginUser_ID;
        String^ LoginUser_AuthLevel;

        //user account page
        String^ user_ID;
        String^ user_Name;
        String^ user_PW;
        String^ user_AuthLevel;

        //dealer account page
        String^ dealer_ComCode;
        String^ dealer_ComName;
        String^ dealer_ZipCode;

        //user list pgae
        String^ listName1;
        String^ listName2;
        String^ listName3;
        String^ listName4;
        String^ listName5;
        String^ listName6;
        String^ listName7;
        String^ listName8;
        String^ listName9;

        //for OSC list
        int total_items_inDir;
        String^ I1_filename;
        String^ I2_filename;
        String^ I3_filename;
        String^ I4_filename;
        String^ I5_filename;
        String^ I6_filename;
        String^ I7_filename;
        String^ I8_filename;
        String^ I9_filename;

    public:
        //-----------------------------class member functions
        nas_state();
        //~nas_state();

        //checking
        Boolean Check_RDS_driver();
        Boolean Check_RDS_dir();
        Boolean Check_Admin_Ini();
        Boolean Check_User_Ini();
        Boolean Check_Dealer_Ini();
        Boolean Check_Model_AD_Ini();

        //login related
        Boolean Check_Person_Logined(unsigned int User_no, String^ LastAct, String^ LastTime);
        int Lock_Person_Login(unsigned int User_no, String^ TimeString);
        int Unlock_Person_Login(unsigned int User_no);

        //format & authority
        Boolean Is_com_code_fmt_OK(String^ ComCode);
        Boolean Is_Zip_code_fmt_OK(String^ ZipCode);
        Boolean Authority_isOK(unsigned Authority_allow);

        //directory
        void Build_All_Dir();

        //for admin.ini
        void Write_Admin_Ini(
            String^ Admin_ID,
            String^ Admin_Name,
            String^ Admin_PW,
            String^ Admin_AuthLevel,
            unsigned int Admin_SQ_index,
            String^ Admin_SQanswer,
            String^ CompanyCode,
            String^ CompanyName
        );
        int Read_Admin_ini();
        int Delete_Admin_ini();
        void Overwrite_Admin_inUsers(
            String^ Admin_ID,
            String^ Admin_Name,
            String^ Admin_PW,
            String^ Admin_AuthLevel
        );

        //for User list
        int Read_UserName_byPage(
            int page
        );
        int Add_Users_Ini(
            String^ user_ID,
            String^ user_Name,
            String^ user_PW,
            String^ user_AuthLevel
        );
        int Get_User_Info();  //using current_user_No to get user name/ID/PW
        int Overwrite_currentUser(  //using current_user_No
            String^ user_ID,
            String^ user_Name,
            String^ user_PW,
            String^ user_AuthLevel
        );
        int Delete_currentUser();  //using current_user_No

        //for OSC list
        int Read_OSClist_byPage(
            int page
        );

        //for login form.....
        int user_Login(
            String^ user_ID,
            String^ user_PW,
            unsigned char Authority_allow
        );
        //for Dealer List...
        int Add_Dealers_Ini(
            String^ CompanyCode,
            String^ CompanyName,
            String^ ZipCode
        );
        String^ Get_Dealer_ComName(String^ CompanyCode);
        int Read_DealerName_byPage(
            int page
        );
        int Get_Dealer_Info();  //using current_dealer_No to get dealer information
        int Delete_cur_dealer();  //using current_dealer_No
        int Overwrite_currDealer( //using current_dealer_No
            String^ CompanyCode,
            String^ CompanyName,
            String^ ZipCode
        );

        //encode/decode
        String^ nasStringEncode(String^ inStr);
        String^ nasStringDecode(String^ inStr);
    };
}
