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
    int maxHeight(TreeNode* root){
        if(root==nullptr){
            return 0;
        }
        return 1+max(maxHeight(root->right), maxHeight(root->left));
    }
    bool isBalanced(TreeNode* root) {
        if(root==nullptr){
            return true;
        }
        int res1=maxHeight(root->left);
        int res2=maxHeight(root->right);
        if(abs(res1-res2)>1){
            return false;
        }
            return isBalanced(root->left) && isBalanced(root->right);
    }
};
