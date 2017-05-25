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
    /// Summary for SupervisorForm
    /// </summary>
    public ref class SupervisorForm: public System::Windows::Forms::Form
    {
    public:
        SupervisorForm()
        {
            InitializeComponent();
            //
            //TODO: Add the constructor code here
            //
        }
    private: System::Windows::Forms::ComboBox^  comboBox_SQ;
    public:

    public:
    private: System::Windows::Forms::Label^  label_SecurityQ;
    private: System::Windows::Forms::TextBox^  textBox_answer;
    private: System::Windows::Forms::Label^  label_answer;

    private: System::Windows::Forms::Label^  label_AuthorLevel;
    private: System::Windows::Forms::Label^  label_CompanyCode;
    private: System::Windows::Forms::Label^  label_AuthLvCode;

    private: System::Windows::Forms::Label^  label_CompanyName;
    private: System::Windows::Forms::TextBox^  textBox_CompanyName;
    private: System::Windows::Forms::TextBox^  textBox_CompanyCode;
    private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel_BG;
    private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel_Content;

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
    private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel_ctrl;
    private: System::Windows::Forms::Button^  button_Save;
    private: System::Windows::Forms::Button^  button_Edit;
    private: System::Windows::Forms::Button^  button_LogOut;
    public:
        //include objects here.....
        RDS_NAS::nas_state iNas;

    protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~SupervisorForm()
        {
            if(components)
            {
                delete components;
            }
        }

    protected:

    private: System::Windows::Forms::Panel^  panel_title;
    private: System::Windows::Forms::Label^  label_Title;

    private: System::Windows::Forms::Panel^  panel1;
    private: System::Windows::Forms::Label^  label_ID;
    private: System::Windows::Forms::Label^  label_Name;

    private: System::Windows::Forms::TextBox^  textBox_PW2;
    private: System::Windows::Forms::TextBox^  textBox_PW;
    private: System::Windows::Forms::TextBox^  textBox_ID;
    private: System::Windows::Forms::TextBox^  textBox_Name;
    private: System::Windows::Forms::Label^  label_PW2;
    private: System::Windows::Forms::Label^  label_PW;

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
            System::ComponentModel::ComponentResourceManager^  resources=(gcnew System::ComponentModel::ComponentResourceManager(SupervisorForm::typeid));
            this->panel_title=(gcnew System::Windows::Forms::Panel());
            this->label_Title=(gcnew System::Windows::Forms::Label());
            this->panel1=(gcnew System::Windows::Forms::Panel());
            this->textBox_CompanyName=(gcnew System::Windows::Forms::TextBox());
            this->textBox_CompanyCode=(gcnew System::Windows::Forms::TextBox());
            this->label_CompanyName=(gcnew System::Windows::Forms::Label());
            this->label_AuthLvCode=(gcnew System::Windows::Forms::Label());
            this->label_AuthorLevel=(gcnew System::Windows::Forms::Label());
            this->label_CompanyCode=(gcnew System::Windows::Forms::Label());
            this->textBox_answer=(gcnew System::Windows::Forms::TextBox());
            this->label_answer=(gcnew System::Windows::Forms::Label());
            this->comboBox_SQ=(gcnew System::Windows::Forms::ComboBox());
            this->label_SecurityQ=(gcnew System::Windows::Forms::Label());
            this->textBox_PW2=(gcnew System::Windows::Forms::TextBox());
            this->textBox_PW=(gcnew System::Windows::Forms::TextBox());
            this->textBox_ID=(gcnew System::Windows::Forms::TextBox());
            this->textBox_Name=(gcnew System::Windows::Forms::TextBox());
            this->label_PW2=(gcnew System::Windows::Forms::Label());
            this->label_PW=(gcnew System::Windows::Forms::Label());
            this->label_ID=(gcnew System::Windows::Forms::Label());
            this->label_Name=(gcnew System::Windows::Forms::Label());
            this->tableLayoutPanel_BG=(gcnew System::Windows::Forms::TableLayoutPanel());
            this->tableLayoutPanel_Content=(gcnew System::Windows::Forms::TableLayoutPanel());
            this->flowLayoutPanel_ctrl=(gcnew System::Windows::Forms::FlowLayoutPanel());
            this->button_Save=(gcnew System::Windows::Forms::Button());
            this->button_Edit=(gcnew System::Windows::Forms::Button());
            this->tableLayoutPanel_Menu=(gcnew System::Windows::Forms::TableLayoutPanel());
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
            this->panel_title->SuspendLayout();
            this->panel1->SuspendLayout();
            this->tableLayoutPanel_BG->SuspendLayout();
            this->tableLayoutPanel_Content->SuspendLayout();
            this->flowLayoutPanel_ctrl->SuspendLayout();
            this->tableLayoutPanel_Menu->SuspendLayout();
            this->flowLayoutPanel_MenuDown->SuspendLayout();
            this->flowLayoutPanel_MenuUp->SuspendLayout();
            this->SuspendLayout();
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
            this->panel_title->TabIndex=6;
            //
            // label_Title
            //
            this->label_Title->AutoSize=true;
            this->label_Title->Font=(gcnew System::Drawing::Font(L"PMingLiU", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->label_Title->ForeColor=System::Drawing::Color::White;
            this->label_Title->Location=System::Drawing::Point(73, 7);
            this->label_Title->Name=L"label_Title";
            this->label_Title->Size=System::Drawing::Size(313, 29);
            this->label_Title->TabIndex=0;
            this->label_Title->Text=L"MIS Supervisor Account";
            //
            // panel1
            //
            this->panel1->BackColor=System::Drawing::Color::Black;
            this->panel1->Controls->Add(this->textBox_CompanyName);
            this->panel1->Controls->Add(this->textBox_CompanyCode);
            this->panel1->Controls->Add(this->label_CompanyName);
            this->panel1->Controls->Add(this->label_AuthLvCode);
            this->panel1->Controls->Add(this->label_AuthorLevel);
            this->panel1->Controls->Add(this->label_CompanyCode);
            this->panel1->Controls->Add(this->textBox_answer);
            this->panel1->Controls->Add(this->label_answer);
            this->panel1->Controls->Add(this->comboBox_SQ);
            this->panel1->Controls->Add(this->label_SecurityQ);
            this->panel1->Controls->Add(this->textBox_PW2);
            this->panel1->Controls->Add(this->textBox_PW);
            this->panel1->Controls->Add(this->textBox_ID);
            this->panel1->Controls->Add(this->textBox_Name);
            this->panel1->Controls->Add(this->label_PW2);
            this->panel1->Controls->Add(this->label_PW);
            this->panel1->Controls->Add(this->label_ID);
            this->panel1->Controls->Add(this->label_Name);
            this->panel1->Dock=System::Windows::Forms::DockStyle::Fill;
            this->panel1->Location=System::Drawing::Point(0, 50);
            this->panel1->Margin=System::Windows::Forms::Padding(0);
            this->panel1->Name=L"panel1";
            this->panel1->Size=System::Drawing::Size(474, 472);
            this->panel1->TabIndex=8;
            //
            // textBox_CompanyName
            //
            this->textBox_CompanyName->Font=(gcnew System::Drawing::Font(L"PMingLiU", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->textBox_CompanyName->Location=System::Drawing::Point(222, 63);
            this->textBox_CompanyName->Name=L"textBox_CompanyName";
            this->textBox_CompanyName->Size=System::Drawing::Size(218, 27);
            this->textBox_CompanyName->TabIndex=23;
            this->textBox_CompanyName->TextAlign=System::Windows::Forms::HorizontalAlignment::Center;
            //
            // textBox_CompanyCode
            //
            this->textBox_CompanyCode->Font=(gcnew System::Drawing::Font(L"PMingLiU", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->textBox_CompanyCode->Location=System::Drawing::Point(222, 19);
            this->textBox_CompanyCode->Name=L"textBox_CompanyCode";
            this->textBox_CompanyCode->Size=System::Drawing::Size(218, 27);
            this->textBox_CompanyCode->TabIndex=22;
            this->textBox_CompanyCode->TextAlign=System::Windows::Forms::HorizontalAlignment::Center;
            //
            // label_CompanyName
            //
            this->label_CompanyName->AutoSize=true;
            this->label_CompanyName->Font=(gcnew System::Drawing::Font(L"PMingLiU", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->label_CompanyName->ForeColor=System::Drawing::Color::White;
            this->label_CompanyName->Location=System::Drawing::Point(30, 64);
            this->label_CompanyName->Name=L"label_CompanyName";
            this->label_CompanyName->Size=System::Drawing::Size(183, 24);
            this->label_CompanyName->TabIndex=21;
            this->label_CompanyName->Text=L"Company Name :";
            //
            // label_AuthLvCode
            //
            this->label_AuthLvCode->AutoSize=true;
            this->label_AuthLvCode->Font=(gcnew System::Drawing::Font(L"PMingLiU", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->label_AuthLvCode->ForeColor=System::Drawing::Color::White;
            this->label_AuthLvCode->Location=System::Drawing::Point(252, 173);
            this->label_AuthLvCode->Name=L"label_AuthLvCode";
            this->label_AuthLvCode->Size=System::Drawing::Size(178, 24);
            this->label_AuthLvCode->TabIndex=15;
            this->label_AuthLvCode->Text=L"0000_0000_0000";
            //
            // label_AuthorLevel
            //
            this->label_AuthorLevel->AutoSize=true;
            this->label_AuthorLevel->Font=(gcnew System::Drawing::Font(L"PMingLiU", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->label_AuthorLevel->ForeColor=System::Drawing::Color::White;
            this->label_AuthorLevel->Location=System::Drawing::Point(34, 173);
            this->label_AuthorLevel->Name=L"label_AuthorLevel";
            this->label_AuthorLevel->Size=System::Drawing::Size(182, 24);
            this->label_AuthorLevel->TabIndex=13;
            this->label_AuthorLevel->Text=L"Authority Level :";
            //
            // label_CompanyCode
            //
            this->label_CompanyCode->AutoSize=true;
            this->label_CompanyCode->Font=(gcnew System::Drawing::Font(L"PMingLiU", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->label_CompanyCode->ForeColor=System::Drawing::Color::White;
            this->label_CompanyCode->Location=System::Drawing::Point(37, 20);
            this->label_CompanyCode->Name=L"label_CompanyCode";
            this->label_CompanyCode->Size=System::Drawing::Size(176, 24);
            this->label_CompanyCode->TabIndex=12;
            this->label_CompanyCode->Text=L"Company Code :";
            //
            // textBox_answer
            //
            this->textBox_answer->Font=(gcnew System::Drawing::Font(L"PMingLiU", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->textBox_answer->Location=System::Drawing::Point(132, 418);
            this->textBox_answer->Name=L"textBox_answer";
            this->textBox_answer->Size=System::Drawing::Size(308, 27);
            this->textBox_answer->TabIndex=11;
            this->textBox_answer->TextAlign=System::Windows::Forms::HorizontalAlignment::Center;
            //
            // label_answer
            //
            this->label_answer->AutoSize=true;
            this->label_answer->Font=(gcnew System::Drawing::Font(L"PMingLiU", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->label_answer->ForeColor=System::Drawing::Color::White;
            this->label_answer->Location=System::Drawing::Point(25, 418);
            this->label_answer->Name=L"label_answer";
            this->label_answer->Size=System::Drawing::Size(100, 24);
            this->label_answer->TabIndex=10;
            this->label_answer->Text=L"Answer :";
            //
            // comboBox_SQ
            //
            this->comboBox_SQ->Font=(gcnew System::Drawing::Font(L"PMingLiU", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->comboBox_SQ->FormattingEnabled=true;
            this->comboBox_SQ->Items->AddRange(gcnew cli::array< System::Object^  >(4)
            {
                L"What was your favorite place to visit as a child\?",
                    L"In what city were you born\?", L"What is your father¡¦s middle name\?", L"What is your favorite actor, musician, or artist\?"
            });
            this->comboBox_SQ->Location=System::Drawing::Point(29, 377);
            this->comboBox_SQ->Name=L"comboBox_SQ";
            this->comboBox_SQ->Size=System::Drawing::Size(411, 24);
            this->comboBox_SQ->TabIndex=9;
            //
            // label_SecurityQ
            //
            this->label_SecurityQ->AutoSize=true;
            this->label_SecurityQ->Font=(gcnew System::Drawing::Font(L"PMingLiU", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->label_SecurityQ->ForeColor=System::Drawing::Color::White;
            this->label_SecurityQ->Location=System::Drawing::Point(25, 343);
            this->label_SecurityQ->Name=L"label_SecurityQ";
            this->label_SecurityQ->Size=System::Drawing::Size(188, 24);
            this->label_SecurityQ->TabIndex=8;
            this->label_SecurityQ->Text=L"Security Question";
            //
            // textBox_PW2
            //
            this->textBox_PW2->Font=(gcnew System::Drawing::Font(L"PMingLiU", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->textBox_PW2->Location=System::Drawing::Point(222, 306);
            this->textBox_PW2->Name=L"textBox_PW2";
            this->textBox_PW2->PasswordChar='*';
            this->textBox_PW2->Size=System::Drawing::Size(218, 27);
            this->textBox_PW2->TabIndex=7;
            this->textBox_PW2->TextAlign=System::Windows::Forms::HorizontalAlignment::Center;
            //
            // textBox_PW
            //
            this->textBox_PW->Font=(gcnew System::Drawing::Font(L"PMingLiU", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->textBox_PW->Location=System::Drawing::Point(222, 260);
            this->textBox_PW->Name=L"textBox_PW";
            this->textBox_PW->PasswordChar='*';
            this->textBox_PW->Size=System::Drawing::Size(218, 27);
            this->textBox_PW->TabIndex=6;
            this->textBox_PW->TextAlign=System::Windows::Forms::HorizontalAlignment::Center;
            //
            // textBox_ID
            //
            this->textBox_ID->Font=(gcnew System::Drawing::Font(L"PMingLiU", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->textBox_ID->Location=System::Drawing::Point(222, 214);
            this->textBox_ID->Name=L"textBox_ID";
            this->textBox_ID->Size=System::Drawing::Size(218, 27);
            this->textBox_ID->TabIndex=5;
            this->textBox_ID->TextAlign=System::Windows::Forms::HorizontalAlignment::Center;
            //
            // textBox_Name
            //
            this->textBox_Name->Font=(gcnew System::Drawing::Font(L"PMingLiU", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->textBox_Name->Location=System::Drawing::Point(222, 128);
            this->textBox_Name->Name=L"textBox_Name";
            this->textBox_Name->Size=System::Drawing::Size(218, 27);
            this->textBox_Name->TabIndex=4;
            this->textBox_Name->TextAlign=System::Windows::Forms::HorizontalAlignment::Center;
            //
            // label_PW2
            //
            this->label_PW2->AutoSize=true;
            this->label_PW2->Font=(gcnew System::Drawing::Font(L"PMingLiU", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->label_PW2->ForeColor=System::Drawing::Color::White;
            this->label_PW2->Location=System::Drawing::Point(35, 307);
            this->label_PW2->Name=L"label_PW2";
            this->label_PW2->Size=System::Drawing::Size(153, 24);
            this->label_PW2->TabIndex=3;
            this->label_PW2->Text=L"Re-enter PW :";
            //
            // label_PW
            //
            this->label_PW->AutoSize=true;
            this->label_PW->Font=(gcnew System::Drawing::Font(L"PMingLiU", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->label_PW->ForeColor=System::Drawing::Color::White;
            this->label_PW->Location=System::Drawing::Point(47, 261);
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
            this->label_ID->Location=System::Drawing::Point(37, 215);
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
            this->label_Name->Location=System::Drawing::Point(25, 129);
            this->label_Name->Name=L"label_Name";
            this->label_Name->Size=System::Drawing::Size(197, 24);
            this->label_Name->TabIndex=0;
            this->label_Name->Text=L"Supervisor Name :";
            //
            // tableLayoutPanel_BG
            //
            this->tableLayoutPanel_BG->ColumnCount=2;
            this->tableLayoutPanel_BG->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                150)));
            this->tableLayoutPanel_BG->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                100)));
            this->tableLayoutPanel_BG->Controls->Add(this->tableLayoutPanel_Content, 1, 0);
            this->tableLayoutPanel_BG->Controls->Add(this->tableLayoutPanel_Menu, 0, 0);
            this->tableLayoutPanel_BG->Dock=System::Windows::Forms::DockStyle::Fill;
            this->tableLayoutPanel_BG->Location=System::Drawing::Point(0, 0);
            this->tableLayoutPanel_BG->Name=L"tableLayoutPanel_BG";
            this->tableLayoutPanel_BG->RowCount=1;
            this->tableLayoutPanel_BG->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
                100)));
            this->tableLayoutPanel_BG->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
                20)));
            this->tableLayoutPanel_BG->Size=System::Drawing::Size(624, 582);
            this->tableLayoutPanel_BG->TabIndex=9;
            //
            // tableLayoutPanel_Content
            //
            this->tableLayoutPanel_Content->ColumnCount=1;
            this->tableLayoutPanel_Content->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                100)));
            this->tableLayoutPanel_Content->Controls->Add(this->flowLayoutPanel_ctrl, 0, 2);
            this->tableLayoutPanel_Content->Controls->Add(this->panel1, 0, 1);
            this->tableLayoutPanel_Content->Controls->Add(this->panel_title, 0, 0);
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
            // flowLayoutPanel_ctrl
            //
            this->flowLayoutPanel_ctrl->BackColor=System::Drawing::Color::SteelBlue;
            this->flowLayoutPanel_ctrl->Controls->Add(this->button_Save);
            this->flowLayoutPanel_ctrl->Controls->Add(this->button_Edit);
            this->flowLayoutPanel_ctrl->Dock=System::Windows::Forms::DockStyle::Fill;
            this->flowLayoutPanel_ctrl->FlowDirection=System::Windows::Forms::FlowDirection::RightToLeft;
            this->flowLayoutPanel_ctrl->Location=System::Drawing::Point(0, 522);
            this->flowLayoutPanel_ctrl->Margin=System::Windows::Forms::Padding(0);
            this->flowLayoutPanel_ctrl->Name=L"flowLayoutPanel_ctrl";
            this->flowLayoutPanel_ctrl->Size=System::Drawing::Size(474, 60);
            this->flowLayoutPanel_ctrl->TabIndex=16;
            //
            // button_Save
            //
            this->button_Save->Enabled=false;
            this->button_Save->Font=(gcnew System::Drawing::Font(L"PMingLiU", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->button_Save->Location=System::Drawing::Point(373, 12);
            this->button_Save->Margin=System::Windows::Forms::Padding(0, 12, 12, 12);
            this->button_Save->Name=L"button_Save";
            this->button_Save->Size=System::Drawing::Size(89, 34);
            this->button_Save->TabIndex=4;
            this->button_Save->Text=L"Save";
            this->button_Save->UseVisualStyleBackColor=true;
            this->button_Save->Click+=gcnew System::EventHandler(this, &SupervisorForm::button_Save_Click);
            //
            // button_Edit
            //
            this->button_Edit->Font=(gcnew System::Drawing::Font(L"PMingLiU", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->button_Edit->Location=System::Drawing::Point(272, 12);
            this->button_Edit->Margin=System::Windows::Forms::Padding(0, 12, 12, 12);
            this->button_Edit->Name=L"button_Edit";
            this->button_Edit->Size=System::Drawing::Size(89, 34);
            this->button_Edit->TabIndex=3;
            this->button_Edit->Text=L"Edit";
            this->button_Edit->UseVisualStyleBackColor=true;
            this->button_Edit->Click+=gcnew System::EventHandler(this, &SupervisorForm::button_Edit_Click);
            //
            // tableLayoutPanel_Menu
            //
            this->tableLayoutPanel_Menu->ColumnCount=1;
            this->tableLayoutPanel_Menu->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                100)));
            this->tableLayoutPanel_Menu->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                20)));
            this->tableLayoutPanel_Menu->Controls->Add(this->flowLayoutPanel_MenuDown, 0, 1);
            this->tableLayoutPanel_Menu->Controls->Add(this->flowLayoutPanel_MenuUp, 0, 0);
            this->tableLayoutPanel_Menu->Dock=System::Windows::Forms::DockStyle::Fill;
            this->tableLayoutPanel_Menu->Location=System::Drawing::Point(0, 0);
            this->tableLayoutPanel_Menu->Margin=System::Windows::Forms::Padding(0);
            this->tableLayoutPanel_Menu->Name=L"tableLayoutPanel_Menu";
            this->tableLayoutPanel_Menu->RowCount=2;
            this->tableLayoutPanel_Menu->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
                100)));
            this->tableLayoutPanel_Menu->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
                50)));
            this->tableLayoutPanel_Menu->Size=System::Drawing::Size(150, 582);
            this->tableLayoutPanel_Menu->TabIndex=0;
            //
            // flowLayoutPanel_MenuDown
            //
            this->flowLayoutPanel_MenuDown->BackColor=System::Drawing::Color::MidnightBlue;
            this->flowLayoutPanel_MenuDown->Controls->Add(this->label_LoginAuthorLv);
            this->flowLayoutPanel_MenuDown->Controls->Add(this->label_LoginID);
            this->flowLayoutPanel_MenuDown->Dock=System::Windows::Forms::DockStyle::Fill;
            this->flowLayoutPanel_MenuDown->FlowDirection=System::Windows::Forms::FlowDirection::BottomUp;
            this->flowLayoutPanel_MenuDown->Location=System::Drawing::Point(1, 532);
            this->flowLayoutPanel_MenuDown->Margin=System::Windows::Forms::Padding(1, 0, 1, 1);
            this->flowLayoutPanel_MenuDown->Name=L"flowLayoutPanel_MenuDown";
            this->flowLayoutPanel_MenuDown->Size=System::Drawing::Size(148, 49);
            this->flowLayoutPanel_MenuDown->TabIndex=2;
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
            this->flowLayoutPanel_MenuUp->Size=System::Drawing::Size(148, 531);
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
            this->button_DashBoard->Click+=gcnew System::EventHandler(this, &SupervisorForm::button_DashBoard_Click);
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
            this->button_ServiceCall->Click+=gcnew System::EventHandler(this, &SupervisorForm::button_ServiceCall_Click);
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
            this->button_RDSuser->Click+=gcnew System::EventHandler(this, &SupervisorForm::button_RDSuser_Click);
            //
            // button_Supervisor
            //
            this->button_Supervisor->BackgroundImage=(cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_Supervisor.BackgroundImage")));
            this->button_Supervisor->Font=(gcnew System::Drawing::Font(L"PMingLiU", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->button_Supervisor->Location=System::Drawing::Point(12, 198);
            this->button_Supervisor->Margin=System::Windows::Forms::Padding(12, 12, 12, 0);
            this->button_Supervisor->Name=L"button_Supervisor";
            this->button_Supervisor->Size=System::Drawing::Size(125, 50);
            this->button_Supervisor->TabIndex=30;
            this->button_Supervisor->Text=L"Supervisor Account";
            this->button_Supervisor->UseVisualStyleBackColor=true;
            this->button_Supervisor->Click+=gcnew System::EventHandler(this, &SupervisorForm::SupervisorForm_Load);
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
            this->button_Dealer->Click+=gcnew System::EventHandler(this, &SupervisorForm::button_Dealer_Click);
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
            this->button_LogOut->Click+=gcnew System::EventHandler(this, &SupervisorForm::button_LogOut_Click);
            //
            // SupervisorForm
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
            this->Name=L"SupervisorForm";
            this->StartPosition=System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text=L"RDSadmin: MIS Supervisor";
            this->Load+=gcnew System::EventHandler(this, &SupervisorForm::SupervisorForm_Load);
            this->panel_title->ResumeLayout(false);
            this->panel_title->PerformLayout();
            this->panel1->ResumeLayout(false);
            this->panel1->PerformLayout();
            this->tableLayoutPanel_BG->ResumeLayout(false);
            this->tableLayoutPanel_Content->ResumeLayout(false);
            this->flowLayoutPanel_ctrl->ResumeLayout(false);
            this->tableLayoutPanel_Menu->ResumeLayout(false);
            this->flowLayoutPanel_MenuDown->ResumeLayout(false);
            this->flowLayoutPanel_MenuDown->PerformLayout();
            this->flowLayoutPanel_MenuUp->ResumeLayout(false);
            this->ResumeLayout(false);
        }
#pragma endregion
    private: System::Void SupervisorForm_Load(System::Object^  sender, System::EventArgs^  e);
             //
    private: System::Void button_DashBoard_Click(System::Object^  sender, System::EventArgs^  e);
    private: System::Void button_ServiceCall_Click(System::Object^  sender, System::EventArgs^  e);
    private: System::Void button_RDSuser_Click(System::Object^  sender, System::EventArgs^  e);
    private: System::Void button_Dealer_Click(System::Object^  sender, System::EventArgs^  e);
             //
    private: System::Void button_Save_Click(System::Object^  sender, System::EventArgs^  e);
    private: System::Void button_Edit_Click(System::Object^  sender, System::EventArgs^  e);
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
