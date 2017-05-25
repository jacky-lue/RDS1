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
	/// Summary for set_PF_Form
	/// </summary>
	public ref class set_PF_Form : public System::Windows::Forms::Form
	{
	public:
		set_PF_Form(RDS_main_Form^ pForm)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			m_MainForm = pForm;
		}
	public: RDS_main_Form^ m_MainForm;
			unsigned char pf_value;
			unsigned char pf_st_hour;
			unsigned char pf_st_min;
			unsigned char pf_dt_hour;
			unsigned char pf_dt_min;

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~set_PF_Form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button_Save;
	protected:
	private: System::Windows::Forms::ComboBox^  cmbx_fltr_DT_min;
	private: System::Windows::Forms::ComboBox^  cmbx_fltr_DT_hour;
	private: System::Windows::Forms::Label^  lbl_filter_duration;
	private: System::Windows::Forms::ComboBox^  cmbx_Fltr_ST_min;
	private: System::Windows::Forms::Label^  lbl_filter_start;
	private: System::Windows::Forms::ComboBox^  cmbx_Fltr_ST_hour;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(set_PF_Form::typeid));
			this->button_Save = (gcnew System::Windows::Forms::Button());
			this->cmbx_fltr_DT_min = (gcnew System::Windows::Forms::ComboBox());
			this->cmbx_fltr_DT_hour = (gcnew System::Windows::Forms::ComboBox());
			this->lbl_filter_duration = (gcnew System::Windows::Forms::Label());
			this->cmbx_Fltr_ST_min = (gcnew System::Windows::Forms::ComboBox());
			this->lbl_filter_start = (gcnew System::Windows::Forms::Label());
			this->cmbx_Fltr_ST_hour = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// button_Save
			// 
			this->button_Save->Location = System::Drawing::Point(8, 68);
			this->button_Save->Name = L"button_Save";
			this->button_Save->Size = System::Drawing::Size(128, 32);
			this->button_Save->TabIndex = 74;
			this->button_Save->Text = L"Save to SPA";
			this->button_Save->UseVisualStyleBackColor = true;
			this->button_Save->Click += gcnew System::EventHandler(this, &set_PF_Form::button_Save_Click);
			// 
			// cmbx_fltr_DT_min
			// 
			this->cmbx_fltr_DT_min->BackColor = System::Drawing::SystemColors::Window;
			this->cmbx_fltr_DT_min->Font = (gcnew System::Drawing::Font(L"PMingLiU", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->cmbx_fltr_DT_min->FormattingEnabled = true;
			this->cmbx_fltr_DT_min->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"0", L"15", L"30", L"45" });
			this->cmbx_fltr_DT_min->Location = System::Drawing::Point(99, 39);
			this->cmbx_fltr_DT_min->Name = L"cmbx_fltr_DT_min";
			this->cmbx_fltr_DT_min->Size = System::Drawing::Size(37, 21);
			this->cmbx_fltr_DT_min->TabIndex = 71;
			this->cmbx_fltr_DT_min->Text = L"30";
			// 
			// cmbx_fltr_DT_hour
			// 
			this->cmbx_fltr_DT_hour->BackColor = System::Drawing::SystemColors::Window;
			this->cmbx_fltr_DT_hour->Font = (gcnew System::Drawing::Font(L"PMingLiU", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->cmbx_fltr_DT_hour->FormattingEnabled = true;
			this->cmbx_fltr_DT_hour->Items->AddRange(gcnew cli::array< System::Object^  >(24) {
				L"0", L"1", L"2", L"3", L"4", L"5", L"6",
					L"7", L"8", L"9", L"10", L"11", L"12", L"13", L"14", L"15", L"16", L"17", L"18", L"19", L"20", L"21", L"22", L"23"
			});
			this->cmbx_fltr_DT_hour->Location = System::Drawing::Point(60, 39);
			this->cmbx_fltr_DT_hour->Name = L"cmbx_fltr_DT_hour";
			this->cmbx_fltr_DT_hour->Size = System::Drawing::Size(39, 21);
			this->cmbx_fltr_DT_hour->TabIndex = 69;
			this->cmbx_fltr_DT_hour->Text = L"1";
			// 
			// lbl_filter_duration
			// 
			this->lbl_filter_duration->AutoSize = true;
			this->lbl_filter_duration->Location = System::Drawing::Point(6, 41);
			this->lbl_filter_duration->Name = L"lbl_filter_duration";
			this->lbl_filter_duration->Size = System::Drawing::Size(46, 12);
			this->lbl_filter_duration->TabIndex = 73;
			this->lbl_filter_duration->Text = L"Duration";
			// 
			// cmbx_Fltr_ST_min
			// 
			this->cmbx_Fltr_ST_min->BackColor = System::Drawing::SystemColors::Window;
			this->cmbx_Fltr_ST_min->Font = (gcnew System::Drawing::Font(L"PMingLiU", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->cmbx_Fltr_ST_min->FormattingEnabled = true;
			this->cmbx_Fltr_ST_min->Items->AddRange(gcnew cli::array< System::Object^  >(60) {
				L"0", L"1", L"2", L"3", L"4", L"5", L"6",
					L"7", L"8", L"9", L"10", L"11", L"12", L"13", L"14", L"15", L"16", L"17", L"18", L"19", L"20", L"21", L"22", L"23", L"24", L"25",
					L"26", L"27", L"28", L"29", L"30", L"31", L"32", L"33", L"34", L"35", L"36", L"37", L"38", L"39", L"40", L"41", L"42", L"43",
					L"44", L"45", L"46", L"47", L"48", L"49", L"50", L"51", L"52", L"53", L"54", L"55", L"56", L"57", L"58", L"59"
			});
			this->cmbx_Fltr_ST_min->Location = System::Drawing::Point(100, 5);
			this->cmbx_Fltr_ST_min->Name = L"cmbx_Fltr_ST_min";
			this->cmbx_Fltr_ST_min->Size = System::Drawing::Size(37, 21);
			this->cmbx_Fltr_ST_min->TabIndex = 72;
			this->cmbx_Fltr_ST_min->Text = L"50";
			// 
			// lbl_filter_start
			// 
			this->lbl_filter_start->AutoSize = true;
			this->lbl_filter_start->Location = System::Drawing::Point(6, 9);
			this->lbl_filter_start->Name = L"lbl_filter_start";
			this->lbl_filter_start->Size = System::Drawing::Size(53, 12);
			this->lbl_filter_start->TabIndex = 68;
			this->lbl_filter_start->Text = L"Start Time";
			// 
			// cmbx_Fltr_ST_hour
			// 
			this->cmbx_Fltr_ST_hour->BackColor = System::Drawing::SystemColors::Window;
			this->cmbx_Fltr_ST_hour->Font = (gcnew System::Drawing::Font(L"PMingLiU", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->cmbx_Fltr_ST_hour->FormattingEnabled = true;
			this->cmbx_Fltr_ST_hour->Items->AddRange(gcnew cli::array< System::Object^  >(24) {
				L"0", L"1", L"2", L"3", L"4", L"5", L"6",
					L"7", L"8", L"9", L"10", L"11", L"12", L"13", L"14", L"15", L"16", L"17", L"18", L"19", L"20", L"21", L"22", L"23"
			});
			this->cmbx_Fltr_ST_hour->Location = System::Drawing::Point(61, 5);
			this->cmbx_Fltr_ST_hour->Name = L"cmbx_Fltr_ST_hour";
			this->cmbx_Fltr_ST_hour->Size = System::Drawing::Size(39, 21);
			this->cmbx_Fltr_ST_hour->TabIndex = 70;
			this->cmbx_Fltr_ST_hour->Text = L"12";
			// 
			// set_PF_Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(149, 107);
			this->Controls->Add(this->button_Save);
			this->Controls->Add(this->cmbx_fltr_DT_min);
			this->Controls->Add(this->cmbx_fltr_DT_hour);
			this->Controls->Add(this->lbl_filter_duration);
			this->Controls->Add(this->cmbx_Fltr_ST_min);
			this->Controls->Add(this->lbl_filter_start);
			this->Controls->Add(this->cmbx_Fltr_ST_hour);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"set_PF_Form";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"PF Filteration";
			this->TopMost = true;
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &set_PF_Form::set_PF_Form_FormClosed);
			this->Load += gcnew System::EventHandler(this, &set_PF_Form::set_PF_Form_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void set_PF_Form_Load(System::Object^  sender, System::EventArgs^  e);
private: System::Void button_Save_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void set_PF_Form_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e);
};
}
