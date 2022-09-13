#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define MOD 1000000007
#define N 10000

class Solution {
    public:
    vector<int> eratos(int n) {
        vector<bool> is_pr(n + 1, true);
        vector<int> primes;

        for (int i = 2; i <= n; i ++) {
            if (is_pr[i]) {
                primes.push_back(i);
                for (int j = i * i; j <= n; j += i) {
                    is_pr[j] = false;
                }
            }
        }

        return primes;
    }

    int idealArrays(int n, int maxValue) {
        vector<int> pr = eratos(maxValue);
        vector<LL> f(maxValue + 1, 1);
        // dp[i][j]: # ways to allocate j same factors to the previous i bins
        // dp[i][j] = sum(dp[i - 1][j - t]) (t factors on the last bin)
        vector<int> dp[2]; 
        for (int i = 0; (1 << i) <= N; i ++) {
            dp[0].push_back(1);
            dp[1].push_back(0);
        }
        
        for (int i = 2; i <= n; i ++) {
            for (int j = 0; (1 << j) <= N; j ++) {
                dp[(i & 1) ^ 1][j] = 0;
                for (int t = 0; t <= j; t ++) {
                    dp[(i & 1) ^ 1][j] += dp[(i & 1)][j - t];
                    dp[(i & 1) ^ 1][j] %= MOD;
                }
            }
        }
        
        int t = (n & 1) ^ 1;
        LL ans = 1;

        for (int i = 2; i <= maxValue; i ++) {
            int x = i;
            for (int j = 0; x > 1 && j < pr.size() && pr[j] <= x; j ++) {
                if (x % pr[j] == 0) {
                    int k = 0;
                    while (x % pr[j] == 0) {
                        k ++, x /= pr[j]; 
                    }
                    f[i] *= dp[t][k];
                    f[i] %= MOD;
                    // cout << i << ", " << pr[j] << ": " << k << " | " << f[i] << endl;    
                }
            }
            ans += f[i];
            ans %= MOD;
        }
        return (int) ans;
    }

};


// class Solution {
// public:
//     struct Node {
//         int num;
//         int cur;
//         Node (int _num, int _cur): num(_num), cur(_cur){}
//     };
    
//     int idealArrays(int n, int maxValue) {
//         vector<LL> f[2];
//         for (int i = 0; i <= maxValue; i ++) { 
//             f[0].push_back(1LL); 
//             f[1].push_back(1LL); 
//         }
        
//         for (int i = 2; i <= n; i ++) {
//             for (int j = 1; j <= maxValue; j ++) 
//                 f[(i ^ 1) & 1][j] = 0;
            
//             for (int j = 1; j <= maxValue; j ++) {
//                 for (int k = j; k <= maxValue; k += j) {
//                     f[(i & 1) ^ 1][k] += f[i & 1][j];
//                     f[(i & 1) ^ 1][k] %= MOD;
//                 }
//             }
//         }
        
//         LL ans = 0;
//         for (int i = 1; i <= maxValue; i ++) {
//             ans += f[(n & 1) ^ 1][i] * 1LL;
//             ans %= MOD;
//         }
                
//         return ans;
//     }
// };

int main() {
    string s = "apple";
    sort(s.begin(), s.end());
    cout << s << endl;
    return 0;
}