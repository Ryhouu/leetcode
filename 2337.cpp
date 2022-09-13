#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct Node{
        char ch;
        int num;
        Node (char _ch, int _num): ch(_ch), num(_num) {}
        Node () {}
        
        bool operator == (Node y) {
            return ch == y.ch && num == y.num;
        }
    };
    
    
    stack<Node> solve(string s) {
        stack<Node> sta;
        map<char, int> cnt;
        int idx = 0;
        
        while (idx < s.size()) {
            while (s[idx] == 'L' || s[idx] == '_') { cnt[s[idx]] ++; idx ++;}
            if (cnt['L'] > 0) {
                sta.push(Node('L', cnt['L']));
                cnt['L'] = 0;
            }
            if (cnt['_'] > 0) {
                if (!sta.empty() && sta.top().ch == '_') sta.top().num += cnt['_'];
                else sta.push(Node('_', cnt['_']));
                cnt['_'] = 0;
            }
            
            while (s[idx] == 'R' || s[idx] == '_') { cnt[s[idx]] ++; idx ++;}
            if (cnt['_'] > 0) {
                if (!sta.empty() && sta.top().ch == '_') sta.top().num += cnt['_'];
                else sta.push(Node('_', cnt['_']));
                cnt['_'] = 0;
            }
            if (cnt['R'] > 0) {
                sta.push(Node('R', cnt['R']));
                cnt['R'] = 0;
            }
        }
        return sta;
    }
    
    bool canChange(string start, string target) {
        // stack<Node> sta1 = solve(start), sta2 = solve(target);
        // if (sta1.size() != sta2.size()) return false;
        // while (!sta1.empty()) {
        //     if (!(sta1.top() == sta2.top())) return false;
        //     sta1.pop(); sta2.pop();
        // }
        // return true;

        int idx1 = 0, idx2 = 0;
        int n = start.size(), m = target.size();

        while (idx1 < n || idx2 < m) {
            while (idx1 < n && start[idx1] == '_') idx1 ++;
            while (idx2 < m && target[idx2] == '_') idx2 ++;

            // cout << idx1 << " " << idx2 << endl;

            if (idx1 >= n && idx2 >= m) return true;
            if (idx1 >= n || idx2 >= m) return false;

            char c1 = start[idx1], c2 = target[idx2];
            if (c1 != c2 || 
                (c1 == 'L' && idx1 < idx2) || 
                (c1 == 'R' && idx1 > idx2)) return false;
            
            idx1 ++, idx2 ++;
        }
        return (idx1 >= n && idx2 >= m);
    }
};


void validate(Solution& sol, string input1, string input2, bool expected) {
    cout << "Testing input: " << input1 << ", " << input2 << endl;
    cout << "Expected: " << expected << endl;
    auto res = sol.canChange(input1, input2);
    cout << "Actual: " << res << endl;
    cout << (res == expected ? "Success" : "Fail") << endl << endl;
}

int main(){
    Solution sol;
    validate(sol, "_L__R__R_", "L______RR", true);
    validate(sol, "R_L_", "__LR", false);
    validate(sol, "_R", "R_", false);
    validate(sol, "_L", "LL", false);

    return 0;
}