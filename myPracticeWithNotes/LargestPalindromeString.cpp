/*
You are given a string num consisting of digits only.

Return the largest palindromic integer (in the form of a string) that can be formed using digits taken from num. It should not contain leading zeroes.

Notes:

You do not need to use all the digits of num, but you must use at least one digit.
The digits can be reordered.

Example 1:
Input: num = "444947137"
Output: "7449447"
Explanation:
Use the digits "4449477" from "444947137" to form the palindromic integer "7449447".
It can be shown that "7449447" is the largest palindromic integer that can be formed.

Example 2:
Input: num = "00009"
Output: "9"
Explanation:
It can be shown that "9" is the largest palindromic integer that can be formed.
Note that the integer returned should not contain leading zeroes.

Notes:
📌 Key Steps in Your Code:
Count digit frequency using vector<int> freq(10, 0).

***Important: Looping from 9 to 0, build the left side of the palindrome.

Build left side of palindrome from highest digits down.

Add freq[i] / 2 copies of digit i.

Skip leading 0s unless no other digit was used.

Pick middle digit (odd-count) if exists.

Mirror left to create right side.

If no left, but middle is '0' or any digit, return middle.
0099

009
00099
Time: O(N + 10 log 10) ≈ O(N)
Space: O(1) (fixed-size frequency array)
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string largestPalindromic(string num)
    {
        // First lets get the frequency of each digit
        vector<int> freq(10, 0);
        for (char c : num)
        {
            freq[c - '0']++;
        }

        // Now let's build the largest palindromic number
        string left = "", middle = "";
        for (int i = 9; i >= 0; i--)
        {
            // cout << "Frequency of " << i << ": " << freq[i] << endl;
            if (freq[i] % 2 == 1 && middle.empty())
            {
                middle = to_string(i); // Choose the odd digit for the middle
            }

            // If we are at digit 0 and no middle digit is set, skip adding leading zeroes
            if (left.empty() && i == 0)
            {
                if (middle.empty())
                {
                    // Special case if we just have "00" as input
                    // If no other digits are present, we can use 0 as the middle
                    middle = "0";
                }

                // If we are at digit 0 and no middle digit is set, skip adding leading zeroes
                continue;
            }
            left += string(freq[i] / 2, '0' + i); // Append half of the even digits
        }
        // Lets print left, middle here
        // cout << "Left part: " << left << endl;
        // cout << "Middle part: " << middle << endl;

        // If we have a left part, we can form a palindrome
        if (!left.empty())
        {
            // Form the largest palindrome
            return left + middle + string(left.rbegin(), left.rend());
        }
        // If no left part, return the middle digit (if exists)
        return middle;
    }
};

// Example usage:
int main()
{
    Solution solution;
    string num = "00099";
    string result = solution.largestPalindromic(num);
    // Expected output: "90009"
    // Print the result
    printf("Result:%s\n", result.c_str());
    return 0;
}
