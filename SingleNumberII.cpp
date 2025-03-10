/*
Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.

You must implement a solution with a linear runtime complexity and use only constant extra space.

 

Example 1:

Input: nums = [2,2,3,2]
Output: 3
Example 2:

Input: nums = [0,1,0,1,0,1,99]
Output: 99
 

Constraints:

1 <= nums.length <= 3 * 104
-231 <= nums[i] <= 231 - 1
Each element in nums appears exactly three times except for one element which appears once.
*/

//Solution:

class Solution {
    public:
        int singleNumber(vector<int>& nums) {
            int ones = 0;
            int twos = 0;
            
            for (int num : nums) {
                // Update `twos` with bits that appear twice
                twos |= ones & num;
                // Update `ones` with bits that appear once
                ones ^= num;
                // Find bits that appear three times
                int threes = ones & twos;
                // Reset bits that appear three times
                ones &= ~threes;
                twos &= ~threes;
            }
            
            return ones;
        }
    };