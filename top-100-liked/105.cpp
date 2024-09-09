#include <vector>
#include <algorithm>
using namespace std;
/**
 * Definition for a binary tree node.
 *
 * 输入: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
 * 输出: [3,9,20,null,null,15,7]
 */
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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        if (preorder.empty())
        {
            return nullptr;
        }
        int RootVal = preorder.front();
        auto it = find(inorder.begin(), inorder.end(), RootVal);
        vector<int> temp_inorder_left(inorder.begin(), it);
        vector<int> temp_inorder_right(it + 1, inorder.end());
        vector<int> temp_preorder_left(preorder.begin() + 1, preorder.begin() + temp_inorder_left.size() + 1);
        vector<int> temp_preorder_right(preorder.begin() + temp_inorder_left.size() + 1, preorder.end());
        TreeNode *left = buildTree(temp_preorder_left, temp_inorder_left);
        TreeNode *right = buildTree(temp_preorder_right, temp_inorder_right);

        TreeNode *root = new TreeNode(RootVal, left, right);

        return root;
    }
};

int main()
{
    Solution S;
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    TreeNode *root = S.buildTree(preorder, inorder);
}