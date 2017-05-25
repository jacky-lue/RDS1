//project defines
#include "RDSadmin_project.h"
//
#include "DashBrdForm.h"
#include "RDSadminMainForm.h"
#include "nas_state.h"
#include "SupervisorForm.h"
#include "UserList_Form.h"
#include "DealerListForm.h"
#include "AddDealerForm.h"
#include "DealerForm.h"

using namespace System;
using namespace System::Globalization;
using namespace System::Windows::Forms;
using namespace RDSadmin;
using namespace RDS_NAS;

//====================//
//  Form Load !!!     //
//====================//
System::Void DealerListForm::DealerListForm_Load(System::Object^  sender, System::EventArgs^  e)
{
    this->iNas.HasAdminIni=this->iNas.Check_Admin_Ini();
    this->iNas.HasDealerIni=this->iNas.Check_Dealer_Ini();
    //checking...
    if(this->iNas.HasDealerIni==false){
        MessageBox::Show(FORM_LOAD_DEALERS_INI_LOST, "ERROR",
            MessageBoxButtons::OK,
            MessageBoxIcon::Information);
    }

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
    Draw_DealerList();

    //hide menu buttons when not root Spa Company
    if(this->iNas.Base_dir!=RDS_NAS_ROOT_DIR){
        this->button_Dealer->Visible=false;
        this->button_DashBoard->Visible=false;
    }
}

//----------------//
//  Menu buttons  //
//----------------//
System::Void DealerListForm::button_DashBoard_Click(System::Object^  sender, System::EventArgs^  e)
{
    RDSadmin::DashBrdForm^ formDash=gcnew DashBrdForm();
    formDash->iNas.LoginUser_no=this->iNas.LoginUser_no;
    formDash->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
    formDash->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
    formDash->iNas.Base_dir=this->iNas.Base_dir;
    formDash->Show();
    this->Close();
}

System::Void DealerListForm::button_ServiceCall_Click(System::Object^  sender, System::EventArgs^  e)
{
    RDSadmin::RDSadminMainForm^ formRDSmain=gcnew RDSadminMainForm(0);
    formRDSmain->iNas.LoginUser_no=this->iNas.LoginUser_no;
    formRDSmain->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
    formRDSmain->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
    formRDSmain->iNas.Base_dir=this->iNas.Base_dir;
    formRDSmain->Show();
    this->Close();
}

System::Void DealerListForm::button_RDSuser_Click(System::Object^  sender, System::EventArgs^  e)
{
    RDSadmin::UserList_Form^ formUser=gcnew UserList_Form();
    formUser->iNas.LoginUser_no=this->iNas.LoginUser_no;
    formUser->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
    formUser->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
    formUser->iNas.Base_dir=this->iNas.Base_dir;
    formUser->Show();
    this->Close();
}

System::Void DealerListForm::button_Supervisor_Click(System::Object^  sender, System::EventArgs^  e)
{
    RDSadmin::SupervisorForm^ formSuper=gcnew SupervisorForm();
    formSuper->iNas.LoginUser_no=this->iNas.LoginUser_no;
    formSuper->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
    formSuper->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
    formSuper->iNas.Base_dir=this->iNas.Base_dir;
    formSuper->Show();
    this->Close();
}

//----------------//
//  Draw userlist //
//----------------//
void DealerListForm::Draw_DealerList()
{
    int display_cnt;
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

    if(this->iNas.HasDealerIni==false){
        display_cnt=-1;
    }
    else{
        //read dealers.ini (display_cnt = 2 : means 3 dealers in this display page)
        display_cnt=this->iNas.Read_DealerName_byPage(this->page);
    }

    //check and display
    int i=0;
    if(display_cnt>=0){
        do{
            int ino=i+1+(this->page * RDS_NAS_USERS_PER_PAGE);
            if(i==0) { this->label_list1->Text="Dealer #"+ino+" "+this->iNas.nasStringDecode(this->iNas.listName1); this->panel_list1->Visible=true; }
            if(i==1) { this->label_list2->Text="Dealer #"+ino+" "+this->iNas.nasStringDecode(this->iNas.listName2); this->panel_list2->Visible=true; }
            if(i==2) { this->label_list3->Text="Dealer #"+ino+" "+this->iNas.nasStringDecode(this->iNas.listName3); this->panel_list3->Visible=true; }
            if(i==3) { this->label_list4->Text="Dealer #"+ino+" "+this->iNas.nasStringDecode(this->iNas.listName4); this->panel_list4->Visible=true; }
            if(i==4) { this->label_list5->Text="Dealer #"+ino+" "+this->iNas.nasStringDecode(this->iNas.listName5); this->panel_list5->Visible=true; }
            if(i==5) { this->label_list6->Text="Dealer #"+ino+" "+this->iNas.nasStringDecode(this->iNas.listName6); this->panel_list6->Visible=true; }
            if(i==6) { this->label_list7->Text="Dealer #"+ino+" "+this->iNas.nasStringDecode(this->iNas.listName7); this->panel_list7->Visible=true; }
            if(i==7) { this->label_list8->Text="Dealer #"+ino+" "+this->iNas.nasStringDecode(this->iNas.listName8); this->panel_list8->Visible=true; }
            if(i==8) { this->label_list9->Text="Dealer #"+ino+" "+this->iNas.nasStringDecode(this->iNas.listName9); this->panel_list9->Visible=true; }
            i++;
        } while(i<=display_cnt);
    }
    if(display_cnt<RDS_NAS_USERS_PER_PAGE){
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
        } while(i<RDS_NAS_USERS_PER_PAGE);
    }

    //setting the right/left button
    if(this->page==0) this->button_left->Enabled=false;
    else                 this->button_left->Enabled=true;
    if(this->page==(this->iNas.total_page-1))
        this->button_right->Enabled=false;
    else this->button_right->Enabled=true;
}

//---------------------//
//  Add dealer button  //
//---------------------//
System::Void DealerListForm::button_Add_Click(System::Object^  sender, System::EventArgs^  e)
{
    RDSadmin::AddDealerForm^ formAddDealer=gcnew AddDealerForm();
    formAddDealer->iNas.LoginUser_no=this->iNas.LoginUser_no;
    formAddDealer->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
    formAddDealer->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
    formAddDealer->iNas.Base_dir=this->iNas.Base_dir;
    formAddDealer->Show();
    this->Close();
}

//-------------------//
// Delete Cur dealer //
//-------------------//
System::Void DealerListForm::button_Delete_Click(System::Object^  sender, System::EventArgs^  e)
{
    int rtn;
    String^ dealerDir;

    //check active
    if(this->active_list==0){ //No one be selected
        MessageBox::Show(DEALER_LIST_DELETE_NO_SELECT, "ERROR",
            MessageBoxButtons::OK,
            MessageBoxIcon::Information);
        return;
    }

    //product current dealer from active UI items
    this->iNas.cur_dealer_no=(this->page * RDS_NAS_USERS_PER_PAGE)+this->active_list-1;

    //get dealer information
    rtn=this->iNas.Get_Dealer_Info();
    if(rtn!=0){
        MessageBox::Show(DEALER_LIST_DELETE_NO_THIS, "ERROR",
            MessageBoxButtons::OK,
            MessageBoxIcon::Information);
        return;
    }

    //confirmation
    System::Windows::Forms::DialogResult result;
    result=MessageBox::Show(DEALER_LIST_DELETE_CONFIRMATION, "Confirmation",
        MessageBoxButtons::YesNo,
        MessageBoxIcon::Question,
        MessageBoxDefaultButton::Button1);
    if(result==::DialogResult::No){
        return;
    }

    //(1)delete directory
    dealerDir=RDS_NAS_ROOT_DIR+this->iNas.dealer_ComCode+"\\";
    Directory::Delete(dealerDir, true);

    //(2) delete dealer in dealers.ini
    rtn=this->iNas.Delete_cur_dealer(); //....
    if(rtn==0){
        this->active_list=0; //dis-active all
        Draw_DealerList(); //re-draw dealer list
    }
}

//------------------//
//  Page up / down  //
//------------------//
System::Void DealerListForm::button_right_Click(System::Object^  sender, System::EventArgs^  e)
{
    this->page++;
    Draw_DealerList();
}
System::Void DealerListForm::button_left_Click(System::Object^  sender, System::EventArgs^  e)
{
    this->page--;
    Draw_DealerList();
}

//-----------------------//
//  Panel active or not  //
//-----------------------//
System::Void DealerListForm::panel_list1_Click(System::Object^  sender, System::EventArgs^  e)
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

System::Void DealerListForm::panel_list2_Click(System::Object^  sender, System::EventArgs^  e)
{
    if(this->active_list!=2) {
        this->active_list=2;
        this->panel_list1->BackgroundImage=Image::FromFile("list_BG0.bmp"); //---------
        this->panel_list2->BackgroundImage=Image::FromFile("list_BG1.bmp");
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

System::Void DealerListForm::panel_list3_Click(System::Object^  sender, System::EventArgs^  e)
{
    if(this->active_list!=3) {
        this->active_list=3;
        this->panel_list1->BackgroundImage=Image::FromFile("list_BG0.bmp"); //---------
        this->panel_list2->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list3->BackgroundImage=Image::FromFile("list_BG1.bmp");
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

System::Void DealerListForm::panel_list4_Click(System::Object^  sender, System::EventArgs^  e)
{
    if(this->active_list!=4) {
        this->active_list=4;
        this->panel_list1->BackgroundImage=Image::FromFile("list_BG0.bmp"); //---------
        this->panel_list2->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list3->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list4->BackgroundImage=Image::FromFile("list_BG1.bmp");
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

System::Void DealerListForm::panel_list5_Click(System::Object^  sender, System::EventArgs^  e)
{
    if(this->active_list!=5) {
        this->active_list=5;
        this->panel_list1->BackgroundImage=Image::FromFile("list_BG0.bmp"); //---------
        this->panel_list2->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list3->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list4->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list5->BackgroundImage=Image::FromFile("list_BG1.bmp");
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

System::Void DealerListForm::panel_list6_Click(System::Object^  sender, System::EventArgs^  e)
{
    if(this->active_list!=6) {
        this->active_list=6;
        this->panel_list1->BackgroundImage=Image::FromFile("list_BG0.bmp"); //---------
        this->panel_list2->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list3->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list4->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list5->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list6->BackgroundImage=Image::FromFile("list_BG1.bmp");
        this->panel_list7->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list8->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list9->BackgroundImage=Image::FromFile("list_BG0.bmp");
    }
    else{
        this->active_list=0;
        this->panel_list6->BackgroundImage=Image::FromFile("list_BG0.bmp");
    }
}

System::Void DealerListForm::panel_list7_Click(System::Object^  sender, System::EventArgs^  e)
{
    if(this->active_list!=7) {
        this->active_list=7;
        this->panel_list1->BackgroundImage=Image::FromFile("list_BG0.bmp"); //---------
        this->panel_list2->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list3->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list4->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list5->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list6->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list7->BackgroundImage=Image::FromFile("list_BG1.bmp");
        this->panel_list8->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list9->BackgroundImage=Image::FromFile("list_BG0.bmp");
    }
    else{
        this->active_list=0;
        this->panel_list7->BackgroundImage=Image::FromFile("list_BG0.bmp");
    }
}

System::Void DealerListForm::panel_list8_Click(System::Object^  sender, System::EventArgs^  e)
{
    if(this->active_list!=8) {
        this->active_list=8;
        this->panel_list1->BackgroundImage=Image::FromFile("list_BG0.bmp"); //---------
        this->panel_list2->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list3->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list4->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list5->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list6->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list7->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list8->BackgroundImage=Image::FromFile("list_BG1.bmp");
        this->panel_list9->BackgroundImage=Image::FromFile("list_BG0.bmp");
    }
    else{
        this->active_list=0;
        this->panel_list8->BackgroundImage=Image::FromFile("list_BG0.bmp");
    }
}

System::Void DealerListForm::panel_list9_Click(System::Object^  sender, System::EventArgs^  e)
{
    if(this->active_list!=9) {
        this->active_list=9;
        this->panel_list1->BackgroundImage=Image::FromFile("list_BG0.bmp"); //---------
        this->panel_list2->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list3->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list4->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list5->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list6->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list7->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list8->BackgroundImage=Image::FromFile("list_BG0.bmp");
        this->panel_list9->BackgroundImage=Image::FromFile("list_BG1.bmp");
    }
    else{
        this->active_list=0;
        this->panel_list9->BackgroundImage=Image::FromFile("list_BG0.bmp");
    }
}

//----------------//
// label active . //
//----------------//
System::Void DealerListForm::label_list1_Click(System::Object^  sender, System::EventArgs^  e)
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

System::Void DealerListForm::label_list2_Click(System::Object^  sender, System::EventArgs^  e)
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

System::Void DealerListForm::label_list3_Click(System::Object^  sender, System::EventArgs^  e)
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

System::Void DealerListForm::label_list4_Click(System::Object^  sender, System::EventArgs^  e)
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

System::Void DealerListForm::label_list5_Click(System::Object^  sender, System::EventArgs^  e)
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

System::Void DealerListForm::label_list6_Click(System::Object^  sender, System::EventArgs^  e)
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

System::Void DealerListForm::label_list7_Click(System::Object^  sender, System::EventArgs^  e)
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

System::Void DealerListForm::label_list8_Click(System::Object^  sender, System::EventArgs^  e)
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

System::Void DealerListForm::label_list9_Click(System::Object^  sender, System::EventArgs^  e)
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

//-----------------------//
//  Panel select dealer  //
//-----------------------//
System::Void DealerListForm::panel_list1_DoubleClick(System::Object^  sender, System::EventArgs^  e)
{
    if(this->active_list==0){
        RDSadmin::DealerForm^ formDealer=gcnew DealerForm();
        formDealer->iNas.cur_dealer_no=(this->page * RDS_NAS_DEALERS_PER_PAGE);
        formDealer->iNas.LoginUser_no=this->iNas.LoginUser_no;
        formDealer->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
        formDealer->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
        formDealer->iNas.Base_dir=this->iNas.Base_dir;
        formDealer->Show();
        this->Close();
    }
}

System::Void DealerListForm::panel_list2_DoubleClick(System::Object^  sender, System::EventArgs^  e)
{
    if(this->active_list==0){
        RDSadmin::DealerForm^ formDealer=gcnew DealerForm();
        formDealer->iNas.cur_dealer_no=(this->page * RDS_NAS_DEALERS_PER_PAGE)+1;
        formDealer->iNas.LoginUser_no=this->iNas.LoginUser_no;
        formDealer->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
        formDealer->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
        formDealer->iNas.Base_dir=this->iNas.Base_dir;
        formDealer->Show();
        this->Close();
    }
}

System::Void DealerListForm::panel_list3_DoubleClick(System::Object^  sender, System::EventArgs^  e)
{
    if(this->active_list==0){
        RDSadmin::DealerForm^ formDealer=gcnew DealerForm();
        formDealer->iNas.cur_dealer_no=(this->page * RDS_NAS_DEALERS_PER_PAGE)+2;
        formDealer->iNas.LoginUser_no=this->iNas.LoginUser_no;
        formDealer->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
        formDealer->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
        formDealer->iNas.Base_dir=this->iNas.Base_dir;
        formDealer->Show();
        this->Close();
    }
}

System::Void DealerListForm::panel_list4_DoubleClick(System::Object^  sender, System::EventArgs^  e)
{
    if(this->active_list==0){
        RDSadmin::DealerForm^ formDealer=gcnew DealerForm();
        formDealer->iNas.cur_dealer_no=(this->page * RDS_NAS_DEALERS_PER_PAGE)+3;
        formDealer->iNas.LoginUser_no=this->iNas.LoginUser_no;
        formDealer->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
        formDealer->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
        formDealer->iNas.Base_dir=this->iNas.Base_dir;
        formDealer->Show();
        this->Close();
    }
}

System::Void DealerListForm::panel_list5_DoubleClick(System::Object^  sender, System::EventArgs^  e)
{
    if(this->active_list==0){
        RDSadmin::DealerForm^ formDealer=gcnew DealerForm();
        formDealer->iNas.cur_dealer_no=(this->page * RDS_NAS_DEALERS_PER_PAGE)+4;
        formDealer->iNas.LoginUser_no=this->iNas.LoginUser_no;
        formDealer->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
        formDealer->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
        formDealer->iNas.Base_dir=this->iNas.Base_dir;
        formDealer->Show();
        this->Close();
    }
}

System::Void DealerListForm::panel_list6_DoubleClick(System::Object^  sender, System::EventArgs^  e)
{
    if(this->active_list==0){
        RDSadmin::DealerForm^ formDealer=gcnew DealerForm();
        formDealer->iNas.cur_dealer_no=(this->page * RDS_NAS_DEALERS_PER_PAGE)+5;
        formDealer->iNas.LoginUser_no=this->iNas.LoginUser_no;
        formDealer->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
        formDealer->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
        formDealer->iNas.Base_dir=this->iNas.Base_dir;
        formDealer->Show();
        this->Close();
    }
}

System::Void DealerListForm::panel_list7_DoubleClick(System::Object^  sender, System::EventArgs^  e)
{
    if(this->active_list==0){
        RDSadmin::DealerForm^ formDealer=gcnew DealerForm();
        formDealer->iNas.cur_dealer_no=(this->page * RDS_NAS_DEALERS_PER_PAGE)+6;
        formDealer->iNas.LoginUser_no=this->iNas.LoginUser_no;
        formDealer->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
        formDealer->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
        formDealer->iNas.Base_dir=this->iNas.Base_dir;
        formDealer->Show();
        this->Close();
    }
}

System::Void DealerListForm::panel_list8_DoubleClick(System::Object^  sender, System::EventArgs^  e)
{
    if(this->active_list==0){
        RDSadmin::DealerForm^ formDealer=gcnew DealerForm();
        formDealer->iNas.cur_dealer_no=(this->page * RDS_NAS_DEALERS_PER_PAGE)+7;
        formDealer->iNas.LoginUser_no=this->iNas.LoginUser_no;
        formDealer->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
        formDealer->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
        formDealer->iNas.Base_dir=this->iNas.Base_dir;
        formDealer->Show();
        this->Close();
    }
}

System::Void DealerListForm::panel_list9_DoubleClick(System::Object^  sender, System::EventArgs^  e)
{
    if(this->active_list==0){
        RDSadmin::DealerForm^ formDealer=gcnew DealerForm();
        formDealer->iNas.cur_dealer_no=(this->page * RDS_NAS_DEALERS_PER_PAGE)+8;
        formDealer->iNas.LoginUser_no=this->iNas.LoginUser_no;
        formDealer->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
        formDealer->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
        formDealer->iNas.Base_dir=this->iNas.Base_dir;
        formDealer->Show();
        this->Close();
    }
}

//-----------------------//
//  Label select dealer  //
//-----------------------//
System::Void DealerListForm::label_list1_DoubleClick(System::Object^  sender, System::EventArgs^  e)
{
    if(this->active_list==0){
        RDSadmin::DealerForm^ formDealer=gcnew DealerForm();
        formDealer->iNas.cur_dealer_no=(this->page * RDS_NAS_DEALERS_PER_PAGE);
        formDealer->iNas.LoginUser_no=this->iNas.LoginUser_no;
        formDealer->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
        formDealer->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
        formDealer->iNas.Base_dir=this->iNas.Base_dir;
        formDealer->Show();
        this->Close();
    }
}

System::Void DealerListForm::label_list2_DoubleClick(System::Object^  sender, System::EventArgs^  e)
{
    if(this->active_list==0){
        RDSadmin::DealerForm^ formDealer=gcnew DealerForm();
        formDealer->iNas.cur_dealer_no=(this->page * RDS_NAS_DEALERS_PER_PAGE)+1;
        formDealer->iNas.LoginUser_no=this->iNas.LoginUser_no;
        formDealer->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
        formDealer->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
        formDealer->iNas.Base_dir=this->iNas.Base_dir;
        formDealer->Show();
        this->Close();
    }
}

System::Void DealerListForm::label_list3_DoubleClick(System::Object^  sender, System::EventArgs^  e)
{
    if(this->active_list==0){
        RDSadmin::DealerForm^ formDealer=gcnew DealerForm();
        formDealer->iNas.cur_dealer_no=(this->page * RDS_NAS_DEALERS_PER_PAGE)+2;
        formDealer->iNas.LoginUser_no=this->iNas.LoginUser_no;
        formDealer->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
        formDealer->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
        formDealer->iNas.Base_dir=this->iNas.Base_dir;
        formDealer->Show();
        this->Close();
    }
}

System::Void DealerListForm::label_list4_DoubleClick(System::Object^  sender, System::EventArgs^  e)
{
    if(this->active_list==0){
        RDSadmin::DealerForm^ formDealer=gcnew DealerForm();
        formDealer->iNas.cur_dealer_no=(this->page * RDS_NAS_DEALERS_PER_PAGE)+3;
        formDealer->iNas.LoginUser_no=this->iNas.LoginUser_no;
        formDealer->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
        formDealer->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
        formDealer->iNas.Base_dir=this->iNas.Base_dir;
        formDealer->Show();
        this->Close();
    }
}

System::Void DealerListForm::label_list5_DoubleClick(System::Object^  sender, System::EventArgs^  e)
{
    if(this->active_list==0){
        RDSadmin::DealerForm^ formDealer=gcnew DealerForm();
        formDealer->iNas.cur_dealer_no=(this->page * RDS_NAS_DEALERS_PER_PAGE)+4;
        formDealer->iNas.LoginUser_no=this->iNas.LoginUser_no;
        formDealer->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
        formDealer->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
        formDealer->iNas.Base_dir=this->iNas.Base_dir;
        formDealer->Show();
        this->Close();
    }
}

System::Void DealerListForm::label_list6_DoubleClick(System::Object^  sender, System::EventArgs^  e)
{
    if(this->active_list==0){
        RDSadmin::DealerForm^ formDealer=gcnew DealerForm();
        formDealer->iNas.cur_dealer_no=(this->page * RDS_NAS_DEALERS_PER_PAGE)+5;
        formDealer->iNas.LoginUser_no=this->iNas.LoginUser_no;
        formDealer->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
        formDealer->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
        formDealer->iNas.Base_dir=this->iNas.Base_dir;
        formDealer->Show();
        this->Close();
    }
}

System::Void DealerListForm::label_list7_DoubleClick(System::Object^  sender, System::EventArgs^  e)
{
    if(this->active_list==0){
        RDSadmin::DealerForm^ formDealer=gcnew DealerForm();
        formDealer->iNas.cur_dealer_no=(this->page * RDS_NAS_DEALERS_PER_PAGE)+6;
        formDealer->iNas.LoginUser_no=this->iNas.LoginUser_no;
        formDealer->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
        formDealer->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
        formDealer->iNas.Base_dir=this->iNas.Base_dir;
        formDealer->Show();
        this->Close();
    }
}

System::Void DealerListForm::label_list8_DoubleClick(System::Object^  sender, System::EventArgs^  e)
{
    if(this->active_list==0){
        RDSadmin::DealerForm^ formDealer=gcnew DealerForm();
        formDealer->iNas.cur_dealer_no=(this->page * RDS_NAS_DEALERS_PER_PAGE)+7;
        formDealer->iNas.LoginUser_no=this->iNas.LoginUser_no;
        formDealer->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
        formDealer->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
        formDealer->iNas.Base_dir=this->iNas.Base_dir;
        formDealer->Show();
        this->Close();
    }
}

System::Void DealerListForm::label_list9_DoubleClick(System::Object^  sender, System::EventArgs^  e)
{
    if(this->active_list==0){
        RDSadmin::DealerForm^ formDealer=gcnew DealerForm();
        formDealer->iNas.cur_dealer_no=(this->page * RDS_NAS_DEALERS_PER_PAGE)+8;
        formDealer->iNas.LoginUser_no=this->iNas.LoginUser_no;
        formDealer->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
        formDealer->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
        formDealer->iNas.Base_dir=this->iNas.Base_dir;
        formDealer->Show();
        this->Close();
    }
}