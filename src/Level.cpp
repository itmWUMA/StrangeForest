// 关卡类：实现关卡的配置

#ifndef __LEVEL__
#define __LEVEL__

#include "Collection.cpp"
#include "Info.cpp"
#include "Player.cpp"
#include "Enemy.cpp"
#include <vector>
using namespace std;

// 关卡接口，派生关卡需实现内部方法
class ILevel
{
public:
    // 出口位置
    pair<int, int> exitPos;
    // 玩家信息
    PlayerInfo playerInfo;
    // 敌人信息
    vector<EnemyInfo*> enemyInfoList;
    // 道具信息
    vector<ICollection *> collectionList;

    // 合成关卡
    void ComposeLevel()
    {
        InitBasicData();
        AddEnemy();
        AddCollection();
    }

    virtual ~ILevel() 
    {
        // 释放敌人信息
        for (EnemyInfo* info : enemyInfoList)
            delete info;

        // 释放道具
        for (ICollection* collection : collectionList)
            delete collection;
    }

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
        playerInfo = PlayerInfo({0, 0}, 20, 1, 3);
        exitPos = make_pair(1, 5);
    }

    virtual void AddEnemy() override
    {
        enemyInfoList.push_back(new NormalEnemyInfo(make_pair(3, 3)));
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
        playerInfo = PlayerInfo({19, 0}, 25, 1, 3);
        exitPos = make_pair(1, 1);
    }

    virtual void AddEnemy() override
    {
        enemyInfoList.push_back(new NormalEnemyInfo(make_pair(6, 2)));
        enemyInfoList.push_back(new NormalEnemyInfo(make_pair(18, 4)));
        enemyInfoList.push_back(new NormalEnemyInfo(make_pair(0, 6)));
    }

    virtual void AddCollection() override
    {

    }
};

#endif