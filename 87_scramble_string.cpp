#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int> (&f)[26], vector<int> (&g)[26], int l1, int r1, int l2, int r2) {
        // l, r > 0
        for (int i = 0; i < 26; i ++) {
            if (f[i][r1] - f[i][l1 - 1] != g[i][r2] - g[i][l2 - 1]) return false;
        }
        return true;
    }

    bool dfs(vector<int> (&f)[26], vector<int> (&g)[26], int l1, int r1, int l2, int r2) {
        // printf ("dfs: (%d, %d), (%d, %d)\n", l1, r1, l2, r2);

        if (r1 - l1 != r2 - l2 || !check(f, g, l1, r1, l2, r2)) {
            // cout << "fail_1" << endl;
            return false;
        }
        if (l1 == r1) return true;

        for (int i = 0; i < r1 - l1; i ++) {
            if (
                (dfs(f, g, l1, l1 + i, l2, l2 + i) && dfs(f, g, l1 + i + 1, r1, l2 + i + 1, r2)) 
                || (dfs(f, g, l1, l1 + i, l2 + r1 - l1 - i, r2) && dfs(f, g, l1 + i + 1, r1, l2, l2 + r1 - l1 - i - 1))
            ) { return true; }
        }
        // cout << "fail_2" << endl;
        return false;
    }

    // bool isScramble(string s1, string s2) {
    //     int n = s1.size(), m = s2.size();

    //     if (n != m) return false;

    //     vector<int> f[26], g[26];
        
    //     for (int i = 0; i < 26; i ++) {
    //         f[i].push_back(0);
    //         g[i].push_back(0);
    //         for (int j = 0; j < n; j ++) {
    //             f[i].push_back(f[i].back() + (s1[j] - 'a' == i));                
    //         }
    //         for (int j = 0; j < m; j ++) {
    //             g[i].push_back(g[i].back() + (s2[j] - 'a' == i));               
    //         }
    //     }
    //     return dfs(f, g, 1, n, 1, m);
    // }

    map<string, bool> mem;

    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        if (s1 == s2) return true;

        string s = s1 + '#' + s2;
        if (mem.find(s) != mem.end()) return mem[s];

        int n = s1.size();

        for (int i = 1; i < n; i ++) {
            if (
                (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i)))
                ||
                (isScramble(s1.substr(0, i), s2.substr(n - i)) && isScramble(s1.substr(i), s2.substr(0, n - i)))
            ) { return mem[s] = true; }
        }
        return mem[s] = false;
    }
};


void validate(Solution& sol, string input1, string input2, bool expected) {
    cout << "Testing input: " << input1 << " " << input2 << endl;
    cout << "Expected: " << expected << endl;
    auto res = sol.isScramble(input1, input2);
    cout << "Actual: " << res << endl;
    cout << (res == expected ? "Success" : "Fail") << endl << endl;
}

int main(){
    Solution sol;
    validate(sol, "great", "rgeat", true);
    // validate(sol, "abcde", "caebd", false);
    // validate(sol, "eebaacbcbcadaaedceaaacadccd", "eadcaacabaddaceacbceaabeccd", false);
    // validate(sol, "a", "aa", "");

    return 0;
}