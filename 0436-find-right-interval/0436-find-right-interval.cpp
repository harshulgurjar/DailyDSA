class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            int idx = -1;
            int minStart = INT_MAX;

            for (int j = 0; j < n; j++) {

                // Is interval j a valid right interval?
                // And is its start the smallest we've seen?
                if (intervals[j][0] >= intervals[i][1] &&
                    intervals[j][0] < minStart) {

                    minStart = intervals[j][0];
                    idx = j;
                }
            }

            ans[i] = idx;
        }

        return ans;
    }
};