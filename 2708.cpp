/*
给你一个下标从 0 开始的整数数组 nums ，它表示一个班级中所有学生在一次考试中的成绩。老师想选出一部分同学组成一个 非空 小组，且这个小组的 实力值 最大，如果这个小组里的学生下标为 i0, i1, i2, ... , ik
那么这个小组的实力值定义为 nums[i0] * nums[i1] * nums[i2] * ... * nums[ik​] 。
请你返回老师创建的小组能得到的最大实力值为多少。
*/
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    long long maxStrength(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return nums[0];
        }

        sort(nums.begin(), nums.end());
        long long temp = 0;
        bool is_0 = true;
        int abs = 0;
        for (int idx = 0; idx < nums.size(); idx++)
        {
            if (nums[idx] == 0)
            {
                continue;
            }

            if (nums[idx] < 0 && abs % 2 == 1)
            {
                if (is_0)
                {
                    temp = 1;
                    is_0 = false;
                }
                temp = temp * nums[idx] * nums[idx - 1];
                abs = 0;
            }
            else if (nums[idx] < 0)
            {
                abs++;
            }
            if (nums[idx] > 0)
            {
                if (is_0)
                {
                    temp = 1;
                    is_0 = false;
                }
                temp = temp * nums[idx];
            }
        }
        return temp;
    }
};

int main()
{
    Solution s;

    vector<int> a = {0, -1};
    s.maxStrength(a);
}