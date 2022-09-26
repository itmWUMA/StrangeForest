// 地图类：实现地图的显示，以及游戏数据信息的存储

#ifndef __MAP__
#define __MAP__

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

    // 打印地图
    void PrintMap()
    {
        int row = grid.size(), col = grid[0].size();
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
                cout << grid[i][j] << ' ';
            cout << endl;
        }
    }

private:
    vector<vector<char>> grid;
};

#endif