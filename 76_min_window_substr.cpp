#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool check(int cnt_t[], vector<int> cnt_s[52], int l, int r) {
        
        // cout << "checking: " << l << ", " << r << endl;
        for (int i = 0; i < 52; i ++) {
            
            if (cnt_s[i][r] - cnt_s[i][l] < cnt_t[i]) {
                // cout << (i < 26 ? (char)(i + 'A') : (char)(i - 26 + 'a')) << ": ";
                // cout << "fail: " << cnt_s[i][r] << " " << cnt_s[i][l] << " " << cnt_t[i] << endl;
                return false;
            }
        }
        return true;
    }
    
    void check1(int cnt_t[]) {
        for (int i = 0; i < 52; i ++) {
            cout << (i < 26 ? (char)(i + 'A') : (char)(i - 26 + 'a')) << ": " << cnt_t[i] << endl;
        }
    }

    void check2(vector<int> cnt_s[52]) {
        for (int j = 0; j < cnt_s[0].size(); j ++) {
            cout << "idx: " << j << endl;
            for (int i = 0; i < 52; i ++) {
                cout << (i < 26 ? (char)(i + 'A') : (char)(i - 26 + 'a')) << ": " << cnt_s[i][j] << endl;
            }
            cout << endl;
        }
    }
    
    string minWindow(string s, string t) {
        vector<int> cnt_s[52];
        int cnt_t[52]; 
        
        for (int i = 0; i < 52; i ++) {
            cnt_t[i] = 0;
            cnt_s[i].push_back(0);
        }
        
        for (char c : t) {
            cnt_t[c > 'Z' ? c - 'a' + 26 : c - 'A'] ++;
        }
        
        for (char c : s) {
            int idx = c > 'Z' ? c - 'a' + 26 : c - 'A';
            for (int i = 0; i < 52; i ++) { 
                cnt_s[i].push_back(cnt_s[i].back() + (i == idx)); 
            }
        }
        
        // check1(cnt_t);
        // check2(cnt_s);
        
        int l = 0, r = 0, minn = s.size() + 1;
        string ans = "";
        while (r <= s.size()) {
            while(r <= s.size() && !check(cnt_t, cnt_s, l, r)) r ++;
            if (r > s.size()) break;
            while(check(cnt_t, cnt_s, l, r)) l ++;

            // cout << "l: " << l << ", r: " << r << endl;

            if (r - l < minn) {
                minn = r - l;
                ans = s.substr(l - 1, r - l + 1);
            }
        }
        
        return ans;
        
    }
};


void check(Solution& sol, string input1, string input2, string expected) {
    cout << "Testing input: " << input1 << " " << input2 << endl;
    cout << "Expected: " << expected << endl;
    auto res = sol.minWindow(input1, input2);
    cout << "Actual: " << res << endl;
    cout << (res == expected ? "Success" : "Fail") << endl << endl;
}

int main(){
    Solution sol;
    check(sol, "ADOBECODEBANC", "ABC", "BANC");
    check(sol, "a", "a", "a");
    check(sol, "a", "aa", "");

    return 0;
}