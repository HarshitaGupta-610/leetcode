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
struct Compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;   // by default pqueue adress comapre karleta so to avoid that happening we are making a comapriosn operator
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
         //abhi heap ke elements pointers hain toh usko comapre functions values ko compare karke pqueue mein dalega
          for (auto node : lists) {
            if (node != NULL){
                pq.push(node);
            }// sari lists ke head dal diye andar
        }
        
ListNode* dummy = new ListNode(-1);//start of merged list
ListNode* tail = dummy; // to attach more nodes

        while (!pq.empty()) {
            ListNode* top = pq.top();// sabse smallest node nikalo
            pq.pop();// heap se bahar aagygi smallest

            tail->next = top;// smallest nde list mein hai result wali
            tail = tail->next;// next node 

            if (top->next) {// check for next node of list
                pq.push(top->next);
            }
        }

        return dummy->next;// final answer list jo hume chahhiye
    }
};