/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int dfs(TreeNode* root, long long targetSum, long long sum) {
        if (!root) {
            return 0;
        }

        sum += root->val;
       int count =0;
        if (sum == targetSum) {
            count++;
        }
        count+= dfs(root->right, targetSum, sum) ;
               count+=dfs(root->left, targetSum, sum);
               return count;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if (!root)
            return 0;

        return dfs(root, targetSum, 0) + pathSum(root->left, targetSum) +
               pathSum(root->right, targetSum);
    }
};