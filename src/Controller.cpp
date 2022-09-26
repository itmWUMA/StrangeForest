// 控制类：用于UI显示以及游戏核心逻辑控制

#ifndef __CONTROLLER__
#define __CONTROLLER__

#include <iostream>
using namespace std;

class Controller
{
public:

   // 获取单例
   static Controller *GetInstance()
   {
      if (instance == nullptr)
         instance = new Controller;
      return instance;
   }

   // 打印界面
   void PrintUI()
   {
      
   }

   // 获取用户输入
   int GetInput()
   {
      int ipt = 0;
      cin >> ipt;
      return ipt;
   }

private:
   static Controller *instance;

   Controller() {}
   Controller(const Controller &) {}
};

#endif // !__CONTROLLER__

Controller *Controller::instance = nullptr;