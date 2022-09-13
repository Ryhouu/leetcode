#include<bits/stdc++.h>
using namespace std;

ostream& operator << (ostream& out, const map<string, int>& m) {
    for (auto const& x: m) {
        out << "[" << x.first << ", " << x.second << "]" << " ";
    }
    return out;
}

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        map<string, int> cnt, head, tail;
        queue<map<string, int> > q;

        int pad = words[0].size();
        for (auto wd: words) { cnt[wd] ++; }

        for (int i = 0; i < pad; i ++) {
            while (!q.empty()) { q.pop(); }
            tail.clear(); q.push(tail);

            for (int j = i; j < s.size(); j += pad) {
                tail = q.back();
                string pref = s.substr(j, pad);

                for (auto const& x: cnt) {
                    if (pref == x.first) {
                        tail[x.first] ++; break;
                    }
                }
                q.push(tail);

                if (q.size() > words.size()) {
                    head = q.front(); q.pop();

                    bool ok = true; 
                    for (auto const& x: cnt) {
                        if (tail[x.first] - head[x.first] != x.second) {
                            ok = false; break;
                        }
                    }
                    if (ok) { ans.push_back(j - (words.size() - 1) * pad); }
                }
            }
        }
        return ans;
    }
};

int main(){
    Solution sol;
    
    string s1 = "barfoothefoobarman";
    vector<string> words1{"foo","bar"};
    for(auto x : sol.findSubstring(s1, words1)) { cout << x << " ";}
    cout << endl;

    string s2= "wordgoodgoodgoodbestword";
    vector<string> words2{"word","good","best","word"};
    for(auto x : sol.findSubstring(s2, words2)) { cout << x << " ";}
    cout << endl;

    string s3= "barfoofoobarthefoobarman";
    vector<string> words3{"bar","foo","the"};
    for(auto x : sol.findSubstring(s3, words3)) { cout << x << " ";}
    cout << endl;

    return 0;
}