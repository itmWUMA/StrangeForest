// 控制类：用于UI显示以及游戏核心逻辑控制

#ifndef __CONTROLLER__
#define __CONTROLLER__

#include "Map.cpp"
#include "Level.cpp"
#include <iostream>
#include <vector>
#include <Windows.h>
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
      system("cls");
      cout << "            Strange Forest" << endl;
      cout << "=======================================" << endl;

      // 打印地图
      map.PrintMap();

      cout << "=======================================" << endl;

      // 打印提示信息
      PrintMessage();
   }

   // 获取用户输入
   int GetInput()
   {
      int ipt = 0;
      cin >> ipt;
      return ipt;
   }

   // 释放单例
   void DeleteInstance()
   {
      delete instance;
      instance = nullptr;
   }

   // 开始关卡
   void StartLevel()
   {
      // 加载关卡
      

      // 打印场景


      // 获取输入


      // 执行当前回合


      // 结果判断

      
      // 关卡变化
   }

   // 结束游戏
   void EndGame()
   {
      system("cls");
      cout << "************ GOODBYE ************" << endl;
      cout << "                design by itmWuma" << endl;
   }

private:
   // 单例
   static Controller *instance;
   // 游戏地图
   Map map;
   // 游戏关卡
   vector<ILevel*> levelList;
   // 当前关卡
   int curLevelIndex;
   // 当前状态
   enum Status
   {
      GAMEING,    // 游戏中
      UNSTART,    // 未开始 
      PASS,       // 通关
      FINISH,     // 结束
   };
   Status status;

   Controller() : curLevelIndex(0), status(UNSTART)
   {
      // 创建关卡
      levelList.push_back(GenerateLevel(new Level_0));
   }

   Controller(const Controller &) {}

   // 创建关卡
   ILevel* GenerateLevel(ILevel* &&level) 
   {
      level->ComposeLevel();  // 合成关卡
      return level;
   }

   // 加载关卡
   void LoadLevel()
   {
      auto curLevel = levelList[curLevelIndex];
   }

   // 执行当前回合
   void DoProcess(int ipt)
   {

   }

   // 打印提示信息
   inline void PrintMessage()
   {
      switch (status)
      {
      case GAMEING:
         cout << "      Your time is limited\n   escape as quick as possible!" << endl;
         cout << "          [Rest Step : " << levelList[curLevelIndex]->player->hp << "]\n";
         break;

      case UNSTART:
         cout << "         [1] Start    [0] End" << endl;
         break;

      case PASS:
         cout << "         [1] Continue    [0] End" << endl;
         break;

      case FINISH:
         cout << "         Congratulations, You Win！" << endl;
         break;

      default:
         break;
      }
      
   }
};
Controller *Controller::instance = nullptr;

#endif // !__CONTROLLER__