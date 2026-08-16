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
int hcf(int val1 , int val2){
    while(val2 != 0){
        int rem = val1 % val2;
        val1 = val2;
        val2 = rem;
    }
    return val1;
}
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* temp = head;
        while(temp != NULL && temp -> next != NULL){
            int value1 = temp -> val;
            int value2 = temp -> next -> val;
            int h = hcf(value1 , value2);
ListNode* newNode = new ListNode(h);
newNode -> next = temp -> next;
temp -> next = newNode;
temp = newNode -> next;
        }
        return head;          
        
    }
};