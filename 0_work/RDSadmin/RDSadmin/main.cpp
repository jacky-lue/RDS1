#include "login.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace RDSadmin;

void ExitWhenLastWindowClosed(Object^ sender, FormClosedEventArgs^ e)
{
    if(Application::OpenForms->Count==0){
        Application::Exit();
    }
    else Application::OpenForms[0]->FormClosed+=gcnew FormClosedEventHandler(ExitWhenLastWindowClosed);
}

[STAThreadAttribute]
int Main(array<System::String ^> ^args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    RDSadmin::login^ first=gcnew login();
    first->FormClosed+=gcnew FormClosedEventHandler(ExitWhenLastWindowClosed);
    first->Show();
    Application::Run();
    return 0;
}