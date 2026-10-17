/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    void inorder(Node *root,vector<int>&in){
        if(root == NULL) return;
        
        inorder(root->left,in);
        in.push_back(root->data);
        inorder(root->right,in);
    }
    int inOrderSuccessor(Node *root, Node *k) {
        vector<int>in;
        inorder(root,in);
        for(int i = 0 ;i<in.size();i++){
            if(in[i] == k->data){
                if(i+1 < in.size()) return in[i+1];
                else{
                    return -1;
                }
            }
        }
        return -1;
    }
};