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
	/// Summary for DateTime_Form
	/// </summary>
	public ref class DateTime_Form : public System::Windows::Forms::Form
	{
	public:
		DateTime_Form(RDS_main_Form^ pForm)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			m_MainForm = pForm;
		}
	public: RDS_main_Form^ m_MainForm;
			unsigned char time_year;   //00~99 : 2000~2099
			unsigned char time_month;  //1~12
			unsigned char time_day;    //1~31
			unsigned char time_week;   //1=sun, 2=mon....7=Sat
			unsigned char time_hour;
			unsigned char time_min;

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~DateTime_Form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button_Save;
	protected:
	private: System::Windows::Forms::Label^  label_year;
	private: System::Windows::Forms::Label^  label_month;
	private: System::Windows::Forms::Label^  label_day;
	private: System::Windows::Forms::Label^  label_semicon;
	private: System::Windows::Forms::ComboBox^  cmbx_DT_min;
	private: System::Windows::Forms::ComboBox^  cmbx_DT_hour;
	private: System::Windows::Forms::ComboBox^  cmbx_DT_day;
	private: System::Windows::Forms::ComboBox^  cmbx_DT_month;
	private: System::Windows::Forms::ComboBox^  cmbx_DT_year;
	private: System::Windows::Forms::ComboBox^  cmbx_DT_weekday;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(DateTime_Form::typeid));
			this->button_Save = (gcnew System::Windows::Forms::Button());
			this->label_year = (gcnew System::Windows::Forms::Label());
			this->label_month = (gcnew System::Windows::Forms::Label());
			this->label_day = (gcnew System::Windows::Forms::Label());
			this->cmbx_DT_min = (gcnew System::Windows::Forms::ComboBox());
			this->cmbx_DT_hour = (gcnew System::Windows::Forms::ComboBox());
			this->cmbx_DT_day = (gcnew System::Windows::Forms::ComboBox());
			this->cmbx_DT_month = (gcnew System::Windows::Forms::ComboBox());
			this->cmbx_DT_year = (gcnew System::Windows::Forms::ComboBox());
			this->cmbx_DT_weekday = (gcnew System::Windows::Forms::ComboBox());
			this->label_semicon = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button_Save
			// 
			this->button_Save->Location = System::Drawing::Point(7, 76);
			this->button_Save->Name = L"button_Save";
			this->button_Save->Size = System::Drawing::Size(191, 32);
			this->button_Save->TabIndex = 0;
			this->button_Save->Text = L"Save to SPA";
			this->button_Save->UseVisualStyleBackColor = true;
			this->button_Save->Click += gcnew System::EventHandler(this, &DateTime_Form::button_Save_Click);
			// 
			// label_year
			// 
			this->label_year->AutoSize = true;
			this->label_year->Location = System::Drawing::Point(10, 6);
			this->label_year->Name = L"label_year";
			this->label_year->Size = System::Drawing::Size(27, 12);
			this->label_year->TabIndex = 1;
			this->label_year->Text = L"Year";
			// 
			// label_month
			// 
			this->label_month->AutoSize = true;
			this->label_month->Location = System::Drawing::Point(62, 6);
			this->label_month->Name = L"label_month";
			this->label_month->Size = System::Drawing::Size(36, 12);
			this->label_month->TabIndex = 2;
			this->label_month->Text = L"Month";
			// 
			// label_day
			// 
			this->label_day->AutoSize = true;
			this->label_day->Location = System::Drawing::Point(109, 6);
			this->label_day->Name = L"label_day";
			this->label_day->Size = System::Drawing::Size(24, 12);
			this->label_day->TabIndex = 3;
			this->label_day->Text = L"Day";
			// 
			// cmbx_DT_min
			// 
			this->cmbx_DT_min->BackColor = System::Drawing::SystemColors::Window;
			this->cmbx_DT_min->Font = (gcnew System::Drawing::Font(L"PMingLiU", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->cmbx_DT_min->FormattingEnabled = true;
			this->cmbx_DT_min->Items->AddRange(gcnew cli::array< System::Object^  >(60) {
				L"0", L"1", L"2", L"3", L"4", L"5", L"6", L"7",
					L"8", L"9", L"10", L"11", L"12", L"13", L"14", L"15", L"16", L"17", L"18", L"19", L"20", L"21", L"22", L"23", L"24", L"25", L"26",
					L"27", L"28", L"29", L"30", L"31", L"32", L"33", L"34", L"35", L"36", L"37", L"38", L"39", L"40", L"41", L"42", L"43", L"44",
					L"45", L"46", L"47", L"48", L"49", L"50", L"51", L"52", L"53", L"54", L"55", L"56", L"57", L"58", L"59"
			});
			this->cmbx_DT_min->Location = System::Drawing::Point(108, 49);
			this->cmbx_DT_min->Name = L"cmbx_DT_min";
			this->cmbx_DT_min->Size = System::Drawing::Size(37, 21);
			this->cmbx_DT_min->TabIndex = 62;
			this->cmbx_DT_min->Text = L"50";
			// 
			// cmbx_DT_hour
			// 
			this->cmbx_DT_hour->BackColor = System::Drawing::SystemColors::Window;
			this->cmbx_DT_hour->Font = (gcnew System::Drawing::Font(L"PMingLiU", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->cmbx_DT_hour->FormattingEnabled = true;
			this->cmbx_DT_hour->Items->AddRange(gcnew cli::array< System::Object^  >(24) {
				L"0", L"1", L"2", L"3", L"4", L"5", L"6", L"7",
					L"8", L"9", L"10", L"11", L"12", L"13", L"14", L"15", L"16", L"17", L"18", L"19", L"20", L"21", L"22", L"23"
			});
			this->cmbx_DT_hour->Location = System::Drawing::Point(60, 49);
			this->cmbx_DT_hour->Name = L"cmbx_DT_hour";
			this->cmbx_DT_hour->Size = System::Drawing::Size(36, 21);
			this->cmbx_DT_hour->TabIndex = 61;
			this->cmbx_DT_hour->Text = L"12";
			// 
			// cmbx_DT_day
			// 
			this->cmbx_DT_day->BackColor = System::Drawing::SystemColors::Window;
			this->cmbx_DT_day->Font = (gcnew System::Drawing::Font(L"PMingLiU", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->cmbx_DT_day->FormattingEnabled = true;
			this->cmbx_DT_day->Items->AddRange(gcnew cli::array< System::Object^  >(31) {
				L"1", L"2", L"3", L"4", L"5", L"6", L"7", L"8",
					L"9", L"10", L"11", L"12", L"13", L"14", L"15", L"16", L"17", L"18", L"19", L"20", L"21", L"22", L"23", L"24", L"25", L"26",
					L"27", L"28", L"29", L"30", L"31"
			});
			this->cmbx_DT_day->Location = System::Drawing::Point(105, 23);
			this->cmbx_DT_day->Name = L"cmbx_DT_day";
			this->cmbx_DT_day->Size = System::Drawing::Size(37, 21);
			this->cmbx_DT_day->TabIndex = 59;
			this->cmbx_DT_day->Text = L"25";
			this->cmbx_DT_day->SelectedIndexChanged += gcnew System::EventHandler(this, &DateTime_Form::cmbx_DT_day_SelectedIndexChanged);
			// 
			// cmbx_DT_month
			// 
			this->cmbx_DT_month->BackColor = System::Drawing::SystemColors::Window;
			this->cmbx_DT_month->Font = (gcnew System::Drawing::Font(L"PMingLiU", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->cmbx_DT_month->FormattingEnabled = true;
			this->cmbx_DT_month->Items->AddRange(gcnew cli::array< System::Object^  >(12) {
				L"1", L"2", L"3", L"4", L"5", L"6", L"7", L"8",
					L"9", L"10", L"11", L"12"
			});
			this->cmbx_DT_month->Location = System::Drawing::Point(60, 23);
			this->cmbx_DT_month->Name = L"cmbx_DT_month";
			this->cmbx_DT_month->Size = System::Drawing::Size(44, 21);
			this->cmbx_DT_month->TabIndex = 58;
			this->cmbx_DT_month->Text = L"12";
			this->cmbx_DT_month->SelectedIndexChanged += gcnew System::EventHandler(this, &DateTime_Form::cmbx_DT_month_SelectedIndexChanged);
			// 
			// cmbx_DT_year
			// 
			this->cmbx_DT_year->BackColor = System::Drawing::SystemColors::Window;
			this->cmbx_DT_year->Font = (gcnew System::Drawing::Font(L"PMingLiU", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->cmbx_DT_year->FormattingEnabled = true;
			this->cmbx_DT_year->Items->AddRange(gcnew cli::array< System::Object^  >(21) {
				L"2010", L"2011", L"2012", L"2013", L"2014",
					L"2015", L"2016", L"2017", L"2018", L"2019", L"2020", L"2021", L"2022", L"2023", L"2024", L"2025", L"2026", L"2027", L"2028",
					L"2029", L"2030"
			});
			this->cmbx_DT_year->Location = System::Drawing::Point(7, 22);
			this->cmbx_DT_year->Name = L"cmbx_DT_year";
			this->cmbx_DT_year->Size = System::Drawing::Size(52, 21);
			this->cmbx_DT_year->TabIndex = 57;
			this->cmbx_DT_year->Text = L"2013";
			this->cmbx_DT_year->SelectedIndexChanged += gcnew System::EventHandler(this, &DateTime_Form::cmbx_DT_year_SelectedIndexChanged);
			// 
			// cmbx_DT_weekday
			// 
			this->cmbx_DT_weekday->BackColor = System::Drawing::SystemColors::Window;
			this->cmbx_DT_weekday->Enabled = false;
			this->cmbx_DT_weekday->Font = (gcnew System::Drawing::Font(L"PMingLiU", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->cmbx_DT_weekday->FormattingEnabled = true;
			this->cmbx_DT_weekday->Items->AddRange(gcnew cli::array< System::Object^  >(7) {
				L"Sun", L"Mon", L"Tue", L"Wen", L"Thu", L"Fri",
					L"Sst"
			});
			this->cmbx_DT_weekday->Location = System::Drawing::Point(146, 23);
			this->cmbx_DT_weekday->Name = L"cmbx_DT_weekday";
			this->cmbx_DT_weekday->Size = System::Drawing::Size(52, 21);
			this->cmbx_DT_weekday->TabIndex = 64;
			this->cmbx_DT_weekday->Text = L"Wen";
			// 
			// label_semicon
			// 
			this->label_semicon->AutoSize = true;
			this->label_semicon->Location = System::Drawing::Point(98, 53);
			this->label_semicon->Name = L"label_semicon";
			this->label_semicon->Size = System::Drawing::Size(8, 12);
			this->label_semicon->TabIndex = 65;
			this->label_semicon->Text = L":";
			// 
			// DateTime_Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(205, 114);
			this->Controls->Add(this->label_semicon);
			this->Controls->Add(this->cmbx_DT_weekday);
			this->Controls->Add(this->cmbx_DT_min);
			this->Controls->Add(this->cmbx_DT_hour);
			this->Controls->Add(this->cmbx_DT_day);
			this->Controls->Add(this->cmbx_DT_month);
			this->Controls->Add(this->cmbx_DT_year);
			this->Controls->Add(this->label_day);
			this->Controls->Add(this->label_month);
			this->Controls->Add(this->label_year);
			this->Controls->Add(this->button_Save);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Location = System::Drawing::Point(520, 560);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"DateTime_Form";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"Date / Time";
			this->TopMost = true;
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &DateTime_Form::DateTime_Form_FormClosed);
			this->Load += gcnew System::EventHandler(this, &DateTime_Form::DateTime_Form_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button_Save_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void DateTime_Form_Load(System::Object^  sender, System::EventArgs^  e);
	private: int isLeapYear(unsigned int year);
	private: unsigned char getWeekDay(
				unsigned int year,
				unsigned char month,
				unsigned char day
				);
	private: System::Void cmbx_DT_year_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void cmbx_DT_month_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void cmbx_DT_day_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void DateTime_Form_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e);
};
}
