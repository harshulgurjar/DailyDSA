class Solution {
    void solve(vector<int>&nums,int start,vector<vector<int>>&ans){
        if(start>=nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int j=start;j<nums.size();j++){
            swap(nums[start],nums[j]);
            solve(nums,start+1,ans);
            swap(nums[start],nums[j]);
            

        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int index=0;
        solve(nums,index,ans);
        return ans;
    }
};
