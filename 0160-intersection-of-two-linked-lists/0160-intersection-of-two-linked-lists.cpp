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
    //     //Better : O(M+N): a ki sari store krlo , b ki find kro a mein hain ya nahi
    //     unordered_set<ListNode*>s;
    //     while(headA){
    //         s.insert(headA);
    //         headA = headA -> next;
    //     }
    //         while(headB){
    //         if(s.find(headB) != s.end()) return headB;
    //         headB = headB -> next;
    //     }
    //     return NULL;
    // }

    //Optimal : O(M+N)
    /*The difference between the list lengths is exactly the 
    difference in their unique parts.When the pointers switch lists,
     each pointer walks through the other list's unique part.
So the pointer that was ahead becomes behind by the same amount,
 and eventually both get aligned at the beginning of the common part.*/
    ListNode* a= headA;
    ListNode* b= headB;
    while(a!=b){
        if(a == NULL) a = headB;
        else a = a-> next;
        if(b==NULL) b = headA;
        else b = b-> next;
    }
    return a;
    }
};