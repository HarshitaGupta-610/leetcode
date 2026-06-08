class Solution {
public:

    bool possible(vector<int>& bloomDay, int day, int m, int k) {

        int bouquets = 0;
        int flowers = 0;

        for(int i = 0; i < bloomDay.size(); i++) {

            if(bloomDay[i] <= day) {
                flowers++;
            }
            else {
                bouquets += flowers / k;
                flowers = 0;
            }
        }

        bouquets += flowers / k;

        return bouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {

        int n = bloomDay.size();

        if((long long)m * k > n)
            return -1;

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        int ans = -1;

        while(low <= high) {

            int mid = low + (high - low) / 2;

            if(possible(bloomDay, mid, m, k)) {

                ans = mid;
                high = mid - 1;
            }
            else {

                low = mid + 1;
            }
        }

        return ans;
    }
};