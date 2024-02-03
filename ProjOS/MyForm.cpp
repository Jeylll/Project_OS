#include "MyForm.h"
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>

using namespace Project1;

[STAThreadAttribute]

int main() {

    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Project1::MyForm form;
    Application::Run(% form);

    return 0;
}

