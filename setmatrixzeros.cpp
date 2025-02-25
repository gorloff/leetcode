/*
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.

 

Example 1:


Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
Example 2:


Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 

Constraints:

m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-231 <= matrix[i][j] <= 231 - 1
 

Follow up:

A straightforward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/

//Solution:

class Solution {
    public:
        void setZeroes(vector<vector<int>>& matrix) {
            int rows = matrix.size();
            int cols = matrix[0].size();
    
            // Flags to tell if zero is needed
            bool zeroFirstRow = false;
            bool zeroFirstCol = false;
    
            // Check for zero 
            for (int c = 0; c < cols; c++) {
                if (matrix[0][c] == 0) {
                    zeroFirstRow = true;
                    break;
                }
            }
    
            // Check first col for zero
            for (int r = 0; r < rows; r++) {
                if (matrix[r][0] == 0) {
                    zeroFirstCol = true;
                    break;
                }
            }
    
            // Mark rows and columns for zeros
            for (int r = 1; r < rows; r++) {
                for (int c = 1; c < cols; c++) {
                    if (matrix[r][c] == 0) {
                        matrix[r][0] = 0;  // Mark first col for this row
                        matrix[0][c] = 0;  // Mark first row for col
                    }
                }
            }
    
            // zero out cells based on mark
            for (int r = 1; r < rows; r++) {
                for (int c = 1; c < cols; c++) {
                    if (matrix[r][0] == 0 || matrix[0][c] == 0) {
                        matrix[r][c] = 0;
                    }
                }
            }
    
            // Zero out first row
            if (zeroFirstRow) {
                for (int c = 0; c < cols; c++) {
                    matrix[0][c] = 0;
                }
            }
    
            // Zero out first col
            if (zeroFirstCol) {
                for (int r = 0; r < rows; r++) {
                    matrix[r][0] = 0;
                }
            }
        }
    };