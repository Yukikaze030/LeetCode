/*
一位老师正在出一场由 n 道判断题构成的考试，每道题的答案为 true （用 'T' 表示）或者 false （用 'F' 表示）。老师想增加学生对自己做出答案的不确定性，方法是 最大化 有 连续相同 结果的题数。（也就是连续出现 true 或者连续出现 false）。

给你一个字符串 answerKey ，其中 answerKey[i] 是第 i 个问题的正确结果。除此以外，还给你一个整数 k ，表示你能进行以下操作的最多次数：

每次操作中，将问题的正确答案改为 'T' 或者 'F' （也就是将 answerKey[i] 改为 'T' 或者 'F' ）。
请你返回在不超过 k 次操作的情况下，最大 连续 'T' 或者 'F' 的数目。


*/

#include <string>
#include <list>
using namespace std;
class Solution
{
public:
    int maxConsecutiveAnswers(string answerKey, int k)
    {
        int max = 0;
        int F_Start = 0;
        int F_End = 0;
        int T_Start = 0;
        int T_End = 0;
        int max_F = 0;
        int max_T = 0;
        int idx = 0;
        int len_F = 0, len_T = 0;
        int k_F = 0, k_T = 0;
        list<int> List_F_F, List_T_T;
        int F_F = 0, T_T = 0;
        while (answerKey[idx] != '\0')
        {
            F_Start++;
            T_Start++;
            if (answerKey[idx] == 'F')
            {
                F_F++;
                if (k_T < k)
                {

                    T_T++;
                    List_T_T.push_back(T_T);
                    T_T = 0;
                    k_T++;
                }
                else
                {
                    T_T++;
                    T_End = T_End + List_T_T.front();
                    List_T_T.push_back(T_T);
                    List_T_T.pop_front();
                    T_T = 0;
                }
            }
            else
            {
                T_T++;
                if (k_F < k)
                {
                    F_F++;
                    List_F_F.push_back(F_F);
                    F_F = 0;
                    k_F++;
                }
                else
                {

                    F_F++;
                    F_End = F_End + List_F_F.front();
                    List_F_F.push_back(F_F);
                    List_F_F.pop_front();
                    F_F = 0;
                }
            }
            idx++;
            len_F = F_Start - F_End;
            len_T = T_Start - T_End;
            if (max < len_F)
            {
                max = len_F;
            }
            if (max < len_T)
            {
                max = len_T;
            }
        }
        return max;
    }
};

int main()
{
    Solution S;
    int max = S.maxConsecutiveAnswers("FFTFTTTFFF", 1);
}