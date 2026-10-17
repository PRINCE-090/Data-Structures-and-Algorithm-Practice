class Solution {
  public:
    int inOrderSuccessor(Node *root, Node *k) {
         Node *curr = root;
         int successor = -1;
         while(curr){
             if(curr->data < k->data){
                 curr = curr->right;
             }
             else if(curr->data > k->data){
                 successor = curr->data;
                 curr = curr->left;
             }
             else curr = curr->right;
         }
        return successor;
    }
};
