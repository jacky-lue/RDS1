//project defines
#include "RDS_project.h"

//for VC program all forms
#include "RDS_main_Form.h"

//related objects
#include "IOTcommunicator.h"
#include "spa_cmd.h"
#include "SPA.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Threading;
// ----- my main..
using namespace RDS;

//The function body of class RDS_main_Form here -----------------------------------------------------------

//==============================//
//  Message show (Main Output)  //
//==============================//
System::Void RDS_main_Form::MsgMain(String^ InStr)
{
    DateTime dt=DateTime::Now;
    String^ CurDateTime=dt.ToString("HH:mm:ss", DateTimeFormatInfo::InvariantInfo);

    //this->richTextBox_main_output->Text += CurDateTime + "> " + InStr + Environment::NewLine;
    String^ newStr=CurDateTime+"> "+InStr+Environment::NewLine;
    this->richTextBox_main_output->AppendText(newStr);

    //Auto-scroll-to-end
    this->richTextBox_main_output->SelectionLength=0;
    this->richTextBox_main_output->SelectionStart=this->richTextBox_main_output->Text->Length;
    this->richTextBox_main_output->ScrollToCaret();
}

System::Void RDS_main_Form::MsgMain2(String^ InStr)
{
    //this->richTextBox_main_output->Text += InStr + Environment::NewLine;
    String^ newStr=InStr+Environment::NewLine;
    this->richTextBox_main_output->AppendText(newStr);

    //Auto-scroll-to-end
    this->richTextBox_main_output->SelectionLength=0;
    this->richTextBox_main_output->SelectionStart=this->richTextBox_main_output->Text->Length;
    this->richTextBox_main_output->ScrollToCaret();
}

System::Void RDS_main_Form::MsgMain2UL(String^ InStr)
{
    String^ newStr=InStr+Environment::NewLine;
    int start=this->richTextBox_main_output->Text->Length;
    int length=newStr->Length;
    this->richTextBox_main_output->AppendText(newStr);
    this->richTextBox_main_output->SelectionStart=start;
    this->richTextBox_main_output->SelectionLength=length;
    this->richTextBox_main_output->SelectionFont=gcnew System::Drawing::Font("Cambria", 12, FontStyle::Underline);
    //this->richTextBox_main_output->SelectionColor = textColor;

    //Auto-scroll-to-end
    this->richTextBox_main_output->SelectionLength=0;
    this->richTextBox_main_output->SelectionStart=this->richTextBox_main_output->Text->Length;
    this->richTextBox_main_output->ScrollToCaret();
}

System::Void RDS_main_Form::MsgMain3CS(String^ InStr, Color textColor)
{
    int start=this->richTextBox_main_output->Text->Length;
    int length=InStr->Length;
    this->richTextBox_main_output->AppendText(InStr);
    this->richTextBox_main_output->SelectionStart=start;
    this->richTextBox_main_output->SelectionLength=length;
    this->richTextBox_main_output->SelectionFont=gcnew System::Drawing::Font("Cambria", 12, FontStyle::Regular);
    this->richTextBox_main_output->SelectionColor=textColor;

    //Auto-scroll-to-end
    this->richTextBox_main_output->SelectionLength=0;
    this->richTextBox_main_output->SelectionStart=this->richTextBox_main_output->Text->Length;
    this->richTextBox_main_output->ScrollToCaret();
}

System::Void RDS_main_Form::MsgMain3FS(String^ InStr, FontStyle textFontStyle)
{
    int start=this->richTextBox_main_output->Text->Length;
    int length=InStr->Length;
    this->richTextBox_main_output->AppendText(InStr);
    this->richTextBox_main_output->SelectionStart=start;
    this->richTextBox_main_output->SelectionLength=length;
    this->richTextBox_main_output->SelectionFont=gcnew System::Drawing::Font("Cambria", 12, textFontStyle);
    //this->richTextBox_main_output->SelectionColor = textColor;

    //Auto-scroll-to-end
    this->richTextBox_main_output->SelectionLength=0;
    this->richTextBox_main_output->SelectionStart=this->richTextBox_main_output->Text->Length;
    this->richTextBox_main_output->ScrollToCaret();
}

//============================//
//  Message show (Eng Basic)  //
//============================//
System::Void RDS_main_Form::MsgEngr(String^ InStr)
{
    if(this->panel_EngArea->Visible==true)
    {
        this->richTextBox_EngMsg->Text+="> "+InStr+Environment::NewLine;
        //Auto-scroll-to-end
        this->richTextBox_EngMsg->SelectionLength=0;
        this->richTextBox_EngMsg->SelectionStart=this->richTextBox_EngMsg->Text->Length;
        this->richTextBox_EngMsg->ScrollToCaret();
    }
}

//=========================//
//  Message show IOT error //
//=========================//
System::Void RDS_main_Form::MsgEngr_IOT_error()
{
    MsgEngr("IOTC return code="
        +this->iCmd.iIOTctrl.return_Code
        +" : "
        +this->iCmd.iIOTctrl.getIOTerrString()
    );
}

//===============//
// Log message   //
//===============//
System::Void RDS_main_Form::MsgLog(String^ InStr)
{
    DateTime dt=DateTime::Now;
    String^ CurDateTime=dt.ToString("HH:mm:ss", DateTimeFormatInfo::InvariantInfo);
    this->richTextBox_ActLog->Text+=CurDateTime+"> "+InStr+Environment::NewLine;
    //Auto-scroll-to-end
    this->richTextBox_ActLog->SelectionLength=0;
    this->richTextBox_ActLog->SelectionStart=this->richTextBox_ActLog->Text->Length;
    this->richTextBox_ActLog->ScrollToCaret();
}