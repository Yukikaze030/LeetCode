#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        for (int Y = 0; Y < grid.size(); Y++)
        {
            for (int X = 0; X < grid[Y].size(); X++)
            {
                if (grid[Y][X] == 2)
                {
                    Rotting(grid, X, Y, 0);
                }
            }
        }

        int min = -1;
        for (int Y = 0; Y < grid.size(); Y++)
        {
            for (int X = 0; X < grid[Y].size(); X++)
            {
                if (grid[Y][X] == 1)
                {
                    return -1;
                }
                else if (grid[Y][X] >= 2)
                {
                    min = max(min, grid[Y][X]);
                }
            }
        }
        if (min == -1)
        {
            return 0;
        }
        return min - 2;
    }

    void Rotting(vector<vector<int>> &grid, int X, int Y, int Time)
    {
        if (grid[Y][X] == 0)
        {
            return;
        }
        else if (grid[Y][X] > 2)
        {
            if (grid[Y][X] - Time > 2)
            {
                grid[Y][X] = Time + 2;
            }
            else
            {
                return;
            }
        }
        else if (grid[Y][X] == 1)
        {
            grid[Y][X] = Time + 2;
        }
        else if (grid[Y][X] == 2 && Time != 0)
        { 
            return;
        }

        if (X > 0)
        {
            Rotting(grid, X - 1, Y, Time + 1);
        }

        if (X + 1 < grid[Y].size())
        {
            Rotting(grid, X + 1, Y, Time + 1);
        }

        if (Y > 0)
        {
            Rotting(grid, X, Y - 1, Time + 1);
        }

        if (Y + 1 < grid.size())
        {
            Rotting(grid, X, Y + 1, Time + 1);
        }
    }
};

int main()
{
    Solution S;
    //[[2,1,1],[1,1,0],[0,1,1]]
    vector<vector<int>> v = {{0, 2, 2}};
    int a = S.orangesRotting(v);
}  