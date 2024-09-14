#include "pch.h"
#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace std;

[STAThreadAttribute]
int main(cli::array<System::String^>^ args)  // Cambiar array por cli::array
{
    // Habilita los visual styles para que el formulario use los estilos actuales de Windows
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    // Crea y muestra la ventana principal
    MUI::MyForm form;
    Application::Run(% form);
    return 0;
}
