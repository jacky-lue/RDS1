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
    /// Summary for AddUserForm
    /// </summary>
    public ref class AddUserForm: public System::Windows::Forms::Form
    {
    public:
        AddUserForm()
        {
            InitializeComponent();
            //
            //TODO: Add the constructor code here
            //
        }

    public:
        String^ user_ID;
        String^ user_Name;
        String^ user_PW;
        String^ user_AuthLevel;
        //include objects here.....
        RDS_NAS::nas_state iNas;

    private: System::Windows::Forms::Panel^  panel1;

    private: System::Windows::Forms::Label^  label_ComName_show;
    private: System::Windows::Forms::Label^  label_CompanyName;
    private: System::Windows::Forms::ComboBox^  comboBox_ALevel;
    private: System::Windows::Forms::Label^  label_ComCode_Show;
    private: System::Windows::Forms::Label^  label_AuthorLevel;
    private: System::Windows::Forms::Label^  label_CompanyCode;
    private: System::Windows::Forms::TextBox^  textBox_PW;
    private: System::Windows::Forms::TextBox^  textBox_ID;
    private: System::Windows::Forms::TextBox^  textBox_Name;
    private: System::Windows::Forms::Label^  label_PW;
    private: System::Windows::Forms::Label^  label_ID;
    private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel_BG;
    private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel_menu;

    private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel_MenuUp;
    private: System::Windows::Forms::Button^  button_DashBoard;
    private: System::Windows::Forms::Button^  button_ServiceCall;
    private: System::Windows::Forms::Button^  button_RDSuser;
    private: System::Windows::Forms::Button^  button_Supervisor;
    private: System::Windows::Forms::Button^  button_Dealer;
    private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel_MenuDown;
    private: System::Windows::Forms::Label^  label_LoginAuthorLv;
    private: System::Windows::Forms::Label^  label_LoginID;
    private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel_Content;
    private: System::Windows::Forms::Button^  button_LogOut;

    private: System::Windows::Forms::Label^  label_Name;

    protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~AddUserForm()
        {
            if(components)
            {
                delete components;
            }
        }

    protected:
    private: System::Windows::Forms::Panel^  panel_Control;
    private: System::Windows::Forms::Button^  button_Save;
    private: System::Windows::Forms::Panel^  panel_title;
    private: System::Windows::Forms::Label^  label_Title;

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
            System::ComponentModel::ComponentResourceManager^  resources=(gcnew System::ComponentModel::ComponentResourceManager(AddUserForm::typeid));
            this->panel_Control=(gcnew System::Windows::Forms::Panel());
            this->button_Save=(gcnew System::Windows::Forms::Button());
            this->panel_title=(gcnew System::Windows::Forms::Panel());
            this->label_Title=(gcnew System::Windows::Forms::Label());
            this->panel1=(gcnew System::Windows::Forms::Panel());
            this->label_ComName_show=(gcnew System::Windows::Forms::Label());
            this->label_CompanyName=(gcnew System::Windows::Forms::Label());
            this->comboBox_ALevel=(gcnew System::Windows::Forms::ComboBox());
            this->label_ComCode_Show=(gcnew System::Windows::Forms::Label());
            this->label_AuthorLevel=(gcnew System::Windows::Forms::Label());
            this->label_CompanyCode=(gcnew System::Windows::Forms::Label());
            this->textBox_PW=(gcnew System::Windows::Forms::TextBox());
            this->textBox_ID=(gcnew System::Windows::Forms::TextBox());
            this->textBox_Name=(gcnew System::Windows::Forms::TextBox());
            this->label_PW=(gcnew System::Windows::Forms::Label());
            this->label_ID=(gcnew System::Windows::Forms::Label());
            this->label_Name=(gcnew System::Windows::Forms::Label());
            this->tableLayoutPanel_BG=(gcnew System::Windows::Forms::TableLayoutPanel());
            this->tableLayoutPanel_menu=(gcnew System::Windows::Forms::TableLayoutPanel());
            this->flowLayoutPanel_MenuDown=(gcnew System::Windows::Forms::FlowLayoutPanel());
            this->label_LoginAuthorLv=(gcnew System::Windows::Forms::Label());
            this->label_LoginID=(gcnew System::Windows::Forms::Label());
            this->flowLayoutPanel_MenuUp=(gcnew System::Windows::Forms::FlowLayoutPanel());
            this->button_DashBoard=(gcnew System::Windows::Forms::Button());
            this->button_ServiceCall=(gcnew System::Windows::Forms::Button());
            this->button_RDSuser=(gcnew System::Windows::Forms::Button());
            this->button_Supervisor=(gcnew System::Windows::Forms::Button());
            this->button_Dealer=(gcnew System::Windows::Forms::Button());
            this->button_LogOut=(gcnew System::Windows::Forms::Button());
            this->tableLayoutPanel_Content=(gcnew System::Windows::Forms::TableLayoutPanel());
            this->panel_Control->SuspendLayout();
            this->panel_title->SuspendLayout();
            this->panel1->SuspendLayout();
            this->tableLayoutPanel_BG->SuspendLayout();
            this->tableLayoutPanel_menu->SuspendLayout();
            this->flowLayoutPanel_MenuDown->SuspendLayout();
            this->flowLayoutPanel_MenuUp->SuspendLayout();
            this->tableLayoutPanel_Content->SuspendLayout();
            this->SuspendLayout();
            //
            // panel_Control
            //
            this->panel_Control->BackColor=System::Drawing::Color::SteelBlue;
            this->panel_Control->Controls->Add(this->button_Save);
            this->panel_Control->Dock=System::Windows::Forms::DockStyle::Fill;
            this->panel_Control->Location=System::Drawing::Point(0, 522);
            this->panel_Control->Margin=System::Windows::Forms::Padding(0);
            this->panel_Control->Name=L"panel_Control";
            this->panel_Control->Size=System::Drawing::Size(474, 60);
            this->panel_Control->TabIndex=11;
            //
            // button_Save
            //
            this->button_Save->Font=(gcnew System::Drawing::Font(L"PMingLiU", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->button_Save->Location=System::Drawing::Point(360, 11);
            this->button_Save->Name=L"button_Save";
            this->button_Save->Size=System::Drawing::Size(89, 34);
            this->button_Save->TabIndex=4;
            this->button_Save->Text=L"Save";
            this->button_Save->UseVisualStyleBackColor=true;
            this->button_Save->Click+=gcnew System::EventHandler(this, &AddUserForm::button_Save_Click);
            //
            // panel_title
            //
            this->panel_title->BackColor=System::Drawing::Color::SteelBlue;
            this->panel_title->Controls->Add(this->label_Title);
            this->panel_title->Dock=System::Windows::Forms::DockStyle::Fill;
            this->panel_title->Location=System::Drawing::Point(0, 0);
            this->panel_title->Margin=System::Windows::Forms::Padding(0);
            this->panel_title->Name=L"panel_title";
            this->panel_title->Size=System::Drawing::Size(474, 50);
            this->panel_title->TabIndex=10;
            //
            // label_Title
            //
            this->label_Title->AutoSize=true;
            this->label_Title->Font=(gcnew System::Drawing::Font(L"PMingLiU", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->label_Title->ForeColor=System::Drawing::Color::White;
            this->label_Title->Location=System::Drawing::Point(110, 9);
            this->label_Title->Name=L"label_Title";
            this->label_Title->Size=System::Drawing::Size(239, 29);
            this->label_Title->TabIndex=0;
            this->label_Title->Text=L"Add User Account";
            //
            // panel1
            //
            this->panel1->BackColor=System::Drawing::Color::Black;
            this->panel1->Controls->Add(this->label_ComName_show);
            this->panel1->Controls->Add(this->label_CompanyName);
            this->panel1->Controls->Add(this->comboBox_ALevel);
            this->panel1->Controls->Add(this->label_ComCode_Show);
            this->panel1->Controls->Add(this->label_AuthorLevel);
            this->panel1->Controls->Add(this->label_CompanyCode);
            this->panel1->Controls->Add(this->textBox_PW);
            this->panel1->Controls->Add(this->textBox_ID);
            this->panel1->Controls->Add(this->textBox_Name);
            this->panel1->Controls->Add(this->label_PW);
            this->panel1->Controls->Add(this->label_ID);
            this->panel1->Controls->Add(this->label_Name);
            this->panel1->Dock=System::Windows::Forms::DockStyle::Fill;
            this->panel1->Location=System::Drawing::Point(0, 51);
            this->panel1->Margin=System::Windows::Forms::Padding(0, 1, 0, 1);
            this->panel1->Name=L"panel1";
            this->panel1->Size=System::Drawing::Size(474, 470);
            this->panel1->TabIndex=17;
            //
            // label_ComName_show
            //
            this->label_ComName_show->AutoSize=true;
            this->label_ComName_show->Font=(gcnew System::Drawing::Font(L"PMingLiU", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->label_ComName_show->ForeColor=System::Drawing::Color::White;
            this->label_ComName_show->Location=System::Drawing::Point(253, 88);
            this->label_ComName_show->Name=L"label_ComName_show";
            this->label_ComName_show->Size=System::Drawing::Size(178, 24);
            this->label_ComName_show->TabIndex=27;
            this->label_ComName_show->Text=L"0000_0000_0000";
            //
            // label_CompanyName
            //
            this->label_CompanyName->AutoSize=true;
            this->label_CompanyName->Font=(gcnew System::Drawing::Font(L"PMingLiU", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->label_CompanyName->ForeColor=System::Drawing::Color::White;
            this->label_CompanyName->Location=System::Drawing::Point(61, 88);
            this->label_CompanyName->Name=L"label_CompanyName";
            this->label_CompanyName->Size=System::Drawing::Size(183, 24);
            this->label_CompanyName->TabIndex=13;
            this->label_CompanyName->Text=L"Company Name :";
            //
            // comboBox_ALevel
            //
            this->comboBox_ALevel->Font=(gcnew System::Drawing::Font(L"PMingLiU", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->comboBox_ALevel->FormattingEnabled=true;
            this->comboBox_ALevel->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Manager", L"C.R.", L"Engineer" });
            this->comboBox_ALevel->Location=System::Drawing::Point(257, 141);
            this->comboBox_ALevel->Name=L"comboBox_ALevel";
            this->comboBox_ALevel->Size=System::Drawing::Size(158, 24);
            this->comboBox_ALevel->TabIndex=12;
            //
            // label_ComCode_Show
            //
            this->label_ComCode_Show->AutoSize=true;
            this->label_ComCode_Show->Font=(gcnew System::Drawing::Font(L"PMingLiU", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->label_ComCode_Show->ForeColor=System::Drawing::Color::White;
            this->label_ComCode_Show->Location=System::Drawing::Point(253, 41);
            this->label_ComCode_Show->Name=L"label_ComCode_Show";
            this->label_ComCode_Show->Size=System::Drawing::Size(58, 24);
            this->label_ComCode_Show->TabIndex=11;
            this->label_ComCode_Show->Text=L"0000";
            //
            // label_AuthorLevel
            //
            this->label_AuthorLevel->AutoSize=true;
            this->label_AuthorLevel->Font=(gcnew System::Drawing::Font(L"PMingLiU", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->label_AuthorLevel->ForeColor=System::Drawing::Color::White;
            this->label_AuthorLevel->Location=System::Drawing::Point(58, 142);
            this->label_AuthorLevel->Name=L"label_AuthorLevel";
            this->label_AuthorLevel->Size=System::Drawing::Size(182, 24);
            this->label_AuthorLevel->TabIndex=10;
            this->label_AuthorLevel->Text=L"Authority Level :";
            //
            // label_CompanyCode
            //
            this->label_CompanyCode->AutoSize=true;
            this->label_CompanyCode->Font=(gcnew System::Drawing::Font(L"PMingLiU", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->label_CompanyCode->ForeColor=System::Drawing::Color::White;
            this->label_CompanyCode->Location=System::Drawing::Point(61, 41);
            this->label_CompanyCode->Name=L"label_CompanyCode";
            this->label_CompanyCode->Size=System::Drawing::Size(176, 24);
            this->label_CompanyCode->TabIndex=7;
            this->label_CompanyCode->Text=L"Company Code :";
            //
            // textBox_PW
            //
            this->textBox_PW->Font=(gcnew System::Drawing::Font(L"PMingLiU", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->textBox_PW->Location=System::Drawing::Point(212, 307);
            this->textBox_PW->Name=L"textBox_PW";
            this->textBox_PW->Size=System::Drawing::Size(203, 27);
            this->textBox_PW->TabIndex=6;
            this->textBox_PW->TextAlign=System::Windows::Forms::HorizontalAlignment::Center;
            //
            // textBox_ID
            //
            this->textBox_ID->Font=(gcnew System::Drawing::Font(L"PMingLiU", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->textBox_ID->Location=System::Drawing::Point(212, 250);
            this->textBox_ID->Name=L"textBox_ID";
            this->textBox_ID->Size=System::Drawing::Size(203, 27);
            this->textBox_ID->TabIndex=5;
            this->textBox_ID->TextAlign=System::Windows::Forms::HorizontalAlignment::Center;
            //
            // textBox_Name
            //
            this->textBox_Name->Font=(gcnew System::Drawing::Font(L"PMingLiU", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->textBox_Name->Location=System::Drawing::Point(212, 194);
            this->textBox_Name->Name=L"textBox_Name";
            this->textBox_Name->Size=System::Drawing::Size(203, 27);
            this->textBox_Name->TabIndex=4;
            this->textBox_Name->TextAlign=System::Windows::Forms::HorizontalAlignment::Center;
            //
            // label_PW
            //
            this->label_PW->AutoSize=true;
            this->label_PW->Font=(gcnew System::Drawing::Font(L"PMingLiU", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->label_PW->ForeColor=System::Drawing::Color::White;
            this->label_PW->Location=System::Drawing::Point(58, 310);
            this->label_PW->Name=L"label_PW";
            this->label_PW->Size=System::Drawing::Size(119, 24);
            this->label_PW->TabIndex=2;
            this->label_PW->Text=L"Password :";
            //
            // label_ID
            //
            this->label_ID->AutoSize=true;
            this->label_ID->Font=(gcnew System::Drawing::Font(L"PMingLiU", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->label_ID->ForeColor=System::Drawing::Color::White;
            this->label_ID->Location=System::Drawing::Point(53, 253);
            this->label_ID->Name=L"label_ID";
            this->label_ID->Size=System::Drawing::Size(139, 24);
            this->label_ID->TabIndex=1;
            this->label_ID->Text=L"Account ID :";
            //
            // label_Name
            //
            this->label_Name->AutoSize=true;
            this->label_Name->Font=(gcnew System::Drawing::Font(L"PMingLiU", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->label_Name->ForeColor=System::Drawing::Color::White;
            this->label_Name->Location=System::Drawing::Point(70, 197);
            this->label_Name->Name=L"label_Name";
            this->label_Name->Size=System::Drawing::Size(82, 24);
            this->label_Name->TabIndex=0;
            this->label_Name->Text=L"Name :";
            //
            // tableLayoutPanel_BG
            //
            this->tableLayoutPanel_BG->ColumnCount=2;
            this->tableLayoutPanel_BG->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                150)));
            this->tableLayoutPanel_BG->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                100)));
            this->tableLayoutPanel_BG->Controls->Add(this->tableLayoutPanel_menu, 0, 0);
            this->tableLayoutPanel_BG->Controls->Add(this->tableLayoutPanel_Content, 1, 0);
            this->tableLayoutPanel_BG->Dock=System::Windows::Forms::DockStyle::Fill;
            this->tableLayoutPanel_BG->Location=System::Drawing::Point(0, 0);
            this->tableLayoutPanel_BG->Name=L"tableLayoutPanel_BG";
            this->tableLayoutPanel_BG->RowCount=1;
            this->tableLayoutPanel_BG->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
                100)));
            this->tableLayoutPanel_BG->Size=System::Drawing::Size(624, 582);
            this->tableLayoutPanel_BG->TabIndex=18;
            //
            // tableLayoutPanel_menu
            //
            this->tableLayoutPanel_menu->ColumnCount=1;
            this->tableLayoutPanel_menu->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                100)));
            this->tableLayoutPanel_menu->Controls->Add(this->flowLayoutPanel_MenuDown, 0, 1);
            this->tableLayoutPanel_menu->Controls->Add(this->flowLayoutPanel_MenuUp, 0, 0);
            this->tableLayoutPanel_menu->Dock=System::Windows::Forms::DockStyle::Fill;
            this->tableLayoutPanel_menu->Location=System::Drawing::Point(0, 0);
            this->tableLayoutPanel_menu->Margin=System::Windows::Forms::Padding(0);
            this->tableLayoutPanel_menu->Name=L"tableLayoutPanel_menu";
            this->tableLayoutPanel_menu->RowCount=2;
            this->tableLayoutPanel_menu->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
                100)));
            this->tableLayoutPanel_menu->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
                60)));
            this->tableLayoutPanel_menu->Size=System::Drawing::Size(150, 582);
            this->tableLayoutPanel_menu->TabIndex=0;
            //
            // flowLayoutPanel_MenuDown
            //
            this->flowLayoutPanel_MenuDown->BackColor=System::Drawing::Color::MidnightBlue;
            this->flowLayoutPanel_MenuDown->Controls->Add(this->label_LoginAuthorLv);
            this->flowLayoutPanel_MenuDown->Controls->Add(this->label_LoginID);
            this->flowLayoutPanel_MenuDown->Dock=System::Windows::Forms::DockStyle::Fill;
            this->flowLayoutPanel_MenuDown->FlowDirection=System::Windows::Forms::FlowDirection::BottomUp;
            this->flowLayoutPanel_MenuDown->Location=System::Drawing::Point(1, 522);
            this->flowLayoutPanel_MenuDown->Margin=System::Windows::Forms::Padding(1, 0, 1, 1);
            this->flowLayoutPanel_MenuDown->Name=L"flowLayoutPanel_MenuDown";
            this->flowLayoutPanel_MenuDown->Size=System::Drawing::Size(148, 59);
            this->flowLayoutPanel_MenuDown->TabIndex=2;
            //
            // label_LoginAuthorLv
            //
            this->label_LoginAuthorLv->AutoSize=true;
            this->label_LoginAuthorLv->ForeColor=System::Drawing::Color::White;
            this->label_LoginAuthorLv->Location=System::Drawing::Point(10, 37);
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
            this->label_LoginID->Location=System::Drawing::Point(10, 20);
            this->label_LoginID->Margin=System::Windows::Forms::Padding(10, 0, 10, 5);
            this->label_LoginID->Name=L"label_LoginID";
            this->label_LoginID->Size=System::Drawing::Size(48, 12);
            this->label_LoginID->TabIndex=17;
            this->label_LoginID->Text=L"Login ID";
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
            this->flowLayoutPanel_MenuUp->Size=System::Drawing::Size(148, 521);
            this->flowLayoutPanel_MenuUp->TabIndex=1;
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
            this->button_DashBoard->Visible=false;
            this->button_DashBoard->Click+=gcnew System::EventHandler(this, &AddUserForm::button_DashBoard_Click);
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
            this->button_ServiceCall->Click+=gcnew System::EventHandler(this, &AddUserForm::button_ServiceCall_Click);
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
            this->button_RDSuser->Click+=gcnew System::EventHandler(this, &AddUserForm::button_RDSuser_Click);
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
            this->button_Supervisor->Click+=gcnew System::EventHandler(this, &AddUserForm::button_Supervisor_Click);
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
            this->button_Dealer->Click+=gcnew System::EventHandler(this, &AddUserForm::button_Dealer_Click);
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
            this->button_LogOut->Click+=gcnew System::EventHandler(this, &AddUserForm::button_LogOut_Click);
            //
            // tableLayoutPanel_Content
            //
            this->tableLayoutPanel_Content->ColumnCount=1;
            this->tableLayoutPanel_Content->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                100)));
            this->tableLayoutPanel_Content->Controls->Add(this->panel_title, 0, 0);
            this->tableLayoutPanel_Content->Controls->Add(this->panel1, 0, 1);
            this->tableLayoutPanel_Content->Controls->Add(this->panel_Control, 0, 2);
            this->tableLayoutPanel_Content->Dock=System::Windows::Forms::DockStyle::Fill;
            this->tableLayoutPanel_Content->Location=System::Drawing::Point(150, 0);
            this->tableLayoutPanel_Content->Margin=System::Windows::Forms::Padding(0);
            this->tableLayoutPanel_Content->Name=L"tableLayoutPanel_Content";
            this->tableLayoutPanel_Content->RowCount=3;
            this->tableLayoutPanel_Content->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
                50)));
            this->tableLayoutPanel_Content->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
                100)));
            this->tableLayoutPanel_Content->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
                60)));
            this->tableLayoutPanel_Content->Size=System::Drawing::Size(474, 582);
            this->tableLayoutPanel_Content->TabIndex=1;
            //
            // AddUserForm
            //
            this->AutoScaleDimensions=System::Drawing::SizeF(6, 12);
            this->AutoScaleMode=System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor=System::Drawing::Color::LightSteelBlue;
            this->ClientSize=System::Drawing::Size(624, 582);
            this->ControlBox=false;
            this->Controls->Add(this->tableLayoutPanel_BG);
            this->Icon=(cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
            this->MaximizeBox=false;
            this->MinimizeBox=false;
            this->Name=L"AddUserForm";
            this->StartPosition=System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text=L"RDSadmin: Add User";
            this->Load+=gcnew System::EventHandler(this, &AddUserForm::AddUserForm_Load);
            this->panel_Control->ResumeLayout(false);
            this->panel_title->ResumeLayout(false);
            this->panel_title->PerformLayout();
            this->panel1->ResumeLayout(false);
            this->panel1->PerformLayout();
            this->tableLayoutPanel_BG->ResumeLayout(false);
            this->tableLayoutPanel_menu->ResumeLayout(false);
            this->flowLayoutPanel_MenuDown->ResumeLayout(false);
            this->flowLayoutPanel_MenuDown->PerformLayout();
            this->flowLayoutPanel_MenuUp->ResumeLayout(false);
            this->tableLayoutPanel_Content->ResumeLayout(false);
            this->ResumeLayout(false);
        }
#pragma endregion
    private: System::Void button_ServiceCall_Click(System::Object^  sender, System::EventArgs^  e);
    private: System::Void button_Supervisor_Click(System::Object^  sender, System::EventArgs^  e);
    private: System::Void button_Dealer_Click(System::Object^  sender, System::EventArgs^  e);
    private: System::Void button_DashBoard_Click(System::Object^  sender, System::EventArgs^  e);
    private: System::Void button_RDSuser_Click(System::Object^  sender, System::EventArgs^  e);
             //
    private: System::Void button_Save_Click(System::Object^  sender, System::EventArgs^  e);
             //
    private: System::Void AddUserForm_Load(System::Object^  sender, System::EventArgs^  e);
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
