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
         // Base case: agar list empty hai ya sirf ek hi node bachi hai
    // To wahi new head banegi
    if(head == NULL || head->next == NULL)
        return head; 


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


// same way using stack:O(N)
// stack<int>s;
// ListNode* temp = head;
// while(temp!= NULL){
//     s.push(temp->val);
//     temp = temp -> next;
// }
// temp = head;
// while(temp != NULL){
// temp -> val = s.top();
// s.pop();
// temp = temp -> next;
// return head;}

// //Optimal : O(N) 3 pointers
//   ListNode* prev = NULL;
//         ListNode* curr = head;
//         while(curr != NULL){
//             // Next node save karo
//             ListNode* next = curr->next;
//             // Pointer reverse karo
//             curr->next = prev;
//             // Prev aage badhao
//             prev = curr;
//             // Current aage badhao
//             curr = next;
//         }
//         // Prev hi naya head hai
//         return prev;
// return head;


//Recursive Approach : O(N)
    // Baaki puri list ko reverse karo aur uska new head le aao
    ListNode* newHead = reverseList(head->next);

    // Apne next node ko bolo ki wo mujhe point kare
    // 2 -> 3 ko 3 -> 2 bana deta hai
    head->next->next = head;

    // Purana forward connection tod do warna cycle ban jayegi
    head->next = NULL;

    // Har recursive call same new head (last node) return karegi
    return newHead;
}
};
