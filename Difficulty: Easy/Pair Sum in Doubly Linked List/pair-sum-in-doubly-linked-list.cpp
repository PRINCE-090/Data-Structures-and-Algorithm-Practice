/* Structure of Doubly Linked List Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
}; */

class Solution {
  public:
    vector<vector<int>> givenSumPairs(Node* head, int target) {
        vector<vector<int>>ans;
       Node*fast = head, *slow = head;
       while(fast->next != NULL) fast = fast->next;
       while(slow != NULL && fast != NULL && slow != fast && fast->next != slow){
           if(slow->data+fast->data == target){
               ans.push_back({slow->data,fast->data});
               slow = slow->next;
               fast = fast->prev;
           }
           else if(slow->data+fast->data > target){
               fast = fast->prev;
           }
           else{
               slow = slow->next;
           }
       }
       return ans;
        
    }
};