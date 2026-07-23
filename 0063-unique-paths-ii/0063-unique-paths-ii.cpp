class Solution {
public:
    int dp[101][101];
    int sol(vector<vector<int>>& o,int i,int j){
        int m=o.size();
        int n=o[0].size();

        if(i>=m || j>=n){
            return 0;
        }
        if(o[i][j]==1)
            return 0;
        if(i == m -1 && j==n-1)
            return 1;
        if(dp[i][j]!=-1)
            return dp[i][j];

        return dp[i][j]=sol(o,i+1,j)+sol(o,i,j+1);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& o) {
        for(int i=0;i<101;i++){
            for(int j=0;j<101;j++){
                dp[i][j]=-1;
            }
        }
        return sol(o,0,0);
    }
};