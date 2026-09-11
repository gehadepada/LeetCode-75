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
     void bst(TreeNode * &root , int key)
     {
        if(root== nullptr)
        {
            return ;
        }
        if(root->val == key)
        {
            TreeNode* node=root;
            if(root->right){
            root = root->right;
            if(node->left){
            if(root->left){
                TreeNode* temp=root;
            while(temp->left)
            {
                temp=temp->left;

            }
             temp->left=node->left;
            }
            else{
                root->left=node->left;
            }
            }
           
            }
            else{
                root=root->left;
            }
             return;
        }
        bst(root->left , key);
        bst(root->right , key);
     }
    TreeNode* deleteNode(TreeNode* root, int key) {
        bst(root , key);
        return root;
        
    }
};