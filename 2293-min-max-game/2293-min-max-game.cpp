class Solution {
public:
    int function(vector<int>& nums) {

        while (nums.size() >= 2) {
            vector<int> newNums(nums.size() / 2);
            for (int i = 0; i < nums.size() / 2; i++) {
                if (i % 2 == 0)
                    newNums[i] = min(nums[2 * i], nums[2 * i + 1]);
                else
                    newNums[i] = max(nums[2 * i], nums[2 * i + 1]);
            }
            nums = newNums;
        }
        return nums[0];
    }
    int minMaxGame(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        else {
            return function(nums);
        }
    }
};