/*
    ✅ NOTES: Merging Two Sorted Arrays In-Place (Leetcode-style)

    🔸 Problem Summary:
        - nums1 has m sorted elements followed by n empty (0) slots
        - nums2 has n sorted elements
        - Merge nums2 into nums1 as one sorted array (in-place)

    🔹 Key Points:
        1. Merge from the end (backward) to avoid overwriting nums1's values.
        2. Use three pointers:
           - i: end of actual nums1 elements (m - 1)
           - j: end of nums2 (n - 1)
           - res: last index of nums1 (m + n - 1)
        3. Handle edge cases:
           - If nums2 is empty, no action needed.
           - If nums1 is empty (m == 0), copy nums2 into nums1.
        4. After merging common parts, copy remaining nums2 elements (if any).
        5. No need to copy remaining nums1 elements — they are already in place.

    🧠 Tip: This is a common two-pointer technique used in merging problems.
    
    tags: #array #string #arrayString
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int i = m - 1, j = n - 1;  // i: pointer for nums1, j: for nums2

        // If nums2 is empty, nothing to merge
        if (n == 0) {
            return;
        }

        // If nums1 is empty (has 0 valid elements), just copy nums2
        if (m == 0) {
            nums1 = nums2;
            return;
        }

        int res = m + n - 1;  // res: position to insert next largest value

        // Merge from the end of both arrays
        while (i >= 0 && j >= 0) {
            if (nums1[i] >= nums2[j]) {
                nums1[res--] = nums1[i--];
            } else {
                nums1[res--] = nums2[j--];
            }
        }

        // If any elements are left in nums2, copy them
        while (j >= 0) {
            nums1[res--] = nums2[j--];
        }

        // Remaining nums1 elements (if any) are already in correct place
    }
};
