#include <string>
using namespace std;

int psum[30001] = { 0 };

class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;
        int cnt = 0;
        int SIZE = s.size();
        for (int i = 0; i < SIZE; i++) {
            if (s[i] == '(') {
                if (psum[cnt] == 0) {
                    psum[cnt] = i + 1;
                }
                cnt++;
            }
            else {
                cnt--;
                if (cnt < 0) {
                    psum[0] = 0;
                    cnt = 0;
                    continue;
                }
                psum[cnt + 1] = 0;
                if (ans < i + 2 - psum[cnt])ans = i + 2 - psum[cnt];
            }
        }
        while (cnt) psum[cnt--] = 0;
        psum[0] = 0;
        return ans;
    }
};

int main() {
    Solution x;
    x.longestValidParentheses("(()()");
}