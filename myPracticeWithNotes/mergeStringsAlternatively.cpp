/*
You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.

Return the merged string.



Example 1:

Input: word1 = "abc", word2 = "pqr"
Output: "apbqcr"
Explanation: The merged string will be merged as so:
word1:  a   b   c
word2:    p   q   r
merged: a p b q c r
*/

#include <iostream>
#include <string>

using namespace std;

/*
Key Points for Revision:

1. Problem: Merge two strings by alternating their characters. If one string is longer, append the rest at the end.

2. Approach:
    - Use two indices to iterate through both strings.
    - Add characters alternately to the result string.
    - After one string ends, append the remaining characters from the other.

3. Edge Cases:
    - Strings of different lengths.
    - One or both strings could be empty.

4. Complexity:
    - Time: O(n + m), where n and m are the lengths of the two strings.
    - Space: O(n + m) for the merged string.

5. STL Usage:
    - Use std::string for easy character appending.
    - Use string::size() for length checks.

6. Readability:
    - Clear variable names (i, j for indices, merged for result).
    - Separate loops for alternating and appending remaining characters.

7. Testing:
    - Test with equal length strings, different lengths, and empty strings.
*/
class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        string merged;
        int i = 0, j = 0;

        // Merge characters from both strings alternately
        while (i < word1.size() && j < word2.size())
        {
            merged += word1[i++];
            merged += word2[j++];
        }

        // Append remaining characters from word1, if any
        while (i < word1.size())
        {
            merged += word1[i++];
        }

        // Append remaining characters from word2, if any
        while (j < word2.size())
        {
            merged += word2[j++];
        }

        return merged;
    }
};
int main()
{
    Solution solution;
    string word1 = "abc";
    string word2 = "pqr";
    string result = solution.mergeAlternately(word1, word2);
    cout << "Merged String: " << result << endl; // Output: "apbqcr"
    return 0;
}
