// 关卡类：实现关卡的配置

#ifndef __LEVEL__
#define __LEVEL__

#include "Player.cpp"
#include "Enemy.cpp"
#include "Collection.cpp"
#include <vector>
using namespace std;

// 关卡信息，记录关卡的信息，以便于解析
struct LevelInfo
{
    // 出口位置
    pair<int, int> exitPos;
    // 玩家信息
    Player *player;
    // 敌人信息
    vector<IEnemy *> enemies;
    // 道具信息
    vector<ICollection *> collections;
};

// 关卡接口，派生关卡需实现内部方法
class ILevel
{
public:
    virtual LevelInfo GenerateInfo();

protected:
    // 设置关卡的基本信息（如玩家位置、出口位置等）
    virtual void InitBasicData();

    // 添加敌人
    virtual void AddEnemy();

    // 添加道具
    virtual void AddCollection();
};

class Level_0 : public ILevel
{
public:
    virtual LevelInfo GenerateInfo() override
    {
        return info;
    }

protected:
    virtual void InitBasicData() override
    {
        info.player = Player::GetInstance();
        info.exitPos = make_pair(19, 19);
    }

    virtual void AddEnemy() override
    {

    }

    virtual void AddCollection() override
    {

    }
    
private:
    LevelInfo info;
};

#endif