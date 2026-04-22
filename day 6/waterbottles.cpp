class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans=numBottles;
        while(numBottles>=numExchange){
            int newbo=numBottles/numExchange;
            int rembo=numBottles%numExchange;
             ans=ans+newbo;
            numBottles=newbo+rembo;

        }
        return ans;
    }
};