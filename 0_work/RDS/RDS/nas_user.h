#pragma once

namespace RDS_NAS {
	using namespace System;
	using namespace System::IO;


	ref class nas_user
	{
	public:
		//-----------------------------class member (variable)
		Boolean HasAdminIni;
		Boolean HasUsersIni;
		Boolean HasDealerIni;
		Boolean Has_Model_AD_Ini;

		//user
		int total_user_count;
		unsigned char userNo;
		String^ userName;
		String^ user_AuthLevel;

		//for dealer
		int total_dealer_count;
		int total_dealer_page;
		int cur_dealer_no;
		
		//admin account screen (or in dealer page)
		String^ SpaCompanyCode;  //go with admin 
		String^ SpaCompanyName;  //go with admin 

		//for currentt logined company...
		String^ Base_dir;     //point to Dealer working-base directory

	public:
		//-----------------------------class member functions
		nas_user();
		//~nas_user();

		Boolean Check_Admin_Ini();
		Boolean Check_User_Ini();
		Boolean Check_Dealer_Ini();
		Boolean Check_Model_AD_Ini();
		
		//login related
		Boolean Check_Person_Logined(unsigned int User_no, String^ LastAct, String^ LastTime);
		int Lock_Person_Login(unsigned int User_no, String^ TimeString);
		int Unlock_Person_Login(unsigned int User_no);

		//encode/decode
		String^ nasStringEncode(String^ inStr);
		String^ nasStringDecode(String^ inStr);
		
		//
		int get_SpaComapny(); //read admin.ini
		String^ Get_Dealer_ComName(String^ CompanyCode); //reading dealers.ini
		
		//
		int user_Login(
			String^ user_ID,
			String^ user_PW
			);
	};

}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            