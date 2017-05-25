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
	/// Summary for EH_Form
	/// </summary>
	public ref class EH_Form : public System::Windows::Forms::Form
	{
	public:
		EH_Form(RDS_main_Form^ pForm)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			m_MainForm = pForm;
		}
	public: System::Windows::Forms::DataGridView^  dataGridView_EH;
	public:

	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  list_No;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  errCode;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  errStartTime;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  errEndTime;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  errHiLiTemper;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  errWaterTemper;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  errPCB_Temper;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^  err_P1_Lo;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^  err_P1_Hi;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^  err_P2_Lo;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^  err_P2_Hi;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^  err_P3_Lo;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^  err_P3_Hi;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^  err_Blower;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^  err_Circ;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^  err_UV;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^  err_Heater;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^  err_Ozon;

	public: RDS_main_Form^ m_MainForm;
			//for two-set of ErrorCode
			unsigned char ECset;

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~EH_Form()
		{
			if (components)
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
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle5 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle6 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle7 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->dataGridView_EH = (gcnew System::Windows::Forms::DataGridView());
			this->list_No = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->errCode = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->errStartTime = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->errEndTime = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->errHiLiTemper = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->errWaterTemper = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->errPCB_Temper = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->err_P1_Lo = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
			this->err_P1_Hi = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
			this->err_P2_Lo = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
			this->err_P2_Hi = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
			this->err_P3_Lo = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
			this->err_P3_Hi = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
			this->err_Blower = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
			this->err_Circ = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
			this->err_UV = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
			this->err_Heater = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
			this->err_Ozon = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_EH))->BeginInit();
			this->tableLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// dataGridView_EH
			// 
			this->dataGridView_EH->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView_EH->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(18) {
				this->list_No,
					this->errCode, this->errStartTime, this->errEndTime, this->errHiLiTemper, this->errWaterTemper, this->errPCB_Temper, this->err_P1_Lo,
					this->err_P1_Hi, this->err_P2_Lo, this->err_P2_Hi, this->err_P3_Lo, this->err_P3_Hi, this->err_Blower, this->err_Circ, this->err_UV,
					this->err_Heater, this->err_Ozon
			});
			this->dataGridView_EH->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView_EH->Location = System::Drawing::Point(3, 53);
			this->dataGridView_EH->Name = L"dataGridView_EH";
			this->dataGridView_EH->RowTemplate->Height = 24;
			this->dataGridView_EH->Size = System::Drawing::Size(1051, 441);
			this->dataGridView_EH->TabIndex = 0;
			// 
			// list_No
			// 
			this->list_No->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle1->ForeColor = System::Drawing::Color::Black;
			this->list_No->DefaultCellStyle = dataGridViewCellStyle1;
			this->list_No->FillWeight = 5;
			this->list_No->HeaderText = L"No.";
			this->list_No->Name = L"list_No";
			this->list_No->ReadOnly = true;
			// 
			// errCode
			// 
			this->errCode->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::Color::Black;
			this->errCode->DefaultCellStyle = dataGridViewCellStyle2;
			this->errCode->FillWeight = 13;
			this->errCode->HeaderText = L"Error Code";
			this->errCode->Name = L"errCode";
			this->errCode->ReadOnly = true;
			// 
			// errStartTime
			// 
			this->errStartTime->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle3->ForeColor = System::Drawing::Color::RoyalBlue;
			this->errStartTime->DefaultCellStyle = dataGridViewCellStyle3;
			this->errStartTime->FillWeight = 10;
			this->errStartTime->HeaderText = L"Start Time";
			this->errStartTime->Name = L"errStartTime";
			this->errStartTime->ReadOnly = true;
			// 
			// errEndTime
			// 
			this->errEndTime->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			dataGridViewCellStyle4->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle4->ForeColor = System::Drawing::Color::RoyalBlue;
			this->errEndTime->DefaultCellStyle = dataGridViewCellStyle4;
			this->errEndTime->FillWeight = 10;
			this->errEndTime->HeaderText = L"End Time";
			this->errEndTime->Name = L"errEndTime";
			this->errEndTime->ReadOnly = true;
			// 
			// errHiLiTemper
			// 
			this->errHiLiTemper->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			dataGridViewCellStyle5->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			this->errHiLiTemper->DefaultCellStyle = dataGridViewCellStyle5;
			this->errHiLiTemper->FillWeight = 6;
			this->errHiLiTemper->HeaderText = L"Hi-Limit Temperature";
			this->errHiLiTemper->Name = L"errHiLiTemper";
			this->errHiLiTemper->ReadOnly = true;
			// 
			// errWaterTemper
			// 
			this->errWaterTemper->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			dataGridViewCellStyle6->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			this->errWaterTemper->DefaultCellStyle = dataGridViewCellStyle6;
			this->errWaterTemper->FillWeight = 6;
			this->errWaterTemper->HeaderText = L"Water Temperature";
			this->errWaterTemper->Name = L"errWaterTemper";
			this->errWaterTemper->ReadOnly = true;
			// 
			// errPCB_Temper
			// 
			this->errPCB_Temper->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			dataGridViewCellStyle7->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			this->errPCB_Temper->DefaultCellStyle = dataGridViewCellStyle7;
			this->errPCB_Temper->FillWeight = 6;
			this->errPCB_Temper->HeaderText = L"PCB Temperature";
			this->errPCB_Temper->Name = L"errPCB_Temper";
			this->errPCB_Temper->ReadOnly = true;
			// 
			// err_P1_Lo
			// 
			this->err_P1_Lo->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->err_P1_Lo->FillWeight = 4;
			this->err_P1_Lo->HeaderText = L"P1 Lo";
			this->err_P1_Lo->Name = L"err_P1_Lo";
			this->err_P1_Lo->ReadOnly = true;
			this->err_P1_Lo->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->err_P1_Lo->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Automatic;
			// 
			// err_P1_Hi
			// 
			this->err_P1_Hi->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->err_P1_Hi->FillWeight = 4;
			this->err_P1_Hi->HeaderText = L"P1 Hi";
			this->err_P1_Hi->Name = L"err_P1_Hi";
			this->err_P1_Hi->ReadOnly = true;
			this->err_P1_Hi->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->err_P1_Hi->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Automatic;
			// 
			// err_P2_Lo
			// 
			this->err_P2_Lo->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->err_P2_Lo->FillWeight = 4;
			this->err_P2_Lo->HeaderText = L"P2 Lo";
			this->err_P2_Lo->Name = L"err_P2_Lo";
			this->err_P2_Lo->ReadOnly = true;
			// 
			// err_P2_Hi
			// 
			this->err_P2_Hi->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->err_P2_Hi->FillWeight = 4;
			this->err_P2_Hi->HeaderText = L"P2 Hi";
			this->err_P2_Hi->Name = L"err_P2_Hi";
			this->err_P2_Hi->ReadOnly = true;
			// 
			// err_P3_Lo
			// 
			this->err_P3_Lo->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->err_P3_Lo->FillWeight = 4;
			this->err_P3_Lo->HeaderText = L"P3_Lo";
			this->err_P3_Lo->MinimumWidth = 3;
			this->err_P3_Lo->Name = L"err_P3_Lo";
			this->err_P3_Lo->ReadOnly = true;
			// 
			// err_P3_Hi
			// 
			this->err_P3_Hi->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->err_P3_Hi->FillWeight = 4;
			this->err_P3_Hi->HeaderText = L"P3 Hi";
			this->err_P3_Hi->Name = L"err_P3_Hi";
			this->err_P3_Hi->ReadOnly = true;
			// 
			// err_Blower
			// 
			this->err_Blower->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->err_Blower->FillWeight = 4;
			this->err_Blower->HeaderText = L"Blower";
			this->err_Blower->Name = L"err_Blower";
			this->err_Blower->ReadOnly = true;
			// 
			// err_Circ
			// 
			this->err_Circ->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->err_Circ->FillWeight = 4;
			this->err_Circ->HeaderText = L"Circ.";
			this->err_Circ->Name = L"err_Circ";
			this->err_Circ->ReadOnly = true;
			// 
			// err_UV
			// 
			this->err_UV->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->err_UV->FillWeight = 4;
			this->err_UV->HeaderText = L"UV";
			this->err_UV->Name = L"err_UV";
			this->err_UV->ReadOnly = true;
			// 
			// err_Heater
			// 
			this->err_Heater->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->err_Heater->FillWeight = 4;
			this->err_Heater->HeaderText = L"Heater";
			this->err_Heater->Name = L"err_Heater";
			this->err_Heater->ReadOnly = true;
			// 
			// err_Ozon
			// 
			this->err_Ozon->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->err_Ozon->FillWeight = 4;
			this->err_Ozon->HeaderText = L"Ozon";
			this->err_Ozon->Name = L"err_Ozon";
			this->err_Ozon->ReadOnly = true;
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->BackColor = System::Drawing::Color::LightBlue;
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel1->Controls->Add(this->dataGridView_EH, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->label1, 0, 0);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 3;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 10)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 89)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 1)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(1057, 503);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"PMingLiU", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label1->Location = System::Drawing::Point(402, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(252, 24);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Error History  Information";
			// 
			// EH_Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1057, 503);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"EH_Form";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Error History";
			this->TopMost = true;
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &EH_Form::EH_Form_FormClosed);
			this->Load += gcnew System::EventHandler(this, &EH_Form::EH_Form_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_EH))->EndInit();
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void EH_Form_Load(System::Object^  sender, System::EventArgs^  e);
private: System::Void EH_Form_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e);
};
}
