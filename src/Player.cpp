// 玩家类：实现玩家相关的逻辑

#ifndef __PLAYER__
#define __PLAYER__

#include <utility>
using namespace std;

class Player
{
public:
    // 位置
    pair<int, int> pos;
    // 生命（剩余移动步数）
    int hp;
    // 单次移动距离
    int step;
    // 代表符号
    const char SYMBOL = 'I'; 

    static Player* GetInstance(pair<int, int> pos = {0, 0}, int hp = 10)
    {
        if (instance == nullptr)
            instance = new Player(pos, hp);
        return instance;
    }

private:
    static Player* instance;

    Player(pair<int, int> pos = {0, 0}, int hp = 10, int step = 1) : 
        pos(pos), hp(hp), step(step) {}
    Player(const Player& p) {}
};
Player* Player::instance = nullptr;

#endif