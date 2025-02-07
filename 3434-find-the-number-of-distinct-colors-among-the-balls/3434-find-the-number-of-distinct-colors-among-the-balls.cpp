class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> ball_color;  // Maps each ball to its color
    unordered_map<int, int> color_count; // Tracks how many balls have each color
    unordered_set<int> color_set;        // Keeps track of distinct colors
    vector<int> result;

    for (auto& query : queries) {
        int ball = query[0], color = query[1];

        // If the ball already has a color
        if (ball_color.count(ball)) {
            int prev_color = ball_color[ball];
            color_count[prev_color]--;

            // If no balls have this color anymore, remove it from the set
            if (color_count[prev_color] == 0) {
                color_set.erase(prev_color);
            }
        }

        // Update ball color and increase its count
        ball_color[ball] = color;
        color_count[color]++;
        color_set.insert(color);

        // Store the count of distinct colors
        result.push_back(color_set.size());
    }

    return result;
    }
};