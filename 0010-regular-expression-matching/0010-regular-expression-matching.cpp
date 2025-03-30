class Solution {
public:
    bool solveMem(int i, int j, const std::string& s, const std::string& p, std::vector<std::vector<std::optional<bool>>>& dp) {
        if (j == p.length()) return i == s.length();
        if (dp[i][j].has_value()) return dp[i][j].value();

        bool firstCharMatch = (i < s.length()) && (s[i] == p[j] || p[j] == '.');

        if (j + 1 < p.length() && p[j + 1] == '*')
        {
            bool take = firstCharMatch && solveMem(i+1, j, s, p, dp);
            bool not_take = solveMem(i, j+2, s, p, dp);
            dp[i][j] = take || not_take;
            return dp[i][j].value();
        }

        dp[i][j] = firstCharMatch && solveMem(i+1, j+1, s, p, dp);
        return dp[i][j].value();
    }

    bool isMatch(string s, string p) {
        std::vector<std::vector<std::optional<bool>>> dp(s.length() + 1, std::vector<std::optional<bool>> (p.length() + 1));
        return solveMem(0, 0, s, p, dp);
    }
};