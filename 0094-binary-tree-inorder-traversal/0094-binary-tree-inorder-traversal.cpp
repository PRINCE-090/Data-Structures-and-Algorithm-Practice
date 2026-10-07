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

// Recursive Approach 
class Solution {
public:
    void traversal(TreeNode*root,vector<int>&inorder){
    if(root == nullptr) return;
      traversal(root->left,inorder);
      inorder.push_back(root->val);
      traversal(root->right,inorder);

   }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>inorder;
        traversal(root,inorder);
        return inorder;
    }
};

// Morris Traversal
class Solution {
public:
   
    vector<int> inorderTraversal(TreeNode* root) {
       vector<int>inorder;
       TreeNode*curr = root;
       while(curr != NULL){
         if(curr->left == NULL){
            inorder.push_back(curr->val);
            curr = curr->right;
         }
         else{
            TreeNode *prev = curr->left;
            while(prev->right && prev->right != curr)
            prev = prev->right;

            if(prev->right == NULL){
                prev->right = curr;
                curr = curr->left;
            }
            else{
                prev->right = NULL;
                inorder.push_back(curr->val);
                curr = curr->right;
            }
         }
       }
       return inorder;
    }
};
