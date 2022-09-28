// 关卡类：实现关卡的配置

#ifndef __LEVEL__
#define __LEVEL__

#include "Player.cpp"
#include "Enemy.cpp"
#include "Collection.cpp"
#include <vector>
using namespace std;

struct PlayerInfo
{
    // 位置
    pair<int, int> pos;
    // 生命（剩余移动步数）
    int hp;
    // 单次移动距离
    int step;
    // 视野范围
    int sight;

    PlayerInfo(pair<int, int> pos, int hp, int step, int sight) :
        pos(pos), hp(hp), step(step), sight(sight) {}
    PlayerInfo() :
        pos({0, 0}), hp(10), step(1), sight(3) {}
};

// 关卡接口，派生关卡需实现内部方法
class ILevel
{
public:
    // 出口位置
    pair<int, int> exitPos;
    // 玩家信息
    PlayerInfo playerInfo;
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
protected:
    virtual void InitBasicData() override
    {
        exitPos = make_pair(1, 1);
    }

    virtual void AddEnemy() override
    {

    }

    virtual void AddCollection() override
    {

    }
};

class Level_1 : public ILevel
{
protected:
    virtual void InitBasicData() override
    {
        playerInfo = PlayerInfo({19, 0}, 10, 1, 3);
        exitPos = make_pair(1, 1);
    }

    virtual void AddEnemy() override
    {

    }

    virtual void AddCollection() override
    {

    }
};

#endif