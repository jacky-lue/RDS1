#pragma once

//for internal objects
#include "nas_state.h"

namespace RDSadmin {
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    /// <summary>
    /// Summary for Dash2Form
    /// </summary>
    public ref class Dash2Form: public System::Windows::Forms::Form
    {
    public:
        Dash2Form(void)
        {
            InitializeComponent();
            //
            //TODO: Add the constructor code here
            //
        }

    public:

    public:
    public:
        //include objects here.....
        RDS_NAS::nas_state iNas;
    private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel_BG;
    public:
    private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel_Menu;
    private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel_MenuUp;
    private: System::Windows::Forms::Button^  button_DashBoard;
    private: System::Windows::Forms::Button^  button_ServiceCall;
    private: System::Windows::Forms::Button^  button_RDSuser;
    private: System::Windows::Forms::Button^  button_Supervisor;
    private: System::Windows::Forms::Button^  button_Dealer;
    private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel_MenuDown;
    private: System::Windows::Forms::Label^  label_LoginAuthorLv;
    private: System::Windows::Forms::Label^  label_LoginID;
    private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel_content;
    private: System::Windows::Forms::Panel^  panel_title;
    private: System::Windows::Forms::Button^  button_back;
    private: System::Windows::Forms::Label^  label_Title;
    private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel1;
    private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart_OSC_Dealer_T10;
    private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart_Efficiency;
    private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart_Channel;
    private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart_Parts;
    private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart_ErrCode;
    private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart_Model;
    private: System::Windows::Forms::Button^  button_LogOut;

    public:
        System::Drawing::Font^ titleFont;

    protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~Dash2Form()
        {
            if(components)
            {
                delete components;
            }
        }

    protected:

    private:
        /// <summary>
        /// Required designer variable.
        /// </summary>
        System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        void InitializeComponent(void)
        {
            System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1=(gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
            System::Windows::Forms::DataVisualization::Charting::Series^  series1=(gcnew System::Windows::Forms::DataVisualization::Charting::Series());
            System::Windows::Forms::DataVisualization::Charting::Title^  title1=(gcnew System::Windows::Forms::DataVisualization::Charting::Title());
            System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea2=(gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
            System::Windows::Forms::DataVisualization::Charting::Series^  series2=(gcnew System::Windows::Forms::DataVisualization::Charting::Series());
            System::Windows::Forms::DataVisualization::Charting::Title^  title2=(gcnew System::Windows::Forms::DataVisualization::Charting::Title());
            System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea3=(gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
            System::Windows::Forms::DataVisualization::Charting::Series^  series3=(gcnew System::Windows::Forms::DataVisualization::Charting::Series());
            System::Windows::Forms::DataVisualization::Charting::Title^  title3=(gcnew System::Windows::Forms::DataVisualization::Charting::Title());
            System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea4=(gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
            System::Windows::Forms::DataVisualization::Charting::Series^  series4=(gcnew System::Windows::Forms::DataVisualization::Charting::Series());
            System::Windows::Forms::DataVisualization::Charting::Title^  title4=(gcnew System::Windows::Forms::DataVisualization::Charting::Title());
            System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea5=(gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
            System::Windows::Forms::DataVisualization::Charting::Series^  series5=(gcnew System::Windows::Forms::DataVisualization::Charting::Series());
            System::Windows::Forms::DataVisualization::Charting::Title^  title5=(gcnew System::Windows::Forms::DataVisualization::Charting::Title());
            System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea6=(gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
            System::Windows::Forms::DataVisualization::Charting::Legend^  legend1=(gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
            System::Windows::Forms::DataVisualization::Charting::Series^  series6=(gcnew System::Windows::Forms::DataVisualization::Charting::Series());
            System::Windows::Forms::DataVisualization::Charting::Title^  title6=(gcnew System::Windows::Forms::DataVisualization::Charting::Title());
            System::ComponentModel::ComponentResourceManager^  resources=(gcnew System::ComponentModel::ComponentResourceManager(Dash2Form::typeid));
            this->tableLayoutPanel_BG=(gcnew System::Windows::Forms::TableLayoutPanel());
            this->tableLayoutPanel_Menu=(gcnew System::Windows::Forms::TableLayoutPanel());
            this->flowLayoutPanel_MenuUp=(gcnew System::Windows::Forms::FlowLayoutPanel());
            this->button_DashBoard=(gcnew System::Windows::Forms::Button());
            this->button_ServiceCall=(gcnew System::Windows::Forms::Button());
            this->button_RDSuser=(gcnew System::Windows::Forms::Button());
            this->button_Supervisor=(gcnew System::Windows::Forms::Button());
            this->button_Dealer=(gcnew System::Windows::Forms::Button());
            this->button_LogOut=(gcnew System::Windows::Forms::Button());
            this->flowLayoutPanel_MenuDown=(gcnew System::Windows::Forms::FlowLayoutPanel());
            this->label_LoginAuthorLv=(gcnew System::Windows::Forms::Label());
            this->label_LoginID=(gcnew System::Windows::Forms::Label());
            this->tableLayoutPanel_content=(gcnew System::Windows::Forms::TableLayoutPanel());
            this->panel_title=(gcnew System::Windows::Forms::Panel());
            this->button_back=(gcnew System::Windows::Forms::Button());
            this->label_Title=(gcnew System::Windows::Forms::Label());
            this->flowLayoutPanel1=(gcnew System::Windows::Forms::FlowLayoutPanel());
            this->chart_OSC_Dealer_T10=(gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
            this->chart_Efficiency=(gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
            this->chart_Channel=(gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
            this->chart_Parts=(gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
            this->chart_ErrCode=(gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
            this->chart_Model=(gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
            this->tableLayoutPanel_BG->SuspendLayout();
            this->tableLayoutPanel_Menu->SuspendLayout();
            this->flowLayoutPanel_MenuUp->SuspendLayout();
            this->flowLayoutPanel_MenuDown->SuspendLayout();
            this->tableLayoutPanel_content->SuspendLayout();
            this->panel_title->SuspendLayout();
            this->flowLayoutPanel1->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart_OSC_Dealer_T10))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart_Efficiency))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart_Channel))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart_Parts))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart_ErrCode))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart_Model))->BeginInit();
            this->SuspendLayout();
            //
            // tableLayoutPanel_BG
            //
            this->tableLayoutPanel_BG->AutoSizeMode=System::Windows::Forms::AutoSizeMode::GrowAndShrink;
            this->tableLayoutPanel_BG->ColumnCount=2;
            this->tableLayoutPanel_BG->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                150)));
            this->tableLayoutPanel_BG->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                100)));
            this->tableLayoutPanel_BG->Controls->Add(this->tableLayoutPanel_Menu, 0, 0);
            this->tableLayoutPanel_BG->Controls->Add(this->tableLayoutPanel_content, 1, 0);
            this->tableLayoutPanel_BG->Dock=System::Windows::Forms::DockStyle::Fill;
            this->tableLayoutPanel_BG->Location=System::Drawing::Point(0, 0);
            this->tableLayoutPanel_BG->Name=L"tableLayoutPanel_BG";
            this->tableLayoutPanel_BG->RowCount=1;
            this->tableLayoutPanel_BG->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
                100)));
            this->tableLayoutPanel_BG->Size=System::Drawing::Size(1229, 782);
            this->tableLayoutPanel_BG->TabIndex=19;
            //
            // tableLayoutPanel_Menu
            //
            this->tableLayoutPanel_Menu->ColumnCount=1;
            this->tableLayoutPanel_Menu->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                100)));
            this->tableLayoutPanel_Menu->Controls->Add(this->flowLayoutPanel_MenuUp, 0, 0);
            this->tableLayoutPanel_Menu->Controls->Add(this->flowLayoutPanel_MenuDown, 0, 1);
            this->tableLayoutPanel_Menu->Dock=System::Windows::Forms::DockStyle::Fill;
            this->tableLayoutPanel_Menu->Location=System::Drawing::Point(0, 0);
            this->tableLayoutPanel_Menu->Margin=System::Windows::Forms::Padding(0);
            this->tableLayoutPanel_Menu->Name=L"tableLayoutPanel_Menu";
            this->tableLayoutPanel_Menu->RowCount=2;
            this->tableLayoutPanel_Menu->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
                100)));
            this->tableLayoutPanel_Menu->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
                50)));
            this->tableLayoutPanel_Menu->Size=System::Drawing::Size(150, 782);
            this->tableLayoutPanel_Menu->TabIndex=0;
            //
            // flowLayoutPanel_MenuUp
            //
            this->flowLayoutPanel_MenuUp->BackColor=System::Drawing::Color::MidnightBlue;
            this->flowLayoutPanel_MenuUp->Controls->Add(this->button_DashBoard);
            this->flowLayoutPanel_MenuUp->Controls->Add(this->button_ServiceCall);
            this->flowLayoutPanel_MenuUp->Controls->Add(this->button_RDSuser);
            this->flowLayoutPanel_MenuUp->Controls->Add(this->button_Supervisor);
            this->flowLayoutPanel_MenuUp->Controls->Add(this->button_Dealer);
            this->flowLayoutPanel_MenuUp->Controls->Add(this->button_LogOut);
            this->flowLayoutPanel_MenuUp->Dock=System::Windows::Forms::DockStyle::Fill;
            this->flowLayoutPanel_MenuUp->FlowDirection=System::Windows::Forms::FlowDirection::TopDown;
            this->flowLayoutPanel_MenuUp->Location=System::Drawing::Point(1, 1);
            this->flowLayoutPanel_MenuUp->Margin=System::Windows::Forms::Padding(1, 1, 1, 0);
            this->flowLayoutPanel_MenuUp->Name=L"flowLayoutPanel_MenuUp";
            this->flowLayoutPanel_MenuUp->Size=System::Drawing::Size(148, 731);
            this->flowLayoutPanel_MenuUp->TabIndex=0;
            //
            // button_DashBoard
            //
            this->button_DashBoard->Font=(gcnew System::Drawing::Font(L"PMingLiU", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->button_DashBoard->Location=System::Drawing::Point(12, 12);
            this->button_DashBoard->Margin=System::Windows::Forms::Padding(12, 12, 12, 0);
            this->button_DashBoard->Name=L"button_DashBoard";
            this->button_DashBoard->Size=System::Drawing::Size(125, 50);
            this->button_DashBoard->TabIndex=31;
            this->button_DashBoard->Text=L"Statistics Dashboard";
            this->button_DashBoard->UseVisualStyleBackColor=true;
            this->button_DashBoard->Click+=gcnew System::EventHandler(this, &Dash2Form::button_DashBoard_Click);
            //
            // button_ServiceCall
            //
            this->button_ServiceCall->Font=(gcnew System::Drawing::Font(L"PMingLiU", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->button_ServiceCall->Location=System::Drawing::Point(12, 74);
            this->button_ServiceCall->Margin=System::Windows::Forms::Padding(12, 12, 12, 0);
            this->button_ServiceCall->Name=L"button_ServiceCall";
            this->button_ServiceCall->Size=System::Drawing::Size(125, 50);
            this->button_ServiceCall->TabIndex=28;
            this->button_ServiceCall->Text=L"Open \r\nService Calls";
            this->button_ServiceCall->UseVisualStyleBackColor=true;
            this->button_ServiceCall->Click+=gcnew System::EventHandler(this, &Dash2Form::button_ServiceCall_Click);
            //
            // button_RDSuser
            //
            this->button_RDSuser->Font=(gcnew System::Drawing::Font(L"PMingLiU", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->button_RDSuser->Location=System::Drawing::Point(12, 136);
            this->button_RDSuser->Margin=System::Windows::Forms::Padding(12, 12, 12, 0);
            this->button_RDSuser->Name=L"button_RDSuser";
            this->button_RDSuser->Size=System::Drawing::Size(125, 50);
            this->button_RDSuser->TabIndex=29;
            this->button_RDSuser->Text=L"RDS User List";
            this->button_RDSuser->UseVisualStyleBackColor=true;
            this->button_RDSuser->Click+=gcnew System::EventHandler(this, &Dash2Form::button_RDSuser_Click);
            //
            // button_Supervisor
            //
            this->button_Supervisor->Font=(gcnew System::Drawing::Font(L"PMingLiU", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->button_Supervisor->Location=System::Drawing::Point(12, 198);
            this->button_Supervisor->Margin=System::Windows::Forms::Padding(12, 12, 12, 0);
            this->button_Supervisor->Name=L"button_Supervisor";
            this->button_Supervisor->Size=System::Drawing::Size(125, 50);
            this->button_Supervisor->TabIndex=30;
            this->button_Supervisor->Text=L"Supervisor Account";
            this->button_Supervisor->UseVisualStyleBackColor=true;
            this->button_Supervisor->Click+=gcnew System::EventHandler(this, &Dash2Form::button_Supervisor_Click);
            //
            // button_Dealer
            //
            this->button_Dealer->Font=(gcnew System::Drawing::Font(L"PMingLiU", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->button_Dealer->Location=System::Drawing::Point(12, 260);
            this->button_Dealer->Margin=System::Windows::Forms::Padding(12, 12, 12, 0);
            this->button_Dealer->Name=L"button_Dealer";
            this->button_Dealer->Size=System::Drawing::Size(125, 50);
            this->button_Dealer->TabIndex=32;
            this->button_Dealer->Text=L"Dealer List";
            this->button_Dealer->UseVisualStyleBackColor=true;
            this->button_Dealer->Click+=gcnew System::EventHandler(this, &Dash2Form::button_Dealer_Click);
            //
            // button_LogOut
            //
            this->button_LogOut->Font=(gcnew System::Drawing::Font(L"PMingLiU", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->button_LogOut->Location=System::Drawing::Point(12, 322);
            this->button_LogOut->Margin=System::Windows::Forms::Padding(12, 12, 12, 0);
            this->button_LogOut->Name=L"button_LogOut";
            this->button_LogOut->Size=System::Drawing::Size(125, 50);
            this->button_LogOut->TabIndex=34;
            this->button_LogOut->Text=L"Log Out";
            this->button_LogOut->UseVisualStyleBackColor=true;
            this->button_LogOut->Click+=gcnew System::EventHandler(this, &Dash2Form::button_LogOut_Click);
            //
            // flowLayoutPanel_MenuDown
            //
            this->flowLayoutPanel_MenuDown->BackColor=System::Drawing::Color::MidnightBlue;
            this->flowLayoutPanel_MenuDown->Controls->Add(this->label_LoginAuthorLv);
            this->flowLayoutPanel_MenuDown->Controls->Add(this->label_LoginID);
            this->flowLayoutPanel_MenuDown->Dock=System::Windows::Forms::DockStyle::Fill;
            this->flowLayoutPanel_MenuDown->FlowDirection=System::Windows::Forms::FlowDirection::BottomUp;
            this->flowLayoutPanel_MenuDown->Location=System::Drawing::Point(1, 732);
            this->flowLayoutPanel_MenuDown->Margin=System::Windows::Forms::Padding(1, 0, 1, 1);
            this->flowLayoutPanel_MenuDown->Name=L"flowLayoutPanel_MenuDown";
            this->flowLayoutPanel_MenuDown->Size=System::Drawing::Size(148, 49);
            this->flowLayoutPanel_MenuDown->TabIndex=1;
            //
            // label_LoginAuthorLv
            //
            this->label_LoginAuthorLv->AutoSize=true;
            this->label_LoginAuthorLv->ForeColor=System::Drawing::Color::White;
            this->label_LoginAuthorLv->Location=System::Drawing::Point(10, 27);
            this->label_LoginAuthorLv->Margin=System::Windows::Forms::Padding(10, 0, 10, 10);
            this->label_LoginAuthorLv->Name=L"label_LoginAuthorLv";
            this->label_LoginAuthorLv->Size=System::Drawing::Size(97, 12);
            this->label_LoginAuthorLv->TabIndex=18;
            this->label_LoginAuthorLv->Text=L"Login Authority Lv";
            //
            // label_LoginID
            //
            this->label_LoginID->AutoSize=true;
            this->label_LoginID->ForeColor=System::Drawing::Color::White;
            this->label_LoginID->Location=System::Drawing::Point(10, 10);
            this->label_LoginID->Margin=System::Windows::Forms::Padding(10, 0, 10, 5);
            this->label_LoginID->Name=L"label_LoginID";
            this->label_LoginID->Size=System::Drawing::Size(48, 12);
            this->label_LoginID->TabIndex=17;
            this->label_LoginID->Text=L"Login ID";
            //
            // tableLayoutPanel_content
            //
            this->tableLayoutPanel_content->ColumnCount=1;
            this->tableLayoutPanel_content->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                100)));
            this->tableLayoutPanel_content->Controls->Add(this->panel_title, 0, 0);
            this->tableLayoutPanel_content->Controls->Add(this->flowLayoutPanel1, 0, 1);
            this->tableLayoutPanel_content->Dock=System::Windows::Forms::DockStyle::Fill;
            this->tableLayoutPanel_content->Location=System::Drawing::Point(150, 0);
            this->tableLayoutPanel_content->Margin=System::Windows::Forms::Padding(0);
            this->tableLayoutPanel_content->Name=L"tableLayoutPanel_content";
            this->tableLayoutPanel_content->RowCount=2;
            this->tableLayoutPanel_content->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
                60)));
            this->tableLayoutPanel_content->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
                100)));
            this->tableLayoutPanel_content->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
                20)));
            this->tableLayoutPanel_content->Size=System::Drawing::Size(1079, 782);
            this->tableLayoutPanel_content->TabIndex=1;
            //
            // panel_title
            //
            this->panel_title->BackColor=System::Drawing::Color::SteelBlue;
            this->panel_title->Controls->Add(this->button_back);
            this->panel_title->Controls->Add(this->label_Title);
            this->panel_title->Dock=System::Windows::Forms::DockStyle::Fill;
            this->panel_title->Location=System::Drawing::Point(1, 0);
            this->panel_title->Margin=System::Windows::Forms::Padding(1, 0, 0, 0);
            this->panel_title->Name=L"panel_title";
            this->panel_title->Size=System::Drawing::Size(1078, 60);
            this->panel_title->TabIndex=19;
            //
            // button_back
            //
            this->button_back->Font=(gcnew System::Drawing::Font(L"PMingLiU", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->button_back->Location=System::Drawing::Point(17, 12);
            this->button_back->Name=L"button_back";
            this->button_back->Size=System::Drawing::Size(66, 37);
            this->button_back->TabIndex=1;
            this->button_back->Text=L"Back";
            this->button_back->UseVisualStyleBackColor=true;
            this->button_back->Click+=gcnew System::EventHandler(this, &Dash2Form::button_back_Click);
            //
            // label_Title
            //
            this->label_Title->AutoSize=true;
            this->label_Title->Font=(gcnew System::Drawing::Font(L"PMingLiU", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->label_Title->ForeColor=System::Drawing::Color::White;
            this->label_Title->Location=System::Drawing::Point(353, 11);
            this->label_Title->Name=L"label_Title";
            this->label_Title->Size=System::Drawing::Size(305, 29);
            this->label_Title->TabIndex=0;
            this->label_Title->Text=L"Statistics Dashboard - 2";
            //
            // flowLayoutPanel1
            //
            this->flowLayoutPanel1->Controls->Add(this->chart_OSC_Dealer_T10);
            this->flowLayoutPanel1->Controls->Add(this->chart_Efficiency);
            this->flowLayoutPanel1->Controls->Add(this->chart_Channel);
            this->flowLayoutPanel1->Controls->Add(this->chart_Parts);
            this->flowLayoutPanel1->Controls->Add(this->chart_ErrCode);
            this->flowLayoutPanel1->Controls->Add(this->chart_Model);
            this->flowLayoutPanel1->Dock=System::Windows::Forms::DockStyle::Fill;
            this->flowLayoutPanel1->Location=System::Drawing::Point(1, 60);
            this->flowLayoutPanel1->Margin=System::Windows::Forms::Padding(1, 0, 0, 0);
            this->flowLayoutPanel1->Name=L"flowLayoutPanel1";
            this->flowLayoutPanel1->Size=System::Drawing::Size(1078, 722);
            this->flowLayoutPanel1->TabIndex=20;
            //
            // chart_OSC_Dealer_T10
            //
            this->chart_OSC_Dealer_T10->BackColor=System::Drawing::SystemColors::Control;
            this->chart_OSC_Dealer_T10->BorderlineColor=System::Drawing::Color::Black;
            this->chart_OSC_Dealer_T10->BorderlineDashStyle=System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Solid;
            this->chart_OSC_Dealer_T10->BorderSkin->BackGradientStyle=System::Windows::Forms::DataVisualization::Charting::GradientStyle::LeftRight;
            chartArea1->AxisX->Interval=1;
            chartArea1->AxisX->IsLabelAutoFit=false;
            chartArea1->AxisX->MajorGrid->Enabled=false;
            chartArea1->BackColor=System::Drawing::SystemColors::Control;
            chartArea1->Name=L"ChartArea1";
            this->chart_OSC_Dealer_T10->ChartAreas->Add(chartArea1);
            this->chart_OSC_Dealer_T10->Location=System::Drawing::Point(1, 1);
            this->chart_OSC_Dealer_T10->Margin=System::Windows::Forms::Padding(1);
            this->chart_OSC_Dealer_T10->Name=L"chart_OSC_Dealer_T10";
            series1->BorderColor=System::Drawing::Color::DodgerBlue;
            series1->ChartArea=L"ChartArea1";
            series1->Color=System::Drawing::Color::SkyBlue;
            series1->IsValueShownAsLabel=true;
            series1->Name=L"OpenServiceCall";
            this->chart_OSC_Dealer_T10->Series->Add(series1);
            this->chart_OSC_Dealer_T10->Size=System::Drawing::Size(542, 240);
            this->chart_OSC_Dealer_T10->TabIndex=23;
            this->chart_OSC_Dealer_T10->Text=L"chart1";
            title1->Font=(gcnew System::Drawing::Font(L"Droid Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            title1->Name=L"Title1";
            title1->Text=L"test title";
            this->chart_OSC_Dealer_T10->Titles->Add(title1);
            //
            // chart_Efficiency
            //
            this->chart_Efficiency->BackColor=System::Drawing::SystemColors::Control;
            this->chart_Efficiency->BorderlineColor=System::Drawing::Color::Black;
            this->chart_Efficiency->BorderlineDashStyle=System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Solid;
            chartArea2->AlignmentOrientation=static_cast<System::Windows::Forms::DataVisualization::Charting::AreaAlignmentOrientations>((System::Windows::Forms::DataVisualization::Charting::AreaAlignmentOrientations::Vertical|System::Windows::Forms::DataVisualization::Charting::AreaAlignmentOrientations::Horizontal));
            chartArea2->AxisX->Interval=1;
            chartArea2->AxisX->IsLabelAutoFit=false;
            chartArea2->AxisX->LabelStyle->Angle=-60;
            chartArea2->AxisX->MajorGrid->Enabled=false;
            chartArea2->BackColor=System::Drawing::SystemColors::Control;
            chartArea2->Name=L"ChartArea1";
            this->chart_Efficiency->ChartAreas->Add(chartArea2);
            this->chart_Efficiency->Location=System::Drawing::Point(545, 1);
            this->chart_Efficiency->Margin=System::Windows::Forms::Padding(1);
            this->chart_Efficiency->Name=L"chart_Efficiency";
            series2->BorderColor=System::Drawing::Color::DodgerBlue;
            series2->BorderWidth=3;
            series2->ChartArea=L"ChartArea1";
            series2->ChartType=System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
            series2->Color=System::Drawing::Color::LightSkyBlue;
            series2->IsValueShownAsLabel=true;
            series2->LabelFormat=L"{0:0.00}";
            series2->MarkerBorderColor=System::Drawing::Color::BlueViolet;
            series2->MarkerColor=System::Drawing::Color::Blue;
            series2->MarkerSize=10;
            series2->MarkerStyle=System::Windows::Forms::DataVisualization::Charting::MarkerStyle::Diamond;
            series2->Name=L"DealerEfficiency";
            series2->ToolTip=L"Average Ticket closed Days";
            this->chart_Efficiency->Series->Add(series2);
            this->chart_Efficiency->Size=System::Drawing::Size(532, 240);
            this->chart_Efficiency->TabIndex=24;
            this->chart_Efficiency->Text=L"chart1";
            title2->Font=(gcnew System::Drawing::Font(L"Droid Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            title2->Name=L"Title1";
            title2->Text=L"test title";
            this->chart_Efficiency->Titles->Add(title2);
            //
            // chart_Channel
            //
            this->chart_Channel->BackColor=System::Drawing::SystemColors::Control;
            this->chart_Channel->BorderlineColor=System::Drawing::Color::Black;
            this->chart_Channel->BorderlineDashStyle=System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Solid;
            chartArea3->Area3DStyle->Inclination=20;
            chartArea3->Area3DStyle->IsClustered=true;
            chartArea3->Area3DStyle->WallWidth=3;
            chartArea3->AxisX->Interval=1;
            chartArea3->AxisX->IsLabelAutoFit=false;
            chartArea3->AxisX->LabelStyle->Angle=-25;
            chartArea3->AxisX->MajorGrid->Enabled=false;
            chartArea3->BackColor=System::Drawing::SystemColors::Control;
            chartArea3->Name=L"ChartArea1";
            this->chart_Channel->ChartAreas->Add(chartArea3);
            this->chart_Channel->Location=System::Drawing::Point(1, 243);
            this->chart_Channel->Margin=System::Windows::Forms::Padding(1);
            this->chart_Channel->Name=L"chart_Channel";
            this->chart_Channel->Palette=System::Windows::Forms::DataVisualization::Charting::ChartColorPalette::None;
            this->chart_Channel->PaletteCustomColors=gcnew cli::array< System::Drawing::Color >(7)
            {
                System::Drawing::Color::MediumPurple,
                    System::Drawing::Color::OliveDrab, System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)),
                        static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0))), System::Drawing::Color::LightSkyBlue,
                    System::Drawing::Color::Orchid, System::Drawing::Color::Brown, System::Drawing::Color::SandyBrown
            };
            series3->BorderColor=System::Drawing::Color::Black;
            series3->ChartArea=L"ChartArea1";
            series3->ChartType=System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Pie;
            series3->Color=System::Drawing::Color::Chartreuse;
            series3->CustomProperties=L"PieDrawingStyle=SoftEdge, PieLabelStyle=Outside, PieStartAngle=10";
            series3->IsValueShownAsLabel=true;
            series3->MarkerBorderColor=System::Drawing::Color::BlueViolet;
            series3->MarkerColor=System::Drawing::Color::Blue;
            series3->MarkerSize=10;
            series3->MarkerStyle=System::Windows::Forms::DataVisualization::Charting::MarkerStyle::Diamond;
            series3->Name=L"CallByChannel";
            this->chart_Channel->Series->Add(series3);
            this->chart_Channel->Size=System::Drawing::Size(421, 240);
            this->chart_Channel->TabIndex=25;
            this->chart_Channel->Text=L"chart1";
            title3->Font=(gcnew System::Drawing::Font(L"Droid Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            title3->Name=L"Title1";
            title3->Text=L"test title";
            this->chart_Channel->Titles->Add(title3);
            //
            // chart_Parts
            //
            this->chart_Parts->BackColor=System::Drawing::SystemColors::Control;
            this->chart_Parts->BorderlineColor=System::Drawing::Color::Black;
            this->chart_Parts->BorderlineDashStyle=System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Solid;
            this->chart_Parts->BorderSkin->BackGradientStyle=System::Windows::Forms::DataVisualization::Charting::GradientStyle::LeftRight;
            chartArea4->AxisX->Interval=1;
            chartArea4->AxisX->IsLabelAutoFit=false;
            chartArea4->AxisX->LabelStyle->Angle=-45;
            chartArea4->AxisX->MajorGrid->Enabled=false;
            chartArea4->BackColor=System::Drawing::SystemColors::Control;
            chartArea4->Name=L"ChartArea1";
            this->chart_Parts->ChartAreas->Add(chartArea4);
            this->chart_Parts->Location=System::Drawing::Point(424, 243);
            this->chart_Parts->Margin=System::Windows::Forms::Padding(1);
            this->chart_Parts->Name=L"chart_Parts";
            series4->BackGradientStyle=System::Windows::Forms::DataVisualization::Charting::GradientStyle::DiagonalLeft;
            series4->BorderColor=System::Drawing::Color::Gray;
            series4->ChartArea=L"ChartArea1";
            series4->Color=System::Drawing::Color::Chartreuse;
            series4->IsValueShownAsLabel=true;
            series4->LabelAngle=-25;
            series4->Name=L"parts";
            series4->ShadowColor=System::Drawing::Color::Green;
            series4->ShadowOffset=5;
            this->chart_Parts->Series->Add(series4);
            this->chart_Parts->Size=System::Drawing::Size(652, 240);
            this->chart_Parts->TabIndex=26;
            this->chart_Parts->Text=L"chart1";
            title4->Font=(gcnew System::Drawing::Font(L"Droid Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            title4->Name=L"Title1";
            title4->Text=L"test title";
            this->chart_Parts->Titles->Add(title4);
            //
            // chart_ErrCode
            //
            this->chart_ErrCode->BackColor=System::Drawing::SystemColors::Control;
            this->chart_ErrCode->BorderlineColor=System::Drawing::Color::Black;
            this->chart_ErrCode->BorderlineDashStyle=System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Solid;
            this->chart_ErrCode->BorderSkin->BackGradientStyle=System::Windows::Forms::DataVisualization::Charting::GradientStyle::LeftRight;
            chartArea5->AlignmentOrientation=static_cast<System::Windows::Forms::DataVisualization::Charting::AreaAlignmentOrientations>((System::Windows::Forms::DataVisualization::Charting::AreaAlignmentOrientations::Vertical|System::Windows::Forms::DataVisualization::Charting::AreaAlignmentOrientations::Horizontal));
            chartArea5->Area3DStyle->Enable3D=true;
            chartArea5->Area3DStyle->Inclination=18;
            chartArea5->Area3DStyle->IsRightAngleAxes=false;
            chartArea5->Area3DStyle->Perspective=5;
            chartArea5->AxisX->Interval=1;
            chartArea5->AxisX->IsLabelAutoFit=false;
            chartArea5->AxisX->LabelStyle->Angle=-30;
            chartArea5->AxisX->MajorGrid->Enabled=false;
            chartArea5->BackColor=System::Drawing::SystemColors::Control;
            chartArea5->BackGradientStyle=System::Windows::Forms::DataVisualization::Charting::GradientStyle::LeftRight;
            chartArea5->Name=L"ChartArea1";
            chartArea5->Position->Auto=false;
            chartArea5->Position->Height=82.32126F;
            chartArea5->Position->Width=100;
            chartArea5->Position->Y=14.67874F;
            chartArea5->ShadowColor=System::Drawing::Color::Silver;
            this->chart_ErrCode->ChartAreas->Add(chartArea5);
            this->chart_ErrCode->Location=System::Drawing::Point(1, 485);
            this->chart_ErrCode->Margin=System::Windows::Forms::Padding(1);
            this->chart_ErrCode->Name=L"chart_ErrCode";
            series5->BorderColor=System::Drawing::Color::Black;
            series5->ChartArea=L"ChartArea1";
            series5->Color=System::Drawing::Color::DarkOrange;
            series5->CustomProperties=L"DrawingStyle=Cylinder";
            series5->IsValueShownAsLabel=true;
            series5->LabelAngle=-25;
            series5->Name=L"Errors";
            series5->ShadowColor=System::Drawing::Color::Green;
            series5->ShadowOffset=5;
            this->chart_ErrCode->Series->Add(series5);
            this->chart_ErrCode->Size=System::Drawing::Size(632, 240);
            this->chart_ErrCode->TabIndex=27;
            this->chart_ErrCode->Text=L"chart1";
            title5->Font=(gcnew System::Drawing::Font(L"Droid Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            title5->Name=L"Title1";
            title5->Text=L"test title";
            this->chart_ErrCode->Titles->Add(title5);
            //
            // chart_Model
            //
            this->chart_Model->BackColor=System::Drawing::SystemColors::Control;
            this->chart_Model->BorderlineColor=System::Drawing::Color::Black;
            this->chart_Model->BorderlineDashStyle=System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Solid;
            chartArea6->Area3DStyle->Enable3D=true;
            chartArea6->Area3DStyle->Inclination=20;
            chartArea6->Area3DStyle->IsClustered=true;
            chartArea6->Area3DStyle->WallWidth=3;
            chartArea6->AxisX->Interval=1;
            chartArea6->AxisX->IsLabelAutoFit=false;
            chartArea6->AxisX->LabelStyle->Angle=-25;
            chartArea6->AxisX->MajorGrid->Enabled=false;
            chartArea6->BackColor=System::Drawing::SystemColors::Control;
            chartArea6->Name=L"ChartArea1";
            this->chart_Model->ChartAreas->Add(chartArea6);
            legend1->Alignment=System::Drawing::StringAlignment::Center;
            legend1->Name=L"Legend1";
            this->chart_Model->Legends->Add(legend1);
            this->chart_Model->Location=System::Drawing::Point(635, 485);
            this->chart_Model->Margin=System::Windows::Forms::Padding(1);
            this->chart_Model->Name=L"chart_Model";
            this->chart_Model->Palette=System::Windows::Forms::DataVisualization::Charting::ChartColorPalette::None;
            this->chart_Model->PaletteCustomColors=gcnew cli::array< System::Drawing::Color >(9)
            {
                System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
                    static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255))), System::Drawing::Color::Lime,
                    System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
                        static_cast<System::Int32>(static_cast<System::Byte>(0))), System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
                            static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(128))), System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)),
                                static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192))), System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
                                    static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255))), System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                                        static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192))), System::Drawing::Color::Green,
                    System::Drawing::Color::Aqua
            };
            series6->BackGradientStyle=System::Windows::Forms::DataVisualization::Charting::GradientStyle::LeftRight;
            series6->BackSecondaryColor=System::Drawing::Color::White;
            series6->BorderColor=System::Drawing::Color::Black;
            series6->ChartArea=L"ChartArea1";
            series6->ChartType=System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Pie;
            series6->Color=System::Drawing::Color::Chartreuse;
            series6->CustomProperties=L"PieLabelStyle=Outside";
            series6->IsValueShownAsLabel=true;
            series6->Legend=L"Legend1";
            series6->LegendText=L"#VALX";
            series6->MarkerBorderColor=System::Drawing::Color::BlueViolet;
            series6->MarkerColor=System::Drawing::Color::Blue;
            series6->MarkerSize=10;
            series6->MarkerStyle=System::Windows::Forms::DataVisualization::Charting::MarkerStyle::Diamond;
            series6->Name=L"CallByModel";
            this->chart_Model->Series->Add(series6);
            this->chart_Model->Size=System::Drawing::Size(441, 240);
            this->chart_Model->TabIndex=28;
            this->chart_Model->Text=L"chart1";
            title6->Font=(gcnew System::Drawing::Font(L"Droid Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            title6->Name=L"Title1";
            title6->Text=L"test title";
            this->chart_Model->Titles->Add(title6);
            //
            // Dash2Form
            //
            this->AutoScaleDimensions=System::Drawing::SizeF(6, 12);
            this->AutoScaleMode=System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor=System::Drawing::Color::White;
            this->ClientSize=System::Drawing::Size(1229, 782);
            this->ControlBox=false;
            this->Controls->Add(this->tableLayoutPanel_BG);
            this->Icon=(cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
            this->MaximizeBox=false;
            this->MinimizeBox=false;
            this->Name=L"Dash2Form";
            this->StartPosition=System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text=L"Statistics Dash Board 2";
            this->Load+=gcnew System::EventHandler(this, &Dash2Form::Dash2Form_Load);
            this->tableLayoutPanel_BG->ResumeLayout(false);
            this->tableLayoutPanel_Menu->ResumeLayout(false);
            this->flowLayoutPanel_MenuUp->ResumeLayout(false);
            this->flowLayoutPanel_MenuDown->ResumeLayout(false);
            this->flowLayoutPanel_MenuDown->PerformLayout();
            this->tableLayoutPanel_content->ResumeLayout(false);
            this->panel_title->ResumeLayout(false);
            this->panel_title->PerformLayout();
            this->flowLayoutPanel1->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart_OSC_Dealer_T10))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart_Efficiency))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart_Channel))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart_Parts))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart_ErrCode))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart_Model))->EndInit();
            this->ResumeLayout(false);
        }
#pragma endregion
        //
    private:  System::Void LoadChart();
              //
    private: System::Void button_DashBoard_Click(System::Object^  sender, System::EventArgs^  e);
    private: System::Void button_ServiceCall_Click(System::Object^  sender, System::EventArgs^  e);
    private: System::Void button_RDSuser_Click(System::Object^  sender, System::EventArgs^  e);
    private: System::Void button_Supervisor_Click(System::Object^  sender, System::EventArgs^  e);
    private: System::Void button_Dealer_Click(System::Object^  sender, System::EventArgs^  e);
             //
    private: System::Void button_back_Click(System::Object^  sender, System::EventArgs^  e);
             //
    private: System::Void Dash2Form_Load(System::Object^  sender, System::EventArgs^  e);
    private: System::Void button_LogOut_Click(System::Object^  sender, System::EventArgs^  e)
    {
        int rtn=this->iNas.Unlock_Person_Login(this->iNas.LoginUser_no);
        if(rtn<0){
            MessageBox::Show(LOGIN_ERR_FILE_LOSS_BEF_UNLOCK, "ERROR",
                MessageBoxButtons::OK, MessageBoxIcon::Information);
        }
        this->Close(); //close login form and exit application
        Application::Exit(); //!!!!!!!!!!!!!!!!!!!
    }
    };
}
