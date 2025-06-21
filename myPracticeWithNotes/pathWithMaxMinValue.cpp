// Path With Maximum Minimum Value
/*
Medium: leetcode 1102
Given a 2D grid of integers, find the path from the top-left corner to the bottom-right
corner that maximizes the minimum value along the path.

This means we want to avoid paths that go through very small numbers, if possible.
In this problem, we have a 2-dimensional grid represented by an m x n matrix.
 The goal is to find a path from the top-left corner (0, 0) to the
 bottom-right corner (m - 1, n - 1) such that the minimum value encountered on
 this path is as high as possible. In other words, we are trying to maximize the
  minimum value. While moving through the grid, we can move in any of the
  four cardinal directions: up, down, left, or right.
  The 'score' of a path is defined as the smallest number on that path.
  For example, if a path goes through the numbers [8, 4, 5, 9],
the path's score would be 4, since that is the smallest number encountered on the path.
Example:
Input: grid = [[5,4,5],[1,2,6],[7,4,6]]
Output: 4
Input: [[5,4,5],[1,2,6],[7,4,6]]
Output: 4

Input: [[2,2,1,2,2,2],[1,2,2,2,1,2]]
Output: 2

Input: [[3,4,6,3,4],[0,2,1,1,7],[8,8,3,2,7],[3,2,4,9,8],[4,1,2,0,0],[4,6,5,4,3]]
Output: 3


Evaluate my approach
At (i,j) row, col i look around me to find the max value (assume we have another a visited vector)
And we keep track of our path and min value in that path
But i am not sure if this approach we can reach the m-1, n-1 that is our destination

Your approach is on the right track conceptually,
but it has some critical limitations.
Let's walk through it and evaluate where it works and where it may fall short.

🔍 Your Approach Summary:
At position (i, j), you look around (up, down, left, right) for the neighbor with the highest value (among unvisited ones).

You move to that neighbor.

While moving, you track the path and maintain the minimum value seen on this path.

You stop when you reach (m-1, n-1).

✅ Strengths:
This greedy strategy intuitively tries to avoid small numbers, which aligns with the goal of maximizing the minimum value.

You're maintaining a visited array, which prevents cycles and revisits.

❌ Weaknesses (Why This Might Fail):
Greedy ≠ Optimal in this problem:

Just because a neighbor has a high value now doesn't mean it leads to the best overall path.

You might choose a high-value cell early on and get stuck later with low values.

The best path might involve a lower-valued step early to reach a better region.

Can Miss Valid Paths:

You only explore the highest-valued neighbor,
but there could be multiple viable paths,
and ignoring the others might cause you to miss the optimal path to (m-1, n-1).

No Backtracking or State Comparison:

If you reach a cell with a worse minimum score than a previously discovered path to that same cell, you're not reconsidering it.

📉 Example Where It Might Fail:
plaintext
Copy
Edit
Start at (0, 0): 5
Neighbors: (0, 1)=4, (1, 0)=1 → pick (0, 1)
Then maybe stuck at lower-valued paths,
but better route might have started at (1, 0) → (2, 0)=7 → (2, 1)=4 → ...
This is a classic scenario where greedy fails to explore better long-term options.


*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int maximumMinimumPath(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();

        // Track visited cells to avoid re-processing
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // Max-heap (priority queue): store tuples of (min_value_along_path, x, y)
        // We use negative value because C++ priority_queue is a max-heap by default
        priority_queue<tuple<int, int, int>> pq;

        // Start from (0, 0) with the starting value
        pq.push({grid[0][0], 0, 0});
        visited[0][0] = true;

        // Possible movement directions: right, down, up, left
        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

        while (!pq.empty())
        {
            auto [minVal, x, y] = pq.top(); // Current best candidate cell
            pq.pop();

            // If we reached bottom-right cell, return the max-min value found
            if (x == m - 1 && y == n - 1)
                return minVal;

            for (auto [dx, dy] : dirs)
            {
                int nx = x + dx;
                int ny = y + dy;

                // Check if the new coordinates are valid and unvisited
                if (nx >= 0 && ny >= 0 && nx < m && ny < n && !visited[nx][ny])
                {
                    visited[nx][ny] = true;

                    // The new path's minimum value is the min of current and next cell
                    int nextMin = min(minVal, grid[nx][ny]);

                    pq.push({nextMin, nx, ny});
                }
            }
        }

        return -1; // Edge case: path doesn't exist (shouldn't happen with valid input)
    }
};
