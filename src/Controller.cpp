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
      LoadLevel();

      // 更改状态
      status = GAMEING;

      // 打印场景
      PrintUI();

      // 获取输入
      int ipt = GetInput();

      // 执行当前回合
      DoProcess(ipt);

      // 结果判断
      switch (status)
      {

      }
      
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
      FAIL,       // 失败
      FINISH,     // 结束
   };
   Status status;

   // 移动朝向
   enum Towards
   {
      UP = 1,
      DOWN,
      LEFT,
      RIGHT,
   };

   Controller() : curLevelIndex(0), status(UNSTART)
   {
      // 创建关卡
      levelList.push_back(GenerateLevel(new Level_0));
   }

   Controller(const Controller &) {}

   // 获取当前关卡
   inline ILevel* GetCurLevel() { return levelList[curLevelIndex]; }

   // 创建关卡
   ILevel* GenerateLevel(ILevel* &&level) 
   {
      level->ComposeLevel();  // 合成关卡
      return level;
   }

   // 加载关卡
   void LoadLevel()
   {
      // 读取当前关卡
      auto curLevel = levelList[curLevelIndex];

      // 初始化地图
      map.SetValue(curLevel->exitPos.first, curLevel->exitPos.second, 'E');
      map.SetValue(curLevel->player->pos.first, curLevel->player->pos.second, 'I');
   }

   // 执行当前回合
   void DoProcess(int ipt)
   {
      auto curLevel = GetCurLevel();
      auto player = curLevel->player;
      
      // 玩家移动控制
      Move(player->pos.first, player->pos.second, (Towards)ipt, player->step, player->SYMBOL);

      // 敌人移动控制
   }

   // 打印提示信息
   inline void PrintMessage()
   {
      switch (status)
      {
      case GAMEING:
         cout << "      Your time is limited\n   escape as quick as possible!" << endl;
         cout << "          [Rest Step : " << levelList[curLevelIndex]->player->hp << "]\n";
         cout << "  [1] Up   [2] Down  [3] Left  [4] Right" << endl;
         break;

      case UNSTART:
         cout << "         [1] Start    [0] End" << endl;
         break;

      case PASS:
         cout << "      You are SAFE now!" << endl;
         cout << "         [1] Continue    [0] End" << endl;
         break;

      case FAIL:
         cout << "      YOU FAIL!" << endl;
         cout << "         [1] Continue    [0] End" << endl;
         break;

      case FINISH:
         cout << "         Congratulations, You Win！" << endl;
         break;

      default:
         break;
      }
   }

   // 游戏对象移动
   void Move(int x, int y, Towards towards, int step, char symbol)
   {
      auto nextPos = GetNextPos_Unchecked(x, y, towards, step);
      if (!map.IsOutOfRange(nextPos.first, nextPos.second))
      {
         map.SetValue(x, y, ' ');
         map.SetValue(nextPos.first, nextPos.second, symbol);
      }
   }

   // 根据移动获取下一个位置（不进行位置合理性检查）
   pair<int, int> GetNextPos_Unchecked(int x, int y, Towards towards, int step)
   {
      auto nextPos = make_pair(x, y);
      switch (towards)
      {
      case UP:
         nextPos.first -= step;
         break;
      case DOWN:
         nextPos.first += step;
         break;
      case LEFT:
         nextPos.second -= step;
         break;
      case RIGHT:
         nextPos.second += step;
      default:
         break;
      }
      return nextPos;
   }
};
Controller *Controller::instance = nullptr;

#endif // !__CONTROLLER__