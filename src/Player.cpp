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

    Player(pair<int, int> pos = {0, 0}, int hp = 10) : pos(pos), hp(hp) {}
    Player(const Player& p) {}
};

#endif