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
	/// Summary for set_SF_Form
	/// </summary>
	public ref class set_SF_Form : public System::Windows::Forms::Form
	{
	public:
		set_SF_Form(RDS_main_Form^ pForm)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			m_MainForm = pForm;
		}
	public: RDS_main_Form^ m_MainForm;
			unsigned int sf_value;

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~set_SF_Form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Label^  label_SF3;
	private: System::Windows::Forms::Label^  label_SF2;
	private: System::Windows::Forms::Label^  label_SF1;
	private: System::Windows::Forms::Label^  label_SF0;
	private: System::Windows::Forms::RadioButton^  radioButton_SF3;
	private: System::Windows::Forms::RadioButton^  radioButton_SF2;
	private: System::Windows::Forms::RadioButton^  radioButton_SF1;
	private: System::Windows::Forms::RadioButton^  radioButton_SF0;
	private: System::Windows::Forms::Button^  button_Save;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(set_SF_Form::typeid));
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label_SF3 = (gcnew System::Windows::Forms::Label());
			this->label_SF2 = (gcnew System::Windows::Forms::Label());
			this->label_SF1 = (gcnew System::Windows::Forms::Label());
			this->label_SF0 = (gcnew System::Windows::Forms::Label());
			this->radioButton_SF3 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton_SF2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton_SF1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton_SF0 = (gcnew System::Windows::Forms::RadioButton());
			this->button_Save = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label_SF3);
			this->groupBox1->Controls->Add(this->label_SF2);
			this->groupBox1->Controls->Add(this->label_SF1);
			this->groupBox1->Controls->Add(this->label_SF0);
			this->groupBox1->Controls->Add(this->radioButton_SF3);
			this->groupBox1->Controls->Add(this->radioButton_SF2);
			this->groupBox1->Controls->Add(this->radioButton_SF1);
			this->groupBox1->Controls->Add(this->radioButton_SF0);
			this->groupBox1->Location = System::Drawing::Point(4, 1);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(324, 109);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"SF";
			// 
			// label_SF3
			// 
			this->label_SF3->AutoSize = true;
			this->label_SF3->Location = System::Drawing::Point(66, 84);
			this->label_SF3->Name = L"label_SF3";
			this->label_SF3->Size = System::Drawing::Size(246, 12);
			this->label_SF3->TabIndex = 7;
			this->label_SF3->Text = L"At (00:00, 6:00, 12:00, 18:00) do filteration 10 min";
			// 
			// label_SF2
			// 
			this->label_SF2->AutoSize = true;
			this->label_SF2->Location = System::Drawing::Point(67, 62);
			this->label_SF2->Name = L"label_SF2";
			this->label_SF2->Size = System::Drawing::Size(213, 12);
			this->label_SF2->TabIndex = 6;
			this->label_SF2->Text = L"At (00:00, 8:00, 16:00) do filteration 10 min";
			// 
			// label_SF1
			// 
			this->label_SF1->AutoSize = true;
			this->label_SF1->Location = System::Drawing::Point(67, 40);
			this->label_SF1->Name = L"label_SF1";
			this->label_SF1->Size = System::Drawing::Size(190, 12);
			this->label_SF1->TabIndex = 5;
			this->label_SF1->Text = L"At (00:00, 12:00) do filterarion 10 min ";
			// 
			// label_SF0
			// 
			this->label_SF0->AutoSize = true;
			this->label_SF0->Location = System::Drawing::Point(67, 18);
			this->label_SF0->Name = L"label_SF0";
			this->label_SF0->Size = System::Drawing::Size(70, 12);
			this->label_SF0->TabIndex = 4;
			this->label_SF0->Text = L"No filteration ";
			// 
			// radioButton_SF3
			// 
			this->radioButton_SF3->AutoSize = true;
			this->radioButton_SF3->Location = System::Drawing::Point(19, 82);
			this->radioButton_SF3->Name = L"radioButton_SF3";
			this->radioButton_SF3->Size = System::Drawing::Size(41, 16);
			this->radioButton_SF3->TabIndex = 3;
			this->radioButton_SF3->Text = L"SF3";
			this->radioButton_SF3->UseVisualStyleBackColor = true;
			this->radioButton_SF3->CheckedChanged += gcnew System::EventHandler(this, &set_SF_Form::radioButton_SF3_CheckedChanged);
			// 
			// radioButton_SF2
			// 
			this->radioButton_SF2->AutoSize = true;
			this->radioButton_SF2->Location = System::Drawing::Point(19, 60);
			this->radioButton_SF2->Name = L"radioButton_SF2";
			this->radioButton_SF2->Size = System::Drawing::Size(41, 16);
			this->radioButton_SF2->TabIndex = 2;
			this->radioButton_SF2->Text = L"SF2";
			this->radioButton_SF2->UseVisualStyleBackColor = true;
			this->radioButton_SF2->CheckedChanged += gcnew System::EventHandler(this, &set_SF_Form::radioButton_SF2_CheckedChanged);
			// 
			// radioButton_SF1
			// 
			this->radioButton_SF1->AutoSize = true;
			this->radioButton_SF1->Location = System::Drawing::Point(19, 38);
			this->radioButton_SF1->Name = L"radioButton_SF1";
			this->radioButton_SF1->Size = System::Drawing::Size(41, 16);
			this->radioButton_SF1->TabIndex = 1;
			this->radioButton_SF1->Text = L"SF1";
			this->radioButton_SF1->UseVisualStyleBackColor = true;
			this->radioButton_SF1->CheckedChanged += gcnew System::EventHandler(this, &set_SF_Form::radioButton_SF1_CheckedChanged);
			// 
			// radioButton_SF0
			// 
			this->radioButton_SF0->AutoSize = true;
			this->radioButton_SF0->Checked = true;
			this->radioButton_SF0->Location = System::Drawing::Point(19, 16);
			this->radioButton_SF0->Name = L"radioButton_SF0";
			this->radioButton_SF0->Size = System::Drawing::Size(41, 16);
			this->radioButton_SF0->TabIndex = 0;
			this->radioButton_SF0->TabStop = true;
			this->radioButton_SF0->Text = L"SF0";
			this->radioButton_SF0->UseVisualStyleBackColor = true;
			this->radioButton_SF0->CheckedChanged += gcnew System::EventHandler(this, &set_SF_Form::radioButton_SF0_CheckedChanged);
			// 
			// button_Save
			// 
			this->button_Save->Location = System::Drawing::Point(59, 116);
			this->button_Save->Name = L"button_Save";
			this->button_Save->Size = System::Drawing::Size(191, 32);
			this->button_Save->TabIndex = 1;
			this->button_Save->Text = L"Save to SPA";
			this->button_Save->UseVisualStyleBackColor = true;
			this->button_Save->Click += gcnew System::EventHandler(this, &set_SF_Form::button_Save_Click);
			// 
			// set_SF_Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(333, 153);
			this->Controls->Add(this->button_Save);
			this->Controls->Add(this->groupBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"set_SF_Form";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"SF Filteration";
			this->TopMost = true;
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &set_SF_Form::set_SF_Form_FormClosed);
			this->Load += gcnew System::EventHandler(this, &set_SF_Form::set_SF_Form_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void set_SF_Form_Load(System::Object^  sender, System::EventArgs^  e);
private: System::Void button_Save_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void radioButton_SF0_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
private: System::Void radioButton_SF1_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
private: System::Void radioButton_SF2_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
private: System::Void radioButton_SF3_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
private: System::Void set_SF_Form_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e);
};
}
