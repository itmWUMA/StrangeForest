#include "Controller.cpp"

#include <iostream>
#include <ctime>
#include <Windows.h>
using namespace std;

int main(int argn, char** args)
{
   system("title Strange Forest");

   // 随机化种子
   srand((unsigned int)time(NULL));

   // 获取控制器单例
   Controller* ctrl = Controller::GetInstance();
   // 用户输入
   int ipt = 0;

   // 界面交互
   do
   {
      ctrl->PrintUI();           // 打印界面
      
      ipt = ctrl->GetInput();    // 获取输入

      if (ipt == 1)              // 开始关卡
         ipt = ctrl->StartLevel();     
      else                       // 结束游戏
         ctrl->EndGame();
   } while (ipt);
   
   ctrl->FreeInstance();
   system("pause");
   return 0;
}