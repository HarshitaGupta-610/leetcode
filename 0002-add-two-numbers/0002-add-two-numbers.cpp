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
 /*Brute force: Convert both linked lists into numbers, 
 add them normally, then convert the sum back into a linked list.
Why not? It doesn't work because the linked lists can represent 
very large numbers (hundreds of digits) that cannot fit in data types
 like int or long long, causing integer overflow.
  Hence, we add the digits directly using carry instead.*/

  //add one digit at a time, while maintaining a carry.
  //sum = digit1 + digit2 + carry
// digit = sum % 10 → store this in the answer list.
// carry = sum / 10 → use in the next addition.
ListNode* dummy = new ListNode(-1);
ListNode* temp =dummy;
int carry = 0;
while(l1 || l2 || carry){
    int sum = carry;
    if(l1){
        sum+=l1->val;
        l1 = l1->next;
    }if(l2){
        sum+=l2->val;
        l2=l2->next;
    }
    temp->next= new ListNode(sum%10);
    carry = sum/10;
    temp=temp->next;
}
return dummy->next;
    }
};