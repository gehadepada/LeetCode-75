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
     void dfs(TreeNode*root ,vector<int>&r)
     {
        if(root==NULL)
        {
            return;
        }
        if(root->left == NULL && root->right == NULL)
        {
            r.push_back(root->val);
            return ;
        }
       
            dfs(root->left,r);
            dfs(root->right,r);
        


     }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
       vector<int>r,rr;
       dfs(root1,r);
       dfs(root2,rr);
       return r==rr;
        
    }
};