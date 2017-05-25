#include "DateTime_Form.h"

using namespace RDS;
using namespace System;

System::Void DateTime_Form::DateTime_Form_Load(System::Object^  sender, System::EventArgs^  e)
{
    this->cmbx_DT_year->Text=""+(time_year+2000);
    this->cmbx_DT_month->SelectedIndex=time_month-1;
    this->cmbx_DT_day->SelectedIndex=time_day-1;
    this->cmbx_DT_weekday->SelectedIndex=time_week-1;
    this->cmbx_DT_hour->SelectedIndex=time_hour;
    this->cmbx_DT_min->SelectedIndex=time_min;
}

System::Void DateTime_Form::button_Save_Click(System::Object^  sender, System::EventArgs^  e)
{
    //get value from UI
    time_year=Convert::ToInt32(this->cmbx_DT_year->Text, 10)-2000;
    time_month=this->cmbx_DT_month->SelectedIndex+1;
    time_day=this->cmbx_DT_day->SelectedIndex+1;
    time_week=getWeekDay(time_year, time_month, time_day)+1; //WiFi & RDS define 1=sun, 2=mon....7=sat
    time_hour=this->cmbx_DT_hour->SelectedIndex;
    time_min=this->cmbx_DT_min->SelectedIndex;
    //then,call main-from function (set DateTime)
    m_MainForm->set_DateTime(
        time_year,   //00~99 : 2000~2099
        time_month,  //1~12
        time_day,    //1~31
        time_week,   //1=sun, 2=mon....7=Sat
        time_hour,
        time_min);
    m_MainForm->enable_DateTime_btn();
    this->Close();
}

System::Void DateTime_Form::DateTime_Form_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e)
{
    m_MainForm->enable_DateTime_btn();
}

System::Void DateTime_Form::cmbx_DT_year_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
{
    unsigned int year;
    unsigned char month;
    unsigned char day;
    unsigned char week;
    year=Convert::ToInt32(this->cmbx_DT_year->Text, 10)-2000;
    month=this->cmbx_DT_month->SelectedIndex+1;
    day=this->cmbx_DT_day->SelectedIndex+1;
    week=getWeekDay(year, month, day);
    this->cmbx_DT_weekday->SelectedIndex=week;
}

System::Void DateTime_Form::cmbx_DT_month_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
{
    unsigned int year;
    unsigned char month;
    unsigned char day;
    unsigned char week;
    year=Convert::ToInt32(this->cmbx_DT_year->Text, 10)-2000;
    month=this->cmbx_DT_month->SelectedIndex+1;
    day=this->cmbx_DT_day->SelectedIndex+1;
    week=getWeekDay(year, month, day);
    this->cmbx_DT_weekday->SelectedIndex=week;
}

System::Void DateTime_Form::cmbx_DT_day_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
{
    unsigned int year;
    unsigned char month;
    unsigned char day;
    unsigned char week;
    year=Convert::ToInt32(this->cmbx_DT_year->Text, 10)-2000;
    month=this->cmbx_DT_month->SelectedIndex+1;
    day=this->cmbx_DT_day->SelectedIndex+1;
    week=getWeekDay(year, month, day);
    this->cmbx_DT_weekday->SelectedIndex=week;
}

int DateTime_Form::isLeapYear(unsigned int year)
{
    return (year%400==0)||((year%4==0)&&(year%100!=0));
}

unsigned char DateTime_Form::getWeekDay(
    unsigned int year,
    unsigned char month,
    unsigned char day
)
{
    int days[]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    days[1]+=isLeapYear(year);
    //====== How many days in this year
    int d, i;
    d=day;
    for(i=0; i<month-1; i++)
    {
        d+=days[i];
    }
    year--;
    d+=year+(year/4)-(year/100)+(year/400);
    d%=7;
    return d; //return 0~~6
}