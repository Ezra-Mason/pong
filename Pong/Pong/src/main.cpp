#include "Application.h"
#include <iostream>

int main()
{
    Application* application = new Application();
    application->Run();
    delete application;
}
