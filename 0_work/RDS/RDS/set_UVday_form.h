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
	/// Summary for set_UVday_form
	/// </summary>
	public ref class set_UVday_form : public System::Windows::Forms::Form
	{
	public:
		set_UVday_form(RDS_main_Form^ pForm)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			m_MainForm = pForm;
		}
	public: String^ SetUVday_Msg;
			RDS_main_Form^ m_MainForm;

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~set_UVday_form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBox_UV_Days;
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(set_UVday_form::typeid));
			this->textBox_UV_Days = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// textBox_UV_Days
			// 
			this->textBox_UV_Days->Font = (gcnew System::Drawing::Font(L"AVGmdBU", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->textBox_UV_Days->Location = System::Drawing::Point(23, 15);
			this->textBox_UV_Days->Name = L"textBox_UV_Days";
			this->textBox_UV_Days->Size = System::Drawing::Size(68, 40);
			this->textBox_UV_Days->TabIndex = 2;
			this->textBox_UV_Days->Text = L"300";
			this->textBox_UV_Days->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// set_UVday_form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::SteelBlue;
			this->ClientSize = System::Drawing::Size(116, 71);
			this->Controls->Add(this->textBox_UV_Days);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->KeyPreview = true;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"set_UVday_form";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"UV Days";
			this->TopMost = true;
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &set_UVday_form::set_UVday_form_FormClosed);
			this->Load += gcnew System::EventHandler(this, &set_UVday_form::set_UVday_form_Load);
			this->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &set_UVday_form::set_UVday_form_KeyPress);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void set_UVday_form_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e);
	private: System::Void set_UVday_form_Load(System::Object^  sender, System::EventArgs^  e);
	private: System::Void set_UVday_form_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e);
	};
}
