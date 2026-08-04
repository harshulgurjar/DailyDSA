class Solution {
public:
    int rec(vector<int>& coins, int amount, int i,vector<vector<int>>&dp){
        if(amount == 0)return 0;
        if(i>=coins.size())return 1e9;
        if(dp[i][amount]!=-1)return dp[i][amount];
        int take =1e9;
        int not_take=1e9;
        not_take=0+rec(coins,amount,i+1,dp);
        if(amount>=coins[i])take=1+rec(coins,amount-coins[i],i,dp);
        dp[i][amount]=min(not_take,take);
        return min(not_take,take);

    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        long long ans=rec(coins,amount,0,dp);
        if(ans == 1e9)return -1;

        return ans;
    }
};