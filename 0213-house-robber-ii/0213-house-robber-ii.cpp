class Solution {
public:
    int solve(int i, vector<int>& nums, vector<int>& dp) {
        if (i == 0) return nums[0];
        if (i < 0) return 0;

        if (dp[i] != -1)
            return dp[i];

        int take = nums[i] + solve(i - 2, nums, dp);
        int notTake = solve(i - 1, nums, dp);

        return dp[i] = max(take, notTake);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return nums[0];

        vector<int> first(nums.begin(), nums.end() - 1); // exclude last
        vector<int> second(nums.begin() + 1, nums.end()); // exclude first

        vector<int> dp1(first.size(), -1);
        vector<int> dp2(second.size(), -1);

        int x = solve(first.size() - 1, first, dp1);
        int y = solve(second.size() - 1, second, dp2);

        return max(x, y);
    }
};