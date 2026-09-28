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
    void findallpaths(TreeNode *root,vector<string>&ans,string s){
        if(root->left == NULL && root->right == NULL){
            ans.push_back(s + to_string(root->val));
            return;
        }
        string curr_path = s + to_string(root->val) + "->";
        if(root->left){
            findallpaths(root->left,ans,curr_path);
        }
        if(root->right){
            findallpaths(root->right,ans,curr_path);
        }
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        if(root == NULL) return ans;
        findallpaths(root,ans,"");
        return ans;
    }
};