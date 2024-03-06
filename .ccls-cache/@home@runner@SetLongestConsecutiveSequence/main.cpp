#include "LongestSequence.h"
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;


int longestConsecutiveSequence(const vector<int>& nums) {
    //   +=====================================================+
    //   |                 WRITE YOUR CODE HERE                |
    //   | Description:                                        |
    //   | - This function finds the longest consecutive       |
    //   |   sequence of integers in a given array.            |
    //   | - It uses an unordered_set for quick look-up.       |
    //   | - Loop through each unique number in the set.       |
    //   | - For each number, check its sequence length.       |
    //   | - Update 'longestStreak' if a longer sequence is    |
    //   |   found.                                            |
    //   |                                                     |
    //   | Return type: int                                    |
    //   |                                                     |
    //   | Tips:                                               |
    //   | - 'numSet' stores unique numbers from 'nums'.       |
    //   | - 'longestStreak' keeps track of the longest        |
    //   |   sequence found so far.                            |
    //   | - Use 'find' method for quick look-up in set.       |
    //   | - Check output from Test.cpp in "User logs".        |
    //   +=====================================================+
     unordered_set<int> numSet(nums.begin(), nums.end()); // Store unique numbers
    int longestStreak = 0; // Track the longest sequence

    for (int num : numSet) {
        // If the current number is the start of a sequence
        if (numSet.find(num - 1) == numSet.end()) {
            int currentNum = num;
            int currentStreak = 1;

            // Count consecutive numbers
            while (numSet.find(currentNum + 1) != numSet.end()) {
                currentNum += 1;
                currentStreak += 1;
            }

            // Update longest streak if current streak is longer
            longestStreak = max(longestStreak, currentStreak);
        }
    }

    return longestStreak; // Return the length of the longest sequence
}