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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //Brute force : O(N)
        //length find krke position from beginnning : length - n +1;
        int l = 0;
        ListNode* temp = head;
        while(temp != NULL){
            l++;
            temp = temp->next;
        }
        if(l ==n){
            ListNode* del = head;
            head = head -> next;
            delete del;
            return head;
        }
        int pos = l-n;//usse pehle ki node
        temp = head;
        for(int i = 1 ; i <=pos-1 ; i++){
            temp = temp -> next;
        }
        ListNode* removal = temp -> next;
temp -> next = temp -> next -> next;
delete removal;
return head;
    }
};