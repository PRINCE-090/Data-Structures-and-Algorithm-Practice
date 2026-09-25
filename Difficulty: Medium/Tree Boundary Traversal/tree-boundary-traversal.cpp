/* Node Structure
class Node {
  public:
    int data;
    Node* left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    bool isleaf(Node*root){
        return root->left == NULL && root->right == NULL;
    }
    void leftboundary(Node *root,vector<int>&res){
        if(root == NULL || isleaf(root)) return;
        
        res.push_back(root->data);
        if(root->left) leftboundary(root->left,res);
        else if(root->right){
            leftboundary(root->right,res);
        }
        
    }
     void leafnodes( Node *root,vector<int>&res){
         if(root == NULL) return;
         if(isleaf(root)) res.push_back(root->data);
         
         if(root->left) leafnodes(root->left,res);
         if(root->right)leafnodes(root->right,res);
     }
     void rightboundary(Node *root,vector<int>&res){
         if(root == NULL || isleaf(root)) return;
         
         if(root->right) rightboundary(root->right,res);
         else if (root->left){
             rightboundary(root->left,res);
         }
         res.push_back(root->data);
     }
    vector<int> boundaryTraversal(Node *root) {
        vector<int>res;
        if(root == NULL) return res;
        if(isleaf(root) == false){
            res.push_back(root->data);
        }
        leftboundary(root->left,res);
        leafnodes(root,res);
        rightboundary(root->right,res);
        return res;
    }
};