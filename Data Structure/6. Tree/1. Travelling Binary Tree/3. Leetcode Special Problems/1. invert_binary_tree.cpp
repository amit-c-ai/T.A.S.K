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
    void invert(TreeNode* root){
        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
    
    void travel(TreeNode* root){
        if(root==NULL){
            return;
        }
        travel(root->left);
        travel(root->right);
        if(root->left || root->right){
            invert(root);
        }
    }
    
    TreeNode* invertTree(TreeNode* root) {
        travel(root);
        return root;
    }
};
