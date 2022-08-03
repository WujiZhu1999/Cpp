//Given a signed 32-bit integer x, return x with its digits reversed. If 
//reversing x causes the value to go outside the signed 32-bit integer range [-2³¹, 2³¹ -
// 1], then return 0. 
//
// Assume the environment does not allow you to store 64-bit integers (signed 
//or unsigned). 
//
// 
// Example 1: 
//
// 
//Input: x = 123
//Output: 321
// 
//
// Example 2: 
//
// 
//Input: x = -123
//Output: -321
// 
//
// Example 3: 
//
// 
//Input: x = 120
//Output: 21
// 
//
// 
// Constraints: 
//
// 
// -2³¹ <= x <= 2³¹ - 1 
// 
// Related Topics Math 👍 7830 👎 10302


//leetcode submit region begin(Prohibit modification and deletion)
#include <vector>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        if ((x <= 9) and (x >= -9)) {
            return x;
        }

        bool is_negative = (x < 0);
        if (x == INT_MIN) {
            return 0;
        } else if (is_negative) {
            x *= -1;
        }

        int last = x % 10, output = 0, size = 0;
        x /= 10;
        while (x) {
            output *= 10;
            if (size) {
                last *= 10;
            }
            output += x % 10;
            x /= 10;
            ++size;
        }


        if ((size < 9) || (last == 100000000)) {
            if (is_negative) {
                return last*(-10)-output;
            } else {
                return last * 10+output;
            }
        } else if (last == 200000000) {
            if (is_negative and (output <= 147483648)) {
                return last*(-10)-output;
            } else if (!is_negative and (output <= 147483647)) {
                return last * 10+output;
            } else {
                return 0;
            }
        } else {
            return 0;
        }




        /*
        bool is_negative = (x < 0);
        if (x == INT_MIN) {
            return 0;
        } else if (is_negative) {
            x *= -1;
        }

        int size = 0, output = 0;
        vector<int> MAX_ARRAY = {2, 1, 4, 7, 4, 8, 3, 6, 4, 7};
        vector<int> num_array = vector<int>(10);
        if (is_negative) { MAX_ARRAY[9] = 8;}

        while (x) {
            num_array[size] = x % 10;
            x /= 10;
            ++size;
        }

        if (size == 10) {
            for (int i = 0; i < 10; ++i) {
                if (num_array[i] > MAX_ARRAY[i]) {

                    return 0;
                } else if (num_array[i] < MAX_ARRAY[i]) {
                    break;
                }
            }
        }
        int neg = is_negative ? -1 : 1;
        for (int i = 0; i < size; ++i) {
            output *= 10;
            output += num_array[i] * neg;
        }

        return output;
        */
    }
};
//leetcode submit region end(Prohibit modification and deletion)
