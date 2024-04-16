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
    TreeNode* nodeAdd(TreeNode* root, int val, int depth,int c){
        if(root == NULL){
            return NULL ;
        }
        if(c==depth-1){
            TreeNode* leftTemp = root->left;
            TreeNode* rightTemp = root->right;
             

            root->left = new TreeNode(val);
            root->right = new TreeNode(val);

            root->left->left = leftTemp;
            root->right->right = rightTemp;

            return root;

            
        }
        root->left = nodeAdd(root->left,val,depth,c+1);
        root->right = nodeAdd(root->right,val,depth,c+1);
        return root;
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        if(depth==1){

            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;

            return newRoot;
        }

        return nodeAdd(root,  val,  depth,1);

    }
};