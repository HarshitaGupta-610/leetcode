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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {


        //Brute : O(N) traverse both and store in vector then sort
//         vector<int>lists;
//         while(list1 != NULL){
// lists.push_back(list1 -> val);
// list1 = list1 -> next;
//         }
//         while(list2){
//             lists.push_back(list2 -> val);
//             list2 = list2 -> next;
//         }
// sort(lists.begin(),lists.end());
// ListNode* dummy = new ListNode(-1);
// ListNode* temp = dummy ;
// for(int num : lists){
//     temp -> next = new ListNode(num);
//     temp = temp -> next;
// }
// return dummy-> next;


// //Better Approach :O(N)  Create a brand new linked list
// ListNode* dummy = new ListNode(-1);
// ListNode* temp =  dummy;
// while(list1 && list2){
//     if(list1->val <= list2 -> val){
//         temp -> next = new ListNode(list1->val);
//         list1 = list1 -> next;
//     }else{
//         temp -> next = new ListNode(list2 -> val);
//         list2 = list2 -> next;
//     }
//     temp = temp -> next;
// }
// while(list1){
//     temp -> next = new ListNode(list1 -> val);
//     list1 = list1 -> next;
//     temp = temp -> next;
// }
// while(list2){
//     temp -> next = new ListNode(list2 -> val);
//     list2 = list2 -> next;
//     temp = temp -> next;
// }
// return dummy -> next;
//     }


//optimal : O(N): keep connecting the exisitng
ListNode* temp = new ListNode(-1);
ListNode* dummy = temp;
while(list1 && list2){
    if(list1 -> val <= list2-> val){
        temp -> next = list1;
        list1 = list1 -> next;
    }else{
        temp -> next = list2;
        list2 = list2 -> next;

    }
    temp = temp -> next;

}
if(list1)temp->next = list1;
else temp -> next = list2;
return dummy -> next;
    }
};