class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {

        sort(items.begin(), items.end());

        vector<pair<int,int>> q;
        for(int i = 0; i < queries.size(); i++)
            q.push_back({queries[i], i});

        sort(q.begin(), q.end());

        vector<int> ans(queries.size());

        int best = 0;
        int j = 0;

        for(auto &x : q){

            while(j < items.size() && items[j][0] <= x.first){
                best = max(best, items[j][1]);
                j++;
            }

            ans[x.second] = best;
        }

        return ans;
    }
};