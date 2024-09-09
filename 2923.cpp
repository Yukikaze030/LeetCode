#include <vector>

using namespace std;
class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int size = grid.size();
        int i = 0,j=0;
        
        auto it = grid.begin();
        auto it_it = (it+i)->begin();
        while(1)
        {
            if(j==size)
            {
                break;
            }
            if(*(it_it+j) == 0 && j!=i)
            {
                i = j;
                j = 0;
                it_it = 
            }
            else
            {
                j++;
            }
        }
        return i 
    }
};