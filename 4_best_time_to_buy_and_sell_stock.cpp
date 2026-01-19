/**
 * Key Learning Point: This is actually a two-pointer problem. Left is current. Right is i. 
 * Left is also the buy price and Right is the sell price.
 * Right always increases.
 * Left jumps to Right only if lower buying price is encountered.
 * The whole idea is also that you cannot go back in time, so it doesn't matter if a more favourable setting presents in itself
 * if the time for it is not feasible.
 *
 * Given the selling price of wherever you are at in time, can you find a better deal than what you saw previously.
 *
 * You can't. Walk through the permutations in your head.
 *
 * Runtime: O(n)
 *
 * Memory: O(1)
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int current = prices[0];
        int profit = 0;

        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] < current)
            {
                current = prices[i];
            }
            else if (prices[i] - current > profit)
            {
                profit = prices[i] - current;
            }
        }

        return profit;
    }
};
