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
//         int l = 0;
//         ListNode* temp = head;
//         while(temp != NULL){
//             l++;
//             temp = temp->next;
//         }
//         if(l ==n){
//             ListNode* del = head;
//             head = head -> next;
//             delete del;
//             return head;
//         }
//         int pos = l-n;//usse pehle ki node
//         temp = head;
//         for(int i = 1 ; i <=pos-1 ; i++){
//             temp = temp -> next;
//         }
//         ListNode* removal = temp -> next;
// temp -> next = temp -> next -> next;
// delete removal;
// return head;


//Optimal : O(N)
/*Move fast n steps ahead.
Then move both fast and slow together.
When fast reaches the last node, slow will be just before the node to delete.*/
 // Dummy node bana liya taaki head delete hone ka case bhi handle ho jaaye
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // Dono pointers dummy se start karenge
        ListNode* slow = dummy;
        ListNode* fast = dummy;

        // Fast ko pehle n steps aage le jao
        for(int i = 0; i < n; i++)
        {
            fast = fast->next;
        }

        // Jab tak fast last node par na pahunch jaaye,
        // tab tak dono ko ek-ek step chalao
        while(fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }

        // Delete hone wali node
        ListNode* del = slow->next;

        // Us node ko skip kar do
        slow->next = slow->next->next;

        delete del;

        return dummy->next;
 
    }
};