/*
  Definition for a binary tree node.
*/
#include <vector>
#include <algorithm>
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
    int kthSmallest(TreeNode *root, int k)
    {
        return kthSmallest(root, k);
    }

    int kthSmallestK(TreeNode *root, int &k)
    {
         
    }
};

int main()
{
    TreeNode T3(3);
    TreeNode T7(7);
    TreeNode T4(4);
    TreeNode T6(6, &T3, &T7);
    TreeNode T5(5, &T4, &T6);

    // TreeNode T2(2, &T1, &T3);

    Solution s;
    // s.isValidBST(&T5);
}