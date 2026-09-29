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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans;

        while(head){
            ans.push_back(head->val);
            head = head->next;
        }

        vector<int> boundary;

        int n = ans.size();

        for(int i = 1; i < n - 1; i++){
            if(ans[i] > ans[i - 1] && ans[i] > ans[i + 1]){
                boundary.push_back(i);
            }
            else if(ans[i] < ans[i - 1] && ans[i] < ans[i + 1]){
                boundary.push_back(i);
            }
        }

        int m = boundary.size();

        if(m < 2) return {-1, -1};

        int Mini = INT_MAX;
        int maxi = boundary[m - 1] - boundary[0];

        for(int i = 1; i < m; i++){
            Mini = min(Mini,boundary[i] - boundary[i - 1]);
        }

        return {Mini, maxi};
    }
};