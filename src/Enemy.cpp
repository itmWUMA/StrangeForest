// 敌人类：实现敌人相关的逻辑，同时为不同种类的敌人提供扩展

#ifndef __ENEMY__
#define __ENEMY__

class IEnemy
{
public:
    // 位置
    pair<int, int> pos;
    // 单次移动距离
    int step;

    IEnemy(const pair<int, int>& pos, int step) : pos(pos), step(step) {}

    // 移动策略
    virtual int MoveTowards() = 0;

    // 获取标识符
    virtual char GetSymbol() = 0;
};

// 普通敌人 
class NormalEnemy : public IEnemy
{
public:
    NormalEnemy(const pair<int, int>& pos) : IEnemy(pos, 1) {}

    virtual int MoveTowards() override 
    {
        return rand() % 4;
    }

    virtual char GetSymbol() override
    {
        return 'X';
    }
};

#endif