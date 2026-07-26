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
//Brute Force: O(N) add in vectors the values and then compare pallindrome
 bool isPalindrome(ListNode* head) {
vector<int>num;
while(head!=NULL){
    num.push_back(head->val);
    head = head -> next;
}
int i = 0 , j = num.size()-1;
while(i<j){
    if(num[i] == num[j]) {
        i++;
        j--;
    }else{
        return false;
    }
}
return true;
    }
};