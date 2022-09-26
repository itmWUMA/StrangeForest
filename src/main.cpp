#include "Controller.cpp"

#include <iostream>
#include <Windows.h>
using namespace std;

int main(int argn, char** args)
{
   system("title Strange Forest");

   // 获取控制器单例
   Controller* ctrl = Controller::GetInstance();
   // 用户输入
   int ipt = 0;

   do
   {
      ctrl->PrintUI();
      ipt = ctrl->GetInput();
      
   } while (ipt);
   

   system("pause");
   return 0;
}