#include <vector>

class Solution {
public:
    string longestPalindrome(string s) {
        int len_str = static_cast<int>(s.length());
        std::vector<std::vector<bool>> dp(len_str, std::vector<bool>(len_str, false));
        
        for (int length = 1; length <= len_str; length++)
        {
            for (int start = 0 ; start <= len_str - length ; start++)
            {
                if (length == 1)
                {
                    dp[start][start] = true;
                } else if (length == 2 && s[start] == s[start+1])
                {
                    dp[start][start+1] = true;
                } else if (s[start] == s[start+length-1] && dp[start+1][start+length-2] == true)
                {
                    dp[start][start+length-1] = true;
                }
            }
        }

        std::string longest_palindromic = "";
        for (int i = 0; i < len_str; i++) 
        {
            for (int j = 0; j < len_str; j++) 
            {
                if (dp[i][j] == true && longest_palindromic.length() < (j-i+1))
                {
                    longest_palindromic = s.substr(i, j - i + 1);
                }
            }
        }
        return longest_palindromic;
    }
};
