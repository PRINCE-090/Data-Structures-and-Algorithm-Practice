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
     void traversal(TreeNode*root,vector<int>&inorder){
    if(root == nullptr) return;
      traversal(root->left,inorder);
      traversal(root->right,inorder);
      inorder.push_back(root->val);

   }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>postorder;
        traversal(root,postorder);
        return postorder;
    }
};