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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL)return head; //empty list


        // //Brute : O(n)  vector mein value store krke baha nikalo end se
        // vector<int>v;
        // ListNode* temp = head;
        // while(temp != NULL){
        //     v.push_back(temp->val);
        //     temp = temp -> next;
        // }
        // temp = head;
        // int i =v.size()-1;
        // while(temp!= NULL){
        //     temp->val = v[i];
        //     i--;
        //     temp = temp -> next;
        // }
        // return head;

//Optimal : O(N) 3 pointers
  ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr != NULL){
            // Next node save karo
            ListNode* next = curr->next;
            // Pointer reverse karo
            curr->next = prev;
            // Prev aage badhao
            prev = curr;
            // Current aage badhao
            curr = next;
        }
        // Prev hi naya head hai
        return prev;
    }
};
