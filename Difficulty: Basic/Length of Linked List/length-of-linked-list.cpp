/* Structure of linked list Node
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
 int countNode(Node*head,int &cnt){
     if(head == NULL){
         return cnt;
     }
     cnt++;
     countNode(head->next,cnt);
 }
class Solution {
  public:
    int getCount(Node* head) {
        int cnt = 0;
     return countNode(head,cnt);
        
    }
};