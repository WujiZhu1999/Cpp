//The string "PAYPALISHIRING" is written in a zigzag pattern on a given number 
//of rows like this: (you may want to display this pattern in a fixed font for 
//better legibility) 
//
// 
//P   A   H   N
//A P L S I I G
//Y   I   R
// 
//
// And then read line by line: "PAHNAPLSIIGYIR" 
//
// Write the code that will take a string and make this conversion given a 
//number of rows: 
//
// 
//string convert(string s, int numRows);
// 
//
// 
// Example 1: 
//
// 
//Input: s = "PAYPALISHIRING", numRows = 3
//Output: "PAHNAPLSIIGYIR"
// 
//
// Example 2: 
//
// 
//Input: s = "PAYPALISHIRING", numRows = 4
//Output: "PINALSIGYAHRPI"
//Explanation:
//P     I    N
//A   L S  I G
//Y A   H R
//P     I
// 
//
// Example 3: 
//
// 
//Input: s = "A", numRows = 1
//Output: "A"
// 
//
// 
// Constraints: 
//
// 
// 1 <= s.length <= 1000 
// s consists of English letters (lower-case and upper-case), ',' and '.'. 
// 1 <= numRows <= 1000 
// 
// Related Topics String 👍 4048 👎 9102


//leetcode submit region begin(Prohibit modification and deletion)

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }

        int itr_size = (numRows - 1) * 2;
        string output = "";

        int r, c;

        for (r = 0; r < numRows; ++r) {
            if (r == 0 || r == (numRows - 1)) {
                for (c = r; c < s.size(); c += itr_size) {
                    output.push_back(s[c]);
                }
            } else {
                for (c = r; c < s.size(); c += itr_size) {
                    output.push_back(s[c]);
                    if ((c+ itr_size - r - r) < s.size()) {
                        output.push_back(s[c+itr_size - r - r]);
                    }
                }
            }
        }

        return output;






        /*
        string output = "";
        int height = numRows - 1;
        int idx = 0;

        vector<vector<int>> bin = vector<vector<int>>(numRows);
        while (idx < s.size()) {
            if (height <= 0) {
                height = numRows - 1;
            }

            if (height == (numRows - 1)) {
                for (vector<int> &b: bin) {
                    b.push_back(idx);
                    idx+=1;
                }
            } else {
                bin[height].push_back(idx);
                idx+=1;
            }
            height-=1;
        }

        for (vector<int> &b : bin) {
            for (int &i: b) {
                if (i < s.size()) {
                    output.push_back(s[i]);
                }
            }
        }
        return output;
        */
    }
};
//leetcode submit region end(Prohibit modification and deletion)
