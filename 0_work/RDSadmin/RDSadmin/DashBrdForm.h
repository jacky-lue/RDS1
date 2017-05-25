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
    /// Summary for DashBrdForm
    /// </summary>
    public ref class DashBrdForm: public System::Windows::Forms::Form
    {
    public:
        DashBrdForm(void)
        {
            InitializeComponent();
            //
            //TODO: Add the constructor code here
            //
        }
    private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel_BG;
    public:
    private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel_Menu;
    private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel_MenuUp;
    private: System::Windows::Forms::Button^  button_DashBoard;
    private: System::Windows::Forms::Button^  button_ServiceCall;
    private: System::Windows::Forms::Button^  button_RDSuser;
    private: System::Windows::Forms::Button^  button_Supervisor;
    private: System::Windows::Forms::Button^  button_Dealer;
    private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel_MenuDown;
    private: System::Windows::Forms::Label^  label_LoginAuthorLv;
    private: System::Windows::Forms::Label^  label_LoginID;
    private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel_content;
    private: System::Windows::Forms::Panel^  panel_title;
    private: System::Windows::Forms::Button^  button_next;
    private: System::Windows::Forms::Label^  label_Title;
    private: System::Windows::Forms::PictureBox^  pictureBox_D1;
    private: System::Windows::Forms::Button^  button_LogOut;
    public:
        //include objects here.....
        RDS_NAS::nas_state iNas;

    protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~DashBrdForm()
        {
            if(components)
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
            System::ComponentModel::ComponentResourceManager^  resources=(gcnew System::ComponentModel::ComponentResourceManager(DashBrdForm::typeid));
            this->tableLayoutPanel_BG=(gcnew System::Windows::Forms::TableLayoutPanel());
            this->tableLayoutPanel_Menu=(gcnew System::Windows::Forms::TableLayoutPanel());
            this->flowLayoutPanel_MenuUp=(gcnew System::Windows::Forms::FlowLayoutPanel());
            this->button_DashBoard=(gcnew System::Windows::Forms::Button());
            this->button_ServiceCall=(gcnew System::Windows::Forms::Button());
            this->button_RDSuser=(gcnew System::Windows::Forms::Button());
            this->button_Supervisor=(gcnew System::Windows::Forms::Button());
            this->button_Dealer=(gcnew System::Windows::Forms::Button());
            this->button_LogOut=(gcnew System::Windows::Forms::Button());
            this->flowLayoutPanel_MenuDown=(gcnew System::Windows::Forms::FlowLayoutPanel());
            this->label_LoginAuthorLv=(gcnew System::Windows::Forms::Label());
            this->label_LoginID=(gcnew System::Windows::Forms::Label());
            this->tableLayoutPanel_content=(gcnew System::Windows::Forms::TableLayoutPanel());
            this->panel_title=(gcnew System::Windows::Forms::Panel());
            this->button_next=(gcnew System::Windows::Forms::Button());
            this->label_Title=(gcnew System::Windows::Forms::Label());
            this->pictureBox_D1=(gcnew System::Windows::Forms::PictureBox());
            this->tableLayoutPanel_BG->SuspendLayout();
            this->tableLayoutPanel_Menu->SuspendLayout();
            this->flowLayoutPanel_MenuUp->SuspendLayout();
            this->flowLayoutPanel_MenuDown->SuspendLayout();
            this->tableLayoutPanel_content->SuspendLayout();
            this->panel_title->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_D1))->BeginInit();
            this->SuspendLayout();
            //
            // tableLayoutPanel_BG
            //
            this->tableLayoutPanel_BG->AutoSizeMode=System::Windows::Forms::AutoSizeMode::GrowAndShrink;
            this->tableLayoutPanel_BG->ColumnCount=2;
            this->tableLayoutPanel_BG->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                150)));
            this->tableLayoutPanel_BG->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                100)));
            this->tableLayoutPanel_BG->Controls->Add(this->tableLayoutPanel_Menu, 0, 0);
            this->tableLayoutPanel_BG->Controls->Add(this->tableLayoutPanel_content, 1, 0);
            this->tableLayoutPanel_BG->Dock=System::Windows::Forms::DockStyle::Fill;
            this->tableLayoutPanel_BG->Location=System::Drawing::Point(0, 0);
            this->tableLayoutPanel_BG->Name=L"tableLayoutPanel_BG";
            this->tableLayoutPanel_BG->RowCount=1;
            this->tableLayoutPanel_BG->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
                100)));
            this->tableLayoutPanel_BG->Size=System::Drawing::Size(1229, 782);
            this->tableLayoutPanel_BG->TabIndex=19;
            //
            // tableLayoutPanel_Menu
            //
            this->tableLayoutPanel_Menu->ColumnCount=1;
            this->tableLayoutPanel_Menu->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                100)));
            this->tableLayoutPanel_Menu->Controls->Add(this->flowLayoutPanel_MenuUp, 0, 0);
            this->tableLayoutPanel_Menu->Controls->Add(this->flowLayoutPanel_MenuDown, 0, 1);
            this->tableLayoutPanel_Menu->Dock=System::Windows::Forms::DockStyle::Fill;
            this->tableLayoutPanel_Menu->Location=System::Drawing::Point(0, 0);
            this->tableLayoutPanel_Menu->Margin=System::Windows::Forms::Padding(0);
            this->tableLayoutPanel_Menu->Name=L"tableLayoutPanel_Menu";
            this->tableLayoutPanel_Menu->RowCount=2;
            this->tableLayoutPanel_Menu->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
                100)));
            this->tableLayoutPanel_Menu->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
                50)));
            this->tableLayoutPanel_Menu->Size=System::Drawing::Size(150, 782);
            this->tableLayoutPanel_Menu->TabIndex=0;
            //
            // flowLayoutPanel_MenuUp
            //
            this->flowLayoutPanel_MenuUp->BackColor=System::Drawing::Color::MidnightBlue;
            this->flowLayoutPanel_MenuUp->Controls->Add(this->button_DashBoard);
            this->flowLayoutPanel_MenuUp->Controls->Add(this->button_ServiceCall);
            this->flowLayoutPanel_MenuUp->Controls->Add(this->button_RDSuser);
            this->flowLayoutPanel_MenuUp->Controls->Add(this->button_Supervisor);
            this->flowLayoutPanel_MenuUp->Controls->Add(this->button_Dealer);
            this->flowLayoutPanel_MenuUp->Controls->Add(this->button_LogOut);
            this->flowLayoutPanel_MenuUp->Dock=System::Windows::Forms::DockStyle::Fill;
            this->flowLayoutPanel_MenuUp->FlowDirection=System::Windows::Forms::FlowDirection::TopDown;
            this->flowLayoutPanel_MenuUp->Location=System::Drawing::Point(1, 1);
            this->flowLayoutPanel_MenuUp->Margin=System::Windows::Forms::Padding(1, 1, 1, 0);
            this->flowLayoutPanel_MenuUp->Name=L"flowLayoutPanel_MenuUp";
            this->flowLayoutPanel_MenuUp->Size=System::Drawing::Size(148, 731);
            this->flowLayoutPanel_MenuUp->TabIndex=0;
            //
            // button_DashBoard
            //
            this->button_DashBoard->BackgroundImage=(cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_DashBoard.BackgroundImage")));
            this->button_DashBoard->Font=(gcnew System::Drawing::Font(L"PMingLiU", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->button_DashBoard->Location=System::Drawing::Point(12, 12);
            this->button_DashBoard->Margin=System::Windows::Forms::Padding(12, 12, 12, 0);
            this->button_DashBoard->Name=L"button_DashBoard";
            this->button_DashBoard->Size=System::Drawing::Size(125, 50);
            this->button_DashBoard->TabIndex=31;
            this->button_DashBoard->Text=L"Statistics Dashboard";
            this->button_DashBoard->UseVisualStyleBackColor=true;
            this->button_DashBoard->Click+=gcnew System::EventHandler(this, &DashBrdForm::DashBrdForm_Load);
            //
            // button_ServiceCall
            //
            this->button_ServiceCall->Font=(gcnew System::Drawing::Font(L"PMingLiU", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->button_ServiceCall->Location=System::Drawing::Point(12, 74);
            this->button_ServiceCall->Margin=System::Windows::Forms::Padding(12, 12, 12, 0);
            this->button_ServiceCall->Name=L"button_ServiceCall";
            this->button_ServiceCall->Size=System::Drawing::Size(125, 50);
            this->button_ServiceCall->TabIndex=28;
            this->button_ServiceCall->Text=L"Open \r\nService Calls";
            this->button_ServiceCall->UseVisualStyleBackColor=true;
            this->button_ServiceCall->Click+=gcnew System::EventHandler(this, &DashBrdForm::button_ServiceCall_Click);
            //
            // button_RDSuser
            //
            this->button_RDSuser->Font=(gcnew System::Drawing::Font(L"PMingLiU", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->button_RDSuser->Location=System::Drawing::Point(12, 136);
            this->button_RDSuser->Margin=System::Windows::Forms::Padding(12, 12, 12, 0);
            this->button_RDSuser->Name=L"button_RDSuser";
            this->button_RDSuser->Size=System::Drawing::Size(125, 50);
            this->button_RDSuser->TabIndex=29;
            this->button_RDSuser->Text=L"RDS User List";
            this->button_RDSuser->UseVisualStyleBackColor=true;
            this->button_RDSuser->Click+=gcnew System::EventHandler(this, &DashBrdForm::button_RDSuser_Click);
            //
            // button_Supervisor
            //
            this->button_Supervisor->Font=(gcnew System::Drawing::Font(L"PMingLiU", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->button_Supervisor->Location=System::Drawing::Point(12, 198);
            this->button_Supervisor->Margin=System::Windows::Forms::Padding(12, 12, 12, 0);
            this->button_Supervisor->Name=L"button_Supervisor";
            this->button_Supervisor->Size=System::Drawing::Size(125, 50);
            this->button_Supervisor->TabIndex=30;
            this->button_Supervisor->Text=L"Supervisor Account";
            this->button_Supervisor->UseVisualStyleBackColor=true;
            this->button_Supervisor->Click+=gcnew System::EventHandler(this, &DashBrdForm::button_Supervisor_Click);
            //
            // button_Dealer
            //
            this->button_Dealer->Font=(gcnew System::Drawing::Font(L"PMingLiU", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->button_Dealer->Location=System::Drawing::Point(12, 260);
            this->button_Dealer->Margin=System::Windows::Forms::Padding(12, 12, 12, 0);
            this->button_Dealer->Name=L"button_Dealer";
            this->button_Dealer->Size=System::Drawing::Size(125, 50);
            this->button_Dealer->TabIndex=32;
            this->button_Dealer->Text=L"Dealer List";
            this->button_Dealer->UseVisualStyleBackColor=true;
            this->button_Dealer->Click+=gcnew System::EventHandler(this, &DashBrdForm::button_Dealer_Click);
            //
            // button_LogOut
            //
            this->button_LogOut->Font=(gcnew System::Drawing::Font(L"PMingLiU", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->button_LogOut->Location=System::Drawing::Point(12, 322);
            this->button_LogOut->Margin=System::Windows::Forms::Padding(12, 12, 12, 0);
            this->button_LogOut->Name=L"button_LogOut";
            this->button_LogOut->Size=System::Drawing::Size(125, 50);
            this->button_LogOut->TabIndex=34;
            this->button_LogOut->Text=L"Log Out";
            this->button_LogOut->UseVisualStyleBackColor=true;
            this->button_LogOut->Click+=gcnew System::EventHandler(this, &DashBrdForm::button_LogOut_Click);
            //
            // flowLayoutPanel_MenuDown
            //
            this->flowLayoutPanel_MenuDown->BackColor=System::Drawing::Color::MidnightBlue;
            this->flowLayoutPanel_MenuDown->Controls->Add(this->label_LoginAuthorLv);
            this->flowLayoutPanel_MenuDown->Controls->Add(this->label_LoginID);
            this->flowLayoutPanel_MenuDown->Dock=System::Windows::Forms::DockStyle::Fill;
            this->flowLayoutPanel_MenuDown->FlowDirection=System::Windows::Forms::FlowDirection::BottomUp;
            this->flowLayoutPanel_MenuDown->Location=System::Drawing::Point(1, 732);
            this->flowLayoutPanel_MenuDown->Margin=System::Windows::Forms::Padding(1, 0, 1, 1);
            this->flowLayoutPanel_MenuDown->Name=L"flowLayoutPanel_MenuDown";
            this->flowLayoutPanel_MenuDown->Size=System::Drawing::Size(148, 49);
            this->flowLayoutPanel_MenuDown->TabIndex=1;
            //
            // label_LoginAuthorLv
            //
            this->label_LoginAuthorLv->AutoSize=true;
            this->label_LoginAuthorLv->ForeColor=System::Drawing::Color::White;
            this->label_LoginAuthorLv->Location=System::Drawing::Point(10, 27);
            this->label_LoginAuthorLv->Margin=System::Windows::Forms::Padding(10, 0, 10, 10);
            this->label_LoginAuthorLv->Name=L"label_LoginAuthorLv";
            this->label_LoginAuthorLv->Size=System::Drawing::Size(97, 12);
            this->label_LoginAuthorLv->TabIndex=18;
            this->label_LoginAuthorLv->Text=L"Login Authority Lv";
            //
            // label_LoginID
            //
            this->label_LoginID->AutoSize=true;
            this->label_LoginID->ForeColor=System::Drawing::Color::White;
            this->label_LoginID->Location=System::Drawing::Point(10, 10);
            this->label_LoginID->Margin=System::Windows::Forms::Padding(10, 0, 10, 5);
            this->label_LoginID->Name=L"label_LoginID";
            this->label_LoginID->Size=System::Drawing::Size(48, 12);
            this->label_LoginID->TabIndex=17;
            this->label_LoginID->Text=L"Login ID";
            //
            // tableLayoutPanel_content
            //
            this->tableLayoutPanel_content->ColumnCount=1;
            this->tableLayoutPanel_content->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                100)));
            this->tableLayoutPanel_content->Controls->Add(this->panel_title, 0, 0);
            this->tableLayoutPanel_content->Controls->Add(this->pictureBox_D1, 0, 1);
            this->tableLayoutPanel_content->Dock=System::Windows::Forms::DockStyle::Fill;
            this->tableLayoutPanel_content->Location=System::Drawing::Point(150, 0);
            this->tableLayoutPanel_content->Margin=System::Windows::Forms::Padding(0);
            this->tableLayoutPanel_content->Name=L"tableLayoutPanel_content";
            this->tableLayoutPanel_content->RowCount=2;
            this->tableLayoutPanel_content->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
                60)));
            this->tableLayoutPanel_content->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
                100)));
            this->tableLayoutPanel_content->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
                20)));
            this->tableLayoutPanel_content->Size=System::Drawing::Size(1079, 782);
            this->tableLayoutPanel_content->TabIndex=1;
            //
            // panel_title
            //
            this->panel_title->BackColor=System::Drawing::Color::SteelBlue;
            this->panel_title->Controls->Add(this->button_next);
            this->panel_title->Controls->Add(this->label_Title);
            this->panel_title->Dock=System::Windows::Forms::DockStyle::Fill;
            this->panel_title->Location=System::Drawing::Point(1, 0);
            this->panel_title->Margin=System::Windows::Forms::Padding(1, 0, 0, 0);
            this->panel_title->Name=L"panel_title";
            this->panel_title->Size=System::Drawing::Size(1078, 60);
            this->panel_title->TabIndex=17;
            //
            // button_next
            //
            this->button_next->Font=(gcnew System::Drawing::Font(L"PMingLiU", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->button_next->Location=System::Drawing::Point(994, 11);
            this->button_next->Name=L"button_next";
            this->button_next->Size=System::Drawing::Size(66, 37);
            this->button_next->TabIndex=1;
            this->button_next->Text=L"Next";
            this->button_next->UseVisualStyleBackColor=true;
            this->button_next->Click+=gcnew System::EventHandler(this, &DashBrdForm::button_next_Click);
            //
            // label_Title
            //
            this->label_Title->AutoSize=true;
            this->label_Title->Font=(gcnew System::Drawing::Font(L"PMingLiU", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->label_Title->ForeColor=System::Drawing::Color::White;
            this->label_Title->Location=System::Drawing::Point(345, 14);
            this->label_Title->Name=L"label_Title";
            this->label_Title->Size=System::Drawing::Size(305, 29);
            this->label_Title->TabIndex=0;
            this->label_Title->Text=L"Statistics Dashboard - 1";
            //
            // pictureBox_D1
            //
            this->pictureBox_D1->Dock=System::Windows::Forms::DockStyle::Fill;
            this->pictureBox_D1->Image=(cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox_D1.Image")));
            this->pictureBox_D1->Location=System::Drawing::Point(3, 63);
            this->pictureBox_D1->Name=L"pictureBox_D1";
            this->pictureBox_D1->Size=System::Drawing::Size(1073, 716);
            this->pictureBox_D1->SizeMode=System::Windows::Forms::PictureBoxSizeMode::CenterImage;
            this->pictureBox_D1->TabIndex=18;
            this->pictureBox_D1->TabStop=false;
            //
            // DashBrdForm
            //
            this->AutoScaleDimensions=System::Drawing::SizeF(6, 12);
            this->AutoScaleMode=System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor=System::Drawing::Color::White;
            this->ClientSize=System::Drawing::Size(1229, 782);
            this->ControlBox=false;
            this->Controls->Add(this->tableLayoutPanel_BG);
            this->Icon=(cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
            this->MaximizeBox=false;
            this->MinimizeBox=false;
            this->Name=L"DashBrdForm";
            this->StartPosition=System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text=L"Statistics Dash Board 1";
            this->Load+=gcnew System::EventHandler(this, &DashBrdForm::DashBrdForm_Load);
            this->tableLayoutPanel_BG->ResumeLayout(false);
            this->tableLayoutPanel_Menu->ResumeLayout(false);
            this->flowLayoutPanel_MenuUp->ResumeLayout(false);
            this->flowLayoutPanel_MenuDown->ResumeLayout(false);
            this->flowLayoutPanel_MenuDown->PerformLayout();
            this->tableLayoutPanel_content->ResumeLayout(false);
            this->panel_title->ResumeLayout(false);
            this->panel_title->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_D1))->EndInit();
            this->ResumeLayout(false);
        }
#pragma endregion
    private: System::Void DashBrdForm_Load(System::Object^  sender, System::EventArgs^  e);
             //
    private: System::Void button_ServiceCall_Click(System::Object^  sender, System::EventArgs^  e);
    private: System::Void button_RDSuser_Click(System::Object^  sender, System::EventArgs^  e);
    private: System::Void button_Supervisor_Click(System::Object^  sender, System::EventArgs^  e);
    private: System::Void button_Dealer_Click(System::Object^  sender, System::EventArgs^  e);
             //
    private: System::Void button_next_Click(System::Object^  sender, System::EventArgs^  e);
    private: System::Void button_LogOut_Click(System::Object^  sender, System::EventArgs^  e)
    {
        int rtn=this->iNas.Unlock_Person_Login(this->iNas.LoginUser_no);
        if(rtn<0){
            MessageBox::Show(LOGIN_ERR_FILE_LOSS_BEF_UNLOCK, "ERROR",
                MessageBoxButtons::OK, MessageBoxIcon::Information);
        }
        this->Close(); //close login form and exit application
        Application::Exit(); //!!!!!!!!!!!!!!!!!!!
    }
    };
}
