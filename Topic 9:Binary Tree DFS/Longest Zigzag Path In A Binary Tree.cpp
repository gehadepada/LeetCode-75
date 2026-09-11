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
    int mx = 0;
    void dfs(TreeNode*root , int isLeft , int cnt )
    {
         mx=max(mx , cnt);
        if(root == NULL)
        {
            return ;
        }
        if(isLeft)
        {
            dfs(root->right ,0 ,cnt+1 );
            dfs(root->left , 1,1);
        }
        else{
            dfs(root->left , 1,cnt+1 );
            dfs(root->right , 0 ,1);
        }
    }
    int longestZigZag(TreeNode* root) {
        dfs(root->left, 1,1);
        dfs(root->right , 0 ,1);
        return mx-1;

        
    }
};