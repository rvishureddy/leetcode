// Best time to buy a stock II
/*
You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.



Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Total profit is 4.
Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.
*/

#include <vector>
#include <stdio.h>
#include <iostream>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int maxProfit = 0; // Initialize total profit
        // Iterate through the price list starting from the second day
        for (int i = 1; i < prices.size(); ++i)
        {
            // If today's price is higher than yesterday's, add the difference to profit
            if (prices[i] > prices[i - 1])
            {
                maxProfit += prices[i] - prices[i - 1]; // Accumulate profit from every upward price movement
            }
        }
        // Return the total profit from all possible transactions
        return maxProfit;
    }
};

int main()
{
    Solution sol;
    vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    vector<int> prices2 = {1, 2, 3, 4, 5};
    vector<int> prices3 = {7, 6, 4, 3, 1};

    // Test cases
    int profit1 = sol.maxProfit(prices1);
    int profit2 = sol.maxProfit(prices2);
    int profit3 = sol.maxProfit(prices3);

    // Output results
    printf("Max Profit for prices1: %d\n", profit1); // Expected: 7
    printf("Max Profit for prices2: %d\n", profit2); // Expected: 4
    printf("Max Profit for prices3: %d\n", profit3); // Expected: 0

    return 0;
}
