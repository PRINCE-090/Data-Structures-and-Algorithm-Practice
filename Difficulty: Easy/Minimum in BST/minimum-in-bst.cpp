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
    int minValue(Node* root) {
        if(root == NULL) return -1;
        int minval = root->data;
       while(root->left != nullptr){
           minval = root->left->data;
           root= root->left;
       }
        return minval;
    }
};