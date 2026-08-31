/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void insertinBetween(Node *head){
        Node *temp = head;
        while(temp != NULL){
            Node* copyNode =new Node(temp->val);
            copyNode->next = temp->next;
            temp->next = copyNode;
            temp = copyNode->next; 
        }
    }
    void copyRandomPointer(Node *head){
        Node *temp = head;
        while(temp != NULL){
          Node *copyNode = temp->next;
            if(temp->random){
            copyNode->random = temp->random->next;
            }
            else{
                copyNode->random = nullptr;
            }
            temp = temp->next->next;
        }
    }
    Node *getDeepCopy(Node *head){
        Node *temp = head;
        Node *dummyNode = new Node(-1);
        Node *res = dummyNode;
        while(temp != NULL){
          res->next = temp->next;
          res = res->next;
          temp->next = temp->next->next;
         temp = temp->next;
        }
        return dummyNode->next;
    }
    Node* copyRandomList(Node* head) {
        insertinBetween(head);
        copyRandomPointer(head);
        return getDeepCopy(head);
    }
};