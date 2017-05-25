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
	/// Summary for FltSchedule_Form
	/// </summary>
	public ref class FltSchedule_Form : public System::Windows::Forms::Form
	{
	public:
		FltSchedule_Form(RDS_main_Form^ pForm)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			m_MainForm = pForm;
		}
	public: RDS_main_Form^ m_MainForm;
			unsigned char std_st_hour;
			unsigned char std_st_min;
			unsigned char std_dt_hour;
			unsigned char std_dt_min;
			unsigned char std_week;

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FltSchedule_Form()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	private: System::Windows::Forms::ComboBox^  cmbx_fltr_DT_hour;
	private: System::Windows::Forms::ComboBox^  cmbx_fltr_DT_min;
	private: System::Windows::Forms::Label^  lbl_filter_duration;
	private: System::Windows::Forms::ComboBox^  cmbx_Fltr_ST_min;
	private: System::Windows::Forms::Label^  lbl_filter_start;
	private: System::Windows::Forms::ComboBox^  cmbx_Fltr_ST_hour;
	private: System::Windows::Forms::Button^  button_Save;
	private: System::Windows::Forms::CheckBox^  cb_sun;
	private: System::Windows::Forms::CheckBox^  cb_mon;
	private: System::Windows::Forms::CheckBox^  cb_Tsu;
	private: System::Windows::Forms::CheckBox^  cb_wed;
	private: System::Windows::Forms::CheckBox^  cb_thu;
	private: System::Windows::Forms::CheckBox^  cb_fri;
	private: System::Windows::Forms::CheckBox^  cb_sat;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(FltSchedule_Form::typeid));
			this->cmbx_fltr_DT_min = (gcnew System::Windows::Forms::ComboBox());
			this->cmbx_fltr_DT_hour = (gcnew System::Windows::Forms::ComboBox());
			this->lbl_filter_duration = (gcnew System::Windows::Forms::Label());
			this->cmbx_Fltr_ST_min = (gcnew System::Windows::Forms::ComboBox());
			this->lbl_filter_start = (gcnew System::Windows::Forms::Label());
			this->cmbx_Fltr_ST_hour = (gcnew System::Windows::Forms::ComboBox());
			this->button_Save = (gcnew System::Windows::Forms::Button());
			this->cb_sun = (gcnew System::Windows::Forms::CheckBox());
			this->cb_mon = (gcnew System::Windows::Forms::CheckBox());
			this->cb_Tsu = (gcnew System::Windows::Forms::CheckBox());
			this->cb_wed = (gcnew System::Windows::Forms::CheckBox());
			this->cb_thu = (gcnew System::Windows::Forms::CheckBox());
			this->cb_fri = (gcnew System::Windows::Forms::CheckBox());
			this->cb_sat = (gcnew System::Windows::Forms::CheckBox());
			this->SuspendLayout();
			// 
			// cmbx_fltr_DT_min
			// 
			this->cmbx_fltr_DT_min->BackColor = System::Drawing::SystemColors::Window;
			this->cmbx_fltr_DT_min->Font = (gcnew System::Drawing::Font(L"PMingLiU", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->cmbx_fltr_DT_min->FormattingEnabled = true;
			this->cmbx_fltr_DT_min->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"0", L"15", L"30", L"45" });
			this->cmbx_fltr_DT_min->Location = System::Drawing::Point(105, 39);
			this->cmbx_fltr_DT_min->Name = L"cmbx_fltr_DT_min";
			this->cmbx_fltr_DT_min->Size = System::Drawing::Size(37, 21);
			this->cmbx_fltr_DT_min->TabIndex = 63;
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
			this->cmbx_fltr_DT_hour->Location = System::Drawing::Point(66, 39);
			this->cmbx_fltr_DT_hour->Name = L"cmbx_fltr_DT_hour";
			this->cmbx_fltr_DT_hour->Size = System::Drawing::Size(39, 21);
			this->cmbx_fltr_DT_hour->TabIndex = 61;
			this->cmbx_fltr_DT_hour->Text = L"1";
			// 
			// lbl_filter_duration
			// 
			this->lbl_filter_duration->AutoSize = true;
			this->lbl_filter_duration->Location = System::Drawing::Point(12, 41);
			this->lbl_filter_duration->Name = L"lbl_filter_duration";
			this->lbl_filter_duration->Size = System::Drawing::Size(46, 12);
			this->lbl_filter_duration->TabIndex = 66;
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
			this->cmbx_Fltr_ST_min->Location = System::Drawing::Point(106, 5);
			this->cmbx_Fltr_ST_min->Name = L"cmbx_Fltr_ST_min";
			this->cmbx_Fltr_ST_min->Size = System::Drawing::Size(37, 21);
			this->cmbx_Fltr_ST_min->TabIndex = 64;
			this->cmbx_Fltr_ST_min->Text = L"50";
			// 
			// lbl_filter_start
			// 
			this->lbl_filter_start->AutoSize = true;
			this->lbl_filter_start->Location = System::Drawing::Point(12, 9);
			this->lbl_filter_start->Name = L"lbl_filter_start";
			this->lbl_filter_start->Size = System::Drawing::Size(53, 12);
			this->lbl_filter_start->TabIndex = 60;
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
			this->cmbx_Fltr_ST_hour->Location = System::Drawing::Point(67, 5);
			this->cmbx_Fltr_ST_hour->Name = L"cmbx_Fltr_ST_hour";
			this->cmbx_Fltr_ST_hour->Size = System::Drawing::Size(39, 21);
			this->cmbx_Fltr_ST_hour->TabIndex = 62;
			this->cmbx_Fltr_ST_hour->Text = L"12";
			// 
			// button_Save
			// 
			this->button_Save->Location = System::Drawing::Point(14, 73);
			this->button_Save->Name = L"button_Save";
			this->button_Save->Size = System::Drawing::Size(128, 32);
			this->button_Save->TabIndex = 67;
			this->button_Save->Text = L"Save to SPA";
			this->button_Save->UseVisualStyleBackColor = true;
			this->button_Save->Click += gcnew System::EventHandler(this, &FltSchedule_Form::button_Save_Click);
			// 
			// cb_sun
			// 
			this->cb_sun->AutoSize = true;
			this->cb_sun->Location = System::Drawing::Point(150, 7);
			this->cb_sun->Name = L"cb_sun";
			this->cb_sun->Size = System::Drawing::Size(42, 16);
			this->cb_sun->TabIndex = 68;
			this->cb_sun->Text = L"Sun";
			this->cb_sun->UseVisualStyleBackColor = true;
			// 
			// cb_mon
			// 
			this->cb_mon->AutoSize = true;
			this->cb_mon->Location = System::Drawing::Point(150, 21);
			this->cb_mon->Name = L"cb_mon";
			this->cb_mon->Size = System::Drawing::Size(46, 16);
			this->cb_mon->TabIndex = 69;
			this->cb_mon->Text = L"Mon";
			this->cb_mon->UseVisualStyleBackColor = true;
			// 
			// cb_Tsu
			// 
			this->cb_Tsu->AutoSize = true;
			this->cb_Tsu->Location = System::Drawing::Point(150, 35);
			this->cb_Tsu->Name = L"cb_Tsu";
			this->cb_Tsu->Size = System::Drawing::Size(42, 16);
			this->cb_Tsu->TabIndex = 70;
			this->cb_Tsu->Text = L"Tue";
			this->cb_Tsu->UseVisualStyleBackColor = true;
			// 
			// cb_wed
			// 
			this->cb_wed->AutoSize = true;
			this->cb_wed->Location = System::Drawing::Point(150, 49);
			this->cb_wed->Name = L"cb_wed";
			this->cb_wed->Size = System::Drawing::Size(46, 16);
			this->cb_wed->TabIndex = 71;
			this->cb_wed->Text = L"Wed";
			this->cb_wed->UseVisualStyleBackColor = true;
			// 
			// cb_thu
			// 
			this->cb_thu->AutoSize = true;
			this->cb_thu->Location = System::Drawing::Point(150, 63);
			this->cb_thu->Name = L"cb_thu";
			this->cb_thu->Size = System::Drawing::Size(43, 16);
			this->cb_thu->TabIndex = 72;
			this->cb_thu->Text = L"Thu";
			this->cb_thu->UseVisualStyleBackColor = true;
			// 
			// cb_fri
			// 
			this->cb_fri->AutoSize = true;
			this->cb_fri->Location = System::Drawing::Point(150, 77);
			this->cb_fri->Name = L"cb_fri";
			this->cb_fri->Size = System::Drawing::Size(37, 16);
			this->cb_fri->TabIndex = 73;
			this->cb_fri->Text = L"Fri";
			this->cb_fri->UseVisualStyleBackColor = true;
			// 
			// cb_sat
			// 
			this->cb_sat->AutoSize = true;
			this->cb_sat->Location = System::Drawing::Point(150, 91);
			this->cb_sat->Name = L"cb_sat";
			this->cb_sat->Size = System::Drawing::Size(38, 16);
			this->cb_sat->TabIndex = 74;
			this->cb_sat->Text = L"Sat";
			this->cb_sat->UseVisualStyleBackColor = true;
			// 
			// FltSchedule_Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(200, 114);
			this->Controls->Add(this->cb_sat);
			this->Controls->Add(this->cb_fri);
			this->Controls->Add(this->cb_thu);
			this->Controls->Add(this->cb_wed);
			this->Controls->Add(this->cb_Tsu);
			this->Controls->Add(this->cb_mon);
			this->Controls->Add(this->cb_sun);
			this->Controls->Add(this->button_Save);
			this->Controls->Add(this->cmbx_fltr_DT_min);
			this->Controls->Add(this->cmbx_fltr_DT_hour);
			this->Controls->Add(this->lbl_filter_duration);
			this->Controls->Add(this->cmbx_Fltr_ST_min);
			this->Controls->Add(this->lbl_filter_start);
			this->Controls->Add(this->cmbx_Fltr_ST_hour);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Location = System::Drawing::Point(520, 560);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"FltSchedule_Form";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"Filteration Schedule";
			this->TopMost = true;
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &FltSchedule_Form::FltSchedule_Form_FormClosed);
			this->Load += gcnew System::EventHandler(this, &FltSchedule_Form::FltSchedule_Form_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button_Save_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void FltSchedule_Form_Load(System::Object^  sender, System::EventArgs^  e);
	private: System::Void FltSchedule_Form_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e);
};
}
