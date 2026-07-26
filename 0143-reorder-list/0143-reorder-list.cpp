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
    void reorderList(ListNode* head) {
        

        //Brute Force: sapce and time O(N)Store all node pointers in a vector, then use two pointers (i from the front and j from the back) to reconnect the nodes alternately, and finally set the last node's next to NULL.
//      if (head == NULL || head->next == NULL) return;
//       vector<ListNode*> nodes;
//          ListNode* temp = head;
//         while (temp) {
//             nodes.push_back(temp);
//             temp = temp->next;
//         } int i = 0;
//         int j = nodes.size() - 1;
//          while (i < j) {
//             nodes[i]->next = nodes[j];
//             i++;
//  if (i == j) break;
//  nodes[j]->next = nodes[i];
//             j--;
//         }
//                 nodes[i]->next = NULL;
//     }


//Optimal Approach (O(N) Time, O(1) Space)
//find middle , reverse remainign , merge
if (head == NULL || head->next == NULL) return;
  ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
ListNode* prev = NULL;
ListNode* curr = slow->next;
        slow->next = NULL;
        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        ListNode* first = head;
        ListNode* second = prev;
        while (second) {
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;
first->next = second;
second->next = temp1;
            first = temp1;
            second = temp2;
        }
    }
};