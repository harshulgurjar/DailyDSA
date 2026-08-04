class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        sort(coins.begin(),coins.end());
        int i,j,k,n=coins.size(),possible=0,cnt=0;
        i=0;
        while(i<coins.size() && possible<target){
            if(coins[i]<=possible+1){
               possible=possible+coins[i];
               i++;
            }
            else{
                possible=2*possible+1;
                cnt++;
            }
        }

        while(possible<target){
            possible=2*possible+1;
            cnt++;
        }
        return cnt;
    }
};