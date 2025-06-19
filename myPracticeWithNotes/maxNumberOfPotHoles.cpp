/*
You are given a string road, consisting only of characters "x" and ".", where each "x" denotes a pothole and each "." denotes a smooth road, along with an integer budget.

In one repair operation, you can repair n consecutive potholes for a price of n + 1.

Return the maximum number of potholes that can be fixed such that the sum of the costs of all repairs doesn't exceed the given budget.

Notes:
✅ Problem: Max Number of Potholes Repaired Within Budget
🧠 Problem Summary:
You're given a string road with 'x' representing potholes and '.' as smooth road, along with a budget.

Repair cost for n consecutive potholes = n + 1

You can only repair complete segments, but if budget is tight, you may partially repair the final segment.

Goal: Maximize the number of potholes repaired within the given budget.

🛠️ Approach Summary:
Traverse the string and find segments of consecutive 'x's.

Store each as {segment_length, segment_cost} in a vector.

Sort segments by ascending cost.

Greedily repair as many full segments as possible.

If one full segment exceeds budget, partially repair it:

You can fix budget_remaining - 1 potholes (since cost = potholes + 1).

🔍 Key Techniques:
Greedy Strategy: Choose cheapest segments first.

Segment Preprocessing: Add a . at the end to capture trailing segments.

Custom Comparator: Sort by cost to optimize budget usage.

Edge Handling:

Handles trailing potholes (push_back('.'))

Allows partial repair of final unaffordable segment

🧮 Time & Space:
Time: O(n log n) – due to sorting segment costs

Space: O(n) – worst case all 1-length pothole segments

📌 Notes for Interviews:
This problem is a classic greedy pattern with twist: full vs. partial repair trade-off.

Be ready to explain why you sort by cost, and how partial repair logic works.

Can lead into follow-up system design questions about batching, budget constraints, or real-world sensor signal prioritization.
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxNumberOfPotHoles(string road, int budget)
    {
        road.push_back('.');                // Append a dot to handle the last segment of potholes
        int k = 0;                          // Count of potholes
        vector<pair<int, int>> repairCosts; // Store costs of repairing segments
        for (auto c : road)
        {
            if (c == 'x')
            {
                ++k; // Increment pothole count
            }
            else
            {
                if (k > 0)
                {
                    // Calculate cost for the segment of potholes
                    repairCosts.push_back({k, k + 1});
                }
                k = 0; // Reset count for next segment
            }
        }
        // Now that i have cost vector we have to sort it by max potholes that can be repaired.
        sort(repairCosts.begin(), repairCosts.end(), [](const pair<int, int> &a, const pair<int, int> &b)
             {
                 return a.second < b.second; // Sort by cost
             });

        int totalCost = 0;
        int maxPotholes = 0;
        for (const auto &poth : repairCosts)
        {
            if (totalCost + poth.second <= budget)
            {
                totalCost += poth.second;  // Add cost of repairing this segment
                maxPotholes += poth.first; // Add number of potholes repaired
            }
            else
            {
                // If adding whole segment exceeds lets take Part of the segment to fit in budget
                int partialSegment = budget - totalCost - 1; // -1 because we need to account for the cost of repairing
                maxPotholes += partialSegment;               // Add the number of potholes we can repair with the remaining budget
                break;                                       // If budget exceeded, stop processing
            }
        }

        return maxPotholes; // Return the maximum number of potholes repaired
    }
};

// Example usage:
int main()
{
    Solution solution;
    string road = "xxx..xxx.xxx..xxxxxx..xxx";
    int budget = 10;
    int result = solution.maxNumberOfPotHoles(road, budget);
    // Output the result
    cout << "Maximum potholes repaired: " << result << endl;
    return 0;
}
