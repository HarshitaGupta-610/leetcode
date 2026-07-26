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

  //Brute : O(N) space and time by cretaing map to store connections      
  if(head == NULL) return NULL;
  unordered_map<Node*,Node*>m;
  Node*temp=head;
  while(temp!=NULL){//nodes ki copy pehli
    m[temp] = new Node(temp->val);
    temp = temp->next;
  }
  temp = head;
  while(temp){
    m[temp]->next=m[temp->next];//new node mein purane jaisa same connection
    m[temp]->random=m[temp->random];
    temp = temp->next;
  }
  return m[head];
    }
};