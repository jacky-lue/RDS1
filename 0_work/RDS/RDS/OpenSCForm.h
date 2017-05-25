#pragma once

#include "RDS_main_Form.h"

namespace RDS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for OpenSCForm
	/// </summary>
	public ref class OpenSCForm : public System::Windows::Forms::Form
	{
	public:
		OpenSCForm(RDS_main_Form^ pForm)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			m_MainForm = pForm;
		}
	private: System::Windows::Forms::Button^  button_fullReport;
	public:
	public: RDS_main_Form^ m_MainForm;

			//for RDS report/ service call...
			String^ Base_dir;

			//for operator
			unsigned char RDS_operator_No;  //operator No, p0=supervisor, p1, p2....
			String^ RDS_operator_name;

			//for directory scan
			unsigned int total_items_inDir;
			unsigned int pageNo;
			Boolean hasPrePage;
			Boolean hasNextPage;
			String^ UID;
			String^ I0_filename;
			String^ I1_filename;
			String^ I2_filename;
			String^ I3_filename;
			String^ I4_filename;
			String^ I5_filename;
			String^ I6_filename;
			String^ I7_filename;
			String^ I8_filename;
			String^ I9_filename;
			String^ I0_text;
			String^ I1_text;
			String^ I2_text;
			String^ I3_text;
			String^ I4_text;
			String^ I5_text;
			String^ I6_text;
			String^ I7_text;
			String^ I8_text;
			String^ I9_text;
			String^ SC_no;

			//for reading file and disply content
			String^ readFilename;
			String^ RPT_date;
			String^ spa_model_name;
			String^ spa_serial;
			String^ spa_owner;
			String^ cr_operatorName;
			String^ StartErr;
			String^ EndErr;
			String^ CR_comment;
			String^ replaced_parts;

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~OpenSCForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel_BG;
	protected:
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel_Left;
	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel_UID;
	private: System::Windows::Forms::Label^  label_OpName;
	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel_Date;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Panel^  panel4;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Panel^  panel5;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Panel^  panel6;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Panel^  panel7;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Panel^  panel8;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Panel^  panel9;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Panel^  panel0;
	private: System::Windows::Forms::Label^  label0;
	private: System::Windows::Forms::Panel^  panel_Btn;
	private: System::Windows::Forms::Button^  btn_NextPage;
	private: System::Windows::Forms::Button^  btn_PrePage;
	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel_Right;
	private: System::Windows::Forms::Panel^  panel_Owner;
	private: System::Windows::Forms::TextBox^  textBox_UID;
	private: System::Windows::Forms::Label^  lbl_UID;
	private: System::Windows::Forms::TextBox^  textBox_owner;
	private: System::Windows::Forms::Label^  lbl_owner;
	private: System::Windows::Forms::Panel^  panel_SpaSerial;
	private: System::Windows::Forms::TextBox^  textBox_HotTub;
	private: System::Windows::Forms::TextBox^  textBox_SpaSerial;
	private: System::Windows::Forms::Label^  lbl_HotTub;
	private: System::Windows::Forms::Label^  lbl_SpaSerial;
	private: System::Windows::Forms::Panel^  panel_CRperson;
	private: System::Windows::Forms::TextBox^  textBox_CRperson;
	private: System::Windows::Forms::TextBox^  textBox_Date;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Label^  lbl_Date;
	private: System::Windows::Forms::Panel^  panel_ErrMsg;
	private: System::Windows::Forms::TextBox^  textBox_ErrMsg;
	private: System::Windows::Forms::Label^  lbl_ErrMsg;
	private: System::Windows::Forms::Panel^  panel_pCause;
	private: System::Windows::Forms::TextBox^  textBox_pCause;
	private: System::Windows::Forms::Label^  lbl_pCause;
	private: System::Windows::Forms::Panel^  panel_Equipments;
	private: System::Windows::Forms::RichTextBox^  richTextBox_Equipment;
	private: System::Windows::Forms::Label^  lbl_Equipments;
	private: System::Windows::Forms::Panel^  panel_SC;
	private: System::Windows::Forms::TextBox^  textBox_SCstr;
	private: System::Windows::Forms::Label^  lbl_SC;
	private: System::Windows::Forms::Panel^  panel_replace;
	private: System::Windows::Forms::RichTextBox^  richTextBox_replace;
	private: System::Windows::Forms::Label^  lbl_replace;
	private: System::Windows::Forms::Panel^  panel_comment;
	private: System::Windows::Forms::RichTextBox^  richTextBox_comment;
	private: System::Windows::Forms::Label^  label_comment;
	private: System::Windows::Forms::Panel^  panel_button;
	private: System::Windows::Forms::Button^  button_SaveDelete;
	private: System::Windows::Forms::TextBox^  textBox_Opname;

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
			this->tableLayoutPanel_BG = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel_Left = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->flowLayoutPanel_UID = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->label_OpName = (gcnew System::Windows::Forms::Label());
			this->textBox_Opname = (gcnew System::Windows::Forms::TextBox());
			this->flowLayoutPanel_Date = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->panel0 = (gcnew System::Windows::Forms::Panel());
			this->label0 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->panel8 = (gcnew System::Windows::Forms::Panel());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->panel9 = (gcnew System::Windows::Forms::Panel());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->panel_Btn = (gcnew System::Windows::Forms::Panel());
			this->btn_NextPage = (gcnew System::Windows::Forms::Button());
			this->btn_PrePage = (gcnew System::Windows::Forms::Button());
			this->flowLayoutPanel_Right = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->panel_Owner = (gcnew System::Windows::Forms::Panel());
			this->textBox_UID = (gcnew System::Windows::Forms::TextBox());
			this->lbl_UID = (gcnew System::Windows::Forms::Label());
			this->textBox_owner = (gcnew System::Windows::Forms::TextBox());
			this->lbl_owner = (gcnew System::Windows::Forms::Label());
			this->panel_SpaSerial = (gcnew System::Windows::Forms::Panel());
			this->textBox_HotTub = (gcnew System::Windows::Forms::TextBox());
			this->textBox_SpaSerial = (gcnew System::Windows::Forms::TextBox());
			this->lbl_HotTub = (gcnew System::Windows::Forms::Label());
			this->lbl_SpaSerial = (gcnew System::Windows::Forms::Label());
			this->panel_CRperson = (gcnew System::Windows::Forms::Panel());
			this->textBox_CRperson = (gcnew System::Windows::Forms::TextBox());
			this->textBox_Date = (gcnew System::Windows::Forms::TextBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->lbl_Date = (gcnew System::Windows::Forms::Label());
			this->panel_ErrMsg = (gcnew System::Windows::Forms::Panel());
			this->textBox_ErrMsg = (gcnew System::Windows::Forms::TextBox());
			this->lbl_ErrMsg = (gcnew System::Windows::Forms::Label());
			this->panel_pCause = (gcnew System::Windows::Forms::Panel());
			this->textBox_pCause = (gcnew System::Windows::Forms::TextBox());
			this->lbl_pCause = (gcnew System::Windows::Forms::Label());
			this->panel_Equipments = (gcnew System::Windows::Forms::Panel());
			this->richTextBox_Equipment = (gcnew System::Windows::Forms::RichTextBox());
			this->lbl_Equipments = (gcnew System::Windows::Forms::Label());
			this->panel_SC = (gcnew System::Windows::Forms::Panel());
			this->textBox_SCstr = (gcnew System::Windows::Forms::TextBox());
			this->lbl_SC = (gcnew System::Windows::Forms::Label());
			this->panel_replace = (gcnew System::Windows::Forms::Panel());
			this->richTextBox_replace = (gcnew System::Windows::Forms::RichTextBox());
			this->lbl_replace = (gcnew System::Windows::Forms::Label());
			this->panel_comment = (gcnew System::Windows::Forms::Panel());
			this->richTextBox_comment = (gcnew System::Windows::Forms::RichTextBox());
			this->label_comment = (gcnew System::Windows::Forms::Label());
			this->panel_button = (gcnew System::Windows::Forms::Panel());
			this->button_fullReport = (gcnew System::Windows::Forms::Button());
			this->button_SaveDelete = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel_BG->SuspendLayout();
			this->tableLayoutPanel_Left->SuspendLayout();
			this->flowLayoutPanel_UID->SuspendLayout();
			this->flowLayoutPanel_Date->SuspendLayout();
			this->panel0->SuspendLayout();
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel4->SuspendLayout();
			this->panel5->SuspendLayout();
			this->panel6->SuspendLayout();
			this->panel7->SuspendLayout();
			this->panel8->SuspendLayout();
			this->panel9->SuspendLayout();
			this->panel_Btn->SuspendLayout();
			this->flowLayoutPanel_Right->SuspendLayout();
			this->panel_Owner->SuspendLayout();
			this->panel_SpaSerial->SuspendLayout();
			this->panel_CRperson->SuspendLayout();
			this->panel_ErrMsg->SuspendLayout();
			this->panel_pCause->SuspendLayout();
			this->panel_Equipments->SuspendLayout();
			this->panel_SC->SuspendLayout();
			this->panel_replace->SuspendLayout();
			this->panel_comment->SuspendLayout();
			this->panel_button->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel_BG
			// 
			this->tableLayoutPanel_BG->BackColor = System::Drawing::Color::Navy;
			this->tableLayoutPanel_BG->ColumnCount = 2;
			this->tableLayoutPanel_BG->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				270)));
			this->tableLayoutPanel_BG->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel_BG->Controls->Add(this->tableLayoutPanel_Left, 0, 0);
			this->tableLayoutPanel_BG->Controls->Add(this->flowLayoutPanel_Right, 1, 0);
			this->tableLayoutPanel_BG->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel_BG->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel_BG->Name = L"tableLayoutPanel_BG";
			this->tableLayoutPanel_BG->RowCount = 1;
			this->tableLayoutPanel_BG->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel_BG->Size = System::Drawing::Size(986, 671);
			this->tableLayoutPanel_BG->TabIndex = 2;
			// 
			// tableLayoutPanel_Left
			// 
			this->tableLayoutPanel_Left->BackColor = System::Drawing::Color::Navy;
			this->tableLayoutPanel_Left->ColumnCount = 1;
			this->tableLayoutPanel_Left->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel_Left->Controls->Add(this->flowLayoutPanel_UID, 0, 0);
			this->tableLayoutPanel_Left->Controls->Add(this->flowLayoutPanel_Date, 0, 1);
			this->tableLayoutPanel_Left->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel_Left->Font = (gcnew System::Drawing::Font(L"Cambria", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tableLayoutPanel_Left->Location = System::Drawing::Point(3, 3);
			this->tableLayoutPanel_Left->Name = L"tableLayoutPanel_Left";
			this->tableLayoutPanel_Left->RowCount = 2;
			this->tableLayoutPanel_Left->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				90)));
			this->tableLayoutPanel_Left->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel_Left->Size = System::Drawing::Size(264, 665);
			this->tableLayoutPanel_Left->TabIndex = 0;
			// 
			// flowLayoutPanel_UID
			// 
			this->flowLayoutPanel_UID->BackColor = System::Drawing::Color::Navy;
			this->flowLayoutPanel_UID->Controls->Add(this->label_OpName);
			this->flowLayoutPanel_UID->Controls->Add(this->textBox_Opname);
			this->flowLayoutPanel_UID->Dock = System::Windows::Forms::DockStyle::Fill;
			this->flowLayoutPanel_UID->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			this->flowLayoutPanel_UID->Location = System::Drawing::Point(3, 3);
			this->flowLayoutPanel_UID->Name = L"flowLayoutPanel_UID";
			this->flowLayoutPanel_UID->Size = System::Drawing::Size(258, 84);
			this->flowLayoutPanel_UID->TabIndex = 0;
			// 
			// label_OpName
			// 
			this->label_OpName->AutoSize = true;
			this->label_OpName->Font = (gcnew System::Drawing::Font(L"Cambria", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_OpName->ForeColor = System::Drawing::Color::White;
			this->label_OpName->Location = System::Drawing::Point(40, 8);
			this->label_OpName->Margin = System::Windows::Forms::Padding(40, 8, 4, 0);
			this->label_OpName->Name = L"label_OpName";
			this->label_OpName->Size = System::Drawing::Size(145, 22);
			this->label_OpName->TabIndex = 0;
			this->label_OpName->Text = L"CR Person Name";
			// 
			// textBox_Opname
			// 
			this->textBox_Opname->BackColor = System::Drawing::Color::LightBlue;
			this->textBox_Opname->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox_Opname->Location = System::Drawing::Point(8, 38);
			this->textBox_Opname->Margin = System::Windows::Forms::Padding(8, 8, 3, 3);
			this->textBox_Opname->Name = L"textBox_Opname";
			this->textBox_Opname->ReadOnly = true;
			this->textBox_Opname->Size = System::Drawing::Size(243, 26);
			this->textBox_Opname->TabIndex = 4;
			this->textBox_Opname->Text = L"123456789";
			this->textBox_Opname->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// flowLayoutPanel_Date
			// 
			this->flowLayoutPanel_Date->BackColor = System::Drawing::Color::Navy;
			this->flowLayoutPanel_Date->Controls->Add(this->panel0);
			this->flowLayoutPanel_Date->Controls->Add(this->panel1);
			this->flowLayoutPanel_Date->Controls->Add(this->panel2);
			this->flowLayoutPanel_Date->Controls->Add(this->panel3);
			this->flowLayoutPanel_Date->Controls->Add(this->panel4);
			this->flowLayoutPanel_Date->Controls->Add(this->panel5);
			this->flowLayoutPanel_Date->Controls->Add(this->panel6);
			this->flowLayoutPanel_Date->Controls->Add(this->panel7);
			this->flowLayoutPanel_Date->Controls->Add(this->panel8);
			this->flowLayoutPanel_Date->Controls->Add(this->panel9);
			this->flowLayoutPanel_Date->Controls->Add(this->panel_Btn);
			this->flowLayoutPanel_Date->Dock = System::Windows::Forms::DockStyle::Fill;
			this->flowLayoutPanel_Date->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			this->flowLayoutPanel_Date->Location = System::Drawing::Point(3, 93);
			this->flowLayoutPanel_Date->Name = L"flowLayoutPanel_Date";
			this->flowLayoutPanel_Date->Size = System::Drawing::Size(258, 570);
			this->flowLayoutPanel_Date->TabIndex = 1;
			// 
			// panel0
			// 
			this->panel0->BackColor = System::Drawing::Color::LightBlue;
			this->panel0->Controls->Add(this->label0);
			this->panel0->Location = System::Drawing::Point(8, 3);
			this->panel0->Margin = System::Windows::Forms::Padding(8, 3, 8, 3);
			this->panel0->Name = L"panel0";
			this->panel0->Size = System::Drawing::Size(243, 35);
			this->panel0->TabIndex = 9;
			this->panel0->Click += gcnew System::EventHandler(this, &OpenSCForm::label0_Click);
			// 
			// label0
			// 
			this->label0->AutoSize = true;
			this->label0->Font = (gcnew System::Drawing::Font(L"PMingLiU", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label0->Location = System::Drawing::Point(36, 9);
			this->label0->Name = L"label0";
			this->label0->Size = System::Drawing::Size(52, 16);
			this->label0->TabIndex = 0;
			this->label0->Text = L"label0";
			this->label0->Click += gcnew System::EventHandler(this, &OpenSCForm::label0_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::LightBlue;
			this->panel1->Controls->Add(this->label1);
			this->panel1->Location = System::Drawing::Point(8, 49);
			this->panel1->Margin = System::Windows::Forms::Padding(8, 8, 8, 3);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(243, 35);
			this->panel1->TabIndex = 0;
			this->panel1->Click += gcnew System::EventHandler(this, &OpenSCForm::label1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"PMingLiU", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label1->Location = System::Drawing::Point(36, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(52, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"label1";
			this->label1->Click += gcnew System::EventHandler(this, &OpenSCForm::label1_Click);
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::LightBlue;
			this->panel2->Controls->Add(this->label2);
			this->panel2->Location = System::Drawing::Point(8, 90);
			this->panel2->Margin = System::Windows::Forms::Padding(8, 3, 8, 3);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(243, 35);
			this->panel2->TabIndex = 1;
			this->panel2->Click += gcnew System::EventHandler(this, &OpenSCForm::label2_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"PMingLiU", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label2->Location = System::Drawing::Point(36, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(52, 16);
			this->label2->TabIndex = 0;
			this->label2->Text = L"label2";
			this->label2->Click += gcnew System::EventHandler(this, &OpenSCForm::label2_Click);
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::LightBlue;
			this->panel3->Controls->Add(this->label3);
			this->panel3->Location = System::Drawing::Point(8, 131);
			this->panel3->Margin = System::Windows::Forms::Padding(8, 3, 8, 3);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(243, 35);
			this->panel3->TabIndex = 2;
			this->panel3->Click += gcnew System::EventHandler(this, &OpenSCForm::label3_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"PMingLiU", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label3->Location = System::Drawing::Point(36, 9);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(52, 16);
			this->label3->TabIndex = 0;
			this->label3->Text = L"label3";
			this->label3->Click += gcnew System::EventHandler(this, &OpenSCForm::label3_Click);
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::Color::LightBlue;
			this->panel4->Controls->Add(this->label4);
			this->panel4->Location = System::Drawing::Point(8, 172);
			this->panel4->Margin = System::Windows::Forms::Padding(8, 3, 8, 3);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(243, 35);
			this->panel4->TabIndex = 3;
			this->panel4->Click += gcnew System::EventHandler(this, &OpenSCForm::label4_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"PMingLiU", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label4->Location = System::Drawing::Point(36, 9);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(52, 16);
			this->label4->TabIndex = 0;
			this->label4->Text = L"label4";
			this->label4->Click += gcnew System::EventHandler(this, &OpenSCForm::label4_Click);
			// 
			// panel5
			// 
			this->panel5->BackColor = System::Drawing::Color::LightBlue;
			this->panel5->Controls->Add(this->label5);
			this->panel5->Location = System::Drawing::Point(8, 213);
			this->panel5->Margin = System::Windows::Forms::Padding(8, 3, 8, 3);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(243, 35);
			this->panel5->TabIndex = 4;
			this->panel5->Click += gcnew System::EventHandler(this, &OpenSCForm::label5_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"PMingLiU", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label5->Location = System::Drawing::Point(36, 9);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(52, 16);
			this->label5->TabIndex = 0;
			this->label5->Text = L"label5";
			this->label5->Click += gcnew System::EventHandler(this, &OpenSCForm::label5_Click);
			// 
			// panel6
			// 
			this->panel6->BackColor = System::Drawing::Color::LightBlue;
			this->panel6->Controls->Add(this->label6);
			this->panel6->Location = System::Drawing::Point(8, 254);
			this->panel6->Margin = System::Windows::Forms::Padding(8, 3, 8, 3);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(243, 35);
			this->panel6->TabIndex = 5;
			this->panel6->Click += gcnew System::EventHandler(this, &OpenSCForm::label6_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"PMingLiU", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label6->Location = System::Drawing::Point(36, 9);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(52, 16);
			this->label6->TabIndex = 0;
			this->label6->Text = L"label6";
			this->label6->Click += gcnew System::EventHandler(this, &OpenSCForm::label6_Click);
			// 
			// panel7
			// 
			this->panel7->BackColor = System::Drawing::Color::LightBlue;
			this->panel7->Controls->Add(this->label7);
			this->panel7->Location = System::Drawing::Point(8, 295);
			this->panel7->Margin = System::Windows::Forms::Padding(8, 3, 8, 3);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(243, 35);
			this->panel7->TabIndex = 6;
			this->panel7->Click += gcnew System::EventHandler(this, &OpenSCForm::label7_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"PMingLiU", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label7->Location = System::Drawing::Point(36, 9);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(52, 16);
			this->label7->TabIndex = 0;
			this->label7->Text = L"label7";
			this->label7->Click += gcnew System::EventHandler(this, &OpenSCForm::label7_Click);
			// 
			// panel8
			// 
			this->panel8->BackColor = System::Drawing::Color::LightBlue;
			this->panel8->Controls->Add(this->label8);
			this->panel8->Location = System::Drawing::Point(8, 336);
			this->panel8->Margin = System::Windows::Forms::Padding(8, 3, 8, 3);
			this->panel8->Name = L"panel8";
			this->panel8->Size = System::Drawing::Size(243, 35);
			this->panel8->TabIndex = 7;
			this->panel8->Click += gcnew System::EventHandler(this, &OpenSCForm::label8_Click);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"PMingLiU", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label8->Location = System::Drawing::Point(36, 9);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(52, 16);
			this->label8->TabIndex = 0;
			this->label8->Text = L"label8";
			this->label8->Click += gcnew System::EventHandler(this, &OpenSCForm::label8_Click);
			// 
			// panel9
			// 
			this->panel9->BackColor = System::Drawing::Color::LightBlue;
			this->panel9->Controls->Add(this->label9);
			this->panel9->Location = System::Drawing::Point(8, 377);
			this->panel9->Margin = System::Windows::Forms::Padding(8, 3, 8, 3);
			this->panel9->Name = L"panel9";
			this->panel9->Size = System::Drawing::Size(243, 35);
			this->panel9->TabIndex = 8;
			this->panel9->Click += gcnew System::EventHandler(this, &OpenSCForm::label9_Click);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"PMingLiU", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label9->Location = System::Drawing::Point(36, 9);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(52, 16);
			this->label9->TabIndex = 0;
			this->label9->Text = L"label9";
			this->label9->Click += gcnew System::EventHandler(this, &OpenSCForm::label9_Click);
			// 
			// panel_Btn
			// 
			this->panel_Btn->BackColor = System::Drawing::Color::Navy;
			this->panel_Btn->Controls->Add(this->btn_NextPage);
			this->panel_Btn->Controls->Add(this->btn_PrePage);
			this->panel_Btn->Location = System::Drawing::Point(8, 423);
			this->panel_Btn->Margin = System::Windows::Forms::Padding(8);
			this->panel_Btn->Name = L"panel_Btn";
			this->panel_Btn->Size = System::Drawing::Size(243, 58);
			this->panel_Btn->TabIndex = 10;
			// 
			// btn_NextPage
			// 
			this->btn_NextPage->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_NextPage->Location = System::Drawing::Point(126, 3);
			this->btn_NextPage->Name = L"btn_NextPage";
			this->btn_NextPage->Size = System::Drawing::Size(114, 34);
			this->btn_NextPage->TabIndex = 1;
			this->btn_NextPage->Text = L"Next";
			this->btn_NextPage->UseVisualStyleBackColor = true;
			this->btn_NextPage->Click += gcnew System::EventHandler(this, &OpenSCForm::btn_NextPage_Click);
			// 
			// btn_PrePage
			// 
			this->btn_PrePage->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_PrePage->Location = System::Drawing::Point(3, 3);
			this->btn_PrePage->Name = L"btn_PrePage";
			this->btn_PrePage->Size = System::Drawing::Size(117, 34);
			this->btn_PrePage->TabIndex = 0;
			this->btn_PrePage->Text = L"Back";
			this->btn_PrePage->UseVisualStyleBackColor = true;
			this->btn_PrePage->Click += gcnew System::EventHandler(this, &OpenSCForm::btn_PrePage_Click);
			// 
			// flowLayoutPanel_Right
			// 
			this->flowLayoutPanel_Right->BackColor = System::Drawing::Color::Black;
			this->flowLayoutPanel_Right->Controls->Add(this->panel_Owner);
			this->flowLayoutPanel_Right->Controls->Add(this->panel_SpaSerial);
			this->flowLayoutPanel_Right->Controls->Add(this->panel_CRperson);
			this->flowLayoutPanel_Right->Controls->Add(this->panel_ErrMsg);
			this->flowLayoutPanel_Right->Controls->Add(this->panel_pCause);
			this->flowLayoutPanel_Right->Controls->Add(this->panel_Equipments);
			this->flowLayoutPanel_Right->Controls->Add(this->panel_SC);
			this->flowLayoutPanel_Right->Controls->Add(this->panel_replace);
			this->flowLayoutPanel_Right->Controls->Add(this->panel_comment);
			this->flowLayoutPanel_Right->Controls->Add(this->panel_button);
			this->flowLayoutPanel_Right->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			this->flowLayoutPanel_Right->Location = System::Drawing::Point(273, 3);
			this->flowLayoutPanel_Right->Name = L"flowLayoutPanel_Right";
			this->flowLayoutPanel_Right->Size = System::Drawing::Size(713, 665);
			this->flowLayoutPanel_Right->TabIndex = 1;
			// 
			// panel_Owner
			// 
			this->panel_Owner->BackColor = System::Drawing::Color::Teal;
			this->panel_Owner->Controls->Add(this->textBox_UID);
			this->panel_Owner->Controls->Add(this->lbl_UID);
			this->panel_Owner->Controls->Add(this->textBox_owner);
			this->panel_Owner->Controls->Add(this->lbl_owner);
			this->panel_Owner->Location = System::Drawing::Point(1, 1);
			this->panel_Owner->Margin = System::Windows::Forms::Padding(1);
			this->panel_Owner->Name = L"panel_Owner";
			this->panel_Owner->Size = System::Drawing::Size(710, 45);
			this->panel_Owner->TabIndex = 4;
			// 
			// textBox_UID
			// 
			this->textBox_UID->BackColor = System::Drawing::Color::LightBlue;
			this->textBox_UID->Font = (gcnew System::Drawing::Font(L"Cambria", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox_UID->Location = System::Drawing::Point(100, 9);
			this->textBox_UID->Name = L"textBox_UID";
			this->textBox_UID->ReadOnly = true;
			this->textBox_UID->Size = System::Drawing::Size(290, 30);
			this->textBox_UID->TabIndex = 4;
			this->textBox_UID->Text = L"123456789";
			this->textBox_UID->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// lbl_UID
			// 
			this->lbl_UID->AutoSize = true;
			this->lbl_UID->Font = (gcnew System::Drawing::Font(L"Cambria", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_UID->ForeColor = System::Drawing::Color::White;
			this->lbl_UID->Location = System::Drawing::Point(30, 10);
			this->lbl_UID->Name = L"lbl_UID";
			this->lbl_UID->Size = System::Drawing::Size(47, 25);
			this->lbl_UID->TabIndex = 3;
			this->lbl_UID->Text = L"UID";
			// 
			// textBox_owner
			// 
			this->textBox_owner->BackColor = System::Drawing::Color::LightBlue;
			this->textBox_owner->Font = (gcnew System::Drawing::Font(L"Cambria", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox_owner->Location = System::Drawing::Point(494, 9);
			this->textBox_owner->Name = L"textBox_owner";
			this->textBox_owner->ReadOnly = true;
			this->textBox_owner->Size = System::Drawing::Size(186, 30);
			this->textBox_owner->TabIndex = 2;
			this->textBox_owner->Text = L"123456789";
			this->textBox_owner->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// lbl_owner
			// 
			this->lbl_owner->AutoSize = true;
			this->lbl_owner->Font = (gcnew System::Drawing::Font(L"Cambria", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_owner->ForeColor = System::Drawing::Color::White;
			this->lbl_owner->Location = System::Drawing::Point(408, 10);
			this->lbl_owner->Name = L"lbl_owner";
			this->lbl_owner->Size = System::Drawing::Size(73, 25);
			this->lbl_owner->TabIndex = 0;
			this->lbl_owner->Text = L"Owner";
			// 
			// panel_SpaSerial
			// 
			this->panel_SpaSerial->BackColor = System::Drawing::Color::Teal;
			this->panel_SpaSerial->Controls->Add(this->textBox_HotTub);
			this->panel_SpaSerial->Controls->Add(this->textBox_SpaSerial);
			this->panel_SpaSerial->Controls->Add(this->lbl_HotTub);
			this->panel_SpaSerial->Controls->Add(this->lbl_SpaSerial);
			this->panel_SpaSerial->Location = System::Drawing::Point(1, 48);
			this->panel_SpaSerial->Margin = System::Windows::Forms::Padding(1);
			this->panel_SpaSerial->Name = L"panel_SpaSerial";
			this->panel_SpaSerial->Size = System::Drawing::Size(710, 45);
			this->panel_SpaSerial->TabIndex = 0;
			// 
			// textBox_HotTub
			// 
			this->textBox_HotTub->BackColor = System::Drawing::Color::LightBlue;
			this->textBox_HotTub->Font = (gcnew System::Drawing::Font(L"Cambria", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox_HotTub->Location = System::Drawing::Point(496, 8);
			this->textBox_HotTub->Name = L"textBox_HotTub";
			this->textBox_HotTub->ReadOnly = true;
			this->textBox_HotTub->Size = System::Drawing::Size(199, 30);
			this->textBox_HotTub->TabIndex = 3;
			this->textBox_HotTub->Text = L"123456789";
			this->textBox_HotTub->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox_SpaSerial
			// 
			this->textBox_SpaSerial->BackColor = System::Drawing::Color::LightBlue;
			this->textBox_SpaSerial->Font = (gcnew System::Drawing::Font(L"Cambria", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox_SpaSerial->Location = System::Drawing::Point(127, 8);
			this->textBox_SpaSerial->Name = L"textBox_SpaSerial";
			this->textBox_SpaSerial->ReadOnly = true;
			this->textBox_SpaSerial->Size = System::Drawing::Size(186, 30);
			this->textBox_SpaSerial->TabIndex = 2;
			this->textBox_SpaSerial->Text = L"123456789";
			this->textBox_SpaSerial->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// lbl_HotTub
			// 
			this->lbl_HotTub->AutoSize = true;
			this->lbl_HotTub->Font = (gcnew System::Drawing::Font(L"Cambria", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_HotTub->ForeColor = System::Drawing::Color::White;
			this->lbl_HotTub->Location = System::Drawing::Point(327, 10);
			this->lbl_HotTub->Name = L"lbl_HotTub";
			this->lbl_HotTub->Size = System::Drawing::Size(163, 25);
			this->lbl_HotTub->TabIndex = 1;
			this->lbl_HotTub->Text = L"Hot Tub Model #";
			// 
			// lbl_SpaSerial
			// 
			this->lbl_SpaSerial->AutoSize = true;
			this->lbl_SpaSerial->Font = (gcnew System::Drawing::Font(L"Cambria", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_SpaSerial->ForeColor = System::Drawing::Color::White;
			this->lbl_SpaSerial->Location = System::Drawing::Point(3, 10);
			this->lbl_SpaSerial->Name = L"lbl_SpaSerial";
			this->lbl_SpaSerial->Size = System::Drawing::Size(118, 25);
			this->lbl_SpaSerial->TabIndex = 0;
			this->lbl_SpaSerial->Text = L"Spa Serial #";
			// 
			// panel_CRperson
			// 
			this->panel_CRperson->BackColor = System::Drawing::Color::Teal;
			this->panel_CRperson->Controls->Add(this->textBox_CRperson);
			this->panel_CRperson->Controls->Add(this->textBox_Date);
			this->panel_CRperson->Controls->Add(this->label13);
			this->panel_CRperson->Controls->Add(this->lbl_Date);
			this->panel_CRperson->Location = System::Drawing::Point(1, 95);
			this->panel_CRperson->Margin = System::Windows::Forms::Padding(1);
			this->panel_CRperson->Name = L"panel_CRperson";
			this->panel_CRperson->Size = System::Drawing::Size(710, 45);
			this->panel_CRperson->TabIndex = 5;
			// 
			// textBox_CRperson
			// 
			this->textBox_CRperson->BackColor = System::Drawing::Color::LightBlue;
			this->textBox_CRperson->Font = (gcnew System::Drawing::Font(L"Cambria", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox_CRperson->Location = System::Drawing::Point(496, 8);
			this->textBox_CRperson->Name = L"textBox_CRperson";
			this->textBox_CRperson->ReadOnly = true;
			this->textBox_CRperson->Size = System::Drawing::Size(199, 30);
			this->textBox_CRperson->TabIndex = 3;
			this->textBox_CRperson->Text = L"123456789";
			this->textBox_CRperson->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox_Date
			// 
			this->textBox_Date->BackColor = System::Drawing::Color::LightBlue;
			this->textBox_Date->Font = (gcnew System::Drawing::Font(L"Cambria", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox_Date->Location = System::Drawing::Point(127, 8);
			this->textBox_Date->Name = L"textBox_Date";
			this->textBox_Date->ReadOnly = true;
			this->textBox_Date->Size = System::Drawing::Size(186, 30);
			this->textBox_Date->TabIndex = 2;
			this->textBox_Date->Text = L"123456789";
			this->textBox_Date->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Cambria", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label13->ForeColor = System::Drawing::Color::White;
			this->label13->Location = System::Drawing::Point(350, 10);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(113, 25);
			this->label13->TabIndex = 1;
			this->label13->Text = L"C.R. Person";
			// 
			// lbl_Date
			// 
			this->lbl_Date->AutoSize = true;
			this->lbl_Date->Font = (gcnew System::Drawing::Font(L"Cambria", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Date->ForeColor = System::Drawing::Color::White;
			this->lbl_Date->Location = System::Drawing::Point(34, 10);
			this->lbl_Date->Name = L"lbl_Date";
			this->lbl_Date->Size = System::Drawing::Size(53, 25);
			this->lbl_Date->TabIndex = 0;
			this->lbl_Date->Text = L"Date";
			// 
			// panel_ErrMsg
			// 
			this->panel_ErrMsg->BackColor = System::Drawing::Color::Teal;
			this->panel_ErrMsg->Controls->Add(this->textBox_ErrMsg);
			this->panel_ErrMsg->Controls->Add(this->lbl_ErrMsg);
			this->panel_ErrMsg->Location = System::Drawing::Point(1, 142);
			this->panel_ErrMsg->Margin = System::Windows::Forms::Padding(1);
			this->panel_ErrMsg->Name = L"panel_ErrMsg";
			this->panel_ErrMsg->Size = System::Drawing::Size(710, 60);
			this->panel_ErrMsg->TabIndex = 5;
			// 
			// textBox_ErrMsg
			// 
			this->textBox_ErrMsg->BackColor = System::Drawing::Color::LightBlue;
			this->textBox_ErrMsg->Font = (gcnew System::Drawing::Font(L"Cambria", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox_ErrMsg->Location = System::Drawing::Point(167, 8);
			this->textBox_ErrMsg->Name = L"textBox_ErrMsg";
			this->textBox_ErrMsg->ReadOnly = true;
			this->textBox_ErrMsg->Size = System::Drawing::Size(528, 41);
			this->textBox_ErrMsg->TabIndex = 2;
			this->textBox_ErrMsg->Text = L"123, 123, 123, 123";
			this->textBox_ErrMsg->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// lbl_ErrMsg
			// 
			this->lbl_ErrMsg->AutoSize = true;
			this->lbl_ErrMsg->Font = (gcnew System::Drawing::Font(L"Cambria", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_ErrMsg->ForeColor = System::Drawing::Color::White;
			this->lbl_ErrMsg->Location = System::Drawing::Point(14, 18);
			this->lbl_ErrMsg->Name = L"lbl_ErrMsg";
			this->lbl_ErrMsg->Size = System::Drawing::Size(147, 25);
			this->lbl_ErrMsg->TabIndex = 0;
			this->lbl_ErrMsg->Text = L"Error Message ";
			// 
			// panel_pCause
			// 
			this->panel_pCause->BackColor = System::Drawing::Color::Teal;
			this->panel_pCause->Controls->Add(this->textBox_pCause);
			this->panel_pCause->Controls->Add(this->lbl_pCause);
			this->panel_pCause->Location = System::Drawing::Point(1, 204);
			this->panel_pCause->Margin = System::Windows::Forms::Padding(1);
			this->panel_pCause->Name = L"panel_pCause";
			this->panel_pCause->Size = System::Drawing::Size(710, 59);
			this->panel_pCause->TabIndex = 6;
			// 
			// textBox_pCause
			// 
			this->textBox_pCause->BackColor = System::Drawing::Color::LightBlue;
			this->textBox_pCause->Font = (gcnew System::Drawing::Font(L"Cambria", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox_pCause->Location = System::Drawing::Point(223, 9);
			this->textBox_pCause->Name = L"textBox_pCause";
			this->textBox_pCause->ReadOnly = true;
			this->textBox_pCause->Size = System::Drawing::Size(472, 41);
			this->textBox_pCause->TabIndex = 2;
			this->textBox_pCause->Text = L"123456789, 123456789";
			this->textBox_pCause->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// lbl_pCause
			// 
			this->lbl_pCause->AutoSize = true;
			this->lbl_pCause->Font = (gcnew System::Drawing::Font(L"Cambria", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_pCause->ForeColor = System::Drawing::Color::White;
			this->lbl_pCause->Location = System::Drawing::Point(14, 20);
			this->lbl_pCause->Name = L"lbl_pCause";
			this->lbl_pCause->Size = System::Drawing::Size(192, 25);
			this->lbl_pCause->TabIndex = 0;
			this->lbl_pCause->Text = L"Possible Root Cause";
			// 
			// panel_Equipments
			// 
			this->panel_Equipments->BackColor = System::Drawing::Color::Teal;
			this->panel_Equipments->Controls->Add(this->richTextBox_Equipment);
			this->panel_Equipments->Controls->Add(this->lbl_Equipments);
			this->panel_Equipments->Location = System::Drawing::Point(1, 265);
			this->panel_Equipments->Margin = System::Windows::Forms::Padding(1);
			this->panel_Equipments->Name = L"panel_Equipments";
			this->panel_Equipments->Size = System::Drawing::Size(710, 103);
			this->panel_Equipments->TabIndex = 5;
			// 
			// richTextBox_Equipment
			// 
			this->richTextBox_Equipment->BackColor = System::Drawing::Color::LightBlue;
			this->richTextBox_Equipment->Font = (gcnew System::Drawing::Font(L"Cambria", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->richTextBox_Equipment->Location = System::Drawing::Point(14, 33);
			this->richTextBox_Equipment->Name = L"richTextBox_Equipment";
			this->richTextBox_Equipment->ReadOnly = true;
			this->richTextBox_Equipment->Size = System::Drawing::Size(681, 63);
			this->richTextBox_Equipment->TabIndex = 1;
			this->richTextBox_Equipment->Text = L"";
			// 
			// lbl_Equipments
			// 
			this->lbl_Equipments->AutoSize = true;
			this->lbl_Equipments->Font = (gcnew System::Drawing::Font(L"Cambria", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Equipments->ForeColor = System::Drawing::Color::White;
			this->lbl_Equipments->Location = System::Drawing::Point(14, 4);
			this->lbl_Equipments->Name = L"lbl_Equipments";
			this->lbl_Equipments->Size = System::Drawing::Size(291, 25);
			this->lbl_Equipments->TabIndex = 0;
			this->lbl_Equipments->Text = L"Equipments for On-Site Service";
			// 
			// panel_SC
			// 
			this->panel_SC->BackColor = System::Drawing::Color::Teal;
			this->panel_SC->Controls->Add(this->textBox_SCstr);
			this->panel_SC->Controls->Add(this->lbl_SC);
			this->panel_SC->Location = System::Drawing::Point(1, 370);
			this->panel_SC->Margin = System::Windows::Forms::Padding(1);
			this->panel_SC->Name = L"panel_SC";
			this->panel_SC->Size = System::Drawing::Size(710, 52);
			this->panel_SC->TabIndex = 6;
			// 
			// textBox_SCstr
			// 
			this->textBox_SCstr->BackColor = System::Drawing::Color::LightBlue;
			this->textBox_SCstr->Font = (gcnew System::Drawing::Font(L"Cambria", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox_SCstr->Location = System::Drawing::Point(167, 10);
			this->textBox_SCstr->Name = L"textBox_SCstr";
			this->textBox_SCstr->ReadOnly = true;
			this->textBox_SCstr->Size = System::Drawing::Size(528, 30);
			this->textBox_SCstr->TabIndex = 2;
			this->textBox_SCstr->Text = L"123, 123, 123, 123";
			this->textBox_SCstr->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// lbl_SC
			// 
			this->lbl_SC->AutoSize = true;
			this->lbl_SC->Font = (gcnew System::Drawing::Font(L"Cambria", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_SC->ForeColor = System::Drawing::Color::White;
			this->lbl_SC->Location = System::Drawing::Point(14, 11);
			this->lbl_SC->Name = L"lbl_SC";
			this->lbl_SC->Size = System::Drawing::Size(134, 25);
			this->lbl_SC->TabIndex = 0;
			this->lbl_SC->Text = L"Service Call #";
			// 
			// panel_replace
			// 
			this->panel_replace->BackColor = System::Drawing::Color::SeaGreen;
			this->panel_replace->Controls->Add(this->richTextBox_replace);
			this->panel_replace->Controls->Add(this->lbl_replace);
			this->panel_replace->Location = System::Drawing::Point(1, 424);
			this->panel_replace->Margin = System::Windows::Forms::Padding(1);
			this->panel_replace->Name = L"panel_replace";
			this->panel_replace->Size = System::Drawing::Size(710, 79);
			this->panel_replace->TabIndex = 6;
			// 
			// richTextBox_replace
			// 
			this->richTextBox_replace->BackColor = System::Drawing::Color::White;
			this->richTextBox_replace->Font = (gcnew System::Drawing::Font(L"Cambria", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->richTextBox_replace->Location = System::Drawing::Point(167, 7);
			this->richTextBox_replace->Name = L"richTextBox_replace";
			this->richTextBox_replace->Size = System::Drawing::Size(528, 63);
			this->richTextBox_replace->TabIndex = 1;
			this->richTextBox_replace->Text = L"";
			// 
			// lbl_replace
			// 
			this->lbl_replace->AutoSize = true;
			this->lbl_replace->Font = (gcnew System::Drawing::Font(L"Cambria", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_replace->ForeColor = System::Drawing::Color::White;
			this->lbl_replace->Location = System::Drawing::Point(14, 24);
			this->lbl_replace->Name = L"lbl_replace";
			this->lbl_replace->Size = System::Drawing::Size(146, 25);
			this->lbl_replace->TabIndex = 0;
			this->lbl_replace->Text = L"Replaced Parts";
			// 
			// panel_comment
			// 
			this->panel_comment->BackColor = System::Drawing::Color::SeaGreen;
			this->panel_comment->Controls->Add(this->richTextBox_comment);
			this->panel_comment->Controls->Add(this->label_comment);
			this->panel_comment->Location = System::Drawing::Point(1, 505);
			this->panel_comment->Margin = System::Windows::Forms::Padding(1);
			this->panel_comment->Name = L"panel_comment";
			this->panel_comment->Size = System::Drawing::Size(710, 79);
			this->panel_comment->TabIndex = 7;
			// 
			// richTextBox_comment
			// 
			this->richTextBox_comment->BackColor = System::Drawing::Color::White;
			this->richTextBox_comment->Font = (gcnew System::Drawing::Font(L"Cambria", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->richTextBox_comment->Location = System::Drawing::Point(167, 7);
			this->richTextBox_comment->Name = L"richTextBox_comment";
			this->richTextBox_comment->Size = System::Drawing::Size(528, 63);
			this->richTextBox_comment->TabIndex = 1;
			this->richTextBox_comment->Text = L"";
			// 
			// label_comment
			// 
			this->label_comment->AutoSize = true;
			this->label_comment->Font = (gcnew System::Drawing::Font(L"Cambria", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_comment->ForeColor = System::Drawing::Color::White;
			this->label_comment->Location = System::Drawing::Point(34, 25);
			this->label_comment->Name = L"label_comment";
			this->label_comment->Size = System::Drawing::Size(98, 25);
			this->label_comment->TabIndex = 0;
			this->label_comment->Text = L"Comment";
			// 
			// panel_button
			// 
			this->panel_button->BackColor = System::Drawing::Color::SteelBlue;
			this->panel_button->Controls->Add(this->button_fullReport);
			this->panel_button->Controls->Add(this->button_SaveDelete);
			this->panel_button->Location = System::Drawing::Point(1, 586);
			this->panel_button->Margin = System::Windows::Forms::Padding(1);
			this->panel_button->Name = L"panel_button";
			this->panel_button->Size = System::Drawing::Size(710, 61);
			this->panel_button->TabIndex = 7;
			// 
			// button_fullReport
			// 
			this->button_fullReport->Font = (gcnew System::Drawing::Font(L"Cambria", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_fullReport->Location = System::Drawing::Point(77, 13);
			this->button_fullReport->Name = L"button_fullReport";
			this->button_fullReport->Size = System::Drawing::Size(267, 35);
			this->button_fullReport->TabIndex = 2;
			this->button_fullReport->Text = L"RDS Full Report";
			this->button_fullReport->UseVisualStyleBackColor = true;
			this->button_fullReport->Click += gcnew System::EventHandler(this, &OpenSCForm::button_fullReport_Click);
			// 
			// button_SaveDelete
			// 
			this->button_SaveDelete->Font = (gcnew System::Drawing::Font(L"Cambria", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_SaveDelete->Location = System::Drawing::Point(371, 13);
			this->button_SaveDelete->Name = L"button_SaveDelete";
			this->button_SaveDelete->Size = System::Drawing::Size(267, 35);
			this->button_SaveDelete->TabIndex = 1;
			this->button_SaveDelete->Text = L"Save and Close Service Call";
			this->button_SaveDelete->UseVisualStyleBackColor = true;
			this->button_SaveDelete->Click += gcnew System::EventHandler(this, &OpenSCForm::button_SaveDelete_Click);
			// 
			// OpenSCForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(986, 671);
			this->Controls->Add(this->tableLayoutPanel_BG);
			this->Name = L"OpenSCForm";
			this->Text = L"My Open Service Call List";
			this->TopMost = true;
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &OpenSCForm::OpenSCForm_FormClosed);
			this->Load += gcnew System::EventHandler(this, &OpenSCForm::OpenSCForm_Load);
			this->tableLayoutPanel_BG->ResumeLayout(false);
			this->tableLayoutPanel_Left->ResumeLayout(false);
			this->flowLayoutPanel_UID->ResumeLayout(false);
			this->flowLayoutPanel_UID->PerformLayout();
			this->flowLayoutPanel_Date->ResumeLayout(false);
			this->panel0->ResumeLayout(false);
			this->panel0->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			this->panel5->ResumeLayout(false);
			this->panel5->PerformLayout();
			this->panel6->ResumeLayout(false);
			this->panel6->PerformLayout();
			this->panel7->ResumeLayout(false);
			this->panel7->PerformLayout();
			this->panel8->ResumeLayout(false);
			this->panel8->PerformLayout();
			this->panel9->ResumeLayout(false);
			this->panel9->PerformLayout();
			this->panel_Btn->ResumeLayout(false);
			this->flowLayoutPanel_Right->ResumeLayout(false);
			this->panel_Owner->ResumeLayout(false);
			this->panel_Owner->PerformLayout();
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
			this->panel_SC->ResumeLayout(false);
			this->panel_SC->PerformLayout();
			this->panel_replace->ResumeLayout(false);
			this->panel_replace->PerformLayout();
			this->panel_comment->ResumeLayout(false);
			this->panel_comment->PerformLayout();
			this->panel_button->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
		//for directory scan
private:	void initial_display();
public:		int getList(int page, String^ CRperson_No);
private:	void showBriefReport(String^ readFileName);
private:	void save_del_SC(String^ readFileName);

private: System::Void OpenSCForm_Load(System::Object^  sender, System::EventArgs^  e);
private: System::Void label0_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void label3_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void label4_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void label5_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void label6_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void label7_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void label8_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void label9_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void btn_PrePage_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void btn_NextPage_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void button_fullReport_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void button_SaveDelete_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void OpenSCForm_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e);
};
}
