#include "Controller.cpp"

#include <iostream>
using namespace std;

int main(int argn, char** args)
{
   Controller* controller = Controller::GetInstance();

   controller->PrintUI();

   return 0;
}