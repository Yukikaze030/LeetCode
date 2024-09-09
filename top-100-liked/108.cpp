/*
  Definition for a binary tree node.
*/
#include <vector>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        if (nums.size() == 0)
        {
            return nullptr;
        }
        TreeNode *p = new TreeNode(nums[nums.size() / 2]);
        if (nums.size() == 1)
        {
            return p;
        }

        auto it_begin = nums.begin();
        vector<int> v_L(it_begin, it_begin + nums.size() / 2);
        p->left = sortedArrayToBST(v_L);

        if (it_begin + nums.size() / 2 + 1 == nums.end())
        {
            return p;
        }
        vector<int> v_R(it_begin + nums.size() / 2 + 1, nums.end());
        p->right = sortedArrayToBST(v_R);
        return p;
    }
};

int main()
{
    vector<int> v{-10, -3, 0, 5, 9};
    Solution S;
    S.sortedArrayToBST(v);
}
