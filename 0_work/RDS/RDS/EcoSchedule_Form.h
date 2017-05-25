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
	/// Summary for EcoSchedule_Form
	/// </summary>
	public ref class EcoSchedule_Form : public System::Windows::Forms::Form
	{
	public:
		EcoSchedule_Form(RDS_main_Form^ pForm)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			m_MainForm = pForm;
		}
	public: RDS_main_Form^ m_MainForm;
			unsigned char eco_1_st_hour;
			unsigned char eco_1_st_min;
			unsigned char eco_1_dt_hour;
			unsigned char eco_1_dt_min;
			unsigned char eco_2_st_hour;
			unsigned char eco_2_st_min;
			unsigned char eco_2_dt_hour;
			unsigned char eco_2_dt_min;
			unsigned char eco_3_st_hour;
			unsigned char eco_3_st_min;
			unsigned char eco_3_dt_hour;
			unsigned char eco_3_dt_min;
			unsigned char eco_4_st_hour;
			unsigned char eco_4_st_min;
			unsigned char eco_4_dt_hour;
			unsigned char eco_4_dt_min;
			unsigned char eco_1_week;
			unsigned char eco_2_week;
			unsigned char eco_3_week;
			unsigned char eco_4_week;

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~EcoSchedule_Form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::CheckBox^  cb1_sat;
	private: System::Windows::Forms::CheckBox^  cb1_fri;
	private: System::Windows::Forms::CheckBox^  cb1_thu;
	private: System::Windows::Forms::CheckBox^  cb1_wed;
	private: System::Windows::Forms::CheckBox^  cb1_tue;


	private: System::Windows::Forms::CheckBox^  cb1_mon;
	private: System::Windows::Forms::CheckBox^  cb1_sun;
	private: System::Windows::Forms::CheckBox^  cb2_sat;
	private: System::Windows::Forms::CheckBox^  cb2_fri;
	private: System::Windows::Forms::CheckBox^  cb2_thu;
	private: System::Windows::Forms::CheckBox^  cb2_wed;
	private: System::Windows::Forms::CheckBox^  cb2_tue;
	private: System::Windows::Forms::CheckBox^  cb2_mon;
	private: System::Windows::Forms::CheckBox^  cb2_sun;
	private: System::Windows::Forms::CheckBox^  cb4_sat;
	private: System::Windows::Forms::CheckBox^  cb4_fri;
	private: System::Windows::Forms::CheckBox^  cb4_thu;
	private: System::Windows::Forms::CheckBox^  cb4_wed;
	private: System::Windows::Forms::CheckBox^  cb4_tue;
	private: System::Windows::Forms::CheckBox^  cb4_mon;
	private: System::Windows::Forms::CheckBox^  cb4_sun;
	private: System::Windows::Forms::CheckBox^  cb3_sat;
	private: System::Windows::Forms::CheckBox^  cb3_fri;
	private: System::Windows::Forms::CheckBox^  cb3_thu;
	private: System::Windows::Forms::CheckBox^  cb3_wed;
	private: System::Windows::Forms::CheckBox^  cb3_tue;
	private: System::Windows::Forms::CheckBox^  cb3_mon;
	private: System::Windows::Forms::CheckBox^  cb3_sun;
	private: System::Windows::Forms::Button^  button_Save;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ComboBox^  cmbx_EC4_DT_min;
	private: System::Windows::Forms::Label^  lbl_EC4_ST;
	private: System::Windows::Forms::ComboBox^  cmbx_EC4_DT_hour;
	private: System::Windows::Forms::ComboBox^  cmbx_EC4_ST_hour;
	private: System::Windows::Forms::Label^  lbl_EC4_DT;
	private: System::Windows::Forms::ComboBox^  cmbx_EC4_ST_min;
	private: System::Windows::Forms::ComboBox^  cmbx_EC3_DT_min;
	private: System::Windows::Forms::Label^  lbl_EC3_ST;
	private: System::Windows::Forms::ComboBox^  cmbx_EC3_DT_hour;
	private: System::Windows::Forms::ComboBox^  cmbx_EC3_ST_hour;
	private: System::Windows::Forms::Label^  lbl_EC3_DT;
	private: System::Windows::Forms::ComboBox^  cmbx_EC3_ST_min;
	private: System::Windows::Forms::ComboBox^  cmbx_EC2_DT_min;
	private: System::Windows::Forms::Label^  ibl_EC2_ST;
	private: System::Windows::Forms::ComboBox^  cmbx_EC2_DT_hour;
	private: System::Windows::Forms::ComboBox^  cmbx_EC2_ST_hour;
	private: System::Windows::Forms::Label^  lbl_EC2_DT;
	private: System::Windows::Forms::ComboBox^  cmbx_EC2_ST_min;
	private: System::Windows::Forms::ComboBox^  cmbx_EC1_DT_min;
	private: System::Windows::Forms::Label^  lbl_EC1_ST;
	private: System::Windows::Forms::ComboBox^  cmbx_EC1_DT_hour;
	private: System::Windows::Forms::ComboBox^  cmbx_EC1_ST_hour;
	private: System::Windows::Forms::Label^  lbl_EC1_DT;
	private: System::Windows::Forms::ComboBox^  cmbx_EC1_ST_min;
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(EcoSchedule_Form::typeid));
			this->button_Save = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->cmbx_EC4_DT_min = (gcnew System::Windows::Forms::ComboBox());
			this->lbl_EC4_ST = (gcnew System::Windows::Forms::Label());
			this->cmbx_EC4_DT_hour = (gcnew System::Windows::Forms::ComboBox());
			this->cmbx_EC4_ST_hour = (gcnew System::Windows::Forms::ComboBox());
			this->lbl_EC4_DT = (gcnew System::Windows::Forms::Label());
			this->cmbx_EC4_ST_min = (gcnew System::Windows::Forms::ComboBox());
			this->cmbx_EC3_DT_min = (gcnew System::Windows::Forms::ComboBox());
			this->lbl_EC3_ST = (gcnew System::Windows::Forms::Label());
			this->cmbx_EC3_DT_hour = (gcnew System::Windows::Forms::ComboBox());
			this->cmbx_EC3_ST_hour = (gcnew System::Windows::Forms::ComboBox());
			this->lbl_EC3_DT = (gcnew System::Windows::Forms::Label());
			this->cmbx_EC3_ST_min = (gcnew System::Windows::Forms::ComboBox());
			this->cmbx_EC2_DT_min = (gcnew System::Windows::Forms::ComboBox());
			this->ibl_EC2_ST = (gcnew System::Windows::Forms::Label());
			this->cmbx_EC2_DT_hour = (gcnew System::Windows::Forms::ComboBox());
			this->cmbx_EC2_ST_hour = (gcnew System::Windows::Forms::ComboBox());
			this->lbl_EC2_DT = (gcnew System::Windows::Forms::Label());
			this->cmbx_EC2_ST_min = (gcnew System::Windows::Forms::ComboBox());
			this->cmbx_EC1_DT_min = (gcnew System::Windows::Forms::ComboBox());
			this->lbl_EC1_ST = (gcnew System::Windows::Forms::Label());
			this->cmbx_EC1_DT_hour = (gcnew System::Windows::Forms::ComboBox());
			this->cmbx_EC1_ST_hour = (gcnew System::Windows::Forms::ComboBox());
			this->lbl_EC1_DT = (gcnew System::Windows::Forms::Label());
			this->cmbx_EC1_ST_min = (gcnew System::Windows::Forms::ComboBox());
			this->cb1_sat = (gcnew System::Windows::Forms::CheckBox());
			this->cb1_fri = (gcnew System::Windows::Forms::CheckBox());
			this->cb1_thu = (gcnew System::Windows::Forms::CheckBox());
			this->cb1_wed = (gcnew System::Windows::Forms::CheckBox());
			this->cb1_tue = (gcnew System::Windows::Forms::CheckBox());
			this->cb1_mon = (gcnew System::Windows::Forms::CheckBox());
			this->cb1_sun = (gcnew System::Windows::Forms::CheckBox());
			this->cb2_sat = (gcnew System::Windows::Forms::CheckBox());
			this->cb2_fri = (gcnew System::Windows::Forms::CheckBox());
			this->cb2_thu = (gcnew System::Windows::Forms::CheckBox());
			this->cb2_wed = (gcnew System::Windows::Forms::CheckBox());
			this->cb2_tue = (gcnew System::Windows::Forms::CheckBox());
			this->cb2_mon = (gcnew System::Windows::Forms::CheckBox());
			this->cb2_sun = (gcnew System::Windows::Forms::CheckBox());
			this->cb4_sat = (gcnew System::Windows::Forms::CheckBox());
			this->cb4_fri = (gcnew System::Windows::Forms::CheckBox());
			this->cb4_thu = (gcnew System::Windows::Forms::CheckBox());
			this->cb4_wed = (gcnew System::Windows::Forms::CheckBox());
			this->cb4_tue = (gcnew System::Windows::Forms::CheckBox());
			this->cb4_mon = (gcnew System::Windows::Forms::CheckBox());
			this->cb4_sun = (gcnew System::Windows::Forms::CheckBox());
			this->cb3_sat = (gcnew System::Windows::Forms::CheckBox());
			this->cb3_fri = (gcnew System::Windows::Forms::CheckBox());
			this->cb3_thu = (gcnew System::Windows::Forms::CheckBox());
			this->cb3_wed = (gcnew System::Windows::Forms::CheckBox());
			this->cb3_tue = (gcnew System::Windows::Forms::CheckBox());
			this->cb3_mon = (gcnew System::Windows::Forms::CheckBox());
			this->cb3_sun = (gcnew System::Windows::Forms::CheckBox());
			this->SuspendLayout();
			// 
			// button_Save
			// 
			this->button_Save->Location = System::Drawing::Point(15, 205);
			this->button_Save->Name = L"button_Save";
			this->button_Save->Size = System::Drawing::Size(378, 32);
			this->button_Save->TabIndex = 153;
			this->button_Save->Text = L"Save to SPA";
			this->button_Save->UseVisualStyleBackColor = true;
			this->button_Save->Click += gcnew System::EventHandler(this, &EcoSchedule_Form::button_Save_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"AVGmdBU", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label4->Location = System::Drawing::Point(8, 158);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(25, 25);
			this->label4->TabIndex = 152;
			this->label4->Text = L"4";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"AVGmdBU", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label3->Location = System::Drawing::Point(8, 106);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(25, 25);
			this->label3->TabIndex = 151;
			this->label3->Text = L"3";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"AVGmdBU", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label2->Location = System::Drawing::Point(8, 57);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(25, 25);
			this->label2->TabIndex = 150;
			this->label2->Text = L"2";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"AVGmdBU", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label1->Location = System::Drawing::Point(8, 11);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(25, 25);
			this->label1->TabIndex = 149;
			this->label1->Text = L"1";
			// 
			// cmbx_EC4_DT_min
			// 
			this->cmbx_EC4_DT_min->BackColor = System::Drawing::SystemColors::Window;
			this->cmbx_EC4_DT_min->Font = (gcnew System::Drawing::Font(L"PMingLiU", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->cmbx_EC4_DT_min->FormattingEnabled = true;
			this->cmbx_EC4_DT_min->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"0", L"15", L"30", L"45" });
			this->cmbx_EC4_DT_min->Location = System::Drawing::Point(136, 178);
			this->cmbx_EC4_DT_min->Name = L"cmbx_EC4_DT_min";
			this->cmbx_EC4_DT_min->Size = System::Drawing::Size(37, 21);
			this->cmbx_EC4_DT_min->TabIndex = 145;
			this->cmbx_EC4_DT_min->Text = L"30";
			// 
			// lbl_EC4_ST
			// 
			this->lbl_EC4_ST->AutoSize = true;
			this->lbl_EC4_ST->Location = System::Drawing::Point(37, 158);
			this->lbl_EC4_ST->Name = L"lbl_EC4_ST";
			this->lbl_EC4_ST->Size = System::Drawing::Size(53, 12);
			this->lbl_EC4_ST->TabIndex = 142;
			this->lbl_EC4_ST->Text = L"Start Time";
			// 
			// cmbx_EC4_DT_hour
			// 
			this->cmbx_EC4_DT_hour->BackColor = System::Drawing::SystemColors::Window;
			this->cmbx_EC4_DT_hour->Font = (gcnew System::Drawing::Font(L"PMingLiU", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->cmbx_EC4_DT_hour->FormattingEnabled = true;
			this->cmbx_EC4_DT_hour->Items->AddRange(gcnew cli::array< System::Object^  >(24) {
				L"0", L"1", L"2", L"3", L"4", L"5", L"6",
					L"7", L"8", L"9", L"10", L"11", L"12", L"13", L"14", L"15", L"16", L"17", L"18", L"19", L"20", L"21", L"22", L"23"
			});
			this->cmbx_EC4_DT_hour->Location = System::Drawing::Point(91, 178);
			this->cmbx_EC4_DT_hour->Name = L"cmbx_EC4_DT_hour";
			this->cmbx_EC4_DT_hour->Size = System::Drawing::Size(44, 21);
			this->cmbx_EC4_DT_hour->TabIndex = 143;
			this->cmbx_EC4_DT_hour->Text = L"1";
			// 
			// cmbx_EC4_ST_hour
			// 
			this->cmbx_EC4_ST_hour->BackColor = System::Drawing::SystemColors::Window;
			this->cmbx_EC4_ST_hour->Font = (gcnew System::Drawing::Font(L"PMingLiU", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->cmbx_EC4_ST_hour->FormattingEnabled = true;
			this->cmbx_EC4_ST_hour->Items->AddRange(gcnew cli::array< System::Object^  >(24) {
				L"0", L"1", L"2", L"3", L"4", L"5", L"6",
					L"7", L"8", L"9", L"10", L"11", L"12", L"13", L"14", L"15", L"16", L"17", L"18", L"19", L"20", L"21", L"22", L"23"
			});
			this->cmbx_EC4_ST_hour->Location = System::Drawing::Point(92, 154);
			this->cmbx_EC4_ST_hour->Name = L"cmbx_EC4_ST_hour";
			this->cmbx_EC4_ST_hour->Size = System::Drawing::Size(44, 21);
			this->cmbx_EC4_ST_hour->TabIndex = 144;
			this->cmbx_EC4_ST_hour->Text = L"12";
			// 
			// lbl_EC4_DT
			// 
			this->lbl_EC4_DT->AutoSize = true;
			this->lbl_EC4_DT->Location = System::Drawing::Point(37, 180);
			this->lbl_EC4_DT->Name = L"lbl_EC4_DT";
			this->lbl_EC4_DT->Size = System::Drawing::Size(46, 12);
			this->lbl_EC4_DT->TabIndex = 148;
			this->lbl_EC4_DT->Text = L"Duration";
			// 
			// cmbx_EC4_ST_min
			// 
			this->cmbx_EC4_ST_min->BackColor = System::Drawing::SystemColors::Window;
			this->cmbx_EC4_ST_min->Font = (gcnew System::Drawing::Font(L"PMingLiU", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->cmbx_EC4_ST_min->FormattingEnabled = true;
			this->cmbx_EC4_ST_min->Items->AddRange(gcnew cli::array< System::Object^  >(60) {
				L"0", L"1", L"2", L"3", L"4", L"5", L"6",
					L"7", L"8", L"9", L"10", L"11", L"12", L"13", L"14", L"15", L"16", L"17", L"18", L"19", L"20", L"21", L"22", L"23", L"24", L"25",
					L"26", L"27", L"28", L"29", L"30", L"31", L"32", L"33", L"34", L"35", L"36", L"37", L"38", L"39", L"40", L"41", L"42", L"43",
					L"44", L"45", L"46", L"47", L"48", L"49", L"50", L"51", L"52", L"53", L"54", L"55", L"56", L"57", L"58", L"59"
			});
			this->cmbx_EC4_ST_min->Location = System::Drawing::Point(137, 154);
			this->cmbx_EC4_ST_min->Name = L"cmbx_EC4_ST_min";
			this->cmbx_EC4_ST_min->Size = System::Drawing::Size(37, 21);
			this->cmbx_EC4_ST_min->TabIndex = 146;
			this->cmbx_EC4_ST_min->Text = L"50";
			// 
			// cmbx_EC3_DT_min
			// 
			this->cmbx_EC3_DT_min->BackColor = System::Drawing::SystemColors::Window;
			this->cmbx_EC3_DT_min->Font = (gcnew System::Drawing::Font(L"PMingLiU", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->cmbx_EC3_DT_min->FormattingEnabled = true;
			this->cmbx_EC3_DT_min->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"0", L"15", L"30", L"45" });
			this->cmbx_EC3_DT_min->Location = System::Drawing::Point(137, 130);
			this->cmbx_EC3_DT_min->Name = L"cmbx_EC3_DT_min";
			this->cmbx_EC3_DT_min->Size = System::Drawing::Size(37, 21);
			this->cmbx_EC3_DT_min->TabIndex = 138;
			this->cmbx_EC3_DT_min->Text = L"30";
			// 
			// lbl_EC3_ST
			// 
			this->lbl_EC3_ST->AutoSize = true;
			this->lbl_EC3_ST->Location = System::Drawing::Point(38, 110);
			this->lbl_EC3_ST->Name = L"lbl_EC3_ST";
			this->lbl_EC3_ST->Size = System::Drawing::Size(53, 12);
			this->lbl_EC3_ST->TabIndex = 135;
			this->lbl_EC3_ST->Text = L"Start Time";
			// 
			// cmbx_EC3_DT_hour
			// 
			this->cmbx_EC3_DT_hour->BackColor = System::Drawing::SystemColors::Window;
			this->cmbx_EC3_DT_hour->Font = (gcnew System::Drawing::Font(L"PMingLiU", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->cmbx_EC3_DT_hour->FormattingEnabled = true;
			this->cmbx_EC3_DT_hour->Items->AddRange(gcnew cli::array< System::Object^  >(24) {
				L"0", L"1", L"2", L"3", L"4", L"5", L"6",
					L"7", L"8", L"9", L"10", L"11", L"12", L"13", L"14", L"15", L"16", L"17", L"18", L"19", L"20", L"21", L"22", L"23"
			});
			this->cmbx_EC3_DT_hour->Location = System::Drawing::Point(92, 130);
			this->cmbx_EC3_DT_hour->Name = L"cmbx_EC3_DT_hour";
			this->cmbx_EC3_DT_hour->Size = System::Drawing::Size(44, 21);
			this->cmbx_EC3_DT_hour->TabIndex = 136;
			this->cmbx_EC3_DT_hour->Text = L"1";
			// 
			// cmbx_EC3_ST_hour
			// 
			this->cmbx_EC3_ST_hour->BackColor = System::Drawing::SystemColors::Window;
			this->cmbx_EC3_ST_hour->Font = (gcnew System::Drawing::Font(L"PMingLiU", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->cmbx_EC3_ST_hour->FormattingEnabled = true;
			this->cmbx_EC3_ST_hour->Items->AddRange(gcnew cli::array< System::Object^  >(24) {
				L"0", L"1", L"2", L"3", L"4", L"5", L"6",
					L"7", L"8", L"9", L"10", L"11", L"12", L"13", L"14", L"15", L"16", L"17", L"18", L"19", L"20", L"21", L"22", L"23"
			});
			this->cmbx_EC3_ST_hour->Location = System::Drawing::Point(93, 106);
			this->cmbx_EC3_ST_hour->Name = L"cmbx_EC3_ST_hour";
			this->cmbx_EC3_ST_hour->Size = System::Drawing::Size(44, 21);
			this->cmbx_EC3_ST_hour->TabIndex = 137;
			this->cmbx_EC3_ST_hour->Text = L"12";
			// 
			// lbl_EC3_DT
			// 
			this->lbl_EC3_DT->AutoSize = true;
			this->lbl_EC3_DT->Location = System::Drawing::Point(38, 132);
			this->lbl_EC3_DT->Name = L"lbl_EC3_DT";
			this->lbl_EC3_DT->Size = System::Drawing::Size(46, 12);
			this->lbl_EC3_DT->TabIndex = 141;
			this->lbl_EC3_DT->Text = L"Duration";
			// 
			// cmbx_EC3_ST_min
			// 
			this->cmbx_EC3_ST_min->BackColor = System::Drawing::SystemColors::Window;
			this->cmbx_EC3_ST_min->Font = (gcnew System::Drawing::Font(L"PMingLiU", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->cmbx_EC3_ST_min->FormattingEnabled = true;
			this->cmbx_EC3_ST_min->Items->AddRange(gcnew cli::array< System::Object^  >(60) {
				L"0", L"1", L"2", L"3", L"4", L"5", L"6",
					L"7", L"8", L"9", L"10", L"11", L"12", L"13", L"14", L"15", L"16", L"17", L"18", L"19", L"20", L"21", L"22", L"23", L"24", L"25",
					L"26", L"27", L"28", L"29", L"30", L"31", L"32", L"33", L"34", L"35", L"36", L"37", L"38", L"39", L"40", L"41", L"42", L"43",
					L"44", L"45", L"46", L"47", L"48", L"49", L"50", L"51", L"52", L"53", L"54", L"55", L"56", L"57", L"58", L"59"
			});
			this->cmbx_EC3_ST_min->Location = System::Drawing::Point(138, 106);
			this->cmbx_EC3_ST_min->Name = L"cmbx_EC3_ST_min";
			this->cmbx_EC3_ST_min->Size = System::Drawing::Size(37, 21);
			this->cmbx_EC3_ST_min->TabIndex = 139;
			this->cmbx_EC3_ST_min->Text = L"50";
			// 
			// cmbx_EC2_DT_min
			// 
			this->cmbx_EC2_DT_min->BackColor = System::Drawing::SystemColors::Window;
			this->cmbx_EC2_DT_min->Font = (gcnew System::Drawing::Font(L"PMingLiU", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->cmbx_EC2_DT_min->FormattingEnabled = true;
			this->cmbx_EC2_DT_min->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"0", L"15", L"30", L"45" });
			this->cmbx_EC2_DT_min->Location = System::Drawing::Point(138, 81);
			this->cmbx_EC2_DT_min->Name = L"cmbx_EC2_DT_min";
			this->cmbx_EC2_DT_min->Size = System::Drawing::Size(37, 21);
			this->cmbx_EC2_DT_min->TabIndex = 131;
			this->cmbx_EC2_DT_min->Text = L"30";
			// 
			// ibl_EC2_ST
			// 
			this->ibl_EC2_ST->AutoSize = true;
			this->ibl_EC2_ST->Location = System::Drawing::Point(39, 61);
			this->ibl_EC2_ST->Name = L"ibl_EC2_ST";
			this->ibl_EC2_ST->Size = System::Drawing::Size(53, 12);
			this->ibl_EC2_ST->TabIndex = 128;
			this->ibl_EC2_ST->Text = L"Start Time";
			// 
			// cmbx_EC2_DT_hour
			// 
			this->cmbx_EC2_DT_hour->BackColor = System::Drawing::SystemColors::Window;
			this->cmbx_EC2_DT_hour->Font = (gcnew System::Drawing::Font(L"PMingLiU", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->cmbx_EC2_DT_hour->FormattingEnabled = true;
			this->cmbx_EC2_DT_hour->Items->AddRange(gcnew cli::array< System::Object^  >(24) {
				L"0", L"1", L"2", L"3", L"4", L"5", L"6",
					L"7", L"8", L"9", L"10", L"11", L"12", L"13", L"14", L"15", L"16", L"17", L"18", L"19", L"20", L"21", L"22", L"23"
			});
			this->cmbx_EC2_DT_hour->Location = System::Drawing::Point(93, 81);
			this->cmbx_EC2_DT_hour->Name = L"cmbx_EC2_DT_hour";
			this->cmbx_EC2_DT_hour->Size = System::Drawing::Size(44, 21);
			this->cmbx_EC2_DT_hour->TabIndex = 129;
			this->cmbx_EC2_DT_hour->Text = L"1";
			// 
			// cmbx_EC2_ST_hour
			// 
			this->cmbx_EC2_ST_hour->BackColor = System::Drawing::SystemColors::Window;
			this->cmbx_EC2_ST_hour->Font = (gcnew System::Drawing::Font(L"PMingLiU", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->cmbx_EC2_ST_hour->FormattingEnabled = true;
			this->cmbx_EC2_ST_hour->Items->AddRange(gcnew cli::array< System::Object^  >(24) {
				L"0", L"1", L"2", L"3", L"4", L"5", L"6",
					L"7", L"8", L"9", L"10", L"11", L"12", L"13", L"14", L"15", L"16", L"17", L"18", L"19", L"20", L"21", L"22", L"23"
			});
			this->cmbx_EC2_ST_hour->Location = System::Drawing::Point(94, 57);
			this->cmbx_EC2_ST_hour->Name = L"cmbx_EC2_ST_hour";
			this->cmbx_EC2_ST_hour->Size = System::Drawing::Size(44, 21);
			this->cmbx_EC2_ST_hour->TabIndex = 130;
			this->cmbx_EC2_ST_hour->Text = L"12";
			// 
			// lbl_EC2_DT
			// 
			this->lbl_EC2_DT->AutoSize = true;
			this->lbl_EC2_DT->Location = System::Drawing::Point(39, 83);
			this->lbl_EC2_DT->Name = L"lbl_EC2_DT";
			this->lbl_EC2_DT->Size = System::Drawing::Size(46, 12);
			this->lbl_EC2_DT->TabIndex = 134;
			this->lbl_EC2_DT->Text = L"Duration";
			// 
			// cmbx_EC2_ST_min
			// 
			this->cmbx_EC2_ST_min->BackColor = System::Drawing::SystemColors::Window;
			this->cmbx_EC2_ST_min->Font = (gcnew System::Drawing::Font(L"PMingLiU", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->cmbx_EC2_ST_min->FormattingEnabled = true;
			this->cmbx_EC2_ST_min->Items->AddRange(gcnew cli::array< System::Object^  >(60) {
				L"0", L"1", L"2", L"3", L"4", L"5", L"6",
					L"7", L"8", L"9", L"10", L"11", L"12", L"13", L"14", L"15", L"16", L"17", L"18", L"19", L"20", L"21", L"22", L"23", L"24", L"25",
					L"26", L"27", L"28", L"29", L"30", L"31", L"32", L"33", L"34", L"35", L"36", L"37", L"38", L"39", L"40", L"41", L"42", L"43",
					L"44", L"45", L"46", L"47", L"48", L"49", L"50", L"51", L"52", L"53", L"54", L"55", L"56", L"57", L"58", L"59"
			});
			this->cmbx_EC2_ST_min->Location = System::Drawing::Point(139, 57);
			this->cmbx_EC2_ST_min->Name = L"cmbx_EC2_ST_min";
			this->cmbx_EC2_ST_min->Size = System::Drawing::Size(37, 21);
			this->cmbx_EC2_ST_min->TabIndex = 132;
			this->cmbx_EC2_ST_min->Text = L"50";
			// 
			// cmbx_EC1_DT_min
			// 
			this->cmbx_EC1_DT_min->BackColor = System::Drawing::SystemColors::Window;
			this->cmbx_EC1_DT_min->Font = (gcnew System::Drawing::Font(L"PMingLiU", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->cmbx_EC1_DT_min->FormattingEnabled = true;
			this->cmbx_EC1_DT_min->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"0", L"15", L"30", L"45" });
			this->cmbx_EC1_DT_min->Location = System::Drawing::Point(138, 31);
			this->cmbx_EC1_DT_min->Name = L"cmbx_EC1_DT_min";
			this->cmbx_EC1_DT_min->Size = System::Drawing::Size(37, 21);
			this->cmbx_EC1_DT_min->TabIndex = 124;
			this->cmbx_EC1_DT_min->Text = L"30";
			// 
			// lbl_EC1_ST
			// 
			this->lbl_EC1_ST->AutoSize = true;
			this->lbl_EC1_ST->Location = System::Drawing::Point(39, 11);
			this->lbl_EC1_ST->Name = L"lbl_EC1_ST";
			this->lbl_EC1_ST->Size = System::Drawing::Size(53, 12);
			this->lbl_EC1_ST->TabIndex = 121;
			this->lbl_EC1_ST->Text = L"Start Time";
			// 
			// cmbx_EC1_DT_hour
			// 
			this->cmbx_EC1_DT_hour->BackColor = System::Drawing::SystemColors::Window;
			this->cmbx_EC1_DT_hour->Font = (gcnew System::Drawing::Font(L"PMingLiU", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->cmbx_EC1_DT_hour->FormattingEnabled = true;
			this->cmbx_EC1_DT_hour->Items->AddRange(gcnew cli::array< System::Object^  >(24) {
				L"0", L"1", L"2", L"3", L"4", L"5", L"6",
					L"7", L"8", L"9", L"10", L"11", L"12", L"13", L"14", L"15", L"16", L"17", L"18", L"19", L"20", L"21", L"22", L"23"
			});
			this->cmbx_EC1_DT_hour->Location = System::Drawing::Point(93, 31);
			this->cmbx_EC1_DT_hour->Name = L"cmbx_EC1_DT_hour";
			this->cmbx_EC1_DT_hour->Size = System::Drawing::Size(44, 21);
			this->cmbx_EC1_DT_hour->TabIndex = 122;
			this->cmbx_EC1_DT_hour->Text = L"1";
			// 
			// cmbx_EC1_ST_hour
			// 
			this->cmbx_EC1_ST_hour->BackColor = System::Drawing::SystemColors::Window;
			this->cmbx_EC1_ST_hour->Font = (gcnew System::Drawing::Font(L"PMingLiU", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->cmbx_EC1_ST_hour->FormattingEnabled = true;
			this->cmbx_EC1_ST_hour->Items->AddRange(gcnew cli::array< System::Object^  >(24) {
				L"0", L"1", L"2", L"3", L"4", L"5", L"6",
					L"7", L"8", L"9", L"10", L"11", L"12", L"13", L"14", L"15", L"16", L"17", L"18", L"19", L"20", L"21", L"22", L"23"
			});
			this->cmbx_EC1_ST_hour->Location = System::Drawing::Point(94, 7);
			this->cmbx_EC1_ST_hour->Name = L"cmbx_EC1_ST_hour";
			this->cmbx_EC1_ST_hour->Size = System::Drawing::Size(44, 21);
			this->cmbx_EC1_ST_hour->TabIndex = 123;
			this->cmbx_EC1_ST_hour->Text = L"12";
			// 
			// lbl_EC1_DT
			// 
			this->lbl_EC1_DT->AutoSize = true;
			this->lbl_EC1_DT->Location = System::Drawing::Point(39, 33);
			this->lbl_EC1_DT->Name = L"lbl_EC1_DT";
			this->lbl_EC1_DT->Size = System::Drawing::Size(46, 12);
			this->lbl_EC1_DT->TabIndex = 127;
			this->lbl_EC1_DT->Text = L"Duration";
			// 
			// cmbx_EC1_ST_min
			// 
			this->cmbx_EC1_ST_min->BackColor = System::Drawing::SystemColors::Window;
			this->cmbx_EC1_ST_min->Font = (gcnew System::Drawing::Font(L"PMingLiU", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->cmbx_EC1_ST_min->FormattingEnabled = true;
			this->cmbx_EC1_ST_min->Items->AddRange(gcnew cli::array< System::Object^  >(60) {
				L"0", L"1", L"2", L"3", L"4", L"5", L"6",
					L"7", L"8", L"9", L"10", L"11", L"12", L"13", L"14", L"15", L"16", L"17", L"18", L"19", L"20", L"21", L"22", L"23", L"24", L"25",
					L"26", L"27", L"28", L"29", L"30", L"31", L"32", L"33", L"34", L"35", L"36", L"37", L"38", L"39", L"40", L"41", L"42", L"43",
					L"44", L"45", L"46", L"47", L"48", L"49", L"50", L"51", L"52", L"53", L"54", L"55", L"56", L"57", L"58", L"59"
			});
			this->cmbx_EC1_ST_min->Location = System::Drawing::Point(139, 7);
			this->cmbx_EC1_ST_min->Name = L"cmbx_EC1_ST_min";
			this->cmbx_EC1_ST_min->Size = System::Drawing::Size(37, 21);
			this->cmbx_EC1_ST_min->TabIndex = 125;
			this->cmbx_EC1_ST_min->Text = L"50";
			// 
			// cb1_sat
			// 
			this->cb1_sat->AutoSize = true;
			this->cb1_sat->CheckAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->cb1_sat->Location = System::Drawing::Point(372, 15);
			this->cb1_sat->Name = L"cb1_sat";
			this->cb1_sat->Size = System::Drawing::Size(23, 30);
			this->cb1_sat->TabIndex = 160;
			this->cb1_sat->Text = L"Sat";
			this->cb1_sat->UseVisualStyleBackColor = true;
			// 
			// cb1_fri
			// 
			this->cb1_fri->AutoSize = true;
			this->cb1_fri->CheckAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->cb1_fri->Location = System::Drawing::Point(342, 15);
			this->cb1_fri->Name = L"cb1_fri";
			this->cb1_fri->Size = System::Drawing::Size(22, 30);
			this->cb1_fri->TabIndex = 159;
			this->cb1_fri->Text = L"Fri";
			this->cb1_fri->UseVisualStyleBackColor = true;
			// 
			// cb1_thu
			// 
			this->cb1_thu->AutoSize = true;
			this->cb1_thu->CheckAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->cb1_thu->Location = System::Drawing::Point(307, 15);
			this->cb1_thu->Name = L"cb1_thu";
			this->cb1_thu->Size = System::Drawing::Size(28, 30);
			this->cb1_thu->TabIndex = 158;
			this->cb1_thu->Text = L"Thu";
			this->cb1_thu->UseVisualStyleBackColor = true;
			// 
			// cb1_wed
			// 
			this->cb1_wed->AutoSize = true;
			this->cb1_wed->CheckAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->cb1_wed->Location = System::Drawing::Point(273, 15);
			this->cb1_wed->Name = L"cb1_wed";
			this->cb1_wed->Size = System::Drawing::Size(31, 30);
			this->cb1_wed->TabIndex = 157;
			this->cb1_wed->Text = L"Wed";
			this->cb1_wed->UseVisualStyleBackColor = true;
			// 
			// cb1_tue
			// 
			this->cb1_tue->AutoSize = true;
			this->cb1_tue->CheckAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->cb1_tue->Location = System::Drawing::Point(242, 15);
			this->cb1_tue->Name = L"cb1_tue";
			this->cb1_tue->Size = System::Drawing::Size(27, 30);
			this->cb1_tue->TabIndex = 156;
			this->cb1_tue->Text = L"Tue";
			this->cb1_tue->UseVisualStyleBackColor = true;
			// 
			// cb1_mon
			// 
			this->cb1_mon->AutoSize = true;
			this->cb1_mon->CheckAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->cb1_mon->Location = System::Drawing::Point(209, 15);
			this->cb1_mon->Name = L"cb1_mon";
			this->cb1_mon->Size = System::Drawing::Size(31, 30);
			this->cb1_mon->TabIndex = 155;
			this->cb1_mon->Text = L"Mon";
			this->cb1_mon->UseVisualStyleBackColor = true;
			// 
			// cb1_sun
			// 
			this->cb1_sun->AutoSize = true;
			this->cb1_sun->CheckAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->cb1_sun->Location = System::Drawing::Point(183, 15);
			this->cb1_sun->Name = L"cb1_sun";
			this->cb1_sun->Size = System::Drawing::Size(27, 30);
			this->cb1_sun->TabIndex = 154;
			this->cb1_sun->Text = L"Sun";
			this->cb1_sun->UseVisualStyleBackColor = true;
			// 
			// cb2_sat
			// 
			this->cb2_sat->AutoSize = true;
			this->cb2_sat->CheckAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->cb2_sat->Location = System::Drawing::Point(372, 65);
			this->cb2_sat->Name = L"cb2_sat";
			this->cb2_sat->Size = System::Drawing::Size(23, 30);
			this->cb2_sat->TabIndex = 167;
			this->cb2_sat->Text = L"Sat";
			this->cb2_sat->UseVisualStyleBackColor = true;
			// 
			// cb2_fri
			// 
			this->cb2_fri->AutoSize = true;
			this->cb2_fri->CheckAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->cb2_fri->Location = System::Drawing::Point(342, 65);
			this->cb2_fri->Name = L"cb2_fri";
			this->cb2_fri->Size = System::Drawing::Size(22, 30);
			this->cb2_fri->TabIndex = 166;
			this->cb2_fri->Text = L"Fri";
			this->cb2_fri->UseVisualStyleBackColor = true;
			// 
			// cb2_thu
			// 
			this->cb2_thu->AutoSize = true;
			this->cb2_thu->CheckAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->cb2_thu->Location = System::Drawing::Point(307, 65);
			this->cb2_thu->Name = L"cb2_thu";
			this->cb2_thu->Size = System::Drawing::Size(28, 30);
			this->cb2_thu->TabIndex = 165;
			this->cb2_thu->Text = L"Thu";
			this->cb2_thu->UseVisualStyleBackColor = true;
			// 
			// cb2_wed
			// 
			this->cb2_wed->AutoSize = true;
			this->cb2_wed->CheckAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->cb2_wed->Location = System::Drawing::Point(273, 65);
			this->cb2_wed->Name = L"cb2_wed";
			this->cb2_wed->Size = System::Drawing::Size(31, 30);
			this->cb2_wed->TabIndex = 164;
			this->cb2_wed->Text = L"Wed";
			this->cb2_wed->UseVisualStyleBackColor = true;
			// 
			// cb2_tue
			// 
			this->cb2_tue->AutoSize = true;
			this->cb2_tue->CheckAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->cb2_tue->Location = System::Drawing::Point(242, 65);
			this->cb2_tue->Name = L"cb2_tue";
			this->cb2_tue->Size = System::Drawing::Size(27, 30);
			this->cb2_tue->TabIndex = 163;
			this->cb2_tue->Text = L"Tue";
			this->cb2_tue->UseVisualStyleBackColor = true;
			// 
			// cb2_mon
			// 
			this->cb2_mon->AutoSize = true;
			this->cb2_mon->CheckAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->cb2_mon->Location = System::Drawing::Point(209, 65);
			this->cb2_mon->Name = L"cb2_mon";
			this->cb2_mon->Size = System::Drawing::Size(31, 30);
			this->cb2_mon->TabIndex = 162;
			this->cb2_mon->Text = L"Mon";
			this->cb2_mon->UseVisualStyleBackColor = true;
			// 
			// cb2_sun
			// 
			this->cb2_sun->AutoSize = true;
			this->cb2_sun->CheckAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->cb2_sun->Location = System::Drawing::Point(183, 65);
			this->cb2_sun->Name = L"cb2_sun";
			this->cb2_sun->Size = System::Drawing::Size(27, 30);
			this->cb2_sun->TabIndex = 161;
			this->cb2_sun->Text = L"Sun";
			this->cb2_sun->UseVisualStyleBackColor = true;
			// 
			// cb4_sat
			// 
			this->cb4_sat->AutoSize = true;
			this->cb4_sat->CheckAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->cb4_sat->Location = System::Drawing::Point(372, 164);
			this->cb4_sat->Name = L"cb4_sat";
			this->cb4_sat->Size = System::Drawing::Size(23, 30);
			this->cb4_sat->TabIndex = 181;
			this->cb4_sat->Text = L"Sat";
			this->cb4_sat->UseVisualStyleBackColor = true;
			// 
			// cb4_fri
			// 
			this->cb4_fri->AutoSize = true;
			this->cb4_fri->CheckAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->cb4_fri->Location = System::Drawing::Point(342, 164);
			this->cb4_fri->Name = L"cb4_fri";
			this->cb4_fri->Size = System::Drawing::Size(22, 30);
			this->cb4_fri->TabIndex = 180;
			this->cb4_fri->Text = L"Fri";
			this->cb4_fri->UseVisualStyleBackColor = true;
			// 
			// cb4_thu
			// 
			this->cb4_thu->AutoSize = true;
			this->cb4_thu->CheckAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->cb4_thu->Location = System::Drawing::Point(307, 164);
			this->cb4_thu->Name = L"cb4_thu";
			this->cb4_thu->Size = System::Drawing::Size(28, 30);
			this->cb4_thu->TabIndex = 179;
			this->cb4_thu->Text = L"Thu";
			this->cb4_thu->UseVisualStyleBackColor = true;
			// 
			// cb4_wed
			// 
			this->cb4_wed->AutoSize = true;
			this->cb4_wed->CheckAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->cb4_wed->Location = System::Drawing::Point(273, 164);
			this->cb4_wed->Name = L"cb4_wed";
			this->cb4_wed->Size = System::Drawing::Size(31, 30);
			this->cb4_wed->TabIndex = 178;
			this->cb4_wed->Text = L"Wed";
			this->cb4_wed->UseVisualStyleBackColor = true;
			// 
			// cb4_tue
			// 
			this->cb4_tue->AutoSize = true;
			this->cb4_tue->CheckAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->cb4_tue->Location = System::Drawing::Point(242, 164);
			this->cb4_tue->Name = L"cb4_tue";
			this->cb4_tue->Size = System::Drawing::Size(27, 30);
			this->cb4_tue->TabIndex = 177;
			this->cb4_tue->Text = L"Tue";
			this->cb4_tue->UseVisualStyleBackColor = true;
			// 
			// cb4_mon
			// 
			this->cb4_mon->AutoSize = true;
			this->cb4_mon->CheckAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->cb4_mon->Location = System::Drawing::Point(209, 164);
			this->cb4_mon->Name = L"cb4_mon";
			this->cb4_mon->Size = System::Drawing::Size(31, 30);
			this->cb4_mon->TabIndex = 176;
			this->cb4_mon->Text = L"Mon";
			this->cb4_mon->UseVisualStyleBackColor = true;
			// 
			// cb4_sun
			// 
			this->cb4_sun->AutoSize = true;
			this->cb4_sun->CheckAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->cb4_sun->Location = System::Drawing::Point(183, 164);
			this->cb4_sun->Name = L"cb4_sun";
			this->cb4_sun->Size = System::Drawing::Size(27, 30);
			this->cb4_sun->TabIndex = 175;
			this->cb4_sun->Text = L"Sun";
			this->cb4_sun->UseVisualStyleBackColor = true;
			// 
			// cb3_sat
			// 
			this->cb3_sat->AutoSize = true;
			this->cb3_sat->CheckAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->cb3_sat->Location = System::Drawing::Point(372, 114);
			this->cb3_sat->Name = L"cb3_sat";
			this->cb3_sat->Size = System::Drawing::Size(23, 30);
			this->cb3_sat->TabIndex = 174;
			this->cb3_sat->Text = L"Sat";
			this->cb3_sat->UseVisualStyleBackColor = true;
			// 
			// cb3_fri
			// 
			this->cb3_fri->AutoSize = true;
			this->cb3_fri->CheckAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->cb3_fri->Location = System::Drawing::Point(342, 114);
			this->cb3_fri->Name = L"cb3_fri";
			this->cb3_fri->Size = System::Drawing::Size(22, 30);
			this->cb3_fri->TabIndex = 173;
			this->cb3_fri->Text = L"Fri";
			this->cb3_fri->UseVisualStyleBackColor = true;
			// 
			// cb3_thu
			// 
			this->cb3_thu->AutoSize = true;
			this->cb3_thu->CheckAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->cb3_thu->Location = System::Drawing::Point(307, 114);
			this->cb3_thu->Name = L"cb3_thu";
			this->cb3_thu->Size = System::Drawing::Size(28, 30);
			this->cb3_thu->TabIndex = 172;
			this->cb3_thu->Text = L"Thu";
			this->cb3_thu->UseVisualStyleBackColor = true;
			// 
			// cb3_wed
			// 
			this->cb3_wed->AutoSize = true;
			this->cb3_wed->CheckAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->cb3_wed->Location = System::Drawing::Point(273, 114);
			this->cb3_wed->Name = L"cb3_wed";
			this->cb3_wed->Size = System::Drawing::Size(31, 30);
			this->cb3_wed->TabIndex = 171;
			this->cb3_wed->Text = L"Wed";
			this->cb3_wed->UseVisualStyleBackColor = true;
			// 
			// cb3_tue
			// 
			this->cb3_tue->AutoSize = true;
			this->cb3_tue->CheckAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->cb3_tue->Location = System::Drawing::Point(242, 114);
			this->cb3_tue->Name = L"cb3_tue";
			this->cb3_tue->Size = System::Drawing::Size(27, 30);
			this->cb3_tue->TabIndex = 170;
			this->cb3_tue->Text = L"Tue";
			this->cb3_tue->UseVisualStyleBackColor = true;
			// 
			// cb3_mon
			// 
			this->cb3_mon->AutoSize = true;
			this->cb3_mon->CheckAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->cb3_mon->Location = System::Drawing::Point(209, 114);
			this->cb3_mon->Name = L"cb3_mon";
			this->cb3_mon->Size = System::Drawing::Size(31, 30);
			this->cb3_mon->TabIndex = 169;
			this->cb3_mon->Text = L"Mon";
			this->cb3_mon->UseVisualStyleBackColor = true;
			// 
			// cb3_sun
			// 
			this->cb3_sun->AutoSize = true;
			this->cb3_sun->CheckAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->cb3_sun->Location = System::Drawing::Point(183, 114);
			this->cb3_sun->Name = L"cb3_sun";
			this->cb3_sun->Size = System::Drawing::Size(27, 30);
			this->cb3_sun->TabIndex = 168;
			this->cb3_sun->Text = L"Sun";
			this->cb3_sun->UseVisualStyleBackColor = true;
			// 
			// EcoSchedule_Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(408, 243);
			this->Controls->Add(this->cb4_sat);
			this->Controls->Add(this->cb4_fri);
			this->Controls->Add(this->cb4_thu);
			this->Controls->Add(this->cb4_wed);
			this->Controls->Add(this->cb4_tue);
			this->Controls->Add(this->cb4_mon);
			this->Controls->Add(this->cb4_sun);
			this->Controls->Add(this->cb3_sat);
			this->Controls->Add(this->cb3_fri);
			this->Controls->Add(this->cb3_thu);
			this->Controls->Add(this->cb3_wed);
			this->Controls->Add(this->cb3_tue);
			this->Controls->Add(this->cb3_mon);
			this->Controls->Add(this->cb3_sun);
			this->Controls->Add(this->cb2_sat);
			this->Controls->Add(this->cb2_fri);
			this->Controls->Add(this->cb2_thu);
			this->Controls->Add(this->cb2_wed);
			this->Controls->Add(this->cb2_tue);
			this->Controls->Add(this->cb2_mon);
			this->Controls->Add(this->cb2_sun);
			this->Controls->Add(this->cb1_sat);
			this->Controls->Add(this->cb1_fri);
			this->Controls->Add(this->cb1_thu);
			this->Controls->Add(this->cb1_wed);
			this->Controls->Add(this->cb1_tue);
			this->Controls->Add(this->cb1_mon);
			this->Controls->Add(this->cb1_sun);
			this->Controls->Add(this->button_Save);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->cmbx_EC4_DT_min);
			this->Controls->Add(this->lbl_EC4_ST);
			this->Controls->Add(this->cmbx_EC4_DT_hour);
			this->Controls->Add(this->cmbx_EC4_ST_hour);
			this->Controls->Add(this->lbl_EC4_DT);
			this->Controls->Add(this->cmbx_EC4_ST_min);
			this->Controls->Add(this->cmbx_EC3_DT_min);
			this->Controls->Add(this->lbl_EC3_ST);
			this->Controls->Add(this->cmbx_EC3_DT_hour);
			this->Controls->Add(this->cmbx_EC3_ST_hour);
			this->Controls->Add(this->lbl_EC3_DT);
			this->Controls->Add(this->cmbx_EC3_ST_min);
			this->Controls->Add(this->cmbx_EC2_DT_min);
			this->Controls->Add(this->ibl_EC2_ST);
			this->Controls->Add(this->cmbx_EC2_DT_hour);
			this->Controls->Add(this->cmbx_EC2_ST_hour);
			this->Controls->Add(this->lbl_EC2_DT);
			this->Controls->Add(this->cmbx_EC2_ST_min);
			this->Controls->Add(this->cmbx_EC1_DT_min);
			this->Controls->Add(this->lbl_EC1_ST);
			this->Controls->Add(this->cmbx_EC1_DT_hour);
			this->Controls->Add(this->cmbx_EC1_ST_hour);
			this->Controls->Add(this->lbl_EC1_DT);
			this->Controls->Add(this->cmbx_EC1_ST_min);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"EcoSchedule_Form";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"ECO filteration Schedule";
			this->TopMost = true;
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &EcoSchedule_Form::EcoSchedule_Form_FormClosed);
			this->Load += gcnew System::EventHandler(this, &EcoSchedule_Form::EcoSchedule_Form_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void EcoSchedule_Form_Load(System::Object^  sender, System::EventArgs^  e);
	private: System::Void button_Save_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void EcoSchedule_Form_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e);
};
}
