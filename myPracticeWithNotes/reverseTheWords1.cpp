// Reverse the words
/*
Input:
s = "the sky is blue"
Step 1: Reverse the entire string:

s = "eulb si yks eht"
Step 2: Process word by word:
Skip leading spaces

    Copy each word into position right
    Reverse each copied word (to fix it)
    Add a space
    Keep track of the write pointer (right) and start of next word (left)

Example flow:
After word	Operation	Intermediate s
"eulb"	reverse → "blue"	"blue si yks eht"
"si"	reverse → "is"	"blue is yks eht"
"yks"	reverse → "sky"	"blue is sky eht"
"eht"	reverse → "the"	"blue is sky the"

Finally trims the last extra space: s.resize(right - 1);
*/
#include <algorithm>
class Solution
{
public:
    string reverseWords(string s)
    {
        // Step 1: Reverse the entire string
        // s = "the sky is blue"
        reverse(s.begin(), s.end()); // Now words are in reverse order
        // s = "eulb si yks eht"

        int n = s.size();
        int i = 0;     // Pointer to read through the string
        int right = 0; // Pointer to write characters in place
        int left = 0;  // Marks the beginning of the current word in the new string

        while (i < n)
        {
            // Skip spaces
            while (i < n && s[i] == ' ')
                i++;

            // If we reached the end after skipping spaces, break
            if (i == n)
                break;

            // Start copying the word (non-space characters)
            // s = "eulb si yks eht"
            while (i < n && s[i] != ' ')
            {
                s[right++] = s[i++]; // Copy current word character to the write position
            }

            // Reverse the copied word in-place (to fix the word after full string reverse)
            reverse(s.begin() + left, s.begin() + right);

            // Add a single space after the word
            s[right++] = ' ';

            // Update left for the next word
            left = right;

            // Skip the space after word (because last i++ will have landed on space)
            i++;
        }

        // Remove the last extra space added (if any words were added)
        if (right > 0)
            s.resize(right - 1); // Remove trailing space

        return s;
    }
};

/*Less performant way*/
int main()
{
    string s = "the sky is blue";
    stringstream ss(s);
    string word;
    string result;

    // "Pop" each word from s and "append" to result
    while (ss >> word)
    {
        // append to front to reverse order
        result = word + " " + result;
    }

    // Remove trailing space
    if (!result.empty())
        result.pop_back();
}
