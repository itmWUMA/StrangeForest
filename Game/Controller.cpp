// 控制类，用于UI显示以及游戏核心逻辑控制

#ifndef __CONTROLLER__
#define __CONTROLLER__

#include <iostream>
using namespace std;

class Controller
{
public:
   static Controller *GetInstance()
   {
      if (instance == nullptr)
         instance = new Controller;
      return instance;
   }

   void PrintUI()
   {
      
   }

private:
   static Controller *instance;

   Controller() {}
   Controller(const Controller &) {}
};

#endif // !__CONTROLLER__

Controller *Controller::instance = nullptr;