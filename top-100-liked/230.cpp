/**
 * Definition for a binary tree node.
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
    int kthSmallest(TreeNode *root, int k)
    {
        kthSmallestk(root, k);
        return end;
    }

    void kthSmallestk(TreeNode *root, int &k)
    {
        if (root == nullptr)
        {
            return;
        }

        kthSmallestk(root->left, k);
        idx++;
        if (idx == k)
        {
            end = root->val;
        }
        kthSmallestk(root->right, k);
        return;
    }

    int idx = 0;
    int end = 0;
};