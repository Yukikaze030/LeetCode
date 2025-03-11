#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
using namespace std;

/*
你这个学期必须选修 numCourses 门课程，记为 0 到 numCourses - 1 。

在选修某些课程之前需要一些先修课程。 先修课程按数组 prerequisites 给出，其中 prerequisites[i] = [ai, bi] ，表示如果要学习课程 ai 则 必须 先学习课程  bi 。

例如，先修课程对 [0, 1] 表示：想要学习课程 0 ，你需要先完成课程 1 。
请你判断是否可能完成所有课程的学习？如果可以，返回 true ；否则，返回 false 。
*/

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        m_prerequisites.resize(prerequisites.size());
        m_over.resize(numCourses);
        for (int i = 0; i < prerequisites.size(); i++)
        {
            m_prerequisites[prerequisites[i][0]].resize(prerequisites[i].size());
            m_prerequisites[prerequisites[i][0]] = prerequisites[i];
        }

        return Finish(prerequisites[0][0], prerequisites[0]);
    }

    bool Finish(int num, vector<int> &prerequisites)
    {
        if (prerequisites.size() == 1)
        {
            m_over[num] = true;
            return true;
        }

        for (int i = 1; i < prerequisites.size(); i++)
        {
            if (m_over[prerequisites[i]] == true)
            {
                
            }
            else
            {
                bool t = Finish(m_over[prerequisites[i]], m_prerequisites[m_over[prerequisites[i]]]);
                if (t == false)
                {
                    return false;
                }
            }
        }

        m_over[num] = true;
        return true;
    }
    vector<vector<int>> m_prerequisites;
    vector<bool> m_over;
};

int main()
{
    Solution S;
    vector<vector<int>> a = {{0, 1}};
    auto t = S.canFinish(2, a);
}