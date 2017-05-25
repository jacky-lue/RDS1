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
	/// Summary for set_T_form
	/// </summary>
	public ref class set_T_form : public System::Windows::Forms::Form
	{
	public:
		set_T_form(RDS_main_Form^ pForm)
		//set_T_form(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			m_MainForm = pForm;
		}

	public: String^ SetTempr_Msg;
			RDS_main_Form^ m_MainForm;

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~set_T_form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBox_Set_T;
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(set_T_form::typeid));
			this->textBox_Set_T = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// textBox_Set_T
			// 
			this->textBox_Set_T->BackColor = System::Drawing::Color::White;
			this->textBox_Set_T->Font = (gcnew System::Drawing::Font(L"AVGmdBU", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox_Set_T->Location = System::Drawing::Point(12, 9);
			this->textBox_Set_T->Name = L"textBox_Set_T";
			this->textBox_Set_T->Size = System::Drawing::Size(129, 57);
			this->textBox_Set_T->TabIndex = 9;
			this->textBox_Set_T->Text = L"xx.xC";
			this->textBox_Set_T->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// set_T_form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Navy;
			this->ClientSize = System::Drawing::Size(161, 74);
			this->Controls->Add(this->textBox_Set_T);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->KeyPreview = true;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"set_T_form";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"Set Temperature";
			this->TopMost = true;
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &set_T_form::set_T_form_FormClosed);
			this->Load += gcnew System::EventHandler(this, &set_T_form::set_T_form_Load);
			this->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &set_T_form::set_T_form_KeyPress);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void set_T_form_Load(System::Object^  sender, System::EventArgs^  e);
	private: System::Void set_T_form_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e);
	private: System::Void set_T_form_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e);
	};
}
