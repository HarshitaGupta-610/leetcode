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
        //Brute Force: O()store the addresses and if we get same address again tehre is cycle
        unordered_set<ListNode*>v;//visited nodes
        ListNode* temp = head;
        while(temp  != NULL){//apan last node tak jayege
            if(v.find(temp) != v.end()) return true;//address already there
            v.insert(temp); 
            temp = temp->next;
        }
        return false;
   }

};