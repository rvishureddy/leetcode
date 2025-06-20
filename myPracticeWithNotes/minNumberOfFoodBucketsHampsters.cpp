// Minimum Number of Food Buckets to Feed the Hamsters
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Minimum Number of Food Buckets to Feed the Hamsters
LeetCode Problem No. 2086
https://leetcode.com/problems/minimum-number-of-food-buckets-to-feed-the-hamsters/
Medium

You are given a 0-indexed string hamsters where hamsters[i] is either:

'H' indicating that there is a hamster at index i, or
'.' indicating that index i is empty.
You will add some number of food buckets at the empty indices in order to feed the hamsters. A hamster can be fed if there is at least one food bucket to its left or to its right. More formally, a hamster at index i can be fed if you place a food bucket at index i - 1 and/or at index i + 1.

Return the minimum number of food buckets you should place at empty indices to feed all the hamsters or -1 if it is impossible to feed all of them.

Input: hamsters = "H..H"
Output: 2
Explanation: We place two food buckets at indices 1 and 2.
It can be shown that if we place only one food bucket, one of the hamsters will not be fed.

Input: hamsters = ".H.H."
Output: 1
Explanation: We place one food bucket at index 2.

Input: hamsters = ".HHH."
Output: -1
Explanation: If we place a food bucket at every empty index as shown, the hamster at index 2 will not be able to eat.

Notes
🔍 Intuition
We want to greedily place a bucket at the most optimal location for each hamster, while minimizing overlap and avoiding double-placing.

The best spot to put a bucket for an 'H' is at i + 1 if it’s a dot, because:

It feeds the hamster at i.

It might also feed the next hamster at i + 2.

But we have to be careful to avoid conflicts like placing buckets that don’t help or double feeding unnecessarily.
💡 Greedy Strategy
Loop through the string:

When you see an 'H':

First, check if a bucket is already placed at i - 1 (we can skip this hamster).

Next, try placing a bucket at i + 1, if it’s a '.' Mark it as 'B'.

If that’s not possible, try placing a bucket at i - 1, if it’s a '.'.

If neither is possible, return -1 (this hamster can’t be fed).
*/

class Solution
{
public:
    int minimumBuckets(string hamsters)
    {
        int n = hamsters.size();
        int buckets = 0;

        for (int i = 0; i < n; ++i)
        {
            if (hamsters[i] == 'H')
            {
                // First, check if a bucket is already placed at i - 1(we can skip this hamster).
                // Covers BH.....
                if (i > 0 && hamsters[i - 1] == 'B')
                {
                    continue;
                }

                // Next, try placing a bucket at i + 1, if it’s a '.' Mark it as 'B'.
                if (i + 1 < n && hamsters[i + 1] == '.')
                {
                    hamsters[i + 1] = 'B'; // Place a bucket at i+1
                    buckets++;
                }
                // If that’s not possible, try placing a bucket at i - 1, if it’s a '.'.
                // H..H
                else if (i > 0 && hamsters[i - 1] == '.')
                {
                    hamsters[i - 1] = 'B'; // Place a bucket at i-1
                    buckets++;
                }
                // If neither side is available, it's impossible to feed this hamster
                else
                {
                    return -1;
                }
            }
        }
        // Return the total number of buckets placed
        return buckets;
    }
};

int main()
{
    Solution sol;
    string hamsters1 = "H..H";
    cout << "Minimum Buckets for '" << hamsters1 << "': " << sol.minimumBuckets(hamsters1) << endl;

    string hamsters2 = ".H.H.";
    cout << "Minimum Buckets for '" << hamsters2 << "': " << sol.minimumBuckets(hamsters2) << endl;

    string hamsters3 = ".HHH.";
    cout << "Minimum Buckets for '" << hamsters3 << "': " << sol.minimumBuckets(hamsters3) << endl;

    // Add tests for edge cases
    string hamsters4 = "H";
    cout << "Minimum Buckets for '" << hamsters4 << "': " << sol.minimumBuckets(hamsters4) << endl;

    string hamsters5 = ".";
    cout << "Minimum Buckets for '" << hamsters5 << "': " << sol.minimumBuckets(hamsters5) << endl;

    string hamsters6 = "HH";
    cout << "Minimum Buckets for '" << hamsters6 << "': " << sol.minimumBuckets(hamsters6) << endl;

    string hamsters7 = "H.H";
    cout << "Minimum Buckets for '" << hamsters7 << "': " << sol.minimumBuckets(hamsters7) << endl;
    return 0;
}
