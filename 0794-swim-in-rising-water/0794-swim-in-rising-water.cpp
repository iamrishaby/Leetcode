class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        
        // Min-heap storing (time, x, y)
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({grid[0][0], 0, 0});
        
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        
        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            int t = cur[0], x = cur[1], y = cur[2];
            
            if (visited[x][y]) continue;
            visited[x][y] = true;
            
            // Reached destination
            if (x == n-1 && y == n-1) return t;
            
            for (auto& d : dirs) {
                int nx = x + d[0], ny = y + d[1];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny]) {
                    pq.push({max(t, grid[nx][ny]), nx, ny});
                }
            }
        }
        return -1; // should never happen
    }
};