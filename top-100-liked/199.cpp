/**
 * Definition for a binary tree node.
 */
#include <vector>
#include <map>
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
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> temp;
        VoidrightSideView(root);

        for (auto it : m_map)
        {
            temp.push_back(it.second.back());
        }
        return temp;
    }

    void VoidrightSideView(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }

        idx++;
        VoidrightSideView(root->left);

        auto it = m_map.find(idx);
        if (it == m_map.end())
        {
            vector<int> temp;
            temp.push_back(root->val);
            m_map.insert(make_pair(idx, temp));
        }
        else
        {
            it->second.push_back(root->val);
        }

        VoidrightSideView(root->right);
        idx--;
    }
    map<int, vector<int>> m_map;
    int idx;
};