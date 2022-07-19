//Given a string s, find the length of the longest substring without repeating 
//characters. 
//
// 
// Example 1: 
//
// 
//Input: s = "abcabcbb"
//Output: 3
//Explanation: The answer is "abc", with the length of 3.
// 
//
// Example 2: 
//
// 
//Input: s = "bbbbb"
//Output: 1
//Explanation: The answer is "b", with the length of 1.
// 
//
// Example 3: 
//
// 
//Input: s = "pwwkew"
//Output: 3
//Explanation: The answer is "wke", with the length of 3.
//Notice that the answer must be a substring, "pwke" is a subsequence and not a 
//substring.
// 
//
// 
// Constraints: 
//
// 
// 0 <= s.length <= 5 * 10⁴ 
// s consists of English letters, digits, symbols and spaces. 
// 
// Related Topics Hash Table String Sliding Window 👍 26452 👎 1149


//leetcode submit region begin(Prohibit modification and deletion)
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxL = 0, idx = 0, head = -1;
        unordered_map<char, int> last_occur;
        unordered_map<char, int>::iterator itr;
        for (idx = 0; idx < s.size(); idx++) {
            itr = last_occur.find(s[idx]);
            if (itr != last_occur.end() && itr->second > head) {

                maxL = (maxL < (idx -1 - head) ) ? idx - 1 - head: maxL;
                head = itr->second;
            }



            last_occur[s[idx]] = idx;
        }

        maxL = (maxL < (idx - 1 - head) ) ? idx - 1 - head: maxL;
        return maxL;

    }
};
//leetcode submit region end(Prohibit modification and deletion)
