/*
A string s is called happy if it satisfies the following conditions:

s only contains the letters 'a', 'b', and 'c'.
s does not contain any of "aaa", "bbb", or "ccc" as a substring.
s contains at most a occurrences of the letter 'a'.
s contains at most b occurrences of the letter 'b'.
s contains at most c occurrences of the letter 'c'.
Given three integers a, b, and c, return the longest possible happy string. If there are multiple longest happy strings, return any of them. If there is no such string, return the empty string "".

A substring is a contiguous sequence of characters within a string.



Example 1:

Input: a = 1, b = 1, c = 7
Output: "ccaccbcc"
Explanation: "ccbccacc" would also be a correct answer.
Example 2:

Input: a = 7, b = 1, c = 0
Output: "aabaa"
Explanation: It is the only correct answer in this case.

🔍 Key Idea:
At every step, greedily choose the character with the most remaining count — unless it would cause 3 in a row.

If it would cause 3 in a row, use the next best (second most frequent character) instead.

🛠️ Data Structure:
Use a max heap (priority queue) to always pick the character with the most remaining count.

🔁 Algorithm (Greedy + Priority Queue):
Put (count, char) pairs into a max heap (using negative count for max-heap behavior).

While the heap is not empty:

Pop the char with highest remaining count.

If the last two characters in the result are the same as this character, we can't use it. Try the next one.

If we can't use any character, we're done.

Else, use the character, update its count, and push it back into the heap if it still has remaining count.


*/

#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

class Solution
{
public:
    string longestHappyString(int a, int b, int c)
    {
        // Result string to build the happy string
        string result = "";
        // Max heap to store counts of characters with their respective letters
        priority_queue<pair<int, char>> maxHeap;
        // Push the counts and characters into the max heap
        if (a > 0)
            maxHeap.push({a, 'a'});
        if (b > 0)
            maxHeap.push({b, 'b'});
        if (c > 0)
            maxHeap.push({c, 'c'});

        while (!maxHeap.empty())
        {
            // Get the character with the maximum count
            auto [c1, ch1] = maxHeap.top();
            maxHeap.pop();
            // Check if the last two characters in the result are the same as this character

            //  int len = result.size();
            // if (len >= 2 && result[len - 1] == ch1 && result[len - 2] == ch1)
            if (result.ends_with(string(2, ch1))) // C++20 feature to check if the last two characters are same as ch1
            {
                // If so, we cannot use this character, we need to try the next one
                if (maxHeap.empty())
                {
                    // If there's no other character to use, we break out of the loop
                    break;
                }
                // Get the next character with the second highest count
                auto [c2, ch2] = maxHeap.top();
                maxHeap.pop();
                // Append the second character to the result
                result += ch2;
                // If the second character still has remaining count, push it back into the heap
                if (--c2 > 0)
                {
                    maxHeap.push({c2, ch2});
                }
                // Push the first character back into the heap
                maxHeap.push({c1, ch1});
            }
            else
            {
                // If we can use the first character, append it to the result
                result += ch1;
                // Decrease its count and push it back into the heap if it still has remaining count
                if (--c1 > 0)
                {
                    maxHeap.push({c1, ch1});
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution sol;
    int a = 1, b = 1, c = 7;
    cout << "Longest Happy String: " << sol.longestHappyString(a, b, c) << endl;

    a = 7, b = 1, c = 0;
    cout << "Longest Happy String: " << sol.longestHappyString(a, b, c) << endl;

    return 0;
}
