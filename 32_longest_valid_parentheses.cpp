#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> dp(s.size() + 1, 0);
        int ans = 0;
        for (int i = 1; i < s.size(); i ++) {
            int j = i + 1;
            if (s[i] == ')') {
                if (s[i - 1] == '(') 
                    dp[j] = dp[j - 2] + 2;
                else{
                    int k = i - dp[j - 1] - 1;
                    if (k >= 0 && s[k] == '(') 
                        dp[j] = dp[j - 1] + dp[j - dp[j - 1] - 2] + 2;
                }
                ans = max(ans, dp[j]);
            }
        }
        return ans;
    }
};

int main(){
    Solution sol;
    
    // cout << (sol.longestValidParentheses("(()") == 2) << endl;
    // cout << (sol.longestValidParentheses(")()())") == 4) << endl;
    // cout << (sol.longestValidParentheses("") == 0) << endl;
    // cout << (sol.longestValidParentheses(")") == 0) << endl;
    // cout << (sol.longestValidParentheses("(") == 0) << endl;
    // cout << (sol.longestValidParentheses("()(())") == 6) << endl;
    // cout << (sol.longestValidParentheses("()(()") == 2) << endl;
    // cout << (sol.longestValidParentheses("(()(((()") == 2) << endl;
    // cout << (sol.longestValidParentheses("(()())") == 6) << endl;
    cout << (sol.longestValidParentheses("())") == 2) << endl;


    return 0;
}