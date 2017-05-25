//project defines
#include "RDSadmin_project.h"
//
#include "RDSadminMainForm.h"
#include "nas_state.h"
#include "SupervisorForm.h"
#include "UserList_Form.h"
#include "DealerListForm.h"
#include "DashBrdForm.h"
#include "Dash2Form.h"
//
#include "data4chart.h"
extern struct ChartArea_1_XY_type Chart_1_Data[DASHBOARD2_CHART1_SERIES_LENNGTH];
extern struct ChartArea_2_XY_type Chart_2_Data[DASHBOARD2_CHART1_SERIES_LENNGTH];
extern struct ChartArea_3_XY_type Chart_3_Data[DASHBOARD2_CHART3_SERIES_LENNGTH];
extern struct ChartArea_4_XY_type Chart_4_Data[DASHBOARD2_CHART4_SERIES_LENNGTH];
extern struct ChartArea_5_XY_type Chart_5_Data[DASHBOARD2_CHART5_SERIES_LENNGTH];
extern struct ChartArea_6_XY_type Chart_6_Data[DASHBOARD2_CHART6_SERIES_LENNGTH];

using namespace System;
using namespace System::Globalization;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace RDSadmin;
using namespace RDS_NAS;

//====================//
//  Form Load !!!     //
//====================//
System::Void Dash2Form::Dash2Form_Load(System::Object^  sender, System::EventArgs^  e)
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
            this->button_Supervisor->Visible=false;
        }

        //hide menu buttons when not root Spa Company
        if(this->iNas.Base_dir!=RDS_NAS_ROOT_DIR){
            this->button_Dealer->Visible=false;
            this->button_DashBoard->Visible=false;
        }

        //load all chart !!
        LoadChart();
    }
}

//----------------//
//  Load Charts   //
//----------------//
System::Void Dash2Form::LoadChart()
{
    String^ my_title_Text;

    //Chart-1 : Open serice calls ================================================
    my_title_Text=CHART_1_TITLE_FIRST+DASHBOARD2_CHART1_TOTAL_OSC+"\n"+CHART_1_TITLE_SECOND;
    this->chart_OSC_Dealer_T10->Titles["Title1"]->Text=my_title_Text;
    //load data
    for(int i=0; i<DASHBOARD2_CHART1_SERIES_LENNGTH; i++){
        this->chart_OSC_Dealer_T10->Series["OpenServiceCall"]->Points->AddXY(
            gcnew String(Chart_1_Data[i].dealer_name), Chart_1_Data[i].calls);
    }

    //Chart-2 : Open serice calls ================================================
    my_title_Text=CHART_2_TITLE_FIRST;
    this->chart_Efficiency->Titles["Title1"]->Text=my_title_Text;
    //load data
    for(int i=0; i<DASHBOARD2_CHART1_SERIES_LENNGTH; i++){
        this->chart_Efficiency->Series["DealerEfficiency"]->Points->AddXY(
            gcnew String(Chart_2_Data[i].dealer_name), Chart_2_Data[i].effct);
    }
    //ToolTip
    this->chart_Efficiency->Series["DealerEfficiency"]->ToolTip=CHART_2_SERIES_TOOLTIP;

    //Chart-3 : ================================================
    my_title_Text=CHART_3_TITLE_FIRST;
    this->chart_Channel->Titles["Title1"]->Text=my_title_Text;
    //load data
    for(int i=0; i<DASHBOARD2_CHART3_SERIES_LENNGTH; i++){
        this->chart_Channel->Series["CallByChannel"]->Points->AddXY(
            gcnew String(Chart_3_Data[i].channel_name), Chart_3_Data[i].calls);
    }
    //ToolTip & Label
    this->chart_Channel->Series["CallByChannel"]->Label="#VALX,#PERCENT{P1}";
    this->chart_Channel->Series["CallByChannel"]->ToolTip=CHART_3_SERIES_TOOLTIP+"#VALX = #VALY";

    //Chart-4 : ================================================
    my_title_Text=CHART_4_TITLE_FIRST;
    this->chart_Parts->Titles["Title1"]->Text=my_title_Text;
    //load data
    for(int i=0; i<DASHBOARD2_CHART4_SERIES_LENNGTH; i++){
        this->chart_Parts->Series["parts"]->Points->AddXY(
            gcnew String(Chart_4_Data[i].part_name), Chart_4_Data[i].number);
    }

    //Chart-5 : ================================================
    my_title_Text=CHART_5_TITLE_FIRST;
    this->chart_ErrCode->Titles["Title1"]->Text=my_title_Text;
    //load data
    for(int i=0; i<DASHBOARD2_CHART5_SERIES_LENNGTH; i++){
        this->chart_ErrCode->Series["Errors"]->Points->AddXY(
            gcnew String(Chart_5_Data[i].Error_name), Chart_5_Data[i].times);
    }

    //Chart-6 : ================================================
    my_title_Text=CHART_6_TITLE_FIRST;
    this->chart_Model->Titles["Title1"]->Text=my_title_Text;
    //load data
    for(int i=0; i<DASHBOARD2_CHART6_SERIES_LENNGTH; i++){
        this->chart_Model->Series["CallByModel"]->Points->AddXY(
            gcnew String(Chart_6_Data[i].model_name), Chart_6_Data[i].calls);
    }
    //ToolTip & Label
    this->chart_Model->Series["CallByModel"]->Label="#PERCENT{P1}";
    this->chart_Model->Series["CallByModel"]->ToolTip=CHART_6_SERIES_TOOLTIP+"#VALX = #VALY";
}

//----------------//
//  Menu buttons  //
//----------------//
System::Void Dash2Form::button_DashBoard_Click(System::Object^  sender, System::EventArgs^  e)
{
    RDSadmin::DashBrdForm^ formDash1=gcnew DashBrdForm();
    formDash1->iNas.LoginUser_no=this->iNas.LoginUser_no;
    formDash1->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
    formDash1->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
    formDash1->iNas.Base_dir=this->iNas.Base_dir;
    formDash1->Show();
    this->Close();
}

System::Void Dash2Form::button_ServiceCall_Click(System::Object^  sender, System::EventArgs^  e)
{
    RDSadmin::RDSadminMainForm^ formRDSmain=gcnew RDSadminMainForm(0);
    formRDSmain->iNas.LoginUser_no=this->iNas.LoginUser_no;
    formRDSmain->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
    formRDSmain->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
    formRDSmain->iNas.Base_dir=this->iNas.Base_dir;
    formRDSmain->Show();
    this->Close();
}

System::Void Dash2Form::button_Supervisor_Click(System::Object^  sender, System::EventArgs^  e)
{
    RDSadmin::SupervisorForm^ formSuper=gcnew SupervisorForm();
    formSuper->iNas.LoginUser_no=this->iNas.LoginUser_no;
    formSuper->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
    formSuper->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
    formSuper->iNas.Base_dir=this->iNas.Base_dir;
    formSuper->Show();
    this->Close();
}

System::Void Dash2Form::button_RDSuser_Click(System::Object^  sender, System::EventArgs^  e)
{
    RDSadmin::UserList_Form^ formUser=gcnew UserList_Form();
    formUser->iNas.LoginUser_no=this->iNas.LoginUser_no;
    formUser->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
    formUser->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
    formUser->iNas.Base_dir=this->iNas.Base_dir;
    formUser->Show();
    this->Close();
}

System::Void Dash2Form::button_Dealer_Click(System::Object^  sender, System::EventArgs^  e)
{
    RDSadmin::DealerListForm^ formDealer=gcnew DealerListForm();
    formDealer->iNas.LoginUser_no=this->iNas.LoginUser_no;
    formDealer->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
    formDealer->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
    formDealer->iNas.Base_dir=this->iNas.Base_dir;
    formDealer->Show();
    this->Close();
}

//----------------//
//  Back buttons  //
//----------------//
System::Void Dash2Form::button_back_Click(System::Object^  sender, System::EventArgs^  e)
{
    RDSadmin::DashBrdForm^ formDash1=gcnew DashBrdForm();
    formDash1->iNas.LoginUser_no=this->iNas.LoginUser_no;
    formDash1->iNas.LoginUser_ID=this->iNas.LoginUser_ID;
    formDash1->iNas.LoginUser_AuthLevel=this->iNas.LoginUser_AuthLevel;
    formDash1->iNas.Base_dir=this->iNas.Base_dir;
    formDash1->Show();
    this->Close();
}