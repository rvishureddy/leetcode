/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).



Example 1:

Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.


Constraints:

1 <= prices.length <= 105
0 <= prices[i] <= 105

Notes:
 This problem can be solved using dynamic programming.
As the rule says we can sell only after buying,
Lets start from left looking for minPrice and maxProfit
Then we can start from right looking for maxPrice and maxProfit

So our left pass array will store the max(maxProfit so far, current price - minPrice so far)
And in our right pass we travel from end to start looking for maxPrice and maxProfit
So our right pass array will store the max(maxProfit so far, maxPrice so far - current price)

If you take both left and right pass on Day 4,
In left pass we will have the max profit by buying at min price before Day 4 and selling on Day 4
In right pass we will have the max profit by buying at Day 4 and selling at max price after Day 4
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        if (n < 2)
            return 0;

        vector<int> left(n, 0), right(n, 0);
        int minPrice = prices[0];
        for (int i = 1; i < n; ++i)
        {
            minPrice = min(minPrice, prices[i]);
            // store the max(maxProfit so far, current price - minPrice so far)
            left[i] = max(left[i - 1], prices[i] - minPrice);
        }

        int maxPrice = prices[n - 1];
        for (int i = n - 2; i >= 0; --i)
        {
            maxPrice = max(maxPrice, prices[i]);
            // store the max(maxProfit so far, maxPrice so far - current price)
            right[i] = max(right[i + 1], maxPrice - prices[i]);
        }

        int maxProfit = 0;
        for (int i = 0; i < n; ++i)
        {
            // On Day i,
            // we combine the max profit by choosing the least price before this Day i and selling today from left[i]
            // and the max profit by choosing the highest price after this Day i and buying today from right[i]
            maxProfit = max(maxProfit, left[i] + right[i]);
        }

        return maxProfit;
    }
};

int main()
{
    Solution sol;
    vector<int> prices1 = {3, 3, 5, 0, 0, 3, 1, 4};
    cout << "Max Profit for prices1: " << sol.maxProfit(prices1) << endl; // Expected output: 6

    vector<int> prices2 = {1, 2, 3, 4, 5};
    cout << "Max Profit for prices2: " << sol.maxProfit(prices2) << endl; // Expected output: 4

    vector<int> prices3 = {7, 6, 4, 3, 1};
    cout << "Max Profit for prices3: " << sol.maxProfit(prices3) << endl; // Expected output: 0

    return 0;
}
