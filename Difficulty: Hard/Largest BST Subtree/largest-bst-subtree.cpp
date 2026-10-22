/* Structure of a Binary Search Tree node
class Node {
public:
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/
 class NodeValue{
     public:
     int maxNode,minNode,maxSize;
     
     NodeValue(int minNode,int maxNode,int maxSize){
         this->maxNode = maxNode;
         this->minNode = minNode;
         this->maxSize = maxSize;
     }
 };

class Solution {
    private:
    NodeValue checkbst(Node *root){
        if(!root) return{INT_MAX,INT_MIN,0};
        
        auto left = checkbst(root->left);
        auto right = checkbst(root->right);
        
        if(left.maxNode < root->data && root->data < right.minNode){
            return NodeValue{min(root->data,left.minNode),max(root->data,right.maxNode),
            left.maxSize + right.maxSize +1};
        }
        
        return NodeValue{INT_MIN,INT_MAX,max(left.maxSize,right.maxSize)};
    }
  public:
    
    int largestBst(Node *root) {
     return checkbst(root).maxSize;
        
    }
};