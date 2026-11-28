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
    bool BST(TreeNode* node, int left, int right){
        if(!node){
            return true;
        }
        if(!(left<node->val && node->val<right)){
            return false;
        }
        return BST(node->left, left, node->val ) && BST(node->right, node->val, right);
    }
    bool isValidBST(TreeNode* root) {
        return BST(root, INT_MIN, INT_MAX);
    }
};
