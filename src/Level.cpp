// 关卡类：实现关卡的配置

#ifndef __LEVEL__
#define __LEVEL__

#include "Player.cpp"
#include "Enemy.cpp"
#include "Collection.cpp"
#include <vector>
using namespace std;

// 关卡接口，派生关卡需实现内部方法
class ILevel
{
public:
    // 出口位置
    pair<int, int> exitPos;
    // 玩家信息
    Player *player;
    // 敌人信息
    vector<IEnemy *> enemyList;
    // 道具信息
    vector<ICollection *> collectionList;

    // 合成关卡
    void ComposeLevel()
    {
        InitBasicData();
        AddEnemy();
        AddCollection();
    }

    virtual ~ILevel() {}

protected:
    // 设置关卡的基本信息（如玩家位置、出口位置等）
    virtual void InitBasicData() = 0;

    // 添加敌人
    virtual void AddEnemy() = 0;

    // 添加道具
    virtual void AddCollection() = 0;
};

class Level_0 : public ILevel
{
public:
    ~Level_0()
    {
        delete player;
        player = nullptr;
    }

protected:
    virtual void InitBasicData() override
    {
        player = Player::GetInstance();
        exitPos = make_pair(19, 19);
    }

    virtual void AddEnemy() override
    {

    }

    virtual void AddCollection() override
    {

    }
};

#endif