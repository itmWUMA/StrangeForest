// 信息类，用于衔接关卡配置与游戏对象生成

#ifndef __INFO__
#define __INFO__

#include "Player.cpp"
#include "Enemy.cpp"
#include <utility>
using namespace std;

// 玩家信息
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

    PlayerInfo(pair<int, int> pos, int hp, int step, int sight) : pos(pos), hp(hp), step(step), sight(sight) {}
    PlayerInfo() : pos({0, 0}), hp(10), step(1), sight(3) {}

    // 转化为对象
    Player *Parse() const
    {
        Player *player = Player::GetInstance();
        player->hp = hp;
        player->pos = pos;
        player->sight = sight;
        player->step = step;
    }
};

// 敌人信息
struct EnemyInfo
{
    // 位置
    pair<int, int> pos;

    EnemyInfo(pair<int, int> pos) : pos(pos) {}
    EnemyInfo() : pos({0, 0}) {}

    // 转化为对象
    virtual IEnemy *Parse() const = 0;
};
struct NormalEnemyInfo : public EnemyInfo
{
    NormalEnemyInfo(pair<int ,int> pos) : EnemyInfo(pos) {}
    NormalEnemyInfo() : EnemyInfo() {}

    virtual IEnemy* Parse() const override
    {
        IEnemy* enemy = new NormalEnemy(pos);
        return enemy;
    }
};

#endif