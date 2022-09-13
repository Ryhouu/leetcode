#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        queue<string> line;
        vector<string> res;
        
        int cnt = 0;
        for (string wd : words) {
            int len = wd.length() + (cnt != 0);
            if (cnt + len <= maxWidth) {
                line.push(wd);
                cnt += len;
            }
            else {
                int k = line.size() - 1;
                int num_spaces = maxWidth - cnt + k;

                // cout << "k: " << k << endl;
                // cout << "num spaces: " << num_spaces << endl;
                
                string s = line.front();
                line.pop();
                
                if (k == 0) { s.append(num_spaces, ' '); }
                else {
                    int pad = num_spaces / k, r = num_spaces % k;

                    // cout << "pad: " << pad << ", r: " << r << endl;

                    while(!line.empty()) {
                        s.append(pad + (r -- > 0), ' ');
                        s.append(line.front());
                        line.pop();
                    }                   
                }

                res.push_back(s);
                line.push(wd);
                cnt = wd.size();
            }
        }
        
        string s = line.front(); 
        line.pop();
        while(!line.empty()) {
            s.append(" " + line.front());
            line.pop();
        }  
        res.push_back(s);
        
        return res;
    }
};

template<typename T>
ostream& operator <<(ostream& out, const vector<T>& vec) {
    for (auto x : vec) {
        out << x << endl;
    }
    return out;
}

void check(Solution& sol, vector<string>& input1, int input2, vector<string>& expected) {
    cout << "Testing input: " << input1 << endl << input2 << endl;
    cout << "Expected: " << endl << expected << endl;
    auto res = sol.fullJustify(input1, input2);
    cout << "Actual: " << endl << res << endl;
    // cout << (res == expected ? "Success" : "Fail") << endl << endl;
}

int main(){
    Solution sol;
    vector<string> words{"This", "is", "an", "example", "of", "text", "justification."};
    vector<string> expected{"This    is    an", "example  of text", "justification.  "};

    check(sol, words, 16, expected);

    return 0;
}