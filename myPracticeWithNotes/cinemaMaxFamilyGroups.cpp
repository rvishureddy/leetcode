/*
A cinema has n rows of seats, numbered from 1 to n and there are ten seats in each row, labelled from 1 to 10 as shown in the figure above.

Given the array reservedSeats containing the numbers of seats already reserved, for example, reservedSeats[i] = [3,8] means the seat located in row 3 and labelled with 8 is already reserved.

Return the maximum number of four-person groups you can assign on the cinema seats. A four-person group occupies four adjacent seats in one single row. Seats across an aisle (such as [3,3] and [3,4]) are not considered to be adjacent, but there is an exceptional case on which an aisle split a four-person group, in that case, the aisle split a four-person group in the middle, which means to have two people on each side.

 1 2 3   4 5 6 7   8 9 10
 _ _ _   _ _ _ _   _ _ _

Example 1:

Input: n = 3, reservedSeats = [[1,2],[1,3],[1,8],[2,6],[3,1],[3,10]]
Output: 4
Explanation: The figure above shows the optimal allocation for four groups, where seats mark with blue are already reserved and contiguous seats mark with orange are for one group.
Example 2:

Input: n = 2, reservedSeats = [[2,1],[1,8],[2,6]]
Output: 2
Example 3:

Input: n = 4, reservedSeats = [[4,3],[1,4],[4,6],[1,7]]
Output: 4


Constraints:

1 <= n <= 10^9
1 <= reservedSeats.length <= min(10*n, 10^4)
reservedSeats[i].length == 2
1 <= reservedSeats[i][0] <= n
1 <= reservedSeats[i][1] <= 10
All reservedSeats[i] are distinct.

We are given:

n rows in a cinema.

Each row has 10 seats labeled 1 to 10.

A group of 4 people needs 4 adjacent seats in the same row, but cannot span across aisles (between seat 3–4 or 7–8).

Valid group blocks are:

Left block: seats 2,3,4,5

Right block: seats 6,7,8,9

Middle block: seats 4,5,6,7 (this is allowed even though it straddles an aisle)

So a reserved seat at column col will set bit 1 << col.

🎯 Predefined Block Masks:
                         10 9 8  7 6 5 4  3 2 1   Bits
Left block (seats 2-5):   0 0 0  0 0 1 1  1 1 0 → bits 2 to 5
Middle block (seats 4-7): 0 0 0  1 1 1 1  0 0 0 → bits 4 to 7
Right block (seats 6-9):  0 1 1  1 1 0 0  0 0 0 → bits 6 to 9

We check if the corresponding bits in the mask are unset → that block is available.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <bitset> // Include bitset for binary representation
using namespace std;

class Solution
{
public:
    int maxNumberOfFamilies(int n, vector<vector<int>> &reservedSeats)
    {
        // rowMap will only store the rows that have reserved seats
        // key: row number, value: 10-bit mask representing reserved seats in that row
        // So we don't need to store all rows, just the ones with reserved seats
        // Since this is a hash we do not have to worry about the row starting from 0
        // We are using rows as 1 to n, so we can directly use the row number as key
        unordered_map<int, int> rowMap;
        // Step 1: Build bitmask for each row with reserved seats
        for (const auto &seat : reservedSeats)
        {
            int row = seat[0];
            int col = seat[1];
            // so first left shift 1 to the left by (col - 1) positions
            // This sets the bit corresponding to the column in the row's bitmask
            // OR it with the existing row's bitmask to mark the seat as reserved
            rowMap[row] |= (1 << (col - 1));
        }

        int totalGroups = 0;
        // Step 2: Calculate maximum groups for each row
        // We only calculate for rows that have reserved seats
        // We can have at most 2 groups per row if there are no reserved seats in the blocks
        for (const auto &row : rowMap)
        {
            int rowSeatMask = row.second;
            // Check for left block (seats 2-5)
            // if any of the bits 2, 3, 4, or 5 are set, then AND will be non-zero
            // That means the left block is not available
            // If the result of rowSeatMask & 0b0000011110 is 0,
            // it means none of those seats are reserved, and we can place a family.
            // So we negate it with ! to get a true when the seats are available.
            bool left = !(rowSeatMask & 0b0000011110);   // seats 2-5
            bool right = !(rowSeatMask & 0b0111100000);  // seats 6-9
            bool middle = !(rowSeatMask & 0b0001111000); // seats 4-7

            if (left && right)
            {
                // If both left and right blocks are available, we can place 2 groups
                totalGroups += 2;
            }
            else if (left || right || middle)
            {
                // If any one of the blocks is available, we can place 1 group
                totalGroups += 1;
            }
            std::cout << "Row " << row.first << ": Reserved Mask = " << rowSeatMask
                      << " (binary: " << std::bitset<10>(rowSeatMask) << ") Total Groups = " << totalGroups << std::endl;
        }
        // Step 3: Add full rows (no reserved seats)
        // Each full row can have 2 groups (left and right blocks)
        totalGroups += (n - rowMap.size()) * 2;
        return totalGroups;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> reservedSeats1 = {{1, 2}, {1, 3}, {1, 8}, {2, 6}, {3, 1}, {3, 10}};
    int n1 = 3;
    int result1 = sol.maxNumberOfFamilies(n1, reservedSeats1);
    // Expected output: 4
    printf("Max number of families for n=%d: %d\n", n1, result1);

    vector<vector<int>> reservedSeats2 = {{2, 1}, {1, 8}, {2, 6}};
    int n2 = 2;
    int result2 = sol.maxNumberOfFamilies(n2, reservedSeats2);
    // Expected output: 2
    printf("Max number of families for n=%d: %d\n", n2, result2);

    vector<vector<int>> reservedSeats3 = {{4, 3}, {1, 4}, {4, 6}, {1, 7}};
    int n3 = 4;
    int result3 = sol.maxNumberOfFamilies(n3, reservedSeats3);
    // Expected output: 4
    printf("Max number of families for n=%d: %d\n", n3, result3);

    return 0;
}
