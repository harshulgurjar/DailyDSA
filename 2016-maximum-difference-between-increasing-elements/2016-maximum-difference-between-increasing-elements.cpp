class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int diff =-1;
        int min=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]>min){
                diff = max(nums[i]-min,diff);
            }
            if(nums[i]<min){
                min=nums[i];
            }
        }
        return diff;
    }
};