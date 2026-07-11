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

// Custom Comparator
class compare {
public:
    bool operator()(ListNode* a, ListNode* b) {

        // Agar a ki value b se badi hai
        // to a ki priority kam hogi.
        // Isliye smallest value top par rahegi.
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        // Min Heap
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;

        // Sabhi linked lists ke first node ko heap me daal do
        for (auto node : lists) {
            if (node != NULL) {
                pq.push(node);
            }
        }

        // Dummy node answer list banane ke liye
        ListNode* dummy = new ListNode(-1);

        // Tail hamesha answer list ke last node ko point karega
        ListNode* tail = dummy;

        // Jab tak heap khali nahi hota
        while (!pq.empty()) {

            // Heap ka smallest node nikalo
            ListNode* curr = pq.top();
            pq.pop();

            // Us node ko answer list me jod do
            tail->next = curr;

            // Tail ko aage badha do
            tail = tail->next;

            // Agar us linked list me aur node bacha hai
            // to us next node ko heap me daal do
            if (curr->next != NULL) {
                pq.push(curr->next);
            }
        }

        // Dummy node ko skip karke actual head return karo
        return dummy->next;
    }
};