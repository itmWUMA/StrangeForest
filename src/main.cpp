#include "Controller.cpp"

#include <iostream>
using namespace std;

int main(int argn, char** args)
{
   // 获取控制器单例
   Controller* ctrl = Controller::GetInstance();
   // 用户输入
   int ipt = 0;

   do
   {
      ctrl->PrintUI();
      ipt = ctrl->GetInput();
      
   } while (ipt);
   

   getchar();
   return 0;
}