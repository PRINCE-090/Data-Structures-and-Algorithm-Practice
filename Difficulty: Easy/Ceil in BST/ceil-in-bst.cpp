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
    void find(Node *root,int &x,int &val){
        if(root == NULL) return ;
        if(root->data == x){
            val = x;
            return;
        }
        // if(x > root->data){
        //   return  find(root->right,x,val);
        // }
        if(root->data > x ){
            if(val == -1 || root->data < val){
              val = root->data;   
            }
           return find(root->left,x,val);
        }
        return  find(root->right,x,val);
        
    }
    int findCeil(Node* root, int x) {
        if(root == NULL) return -1;
        int val = -1;
        find(root,x,val);
        return val;
        
    }
};
