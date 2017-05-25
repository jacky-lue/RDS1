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
    using namespace RDS_NAS;

    /// <summary>
    /// Summary for RDSadminMainForm
    /// </summary>
    public ref class RDSadminMainForm: public System::Windows::Forms::Form
    {
    public:
        RDSadminMainForm(int pageIn)
        {
            InitializeComponent();
            //
            //TODO: Add the constructor code here
            //
            this->page=pageIn;
        }
    private: System::Windows::Forms::Panel^  panel_list9;
    private: System::Windows::Forms::Label^  label_list9;
    private: System::Windows::Forms::Panel^  panel_list8;
    private: System::Windows::Forms::Label^  label_list8;
    private: System::Windows::Forms::Panel^  panel_list4;
    private: System::Windows::Forms::Label^  label_list4;
    private: System::Windows::Forms::Panel^  panel_list6;
    private: System::Windows::Forms::Label^  label_list6;
    private: System::Windows::Forms::Panel^  panel_list2;
    private: System::Windows::Forms::Label^  label_list2;
    private: System::Windows::Forms::Panel^  panel_list7;
    private: System::Windows::Forms::Label^  label_list7;
    private: System::Windows::Forms::Panel^  panel_list3;
    private: System::Windows::Forms::Label^  label_list3;
    private: System::Windows::Forms::Panel^  panel_list5;
    private: System::Windows::Forms::Label^  label_list5;
    private: System::Windows::Forms::Panel^  panel_list1;
    private: System::Windows::Forms::Label^  label_list1;
    private: System::Windows::Forms::Panel^  panel_Control;
    private: System::Windows::Forms::Label^  label_page;
    private: System::Windows::Forms::Button^  button_left;
    private: System::Windows::Forms::Button^  button_right;

    public:
        //include objects here.....
        RDS_NAS::nas_state iNas;

        //UI related
        int active_list;
    private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel_BG;
    private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel_Menu;
    private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel_Content;
    private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel_MenuUp;
    private: System::Windows::Forms::Button^  button_DashBoard;
    private: System::Windows::Forms::Button^  button_ServiceCall;
    private: System::Windows::Forms::Button^  button_RDSuser;
    private: System::Windows::Forms::Button^  button_Supervisor;
    private: System::Windows::Forms::Button^  button_Dealer;
    private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel_MenuDown;
    private: System::Windows::Forms::Label^  label_LoginAuthorLv;
    private: System::Windows::Forms::Label^  label_LoginID;
    private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel_list;
    private: System::Windows::Forms::Button^  button_LogOut;
    public:
        int page;

    protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~RDSadminMainForm()
        {
            if(components)
            {
                delete components;
            }
        }

    protected:

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
            System::ComponentModel::ComponentResourceManager^  resources=(gcnew System::ComponentModel::ComponentResourceManager(RDSadminMainForm::typeid));
            this->panel_title=(gcnew System::Windows::Forms::Panel());
            this->label_Title=(gcnew System::Windows::Forms::Label());
            this->panel_list9=(gcnew System::Windows::Forms::Panel());
            this->label_list9=(gcnew System::Windows::Forms::Label());
            this->panel_list8=(gcnew System::Windows::Forms::Panel());
            this->label_list8=(gcnew System::Windows::Forms::Label());
            this->panel_list4=(gcnew System::Windows::Forms::Panel());
            this->label_list4=(gcnew System::Windows::Forms::Label());
            this->panel_list6=(gcnew System::Windows::Forms::Panel());
            this->label_list6=(gcnew System::Windows::Forms::Label());
            this->panel_list2=(gcnew System::Windows::Forms::Panel());
            this->label_list2=(gcnew System::Windows::Forms::Label());
            this->panel_list7=(gcnew System::Windows::Forms::Panel());
            this->label_list7=(gcnew System::Windows::Forms::Label());
            this->panel_list3=(gcnew System::Windows::Forms::Panel());
            this->label_list3=(gcnew System::Windows::Forms::Label());
            this->panel_list5=(gcnew System::Windows::Forms::Panel());
            this->label_list5=(gcnew System::Windows::Forms::Label());
            this->panel_list1=(gcnew System::Windows::Forms::Panel());
            this->label_list1=(gcnew System::Windows::Forms::Label());
            this->panel_Control=(gcnew System::Windows::Forms::Panel());
            this->label_page=(gcnew System::Windows::Forms::Label());
            this->button_left=(gcnew System::Windows::Forms::Button());
            this->button_right=(gcnew System::Windows::Forms::Button());
            this->tableLayoutPanel_BG=(gcnew System::Windows::Forms::TableLayoutPanel());
            this->tableLayoutPanel_Menu=(gcnew System::Windows::Forms::TableLayoutPanel());
            this->flowLayoutPanel_MenuDown=(gcnew System::Windows::Forms::FlowLayoutPanel());
            this->label_LoginAuthorLv=(gcnew System::Windows::Forms::Label());
            this->label_LoginID=(gcnew System::Windows::Forms::Label());
            this->flowLayoutPanel_MenuUp=(gcnew System::Windows::Forms::FlowLayoutPanel());
            this->button_DashBoard=(gcnew System::Windows::Forms::Button());
            this->button_ServiceCall=(gcnew System::Windows::Forms::Button());
            this->button_RDSuser=(gcnew System::Windows::Forms::Button());
            this->button_Supervisor=(gcnew System::Windows::Forms::Button());
            this->button_Dealer=(gcnew System::Windows::Forms::Button());
            this->button_LogOut=(gcnew System::Windows::Forms::Button());
            this->tableLayoutPanel_Content=(gcnew System::Windows::Forms::TableLayoutPanel());
            this->tableLayoutPanel_list=(gcnew System::Windows::Forms::TableLayoutPanel());
            this->panel_title->SuspendLayout();
            this->panel_list9->SuspendLayout();
            this->panel_list8->SuspendLayout();
            this->panel_list4->SuspendLayout();
            this->panel_list6->SuspendLayout();
            this->panel_list2->SuspendLayout();
            this->panel_list7->SuspendLayout();
            this->panel_list3->SuspendLayout();
            this->panel_list5->SuspendLayout();
            this->panel_list1->SuspendLayout();
            this->panel_Control->SuspendLayout();
            this->tableLayoutPanel_BG->SuspendLayout();
            this->tableLayoutPanel_Menu->SuspendLayout();
            this->flowLayoutPanel_MenuDown->SuspendLayout();
            this->flowLayoutPanel_MenuUp->SuspendLayout();
            this->tableLayoutPanel_Content->SuspendLayout();
            this->tableLayoutPanel_list->SuspendLayout();
            this->SuspendLayout();
            //
            // panel_title
            //
            this->panel_title->BackColor=System::Drawing::Color::SteelBlue;
            this->panel_title->Controls->Add(this->label_Title);
            this->panel_title->Dock=System::Windows::Forms::DockStyle::Fill;
            this->panel_title->Location=System::Drawing::Point(0, 0);
            this->panel_title->Margin=System::Windows::Forms::Padding(0);
            this->panel_title->Name=L"panel_title";
            this->panel_title->Size=System::Drawing::Size(474, 50);
            this->panel_title->TabIndex=6;
            //
            // label_Title
            //
            this->label_Title->AutoSize=true;
            this->label_Title->Font=(gcnew System::Drawing::Font(L"PMingLiU", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->label_Title->ForeColor=System::Drawing::Color::White;
            this->label_Title->Location=System::Drawing::Point(86, 7);
            this->label_Title->Name=L"label_Title";
            this->label_Title->Size=System::Drawing::Size(246, 29);
            this->label_Title->TabIndex=0;
            this->label_Title->Text=L"Open Service Calls";
            //
            // panel_list9
            //
            this->panel_list9->BackColor=System::Drawing::Color::Black;
            this->panel_list9->BackgroundImage=(cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel_list9.BackgroundImage")));
            this->panel_list9->BackgroundImageLayout=System::Windows::Forms::ImageLayout::Stretch;
            this->panel_list9->Controls->Add(this->label_list9);
            this->panel_list9->Dock=System::Windows::Forms::DockStyle::Fill;
            this->panel_list9->Location=System::Drawing::Point(0, 418);
            this->panel_list9->Margin=System::Windows::Forms::Padding(0, 10, 0, 0);
            this->panel_list9->Name=L"panel_list9";
            this->panel_list9->Size=System::Drawing::Size(474, 41);
            this->panel_list9->TabIndex=23;
            this->panel_list9->Click+=gcnew System::EventHandler(this, &RDSadminMainForm::label_list9_Click);
            this->panel_list9->DoubleClick+=gcnew System::EventHandler(this, &RDSadminMainForm::label_list9_DoubleClick);
            //
            // label_list9
            //
            this->label_list9->AutoSize=true;
            this->label_list9->Font=(gcnew System::Drawing::Font(L"PMingLiU", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->label_list9->ForeColor=System::Drawing::Color::White;
            this->label_list9->Location=System::Drawing::Point(24, 9);
            this->label_list9->Name=L"label_list9";
            this->label_list9->Size=System::Drawing::Size(69, 21);
            this->label_list9->TabIndex=1;
            this->label_list9->Text=L"User 9";
            this->label_list9->Click+=gcnew System::EventHandler(this, &RDSadminMainForm::label_list9_Click);
            this->label_list9->DoubleClick+=gcnew System::EventHandler(this, &RDSadminMainForm::label_list9_DoubleClick);
            //
            // panel_list8
            //
            this->panel_list8->BackColor=System::Drawing::Color::Black;
            this->panel_list8->BackgroundImage=(cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel_list8.BackgroundImage")));
            this->panel_list8->BackgroundImageLayout=System::Windows::Forms::ImageLayout::Stretch;
            this->panel_list8->Controls->Add(this->label_list8);
            this->panel_list8->Dock=System::Windows::Forms::DockStyle::Fill;
            this->panel_list8->Location=System::Drawing::Point(0, 367);
            this->panel_list8->Margin=System::Windows::Forms::Padding(0, 10, 0, 0);
            this->panel_list8->Name=L"panel_list8";
            this->panel_list8->Size=System::Drawing::Size(474, 41);
            this->panel_list8->TabIndex=22;
            this->panel_list8->Click+=gcnew System::EventHandler(this, &RDSadminMainForm::label_list8_Click);
            this->panel_list8->DoubleClick+=gcnew System::EventHandler(this, &RDSadminMainForm::label_list8_DoubleClick);
            //
            // label_list8
            //
            this->label_list8->AutoSize=true;
            this->label_list8->Font=(gcnew System::Drawing::Font(L"PMingLiU", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->label_list8->ForeColor=System::Drawing::Color::White;
            this->label_list8->Location=System::Drawing::Point(24, 9);
            this->label_list8->Name=L"label_list8";
            this->label_list8->Size=System::Drawing::Size(69, 21);
            this->label_list8->TabIndex=1;
            this->label_list8->Text=L"User 8";
            this->label_list8->Click+=gcnew System::EventHandler(this, &RDSadminMainForm::label_list8_Click);
            this->label_list8->DoubleClick+=gcnew System::EventHandler(this, &RDSadminMainForm::label_list8_DoubleClick);
            //
            // panel_list4
            //
            this->panel_list4->BackColor=System::Drawing::Color::Black;
            this->panel_list4->BackgroundImage=(cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel_list4.BackgroundImage")));
            this->panel_list4->BackgroundImageLayout=System::Windows::Forms::ImageLayout::Stretch;
            this->panel_list4->Controls->Add(this->label_list4);
            this->panel_list4->Dock=System::Windows::Forms::DockStyle::Fill;
            this->panel_list4->Location=System::Drawing::Point(0, 163);
            this->panel_list4->Margin=System::Windows::Forms::Padding(0, 10, 0, 0);
            this->panel_list4->Name=L"panel_list4";
            this->panel_list4->Size=System::Drawing::Size(474, 41);
            this->panel_list4->TabIndex=18;
            this->panel_list4->Click+=gcnew System::EventHandler(this, &RDSadminMainForm::label_list4_Click);
            this->panel_list4->DoubleClick+=gcnew System::EventHandler(this, &RDSadminMainForm::label_list4_DoubleClick);
            //
            // label_list4
            //
            this->label_list4->AutoSize=true;
            this->label_list4->Font=(gcnew System::Drawing::Font(L"PMingLiU", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->label_list4->ForeColor=System::Drawing::Color::White;
            this->label_list4->Location=System::Drawing::Point(24, 9);
            this->label_list4->Name=L"label_list4";
            this->label_list4->Size=System::Drawing::Size(69, 21);
            this->label_list4->TabIndex=1;
            this->label_list4->Text=L"User 4";
            this->label_list4->Click+=gcnew System::EventHandler(this, &RDSadminMainForm::label_list4_Click);
            this->label_list4->DoubleClick+=gcnew System::EventHandler(this, &RDSadminMainForm::label_list4_DoubleClick);
            //
            // panel_list6
            //
            this->panel_list6->BackColor=System::Drawing::Color::Black;
            this->panel_list6->BackgroundImage=(cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel_list6.BackgroundImage")));
            this->panel_list6->BackgroundImageLayout=System::Windows::Forms::ImageLayout::Stretch;
            this->panel_list6->Controls->Add(this->label_list6);
            this->panel_list6->Dock=System::Windows::Forms::DockStyle::Fill;
            this->panel_list6->Location=System::Drawing::Point(0, 265);
            this->panel_list6->Margin=System::Windows::Forms::Padding(0, 10, 0, 0);
            this->panel_list6->Name=L"panel_list6";
            this->panel_list6->Size=System::Drawing::Size(474, 41);
            this->panel_list6->TabIndex=20;
            this->panel_list6->Click+=gcnew System::EventHandler(this, &RDSadminMainForm::label_list6_Click);
            this->panel_list6->DoubleClick+=gcnew System::EventHandler(this, &RDSadminMainForm::label_list6_DoubleClick);
            //
            // label_list6
            //
            this->label_list6->AutoSize=true;
            this->label_list6->Font=(gcnew System::Drawing::Font(L"PMingLiU", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->label_list6->ForeColor=System::Drawing::Color::White;
            this->label_list6->Location=System::Drawing::Point(24, 9);
            this->label_list6->Name=L"label_list6";
            this->label_list6->Size=System::Drawing::Size(69, 21);
            this->label_list6->TabIndex=1;
            this->label_list6->Text=L"User 6";
            this->label_list6->Click+=gcnew System::EventHandler(this, &RDSadminMainForm::label_list6_Click);
            this->label_list6->DoubleClick+=gcnew System::EventHandler(this, &RDSadminMainForm::label_list6_DoubleClick);
            //
            // panel_list2
            //
            this->panel_list2->BackColor=System::Drawing::Color::Black;
            this->panel_list2->BackgroundImage=(cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel_list2.BackgroundImage")));
            this->panel_list2->BackgroundImageLayout=System::Windows::Forms::ImageLayout::Stretch;
            this->panel_list2->Controls->Add(this->label_list2);
            this->panel_list2->Dock=System::Windows::Forms::DockStyle::Fill;
            this->panel_list2->Location=System::Drawing::Point(0, 61);
            this->panel_list2->Margin=System::Windows::Forms::Padding(0, 10, 0, 0);
            this->panel_list2->Name=L"panel_list2";
            this->panel_list2->Size=System::Drawing::Size(474, 41);
            this->panel_list2->TabIndex=16;
            this->panel_list2->Click+=gcnew System::EventHandler(this, &RDSadminMainForm::label_list2_Click);
            this->panel_list2->DoubleClick+=gcnew System::EventHandler(this, &RDSadminMainForm::label_list2_DoubleClick);
            //
            // label_list2
            //
            this->label_list2->AutoSize=true;
            this->label_list2->Font=(gcnew System::Drawing::Font(L"PMingLiU", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->label_list2->ForeColor=System::Drawing::Color::White;
            this->label_list2->Location=System::Drawing::Point(24, 9);
            this->label_list2->Name=L"label_list2";
            this->label_list2->Size=System::Drawing::Size(69, 21);
            this->label_list2->TabIndex=1;
            this->label_list2->Text=L"User 2";
            this->label_list2->Click+=gcnew System::EventHandler(this, &RDSadminMainForm::label_list2_Click);
            this->label_list2->DoubleClick+=gcnew System::EventHandler(this, &RDSadminMainForm::label_list2_DoubleClick);
            //
            // panel_list7
            //
            this->panel_list7->BackColor=System::Drawing::Color::Black;
            this->panel_list7->BackgroundImage=(cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel_list7.BackgroundImage")));
            this->panel_list7->BackgroundImageLayout=System::Windows::Forms::ImageLayout::Stretch;
            this->panel_list7->Controls->Add(this->label_list7);
            this->panel_list7->Dock=System::Windows::Forms::DockStyle::Fill;
            this->panel_list7->Location=System::Drawing::Point(0, 316);
            this->panel_list7->Margin=System::Windows::Forms::Padding(0, 10, 0, 0);
            this->panel_list7->Name=L"panel_list7";
            this->panel_list7->Size=System::Drawing::Size(474, 41);
            this->panel_list7->TabIndex=21;
            this->panel_list7->Click+=gcnew System::EventHandler(this, &RDSadminMainForm::label_list7_Click);
            this->panel_list7->DoubleClick+=gcnew System::EventHandler(this, &RDSadminMainForm::label_list7_DoubleClick);
            //
            // label_list7
            //
            this->label_list7->AutoSize=true;
            this->label_list7->Font=(gcnew System::Drawing::Font(L"PMingLiU", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->label_list7->ForeColor=System::Drawing::Color::White;
            this->label_list7->Location=System::Drawing::Point(24, 9);
            this->label_list7->Name=L"label_list7";
            this->label_list7->Size=System::Drawing::Size(69, 21);
            this->label_list7->TabIndex=1;
            this->label_list7->Text=L"User 7";
            this->label_list7->Click+=gcnew System::EventHandler(this, &RDSadminMainForm::label_list7_Click);
            this->label_list7->DoubleClick+=gcnew System::EventHandler(this, &RDSadminMainForm::label_list7_DoubleClick);
            //
            // panel_list3
            //
            this->panel_list3->BackColor=System::Drawing::Color::Black;
            this->panel_list3->BackgroundImage=(cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel_list3.BackgroundImage")));
            this->panel_list3->BackgroundImageLayout=System::Windows::Forms::ImageLayout::Stretch;
            this->panel_list3->Controls->Add(this->label_list3);
            this->panel_list3->Dock=System::Windows::Forms::DockStyle::Fill;
            this->panel_list3->Location=System::Drawing::Point(0, 112);
            this->panel_list3->Margin=System::Windows::Forms::Padding(0, 10, 0, 0);
            this->panel_list3->Name=L"panel_list3";
            this->panel_list3->Size=System::Drawing::Size(474, 41);
            this->panel_list3->TabIndex=17;
            this->panel_list3->Click+=gcnew System::EventHandler(this, &RDSadminMainForm::label_list3_Click);
            this->panel_list3->DoubleClick+=gcnew System::EventHandler(this, &RDSadminMainForm::label_list3_DoubleClick);
            //
            // label_list3
            //
            this->label_list3->AutoSize=true;
            this->label_list3->Font=(gcnew System::Drawing::Font(L"PMingLiU", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->label_list3->ForeColor=System::Drawing::Color::White;
            this->label_list3->Location=System::Drawing::Point(24, 9);
            this->label_list3->Name=L"label_list3";
            this->label_list3->Size=System::Drawing::Size(69, 21);
            this->label_list3->TabIndex=1;
            this->label_list3->Text=L"User 3";
            this->label_list3->Click+=gcnew System::EventHandler(this, &RDSadminMainForm::label_list3_Click);
            this->label_list3->DoubleClick+=gcnew System::EventHandler(this, &RDSadminMainForm::label_list3_DoubleClick);
            //
            // panel_list5
            //
            this->panel_list5->BackColor=System::Drawing::Color::Black;
            this->panel_list5->BackgroundImage=(cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel_list5.BackgroundImage")));
            this->panel_list5->BackgroundImageLayout=System::Windows::Forms::ImageLayout::Stretch;
            this->panel_list5->Controls->Add(this->label_list5);
            this->panel_list5->Dock=System::Windows::Forms::DockStyle::Fill;
            this->panel_list5->Location=System::Drawing::Point(0, 214);
            this->panel_list5->Margin=System::Windows::Forms::Padding(0, 10, 0, 0);
            this->panel_list5->Name=L"panel_list5";
            this->panel_list5->Size=System::Drawing::Size(474, 41);
            this->panel_list5->TabIndex=19;
            this->panel_list5->Click+=gcnew System::EventHandler(this, &RDSadminMainForm::label_list5_Click);
            this->panel_list5->DoubleClick+=gcnew System::EventHandler(this, &RDSadminMainForm::label_list5_DoubleClick);
            //
            // label_list5
            //
            this->label_list5->AutoSize=true;
            this->label_list5->Font=(gcnew System::Drawing::Font(L"PMingLiU", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->label_list5->ForeColor=System::Drawing::Color::White;
            this->label_list5->Location=System::Drawing::Point(24, 9);
            this->label_list5->Name=L"label_list5";
            this->label_list5->Size=System::Drawing::Size(69, 21);
            this->label_list5->TabIndex=1;
            this->label_list5->Text=L"User 5";
            this->label_list5->Click+=gcnew System::EventHandler(this, &RDSadminMainForm::label_list5_Click);
            this->label_list5->DoubleClick+=gcnew System::EventHandler(this, &RDSadminMainForm::label_list5_DoubleClick);
            //
            // panel_list1
            //
            this->panel_list1->BackColor=System::Drawing::Color::Black;
            this->panel_list1->BackgroundImage=(cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel_list1.BackgroundImage")));
            this->panel_list1->BackgroundImageLayout=System::Windows::Forms::ImageLayout::Stretch;
            this->panel_list1->Controls->Add(this->label_list1);
            this->panel_list1->Dock=System::Windows::Forms::DockStyle::Fill;
            this->panel_list1->Location=System::Drawing::Point(0, 10);
            this->panel_list1->Margin=System::Windows::Forms::Padding(0, 10, 0, 0);
            this->panel_list1->Name=L"panel_list1";
            this->panel_list1->Size=System::Drawing::Size(474, 41);
            this->panel_list1->TabIndex=15;
            this->panel_list1->Click+=gcnew System::EventHandler(this, &RDSadminMainForm::label_list1_Click);
            this->panel_list1->DoubleClick+=gcnew System::EventHandler(this, &RDSadminMainForm::label_list1_DoubleClick);
            //
            // label_list1
            //
            this->label_list1->AutoSize=true;
            this->label_list1->Font=(gcnew System::Drawing::Font(L"PMingLiU", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->label_list1->ForeColor=System::Drawing::Color::White;
            this->label_list1->Location=System::Drawing::Point(24, 9);
            this->label_list1->Name=L"label_list1";
            this->label_list1->Size=System::Drawing::Size(69, 21);
            this->label_list1->TabIndex=1;
            this->label_list1->Text=L"User 1";
            this->label_list1->Click+=gcnew System::EventHandler(this, &RDSadminMainForm::label_list1_Click);
            this->label_list1->DoubleClick+=gcnew System::EventHandler(this, &RDSadminMainForm::label_list1_DoubleClick);
            //
            // panel_Control
            //
            this->panel_Control->BackColor=System::Drawing::Color::SteelBlue;
            this->panel_Control->Controls->Add(this->label_page);
            this->panel_Control->Controls->Add(this->button_left);
            this->panel_Control->Controls->Add(this->button_right);
            this->panel_Control->Dock=System::Windows::Forms::DockStyle::Fill;
            this->panel_Control->Location=System::Drawing::Point(3, 525);
            this->panel_Control->Name=L"panel_Control";
            this->panel_Control->Size=System::Drawing::Size(468, 54);
            this->panel_Control->TabIndex=14;
            //
            // label_page
            //
            this->label_page->AutoSize=true;
            this->label_page->Font=(gcnew System::Drawing::Font(L"PMingLiU", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->label_page->Location=System::Drawing::Point(208, 17);
            this->label_page->Name=L"label_page";
            this->label_page->Size=System::Drawing::Size(58, 19);
            this->label_page->TabIndex=7;
            this->label_page->Text=L"Page 0";
            //
            // button_left
            //
            this->button_left->Font=(gcnew System::Drawing::Font(L"PMingLiU", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->button_left->Location=System::Drawing::Point(11, 9);
            this->button_left->Name=L"button_left";
            this->button_left->Size=System::Drawing::Size(33, 34);
            this->button_left->TabIndex=6;
            this->button_left->Text=L"<<";
            this->button_left->UseVisualStyleBackColor=true;
            this->button_left->Click+=gcnew System::EventHandler(this, &RDSadminMainForm::button_left_Click);
            //
            // button_right
            //
            this->button_right->Font=(gcnew System::Drawing::Font(L"PMingLiU", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->button_right->Location=System::Drawing::Point(423, 9);
            this->button_right->Name=L"button_right";
            this->button_right->Size=System::Drawing::Size(33, 34);
            this->button_right->TabIndex=5;
            this->button_right->Text=L">>";
            this->button_right->UseVisualStyleBackColor=true;
            this->button_right->Click+=gcnew System::EventHandler(this, &RDSadminMainForm::button_right_Click);
            //
            // tableLayoutPanel_BG
            //
            this->tableLayoutPanel_BG->ColumnCount=2;
            this->tableLayoutPanel_BG->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                150)));
            this->tableLayoutPanel_BG->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                100)));
            this->tableLayoutPanel_BG->Controls->Add(this->tableLayoutPanel_Menu, 0, 0);
            this->tableLayoutPanel_BG->Controls->Add(this->tableLayoutPanel_Content, 1, 0);
            this->tableLayoutPanel_BG->Dock=System::Windows::Forms::DockStyle::Fill;
            this->tableLayoutPanel_BG->Location=System::Drawing::Point(0, 0);
            this->tableLayoutPanel_BG->Name=L"tableLayoutPanel_BG";
            this->tableLayoutPanel_BG->RowCount=1;
            this->tableLayoutPanel_BG->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
                100)));
            this->tableLayoutPanel_BG->Size=System::Drawing::Size(624, 582);
            this->tableLayoutPanel_BG->TabIndex=24;
            //
            // tableLayoutPanel_Menu
            //
            this->tableLayoutPanel_Menu->ColumnCount=1;
            this->tableLayoutPanel_Menu->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                100)));
            this->tableLayoutPanel_Menu->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                20)));
            this->tableLayoutPanel_Menu->Controls->Add(this->flowLayoutPanel_MenuDown, 0, 1);
            this->tableLayoutPanel_Menu->Controls->Add(this->flowLayoutPanel_MenuUp, 0, 0);
            this->tableLayoutPanel_Menu->Dock=System::Windows::Forms::DockStyle::Fill;
            this->tableLayoutPanel_Menu->Location=System::Drawing::Point(0, 0);
            this->tableLayoutPanel_Menu->Margin=System::Windows::Forms::Padding(0);
            this->tableLayoutPanel_Menu->Name=L"tableLayoutPanel_Menu";
            this->tableLayoutPanel_Menu->RowCount=2;
            this->tableLayoutPanel_Menu->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
                100)));
            this->tableLayoutPanel_Menu->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
                60)));
            this->tableLayoutPanel_Menu->Size=System::Drawing::Size(150, 582);
            this->tableLayoutPanel_Menu->TabIndex=0;
            //
            // flowLayoutPanel_MenuDown
            //
            this->flowLayoutPanel_MenuDown->BackColor=System::Drawing::Color::MidnightBlue;
            this->flowLayoutPanel_MenuDown->Controls->Add(this->label_LoginAuthorLv);
            this->flowLayoutPanel_MenuDown->Controls->Add(this->label_LoginID);
            this->flowLayoutPanel_MenuDown->Dock=System::Windows::Forms::DockStyle::Fill;
            this->flowLayoutPanel_MenuDown->FlowDirection=System::Windows::Forms::FlowDirection::BottomUp;
            this->flowLayoutPanel_MenuDown->Location=System::Drawing::Point(1, 522);
            this->flowLayoutPanel_MenuDown->Margin=System::Windows::Forms::Padding(1, 0, 1, 1);
            this->flowLayoutPanel_MenuDown->Name=L"flowLayoutPanel_MenuDown";
            this->flowLayoutPanel_MenuDown->Size=System::Drawing::Size(148, 59);
            this->flowLayoutPanel_MenuDown->TabIndex=4;
            //
            // label_LoginAuthorLv
            //
            this->label_LoginAuthorLv->AutoSize=true;
            this->label_LoginAuthorLv->ForeColor=System::Drawing::Color::White;
            this->label_LoginAuthorLv->Location=System::Drawing::Point(10, 37);
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
            this->label_LoginID->Location=System::Drawing::Point(10, 20);
            this->label_LoginID->Margin=System::Windows::Forms::Padding(10, 0, 10, 5);
            this->label_LoginID->Name=L"label_LoginID";
            this->label_LoginID->Size=System::Drawing::Size(48, 12);
            this->label_LoginID->TabIndex=17;
            this->label_LoginID->Text=L"Login ID";
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
            this->flowLayoutPanel_MenuUp->Size=System::Drawing::Size(148, 521);
            this->flowLayoutPanel_MenuUp->TabIndex=3;
            //
            // button_DashBoard
            //
            this->button_DashBoard->Font=(gcnew System::Drawing::Font(L"PMingLiU", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->button_DashBoard->Location=System::Drawing::Point(12, 12);
            this->button_DashBoard->Margin=System::Windows::Forms::Padding(12, 12, 12, 0);
            this->button_DashBoard->Name=L"button_DashBoard";
            this->button_DashBoard->Size=System::Drawing::Size(125, 50);
            this->button_DashBoard->TabIndex=31;
            this->button_DashBoard->Text=L"Statistics Dashboard";
            this->button_DashBoard->UseVisualStyleBackColor=true;
            this->button_DashBoard->Visible=false;
            this->button_DashBoard->Click+=gcnew System::EventHandler(this, &RDSadminMainForm::button_DashBoard_Click);
            //
            // button_ServiceCall
            //
            this->button_ServiceCall->BackgroundImage=(cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_ServiceCall.BackgroundImage")));
            this->button_ServiceCall->Font=(gcnew System::Drawing::Font(L"PMingLiU", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->button_ServiceCall->Location=System::Drawing::Point(12, 74);
            this->button_ServiceCall->Margin=System::Windows::Forms::Padding(12, 12, 12, 0);
            this->button_ServiceCall->Name=L"button_ServiceCall";
            this->button_ServiceCall->Size=System::Drawing::Size(125, 50);
            this->button_ServiceCall->TabIndex=28;
            this->button_ServiceCall->Text=L"Open \r\nService Calls";
            this->button_ServiceCall->UseVisualStyleBackColor=true;
            this->button_ServiceCall->Click+=gcnew System::EventHandler(this, &RDSadminMainForm::button_ServiceCall_Click);
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
            this->button_RDSuser->Click+=gcnew System::EventHandler(this, &RDSadminMainForm::button_RDSuser_Click);
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
            this->button_Supervisor->Click+=gcnew System::EventHandler(this, &RDSadminMainForm::button_Supervisor_Click);
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
            this->button_Dealer->Click+=gcnew System::EventHandler(this, &RDSadminMainForm::button_Dealer_Click);
            //
            // button_LogOut
            //
            this->button_LogOut->Font=(gcnew System::Drawing::Font(L"PMingLiU", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->button_LogOut->Location=System::Drawing::Point(12, 322);
            this->button_LogOut->Margin=System::Windows::Forms::Padding(12, 12, 12, 0);
            this->button_LogOut->Name=L"button_LogOut";
            this->button_LogOut->Size=System::Drawing::Size(125, 50);
            this->button_LogOut->TabIndex=33;
            this->button_LogOut->Text=L"Log Out";
            this->button_LogOut->UseVisualStyleBackColor=true;
            this->button_LogOut->Click+=gcnew System::EventHandler(this, &RDSadminMainForm::button_LogOut_Click);
            //
            // tableLayoutPanel_Content
            //
            this->tableLayoutPanel_Content->ColumnCount=1;
            this->tableLayoutPanel_Content->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                100)));
            this->tableLayoutPanel_Content->Controls->Add(this->panel_title, 0, 0);
            this->tableLayoutPanel_Content->Controls->Add(this->panel_Control, 0, 2);
            this->tableLayoutPanel_Content->Controls->Add(this->tableLayoutPanel_list, 0, 1);
            this->tableLayoutPanel_Content->Dock=System::Windows::Forms::DockStyle::Fill;
            this->tableLayoutPanel_Content->Location=System::Drawing::Point(150, 0);
            this->tableLayoutPanel_Content->Margin=System::Windows::Forms::Padding(0);
            this->tableLayoutPanel_Content->Name=L"tableLayoutPanel_Content";
            this->tableLayoutPanel_Content->RowCount=3;
            this->tableLayoutPanel_Content->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
                50)));
            this->tableLayoutPanel_Content->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
                100)));
            this->tableLayoutPanel_Content->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
                60)));
            this->tableLayoutPanel_Content->Size=System::Drawing::Size(474, 582);
            this->tableLayoutPanel_Content->TabIndex=1;
            //
            // tableLayoutPanel_list
            //
            this->tableLayoutPanel_list->ColumnCount=1;
            this->tableLayoutPanel_list->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                100)));
            this->tableLayoutPanel_list->Controls->Add(this->panel_list1, 0, 0);
            this->tableLayoutPanel_list->Controls->Add(this->panel_list9, 0, 8);
            this->tableLayoutPanel_list->Controls->Add(this->panel_list2, 0, 1);
            this->tableLayoutPanel_list->Controls->Add(this->panel_list8, 0, 7);
            this->tableLayoutPanel_list->Controls->Add(this->panel_list3, 0, 2);
            this->tableLayoutPanel_list->Controls->Add(this->panel_list7, 0, 6);
            this->tableLayoutPanel_list->Controls->Add(this->panel_list5, 0, 4);
            this->tableLayoutPanel_list->Controls->Add(this->panel_list6, 0, 5);
            this->tableLayoutPanel_list->Controls->Add(this->panel_list4, 0, 3);
            this->tableLayoutPanel_list->Dock=System::Windows::Forms::DockStyle::Fill;
            this->tableLayoutPanel_list->Location=System::Drawing::Point(0, 50);
            this->tableLayoutPanel_list->Margin=System::Windows::Forms::Padding(0);
            this->tableLayoutPanel_list->Name=L"tableLayoutPanel_list";
            this->tableLayoutPanel_list->RowCount=10;
            this->tableLayoutPanel_list->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
                11)));
            this->tableLayoutPanel_list->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
                11)));
            this->tableLayoutPanel_list->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
                11)));
            this->tableLayoutPanel_list->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
                11)));
            this->tableLayoutPanel_list->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
                11)));
            this->tableLayoutPanel_list->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
                11)));
            this->tableLayoutPanel_list->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
                11)));
            this->tableLayoutPanel_list->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
                11)));
            this->tableLayoutPanel_list->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
                11)));
            this->tableLayoutPanel_list->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
                1)));
            this->tableLayoutPanel_list->Size=System::Drawing::Size(474, 472);
            this->tableLayoutPanel_list->TabIndex=15;
            //
            // RDSadminMainForm
            //
            this->AutoScaleDimensions=System::Drawing::SizeF(6, 12);
            this->AutoScaleMode=System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor=System::Drawing::Color::LightSteelBlue;
            this->ClientSize=System::Drawing::Size(624, 582);
            this->ControlBox=false;
            this->Controls->Add(this->tableLayoutPanel_BG);
            this->Icon=(cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
            this->MaximizeBox=false;
            this->MinimizeBox=false;
            this->Name=L"RDSadminMainForm";
            this->StartPosition=System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text=L"RDSadminMainForm";
            this->Load+=gcnew System::EventHandler(this, &RDSadminMainForm::RDSadminMainForm_Load);
            this->panel_title->ResumeLayout(false);
            this->panel_title->PerformLayout();
            this->panel_list9->ResumeLayout(false);
            this->panel_list9->PerformLayout();
            this->panel_list8->ResumeLayout(false);
            this->panel_list8->PerformLayout();
            this->panel_list4->ResumeLayout(false);
            this->panel_list4->PerformLayout();
            this->panel_list6->ResumeLayout(false);
            this->panel_list6->PerformLayout();
            this->panel_list2->ResumeLayout(false);
            this->panel_list2->PerformLayout();
            this->panel_list7->ResumeLayout(false);
            this->panel_list7->PerformLayout();
            this->panel_list3->ResumeLayout(false);
            this->panel_list3->PerformLayout();
            this->panel_list5->ResumeLayout(false);
            this->panel_list5->PerformLayout();
            this->panel_list1->ResumeLayout(false);
            this->panel_list1->PerformLayout();
            this->panel_Control->ResumeLayout(false);
            this->panel_Control->PerformLayout();
            this->tableLayoutPanel_BG->ResumeLayout(false);
            this->tableLayoutPanel_Menu->ResumeLayout(false);
            this->flowLayoutPanel_MenuDown->ResumeLayout(false);
            this->flowLayoutPanel_MenuDown->PerformLayout();
            this->flowLayoutPanel_MenuUp->ResumeLayout(false);
            this->tableLayoutPanel_Content->ResumeLayout(false);
            this->tableLayoutPanel_list->ResumeLayout(false);
            this->ResumeLayout(false);
        }
#pragma endregion
    public:
    private: System::Void RDSadminMainForm_Load(System::Object^  sender, System::EventArgs^  e);
    private: void Draw_OSCList();
    public: System::Void button_Supervisor_Click(System::Object^  sender, System::EventArgs^  e);
    public: System::Void button_RDSuser_Click(System::Object^  sender, System::EventArgs^  e);
    private: System::Void label_list1_Click(System::Object^  sender, System::EventArgs^  e);
    private: System::Void label_list2_Click(System::Object^  sender, System::EventArgs^  e);
    private: System::Void label_list3_Click(System::Object^  sender, System::EventArgs^  e);
    private: System::Void label_list4_Click(System::Object^  sender, System::EventArgs^  e);
    private: System::Void label_list5_Click(System::Object^  sender, System::EventArgs^  e);
    private: System::Void label_list6_Click(System::Object^  sender, System::EventArgs^  e);
    private: System::Void label_list7_Click(System::Object^  sender, System::EventArgs^  e);
    private: System::Void label_list8_Click(System::Object^  sender, System::EventArgs^  e);
    private: System::Void label_list9_Click(System::Object^  sender, System::EventArgs^  e);
    private: System::Void label_list1_DoubleClick(System::Object^  sender, System::EventArgs^  e);
    private: System::Void label_list2_DoubleClick(System::Object^  sender, System::EventArgs^  e);
    private: System::Void label_list3_DoubleClick(System::Object^  sender, System::EventArgs^  e);
    private: System::Void label_list4_DoubleClick(System::Object^  sender, System::EventArgs^  e);
    private: System::Void label_list5_DoubleClick(System::Object^  sender, System::EventArgs^  e);
    private: System::Void label_list6_DoubleClick(System::Object^  sender, System::EventArgs^  e);
    private: System::Void label_list7_DoubleClick(System::Object^  sender, System::EventArgs^  e);
    private: System::Void label_list8_DoubleClick(System::Object^  sender, System::EventArgs^  e);
    private: System::Void label_list9_DoubleClick(System::Object^  sender, System::EventArgs^  e);
    private: System::Void button_left_Click(System::Object^  sender, System::EventArgs^  e);
    private: System::Void button_right_Click(System::Object^  sender, System::EventArgs^  e);
    private: System::Void button_ServiceCall_Click(System::Object^  sender, System::EventArgs^  e)
    { //dummy...
    }
    private: System::Void button_Dealer_Click(System::Object^  sender, System::EventArgs^  e);
    private: System::Void button_DashBoard_Click(System::Object^  sender, System::EventArgs^  e);
    private: System::Void button_LogOut_Click(System::Object^  sender, System::EventArgs^  e)
    {
        if(this->iNas.LoginUser_no==0){
            MessageBox::Show(LOGIN_ERR_NO_PERSON_BEF_UNLOCK, "ERROR",
                MessageBoxButtons::OK, MessageBoxIcon::Information);
        }
        else{
            int rtn=this->iNas.Unlock_Person_Login(this->iNas.LoginUser_no);
            if(rtn<0){
                MessageBox::Show(LOGIN_ERR_FILE_LOSS_BEF_UNLOCK, "ERROR",
                    MessageBoxButtons::OK, MessageBoxIcon::Information);
            }
        }
        this->Close(); //close login form and exit application
        Application::Exit(); //!!!!!!!!!!!!!!!!!!!
    }
    };
}
