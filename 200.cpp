#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    void Find_1_To_2(vector<vector<char>> &grid, int x, int y)
    {
        if (grid[y][x] == '1')
        {
            grid[y][x] = '2';
        }
        else
        {
            return;
        }

        if ((x + 1) < grid[y].size())
        {
            Find_1_To_2(grid, x + 1, y);
        }
        if (x > 0)
        {
            Find_1_To_2(grid, x - 1, y);
        }
        if (y > 0)
        {
            Find_1_To_2(grid, x, y - 1);
        }
        if ((y + 1) < grid.size())
        {
            Find_1_To_2(grid, x, y + 1);
        }
    }
    int numIslands(vector<vector<char>> &grid)
    {

        for (int y = 0; y < grid.size(); y++)
        {
            for (int x = 0; x < grid[y].size(); x++)
            {
                if (grid[y][x] == '1')
                {
                    r++;
                    Find_1_To_2(grid, x, y);
                }
            }
        }
        return r;
    }

    int r = 0;
};

int main()
{
    vector<vector<char>> date{{'1', '1', '1', '1', '0'}, {'1', '1', '0', '1', '0'}, {'1', '1', '0', '0', '0'}, {'0', '0', '0', '0', '0'}};
    Solution S;
    int a = S.numIslands(date);
}