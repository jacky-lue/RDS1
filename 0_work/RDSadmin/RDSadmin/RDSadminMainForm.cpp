//project defines
#include "RDSadmin_project.h"
//
#include "DashBrdForm.h"
#include "RDSadminMainForm.h"
#include "nas_state.h"
#include "SupervisorForm.h"
#include "UserList_Form.h"
#include "DealerListForm.h"
#include "rpt_b_Form.h"
//
#include "global.h"
#include "global_chart.h"

using namespace System;
using namespace System::Globalization;
using namespace System::Windows::Forms;
using namespace RDSadmin;
using namespace RDS_NAS;

//----------------//
// Form loading   //
//----------------//
System::Void RDSadminMainForm::RDSadminMainForm_Load(System::Object^  sender, System::EventArgs^  e)
{
    this->iNas.HasAdminIni=this->iNas.Check_Admin_Ini();
    this->iNas.HasUsersIni=this->iNas.Check_User_Ini();

    //show Login-User
    this->label_LoginID->Text=this->iNas.LoginUser_ID;
    this->label_LoginAuthorLv->Text=this->iNas.LoginUser_AuthLevel;

    //when build this object, should give page number.
    Draw_OSCList();

    //Hide Buttons by authority_level
    if(this->iNas.LoginUser_AuthLevel!=RDS_NAS_AUTHORITY_LEVEL_0){
        this->button_Supervisor->Visible=false;
    }

    //hide menu buttons when not root Spa Company
    if(this->iNas.Base_dir!=RDS_NAS_ROOT_DIR){
        this->button_Dealer->Visible=false;
        this->button_DashBoard->Visible=false;
    }
}

//----------------//
//  Draw userlist //
//----------------//
void RDSadminMainForm::Draw_OSCList()
{
    //reset UI
    this->active_list=0; //none be selected
    this->label_list1->Text="";
    this->label_list2->Text="";
    this->label_list3->Text="";
    this->label_list4->Text="";
    this->label_list5->Text="";
    this->label_list6->Text="";
    this->label_list7->Text="";
    this->label_list8->Text="";
    this->label_list9->Text="";
    this->label_page->Text="Page "+this->page;

    //read OSC directory (display_cnt = 2 : means 3 items in this display page)
    int display_cnt=this->iNas.Read_OSClist_byPage(this->page);

    //process no file case
    if(display_cnt<=0){
        MessageBox::Show(SERVICE_CALL_CURRENT_NO_OSC, "NOTICE",
            MessageBoxButtons::OK,
            MessageBoxIcon::Information);
        this->button_left->Enabled=false;
        this->button_right->Enabled=false;
        display_cnt=-1; //means no any items
    }

    //check and display
    int i=0;
    if(display_cnt>=0){
        do{
            int ino=i+1+(this->page * RDS_OSC_LIST_PER_PAGE);
            if(i==0) { this->label_list1->Text=this->iNas.listName1; this->panel_list1->Visible=true; }
            if(i==1) { this->label_list2->Text=this->iNas.listName2; this->panel_list2->Visible=true; }
            if(i==2) { this->label_list3->Text=this->iNas.listName3; this->panel_list3->Visible=true; }
            if(i==3) { this->label_list4->Text=this->iNas.listName4; this->panel_list4->Visible=true; }
            if(i==4) { this->label_list5->Text=this->iNas.listName5; this->panel_list5->Visible=true; }
            if(i==5) { this->label_list6->Text=this->iNas.listName6; this->panel_list6->Visible=true; }
            if(i==6) { this->label_list7->Text=this->iNas.listName7; this->panel_list7->Visible=true; }
            if(i==7) { this->label_list8->Text=this->iNas.listName8; this->panel_list8->Visible=true; }
            if(i==8) { this->label_list9->Text=this->iNas.listName9; this->panel_list9->Visible=true; }
            i++;
        } while(i<display_cnt);
    }
    if(display_cnt<RDS_OSC_LIST_PER_PAGE){
        do{
            if(i==0){ this->panel_list1->Visible=false; }
            if(i==1){ this->panel_list2->Visible=false; }
            if(i==2){ this->panel_list3->Visible=false; }
            if(i==3){ this->panel_list4->Visible=false; }
            if(i==4){ this->panel_list5->Visible=false; }
            if(i==5){ this->panel_list6->Visible=false; }
            if(i==6){ this->panel_list7->Visible=false; }
            if(i==7){ this->panel_list8->Visible=false; }
            if(i==8){ this->panel_list9->Visible=false; }
            i++;
        } while(i<RDS_OSC_LIST_PER_PAGE);
    }

    //setting the right/left button
    if(this->page==0) this->button_left->Enabled=false;
    else                 this->button_left->Enabled=true;
    if(this->page==(this->iNas.total_page-1))
        this->button_right->Enabled=false;
    else this->button_right->Enabled=true;
}

//--------------------//
// Supervisor button  //
//--------------------//
System::Void RDSadminMainForm::button_Supervisor_Click(System::Object^  sender, System::EventArgs^  e)
{
    RDSadmin::SupervisorForm^ formSuper=gcnew SupervisorForm();
    formSuper->iNas.LoginUser_no=this->iNas.LoginUser_no;
    formSuper->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
    formSuper->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
    formSuper->iNas.Base_dir=this->iNas.Base_dir;
    formSuper->Show();
    this->Close();
}

//------------------//
// UserList button  //
//------------------//
System::Void RDSadminMainForm::button_RDSuser_Click(System::Object^  sender, System::EventArgs^  e)
{
    RDSadmin::UserList_Form^ formUser=gcnew UserList_Form();
    formUser->iNas.LoginUser_no=this->iNas.LoginUser_no;
    formUser->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
    formUser->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
    formUser->iNas.Base_dir=this->iNas.Base_dir;
    formUser->Show();
    this->Close();
}

//--------------------//
// DealerList button  //
//--------------------//
System::Void RDSadminMainForm::button_Dealer_Click(System::Object^  sender, System::EventArgs^  e)
{
    RDSadmin::DealerListForm^ formDealer=gcnew DealerListForm();
    formDealer->iNas.LoginUser_no=this->iNas.LoginUser_no;
    formDealer->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
    formDealer->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
    formDealer->iNas.Base_dir=this->iNas.Base_dir;
    formDealer->Show();
    this->Close();
}

//--------------------//
// Dash Board button  //
//--------------------//
System::Void RDSadminMainForm::button_DashBoard_Click(System::Object^  sender, System::EventArgs^  e)
{
    RDSadmin::DashBrdForm^ formDash=gcnew DashBrdForm();
    formDash->iNas.LoginUser_no=this->iNas.LoginUser_no;
    formDash->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
    formDash->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
    formDash->iNas.Base_dir=this->iNas.Base_dir;
    formDash->Show();
    this->Close();
}

//------------------//
//  Page up / down  //
//------------------//
System::Void RDSadminMainForm::button_right_Click(System::Object^  sender, System::EventArgs^  e)
{
    this->page++;
    Draw_OSCList();
}
System::Void RDSadminMainForm::button_left_Click(System::Object^  sender, System::EventArgs^  e)
{
    this->page--;
    Draw_OSCList();
}

//----------------//
// label click  . //
//----------------//
System::Void RDSadminMainForm::label_list1_Click(System::Object^  sender, System::EventArgs^  e)
{
    if(this->active_list!=1) {
        this->active_list=1;
        this->panel_list1->BackgroundImage=Image::FromFile("list_BG1.bmp"); //---------
        this->panel_list2->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list3->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list4->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list5->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list6->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list7->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list8->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list9->BackgroundImage=Image::FromFile("list_BG0.bmp");
    }
    else{
        this->active_list=0;
        this->panel_list1->BackgroundImage=Image::FromFile("list_BG0.bmp");
    }
}

System::Void RDSadminMainForm::label_list2_Click(System::Object^  sender, System::EventArgs^  e)
{
    if(this->active_list!=2) {
        this->active_list=2;
        this->panel_list1->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list2->BackgroundImage=Image::FromFile("list_BG1.bmp"); //
        this->panel_list3->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list4->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list5->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list6->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list7->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list8->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list9->BackgroundImage=Image::FromFile("list_BG0.bmp");
    }
    else{
        this->active_list=0;
        this->panel_list2->BackgroundImage=Image::FromFile("list_BG0.bmp");
    }
}

System::Void RDSadminMainForm::label_list3_Click(System::Object^  sender, System::EventArgs^  e)
{
    if(this->active_list!=3) {
        this->active_list=3;
        this->panel_list1->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list2->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list3->BackgroundImage=Image::FromFile("list_BG1.bmp"); //
        this->panel_list4->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list5->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list6->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list7->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list8->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list9->BackgroundImage=Image::FromFile("list_BG0.bmp");
    }
    else{
        this->active_list=0;
        this->panel_list3->BackgroundImage=Image::FromFile("list_BG0.bmp");
    }
}

System::Void RDSadminMainForm::label_list4_Click(System::Object^  sender, System::EventArgs^  e)
{
    if(this->active_list!=4) {
        this->active_list=4;
        this->panel_list1->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list2->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list3->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list4->BackgroundImage=Image::FromFile("list_BG1.bmp"); //
        this->panel_list5->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list6->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list7->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list8->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list9->BackgroundImage=Image::FromFile("list_BG0.bmp");
    }
    else{
        this->active_list=0;
        this->panel_list4->BackgroundImage=Image::FromFile("list_BG0.bmp");
    }
}

System::Void RDSadminMainForm::label_list5_Click(System::Object^  sender, System::EventArgs^  e)
{
    if(this->active_list!=5) {
        this->active_list=5;
        this->panel_list1->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list2->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list3->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list4->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list5->BackgroundImage=Image::FromFile("list_BG1.bmp"); //
        this->panel_list6->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list7->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list8->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list9->BackgroundImage=Image::FromFile("list_BG0.bmp");
    }
    else{
        this->active_list=0;
        this->panel_list5->BackgroundImage=Image::FromFile("list_BG0.bmp");
    }
}

System::Void RDSadminMainForm::label_list6_Click(System::Object^  sender, System::EventArgs^  e)
{
    if(this->active_list!=6) {
        this->active_list=6;
        this->panel_list1->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list2->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list3->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list4->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list5->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list6->BackgroundImage=Image::FromFile("list_BG1.bmp"); //
        this->panel_list7->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list8->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list9->BackgroundImage=Image::FromFile("list_BG0.bmp");
    }
    else{
        this->active_list=0;
        this->panel_list6->BackgroundImage=Image::FromFile("list_BG0.bmp");
    }
}

System::Void RDSadminMainForm::label_list7_Click(System::Object^  sender, System::EventArgs^  e)
{
    if(this->active_list!=7) {
        this->active_list=7;
        this->panel_list1->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list2->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list3->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list4->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list5->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list6->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list7->BackgroundImage=Image::FromFile("list_BG1.bmp"); //
        this->panel_list8->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list9->BackgroundImage=Image::FromFile("list_BG0.bmp");
    }
    else{
        this->active_list=0;
        this->panel_list7->BackgroundImage=Image::FromFile("list_BG0.bmp");
    }
}

System::Void RDSadminMainForm::label_list8_Click(System::Object^  sender, System::EventArgs^  e)
{
    if(this->active_list!=8) {
        this->active_list=8;
        this->panel_list1->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list2->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list3->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list4->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list5->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list6->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list7->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list8->BackgroundImage=Image::FromFile("list_BG1.bmp"); //
        this->panel_list9->BackgroundImage=Image::FromFile("list_BG0.bmp");
    }
    else{
        this->active_list=0;
        this->panel_list8->BackgroundImage=Image::FromFile("list_BG0.bmp");
    }
}

System::Void RDSadminMainForm::label_list9_Click(System::Object^  sender, System::EventArgs^  e)
{
    if(this->active_list!=9) {
        this->active_list=9;
        this->panel_list1->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list2->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list3->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list4->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list5->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list6->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list7->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list8->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list9->BackgroundImage=Image::FromFile("list_BG1.bmp"); //
    }
    else{
        this->active_list=0;
        this->panel_list9->BackgroundImage=Image::FromFile("list_BG0.bmp");
    }
}

//---------------------//
// label double click. //
//---------------------//
System::Void RDSadminMainForm::label_list1_DoubleClick(System::Object^  sender, System::EventArgs^  e)
{
    if(this->active_list==0){
        RDSadmin::rpt_b_Form^ formUser=gcnew rpt_b_Form(this->iNas.I1_filename);
        formUser->belong_Page=this->page;
        formUser->iNas.LoginUser_no=this->iNas.LoginUser_no;
        formUser->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
        formUser->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
        formUser->Show();
        this->Close();
    }
}
System::Void RDSadminMainForm::label_list2_DoubleClick(System::Object^  sender, System::EventArgs^  e)
{
    if(this->active_list==0){
        RDSadmin::rpt_b_Form^ formUser=gcnew rpt_b_Form(this->iNas.I2_filename);
        formUser->belong_Page=this->page;
        formUser->iNas.LoginUser_no=this->iNas.LoginUser_no;
        formUser->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
        formUser->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
        formUser->Show();
        this->Close();
    }
}
System::Void RDSadminMainForm::label_list3_DoubleClick(System::Object^  sender, System::EventArgs^  e)
{
    if(this->active_list==0){
        RDSadmin::rpt_b_Form^ formUser=gcnew rpt_b_Form(this->iNas.I3_filename);
        formUser->belong_Page=this->page;
        formUser->iNas.LoginUser_no=this->iNas.LoginUser_no;
        formUser->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
        formUser->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
        formUser->Show();
        this->Close();
    }
}
System::Void RDSadminMainForm::label_list4_DoubleClick(System::Object^  sender, System::EventArgs^  e)
{
    if(this->active_list==0){
        RDSadmin::rpt_b_Form^ formUser=gcnew rpt_b_Form(this->iNas.I4_filename);
        formUser->belong_Page=this->page;
        formUser->iNas.LoginUser_no=this->iNas.LoginUser_no;
        formUser->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
        formUser->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
        formUser->Show();
        this->Close();
    }
}
System::Void RDSadminMainForm::label_list5_DoubleClick(System::Object^  sender, System::EventArgs^  e)
{
    if(this->active_list==0){
        RDSadmin::rpt_b_Form^ formUser=gcnew rpt_b_Form(this->iNas.I5_filename);
        formUser->belong_Page=this->page;
        formUser->iNas.LoginUser_no=this->iNas.LoginUser_no;
        formUser->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
        formUser->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
        formUser->Show();
        this->Close();
    }
}
System::Void RDSadminMainForm::label_list6_DoubleClick(System::Object^  sender, System::EventArgs^  e)
{
    if(this->active_list==0){
        RDSadmin::rpt_b_Form^ formUser=gcnew rpt_b_Form(this->iNas.I6_filename);
        formUser->belong_Page=this->page;
        formUser->iNas.LoginUser_no=this->iNas.LoginUser_no;
        formUser->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
        formUser->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
        formUser->Show();
        this->Close();
    }
}
System::Void RDSadminMainForm::label_list7_DoubleClick(System::Object^  sender, System::EventArgs^  e)
{
    if(this->active_list==0){
        RDSadmin::rpt_b_Form^ formUser=gcnew rpt_b_Form(this->iNas.I7_filename);
        formUser->belong_Page=this->page;
        formUser->iNas.LoginUser_no=this->iNas.LoginUser_no;
        formUser->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
        formUser->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
        formUser->Show();
        this->Close();
    }
}
System::Void RDSadminMainForm::label_list8_DoubleClick(System::Object^  sender, System::EventArgs^  e)
{
    if(this->active_list==0){
        RDSadmin::rpt_b_Form^ formUser=gcnew rpt_b_Form(this->iNas.I8_filename);
        formUser->belong_Page=this->page;
        formUser->iNas.LoginUser_no=this->iNas.LoginUser_no;
        formUser->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
        formUser->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
        formUser->Show();
        this->Close();
    }
}
System::Void RDSadminMainForm::label_list9_DoubleClick(System::Object^  sender, System::EventArgs^  e)
{
    if(this->active_list==0){
        RDSadmin::rpt_b_Form^ formUser=gcnew rpt_b_Form(this->iNas.I9_filename);
        formUser->belong_Page=this->page;
        formUser->iNas.LoginUser_no=this->iNas.LoginUser_no;
        formUser->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
        formUser->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
        formUser->Show();
        this->Close();
    }
}