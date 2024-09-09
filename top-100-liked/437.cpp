/**
 * Definition for a binary tree node.
 */
#include <vector>
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
    int pathSum(TreeNode *root, int targetSum)
    {
        return pathSum1(root, targetSum);
    }

    int pathSum1(TreeNode *root, long long targetSum)
    {
        if (is)
        {
            aa = targetSum;
            is = false;
        }
        if (root == nullptr)
        {
            return 0;
        }
        if (targetSum - root->val == 0)
        {
            bb++;
        }
        pathSum1(root->left, targetSum - root->val);
        pathSum1(root->right, targetSum - root->val);
        if (root->left != nullptr)
        {
            auto it = find(v.begin(), v.end(), (void *)root->left);
            if (it == v.end())
            {
                pathSum1(root->left, aa);
                v.push_back(root->left);
            }
        }

        if (root->right != nullptr)
        {
            auto it = find(v.begin(), v.end(), (void *)root->right);
            if (it == v.end())
            {
                pathSum1(root->right, aa);
                v.push_back(root->right);
            }
        }
        return bb;
    }
    int bb = 0;
    bool is = true;
    int aa = 0;
    std::vector<void *> v;
};

int main()
{
    //[10,5,-3,3,2,null,11,3,-2,null,1]
    // TreeNode S1(3);
    // TreeNode S2(-2);
    // TreeNode S3(1);
    // TreeNode S4(11);

    // TreeNode S5(3, &S1, &S2);
    // TreeNode S6(2, nullptr, &S3);
    // TreeNode S7(11);

    // TreeNode S8(5, &S5, &S6);
    // TreeNode S9(-3, nullptr, &S7);

    // TreeNode S10(10, &S8, &S9);
    //[1,null,2,null,3,null,4,null,5]

    TreeNode S1(5);
    TreeNode S2(4, nullptr, &S1);
    TreeNode S3(3, nullptr, &S2);
    TreeNode S4(2, nullptr, &S3);
    TreeNode S5(1, nullptr, &S4);
    // TreeNode S4(4, nullptr, &S1);

    Solution S;
    auto a = S.pathSum(&S5, 3);
}
