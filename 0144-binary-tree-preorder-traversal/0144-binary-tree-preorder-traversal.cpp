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

// REcursion 
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
      inorder.push_back(root->val);
      traversal(root->left,inorder);
      traversal(root->right,inorder);

   }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>inorder;
        traversal(root,inorder);
        return inorder;
    }
};

// Moris traversal
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
         vector<int>preorder;
       TreeNode*curr = root;
       while(curr != NULL){
         if(curr->left == NULL){
            preorder.push_back(curr->val);
            curr = curr->right;
         }
         else{
            TreeNode *prev = curr->left;
            while(prev->right && prev->right != curr)
            prev = prev->right;

            if(prev->right == NULL){
                prev->right = curr;
                preorder.push_back(curr->val);
                curr = curr->left;
            }
            else{
                prev->right = NULL;
                curr = curr->right;
            }
         }
       }
       return preorder;
    }
};
