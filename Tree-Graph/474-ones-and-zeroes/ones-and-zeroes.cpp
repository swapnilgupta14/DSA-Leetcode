class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> memo(strs.size(), vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        return dp(strs, m, n, 0, memo); 
    }

private:
    int dp(vector<string>& strs, int m, int n, int i, vector<vector<vector<int>>>& memo) {
        if (m == 0 && n == 0) return 0;
        if (i == strs.size()) return 0;
        if (memo[i][m][n] != -1) return memo[i][m][n];

        int ones = count(strs[i].begin(), strs[i].end(), '1');
        int zeros = strs[i].size() - ones;
        int take = 0;
        if (m >= zeros && n >= ones)
            take = 1 + dp(strs, m - zeros, n - ones, i + 1, memo);
        int dontTake = dp(strs, m, n, i + 1, memo);

        return memo[i][m][n] = max(take, dontTake);
    }
};