// 地图类：实现地图的显示，以及游戏数据信息的存储

#ifndef __MAP__
#define __MAP__

#include "Player.cpp"
#include <vector>
#include <iostream>
using namespace std;

class Map
{
public:
    Map(int row = 20, int col = 20)
    {
        grid = vector<vector<char>>(row, vector<char>(col, ' '));
    }

    // 设置地图元素
    void SetValue(int x, int y, char val)
    {
        if (IsOutOfRange(x, y))
            return;
        grid[x][y] = val;
    }

    // 获取地图元素
    char GetValue(int x, int y)
    {
        if (IsOutOfRange(x, y))
            return 0;
        return grid[x][y];
    }

    // 判断是否越界
    inline bool IsOutOfRange(int x, int y)
    {
        return (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size());
    }

    // 打印游戏中地图
    void PrintGamingMap()
    {
        // 计算可见区域
        int row = grid.size(), col = grid[0].size();
        auto player = Player::GetInstance();
        auto playerPos = player->pos;
        int visibleLeft = playerPos.second - player->sight,
            visibleRight = playerPos.second + player->sight,
            visibleDown = playerPos.first + player->sight,
            visibleUp = playerPos.first - player->sight;

        // 打印地图
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                // 在可见区域
                if (i >= visibleUp && i <= visibleDown && j >= visibleLeft && j <= visibleRight)
                    cout << grid[i][j] << ' ';
                // 不在可见区域
                else
                    cout << FOG << ' ';
            }
            cout << endl;
        }
    }

    // 打印未开始地图
    void PrintUnstartMap()
    {
        int row = grid.size(), col = grid[0].size();
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                cout << FOG << ' ';
            }
            cout << endl;
        }
    }

private:
    vector<vector<char>> grid;

    // 迷雾标志
    const char FOG = '-';
};

#endif