#include <algorithm>
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
    int maxPathSum(TreeNode *root)
    {
        if (IsTrue)
        {
            Root = root;
            IsTrue = false;
        }
        if (root->left == nullptr && root->right == nullptr)
        {
            return root->val;
        }

        int L = root->val, R = root->val;

        if (root->left != nullptr)
        {
            L = maxPathSum(root->left);
        }
        if (root->right != nullptr)
        {
            R = maxPathSum(root->right);
        }

        int max = 0;
        int max1 = 0;
        if (root->left != nullptr && root->right != nullptr)
        {
            //
            max = std::max(L, R);
            max1 = max + root->val; // max1 return

            max = std::max(max, max1);
            max = std::max(max, L + R + root->val); // max2
            max = std::max(max, root->val);         // max2
            max1 = std::max(max1, root->val);
            max2 = std::max(max, max2);
        }
        else if (root->left == nullptr)
        {
            max = R;
            max1 = max + root->val; // max1 return

            max = std::max(max, max1);        // max2
            max1 = std::max(max1, root->val); // max2
            max2 = std::max(max, max2);
            // max = std::max(max, L + R + root->val); // max2
        }
        else if (root->right == nullptr)
        {
            max = L;
            max1 = max + root->val; // max1 return

            max = std::max(max, max1);        // max2
            max1 = std::max(max1, root->val); // max2
            max2 = std::max(max, max2);
            // max = std::max(max, L + R + root->val); // max2
        }
        if (root == Root)
        {
            return std::max(max1, max2);
        }
        return max1;
    }

    int max2 = 0x80000000;
    bool IsTrue = true;

    TreeNode *Root = nullptr;
};

int main()
{
    Solution S;

    TreeNode S1(-8);
    TreeNode S2(3, nullptr, &S1);
    TreeNode S3(-3, &S2, nullptr);
    TreeNode S4(0);
    TreeNode S5(9, &S3, &S4);

    auto a = S.maxPathSum(&S5);
}