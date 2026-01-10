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

    long long res=0, totSum=0;
    int MOD=1e9+7;
 
    long long sumi(TreeNode* root){
        if(!root)return 0;

        return root->val + sumi(root->left)+sumi(root->right);
    }

    long long dfs(TreeNode* root){
        if(!root)return 0;

        long long left = dfs(root->left);
        long long right = dfs(root->right);

        long long subtreeSum = root->val + left + right;

        res = max(res, (subtreeSum*(totSum-subtreeSum)));

        return subtreeSum;
        
    }

    int maxProduct(TreeNode* root) {
        totSum = sumi(root);
        dfs(root);
        return (int)(res%MOD);
    }
};