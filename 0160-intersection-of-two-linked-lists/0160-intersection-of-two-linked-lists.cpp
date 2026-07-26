/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //Brute : O(N*M) for every node of a , check in b
        // ListNode* a = headA;
        // while(a != NULL){
        //     ListNode* b = headB;
        //     while(b!=NULL){
        //         if(a==b) return a;
        //         b=b->next;
        //     }
        //     a=a->next;
        // }
        // return NULL;
        //Better : O(M+N): a ki sari store krlo , b ki find kro a mein hain ya nahi
        unordered_set<ListNode*>s;
        while(headA){
            s.insert(headA);
            headA = headA -> next;
        }
            while(headB){
            if(s.find(headB) != s.end()) return headB;
            headB = headB -> next;
        }
        return NULL;
    }
};