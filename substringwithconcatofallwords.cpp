/*
You are given a string s and an array of strings words. All the strings of words are of the same length.

A concatenated string is a string that exactly contains all the strings of any permutation of words concatenated.

For example, if words = ["ab","cd","ef"], then "abcdef", "abefcd", "cdabef", "cdefab", "efabcd", and "efcdab" are all concatenated strings. "acdbef" is not a concatenated string because it is not the concatenation of any permutation of words.
Return an array of the starting indices of all the concatenated substrings in s. You can return the answer in any order.

 

Example 1:

Input: s = "barfoothefoobarman", words = ["foo","bar"]

Output: [0,9]

Explanation:

The substring starting at 0 is "barfoo". It is the concatenation of ["bar","foo"] which is a permutation of words.
The substring starting at 9 is "foobar". It is the concatenation of ["foo","bar"] which is a permutation of words.

Example 2:

Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]

Output: []

Explanation:

There is no concatenated substring.

Example 3:

Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]

Output: [6,9,12]

Explanation:

The substring starting at 6 is "foobarthe". It is the concatenation of ["foo","bar","the"].
The substring starting at 9 is "barthefoo". It is the concatenation of ["bar","the","foo"].
The substring starting at 12 is "thefoobar". It is the concatenation of ["the","foo","bar"].

 

Constraints:

1 <= s.length <= 104
1 <= words.length <= 5000
1 <= words[i].length <= 30
s and words[i] consist of lowercase English letters.
*/


//Solution:
class Solution {
    public:
        vector<int> findSubstring(string s, vector<string>& words) {
            vector<int> result;
    
            // Early exit if words are empty or s is too short for any concatenation
            if (s.empty() || words.empty() || words[0].empty()) {
                return result;
            }
    
            int wordLength = words[0].length();  // Length of each word
            int numWords = words.size();         // Total number of words
            int totalLength = wordLength * numWords;  // Length of the concatenated substring
    
            // Build a frequency map
            unordered_map<string, int> wordCount;
            for (const string& word : words) {
                wordCount[word]++;
            }
    
            // Try every possible starting point 
            for (int i = 0; i < wordLength; i++) {
                int left = i;  // Left pointer of window
                int right = i; // Right pointer of window
                unordered_map<string, int> currentCount; 
                int count = 0; 
    
                
                // Sliding window: moving the right pointer
                while (right + wordLength <= s.length()) {
                    string currentWord = s.substr(right, wordLength); // Extract current word
                    right += wordLength;  // Move right pointer
                    
                    // If the word is in the word list
                    if (wordCount.find(currentWord) != wordCount.end()) {
                        currentCount[currentWord]++;
                        count++;
                        
                        // If we have more instances of a word than allowed, move the left pointer
                        while (currentCount[currentWord] > wordCount[currentWord]) {
                            string leftWord = s.substr(left, wordLength);
                            currentCount[leftWord]--;
                            left += wordLength; // Move left pointer
                            count--;
                        }
    
                        // If count equals the number of words, we found a valid substring
                        if (count == numWords) {
                            result.push_back(left);  // Add the start index to the result
                        }
                    } else {
                        // If the word is not in the list, reset the window
                        currentCount.clear();
                        count = 0;
                        left = right;
                    }
                }
            }
            
            return result; // Return the list of starting indices
        }
    };