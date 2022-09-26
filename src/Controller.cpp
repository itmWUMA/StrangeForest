// 控制类：用于UI显示以及游戏核心逻辑控制

#ifndef __CONTROLLER__
#define __CONTROLLER__

#include "Map.cpp"
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
      cout << "            Strange Forest" << endl;
      cout << "=======================================" << endl;

      // 打印地图
      map.PrintMap();

      cout << "=======================================" << endl;

      // 打印玩家信息
      
   }

   // 获取用户输入
   int GetInput()
   {
      int ipt = 0;
      cin >> ipt;
      return ipt;
   }

private:
   // 单例
   static Controller *instance;
   // 游戏地图
   Map map;

   Controller()
   {
   }

   Controller(const Controller &) {}
};

#endif // !__CONTROLLER__

Controller *Controller::instance = nullptr;