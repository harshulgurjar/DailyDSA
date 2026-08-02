class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int buyprice=prices[0];
        for(int i=0;i<prices.size();i++){
            if(buyprice>prices[i])
            buyprice=prices[i];
            profit=profit+prices[i]-buyprice;
            buyprice=prices[i];
        }
        return profit;
    }
};