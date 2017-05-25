//project defines
#include "RDSadmin_project.h"
//
#include "DashBrdForm.h"
#include "RDSadminMainForm.h"
#include "nas_state.h"
#include "SupervisorForm.h"
#include "UserList_Form.h"
#include "AddUserForm.h"
#include "UserForm.h"
#include "DealerListForm.h"

using namespace System;
using namespace System::Globalization;
using namespace System::Windows::Forms;
using namespace RDSadmin;
using namespace RDS_NAS;

//====================//
//  Form Load !!!     //
//====================//
System::Void UserList_Form::UserList_Form_Load(System::Object^  sender, System::EventArgs^  e)
{
    this->iNas.HasAdminIni=this->iNas.Check_Admin_Ini();
    this->iNas.HasUsersIni=this->iNas.Check_User_Ini();
    //checking...
    if(this->iNas.HasUsersIni==false){
        MessageBox::Show(FORM_LOAD_USERS_INI_LOST, "ERROR",
            MessageBoxButtons::OK,
            MessageBoxIcon::Information);
        this->Close();
    }
    else{
        //show Login-User
        this->label_LoginID->Text=this->iNas.LoginUser_ID;
        this->label_LoginAuthorLv->Text=this->iNas.LoginUser_AuthLevel;

        //Hide Buttons by authority_level
        if(this->iNas.LoginUser_AuthLevel!=RDS_NAS_AUTHORITY_LEVEL_0){
            this->button_Add->Enabled=false;
            this->button_Delete->Enabled=false;
            this->button_Add->Visible=false;
            this->button_Delete->Visible=false;
            //
            this->button_Supervisor->Visible=false;
        }

        //list users from users.ini
        this->page=0;
        Draw_UserList();

        //hide menu buttons when not root Spa Company
        if(this->iNas.Base_dir!=RDS_NAS_ROOT_DIR){
            this->button_Dealer->Visible=false;
            this->button_DashBoard->Visible=false;
        }
    }
}

//----------------//
//  Draw userlist //
//----------------//
void UserList_Form::Draw_UserList()
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

    //read user.ini (display_cnt = 2 : means 3 users in this display page)
    int display_cnt=this->iNas.Read_UserName_byPage(this->page);

    //check and display
    int i=0;
    do{
        int ino=i+1+(this->page * RDS_NAS_USERS_PER_PAGE);
        if(i==0) { this->label_list1->Text="Account #"+ino+" "+this->iNas.nasStringDecode(this->iNas.listName1); this->panel_list1->Visible=true; }
        if(i==1) { this->label_list2->Text="Account #"+ino+" "+this->iNas.nasStringDecode(this->iNas.listName2); this->panel_list2->Visible=true; }
        if(i==2) { this->label_list3->Text="Account #"+ino+" "+this->iNas.nasStringDecode(this->iNas.listName3); this->panel_list3->Visible=true; }
        if(i==3) { this->label_list4->Text="Account #"+ino+" "+this->iNas.nasStringDecode(this->iNas.listName4); this->panel_list4->Visible=true; }
        if(i==4) { this->label_list5->Text="Account #"+ino+" "+this->iNas.nasStringDecode(this->iNas.listName5); this->panel_list5->Visible=true; }
        if(i==5) { this->label_list6->Text="Account #"+ino+" "+this->iNas.nasStringDecode(this->iNas.listName6); this->panel_list6->Visible=true; }
        if(i==6) { this->label_list7->Text="Account #"+ino+" "+this->iNas.nasStringDecode(this->iNas.listName7); this->panel_list7->Visible=true; }
        if(i==7) { this->label_list8->Text="Account #"+ino+" "+this->iNas.nasStringDecode(this->iNas.listName8); this->panel_list8->Visible=true; }
        if(i==8) { this->label_list9->Text="Account #"+ino+" "+this->iNas.nasStringDecode(this->iNas.listName9); this->panel_list9->Visible=true; }
        i++;
    } while(i<=display_cnt);
    if(display_cnt<RDS_NAS_USERS_PER_PAGE){
        do{
            if(i==1){ this->panel_list2->Visible=false; }
            if(i==2){ this->panel_list3->Visible=false; }
            if(i==3){ this->panel_list4->Visible=false; }
            if(i==4){ this->panel_list5->Visible=false; }
            if(i==5){ this->panel_list6->Visible=false; }
            if(i==6){ this->panel_list7->Visible=false; }
            if(i==7){ this->panel_list8->Visible=false; }
            if(i==8){ this->panel_list9->Visible=false; }
            i++;
        } while(i<RDS_NAS_USERS_PER_PAGE);
    }

    //setting the right/left button
    if(this->page==0) this->button_left->Enabled=false;
    else                 this->button_left->Enabled=true;
    if(this->page==(this->iNas.total_page-1))
        this->button_right->Enabled=false;
    else this->button_right->Enabled=true;
}

//----------------//
//  Menu buttons  //
//----------------//
System::Void UserList_Form::button_DashBoard_Click(System::Object^  sender, System::EventArgs^  e)
{
    RDSadmin::DashBrdForm^ formDash=gcnew DashBrdForm();
    formDash->iNas.LoginUser_no=this->iNas.LoginUser_no;
    formDash->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
    formDash->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
    formDash->iNas.Base_dir=this->iNas.Base_dir;
    formDash->Show();
    this->Close();
}

System::Void UserList_Form::button_ServiceCall_Click(System::Object^  sender, System::EventArgs^  e)
{
    RDSadmin::RDSadminMainForm^ formRDSmain=gcnew RDSadminMainForm(0);
    formRDSmain->iNas.LoginUser_no=this->iNas.LoginUser_no;
    formRDSmain->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
    formRDSmain->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
    formRDSmain->iNas.Base_dir=this->iNas.Base_dir;
    formRDSmain->Show();
    this->Close();
}

System::Void UserList_Form::button_Supervisor_Click(System::Object^  sender, System::EventArgs^  e)
{
    RDSadmin::SupervisorForm^ formSuper=gcnew SupervisorForm();
    formSuper->iNas.LoginUser_no=this->iNas.LoginUser_no;
    formSuper->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
    formSuper->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
    formSuper->iNas.Base_dir=this->iNas.Base_dir;
    formSuper->Show();
    this->Close();
}

System::Void UserList_Form::button_Dealer_Click(System::Object^  sender, System::EventArgs^  e)
{
    RDSadmin::DealerListForm^ formDealer=gcnew DealerListForm();
    formDealer->iNas.LoginUser_no=this->iNas.LoginUser_no;
    formDealer->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
    formDealer->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
    formDealer->iNas.Base_dir=this->iNas.Base_dir;
    formDealer->Show();
    this->Close();
}

//-------------------//
//  Add user button  //
//-------------------//
System::Void UserList_Form::button_Add_Click(System::Object^  sender, System::EventArgs^  e)
{
    RDSadmin::AddUserForm^ formAddUser=gcnew AddUserForm();
    formAddUser->iNas.LoginUser_no=this->iNas.LoginUser_no;
    formAddUser->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
    formAddUser->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
    formAddUser->iNas.Base_dir=this->iNas.Base_dir;
    formAddUser->Show();
    this->Close();
}

//------------------//
//  Delete cur.user //
//------------------//
System::Void UserList_Form::button_Delete_Click(System::Object^  sender, System::EventArgs^  e)
{
    //check active
    if(this->active_list==0){ //No one be selected
        return;
    }
    this->iNas.current_user_no=(this->page * RDS_NAS_USERS_PER_PAGE)+this->active_list-1;
    if(this->iNas.current_user_no==0){
        MessageBox::Show(USER_LIST_NOT_DELETE_SUPERVISOR, "NOTICE",
            MessageBoxButtons::OK,
            MessageBoxIcon::Information);
        return;
    }
    //confirmation
    System::Windows::Forms::DialogResult result;
    result=MessageBox::Show(
        USER_LIST_DELETE_CONFIRMATION, "Confirmation",
        MessageBoxButtons::YesNo,
        MessageBoxIcon::Question,
        MessageBoxDefaultButton::Button1);
    if(result==::DialogResult::No){
        return;
    }

    int rtn;
    rtn=this->iNas.Delete_currentUser(); //....
    if(rtn==0)Draw_UserList(); //re-draw user list
}

//------------------//
//  Page up / down  //
//------------------//
System::Void UserList_Form::button_right_Click(System::Object^  sender, System::EventArgs^  e)
{
    this->page++;
    Draw_UserList();
}
System::Void UserList_Form::button_left_Click(System::Object^  sender, System::EventArgs^  e)
{
    this->page--;
    Draw_UserList();
}

//-----------------------//
//  Panel active or not  //
//-----------------------//
System::Void UserList_Form::panel_list1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
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

System::Void UserList_Form::panel_list2_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
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

System::Void UserList_Form::panel_list3_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
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

System::Void UserList_Form::panel_list4_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
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

System::Void UserList_Form::panel_list5_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
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

System::Void UserList_Form::panel_list6_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
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

System::Void UserList_Form::panel_list7_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
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

System::Void UserList_Form::panel_list8_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
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

System::Void UserList_Form::panel_list9_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
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

//----------------//
// label active . //
//----------------//
System::Void UserList_Form::label_list1_Click(System::Object^  sender, System::EventArgs^  e)
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

System::Void UserList_Form::label_list2_Click(System::Object^  sender, System::EventArgs^  e)
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

System::Void UserList_Form::label_list3_Click(System::Object^  sender, System::EventArgs^  e)
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

System::Void UserList_Form::label_list4_Click(System::Object^  sender, System::EventArgs^  e)
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

System::Void UserList_Form::label_list5_Click(System::Object^  sender, System::EventArgs^  e)
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

System::Void UserList_Form::label_list6_Click(System::Object^  sender, System::EventArgs^  e)
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

System::Void UserList_Form::label_list7_Click(System::Object^  sender, System::EventArgs^  e)
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

System::Void UserList_Form::label_list8_Click(System::Object^  sender, System::EventArgs^  e)
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

System::Void UserList_Form::label_list9_Click(System::Object^  sender, System::EventArgs^  e)
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
//  Panel select user  //
//---------------------//
System::Void UserList_Form::panel_list1_MouseDoubleClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
    if(this->active_list==0){
        if(this->page!=0){
            RDSadmin::UserForm^ formUser=gcnew UserForm();
            formUser->iNas.current_user_no=(this->page * RDS_NAS_USERS_PER_PAGE);
            formUser->iNas.LoginUser_no=this->iNas.LoginUser_no;
            formUser->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
            formUser->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
            formUser->iNas.Base_dir=this->iNas.Base_dir;
            formUser->Show();
            this->Close();
        }
        else{  // same as supervisor case
            RDSadmin::SupervisorForm^ formSuper=gcnew SupervisorForm();
            formSuper->iNas.LoginUser_no=this->iNas.LoginUser_no;
            formSuper->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
            formSuper->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
            formSuper->iNas.Base_dir=this->iNas.Base_dir;
            formSuper->Show();
            this->Close();
        }
    }
}

System::Void UserList_Form::panel_list2_MouseDoubleClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
    if(this->active_list==0){
        RDSadmin::UserForm^ formUser=gcnew UserForm();
        formUser->iNas.current_user_no=(this->page * RDS_NAS_USERS_PER_PAGE)+1;
        formUser->iNas.LoginUser_no=this->iNas.LoginUser_no;
        formUser->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
        formUser->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
        formUser->iNas.Base_dir=this->iNas.Base_dir;
        formUser->Show();
        this->Close();
    }
}

System::Void UserList_Form::panel_list3_MouseDoubleClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
    if(this->active_list==0){
        RDSadmin::UserForm^ formUser=gcnew UserForm();
        formUser->iNas.current_user_no=(this->page * RDS_NAS_USERS_PER_PAGE)+2;
        formUser->iNas.LoginUser_no=this->iNas.LoginUser_no;
        formUser->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
        formUser->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
        formUser->iNas.Base_dir=this->iNas.Base_dir;
        formUser->Show();
        this->Close();
    }
}

System::Void UserList_Form::panel_list4_MouseDoubleClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
    if(this->active_list==0){
        RDSadmin::UserForm^ formUser=gcnew UserForm();
        formUser->iNas.current_user_no=(this->page * RDS_NAS_USERS_PER_PAGE)+3;
        formUser->iNas.LoginUser_no=this->iNas.LoginUser_no;
        formUser->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
        formUser->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
        formUser->iNas.Base_dir=this->iNas.Base_dir;
        formUser->Show();
        this->Close();
    }
}

System::Void UserList_Form::panel_list5_MouseDoubleClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
    if(this->active_list==0){
        RDSadmin::UserForm^ formUser=gcnew UserForm();
        formUser->iNas.current_user_no=(this->page * RDS_NAS_USERS_PER_PAGE)+4;
        formUser->iNas.LoginUser_no=this->iNas.LoginUser_no;
        formUser->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
        formUser->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
        formUser->iNas.Base_dir=this->iNas.Base_dir;
        formUser->Show();
        this->Close();
    }
}

System::Void UserList_Form::panel_list6_MouseDoubleClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
    if(this->active_list==0){
        RDSadmin::UserForm^ formUser=gcnew UserForm();
        formUser->iNas.current_user_no=(this->page * RDS_NAS_USERS_PER_PAGE)+5;
        formUser->iNas.LoginUser_no=this->iNas.LoginUser_no;
        formUser->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
        formUser->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
        formUser->iNas.Base_dir=this->iNas.Base_dir;
        formUser->Show();
        this->Close();
    }
}

System::Void UserList_Form::panel_list7_MouseDoubleClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
    if(this->active_list==0){
        RDSadmin::UserForm^ formUser=gcnew UserForm();
        formUser->iNas.current_user_no=(this->page * RDS_NAS_USERS_PER_PAGE)+6;
        formUser->iNas.LoginUser_no=this->iNas.LoginUser_no;
        formUser->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
        formUser->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
        formUser->iNas.Base_dir=this->iNas.Base_dir;
        formUser->Show();
        this->Close();
    }
}

System::Void UserList_Form::panel_list8_MouseDoubleClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
    if(this->active_list==0){
        RDSadmin::UserForm^ formUser=gcnew UserForm();
        formUser->iNas.current_user_no=(this->page * RDS_NAS_USERS_PER_PAGE)+7;
        formUser->iNas.LoginUser_no=this->iNas.LoginUser_no;
        formUser->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
        formUser->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
        formUser->iNas.Base_dir=this->iNas.Base_dir;
        formUser->Show();
        this->Close();
    }
}

System::Void UserList_Form::panel_list9_MouseDoubleClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
    if(this->active_list==0){
        RDSadmin::UserForm^ formUser=gcnew UserForm();
        formUser->iNas.current_user_no=(this->page * RDS_NAS_USERS_PER_PAGE)+8;
        formUser->iNas.LoginUser_no=this->iNas.LoginUser_no;
        formUser->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
        formUser->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
        formUser->iNas.Base_dir=this->iNas.Base_dir;
        formUser->Show();
        this->Close();
    }
}

//=======================
System::Void UserList_Form::label_list1_DoubleClick(System::Object^  sender, System::EventArgs^  e)
{
    if(this->active_list==0){
        if(this->page!=0){
            RDSadmin::UserForm^ formUser=gcnew UserForm();
            formUser->iNas.current_user_no=(this->page * RDS_NAS_USERS_PER_PAGE);
            formUser->iNas.LoginUser_no=this->iNas.LoginUser_no;
            formUser->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
            formUser->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
            formUser->iNas.Base_dir=this->iNas.Base_dir;
            formUser->Show();
            this->Close();
        }
        else{  // same as supervisor case
            RDSadmin::SupervisorForm^ formSuper=gcnew SupervisorForm();
            formSuper->iNas.LoginUser_no=this->iNas.LoginUser_no;
            formSuper->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
            formSuper->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
            formSuper->iNas.Base_dir=this->iNas.Base_dir;
            formSuper->Show();
            this->Close();
        }
    }
}

System::Void UserList_Form::label_list2_DoubleClick(System::Object^  sender, System::EventArgs^  e)
{
    if(this->active_list==0){
        RDSadmin::UserForm^ formUser=gcnew UserForm();
        formUser->iNas.current_user_no=(this->page * RDS_NAS_USERS_PER_PAGE)+1;
        formUser->iNas.LoginUser_no=this->iNas.LoginUser_no;
        formUser->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
        formUser->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
        formUser->iNas.Base_dir=this->iNas.Base_dir;
        formUser->Show();
        this->Close();
    }
}

System::Void UserList_Form::label_list3_DoubleClick(System::Object^  sender, System::EventArgs^  e)
{
    if(this->active_list==0){
        RDSadmin::UserForm^ formUser=gcnew UserForm();
        formUser->iNas.current_user_no=(this->page * RDS_NAS_USERS_PER_PAGE)+2;
        formUser->iNas.LoginUser_no=this->iNas.LoginUser_no;
        formUser->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
        formUser->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
        formUser->iNas.Base_dir=this->iNas.Base_dir;
        formUser->Show();
        this->Close();
    }
}

System::Void UserList_Form::label_list4_DoubleClick(System::Object^  sender, System::EventArgs^  e)
{
    if(this->active_list==0){
        RDSadmin::UserForm^ formUser=gcnew UserForm();
        formUser->iNas.current_user_no=(this->page * RDS_NAS_USERS_PER_PAGE)+3;
        formUser->iNas.LoginUser_no=this->iNas.LoginUser_no;
        formUser->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
        formUser->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
        formUser->iNas.Base_dir=this->iNas.Base_dir;
        formUser->Show();
        this->Close();
    }
}

System::Void UserList_Form::label_list5_DoubleClick(System::Object^  sender, System::EventArgs^  e)
{
    if(this->active_list==0){
        RDSadmin::UserForm^ formUser=gcnew UserForm();
        formUser->iNas.current_user_no=(this->page * RDS_NAS_USERS_PER_PAGE)+4;
        formUser->iNas.LoginUser_no=this->iNas.LoginUser_no;
        formUser->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
        formUser->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
        formUser->iNas.Base_dir=this->iNas.Base_dir;
        formUser->Show();
        this->Close();
    }
}

System::Void UserList_Form::label_list6_DoubleClick(System::Object^  sender, System::EventArgs^  e)
{
    if(this->active_list==0){
        RDSadmin::UserForm^ formUser=gcnew UserForm();
        formUser->iNas.current_user_no=(this->page * RDS_NAS_USERS_PER_PAGE)+5;
        formUser->iNas.LoginUser_no=this->iNas.LoginUser_no;
        formUser->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
        formUser->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
        formUser->iNas.Base_dir=this->iNas.Base_dir;
        formUser->Show();
        this->Close();
    }
}

System::Void UserList_Form::label_list7_DoubleClick(System::Object^  sender, System::EventArgs^  e)
{
    if(this->active_list==0){
        RDSadmin::UserForm^ formUser=gcnew UserForm();
        formUser->iNas.current_user_no=(this->page * RDS_NAS_USERS_PER_PAGE)+6;
        formUser->iNas.LoginUser_no=this->iNas.LoginUser_no;
        formUser->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
        formUser->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
        formUser->iNas.Base_dir=this->iNas.Base_dir;
        formUser->Show();
        this->Close();
    }
}

System::Void UserList_Form::label_list8_DoubleClick(System::Object^  sender, System::EventArgs^  e)
{
    if(this->active_list==0){
        RDSadmin::UserForm^ formUser=gcnew UserForm();
        formUser->iNas.current_user_no=(this->page * RDS_NAS_USERS_PER_PAGE)+7;
        formUser->iNas.LoginUser_no=this->iNas.LoginUser_no;
        formUser->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
        formUser->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
        formUser->iNas.Base_dir=this->iNas.Base_dir;
        formUser->Show();
        this->Close();
    }
}

System::Void UserList_Form::label_list9_DoubleClick(System::Object^  sender, System::EventArgs^  e)
{
    if(this->active_list==0){
        RDSadmin::UserForm^ formUser=gcnew UserForm();
        formUser->iNas.current_user_no=(this->page * RDS_NAS_USERS_PER_PAGE)+8;
        formUser->iNas.LoginUser_no=this->iNas.LoginUser_no;
        formUser->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
        formUser->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
        formUser->iNas.Base_dir=this->iNas.Base_dir;
        formUser->Show();
        this->Close();
    }
}