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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*dummy = new ListNode(-1);
        ListNode*temp1 = l1, *temp2 = l2,*ans = dummy;
        int carry = 0;
        while(temp1  && temp2){
            int sum = temp1->val +temp2->val+carry;
            ListNode *node = new ListNode(sum%10);
            carry = sum/10;
            ans->next = node;
            ans = node;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        while(temp1){
            int sum = temp1->val + carry;
            ListNode *node = new ListNode(sum%10);
            carry = sum/10;
            ans->next = node;
            ans = node;
            temp1 = temp1->next;
        }
        while(temp2){
            int sum = temp2->val + carry;
            ListNode *node = new ListNode(sum%10);
            carry = sum/10;
            ans->next = node;
            ans = node;
            temp2 = temp2->next;
        }
        if(carry != 0){
            ListNode *node = new ListNode(carry);
            ans->next = node;
        }
        return dummy->next;
    }
};