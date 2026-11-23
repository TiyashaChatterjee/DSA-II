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
    bool nodeToPath(TreeNode* root, vector<TreeNode*>&arr, TreeNode* p){
        if(!root){
            return false;
        }
        arr.push_back(root);
        if(root==p){
            return true;
        }
        if(nodeToPath(root->left,arr,p)||nodeToPath(root->right,arr,p)){
            return true;
        }
        arr.pop_back();
        return false;
    }
    vector<TreeNode*> result(TreeNode* root, TreeNode* p){
        vector<TreeNode*>arr;
        nodeToPath(root, arr, p);
        return arr;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>arr1;
        vector<TreeNode*>arr2;
        arr1=result(root, p);
        arr2=result(root, q);
        int i = 0;
        TreeNode* prev = nullptr;
        while(i<arr1.size() && i<arr2.size() && arr1[i]==arr2[i]){
            prev=arr1[i];
            i++;
        }
        return prev;
    }
};
