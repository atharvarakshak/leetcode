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

    int treeSum(TreeNode* p,int cur){
        if(p == nullptr){
            return 0;
        }
        
            cur =cur*10 + p->val;
            
        if(p->left == NULL && p->right == NULL){
                return cur;
        }
            return treeSum(p->left,cur) +  treeSum(p->right,cur) ;
    }
    int sumNumbers(TreeNode* root) {
        
  

        return treeSum(root,0);
      
        
    }
};