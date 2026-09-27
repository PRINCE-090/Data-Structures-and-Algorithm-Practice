/* Structure of Binary Tree Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    void leftsideview(Node *root,int level,vector<int>&res){
        if(root == NULL) return ;
        if(res.size() == level) res.push_back(root->data);
        if(root->left) leftsideview(root->left,level+1,res);
        if(root->right) leftsideview(root->right,level+1,res);
    }
    vector<int> leftView(Node *root) {
       vector<int>res;
       if(root == NULL) return res;
       leftsideview(root,0,res);
       return res;
        
    }
};