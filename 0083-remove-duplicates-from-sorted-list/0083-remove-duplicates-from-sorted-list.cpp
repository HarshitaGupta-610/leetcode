class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp = head;
        while (temp != nullptr && temp->next != nullptr) {
            if (temp->val == temp->next->val) {
                // Duplicate found → skip the next node
                temp->next = temp->next->next;
            } else {
                // Move forward only if no duplicate
                temp = temp->next;
            }
        }
        return head;
    }
};
