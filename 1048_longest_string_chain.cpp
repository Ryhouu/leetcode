#include<bits/stdc++.h>
using namespace std;

void dfs(
    string wd, 
    map<string, vector<string> >& predec, 
    map<string, int>& chain
){
    chain[wd] = 1;
    for (auto x : predec[wd]) {
        if (chain[x] == 0) {
            dfs(x, predec, chain);
        }
        chain[wd] = max(chain[wd], chain[x] + 1);
    }
}

int solve(vector<string>& words){
    set<string> wdset(words.begin(), words.end());
    map<string, vector<string> > predec;
    map<string, int> chain;

    for (auto x : words) {
        for (int i = 0; i < x.size(); i ++) {
            string tmp = x.substr(0, i) + x.substr(i + 1);
            if (wdset.find(tmp) != wdset.end()) {
                predec[x].push_back(tmp);
            }
        }
    }

    int max_chain = 0;
    for (auto x : words) {
        dfs(x, predec, chain);
        max_chain = max(max_chain, chain[x]);
    }

    return max_chain;
}

int main(){
    vector<string> words1{"a","b","ba","bca","bda","bdca"};
    vector<string> words2{"xbc","pcxbcf","xb","cxbc","pcxbc"};
    vector<string> words3{"abcd","dbqca"};
    cout << solve(words1) << endl;
    cout << solve(words2) << endl;
    cout << solve(words3) << endl;
    return 0;
}