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
     bool isvalid(TreeNode * root,TreeNode *minnode,TreeNode *maxnode){
      if(root == nullptr) return true;
      if(minnode && minnode->val >= root->val){
        return false;
      }
      if(maxnode && maxnode->val <= root->val) return false;

     return isvalid(root->left,minnode,root) && isvalid(root->right,root,maxnode);
     }
    bool isValidBST(TreeNode* root) {
        return isvalid(root,nullptr,nullptr);
    }
};