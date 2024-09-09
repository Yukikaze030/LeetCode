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
    void flatten(TreeNode *root)
    {
        auto temp = root;
        Flatten(root);

        while (temp != nullptr)
        {
            if (temp->left != nullptr)
            {
                temp->right = temp->left;
                temp->left = nullptr;
            }
            temp = temp->right;
        }
    }

    void Flatten(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        end = root;
        Flatten(root->left);
        auto temp = end;
        Flatten(root->right);
        temp->right = root->right;
        if (root != temp)
        {
            root->right = nullptr;
        }
    }
    TreeNode *end = nullptr;
};

int main()
{
    Solution S;

    TreeNode s3(3);
    TreeNode s4(4);
    TreeNode s6(6);

    TreeNode s2(2, &s3, &s4);
    TreeNode s5(5, nullptr, &s6);

    TreeNode s1(1, &s2, &s5);

    S.flatten(&s1);
}