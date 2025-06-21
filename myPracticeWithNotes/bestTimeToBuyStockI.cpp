// bestTimeTobuyStockI
/*
You can buy and sell the stock Any number of times,
but you must sell the stock before you buy again.
Simple greedy approach:
If the price goes up tomorrow, we can make a profit by buying today and selling tomorrow.

That means:
You don't even need to track buys/sells explicitly
Just accumulate every positive difference in prices.

1, 2, 3, 4, 5
4 is the max profit.

1 2 1 4 20
20 is the max profit.

*/
#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int profit = 0;
    for (int i = 1; i < prices.size(); ++i)
    {
        if (prices[i] > prices[i - 1])
        {
            profit += prices[i] - prices[i - 1]; // Buy yesterday, sell today
        }
    }
    return profit;
}

int main()
{
    vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    cout << "Max Profit for prices1: " << maxProfit(prices1) << endl; // Expected output: 7

    vector<int> prices2 = {1, 2, 3, 4, 5};
    cout << "Max Profit for prices2: " << maxProfit(prices2) << endl; // Expected output: 4

    vector<int> prices3 = {7, 6, 4, 3, 1};
    cout << "Max Profit for prices3: " << maxProfit(prices3) << endl; // Expected output: 0

    vector<int> prices4 = {1, 2, 1, 4, 20};
    cout << "Max Profit for prices4: " << maxProfit(prices4) << endl; // Expected output: 20
    return 0;
}
