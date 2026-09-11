/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
int cnt= 0 ;
    void dfs(TreeNode*root , int value)
    {
        if(root==NULL)
        {
            return ;
        }
        if(value <= root->val)
        {
            cnt++;
        }
        value=max(value , root->val);
        dfs(root->left,value);
        dfs(root->right,value);
    }
    int goodNodes(TreeNode* root) {

        dfs(root , -1e5);
        return cnt;
    }
};