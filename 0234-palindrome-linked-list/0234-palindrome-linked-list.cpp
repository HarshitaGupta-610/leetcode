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
//Brute Force: O(N) add in vectors the values and then compare pallindrome
//bool isPalindrome(ListNode* head) {
// vector<int>num;
// while(head!=NULL){
//     num.push_back(head->val);
//     head = head -> next;
// }
// int i = 0 , j = num.size()-1;
// while(i<j){
//     if(num[i] == num[j]) {
//         i++;
//         j--;
//     }else{
//         return false;
//     }
// }
// return true;
//     }


//Optimal :Find the middle using slow-fast pointers, reverse the second half, and compare both halves node by node. (O(N) )
ListNode* Rev(ListNode* head){
    ListNode* prev = NULL;
    ListNode* curr = head;
    while(curr){
        ListNode* next = curr->next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
bool isPalindrome(ListNode* head) {
if(head == NULL && head -> next == NULL) return true;
ListNode* slow = head;
ListNode* fast = head;
while(fast-> next != NULL && fast -> next -> next != NULL){
    slow = slow->next;
    fast = fast->next->next;
}
ListNode* second = Rev(slow->next);
ListNode* first = head;
while(second!= NULL){
    if(first->val != second -> val) return false;
    first = first -> next;
    second = second->next;
}

return true;
}
};