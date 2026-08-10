/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
   ListNode*reverse(ListNode *head){
    ListNode *prev = NULL;
    while(head){
        ListNode* front = head->next;
        head->next = prev;
        prev = head;
        head = front;
    }
    return prev;
   }
    void reorderList(ListNode* head) {
        ListNode*slow = head;
        ListNode*fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode*mid =  reverse(slow->next);
        slow->next = NULL;
       ListNode*head1 = head;
       ListNode*head2 = mid;
       while(head2){
       ListNode*temp1 = head1->next;
       ListNode*temp2 = head2->next;
       head1->next = head2;
       head2->next = temp1;

       head1 = temp1;
       head2 = temp2;
       }
    }
};