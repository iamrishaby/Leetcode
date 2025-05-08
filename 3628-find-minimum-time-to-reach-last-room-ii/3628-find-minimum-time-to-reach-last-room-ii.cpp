#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int rows = moveTime.size();
        int cols = moveTime[0].size();
        
        // minTime array to store the minimum time to reach each cell with 0 and 1 parity
        vector<vector<vector<int>>> minTime(rows, vector<vector<int>>(cols, vector<int>(2, INT_MAX)));
        
        // Starting point (0, 0) with parity 0 at time 0
        minTime[0][0][0] = 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> priorityQueue;
        priorityQueue.push({0, 0, 0, 0}); // {currentTime, row, col, parity}
        
        // Directions for moving in the grid: right, down, left, up
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        while (!priorityQueue.empty()) {
            vector<int> current = priorityQueue.top();
            priorityQueue.pop();
            
            int currentTime = current[0];
            int row = current[1];
            int col = current[2];
            int parity = current[3];
            
            // Skip if we've already found a faster way to this cell with this parity
            if (currentTime > minTime[row][col][parity]) continue;
            
            // Explore all adjacent cells
            for (const auto& direction : directions) {
                int newRow = row + direction[0];
                int newCol = col + direction[1];
                
                // Check if newRow and newCol are within bounds
                if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols) {
                    // Calculate next time based on parity and moveTime constraint
                    int nextTime = max(currentTime, moveTime[newRow][newCol]) + (parity == 0 ? 1 : 2);
                    
                    // Update if a faster way to reach (newRow, newCol) is found
                    if (nextTime < minTime[newRow][newCol][1 - parity]) {
                        minTime[newRow][newCol][1 - parity] = nextTime;
                        priorityQueue.push({nextTime, newRow, newCol, 1 - parity});
                    }
                }
            }
        }
        
        // Result is the minimum of the two parities at the target cell
        return min(minTime[rows - 1][cols - 1][0], minTime[rows - 1][cols - 1][1]);
    }
};
