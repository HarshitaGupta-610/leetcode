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
    bool hasCycle(ListNode *head) {
        //Brute Force: O(N)store the addresses and if we get same address again tehre is cycle
        // unordered_set<ListNode*>v;//visited nodes
        // ListNode* temp = head;
        // while(temp  != NULL){//apan last node tak jayege
        //     if(v.find(temp) != v.end()) return true;//address already there
        //     v.insert(temp); 
        //     temp = temp->next;
        // }
        // return false;


        //Optimal Approach : O(N)(Floyd's via 2 pointers)
                // Dono pointers head se start karenge
        ListNode* slow = head;
        ListNode* fast = head;
while(fast != NULL && fast -> next != NULL){//jab tak fast aur uska next exists
    slow = slow -> next;// slow ek time pe ek step chalega
    fast = fast -> next -> next;//fast ek time pe do step
    if(slow == fast) return true;//agarr donon meet krjayein toh cycle
}
return false;
   }

};