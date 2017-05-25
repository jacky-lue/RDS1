#pragma once

//for internal objects
#include "nas_state.h"

namespace RDSadmin {
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    /// <summary>
    /// Summary for login
    /// </summary>
    public ref class login: public System::Windows::Forms::Form
    {
    public:
        login()
        {
            InitializeComponent();
            //
            //TODO: Add the constructor code here
            //
        }
        //include objects here.....
        RDS_NAS::nas_state iNas;
        String^ Spa_Company_Code;
        String^ Spa_Company_Name;
        Boolean Root_Has_AdminIni;

    private: System::Windows::Forms::Button^  button_Exit;
    private: System::Windows::Forms::Button^  button_Forget;
    private: System::Windows::Forms::Panel^  panel_SQ;
    private: System::Windows::Forms::Label^  label_SQuestion;
    private: System::Windows::Forms::Button^  button_EnterAns;
    private: System::Windows::Forms::TextBox^  textBox_answer;
    private: System::Windows::Forms::Label^  label_answer;
    private: System::Windows::Forms::Label^  label_SecurityQ;
    private: System::Windows::Forms::Label^  label_Disp_PW;
    private: System::Windows::Forms::Label^  label_wrong;
    private: System::Windows::Forms::Label^  label_CompanyCode;
    private: System::Windows::Forms::TextBox^  textBox_CompanyCode;
    private: System::Windows::Forms::Label^  label_ComName;

    private: System::Windows::Forms::Label^  label_CompanyName;

    private: System::Windows::Forms::Label^  label_msg;
    protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~login()
        {
            if(components)
            {
                delete components;
            }
        }
    private: System::Windows::Forms::Label^  label_Title;
    protected:
    private: System::Windows::Forms::Panel^  panel_title;
    private: System::Windows::Forms::Panel^  panel1;
    private: System::Windows::Forms::Button^  button_login;
    private: System::Windows::Forms::TextBox^  textBox_PW;
    private: System::Windows::Forms::TextBox^  textBox_ID;
    private: System::Windows::Forms::Label^  label_PW;
    private: System::Windows::Forms::Label^  label_ID;

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
            System::ComponentModel::ComponentResourceManager^  resources=(gcnew System::ComponentModel::ComponentResourceManager(login::typeid));
            this->label_Title=(gcnew System::Windows::Forms::Label());
            this->panel_title=(gcnew System::Windows::Forms::Panel());
            this->panel1=(gcnew System::Windows::Forms::Panel());
            this->label_ComName=(gcnew System::Windows::Forms::Label());
            this->label_CompanyName=(gcnew System::Windows::Forms::Label());
            this->textBox_CompanyCode=(gcnew System::Windows::Forms::TextBox());
            this->label_CompanyCode=(gcnew System::Windows::Forms::Label());
            this->label_Disp_PW=(gcnew System::Windows::Forms::Label());
            this->button_Forget=(gcnew System::Windows::Forms::Button());
            this->label_msg=(gcnew System::Windows::Forms::Label());
            this->button_Exit=(gcnew System::Windows::Forms::Button());
            this->button_login=(gcnew System::Windows::Forms::Button());
            this->textBox_PW=(gcnew System::Windows::Forms::TextBox());
            this->textBox_ID=(gcnew System::Windows::Forms::TextBox());
            this->label_PW=(gcnew System::Windows::Forms::Label());
            this->label_ID=(gcnew System::Windows::Forms::Label());
            this->panel_SQ=(gcnew System::Windows::Forms::Panel());
            this->label_wrong=(gcnew System::Windows::Forms::Label());
            this->label_SQuestion=(gcnew System::Windows::Forms::Label());
            this->button_EnterAns=(gcnew System::Windows::Forms::Button());
            this->textBox_answer=(gcnew System::Windows::Forms::TextBox());
            this->label_answer=(gcnew System::Windows::Forms::Label());
            this->label_SecurityQ=(gcnew System::Windows::Forms::Label());
            this->panel_title->SuspendLayout();
            this->panel1->SuspendLayout();
            this->panel_SQ->SuspendLayout();
            this->SuspendLayout();
            //
            // label_Title
            //
            this->label_Title->AutoSize=true;
            this->label_Title->Font=(gcnew System::Drawing::Font(L"PMingLiU", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->label_Title->ForeColor=System::Drawing::Color::Black;
            this->label_Title->Location=System::Drawing::Point(54, 5);
            this->label_Title->Name=L"label_Title";
            this->label_Title->Size=System::Drawing::Size(340, 58);
            this->label_Title->TabIndex=0;
            this->label_Title->Text=L"Remote Diagnostic System\r\nAdmin";
            this->label_Title->TextAlign=System::Drawing::ContentAlignment::TopCenter;
            //
            // panel_title
            //
            this->panel_title->BackColor=System::Drawing::Color::LightGray;
            this->panel_title->Controls->Add(this->label_Title);
            this->panel_title->Location=System::Drawing::Point(-9, 0);
            this->panel_title->Name=L"panel_title";
            this->panel_title->Size=System::Drawing::Size(441, 68);
            this->panel_title->TabIndex=4;
            //
            // panel1
            //
            this->panel1->BackColor=System::Drawing::SystemColors::ActiveCaptionText;
            this->panel1->Controls->Add(this->label_ComName);
            this->panel1->Controls->Add(this->label_CompanyName);
            this->panel1->Controls->Add(this->textBox_CompanyCode);
            this->panel1->Controls->Add(this->label_CompanyCode);
            this->panel1->Controls->Add(this->label_Disp_PW);
            this->panel1->Controls->Add(this->button_Forget);
            this->panel1->Controls->Add(this->label_msg);
            this->panel1->Controls->Add(this->button_Exit);
            this->panel1->Controls->Add(this->button_login);
            this->panel1->Controls->Add(this->textBox_PW);
            this->panel1->Controls->Add(this->textBox_ID);
            this->panel1->Controls->Add(this->label_PW);
            this->panel1->Controls->Add(this->label_ID);
            this->panel1->Location=System::Drawing::Point(1, 68);
            this->panel1->Name=L"panel1";
            this->panel1->Size=System::Drawing::Size(431, 302);
            this->panel1->TabIndex=5;
            //
            // label_ComName
            //
            this->label_ComName->AutoSize=true;
            this->label_ComName->Font=(gcnew System::Drawing::Font(L"PMingLiU", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->label_ComName->ForeColor=System::Drawing::Color::White;
            this->label_ComName->Location=System::Drawing::Point(223, 69);
            this->label_ComName->Name=L"label_ComName";
            this->label_ComName->Size=System::Drawing::Size(185, 19);
            this->label_ComName->TabIndex=18;
            this->label_ComName->Text=L"show company name ";
            //
            // label_CompanyName
            //
            this->label_CompanyName->AutoSize=true;
            this->label_CompanyName->Font=(gcnew System::Drawing::Font(L"PMingLiU", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->label_CompanyName->ForeColor=System::Drawing::Color::White;
            this->label_CompanyName->Location=System::Drawing::Point(18, 64);
            this->label_CompanyName->Name=L"label_CompanyName";
            this->label_CompanyName->Size=System::Drawing::Size(183, 24);
            this->label_CompanyName->TabIndex=20;
            this->label_CompanyName->Text=L"Company Name :";
            //
            // textBox_CompanyCode
            //
            this->textBox_CompanyCode->Font=(gcnew System::Drawing::Font(L"PMingLiU", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->textBox_CompanyCode->Location=System::Drawing::Point(218, 24);
            this->textBox_CompanyCode->Name=L"textBox_CompanyCode";
            this->textBox_CompanyCode->Size=System::Drawing::Size(201, 27);
            this->textBox_CompanyCode->TabIndex=1;
            this->textBox_CompanyCode->TextAlign=System::Windows::Forms::HorizontalAlignment::Center;
            this->textBox_CompanyCode->TextChanged+=gcnew System::EventHandler(this, &login::textBox_CompanyCode_TextChanged);
            //
            // label_CompanyCode
            //
            this->label_CompanyCode->AutoSize=true;
            this->label_CompanyCode->Font=(gcnew System::Drawing::Font(L"PMingLiU", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->label_CompanyCode->ForeColor=System::Drawing::Color::White;
            this->label_CompanyCode->Location=System::Drawing::Point(18, 24);
            this->label_CompanyCode->Name=L"label_CompanyCode";
            this->label_CompanyCode->Size=System::Drawing::Size(176, 24);
            this->label_CompanyCode->TabIndex=18;
            this->label_CompanyCode->Text=L"Company Code :";
            //
            // label_Disp_PW
            //
            this->label_Disp_PW->AutoSize=true;
            this->label_Disp_PW->Font=(gcnew System::Drawing::Font(L"PMingLiU", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->label_Disp_PW->ForeColor=System::Drawing::Color::White;
            this->label_Disp_PW->Location=System::Drawing::Point(150, 204);
            this->label_Disp_PW->Name=L"label_Disp_PW";
            this->label_Disp_PW->Size=System::Drawing::Size(107, 19);
            this->label_Disp_PW->TabIndex=17;
            this->label_Disp_PW->Text=L"Display PW";
            //
            // button_Forget
            //
            this->button_Forget->Font=(gcnew System::Drawing::Font(L"PMingLiU", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->button_Forget->Location=System::Drawing::Point(20, 242);
            this->button_Forget->Name=L"button_Forget";
            this->button_Forget->Size=System::Drawing::Size(132, 31);
            this->button_Forget->TabIndex=6;
            this->button_Forget->Text=L"Forget Password\?";
            this->button_Forget->UseVisualStyleBackColor=true;
            this->button_Forget->Click+=gcnew System::EventHandler(this, &login::button_Forget_Click);
            //
            // label_msg
            //
            this->label_msg->AutoSize=true;
            this->label_msg->Font=(gcnew System::Drawing::Font(L"PMingLiU", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->label_msg->ForeColor=System::Drawing::Color::White;
            this->label_msg->Location=System::Drawing::Point(11, 243);
            this->label_msg->Name=L"label_msg";
            this->label_msg->Size=System::Drawing::Size(0, 16);
            this->label_msg->TabIndex=13;
            //
            // button_Exit
            //
            this->button_Exit->Font=(gcnew System::Drawing::Font(L"PMingLiU", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->button_Exit->Location=System::Drawing::Point(334, 242);
            this->button_Exit->Name=L"button_Exit";
            this->button_Exit->Size=System::Drawing::Size(85, 31);
            this->button_Exit->TabIndex=5;
            this->button_Exit->Text=L"Exit";
            this->button_Exit->UseVisualStyleBackColor=true;
            this->button_Exit->Click+=gcnew System::EventHandler(this, &login::button_Exit_Click);
            //
            // button_login
            //
            this->button_login->Font=(gcnew System::Drawing::Font(L"PMingLiU", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->button_login->Location=System::Drawing::Point(180, 242);
            this->button_login->Name=L"button_login";
            this->button_login->Size=System::Drawing::Size(132, 31);
            this->button_login->TabIndex=4;
            this->button_login->Text=L"LogIn";
            this->button_login->UseVisualStyleBackColor=true;
            this->button_login->Click+=gcnew System::EventHandler(this, &login::button_login_Click);
            //
            // textBox_PW
            //
            this->textBox_PW->Font=(gcnew System::Drawing::Font(L"PMingLiU", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->textBox_PW->Location=System::Drawing::Point(170, 174);
            this->textBox_PW->Name=L"textBox_PW";
            this->textBox_PW->PasswordChar='*';
            this->textBox_PW->Size=System::Drawing::Size(249, 27);
            this->textBox_PW->TabIndex=3;
            this->textBox_PW->TextAlign=System::Windows::Forms::HorizontalAlignment::Center;
            //
            // textBox_ID
            //
            this->textBox_ID->Font=(gcnew System::Drawing::Font(L"PMingLiU", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->textBox_ID->Location=System::Drawing::Point(170, 120);
            this->textBox_ID->Name=L"textBox_ID";
            this->textBox_ID->Size=System::Drawing::Size(249, 27);
            this->textBox_ID->TabIndex=2;
            this->textBox_ID->TextAlign=System::Windows::Forms::HorizontalAlignment::Center;
            //
            // label_PW
            //
            this->label_PW->AutoSize=true;
            this->label_PW->Font=(gcnew System::Drawing::Font(L"PMingLiU", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->label_PW->ForeColor=System::Drawing::Color::White;
            this->label_PW->Location=System::Drawing::Point(28, 173);
            this->label_PW->Name=L"label_PW";
            this->label_PW->Size=System::Drawing::Size(119, 24);
            this->label_PW->TabIndex=8;
            this->label_PW->Text=L"Password :";
            //
            // label_ID
            //
            this->label_ID->AutoSize=true;
            this->label_ID->Font=(gcnew System::Drawing::Font(L"PMingLiU", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->label_ID->ForeColor=System::Drawing::Color::White;
            this->label_ID->Location=System::Drawing::Point(18, 123);
            this->label_ID->Name=L"label_ID";
            this->label_ID->Size=System::Drawing::Size(139, 24);
            this->label_ID->TabIndex=7;
            this->label_ID->Text=L"Account ID :";
            //
            // panel_SQ
            //
            this->panel_SQ->BackColor=System::Drawing::Color::Black;
            this->panel_SQ->Controls->Add(this->label_wrong);
            this->panel_SQ->Controls->Add(this->label_SQuestion);
            this->panel_SQ->Controls->Add(this->button_EnterAns);
            this->panel_SQ->Controls->Add(this->textBox_answer);
            this->panel_SQ->Controls->Add(this->label_answer);
            this->panel_SQ->Controls->Add(this->label_SecurityQ);
            this->panel_SQ->Location=System::Drawing::Point(1, 370);
            this->panel_SQ->Name=L"panel_SQ";
            this->panel_SQ->Size=System::Drawing::Size(431, 187);
            this->panel_SQ->TabIndex=6;
            //
            // label_wrong
            //
            this->label_wrong->AutoSize=true;
            this->label_wrong->Font=(gcnew System::Drawing::Font(L"PMingLiU", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->label_wrong->ForeColor=System::Drawing::Color::Yellow;
            this->label_wrong->Location=System::Drawing::Point(318, 132);
            this->label_wrong->Name=L"label_wrong";
            this->label_wrong->Size=System::Drawing::Size(71, 19);
            this->label_wrong->TabIndex=17;
            this->label_wrong->Text=L"Wrong!";
            //
            // label_SQuestion
            //
            this->label_SQuestion->AutoSize=true;
            this->label_SQuestion->Font=(gcnew System::Drawing::Font(L"PMingLiU", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->label_SQuestion->ForeColor=System::Drawing::Color::White;
            this->label_SQuestion->Location=System::Drawing::Point(2, 36);
            this->label_SQuestion->Name=L"label_SQuestion";
            this->label_SQuestion->Size=System::Drawing::Size(162, 19);
            this->label_SQuestion->TabIndex=16;
            this->label_SQuestion->Text=L"Security Question:";
            //
            // button_EnterAns
            //
            this->button_EnterAns->Font=(gcnew System::Drawing::Font(L"PMingLiU", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->button_EnterAns->Location=System::Drawing::Point(180, 127);
            this->button_EnterAns->Name=L"button_EnterAns";
            this->button_EnterAns->Size=System::Drawing::Size(132, 31);
            this->button_EnterAns->TabIndex=8;
            this->button_EnterAns->Text=L"Enter Answer";
            this->button_EnterAns->UseVisualStyleBackColor=true;
            this->button_EnterAns->Click+=gcnew System::EventHandler(this, &login::button_EnterAns_Click);
            //
            // textBox_answer
            //
            this->textBox_answer->Font=(gcnew System::Drawing::Font(L"PMingLiU", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->textBox_answer->Location=System::Drawing::Point(106, 78);
            this->textBox_answer->Name=L"textBox_answer";
            this->textBox_answer->Size=System::Drawing::Size(313, 27);
            this->textBox_answer->TabIndex=7;
            this->textBox_answer->TextAlign=System::Windows::Forms::HorizontalAlignment::Center;
            //
            // label_answer
            //
            this->label_answer->AutoSize=true;
            this->label_answer->Font=(gcnew System::Drawing::Font(L"PMingLiU", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->label_answer->ForeColor=System::Drawing::Color::White;
            this->label_answer->Location=System::Drawing::Point(-1, 78);
            this->label_answer->Name=L"label_answer";
            this->label_answer->Size=System::Drawing::Size(100, 24);
            this->label_answer->TabIndex=14;
            this->label_answer->Text=L"Answer :";
            //
            // label_SecurityQ
            //
            this->label_SecurityQ->AutoSize=true;
            this->label_SecurityQ->Font=(gcnew System::Drawing::Font(L"PMingLiU", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->label_SecurityQ->ForeColor=System::Drawing::Color::White;
            this->label_SecurityQ->Location=System::Drawing::Point(-1, 3);
            this->label_SecurityQ->Name=L"label_SecurityQ";
            this->label_SecurityQ->Size=System::Drawing::Size(195, 24);
            this->label_SecurityQ->TabIndex=12;
            this->label_SecurityQ->Text=L"Security Question:";
            //
            // login
            //
            this->AutoScaleDimensions=System::Drawing::SizeF(6, 12);
            this->AutoScaleMode=System::Windows::Forms::AutoScaleMode::Font;
            this->AutoSize=true;
            this->AutoSizeMode=System::Windows::Forms::AutoSizeMode::GrowAndShrink;
            this->ClientSize=System::Drawing::Size(432, 565);
            this->ControlBox=false;
            this->Controls->Add(this->panel_SQ);
            this->Controls->Add(this->panel1);
            this->Controls->Add(this->panel_title);
            this->Icon=(cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
            this->MaximizeBox=false;
            this->MinimizeBox=false;
            this->Name=L"login";
            this->StartPosition=System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text=L"RDSadmin: Login";
            this->Load+=gcnew System::EventHandler(this, &login::login_Load);
            this->panel_title->ResumeLayout(false);
            this->panel_title->PerformLayout();
            this->panel1->ResumeLayout(false);
            this->panel1->PerformLayout();
            this->panel_SQ->ResumeLayout(false);
            this->panel_SQ->PerformLayout();
            this->ResumeLayout(false);
        }
#pragma endregion
    private: System::Void login_Load(System::Object^  sender, System::EventArgs^  e);
             //
    private: System::Void textBox_CompanyCode_TextChanged(System::Object^  sender, System::EventArgs^  e);
             //
    private: System::Void button_login_Click(System::Object^  sender, System::EventArgs^  e);
    private: System::Void button_Exit_Click(System::Object^  sender, System::EventArgs^  e);
    private: System::Void button_Forget_Click(System::Object^  sender, System::EventArgs^  e);
    private: System::Void button_EnterAns_Click(System::Object^  sender, System::EventArgs^  e);
    };
}
