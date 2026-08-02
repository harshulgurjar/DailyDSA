class Solution {
public:
    vector<int> dp;

    int solve(vector<int>& nums, int idx) {
        int n = nums.size();

        if (idx >= n - 1)
            return 0;

        if (dp[idx] != -1)
            return dp[idx];

        int ans = INT_MAX;

        for (int jump = 1; jump <= nums[idx]; jump++) {
            if (idx + jump < n) {
                int next = solve(nums, idx + jump);

                    if (next != INT_MAX) {
                        ans = min(ans, 1 + next);
                    }
                }
            }

        return dp[idx] = ans;
    }

    int jump(vector<int>& nums) {
        dp.assign(nums.size(), -1);
        return solve(nums, 0);
    }
};