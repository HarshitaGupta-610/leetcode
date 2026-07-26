/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
  //Question in simple words:Create a completely independent clone of the linked list where both next and random connections are exactly the same as the original, but every node is newly created.
   if(head == NULL) return NULL;
  //Brute : O(N) space and time by cretaing map to store connections      

//   unordered_map<Node*,Node*>m;
//   Node*temp=head;
//   while(temp!=NULL){//nodes ki copy pehli
//     m[temp] = new Node(temp->val);
//     temp = temp->next;
//   }
//   temp = head;
//   while(temp){
//     m[temp]->next=m[temp->next];//new node mein purane jaisa same connection
//     m[temp]->random=m[temp->random];
//     temp = temp->next;
//   }
//   return m[head];


//optimal: O(N)
Node* curr =head;
while(curr!=NULL){//Har original node ke baad uski copy insert karo
    Node* copy = new Node(curr->val);// Current original node ki copy banao
    copy->next=curr->next;// Copy ka next us jagah point karega jahan original ka next tha
    curr->next = copy;// Original ke baad copy insert kar do
    curr=copy->next;//Agle original node par jao,(copy ke baad hi original next node hai)
}
curr = head;//copy->random = original->random->next
//randoms conenct karne ke liye
while(curr){
    if(curr->random !=NULL){
        curr->next->random=curr->random->next;
    }
    curr=curr->next->next;
}
//final answer list
curr = head;
 Node* dummy = new Node(-1);
Node* temp = dummy;
while(curr){
    Node* copy = curr->next;
    curr->next = copy->next;
temp->next = copy;//new list
temp = copy;
curr=curr->next;
}

   return dummy->next;
    }
};