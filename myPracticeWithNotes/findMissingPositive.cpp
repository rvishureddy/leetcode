/*
findMissingPositive
Given an unsorted integer array nums.
Return the smallest positive integer that is not present in nums.
You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.
Example 1:

Input: nums = [1,2,0]
Output: 3
Explanation: The numbers in the range [1,2] are all in the array.
Example 2:

Input: nums = [3,4,-1,1]
Output: 2
Explanation: 1 is in the array but 2 is missing.
Example 3:

Input: nums = [7,8,9,11,12]
Output: 1
Explanation: The smallest positive integer 1 is missing.

****Missing Positive Integer****
Explanation: If there was no O(n) constraint, we could sort the array and then scan
through it to find the first missing positive integer.
However, we need to do this in O(n) time and O(1) space.
We can achieve this by rearranging the elements in the array such that each number
is placed at its correct index => We’ll try to place value x at index x - 1.

Step 1: Ignore invalid numbers (≤ 0 and > n)
Valid values in range [1, n=3] are: 1, 2
Step 2: Rearranged array (optional in logic, helpful for understanding):
We’ll try to place value x at index x - 1.

1 should be at index 0

2 at index 1

0 is ignored

Resulting array could look like:
[1, 2, 0]
Step 3: Scan from left to right:
nums[0] == 1 ✅

nums[1] == 2 ✅

nums[2] != 3 ❌

So the first missing positive integer is 3.

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int n = nums.size();

        // Step 1: Put each number in its correct position if possible
        for (int i = 0; i < n; ++i)
        {
            // nums[i] should be placed at nums[nums[i] - 1] and continue to swap until
            // the current number is either out of range or already in the correct position.
            // We also ensure that we don't swap a number to its own position again.
            // This ensures that we only swap valid numbers (1 to n) and avoid infinite loops
            // or unnecessary swaps.

            // Step 1 : Ignore invalid numbers(≤ 0 and > n)
            // because we are looking for the smallest positive integer.
            //          Valid values in range[1, n = 3] are : 1, 2
            // Input: nums = [7,8,9,11,12] n = 5
            // Output: 1
            // Explanation: The smallest positive integer 1 is missing.

            while (nums[i] >= 1 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
            {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        // Step 2: Scan through the array and find the first index i such that nums[i] != i + 1
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] != i + 1)
            {
                return i + 1;
            }
        }

        // Step 3: All values are in correct positions, so return n + 1
        return n + 1;
    }
};

int main()
{
    Solution sol;
    vector<int> nums1 = {1, 2, 0};
    vector<int> nums2 = {3, 4, -1, 1};
    vector<int> nums3 = {7, 8, 9, 11, 12};

    int result1 = sol.firstMissingPositive(nums1);
    int result2 = sol.firstMissingPositive(nums2);
    int result3 = sol.firstMissingPositive(nums3);

    // Expected outputs: 3, 2, 1
    printf("First Missing Positive for [1, 2, 0]: %d\n", result1);
    printf("First Missing Positive for [3, 4, -1, 1]: %d\n", result2);
    printf("First Missing Positive for [7, 8, 9, 11, 12]: %d\n", result3);

    return 0;
}
