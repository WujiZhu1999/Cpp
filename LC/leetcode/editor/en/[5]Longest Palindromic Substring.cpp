//Given a string s, return the longest palindromic substring in s. 
//
// 
// Example 1: 
//
// 
//Input: s = "babad"
//Output: "bab"
//Explanation: "aba" is also a valid answer.
// 
//
// Example 2: 
//
// 
//Input: s = "cbbd"
//Output: "bb"
// 
//
// 
// Constraints: 
//
// 
// 1 <= s.length <= 1000 
// s consist of only digits and English letters. 
// 
// Related Topics String Dynamic Programming 👍 19929 👎 1153


//leetcode submit region begin(Prohibit modification and deletion)
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        //construct extended string
        int str_size = s.size()*2+1;
        char str[str_size];
        for (int i = 0; i < s.size(); ++i) {
            str[2*i] = '#';
            str[2*i+1] = s[i];
        }
        str[str_size-1] = '#';

        //construct radius
        int r[str_size];

        int radius=0, center=0, mirror_radius, mirror_center, old_radius, old_center;

        while (center < str_size) {
            while ((center-radius-1) >=0 && (center+radius+1) < str_size &&
            str[center-radius-1] == str[center+radius+1]) {
                radius+=1;
            }

            r[center] = radius;
            old_radius = radius;
            old_center = center;
            radius = 0;
            center += 1;

            while (center <= (old_center+old_radius)) {
                mirror_center = old_center - (center - old_center);
                mirror_radius = old_radius - (center - old_center);

                if (mirror_radius < r[mirror_center]) {
                    r[center] = mirror_radius;
                    center += 1;
                } else if (mirror_radius > r[mirror_center]) {
                    r[center] = r[mirror_center];
                    center += 1;
                } else {
                    radius = mirror_radius;
                    break;
                }
            }

        }

        int max_r = 0, max_idx = 0;
        for (int i = 0; i < str_size; ++i) {
            if (r[i] > max_r) {
                max_r = r[i];
                max_idx = i;
            }
        }

        string output = "";

        for (int i = (max_idx-max_r+1); i < (max_idx+max_r); i+=2) {
            output.push_back(str[i]);
        }


        return output;

    }
};
//leetcode submit region end(Prohibit modification and deletion)
