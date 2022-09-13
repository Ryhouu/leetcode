class Solution {
public:
    int minDistance(string word1, string word2) {
        // dp[i][j]: match the i-th char in word1 with the j-th char in word2
        int n = word1.size(), m = word2.size();
        vector<vector<int> > dp(n + 1, vector<int>(m + 1));

        for (int i = 0; i <= n; i ++) dp[i][0] = i;
        for (int i = 0; i <= m; i ++) dp[0][i] = i;

        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= m; j ++) {
                dp[i][j] = (
                    word1[i] == word2[j] ? 
                    dp[i - 1][j - 1] :
                    min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1 // insert/delete/replace
                )
            }
        }

        return dp[n][m];
    }
};