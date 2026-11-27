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
    int cnt=0;

    int traversal(TreeNode* root, TreeNode* maxi){
        if(!root){
            return cnt;
        }
        if(maxi->val <= root->val){
            cnt++;
            maxi=root;
        }
        if(root->left!=NULL )  traversal(root->left, maxi);
        if(root->right!=NULL )  traversal(root->right, maxi);

        return cnt;
    }
    int goodNodes(TreeNode* root) {
        return traversal(root, root);
    }
};
