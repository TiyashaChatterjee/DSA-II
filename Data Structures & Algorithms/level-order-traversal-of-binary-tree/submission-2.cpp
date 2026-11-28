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
    vector<vector<int>>ans;
    void level2(TreeNode* root, int depth){
        if(!root){
            return;
        }
        if(ans.size()==depth){
            ans.push_back(vector<int>());
        }
        ans[depth].push_back(root->val);
        level2(root->left, depth+1);
        level2(root->right, depth+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        level2(root, 0);
        return ans;
    }
};
