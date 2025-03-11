#include <string>
using namespace std;

class Solution
{
public:
    string largestGoodInteger(string num)
    {
        if (num.size() < 3)
        {
            return "";
        }
        string a = "";
        while (num.size() > 3)
        {
            string temp = string(num.begin(), num.begin() + 3);
            if (temp[0] != temp[1] || temp[0] != temp[2] || temp[1] != temp[2])
            {
                continue; // return "";
            }
            else
            {
                if (temp > a)
                {
                    a = temp;
                }
                // return temp;
            }
        }
        return a;
    }
};

int main()
{
    Solution s;
    string a = s.largestGoodInteger("000111333222555");
}