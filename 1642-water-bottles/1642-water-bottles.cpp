class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int drank = numBottles;
        int empty = numBottles;

        while (empty >= numExchange) {
            int newBottles = empty / numExchange;   // exchange for new full bottles
            drank += newBottles;                   // drink them
            empty = empty % numExchange + newBottles; // leftover + new empties
        }

        return drank;
    }
};