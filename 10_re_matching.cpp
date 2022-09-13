#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        if (s.size() == 0) { 
            if (p.size() & 1) return false;
            for (int i = 1; i < p.size(); i += 2) {
                if (p[i] != '*') return false;
            }
            return true; 
        }
        else if (p.size() == 0) { return false; }

        if (p[0] == '.') {
            if (
                p.size() > 1 && p[1] == '*' &&
                (isMatch(s.substr(1), p) || isMatch(s, p.substr(2)))
            ) {
                return true;
            }
            else if (isMatch(s.substr(1), p.substr(1))) {
                return true;
            }
        }
        else {
            if (
                p.size() > 1 && p[1] == '*' &&
                (s[0] == p[0] && isMatch(s.substr(1), p) || 
                    isMatch(s, p.substr(2)))
            ) {
                return true;
            }
            else if (s[0] == p[0] && isMatch(s.substr(1), p.substr(1))) {
                return true;
            }
        }
        return false;
    }
};

int main(){
    Solution sol;
    cout << "expected: " << false << ", got: " << sol.isMatch("aa", "a") << endl;
    cout << "expected: " << true << ", got: " << sol.isMatch("aa", "a*") << endl;
    cout << "expected: " << true << ", got: " << sol.isMatch("ab", ".*") << endl;
    
    return 0;
}
