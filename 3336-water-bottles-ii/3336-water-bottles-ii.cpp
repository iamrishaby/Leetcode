class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int drunk = numBottles;
        int empty = numBottles;

        while (empty >= numExchange) {
            empty -= numExchange;   // use empties for exchange
            numExchange++;          // exchange rate increases
            drunk++;                // drink new bottle
            empty++;                // new bottle becomes empty after drinking
        }
        return drunk;
    }
};