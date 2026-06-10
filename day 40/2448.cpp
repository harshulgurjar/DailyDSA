class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {

        vector<pair<int,int>> v;

        long long total = 0;

        for(int i=0;i<nums.size();i++){
            v.push_back({nums[i], cost[i]});
            total += cost[i];
        }

        sort(v.begin(), v.end());

        long long prefix = 0;
        long long target = 0;

        for(auto &p : v){

            prefix += p.second;

            if(prefix >= (total + 1)/2){
                target = p.first;
                break;
            }
        }

        long long ans = 0;

        for(auto &p : v){

            ans += 1LL * abs(p.first - target) * p.second;
        }

        return ans;
    }
};
