#pragma once

namespace RDSadmin {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for aTempForm
	/// </summary>
	public ref class aTempForm : public System::Windows::Forms::Form
	{
	public:
		aTempForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~aTempForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel_BG;
	protected:
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
	private: System::Windows::Forms::Button^  button_back;
	private: System::Windows::Forms::Label^  label_Title;
	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel1;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart_OSC_Dealer_T10;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart_Efficiency;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart_Channel;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart_Parts;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart_ErrCode;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart_Model;





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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea23 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Series^  series23 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Title^  title23 = (gcnew System::Windows::Forms::DataVisualization::Charting::Title());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea22 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Series^  series22 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Title^  title22 = (gcnew System::Windows::Forms::DataVisualization::Charting::Title());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea21 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Series^  series21 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Title^  title21 = (gcnew System::Windows::Forms::DataVisualization::Charting::Title());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea20 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Series^  series20 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Title^  title20 = (gcnew System::Windows::Forms::DataVisualization::Charting::Title());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea24 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Series^  series24 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Title^  title24 = (gcnew System::Windows::Forms::DataVisualization::Charting::Title());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea25 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series25 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Title^  title25 = (gcnew System::Windows::Forms::DataVisualization::Charting::Title());
			this->tableLayoutPanel_BG = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel_Menu = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->flowLayoutPanel_MenuUp = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->button_DashBoard = (gcnew System::Windows::Forms::Button());
			this->button_ServiceCall = (gcnew System::Windows::Forms::Button());
			this->button_RDSuser = (gcnew System::Windows::Forms::Button());
			this->button_Supervisor = (gcnew System::Windows::Forms::Button());
			this->button_Dealer = (gcnew System::Windows::Forms::Button());
			this->flowLayoutPanel_MenuDown = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->label_LoginAuthorLv = (gcnew System::Windows::Forms::Label());
			this->label_LoginID = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel_content = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->panel_title = (gcnew System::Windows::Forms::Panel());
			this->button_back = (gcnew System::Windows::Forms::Button());
			this->label_Title = (gcnew System::Windows::Forms::Label());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->chart_Parts = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->chart_Channel = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->chart_Efficiency = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->chart_OSC_Dealer_T10 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->chart_ErrCode = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->chart_Model = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->tableLayoutPanel_BG->SuspendLayout();
			this->tableLayoutPanel_Menu->SuspendLayout();
			this->flowLayoutPanel_MenuUp->SuspendLayout();
			this->flowLayoutPanel_MenuDown->SuspendLayout();
			this->tableLayoutPanel_content->SuspendLayout();
			this->panel_title->SuspendLayout();
			this->flowLayoutPanel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart_Parts))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart_Channel))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart_Efficiency))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart_OSC_Dealer_T10))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart_ErrCode))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart_Model))->BeginInit();
			this->SuspendLayout();
			// 
			// tableLayoutPanel_BG
			// 
			this->tableLayoutPanel_BG->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->tableLayoutPanel_BG->ColumnCount = 2;
			this->tableLayoutPanel_BG->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				150)));
			this->tableLayoutPanel_BG->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel_BG->Controls->Add(this->tableLayoutPanel_Menu, 0, 0);
			this->tableLayoutPanel_BG->Controls->Add(this->tableLayoutPanel_content, 1, 0);
			this->tableLayoutPanel_BG->Dock = System::Windows::Forms::DockStyle::Left;
			this->tableLayoutPanel_BG->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel_BG->Name = L"tableLayoutPanel_BG";
			this->tableLayoutPanel_BG->RowCount = 1;
			this->tableLayoutPanel_BG->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel_BG->Size = System::Drawing::Size(1231, 787);
			this->tableLayoutPanel_BG->TabIndex = 18;
			// 
			// tableLayoutPanel_Menu
			// 
			this->tableLayoutPanel_Menu->ColumnCount = 1;
			this->tableLayoutPanel_Menu->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel_Menu->Controls->Add(this->flowLayoutPanel_MenuUp, 0, 0);
			this->tableLayoutPanel_Menu->Controls->Add(this->flowLayoutPanel_MenuDown, 0, 1);
			this->tableLayoutPanel_Menu->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel_Menu->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel_Menu->Margin = System::Windows::Forms::Padding(0);
			this->tableLayoutPanel_Menu->Name = L"tableLayoutPanel_Menu";
			this->tableLayoutPanel_Menu->RowCount = 2;
			this->tableLayoutPanel_Menu->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel_Menu->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				50)));
			this->tableLayoutPanel_Menu->Size = System::Drawing::Size(150, 787);
			this->tableLayoutPanel_Menu->TabIndex = 0;
			// 
			// flowLayoutPanel_MenuUp
			// 
			this->flowLayoutPanel_MenuUp->BackColor = System::Drawing::Color::MidnightBlue;
			this->flowLayoutPanel_MenuUp->Controls->Add(this->button_DashBoard);
			this->flowLayoutPanel_MenuUp->Controls->Add(this->button_ServiceCall);
			this->flowLayoutPanel_MenuUp->Controls->Add(this->button_RDSuser);
			this->flowLayoutPanel_MenuUp->Controls->Add(this->button_Supervisor);
			this->flowLayoutPanel_MenuUp->Controls->Add(this->button_Dealer);
			this->flowLayoutPanel_MenuUp->Dock = System::Windows::Forms::DockStyle::Fill;
			this->flowLayoutPanel_MenuUp->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			this->flowLayoutPanel_MenuUp->Location = System::Drawing::Point(1, 1);
			this->flowLayoutPanel_MenuUp->Margin = System::Windows::Forms::Padding(1, 1, 1, 0);
			this->flowLayoutPanel_MenuUp->Name = L"flowLayoutPanel_MenuUp";
			this->flowLayoutPanel_MenuUp->Size = System::Drawing::Size(148, 736);
			this->flowLayoutPanel_MenuUp->TabIndex = 0;
			// 
			// button_DashBoard
			// 
			this->button_DashBoard->Font = (gcnew System::Drawing::Font(L"PMingLiU", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button_DashBoard->Location = System::Drawing::Point(12, 12);
			this->button_DashBoard->Margin = System::Windows::Forms::Padding(12, 12, 12, 0);
			this->button_DashBoard->Name = L"button_DashBoard";
			this->button_DashBoard->Size = System::Drawing::Size(125, 50);
			this->button_DashBoard->TabIndex = 31;
			this->button_DashBoard->Text = L"Statistics Dashboard";
			this->button_DashBoard->UseVisualStyleBackColor = true;
			// 
			// button_ServiceCall
			// 
			this->button_ServiceCall->Font = (gcnew System::Drawing::Font(L"PMingLiU", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button_ServiceCall->Location = System::Drawing::Point(12, 74);
			this->button_ServiceCall->Margin = System::Windows::Forms::Padding(12, 12, 12, 0);
			this->button_ServiceCall->Name = L"button_ServiceCall";
			this->button_ServiceCall->Size = System::Drawing::Size(125, 50);
			this->button_ServiceCall->TabIndex = 28;
			this->button_ServiceCall->Text = L"Open \r\nService Calls";
			this->button_ServiceCall->UseVisualStyleBackColor = true;
			// 
			// button_RDSuser
			// 
			this->button_RDSuser->Font = (gcnew System::Drawing::Font(L"PMingLiU", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button_RDSuser->Location = System::Drawing::Point(12, 136);
			this->button_RDSuser->Margin = System::Windows::Forms::Padding(12, 12, 12, 0);
			this->button_RDSuser->Name = L"button_RDSuser";
			this->button_RDSuser->Size = System::Drawing::Size(125, 50);
			this->button_RDSuser->TabIndex = 29;
			this->button_RDSuser->Text = L"RDS User List";
			this->button_RDSuser->UseVisualStyleBackColor = true;
			// 
			// button_Supervisor
			// 
			this->button_Supervisor->Font = (gcnew System::Drawing::Font(L"PMingLiU", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button_Supervisor->Location = System::Drawing::Point(12, 198);
			this->button_Supervisor->Margin = System::Windows::Forms::Padding(12, 12, 12, 0);
			this->button_Supervisor->Name = L"button_Supervisor";
			this->button_Supervisor->Size = System::Drawing::Size(125, 50);
			this->button_Supervisor->TabIndex = 30;
			this->button_Supervisor->Text = L"Supervisor Account";
			this->button_Supervisor->UseVisualStyleBackColor = true;
			// 
			// button_Dealer
			// 
			this->button_Dealer->Font = (gcnew System::Drawing::Font(L"PMingLiU", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button_Dealer->Location = System::Drawing::Point(12, 260);
			this->button_Dealer->Margin = System::Windows::Forms::Padding(12, 12, 12, 0);
			this->button_Dealer->Name = L"button_Dealer";
			this->button_Dealer->Size = System::Drawing::Size(125, 50);
			this->button_Dealer->TabIndex = 32;
			this->button_Dealer->Text = L"Dealer List";
			this->button_Dealer->UseVisualStyleBackColor = true;
			// 
			// flowLayoutPanel_MenuDown
			// 
			this->flowLayoutPanel_MenuDown->BackColor = System::Drawing::Color::MidnightBlue;
			this->flowLayoutPanel_MenuDown->Controls->Add(this->label_LoginAuthorLv);
			this->flowLayoutPanel_MenuDown->Controls->Add(this->label_LoginID);
			this->flowLayoutPanel_MenuDown->Dock = System::Windows::Forms::DockStyle::Fill;
			this->flowLayoutPanel_MenuDown->FlowDirection = System::Windows::Forms::FlowDirection::BottomUp;
			this->flowLayoutPanel_MenuDown->Location = System::Drawing::Point(1, 737);
			this->flowLayoutPanel_MenuDown->Margin = System::Windows::Forms::Padding(1, 0, 1, 1);
			this->flowLayoutPanel_MenuDown->Name = L"flowLayoutPanel_MenuDown";
			this->flowLayoutPanel_MenuDown->Size = System::Drawing::Size(148, 49);
			this->flowLayoutPanel_MenuDown->TabIndex = 1;
			// 
			// label_LoginAuthorLv
			// 
			this->label_LoginAuthorLv->AutoSize = true;
			this->label_LoginAuthorLv->ForeColor = System::Drawing::Color::White;
			this->label_LoginAuthorLv->Location = System::Drawing::Point(10, 27);
			this->label_LoginAuthorLv->Margin = System::Windows::Forms::Padding(10, 0, 10, 10);
			this->label_LoginAuthorLv->Name = L"label_LoginAuthorLv";
			this->label_LoginAuthorLv->Size = System::Drawing::Size(97, 12);
			this->label_LoginAuthorLv->TabIndex = 18;
			this->label_LoginAuthorLv->Text = L"Login Authority Lv";
			// 
			// label_LoginID
			// 
			this->label_LoginID->AutoSize = true;
			this->label_LoginID->ForeColor = System::Drawing::Color::White;
			this->label_LoginID->Location = System::Drawing::Point(10, 10);
			this->label_LoginID->Margin = System::Windows::Forms::Padding(10, 0, 10, 5);
			this->label_LoginID->Name = L"label_LoginID";
			this->label_LoginID->Size = System::Drawing::Size(48, 12);
			this->label_LoginID->TabIndex = 17;
			this->label_LoginID->Text = L"Login ID";
			// 
			// tableLayoutPanel_content
			// 
			this->tableLayoutPanel_content->ColumnCount = 1;
			this->tableLayoutPanel_content->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel_content->Controls->Add(this->panel_title, 0, 0);
			this->tableLayoutPanel_content->Controls->Add(this->flowLayoutPanel1, 0, 1);
			this->tableLayoutPanel_content->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel_content->Location = System::Drawing::Point(150, 0);
			this->tableLayoutPanel_content->Margin = System::Windows::Forms::Padding(0);
			this->tableLayoutPanel_content->Name = L"tableLayoutPanel_content";
			this->tableLayoutPanel_content->RowCount = 2;
			this->tableLayoutPanel_content->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				60)));
			this->tableLayoutPanel_content->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel_content->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				20)));
			this->tableLayoutPanel_content->Size = System::Drawing::Size(1081, 787);
			this->tableLayoutPanel_content->TabIndex = 1;
			// 
			// panel_title
			// 
			this->panel_title->BackColor = System::Drawing::Color::SteelBlue;
			this->panel_title->Controls->Add(this->button_back);
			this->panel_title->Controls->Add(this->label_Title);
			this->panel_title->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel_title->Location = System::Drawing::Point(1, 0);
			this->panel_title->Margin = System::Windows::Forms::Padding(1, 0, 0, 0);
			this->panel_title->Name = L"panel_title";
			this->panel_title->Size = System::Drawing::Size(1080, 60);
			this->panel_title->TabIndex = 19;
			// 
			// button_back
			// 
			this->button_back->Font = (gcnew System::Drawing::Font(L"PMingLiU", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button_back->Location = System::Drawing::Point(16, 7);
			this->button_back->Name = L"button_back";
			this->button_back->Size = System::Drawing::Size(66, 37);
			this->button_back->TabIndex = 1;
			this->button_back->Text = L"Back";
			this->button_back->UseVisualStyleBackColor = true;
			// 
			// label_Title
			// 
			this->label_Title->AutoSize = true;
			this->label_Title->Font = (gcnew System::Drawing::Font(L"PMingLiU", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label_Title->ForeColor = System::Drawing::Color::White;
			this->label_Title->Location = System::Drawing::Point(353, 11);
			this->label_Title->Name = L"label_Title";
			this->label_Title->Size = System::Drawing::Size(305, 29);
			this->label_Title->TabIndex = 0;
			this->label_Title->Text = L"Statistics Dashboard - 2";
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->Controls->Add(this->chart_OSC_Dealer_T10);
			this->flowLayoutPanel1->Controls->Add(this->chart_Efficiency);
			this->flowLayoutPanel1->Controls->Add(this->chart_Channel);
			this->flowLayoutPanel1->Controls->Add(this->chart_Parts);
			this->flowLayoutPanel1->Controls->Add(this->chart_ErrCode);
			this->flowLayoutPanel1->Controls->Add(this->chart_Model);
			this->flowLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->flowLayoutPanel1->Location = System::Drawing::Point(1, 60);
			this->flowLayoutPanel1->Margin = System::Windows::Forms::Padding(1, 0, 0, 0);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(1080, 727);
			this->flowLayoutPanel1->TabIndex = 20;
			// 
			// chart_Parts
			// 
			this->chart_Parts->BackColor = System::Drawing::SystemColors::Control;
			this->chart_Parts->BorderlineColor = System::Drawing::Color::Black;
			this->chart_Parts->BorderlineDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Solid;
			this->chart_Parts->BorderSkin->BackGradientStyle = System::Windows::Forms::DataVisualization::Charting::GradientStyle::LeftRight;
			chartArea23->AxisX->Interval = 1;
			chartArea23->AxisX->IsLabelAutoFit = false;
			chartArea23->AxisX->LabelStyle->Angle = -45;
			chartArea23->AxisX->MajorGrid->Enabled = false;
			chartArea23->BackColor = System::Drawing::SystemColors::Control;
			chartArea23->Name = L"ChartArea1";
			this->chart_Parts->ChartAreas->Add(chartArea23);
			this->chart_Parts->Location = System::Drawing::Point(424, 243);
			this->chart_Parts->Margin = System::Windows::Forms::Padding(1);
			this->chart_Parts->Name = L"chart_Parts";
			series23->BackGradientStyle = System::Windows::Forms::DataVisualization::Charting::GradientStyle::DiagonalLeft;
			series23->BorderColor = System::Drawing::Color::Gray;
			series23->ChartArea = L"ChartArea1";
			series23->Color = System::Drawing::Color::Chartreuse;
			series23->IsValueShownAsLabel = true;
			series23->LabelAngle = -25;
			series23->Name = L"parts";
			series23->ShadowColor = System::Drawing::Color::Green;
			series23->ShadowOffset = 5;
			this->chart_Parts->Series->Add(series23);
			this->chart_Parts->Size = System::Drawing::Size(652, 240);
			this->chart_Parts->TabIndex = 26;
			this->chart_Parts->Text = L"chart1";
			title23->Font = (gcnew System::Drawing::Font(L"Droid Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			title23->Name = L"Title1";
			title23->Text = L"test title";
			this->chart_Parts->Titles->Add(title23);
			// 
			// chart_Channel
			// 
			this->chart_Channel->BackColor = System::Drawing::SystemColors::Control;
			this->chart_Channel->BorderlineColor = System::Drawing::Color::Black;
			this->chart_Channel->BorderlineDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Solid;
			chartArea22->Area3DStyle->Inclination = 20;
			chartArea22->Area3DStyle->IsClustered = true;
			chartArea22->Area3DStyle->WallWidth = 3;
			chartArea22->AxisX->Interval = 1;
			chartArea22->AxisX->IsLabelAutoFit = false;
			chartArea22->AxisX->LabelStyle->Angle = -25;
			chartArea22->AxisX->MajorGrid->Enabled = false;
			chartArea22->BackColor = System::Drawing::SystemColors::Control;
			chartArea22->Name = L"ChartArea1";
			this->chart_Channel->ChartAreas->Add(chartArea22);
			this->chart_Channel->Location = System::Drawing::Point(1, 243);
			this->chart_Channel->Margin = System::Windows::Forms::Padding(1);
			this->chart_Channel->Name = L"chart_Channel";
			this->chart_Channel->Palette = System::Windows::Forms::DataVisualization::Charting::ChartColorPalette::None;
			this->chart_Channel->PaletteCustomColors = gcnew cli::array< System::Drawing::Color >(7) {
				System::Drawing::Color::MediumPurple,
					System::Drawing::Color::OliveDrab, System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)),
					static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0))), System::Drawing::Color::LightSkyBlue,
					System::Drawing::Color::Orchid, System::Drawing::Color::Brown, System::Drawing::Color::SandyBrown
			};
			series22->BorderColor = System::Drawing::Color::Black;
			series22->ChartArea = L"ChartArea1";
			series22->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Pie;
			series22->Color = System::Drawing::Color::Chartreuse;
			series22->CustomProperties = L"PieDrawingStyle=SoftEdge, PieLabelStyle=Outside, PieStartAngle=10";
			series22->IsValueShownAsLabel = true;
			series22->MarkerBorderColor = System::Drawing::Color::BlueViolet;
			series22->MarkerColor = System::Drawing::Color::Blue;
			series22->MarkerSize = 10;
			series22->MarkerStyle = System::Windows::Forms::DataVisualization::Charting::MarkerStyle::Diamond;
			series22->Name = L"CallByChannel";
			this->chart_Channel->Series->Add(series22);
			this->chart_Channel->Size = System::Drawing::Size(421, 240);
			this->chart_Channel->TabIndex = 25;
			this->chart_Channel->Text = L"chart1";
			title22->Font = (gcnew System::Drawing::Font(L"Droid Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			title22->Name = L"Title1";
			title22->Text = L"test title";
			this->chart_Channel->Titles->Add(title22);
			// 
			// chart_Efficiency
			// 
			this->chart_Efficiency->BackColor = System::Drawing::SystemColors::Control;
			this->chart_Efficiency->BorderlineColor = System::Drawing::Color::Black;
			this->chart_Efficiency->BorderlineDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Solid;
			chartArea21->AlignmentOrientation = static_cast<System::Windows::Forms::DataVisualization::Charting::AreaAlignmentOrientations>((System::Windows::Forms::DataVisualization::Charting::AreaAlignmentOrientations::Vertical | System::Windows::Forms::DataVisualization::Charting::AreaAlignmentOrientations::Horizontal));
			chartArea21->AxisX->Interval = 1;
			chartArea21->AxisX->IsLabelAutoFit = false;
			chartArea21->AxisX->LabelStyle->Angle = -60;
			chartArea21->AxisX->MajorGrid->Enabled = false;
			chartArea21->BackColor = System::Drawing::SystemColors::Control;
			chartArea21->Name = L"ChartArea1";
			this->chart_Efficiency->ChartAreas->Add(chartArea21);
			this->chart_Efficiency->Location = System::Drawing::Point(545, 1);
			this->chart_Efficiency->Margin = System::Windows::Forms::Padding(1);
			this->chart_Efficiency->Name = L"chart_Efficiency";
			series21->BorderColor = System::Drawing::Color::DodgerBlue;
			series21->BorderWidth = 3;
			series21->ChartArea = L"ChartArea1";
			series21->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series21->Color = System::Drawing::Color::LightSkyBlue;
			series21->IsValueShownAsLabel = true;
			series21->LabelFormat = L"{0:0.00}";
			series21->MarkerBorderColor = System::Drawing::Color::BlueViolet;
			series21->MarkerColor = System::Drawing::Color::Blue;
			series21->MarkerSize = 10;
			series21->MarkerStyle = System::Windows::Forms::DataVisualization::Charting::MarkerStyle::Diamond;
			series21->Name = L"DealerEfficiency";
			series21->ToolTip = L"Average Ticket closed Days";
			this->chart_Efficiency->Series->Add(series21);
			this->chart_Efficiency->Size = System::Drawing::Size(532, 240);
			this->chart_Efficiency->TabIndex = 24;
			this->chart_Efficiency->Text = L"chart1";
			title21->Font = (gcnew System::Drawing::Font(L"Droid Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			title21->Name = L"Title1";
			title21->Text = L"test title";
			this->chart_Efficiency->Titles->Add(title21);
			// 
			// chart_OSC_Dealer_T10
			// 
			this->chart_OSC_Dealer_T10->BackColor = System::Drawing::SystemColors::Control;
			this->chart_OSC_Dealer_T10->BorderlineColor = System::Drawing::Color::Black;
			this->chart_OSC_Dealer_T10->BorderlineDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Solid;
			this->chart_OSC_Dealer_T10->BorderSkin->BackGradientStyle = System::Windows::Forms::DataVisualization::Charting::GradientStyle::LeftRight;
			chartArea20->AxisX->Interval = 1;
			chartArea20->AxisX->IsLabelAutoFit = false;
			chartArea20->AxisX->MajorGrid->Enabled = false;
			chartArea20->BackColor = System::Drawing::SystemColors::Control;
			chartArea20->Name = L"ChartArea1";
			this->chart_OSC_Dealer_T10->ChartAreas->Add(chartArea20);
			this->chart_OSC_Dealer_T10->Location = System::Drawing::Point(1, 1);
			this->chart_OSC_Dealer_T10->Margin = System::Windows::Forms::Padding(1);
			this->chart_OSC_Dealer_T10->Name = L"chart_OSC_Dealer_T10";
			series20->BorderColor = System::Drawing::Color::DodgerBlue;
			series20->ChartArea = L"ChartArea1";
			series20->Color = System::Drawing::Color::SkyBlue;
			series20->IsValueShownAsLabel = true;
			series20->Name = L"OpenServiceCall";
			this->chart_OSC_Dealer_T10->Series->Add(series20);
			this->chart_OSC_Dealer_T10->Size = System::Drawing::Size(542, 240);
			this->chart_OSC_Dealer_T10->TabIndex = 23;
			this->chart_OSC_Dealer_T10->Text = L"chart1";
			title20->Font = (gcnew System::Drawing::Font(L"Droid Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			title20->Name = L"Title1";
			title20->Text = L"test title";
			this->chart_OSC_Dealer_T10->Titles->Add(title20);
			// 
			// chart_ErrCode
			// 
			this->chart_ErrCode->BackColor = System::Drawing::SystemColors::Control;
			this->chart_ErrCode->BorderlineColor = System::Drawing::Color::Black;
			this->chart_ErrCode->BorderlineDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Solid;
			this->chart_ErrCode->BorderSkin->BackGradientStyle = System::Windows::Forms::DataVisualization::Charting::GradientStyle::LeftRight;
			chartArea24->AlignmentOrientation = static_cast<System::Windows::Forms::DataVisualization::Charting::AreaAlignmentOrientations>((System::Windows::Forms::DataVisualization::Charting::AreaAlignmentOrientations::Vertical | System::Windows::Forms::DataVisualization::Charting::AreaAlignmentOrientations::Horizontal));
			chartArea24->Area3DStyle->Enable3D = true;
			chartArea24->Area3DStyle->Inclination = 18;
			chartArea24->Area3DStyle->IsRightAngleAxes = false;
			chartArea24->Area3DStyle->Perspective = 5;
			chartArea24->AxisX->Interval = 1;
			chartArea24->AxisX->IsLabelAutoFit = false;
			chartArea24->AxisX->LabelStyle->Angle = -30;
			chartArea24->AxisX->MajorGrid->Enabled = false;
			chartArea24->BackColor = System::Drawing::SystemColors::Control;
			chartArea24->BackGradientStyle = System::Windows::Forms::DataVisualization::Charting::GradientStyle::LeftRight;
			chartArea24->Name = L"ChartArea1";
			chartArea24->Position->Auto = false;
			chartArea24->Position->Height = 82.32126F;
			chartArea24->Position->Width = 100;
			chartArea24->Position->Y = 14.67874F;
			chartArea24->ShadowColor = System::Drawing::Color::Silver;
			this->chart_ErrCode->ChartAreas->Add(chartArea24);
			this->chart_ErrCode->Location = System::Drawing::Point(1, 485);
			this->chart_ErrCode->Margin = System::Windows::Forms::Padding(1);
			this->chart_ErrCode->Name = L"chart_ErrCode";
			series24->BorderColor = System::Drawing::Color::Black;
			series24->ChartArea = L"ChartArea1";
			series24->Color = System::Drawing::Color::DarkOrange;
			series24->CustomProperties = L"DrawingStyle=Cylinder";
			series24->IsValueShownAsLabel = true;
			series24->LabelAngle = -25;
			series24->Name = L"Errors";
			series24->ShadowColor = System::Drawing::Color::Green;
			series24->ShadowOffset = 5;
			this->chart_ErrCode->Series->Add(series24);
			this->chart_ErrCode->Size = System::Drawing::Size(632, 240);
			this->chart_ErrCode->TabIndex = 27;
			this->chart_ErrCode->Text = L"chart1";
			title24->Font = (gcnew System::Drawing::Font(L"Droid Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			title24->Name = L"Title1";
			title24->Text = L"test title";
			this->chart_ErrCode->Titles->Add(title24);
			// 
			// chart_Model
			// 
			this->chart_Model->BackColor = System::Drawing::SystemColors::Control;
			this->chart_Model->BorderlineColor = System::Drawing::Color::Black;
			this->chart_Model->BorderlineDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Solid;
			chartArea25->Area3DStyle->Enable3D = true;
			chartArea25->Area3DStyle->Inclination = 20;
			chartArea25->Area3DStyle->IsClustered = true;
			chartArea25->Area3DStyle->WallWidth = 3;
			chartArea25->AxisX->Interval = 1;
			chartArea25->AxisX->IsLabelAutoFit = false;
			chartArea25->AxisX->LabelStyle->Angle = -25;
			chartArea25->AxisX->MajorGrid->Enabled = false;
			chartArea25->BackColor = System::Drawing::SystemColors::Control;
			chartArea25->Name = L"ChartArea1";
			this->chart_Model->ChartAreas->Add(chartArea25);
			legend2->Alignment = System::Drawing::StringAlignment::Center;
			legend2->Name = L"Legend1";
			this->chart_Model->Legends->Add(legend2);
			this->chart_Model->Location = System::Drawing::Point(635, 485);
			this->chart_Model->Margin = System::Windows::Forms::Padding(1);
			this->chart_Model->Name = L"chart_Model";
			this->chart_Model->Palette = System::Windows::Forms::DataVisualization::Charting::ChartColorPalette::None;
			this->chart_Model->PaletteCustomColors = gcnew cli::array< System::Drawing::Color >(9) {
				System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
					static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255))), System::Drawing::Color::Lime,
					System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
					static_cast<System::Int32>(static_cast<System::Byte>(0))), System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
					static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(128))), System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)),
					static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192))), System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
					static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255))), System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
					static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192))), System::Drawing::Color::Green,
					System::Drawing::Color::Aqua
			};
			series25->BackGradientStyle = System::Windows::Forms::DataVisualization::Charting::GradientStyle::LeftRight;
			series25->BackSecondaryColor = System::Drawing::Color::White;
			series25->BorderColor = System::Drawing::Color::Black;
			series25->ChartArea = L"ChartArea1";
			series25->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Pie;
			series25->Color = System::Drawing::Color::Chartreuse;
			series25->CustomProperties = L"PieLabelStyle=Outside";
			series25->IsValueShownAsLabel = true;
			series25->Legend = L"Legend1";
			series25->LegendText = L"#VALX";
			series25->MarkerBorderColor = System::Drawing::Color::BlueViolet;
			series25->MarkerColor = System::Drawing::Color::Blue;
			series25->MarkerSize = 10;
			series25->MarkerStyle = System::Windows::Forms::DataVisualization::Charting::MarkerStyle::Diamond;
			series25->Name = L"CallByModel";
			this->chart_Model->Series->Add(series25);
			this->chart_Model->Size = System::Drawing::Size(441, 240);
			this->chart_Model->TabIndex = 28;
			this->chart_Model->Text = L"chart1";
			title25->Font = (gcnew System::Drawing::Font(L"Droid Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			title25->Name = L"Title1";
			title25->Text = L"test title";
			this->chart_Model->Titles->Add(title25);
			// 
			// aTempForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1267, 787);
			this->Controls->Add(this->tableLayoutPanel_BG);
			this->Name = L"aTempForm";
			this->Text = L"aTempForm";
			this->tableLayoutPanel_BG->ResumeLayout(false);
			this->tableLayoutPanel_Menu->ResumeLayout(false);
			this->flowLayoutPanel_MenuUp->ResumeLayout(false);
			this->flowLayoutPanel_MenuDown->ResumeLayout(false);
			this->flowLayoutPanel_MenuDown->PerformLayout();
			this->tableLayoutPanel_content->ResumeLayout(false);
			this->panel_title->ResumeLayout(false);
			this->panel_title->PerformLayout();
			this->flowLayoutPanel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart_Parts))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart_Channel))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart_Efficiency))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart_OSC_Dealer_T10))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart_ErrCode))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart_Model))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
