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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr)
        {
            return nullptr;
        }

        auto p1 = lowestCommonAncestor(root->left, p, q);
        auto p2 = lowestCommonAncestor(root->right, p, q);

        bool IsFalse = false;
        if (root == p)
        {
            IsFalse = true;
        }
        if (root == q)
        {
            IsFalse = true;
        }

        if ((((void *)p1 || (void *)p2) != 0) && IsFalse)
        {
            if (isTrue)
            {
                Node = root;
                isTrue = false;
            }
            return Node;
        }
        else if (p1 != nullptr && p2 != nullptr)
        {
            if (isTrue)
            {
                Node = root;
                isTrue = false;
            }
            return Node;
        }
        else if (p1 != nullptr || p2 != nullptr)
        {
            if (!isTrue)
            {
                return Node;
            }
            return root;
        }

        if (root == p)
        {
            return p;
        }
        if (root == q)
        {
            return q;
        }

        return Node;
    }
    bool isTrue = true;
    TreeNode *Node = nullptr;
};

//[3,5,1,6,2,0,8,null,null,7,4]

int main()
{
    Solution S;
    TreeNode S1(6);
    TreeNode S2(7);
    TreeNode S3(4);
    TreeNode S4(0);
    TreeNode S5(8);

    TreeNode S6(2, &S2, &S3);

    TreeNode S7(5, &S1, &S6);
    TreeNode S8(1, &S4, &S5);

    TreeNode S9(3, &S7, &S8);

    auto p = S.lowestCommonAncestor(&S9, &S4, &S5);
}