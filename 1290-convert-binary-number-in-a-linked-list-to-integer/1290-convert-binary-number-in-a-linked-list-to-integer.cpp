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
    int getDecimalValue(ListNode* head) {

        //Brute: both time and space O(N):Traverse the linked list and store all binary digits in a vector.Reverse the vector.Multiply each digit by its corresponding power of 2.Add everything to ans.
        // vector<int>bdigits;
        // while(head){
        //     bdigits.push_back(head ->val);
        //     head = head -> next;
        // }
        // reverse(bdigits.begin() , bdigits.end());
        // int ans = 0;
        // int n = bdigits.size();
        // int pow =1;
        // for(int i = 0 ; i< n ; i++){
        //     ans = ans + (pow*bdigits[i]);
        //     pow*=2;
        // }
        // return ans;

//Optimal Appraoch :Har new binary digit ke liye: old answer ko 2 se multiply karo, phir current bit add karo. TC : O(N)
int ans = 0;
while(head){
    ans = ans * 2 + head->val;
    head = head->next;
}
return ans;
    }
};