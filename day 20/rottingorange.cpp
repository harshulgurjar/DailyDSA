class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int,int>, int>> q;
        int fresh = 0;
        int time = 0;

        // Step 1: push all rotten oranges
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j}, 0});
                }
                else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }

        // directions: up, right, down, left
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        while(!q.empty()){
            auto front = q.front();
            q.pop();

            int r = front.first.first;
            int c = front.first.second;
            int t = front.second;

            time = max(time, t);

            for(int k = 0; k < 4; k++){
                int nr = r + drow[k];
                int nc = c + dcol[k];

                if(nr >= 0 && nc >= 0 && nr < n && nc < m && grid[nr][nc] == 1){
                    grid[nr][nc] = 2; // mark rotten
                    fresh--;
                    q.push({{nr, nc}, t + 1});
                }
            }
        }

        if(fresh > 0) return -1;
        return time;
    }
};