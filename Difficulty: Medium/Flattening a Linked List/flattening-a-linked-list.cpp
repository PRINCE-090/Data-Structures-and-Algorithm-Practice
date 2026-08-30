// using recursion 
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = nullptr;
        bottom = nullptr;
    }
};
   Node * mergeLists(Node *list1, Node *list2){
       Node *dummyNode = new Node(-1);
       Node *res = dummyNode;
       while(list1  != NULL && list2 != NULL){
           if(list1->data <= list2->data){
               res->bottom = list1;
               res = list1;
               list1 = list1->bottom;
           }
           else {
               res->bottom = list2;
               res = list2;
               list2 = list2->bottom;
           }
           res->next = NULL;
       }
       if(list1) res->bottom = list1;
       else res->bottom = list2;
       return dummyNode->bottom;
       
   }
class Solution {
  public:
    Node* flatten(Node* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
      Node* newList =  flatten(head->next);
        return mergeLists(head,newList);
        
    }
};


// using min heap

/* Structure of Linked List Node
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = nullptr;
        bottom = nullptr;
    }
};*/

class Solution {
  public:
   struct compare{
       bool operator()(Node *a , Node *b){
           return a->data > b->data;
       }
   };
    Node* flatten(Node* head) {
     if(head == NULL) return NULL;
     
     priority_queue<Node*,vector<Node*>,compare>pq;
     Node *temp = head;
     
     while(temp != NULL){
         pq.push(temp);
         temp = temp->next;
     }
     Node *dummy = new Node(-1);
     Node* tail = dummy;
     
     while(!pq.empty()){
         Node *curr = pq.top();
         pq.pop();
         
         if(curr->bottom != NULL){
             pq.push(curr->bottom);
         }
         
         tail->bottom = curr;
         tail = curr;
         
         curr->next = NULL;
     }
     tail->bottom = NULL;
     
     return dummy->bottom;
        
    }
};
