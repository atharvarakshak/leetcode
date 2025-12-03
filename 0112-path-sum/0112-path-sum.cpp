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
    bool pathSum(TreeNode* root, int targetSum, int cur){
        if(!root) return false;
        cur+=root->val;
        if(root->left==NULL && root->right==NULL)return cur==targetSum;

        return pathSum(root->left,targetSum,cur) || pathSum(root->right,targetSum,cur);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        return pathSum(root,targetSum,0);
    }
};