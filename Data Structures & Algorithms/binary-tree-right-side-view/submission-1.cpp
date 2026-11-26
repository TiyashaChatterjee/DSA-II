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
    vector<int> ans;
    vector<int> right2(TreeNode* root,int level){
        if(!root){
            return {}; 
        }
        if(level==ans.size()){
            ans.push_back(root->val);
        }
        right2(root->right, level+1);
        right2(root->left, level+1);
        return ans;
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>res = right2(root, 0);
        
        return res;
    }
};
