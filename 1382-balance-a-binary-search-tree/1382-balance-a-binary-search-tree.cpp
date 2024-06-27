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
    void inOrderTraversal(TreeNode* node,vector<int>& sortedElements){
        if(node==NULL){
            return ;
        }
        inOrderTraversal(node->left,sortedElements);
        sortedElements.push_back(node->val);
        inOrderTraversal(node->right,sortedElements);


    } 
    TreeNode* buildBalance(int s,int e,vector<int>& sortedElements){
        if(s>e){
            return nullptr;
        }
        int m = s + (e-s)/2;
        TreeNode* node = new TreeNode(sortedElements[m]);
        node->left = buildBalance(s,m-1,sortedElements);
        node->right = buildBalance(m+1,e,sortedElements);
        return node;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> sortedElements;
        inOrderTraversal(root,sortedElements);
        return buildBalance(0,sortedElements.size()-1,sortedElements);

    }
};