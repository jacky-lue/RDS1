#pragma once

namespace RDSadmin {
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    /// <summary>
    /// Summary for rpt_b_Form
    /// </summary>
    public ref class rpt_b_Form: public System::Windows::Forms::Form
    {
    public:
        rpt_b_Form(String^ filename)
        {
            InitializeComponent();
            //
            //TODO: Add the constructor code here
            //
            this->readFilename=filename;
        }
    public:
        //control usage
        int belong_Page;
        //include objects here.....
        RDS_NAS::nas_state iNas;

        //for reading file and disply content
        String^ readFilename;
        String^ UID;
        String^ RPT_date;
        String^ spa_model_name;
        String^ spa_serial;
        String^ spa_owner;
        String^ cr_operatorName;
        String^ StartErr;
        String^ EndErr;
        String^ CR_comment;
    private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel_BG;
    public:
    private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
    private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel_MenuUp;
    private: System::Windows::Forms::Button^  button_DashBoard;
    private: System::Windows::Forms::Button^  button_ServiceCall;
    private: System::Windows::Forms::Button^  button_RDSuser;
    private: System::Windows::Forms::Button^  button_Supervisor;
    private: System::Windows::Forms::Button^  button_Dealer;
    private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel_MenuDown;
    private: System::Windows::Forms::Label^  label_LoginAuthorLv;
    private: System::Windows::Forms::Label^  label_LoginID;
    private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel2;
    private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel_Brpt;
    private: System::Windows::Forms::Button^  button_LogOut;

    public:

    public:

        String^ replaced_parts;

    protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~rpt_b_Form()
        {
            if(components)
            {
                delete components;
            }
        }

    protected:

    private: System::Windows::Forms::Panel^  panel_SpaSerial;
    private: System::Windows::Forms::TextBox^  textBox_HotTub;
    private: System::Windows::Forms::TextBox^  textBox_SpaSerial;
    private: System::Windows::Forms::Label^  lbl_HotTub;
    private: System::Windows::Forms::Label^  lbl_SpaSerial;
    private: System::Windows::Forms::Panel^  panel_CRperson;
    private: System::Windows::Forms::TextBox^  textBox_CRperson;
    private: System::Windows::Forms::TextBox^  textBox_Date;
    private: System::Windows::Forms::Label^  lbl_crPerson;
    private: System::Windows::Forms::Label^  lbl_Date;
    private: System::Windows::Forms::Panel^  panel_ErrMsg;
    private: System::Windows::Forms::TextBox^  textBox_ErrMsg;
    private: System::Windows::Forms::Label^  lbl_ErrMsg;
    private: System::Windows::Forms::Panel^  panel_pCause;
    private: System::Windows::Forms::TextBox^  textBox_pCause;
    private: System::Windows::Forms::Label^  lbl_pCause;
    private: System::Windows::Forms::Panel^  panel_Equipments;
    private: System::Windows::Forms::RichTextBox^  richTextBox_equipments;

    private: System::Windows::Forms::Label^  lbl_Equipments;
    private: System::Windows::Forms::Panel^  panel_RDSreport;
    private: System::Windows::Forms::Button^  button_back;
    private: System::Windows::Forms::Button^  button_fullReport;
    private: System::Windows::Forms::Panel^  panel_comment;
    private: System::Windows::Forms::RichTextBox^  richTextBox_comment;
    private: System::Windows::Forms::Label^  label_comment;
    private: System::Windows::Forms::Panel^  panel_Owner;
    private: System::Windows::Forms::TextBox^  textBox_UID;
    private: System::Windows::Forms::Label^  lbl_UID;
    private: System::Windows::Forms::TextBox^  textBox_owner;
    private: System::Windows::Forms::Label^  lbl_owner;

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
            System::ComponentModel::ComponentResourceManager^  resources=(gcnew System::ComponentModel::ComponentResourceManager(rpt_b_Form::typeid));
            this->panel_SpaSerial=(gcnew System::Windows::Forms::Panel());
            this->textBox_HotTub=(gcnew System::Windows::Forms::TextBox());
            this->textBox_SpaSerial=(gcnew System::Windows::Forms::TextBox());
            this->lbl_HotTub=(gcnew System::Windows::Forms::Label());
            this->lbl_SpaSerial=(gcnew System::Windows::Forms::Label());
            this->panel_CRperson=(gcnew System::Windows::Forms::Panel());
            this->textBox_CRperson=(gcnew System::Windows::Forms::TextBox());
            this->textBox_Date=(gcnew System::Windows::Forms::TextBox());
            this->lbl_crPerson=(gcnew System::Windows::Forms::Label());
            this->lbl_Date=(gcnew System::Windows::Forms::Label());
            this->panel_ErrMsg=(gcnew System::Windows::Forms::Panel());
            this->textBox_ErrMsg=(gcnew System::Windows::Forms::TextBox());
            this->lbl_ErrMsg=(gcnew System::Windows::Forms::Label());
            this->panel_pCause=(gcnew System::Windows::Forms::Panel());
            this->textBox_pCause=(gcnew System::Windows::Forms::TextBox());
            this->lbl_pCause=(gcnew System::Windows::Forms::Label());
            this->panel_Equipments=(gcnew System::Windows::Forms::Panel());
            this->richTextBox_equipments=(gcnew System::Windows::Forms::RichTextBox());
            this->lbl_Equipments=(gcnew System::Windows::Forms::Label());
            this->panel_RDSreport=(gcnew System::Windows::Forms::Panel());
            this->button_back=(gcnew System::Windows::Forms::Button());
            this->button_fullReport=(gcnew System::Windows::Forms::Button());
            this->panel_comment=(gcnew System::Windows::Forms::Panel());
            this->richTextBox_comment=(gcnew System::Windows::Forms::RichTextBox());
            this->label_comment=(gcnew System::Windows::Forms::Label());
            this->panel_Owner=(gcnew System::Windows::Forms::Panel());
            this->textBox_UID=(gcnew System::Windows::Forms::TextBox());
            this->lbl_UID=(gcnew System::Windows::Forms::Label());
            this->textBox_owner=(gcnew System::Windows::Forms::TextBox());
            this->lbl_owner=(gcnew System::Windows::Forms::Label());
            this->tableLayoutPanel_BG=(gcnew System::Windows::Forms::TableLayoutPanel());
            this->tableLayoutPanel1=(gcnew System::Windows::Forms::TableLayoutPanel());
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
            this->tableLayoutPanel2=(gcnew System::Windows::Forms::TableLayoutPanel());
            this->flowLayoutPanel_Brpt=(gcnew System::Windows::Forms::FlowLayoutPanel());
            this->panel_SpaSerial->SuspendLayout();
            this->panel_CRperson->SuspendLayout();
            this->panel_ErrMsg->SuspendLayout();
            this->panel_pCause->SuspendLayout();
            this->panel_Equipments->SuspendLayout();
            this->panel_RDSreport->SuspendLayout();
            this->panel_comment->SuspendLayout();
            this->panel_Owner->SuspendLayout();
            this->tableLayoutPanel_BG->SuspendLayout();
            this->tableLayoutPanel1->SuspendLayout();
            this->flowLayoutPanel_MenuDown->SuspendLayout();
            this->flowLayoutPanel_MenuUp->SuspendLayout();
            this->tableLayoutPanel2->SuspendLayout();
            this->flowLayoutPanel_Brpt->SuspendLayout();
            this->SuspendLayout();
            //
            // panel_SpaSerial
            //
            this->panel_SpaSerial->BackColor=System::Drawing::Color::Teal;
            this->panel_SpaSerial->Controls->Add(this->textBox_HotTub);
            this->panel_SpaSerial->Controls->Add(this->textBox_SpaSerial);
            this->panel_SpaSerial->Controls->Add(this->lbl_HotTub);
            this->panel_SpaSerial->Controls->Add(this->lbl_SpaSerial);
            this->panel_SpaSerial->Location=System::Drawing::Point(0, 357);
            this->panel_SpaSerial->Margin=System::Windows::Forms::Padding(0, 5, 0, 0);
            this->panel_SpaSerial->Name=L"panel_SpaSerial";
            this->panel_SpaSerial->Size=System::Drawing::Size(710, 45);
            this->panel_SpaSerial->TabIndex=7;
            //
            // textBox_HotTub
            //
            this->textBox_HotTub->BackColor=System::Drawing::Color::LightBlue;
            this->textBox_HotTub->Font=(gcnew System::Drawing::Font(L"Cambria", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->textBox_HotTub->Location=System::Drawing::Point(496, 8);
            this->textBox_HotTub->Name=L"textBox_HotTub";
            this->textBox_HotTub->ReadOnly=true;
            this->textBox_HotTub->Size=System::Drawing::Size(199, 30);
            this->textBox_HotTub->TabIndex=3;
            this->textBox_HotTub->Text=L"123456789";
            this->textBox_HotTub->TextAlign=System::Windows::Forms::HorizontalAlignment::Center;
            //
            // textBox_SpaSerial
            //
            this->textBox_SpaSerial->BackColor=System::Drawing::Color::LightBlue;
            this->textBox_SpaSerial->Font=(gcnew System::Drawing::Font(L"Cambria", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->textBox_SpaSerial->Location=System::Drawing::Point(127, 8);
            this->textBox_SpaSerial->Name=L"textBox_SpaSerial";
            this->textBox_SpaSerial->ReadOnly=true;
            this->textBox_SpaSerial->Size=System::Drawing::Size(186, 30);
            this->textBox_SpaSerial->TabIndex=2;
            this->textBox_SpaSerial->Text=L"123456789";
            this->textBox_SpaSerial->TextAlign=System::Windows::Forms::HorizontalAlignment::Center;
            //
            // lbl_HotTub
            //
            this->lbl_HotTub->AutoSize=true;
            this->lbl_HotTub->Font=(gcnew System::Drawing::Font(L"Cambria", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lbl_HotTub->ForeColor=System::Drawing::Color::White;
            this->lbl_HotTub->Location=System::Drawing::Point(327, 10);
            this->lbl_HotTub->Name=L"lbl_HotTub";
            this->lbl_HotTub->Size=System::Drawing::Size(163, 25);
            this->lbl_HotTub->TabIndex=1;
            this->lbl_HotTub->Text=L"Hot Tub Model #";
            //
            // lbl_SpaSerial
            //
            this->lbl_SpaSerial->AutoSize=true;
            this->lbl_SpaSerial->Font=(gcnew System::Drawing::Font(L"Cambria", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lbl_SpaSerial->ForeColor=System::Drawing::Color::White;
            this->lbl_SpaSerial->Location=System::Drawing::Point(3, 10);
            this->lbl_SpaSerial->Name=L"lbl_SpaSerial";
            this->lbl_SpaSerial->Size=System::Drawing::Size(118, 25);
            this->lbl_SpaSerial->TabIndex=0;
            this->lbl_SpaSerial->Text=L"Spa Serial #";
            //
            // panel_CRperson
            //
            this->panel_CRperson->BackColor=System::Drawing::Color::Teal;
            this->panel_CRperson->Controls->Add(this->textBox_CRperson);
            this->panel_CRperson->Controls->Add(this->textBox_Date);
            this->panel_CRperson->Controls->Add(this->lbl_crPerson);
            this->panel_CRperson->Controls->Add(this->lbl_Date);
            this->panel_CRperson->Location=System::Drawing::Point(0, 184);
            this->panel_CRperson->Margin=System::Windows::Forms::Padding(0, 5, 0, 0);
            this->panel_CRperson->Name=L"panel_CRperson";
            this->panel_CRperson->Size=System::Drawing::Size(710, 45);
            this->panel_CRperson->TabIndex=9;
            //
            // textBox_CRperson
            //
            this->textBox_CRperson->BackColor=System::Drawing::Color::LightBlue;
            this->textBox_CRperson->Font=(gcnew System::Drawing::Font(L"Cambria", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->textBox_CRperson->Location=System::Drawing::Point(496, 8);
            this->textBox_CRperson->Name=L"textBox_CRperson";
            this->textBox_CRperson->ReadOnly=true;
            this->textBox_CRperson->Size=System::Drawing::Size(199, 30);
            this->textBox_CRperson->TabIndex=3;
            this->textBox_CRperson->Text=L"123456789";
            this->textBox_CRperson->TextAlign=System::Windows::Forms::HorizontalAlignment::Center;
            //
            // textBox_Date
            //
            this->textBox_Date->BackColor=System::Drawing::Color::LightBlue;
            this->textBox_Date->Font=(gcnew System::Drawing::Font(L"Cambria", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->textBox_Date->Location=System::Drawing::Point(127, 8);
            this->textBox_Date->Name=L"textBox_Date";
            this->textBox_Date->ReadOnly=true;
            this->textBox_Date->Size=System::Drawing::Size(186, 30);
            this->textBox_Date->TabIndex=2;
            this->textBox_Date->Text=L"123456789";
            this->textBox_Date->TextAlign=System::Windows::Forms::HorizontalAlignment::Center;
            //
            // lbl_crPerson
            //
            this->lbl_crPerson->AutoSize=true;
            this->lbl_crPerson->Font=(gcnew System::Drawing::Font(L"Cambria", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lbl_crPerson->ForeColor=System::Drawing::Color::White;
            this->lbl_crPerson->Location=System::Drawing::Point(350, 10);
            this->lbl_crPerson->Name=L"lbl_crPerson";
            this->lbl_crPerson->Size=System::Drawing::Size(113, 25);
            this->lbl_crPerson->TabIndex=1;
            this->lbl_crPerson->Text=L"C.R. Person";
            //
            // lbl_Date
            //
            this->lbl_Date->AutoSize=true;
            this->lbl_Date->Font=(gcnew System::Drawing::Font(L"Cambria", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lbl_Date->ForeColor=System::Drawing::Color::White;
            this->lbl_Date->Location=System::Drawing::Point(34, 10);
            this->lbl_Date->Name=L"lbl_Date";
            this->lbl_Date->Size=System::Drawing::Size(53, 25);
            this->lbl_Date->TabIndex=0;
            this->lbl_Date->Text=L"Date";
            //
            // panel_ErrMsg
            //
            this->panel_ErrMsg->BackColor=System::Drawing::Color::Teal;
            this->panel_ErrMsg->Controls->Add(this->textBox_ErrMsg);
            this->panel_ErrMsg->Controls->Add(this->lbl_ErrMsg);
            this->panel_ErrMsg->Location=System::Drawing::Point(0, 55);
            this->panel_ErrMsg->Margin=System::Windows::Forms::Padding(0, 5, 0, 0);
            this->panel_ErrMsg->Name=L"panel_ErrMsg";
            this->panel_ErrMsg->Size=System::Drawing::Size(710, 60);
            this->panel_ErrMsg->TabIndex=10;
            //
            // textBox_ErrMsg
            //
            this->textBox_ErrMsg->BackColor=System::Drawing::Color::LightBlue;
            this->textBox_ErrMsg->Font=(gcnew System::Drawing::Font(L"Cambria", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->textBox_ErrMsg->Location=System::Drawing::Point(167, 8);
            this->textBox_ErrMsg->Name=L"textBox_ErrMsg";
            this->textBox_ErrMsg->ReadOnly=true;
            this->textBox_ErrMsg->Size=System::Drawing::Size(528, 41);
            this->textBox_ErrMsg->TabIndex=2;
            this->textBox_ErrMsg->Text=L"123, 123, 123, 123";
            this->textBox_ErrMsg->TextAlign=System::Windows::Forms::HorizontalAlignment::Center;
            //
            // lbl_ErrMsg
            //
            this->lbl_ErrMsg->AutoSize=true;
            this->lbl_ErrMsg->Font=(gcnew System::Drawing::Font(L"Cambria", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lbl_ErrMsg->ForeColor=System::Drawing::Color::White;
            this->lbl_ErrMsg->Location=System::Drawing::Point(14, 18);
            this->lbl_ErrMsg->Name=L"lbl_ErrMsg";
            this->lbl_ErrMsg->Size=System::Drawing::Size(147, 25);
            this->lbl_ErrMsg->TabIndex=0;
            this->lbl_ErrMsg->Text=L"Error Message ";
            //
            // panel_pCause
            //
            this->panel_pCause->BackColor=System::Drawing::Color::Teal;
            this->panel_pCause->Controls->Add(this->textBox_pCause);
            this->panel_pCause->Controls->Add(this->lbl_pCause);
            this->panel_pCause->Location=System::Drawing::Point(0, 120);
            this->panel_pCause->Margin=System::Windows::Forms::Padding(0, 5, 0, 0);
            this->panel_pCause->Name=L"panel_pCause";
            this->panel_pCause->Size=System::Drawing::Size(710, 59);
            this->panel_pCause->TabIndex=12;
            //
            // textBox_pCause
            //
            this->textBox_pCause->BackColor=System::Drawing::Color::LightBlue;
            this->textBox_pCause->Font=(gcnew System::Drawing::Font(L"Cambria", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->textBox_pCause->Location=System::Drawing::Point(223, 9);
            this->textBox_pCause->Name=L"textBox_pCause";
            this->textBox_pCause->ReadOnly=true;
            this->textBox_pCause->Size=System::Drawing::Size(472, 41);
            this->textBox_pCause->TabIndex=2;
            this->textBox_pCause->Text=L"123456789, 123456789";
            this->textBox_pCause->TextAlign=System::Windows::Forms::HorizontalAlignment::Center;
            //
            // lbl_pCause
            //
            this->lbl_pCause->AutoSize=true;
            this->lbl_pCause->Font=(gcnew System::Drawing::Font(L"Cambria", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lbl_pCause->ForeColor=System::Drawing::Color::White;
            this->lbl_pCause->Location=System::Drawing::Point(14, 20);
            this->lbl_pCause->Name=L"lbl_pCause";
            this->lbl_pCause->Size=System::Drawing::Size(192, 25);
            this->lbl_pCause->TabIndex=0;
            this->lbl_pCause->Text=L"Possible Root Cause";
            //
            // panel_Equipments
            //
            this->panel_Equipments->BackColor=System::Drawing::Color::Teal;
            this->panel_Equipments->Controls->Add(this->richTextBox_equipments);
            this->panel_Equipments->Controls->Add(this->lbl_Equipments);
            this->panel_Equipments->Location=System::Drawing::Point(0, 234);
            this->panel_Equipments->Margin=System::Windows::Forms::Padding(0, 5, 0, 0);
            this->panel_Equipments->Name=L"panel_Equipments";
            this->panel_Equipments->Size=System::Drawing::Size(710, 118);
            this->panel_Equipments->TabIndex=11;
            //
            // richTextBox_equipments
            //
            this->richTextBox_equipments->BackColor=System::Drawing::Color::LightBlue;
            this->richTextBox_equipments->Font=(gcnew System::Drawing::Font(L"Cambria", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->richTextBox_equipments->Location=System::Drawing::Point(14, 36);
            this->richTextBox_equipments->Name=L"richTextBox_equipments";
            this->richTextBox_equipments->ReadOnly=true;
            this->richTextBox_equipments->Size=System::Drawing::Size(681, 71);
            this->richTextBox_equipments->TabIndex=1;
            this->richTextBox_equipments->Text=L"";
            //
            // lbl_Equipments
            //
            this->lbl_Equipments->AutoSize=true;
            this->lbl_Equipments->Font=(gcnew System::Drawing::Font(L"Cambria", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lbl_Equipments->ForeColor=System::Drawing::Color::White;
            this->lbl_Equipments->Location=System::Drawing::Point(14, 4);
            this->lbl_Equipments->Name=L"lbl_Equipments";
            this->lbl_Equipments->Size=System::Drawing::Size(291, 25);
            this->lbl_Equipments->TabIndex=0;
            this->lbl_Equipments->Text=L"Equipments for On-Site Service";
            //
            // panel_RDSreport
            //
            this->panel_RDSreport->BackColor=System::Drawing::Color::SteelBlue;
            this->panel_RDSreport->Controls->Add(this->button_back);
            this->panel_RDSreport->Controls->Add(this->button_fullReport);
            this->panel_RDSreport->Dock=System::Windows::Forms::DockStyle::Fill;
            this->panel_RDSreport->Location=System::Drawing::Point(1, 523);
            this->panel_RDSreport->Margin=System::Windows::Forms::Padding(1);
            this->panel_RDSreport->Name=L"panel_RDSreport";
            this->panel_RDSreport->Size=System::Drawing::Size(708, 58);
            this->panel_RDSreport->TabIndex=13;
            //
            // button_back
            //
            this->button_back->Font=(gcnew System::Drawing::Font(L"Cambria", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button_back->Location=System::Drawing::Point(14, 15);
            this->button_back->Name=L"button_back";
            this->button_back->Size=System::Drawing::Size(147, 35);
            this->button_back->TabIndex=2;
            this->button_back->Text=L"Back";
            this->button_back->UseVisualStyleBackColor=true;
            this->button_back->Click+=gcnew System::EventHandler(this, &rpt_b_Form::button_back_Click);
            //
            // button_fullReport
            //
            this->button_fullReport->Font=(gcnew System::Drawing::Font(L"Cambria", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button_fullReport->Location=System::Drawing::Point(428, 15);
            this->button_fullReport->Name=L"button_fullReport";
            this->button_fullReport->Size=System::Drawing::Size(267, 35);
            this->button_fullReport->TabIndex=1;
            this->button_fullReport->Text=L"RDS Full Report";
            this->button_fullReport->UseVisualStyleBackColor=true;
            this->button_fullReport->Click+=gcnew System::EventHandler(this, &rpt_b_Form::button_fullReport_Click);
            //
            // panel_comment
            //
            this->panel_comment->BackColor=System::Drawing::Color::Teal;
            this->panel_comment->Controls->Add(this->richTextBox_comment);
            this->panel_comment->Controls->Add(this->label_comment);
            this->panel_comment->Location=System::Drawing::Point(0, 407);
            this->panel_comment->Margin=System::Windows::Forms::Padding(0, 5, 0, 0);
            this->panel_comment->Name=L"panel_comment";
            this->panel_comment->Size=System::Drawing::Size(710, 91);
            this->panel_comment->TabIndex=14;
            //
            // richTextBox_comment
            //
            this->richTextBox_comment->BackColor=System::Drawing::Color::LightBlue;
            this->richTextBox_comment->Font=(gcnew System::Drawing::Font(L"Cambria", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->richTextBox_comment->Location=System::Drawing::Point(167, 7);
            this->richTextBox_comment->Name=L"richTextBox_comment";
            this->richTextBox_comment->Size=System::Drawing::Size(528, 75);
            this->richTextBox_comment->TabIndex=1;
            this->richTextBox_comment->Text=L"";
            //
            // label_comment
            //
            this->label_comment->AutoSize=true;
            this->label_comment->Font=(gcnew System::Drawing::Font(L"Cambria", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label_comment->ForeColor=System::Drawing::Color::White;
            this->label_comment->Location=System::Drawing::Point(34, 25);
            this->label_comment->Name=L"label_comment";
            this->label_comment->Size=System::Drawing::Size(98, 25);
            this->label_comment->TabIndex=0;
            this->label_comment->Text=L"Comment";
            //
            // panel_Owner
            //
            this->panel_Owner->BackColor=System::Drawing::Color::Teal;
            this->panel_Owner->Controls->Add(this->textBox_UID);
            this->panel_Owner->Controls->Add(this->lbl_UID);
            this->panel_Owner->Controls->Add(this->textBox_owner);
            this->panel_Owner->Controls->Add(this->lbl_owner);
            this->panel_Owner->Location=System::Drawing::Point(0, 5);
            this->panel_Owner->Margin=System::Windows::Forms::Padding(0, 5, 0, 0);
            this->panel_Owner->Name=L"panel_Owner";
            this->panel_Owner->Size=System::Drawing::Size(710, 45);
            this->panel_Owner->TabIndex=15;
            //
            // textBox_UID
            //
            this->textBox_UID->BackColor=System::Drawing::Color::LightBlue;
            this->textBox_UID->Font=(gcnew System::Drawing::Font(L"Cambria", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->textBox_UID->Location=System::Drawing::Point(100, 9);
            this->textBox_UID->Name=L"textBox_UID";
            this->textBox_UID->ReadOnly=true;
            this->textBox_UID->Size=System::Drawing::Size(290, 30);
            this->textBox_UID->TabIndex=4;
            this->textBox_UID->Text=L"123456789";
            this->textBox_UID->TextAlign=System::Windows::Forms::HorizontalAlignment::Center;
            //
            // lbl_UID
            //
            this->lbl_UID->AutoSize=true;
            this->lbl_UID->Font=(gcnew System::Drawing::Font(L"Cambria", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lbl_UID->ForeColor=System::Drawing::Color::White;
            this->lbl_UID->Location=System::Drawing::Point(30, 10);
            this->lbl_UID->Name=L"lbl_UID";
            this->lbl_UID->Size=System::Drawing::Size(47, 25);
            this->lbl_UID->TabIndex=3;
            this->lbl_UID->Text=L"UID";
            //
            // textBox_owner
            //
            this->textBox_owner->BackColor=System::Drawing::Color::LightBlue;
            this->textBox_owner->Font=(gcnew System::Drawing::Font(L"Cambria", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->textBox_owner->Location=System::Drawing::Point(494, 9);
            this->textBox_owner->Name=L"textBox_owner";
            this->textBox_owner->ReadOnly=true;
            this->textBox_owner->Size=System::Drawing::Size(186, 30);
            this->textBox_owner->TabIndex=2;
            this->textBox_owner->Text=L"123456789";
            this->textBox_owner->TextAlign=System::Windows::Forms::HorizontalAlignment::Center;
            //
            // lbl_owner
            //
            this->lbl_owner->AutoSize=true;
            this->lbl_owner->Font=(gcnew System::Drawing::Font(L"Cambria", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lbl_owner->ForeColor=System::Drawing::Color::White;
            this->lbl_owner->Location=System::Drawing::Point(408, 10);
            this->lbl_owner->Name=L"lbl_owner";
            this->lbl_owner->Size=System::Drawing::Size(73, 25);
            this->lbl_owner->TabIndex=0;
            this->lbl_owner->Text=L"Owner";
            //
            // tableLayoutPanel_BG
            //
            this->tableLayoutPanel_BG->ColumnCount=2;
            this->tableLayoutPanel_BG->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                150)));
            this->tableLayoutPanel_BG->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                100)));
            this->tableLayoutPanel_BG->Controls->Add(this->tableLayoutPanel1, 0, 0);
            this->tableLayoutPanel_BG->Controls->Add(this->tableLayoutPanel2, 1, 0);
            this->tableLayoutPanel_BG->Dock=System::Windows::Forms::DockStyle::Fill;
            this->tableLayoutPanel_BG->Location=System::Drawing::Point(0, 0);
            this->tableLayoutPanel_BG->Name=L"tableLayoutPanel_BG";
            this->tableLayoutPanel_BG->RowCount=1;
            this->tableLayoutPanel_BG->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
                100)));
            this->tableLayoutPanel_BG->Size=System::Drawing::Size(860, 582);
            this->tableLayoutPanel_BG->TabIndex=16;
            //
            // tableLayoutPanel1
            //
            this->tableLayoutPanel1->ColumnCount=1;
            this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                100)));
            this->tableLayoutPanel1->Controls->Add(this->flowLayoutPanel_MenuDown, 0, 1);
            this->tableLayoutPanel1->Controls->Add(this->flowLayoutPanel_MenuUp, 0, 0);
            this->tableLayoutPanel1->Dock=System::Windows::Forms::DockStyle::Fill;
            this->tableLayoutPanel1->Location=System::Drawing::Point(0, 0);
            this->tableLayoutPanel1->Margin=System::Windows::Forms::Padding(0);
            this->tableLayoutPanel1->Name=L"tableLayoutPanel1";
            this->tableLayoutPanel1->RowCount=2;
            this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
            this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 60)));
            this->tableLayoutPanel1->Size=System::Drawing::Size(150, 582);
            this->tableLayoutPanel1->TabIndex=0;
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
            this->flowLayoutPanel_MenuDown->TabIndex=5;
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
            this->flowLayoutPanel_MenuUp->TabIndex=4;
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
            this->button_DashBoard->Click+=gcnew System::EventHandler(this, &rpt_b_Form::button_DashBoard_Click);
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
            this->button_ServiceCall->Click+=gcnew System::EventHandler(this, &rpt_b_Form::button_ServiceCall_Click);
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
            this->button_RDSuser->Click+=gcnew System::EventHandler(this, &rpt_b_Form::button_RDSuser_Click);
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
            this->button_Supervisor->Click+=gcnew System::EventHandler(this, &rpt_b_Form::button_Supervisor_Click);
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
            this->button_Dealer->Click+=gcnew System::EventHandler(this, &rpt_b_Form::button_Dealer_Click);
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
            this->button_LogOut->Click+=gcnew System::EventHandler(this, &rpt_b_Form::button_LogOut_Click);
            //
            // tableLayoutPanel2
            //
            this->tableLayoutPanel2->ColumnCount=1;
            this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                100)));
            this->tableLayoutPanel2->Controls->Add(this->panel_RDSreport, 0, 1);
            this->tableLayoutPanel2->Controls->Add(this->flowLayoutPanel_Brpt, 0, 0);
            this->tableLayoutPanel2->Dock=System::Windows::Forms::DockStyle::Fill;
            this->tableLayoutPanel2->Location=System::Drawing::Point(150, 0);
            this->tableLayoutPanel2->Margin=System::Windows::Forms::Padding(0);
            this->tableLayoutPanel2->Name=L"tableLayoutPanel2";
            this->tableLayoutPanel2->RowCount=2;
            this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
            this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 60)));
            this->tableLayoutPanel2->Size=System::Drawing::Size(710, 582);
            this->tableLayoutPanel2->TabIndex=1;
            //
            // flowLayoutPanel_Brpt
            //
            this->flowLayoutPanel_Brpt->BackColor=System::Drawing::Color::Black;
            this->flowLayoutPanel_Brpt->Controls->Add(this->panel_Owner);
            this->flowLayoutPanel_Brpt->Controls->Add(this->panel_ErrMsg);
            this->flowLayoutPanel_Brpt->Controls->Add(this->panel_pCause);
            this->flowLayoutPanel_Brpt->Controls->Add(this->panel_CRperson);
            this->flowLayoutPanel_Brpt->Controls->Add(this->panel_Equipments);
            this->flowLayoutPanel_Brpt->Controls->Add(this->panel_SpaSerial);
            this->flowLayoutPanel_Brpt->Controls->Add(this->panel_comment);
            this->flowLayoutPanel_Brpt->Dock=System::Windows::Forms::DockStyle::Fill;
            this->flowLayoutPanel_Brpt->FlowDirection=System::Windows::Forms::FlowDirection::TopDown;
            this->flowLayoutPanel_Brpt->Location=System::Drawing::Point(0, 0);
            this->flowLayoutPanel_Brpt->Margin=System::Windows::Forms::Padding(0);
            this->flowLayoutPanel_Brpt->Name=L"flowLayoutPanel_Brpt";
            this->flowLayoutPanel_Brpt->Size=System::Drawing::Size(710, 522);
            this->flowLayoutPanel_Brpt->TabIndex=14;
            //
            // rpt_b_Form
            //
            this->AutoScaleDimensions=System::Drawing::SizeF(6, 12);
            this->AutoScaleMode=System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor=System::Drawing::SystemColors::Control;
            this->ClientSize=System::Drawing::Size(860, 582);
            this->ControlBox=false;
            this->Controls->Add(this->tableLayoutPanel_BG);
            this->Icon=(cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
            this->MaximizeBox=false;
            this->MinimizeBox=false;
            this->Name=L"rpt_b_Form";
            this->StartPosition=System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text=L"rpt_b_Form";
            this->Load+=gcnew System::EventHandler(this, &rpt_b_Form::rpt_b_Form_Load);
            this->panel_SpaSerial->ResumeLayout(false);
            this->panel_SpaSerial->PerformLayout();
            this->panel_CRperson->ResumeLayout(false);
            this->panel_CRperson->PerformLayout();
            this->panel_ErrMsg->ResumeLayout(false);
            this->panel_ErrMsg->PerformLayout();
            this->panel_pCause->ResumeLayout(false);
            this->panel_pCause->PerformLayout();
            this->panel_Equipments->ResumeLayout(false);
            this->panel_Equipments->PerformLayout();
            this->panel_RDSreport->ResumeLayout(false);
            this->panel_comment->ResumeLayout(false);
            this->panel_comment->PerformLayout();
            this->panel_Owner->ResumeLayout(false);
            this->panel_Owner->PerformLayout();
            this->tableLayoutPanel_BG->ResumeLayout(false);
            this->tableLayoutPanel1->ResumeLayout(false);
            this->flowLayoutPanel_MenuDown->ResumeLayout(false);
            this->flowLayoutPanel_MenuDown->PerformLayout();
            this->flowLayoutPanel_MenuUp->ResumeLayout(false);
            this->tableLayoutPanel2->ResumeLayout(false);
            this->flowLayoutPanel_Brpt->ResumeLayout(false);
            this->ResumeLayout(false);
        }
#pragma endregion
    private: void showBriefReport(String^ readFileName);
             //
    private: System::Void rpt_b_Form_Load(System::Object^  sender, System::EventArgs^  e);
             //
    private: System::Void button_ServiceCall_Click(System::Object^  sender, System::EventArgs^  e);
    private: System::Void button_RDSuser_Click(System::Object^  sender, System::EventArgs^  e);
    private: System::Void button_Supervisor_Click(System::Object^  sender, System::EventArgs^  e);
    private: System::Void button_DashBoard_Click(System::Object^  sender, System::EventArgs^  e);
    private: System::Void button_Dealer_Click(System::Object^  sender, System::EventArgs^  e);
             //
    private: System::Void button_back_Click(System::Object^  sender, System::EventArgs^  e);
    private: System::Void button_fullReport_Click(System::Object^  sender, System::EventArgs^  e);
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
