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

// Using Recursion 
class Solution {
public:
    TreeNode *prev = NULL;
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        flatten(root->right);
        flatten(root->left);

        root->right = prev;
        root->left = NULL;
        prev = root;
    }
};

// Iterative Method 
void flatten(TreeNode* root) {
        if(root == NULL) return;
        stack<TreeNode*>st;
        st.push(root);
        while(!st.empty()){
            TreeNode*node = st.top();
            st.pop();

            if(node->right) st.push(node->right);
            if(node->left)  st.push(node->left);

            if(!st.empty()){
                node->right = st.top();
                node->left = NULL;
            } 
        }
    }
};



// Using Morris Traversal 
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        TreeNode *curr = root;
        while(curr != NULL){
            if(curr->left != NULL){
              TreeNode *prev = curr->left;
                while(prev->right != NULL) prev = prev->right;
                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
             curr = curr->right;
         }
    }
};
