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
	/// Summary for HistLogForm
	/// </summary>
	public ref class HistLogForm : public System::Windows::Forms::Form
	{
	public:
		HistLogForm(RDS_main_Form^ pForm)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			m_MainForm = pForm;
		}
	public: RDS_main_Form^ m_MainForm;

			//for RDS report/ service call...
			String^ Base_dir;

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

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~HistLogForm()
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
	private: System::Windows::Forms::Label^  label_UID;
	private: System::Windows::Forms::TextBox^  textBox_UID_in;
	private: System::Windows::Forms::Button^  btn_ToReportList;
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
	private: System::Windows::Forms::Panel^  panel_Equipments;
	private: System::Windows::Forms::RichTextBox^  richTextBox_Log;
	private: System::Windows::Forms::Label^  lbl_Time;
	private: System::Windows::Forms::Label^  lbll_ActLog;

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
			this->label_UID = (gcnew System::Windows::Forms::Label());
			this->textBox_UID_in = (gcnew System::Windows::Forms::TextBox());
			this->btn_ToReportList = (gcnew System::Windows::Forms::Button());
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
			this->panel_Equipments = (gcnew System::Windows::Forms::Panel());
			this->lbll_ActLog = (gcnew System::Windows::Forms::Label());
			this->richTextBox_Log = (gcnew System::Windows::Forms::RichTextBox());
			this->lbl_Time = (gcnew System::Windows::Forms::Label());
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
			this->panel_Equipments->SuspendLayout();
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
			this->tableLayoutPanel_BG->Size = System::Drawing::Size(987, 619);
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
				130)));
			this->tableLayoutPanel_Left->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel_Left->Size = System::Drawing::Size(264, 613);
			this->tableLayoutPanel_Left->TabIndex = 0;
			// 
			// flowLayoutPanel_UID
			// 
			this->flowLayoutPanel_UID->BackColor = System::Drawing::Color::Navy;
			this->flowLayoutPanel_UID->Controls->Add(this->label_UID);
			this->flowLayoutPanel_UID->Controls->Add(this->textBox_UID_in);
			this->flowLayoutPanel_UID->Controls->Add(this->btn_ToReportList);
			this->flowLayoutPanel_UID->Dock = System::Windows::Forms::DockStyle::Fill;
			this->flowLayoutPanel_UID->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			this->flowLayoutPanel_UID->Location = System::Drawing::Point(3, 3);
			this->flowLayoutPanel_UID->Name = L"flowLayoutPanel_UID";
			this->flowLayoutPanel_UID->Size = System::Drawing::Size(258, 124);
			this->flowLayoutPanel_UID->TabIndex = 0;
			// 
			// label_UID
			// 
			this->label_UID->AutoSize = true;
			this->label_UID->Font = (gcnew System::Drawing::Font(L"Cambria", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_UID->ForeColor = System::Drawing::Color::White;
			this->label_UID->Location = System::Drawing::Point(40, 8);
			this->label_UID->Margin = System::Windows::Forms::Padding(40, 8, 4, 0);
			this->label_UID->Name = L"label_UID";
			this->label_UID->Size = System::Drawing::Size(148, 22);
			this->label_UID->TabIndex = 0;
			this->label_UID->Text = L"Spa Wireless UID";
			// 
			// textBox_UID_in
			// 
			this->textBox_UID_in->BackColor = System::Drawing::Color::LightBlue;
			this->textBox_UID_in->Font = (gcnew System::Drawing::Font(L"AVGmdBU", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox_UID_in->Location = System::Drawing::Point(8, 38);
			this->textBox_UID_in->Margin = System::Windows::Forms::Padding(8, 8, 3, 3);
			this->textBox_UID_in->Name = L"textBox_UID_in";
			this->textBox_UID_in->ReadOnly = true;
			this->textBox_UID_in->Size = System::Drawing::Size(238, 24);
			this->textBox_UID_in->TabIndex = 1;
			this->textBox_UID_in->Text = L"FVC91WZP6JAUVN6PMXKJ";
			this->textBox_UID_in->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// btn_ToReportList
			// 
			this->btn_ToReportList->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_ToReportList->Location = System::Drawing::Point(20, 73);
			this->btn_ToReportList->Margin = System::Windows::Forms::Padding(20, 8, 2, 2);
			this->btn_ToReportList->Name = L"btn_ToReportList";
			this->btn_ToReportList->Size = System::Drawing::Size(207, 46);
			this->btn_ToReportList->TabIndex = 2;
			this->btn_ToReportList->Text = L"RDS Report List";
			this->btn_ToReportList->UseVisualStyleBackColor = true;
			this->btn_ToReportList->Click += gcnew System::EventHandler(this, &HistLogForm::btn_ToReportList_Click);
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
			this->flowLayoutPanel_Date->Location = System::Drawing::Point(3, 133);
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
			this->panel0->Click += gcnew System::EventHandler(this, &HistLogForm::label0_Click);
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
			this->label0->Click += gcnew System::EventHandler(this, &HistLogForm::label0_Click);
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
			this->panel1->Click += gcnew System::EventHandler(this, &HistLogForm::label1_Click);
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
			this->label1->Click += gcnew System::EventHandler(this, &HistLogForm::label1_Click);
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
			this->panel2->Click += gcnew System::EventHandler(this, &HistLogForm::label2_Click);
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
			this->label2->Click += gcnew System::EventHandler(this, &HistLogForm::label2_Click);
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
			this->panel3->Click += gcnew System::EventHandler(this, &HistLogForm::label3_Click);
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
			this->label3->Click += gcnew System::EventHandler(this, &HistLogForm::label3_Click);
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
			this->panel4->Click += gcnew System::EventHandler(this, &HistLogForm::label4_Click);
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
			this->label4->Click += gcnew System::EventHandler(this, &HistLogForm::label4_Click);
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
			this->panel5->Click += gcnew System::EventHandler(this, &HistLogForm::label5_Click);
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
			this->label5->Click += gcnew System::EventHandler(this, &HistLogForm::label5_Click);
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
			this->panel6->Click += gcnew System::EventHandler(this, &HistLogForm::label6_Click);
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
			this->label6->Click += gcnew System::EventHandler(this, &HistLogForm::label6_Click);
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
			this->panel7->Click += gcnew System::EventHandler(this, &HistLogForm::label7_Click);
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
			this->label7->Click += gcnew System::EventHandler(this, &HistLogForm::label7_Click);
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
			this->panel8->Click += gcnew System::EventHandler(this, &HistLogForm::label8_Click);
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
			this->label8->Click += gcnew System::EventHandler(this, &HistLogForm::label8_Click);
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
			this->panel9->Click += gcnew System::EventHandler(this, &HistLogForm::label9_Click);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"PMingLiU", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label9->Location = System::Drawing::Point(36, 10);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(52, 16);
			this->label9->TabIndex = 0;
			this->label9->Text = L"label9";
			this->label9->Click += gcnew System::EventHandler(this, &HistLogForm::label9_Click);
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
			this->btn_NextPage->Click += gcnew System::EventHandler(this, &HistLogForm::btn_NextPage_Click);
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
			this->btn_PrePage->Click += gcnew System::EventHandler(this, &HistLogForm::btn_PrePage_Click);
			// 
			// flowLayoutPanel_Right
			// 
			this->flowLayoutPanel_Right->BackColor = System::Drawing::Color::Black;
			this->flowLayoutPanel_Right->Controls->Add(this->panel_Equipments);
			this->flowLayoutPanel_Right->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			this->flowLayoutPanel_Right->Location = System::Drawing::Point(273, 3);
			this->flowLayoutPanel_Right->Name = L"flowLayoutPanel_Right";
			this->flowLayoutPanel_Right->Size = System::Drawing::Size(713, 613);
			this->flowLayoutPanel_Right->TabIndex = 1;
			// 
			// panel_Equipments
			// 
			this->panel_Equipments->BackColor = System::Drawing::Color::Teal;
			this->panel_Equipments->Controls->Add(this->lbll_ActLog);
			this->panel_Equipments->Controls->Add(this->richTextBox_Log);
			this->panel_Equipments->Controls->Add(this->lbl_Time);
			this->panel_Equipments->Location = System::Drawing::Point(1, 1);
			this->panel_Equipments->Margin = System::Windows::Forms::Padding(1);
			this->panel_Equipments->Name = L"panel_Equipments";
			this->panel_Equipments->Size = System::Drawing::Size(710, 612);
			this->panel_Equipments->TabIndex = 5;
			// 
			// lbll_ActLog
			// 
			this->lbll_ActLog->AutoSize = true;
			this->lbll_ActLog->Font = (gcnew System::Drawing::Font(L"Cambria", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbll_ActLog->ForeColor = System::Drawing::Color::White;
			this->lbll_ActLog->Location = System::Drawing::Point(135, 4);
			this->lbll_ActLog->Name = L"lbll_ActLog";
			this->lbll_ActLog->Size = System::Drawing::Size(112, 25);
			this->lbll_ActLog->TabIndex = 2;
			this->lbll_ActLog->Text = L"Operations";
			// 
			// richTextBox_Log
			// 
			this->richTextBox_Log->BackColor = System::Drawing::Color::LightBlue;
			this->richTextBox_Log->Font = (gcnew System::Drawing::Font(L"Cambria", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->richTextBox_Log->Location = System::Drawing::Point(3, 33);
			this->richTextBox_Log->Name = L"richTextBox_Log";
			this->richTextBox_Log->ReadOnly = true;
			this->richTextBox_Log->Size = System::Drawing::Size(704, 570);
			this->richTextBox_Log->TabIndex = 1;
			this->richTextBox_Log->Text = L"";
			// 
			// lbl_Time
			// 
			this->lbl_Time->AutoSize = true;
			this->lbl_Time->Font = (gcnew System::Drawing::Font(L"Cambria", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Time->ForeColor = System::Drawing::Color::White;
			this->lbl_Time->Location = System::Drawing::Point(14, 4);
			this->lbl_Time->Name = L"lbl_Time";
			this->lbl_Time->Size = System::Drawing::Size(57, 25);
			this->lbl_Time->TabIndex = 0;
			this->lbl_Time->Text = L"Time";
			// 
			// HistLogForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(987, 619);
			this->Controls->Add(this->tableLayoutPanel_BG);
			this->Name = L"HistLogForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"History of Operation Records";
			this->TopMost = true;
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &HistLogForm::HistLogForm_FormClosed);
			this->Load += gcnew System::EventHandler(this, &HistLogForm::HistLogForm_Load);
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
			this->panel_Equipments->ResumeLayout(false);
			this->panel_Equipments->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

	//for directory scan
public:		int getList(int page, String^ UID);
private:	void showBriefReport(String^ readFileName); //show Log report
			void initial_display();

private: System::Void btn_ToReportList_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void HistLogForm_Load(System::Object^  sender, System::EventArgs^  e);
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
private: System::Void HistLogForm_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e);
};
}
