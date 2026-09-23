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
    int findDiameter(TreeNode *root,int &diameter){
        if(root == NULL) return 0;

        int leftheight = findDiameter(root->left,diameter);
        int rightheight = findDiameter(root->right,diameter);

        diameter = max(diameter, leftheight + rightheight);
        return 1 + max(leftheight,rightheight);

    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
     findDiameter(root,diameter);
      return diameter;
    }
};