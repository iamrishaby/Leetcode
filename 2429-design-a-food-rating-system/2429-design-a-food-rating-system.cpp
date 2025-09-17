class FoodRatings {

private:
    unordered_map<string, string> foodToCuisine; // food -> cuisine
    unordered_map<string, int> foodToRating;     // food -> rating

    // comparator for max-heap
    struct cmp {
        bool operator()(const pair<int, string>& a, const pair<int, string>& b) const {
            if (a.first != b.first)
                return a.first < b.first;  // higher rating first
            return a.second > b.second;    // lexicographically smaller first
        }
    };

    unordered_map<string, priority_queue<pair<int, string>, vector<pair<int, string>>, cmp>> cuisineToPQ;
    
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for (int i = 0; i < n; i++) {
            foodToCuisine[foods[i]] = cuisines[i];
            foodToRating[foods[i]] = ratings[i];
            cuisineToPQ[cuisines[i]].push({ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = foodToCuisine[food];
        foodToRating[food] = newRating;
        // push new entry, leave old one inside (lazy deletion)
        cuisineToPQ[cuisine].push({newRating, food});
        
    }
    
    string highestRated(string cuisine) {
        auto& pq = cuisineToPQ[cuisine];
        // discard outdated ratings
        while (!pq.empty()) {
            auto top = pq.top();
            if (foodToRating[top.second] == top.first) {
                return top.second;
            }
            pq.pop(); // stale entry
        }
        return ""; 
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */