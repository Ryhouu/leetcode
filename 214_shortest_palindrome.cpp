#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.length();
        s = s + '#' + string(s.rbegin(), s.rend());
        
        vector<int> pi;
        pi.push_back(0);
        
        for (int i = 1; i < s.size(); i ++) {
            int j = pi[i - 1];
            while (j > 0 && s[j] != s[i]) {
                j = pi[j - 1];
            }
            pi.push_back(s[j] == s[i] ? j + 1 : 0);
        }
        
        // int idx = 0;
        // for (int i = n + 1; i < s.size(); i ++) {
        //     cout << pi[i] << " ";
        //     if (pi[i] > pi[idx]) { idx = i; }
        // }
        // cout << endl;
        
        return s.substr(n + 1, n - pi[n * 2]) + s.substr(0, n);
        
    }
};

void check(Solution& sol, string input, string expected) {
    cout << "Testing input: " << input << endl;
    cout << "Expected: " << expected << endl;
    auto res = sol.shortestPalindrome(input);
    cout << "Actual: " << res << endl;
    cout << (res == expected ? "Success" : "Fail") << endl << endl;
}

int main(){
    Solution sol;
    check(sol, "ababbbabbaba", "ababbabbbababbbabbaba");

    return 0;
}
