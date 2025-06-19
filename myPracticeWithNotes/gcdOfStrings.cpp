/* GCD of strings */
/*
🧠 Notes: Greatest Common Divisor of Strings
Concept:

If a string x divides both str1 and str2, then both strings can be expressed as multiples of x.

Why str1 + str2 == str2 + str1?

This checks if the order of repetition is consistent.

If both concatenations yield the same result, it implies both strings are composed of the same base string repeated some number of times.

If not equal:

No such base string exists → return "".

GCD Logic:

If base string exists, its length must divide the lengths of both str1 and str2.

Therefore, compute gcd(str1.size(), str2.size()) and extract the prefix of that length.

Final Step:

return str1.substr(0, gcdLength); — gives the actual repeating base string.

Time Complexity:

O(n + m), linear in total length of both strings.

Edge Cases:

Completely unrelated strings like "LEET" and "CODE".
*/
#include <string>
#include <numeric> // for std::gcd
using namespace std;

class Solution
{
public:
    string gcdOfStrings(string str1, string str2)
    {
        // Check if they have non-zero GCD string.
        if (str1 + str2 != str2 + str1)
        {
            return "";
        }

        // Get the GCD of the two lengths.
        int gcdLength = gcd(str1.size(), str2.size());
        return str1.substr(0, gcdLength);
    }
};

// Example usage:
int main()
{
    Solution solution;
    string str1 = "ABCABC";
    string str2 = "ABC";
    string result = solution.gcdOfStrings(str1, str2);
    // Expected output: "ABC"
    return 0;
}
