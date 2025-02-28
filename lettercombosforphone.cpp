/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.


 

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = ""
Output: []
Example 3:

Input: digits = "2"
Output: ["a","b","c"]
 

Constraints:

0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].
*/

//Solution

class Solution {
    public:
        vector<string> letterCombinations(string digits) {
            //base case
            if(digits.empty()){
                return {};
            }
            
            //mapping
            vector<string> digitToLetters = {
                " ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
            };

            vector<string> result;
            string currentCombination;

            backtrack(digits, 0, currentCombination, result, digitToLetters);
            return result;
        }
    private:
        void backtrack(const string &digits, int index, string &currentCombination, vector<string> &result, const vector<string> &digitToLetters){
            //if combo is same length as digits, add to result
            if(index == digits.size()){
                result.push_back(currentCombination);
                return;
            }

            //get letters
            int digit = digits[index] - '0';
            string letters = digitToLetters[digit];


            //explore possible letters for current digit
            for(char letter : letters){
                currentCombination.push_back(letter);
                backtrack(digits, index + 1, currentCombination, result, digitToLetters);
                currentCombination.pop_back();
            }
        }
    };