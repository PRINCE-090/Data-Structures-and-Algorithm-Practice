/* Structure of Linked List Node
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};*/

class Solution {
  public:
    int lengthOfLoop(Node *head) {
        int length = 0;
        Node*slow = head,*fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                length++;
                slow = slow->next;
                while(slow != fast){
                    length++;
                    slow = slow->next;
                }
                return length;
            }
        }
       
        return length;
        
    }
};