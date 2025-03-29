class Solution {
public:
    bool match(char chs, char chp) {
        return (chp == '.' || chs == chp);
    }

    bool isMatch(string s, string p) {
        if (s.length() != p.length())
        {
            return false;
        }
        int s_idx = 0;
        int p_idx = 0;
        char prev = '0';
        while (s_idx < s.length())
        {
            if (p[p_idx] == '*')
            {
                if (!match(prev, p[p_idx-1]))
                {
                    return false;

                }
            } else if (p[p_idx] != '.')
            {
                if (s[s_idx] != p[p_idx]) 
                {
                    return false;
                }
            } 
            prev = s[s_idx];
            s_idx++;
            p_idx++;
        }
        return true;
    }
};