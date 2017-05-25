#pragma once

#include "RDS_main_Form.h"

//for internal objects
#include "nas_user.h"

namespace RDS {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    /// <summary>
    /// Summary for login
    /// </summary>
    public ref class login : public System::Windows::Forms::Form
    {
    public:
        login(RDS_main_Form^ pForm)
        {
            InitializeComponent();
            //
            //TODO: Add the constructor code here
            //
            m_MainForm = pForm;
        }
    public: RDS_main_Form^ m_MainForm;
    private: System::Windows::Forms::Label^  label_ComName;
    public:
    private: System::Windows::Forms::Label^  label_CompanyName;
    private: System::Windows::Forms::TextBox^  textBox_CompanyCode;
    private: System::Windows::Forms::Label^  label_CompanyCode;

             //include objects here.....
             RDS_NAS::nas_user iNas;

    protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~login()
        {
            if (components)
            {
                delete components;
            }
        }
    private: System::Windows::Forms::Panel^  panel1;
    protected:
    private: System::Windows::Forms::Label^  label_msg;
    private: System::Windows::Forms::Button^  button_Exit;
    private: System::Windows::Forms::Button^  button_login;
    private: System::Windows::Forms::TextBox^  textBox_PW;
    private: System::Windows::Forms::TextBox^  textBox_ID;
    private: System::Windows::Forms::Label^  label_PW;
    private: System::Windows::Forms::Label^  label_ID;
    private: System::Windows::Forms::Panel^  panel_title;
    private: System::Windows::Forms::Label^  label_Title;

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
            System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(login::typeid));
            this->panel1 = (gcnew System::Windows::Forms::Panel());
            this->label_ComName = (gcnew System::Windows::Forms::Label());
            this->label_CompanyName = (gcnew System::Windows::Forms::Label());
            this->textBox_CompanyCode = (gcnew System::Windows::Forms::TextBox());
            this->label_CompanyCode = (gcnew System::Windows::Forms::Label());
            this->button_Exit = (gcnew System::Windows::Forms::Button());
            this->button_login = (gcnew System::Windows::Forms::Button());
            this->label_msg = (gcnew System::Windows::Forms::Label());
            this->textBox_PW = (gcnew System::Windows::Forms::TextBox());
            this->textBox_ID = (gcnew System::Windows::Forms::TextBox());
            this->label_PW = (gcnew System::Windows::Forms::Label());
            this->label_ID = (gcnew System::Windows::Forms::Label());
            this->panel_title = (gcnew System::Windows::Forms::Panel());
            this->label_Title = (gcnew System::Windows::Forms::Label());
            this->panel1->SuspendLayout();
            this->panel_title->SuspendLayout();
            this->SuspendLayout();
            // 
            // panel1
            // 
            this->panel1->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
            this->panel1->Controls->Add(this->label_ComName);
            this->panel1->Controls->Add(this->label_CompanyName);
            this->panel1->Controls->Add(this->textBox_CompanyCode);
            this->panel1->Controls->Add(this->label_CompanyCode);
            this->panel1->Controls->Add(this->button_Exit);
            this->panel1->Controls->Add(this->button_login);
            this->panel1->Controls->Add(this->label_msg);
            this->panel1->Controls->Add(this->textBox_PW);
            this->panel1->Controls->Add(this->textBox_ID);
            this->panel1->Controls->Add(this->label_PW);
            this->panel1->Controls->Add(this->label_ID);
            this->panel1->Location = System::Drawing::Point(1, 71);
            this->panel1->Name = L"panel1";
            this->panel1->Size = System::Drawing::Size(435, 303);
            this->panel1->TabIndex = 7;
            // 
            // label_ComName
            // 
            this->label_ComName->AutoSize = true;
            this->label_ComName->Font = (gcnew System::Drawing::Font(L"PMingLiU", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->label_ComName->ForeColor = System::Drawing::Color::White;
            this->label_ComName->Location = System::Drawing::Point(216, 68);
            this->label_ComName->Name = L"label_ComName";
            this->label_ComName->Size = System::Drawing::Size(185, 19);
            this->label_ComName->TabIndex = 22;
            this->label_ComName->Text = L"show company name ";
            // 
            // label_CompanyName
            // 
            this->label_CompanyName->AutoSize = true;
            this->label_CompanyName->Font = (gcnew System::Drawing::Font(L"PMingLiU", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->label_CompanyName->ForeColor = System::Drawing::Color::White;
            this->label_CompanyName->Location = System::Drawing::Point(11, 63);
            this->label_CompanyName->Name = L"label_CompanyName";
            this->label_CompanyName->Size = System::Drawing::Size(183, 24);
            this->label_CompanyName->TabIndex = 24;
            this->label_CompanyName->Text = L"Company Name :";
            // 
            // textBox_CompanyCode
            // 
            this->textBox_CompanyCode->Font = (gcnew System::Drawing::Font(L"PMingLiU", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->textBox_CompanyCode->Location = System::Drawing::Point(211, 23);
            this->textBox_CompanyCode->Name = L"textBox_CompanyCode";
            this->textBox_CompanyCode->Size = System::Drawing::Size(201, 27);
            this->textBox_CompanyCode->TabIndex = 1;
            this->textBox_CompanyCode->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
            this->textBox_CompanyCode->TextChanged += gcnew System::EventHandler(this, &login::textBox_CompanyCode_TextChanged);
            // 
            // label_CompanyCode
            // 
            this->label_CompanyCode->AutoSize = true;
            this->label_CompanyCode->Font = (gcnew System::Drawing::Font(L"PMingLiU", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->label_CompanyCode->ForeColor = System::Drawing::Color::White;
            this->label_CompanyCode->Location = System::Drawing::Point(11, 23);
            this->label_CompanyCode->Name = L"label_CompanyCode";
            this->label_CompanyCode->Size = System::Drawing::Size(176, 24);
            this->label_CompanyCode->TabIndex = 23;
            this->label_CompanyCode->Text = L"Company Code :";
            // 
            // button_Exit
            // 
            this->button_Exit->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
            this->button_Exit->Font = (gcnew System::Drawing::Font(L"PMingLiU", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->button_Exit->Location = System::Drawing::Point(291, 240);
            this->button_Exit->Name = L"button_Exit";
            this->button_Exit->Size = System::Drawing::Size(121, 31);
            this->button_Exit->TabIndex = 5;
            this->button_Exit->Text = L"Exit";
            this->button_Exit->UseVisualStyleBackColor = true;
            this->button_Exit->Click += gcnew System::EventHandler(this, &login::button_Exit_Click);
            // 
            // button_login
            // 
            this->button_login->Font = (gcnew System::Drawing::Font(L"PMingLiU", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->button_login->Location = System::Drawing::Point(64, 240);
            this->button_login->Name = L"button_login";
            this->button_login->Size = System::Drawing::Size(191, 31);
            this->button_login->TabIndex = 4;
            this->button_login->Text = L"LogIn";
            this->button_login->UseVisualStyleBackColor = true;
            this->button_login->Click += gcnew System::EventHandler(this, &login::button_login_Click);
            // 
            // label_msg
            // 
            this->label_msg->AutoSize = true;
            this->label_msg->Font = (gcnew System::Drawing::Font(L"PMingLiU", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->label_msg->ForeColor = System::Drawing::Color::White;
            this->label_msg->Location = System::Drawing::Point(11, 243);
            this->label_msg->Name = L"label_msg";
            this->label_msg->Size = System::Drawing::Size(0, 16);
            this->label_msg->TabIndex = 13;
            // 
            // textBox_PW
            // 
            this->textBox_PW->Font = (gcnew System::Drawing::Font(L"PMingLiU", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->textBox_PW->Location = System::Drawing::Point(155, 181);
            this->textBox_PW->Name = L"textBox_PW";
            this->textBox_PW->PasswordChar = '*';
            this->textBox_PW->Size = System::Drawing::Size(257, 27);
            this->textBox_PW->TabIndex = 3;
            this->textBox_PW->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
            // 
            // textBox_ID
            // 
            this->textBox_ID->Font = (gcnew System::Drawing::Font(L"PMingLiU", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->textBox_ID->Location = System::Drawing::Point(155, 124);
            this->textBox_ID->Name = L"textBox_ID";
            this->textBox_ID->Size = System::Drawing::Size(257, 27);
            this->textBox_ID->TabIndex = 2;
            this->textBox_ID->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
            // 
            // label_PW
            // 
            this->label_PW->AutoSize = true;
            this->label_PW->Font = (gcnew System::Drawing::Font(L"PMingLiU", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->label_PW->ForeColor = System::Drawing::Color::White;
            this->label_PW->Location = System::Drawing::Point(22, 180);
            this->label_PW->Name = L"label_PW";
            this->label_PW->Size = System::Drawing::Size(119, 24);
            this->label_PW->TabIndex = 8;
            this->label_PW->Text = L"Password :";
            // 
            // label_ID
            // 
            this->label_ID->AutoSize = true;
            this->label_ID->Font = (gcnew System::Drawing::Font(L"PMingLiU", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->label_ID->ForeColor = System::Drawing::Color::White;
            this->label_ID->Location = System::Drawing::Point(29, 127);
            this->label_ID->Name = L"label_ID";
            this->label_ID->Size = System::Drawing::Size(104, 24);
            this->label_ID->TabIndex = 7;
            this->label_ID->Text = L"User ID :";
            // 
            // panel_title
            // 
            this->panel_title->BackColor = System::Drawing::Color::LightGray;
            this->panel_title->Controls->Add(this->label_Title);
            this->panel_title->Location = System::Drawing::Point(2, 2);
            this->panel_title->Name = L"panel_title";
            this->panel_title->Size = System::Drawing::Size(434, 68);
            this->panel_title->TabIndex = 6;
            // 
            // label_Title
            // 
            this->label_Title->AutoSize = true;
            this->label_Title->Font = (gcnew System::Drawing::Font(L"PMingLiU", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->label_Title->ForeColor = System::Drawing::Color::Black;
            this->label_Title->Location = System::Drawing::Point(40, 16);
            this->label_Title->Name = L"label_Title";
            this->label_Title->Size = System::Drawing::Size(340, 29);
            this->label_Title->TabIndex = 0;
            this->label_Title->Text = L"Remote Diagnostic System";
            this->label_Title->TextAlign = System::Drawing::ContentAlignment::TopCenter;
            // 
            // login
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->AutoScroll = true;
            this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
            this->ClientSize = System::Drawing::Size(436, 374);
            this->ControlBox = false;
            this->Controls->Add(this->panel1);
            this->Controls->Add(this->panel_title);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
            this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
            this->MaximizeBox = false;
            this->MinimizeBox = false;
            this->Name = L"login";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"login";
            this->Load += gcnew System::EventHandler(this, &login::login_Load);
            this->panel1->ResumeLayout(false);
            this->panel1->PerformLayout();
            this->panel_title->ResumeLayout(false);
            this->panel_title->PerformLayout();
            this->ResumeLayout(false);

        }
#pragma endregion
    private: System::Void login_Load(System::Object^  sender, System::EventArgs^  e);
             //
    private: System::Void button_login_Click(System::Object^  sender, System::EventArgs^  e);
    private: System::Void button_Exit_Click(System::Object^  sender, System::EventArgs^  e);
             //
    private: System::Void textBox_CompanyCode_TextChanged(System::Object^  sender, System::EventArgs^  e);
    };
}
