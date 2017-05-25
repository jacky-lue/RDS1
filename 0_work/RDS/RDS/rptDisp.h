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
	/// Summary for rptDisp
	/// </summary>
	public ref class rptDisp : public System::Windows::Forms::Form
	{
	public:
		rptDisp(RDS_main_Form^ pForm)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			m_MainForm = pForm;
		}
		//caller Form
		RDS_main_Form^ m_MainForm;
		
		//for report display
		Bitmap^ iBMP;
		Graphics^ iG;
		Pen^  blackPen_w1;
		Pen^  grayPen_w1;
		SolidBrush^ blackSolidBrush;
		SolidBrush^ redSolidBrush;
		//SolidBrush^ blueSolidBrush;
		System::Drawing::Font^ titleFont;
		System::Drawing::Font^ titleFont2;
		System::Drawing::Font^ contentFont;
		StringFormat^ titleTextFormat;
		StringFormat^ titleTextFormat_L;
		StringFormat^ contentTextFormat;
		StringFormat^ contentTextFormat_R;
		StringFormat^ contentTextFormat_Wrap;

		//For read report.
		String^ readFilename;
		String^ UID;
		String^ RPT_date;
		String^ RPT_time;
		String^ spa_model_name;
		String^ spa_serial;
		String^ spa_owner;
		String^ cr_operatorName;
		String^ cur_WaterT;
		String^ set_T;
		String^ highLimitT;
		String^ PCB_T;
		String^ StartErr;
		String^ EndErr;
		String^ voltageMaxP;
		String^ voltageCurP;
		String^ voltageMinP;
		String^ HiLimit_Max;
		String^ HiLimit_Cur;
		String^ HiLimit_Min;
		String^ SpaTemp_Max;
		String^ SpaTemp_Cur;
		String^ SpaTemp_Min;
		String^ pcbTemp_Max;
		String^ pcbTemp_Cur;
		String^ pcbTemp_Min;
		String^ CR_comment;
		String^ replace_part;
		String^ M0_HC_state;
		String^ M0_C_state;
		String^ M0_state;
		String^ M1_state;
		String^ M2_state;
		String^ M3_state;
		String^ M4_state;
		String^ M5_state;
		String^ M6_state;
		String^ M7_state;
		unsigned int AD_CauseEquip_TotalCnt;
		String^ all_cause;
		String^ all_equip;


	private: System::Drawing::Printing::PrintDocument^  printDocument1;
	private: System::Windows::Forms::Button^  btn_prePage;
	private: System::Windows::Forms::Button^  button_nextPage;
	private: System::Windows::Forms::Label^  lbl_page_X;

	private: System::Windows::Forms::Label^  lbl_page_Y;
	private: System::Windows::Forms::Button^  btn_save;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;

	private: System::Windows::Forms::PrintDialog^  printDialog1;

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~rptDisp()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel_Bottom;
	private: System::Windows::Forms::Button^  btn_Print;



	private: System::Windows::Forms::PictureBox^  pictureBox1;
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
			this->flowLayoutPanel_Bottom = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->btn_Print = (gcnew System::Windows::Forms::Button());
			this->btn_save = (gcnew System::Windows::Forms::Button());
			this->btn_prePage = (gcnew System::Windows::Forms::Button());
			this->button_nextPage = (gcnew System::Windows::Forms::Button());
			this->lbl_page_X = (gcnew System::Windows::Forms::Label());
			this->lbl_page_Y = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->printDocument1 = (gcnew System::Drawing::Printing::PrintDocument());
			this->printDialog1 = (gcnew System::Windows::Forms::PrintDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->flowLayoutPanel_Bottom->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// flowLayoutPanel_Bottom
			// 
			this->flowLayoutPanel_Bottom->BackColor = System::Drawing::Color::SteelBlue;
			this->flowLayoutPanel_Bottom->Controls->Add(this->btn_Print);
			this->flowLayoutPanel_Bottom->Controls->Add(this->btn_save);
			this->flowLayoutPanel_Bottom->Controls->Add(this->btn_prePage);
			this->flowLayoutPanel_Bottom->Controls->Add(this->button_nextPage);
			this->flowLayoutPanel_Bottom->Controls->Add(this->lbl_page_X);
			this->flowLayoutPanel_Bottom->Controls->Add(this->lbl_page_Y);
			this->flowLayoutPanel_Bottom->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			this->flowLayoutPanel_Bottom->Location = System::Drawing::Point(2, 2);
			this->flowLayoutPanel_Bottom->Name = L"flowLayoutPanel_Bottom";
			this->flowLayoutPanel_Bottom->Size = System::Drawing::Size(76, 718);
			this->flowLayoutPanel_Bottom->TabIndex = 2;
			// 
			// btn_Print
			// 
			this->btn_Print->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_Print->Location = System::Drawing::Point(10, 10);
			this->btn_Print->Margin = System::Windows::Forms::Padding(10, 10, 10, 5);
			this->btn_Print->Name = L"btn_Print";
			this->btn_Print->Size = System::Drawing::Size(66, 55);
			this->btn_Print->TabIndex = 0;
			this->btn_Print->Text = L"Print";
			this->btn_Print->UseVisualStyleBackColor = true;
			this->btn_Print->Click += gcnew System::EventHandler(this, &rptDisp::btn_Print_Click);
			// 
			// btn_save
			// 
			this->btn_save->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_save->Location = System::Drawing::Point(10, 80);
			this->btn_save->Margin = System::Windows::Forms::Padding(10, 10, 10, 5);
			this->btn_save->Name = L"btn_save";
			this->btn_save->Size = System::Drawing::Size(66, 55);
			this->btn_save->TabIndex = 5;
			this->btn_save->Text = L"Save Image";
			this->btn_save->UseVisualStyleBackColor = true;
			this->btn_save->Click += gcnew System::EventHandler(this, &rptDisp::btn_save_Click);
			// 
			// btn_prePage
			// 
			this->btn_prePage->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_prePage->Location = System::Drawing::Point(10, 150);
			this->btn_prePage->Margin = System::Windows::Forms::Padding(10, 10, 10, 5);
			this->btn_prePage->Name = L"btn_prePage";
			this->btn_prePage->Size = System::Drawing::Size(56, 52);
			this->btn_prePage->TabIndex = 1;
			this->btn_prePage->Text = L"Pre Page";
			this->btn_prePage->UseVisualStyleBackColor = true;
			this->btn_prePage->Visible = false;
			this->btn_prePage->Click += gcnew System::EventHandler(this, &rptDisp::btn_prePage_Click);
			// 
			// button_nextPage
			// 
			this->button_nextPage->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_nextPage->Location = System::Drawing::Point(10, 217);
			this->button_nextPage->Margin = System::Windows::Forms::Padding(10, 10, 10, 5);
			this->button_nextPage->Name = L"button_nextPage";
			this->button_nextPage->Size = System::Drawing::Size(56, 52);
			this->button_nextPage->TabIndex = 2;
			this->button_nextPage->Text = L"NextPage";
			this->button_nextPage->UseVisualStyleBackColor = true;
			this->button_nextPage->Visible = false;
			this->button_nextPage->Click += gcnew System::EventHandler(this, &rptDisp::button_nextPage_Click);
			// 
			// lbl_page_X
			// 
			this->lbl_page_X->AutoSize = true;
			this->lbl_page_X->Location = System::Drawing::Point(3, 274);
			this->lbl_page_X->Name = L"lbl_page_X";
			this->lbl_page_X->Size = System::Drawing::Size(38, 12);
			this->lbl_page_X->TabIndex = 3;
			this->lbl_page_X->Text = L"PageX ";
			this->lbl_page_X->Visible = false;
			this->lbl_page_X->Click += gcnew System::EventHandler(this, &rptDisp::lbl_page_X_Click);
			// 
			// lbl_page_Y
			// 
			this->lbl_page_Y->AutoSize = true;
			this->lbl_page_Y->Location = System::Drawing::Point(3, 286);
			this->lbl_page_Y->Name = L"lbl_page_Y";
			this->lbl_page_Y->Size = System::Drawing::Size(35, 12);
			this->lbl_page_Y->TabIndex = 4;
			this->lbl_page_Y->Text = L"PageY";
			this->lbl_page_Y->Visible = false;
			this->lbl_page_Y->Click += gcnew System::EventHandler(this, &rptDisp::lbl_page_Y_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(85, 3);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(800, 700);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// printDocument1
			// 
			this->printDocument1->PrintPage += gcnew System::Drawing::Printing::PrintPageEventHandler(this, &rptDisp::printDocument1_PrintPage);
			// 
			// printDialog1
			// 
			this->printDialog1->UseEXDialog = true;
			// 
			// rptDisp
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->BackColor = System::Drawing::Color::SteelBlue;
			this->ClientSize = System::Drawing::Size(901, 782);
			this->Controls->Add(this->flowLayoutPanel_Bottom);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"rptDisp";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"RDS report";
			this->TopMost = true;
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &rptDisp::rptDisp_FormClosed);
			this->Load += gcnew System::EventHandler(this, &rptDisp::rptDisp_Load);
			this->flowLayoutPanel_Bottom->ResumeLayout(false);
			this->flowLayoutPanel_Bottom->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private:
	void RPT_read(String^ fullfilename);
	void DrawRreportPage();
	void ShowBasicInfo();
	void ShowErrCause();
	void ShowEquipments();
	void ShowBasicLog();
	void ShowAutoDiagResult();
	void ShowTechBack();
	//
	String^ parse_M0_HC(String^ InStr);
	String^ parse_M0_C(String^ InStr);
	String^ parse_M0(String^ InStr);
	String^ parse_M1(String^ InStr);
	String^ parse_M2(String^ InStr);
	String^ parse_M3(String^ InStr);
	String^ parse_M4(String^ InStr);
	String^ parse_M5(String^ InStr);
	String^ parse_M6(String^ InStr);
	String^ parse_M7(String^ InStr);
	//
	void rTitleText(float X, float Y, float WD, String^ strText, Boolean hasBorder);
	void rTitle2Text(float X, float Y, float WD, String^ strText, Boolean hasBorder);
	void rTitle2TextL(float X, float Y, float WD, String^ strText, Boolean hasBorder);
	void blackContentText(float X, float Y, float WD, String^ strText, Boolean hasBorder);
	void blackContentTxtR(float X, float Y, float WD, String^ strText, Boolean hasBorder);
	void blackContentTxtWrap(float X, float Y, float WD, String^ strText, Boolean hasBorder);
	void redContentText(float X, float Y, float WD, String^ strText, Boolean hasBorder);
	void rSplitLine(float X, float Y, float WD);

private: System::Void rptDisp_Load(System::Object^  sender, System::EventArgs^  e);
private: System::Void printDocument1_PrintPage(System::Object^  sender, System::Drawing::Printing::PrintPageEventArgs^  e);
private: System::Void btn_Print_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void btn_save_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void btn_prePage_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void button_nextPage_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void lbl_page_X_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void lbl_page_Y_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void rptDisp_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e);
};
}
