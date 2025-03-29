class Solution {
public:
    bool rec(std::string ss, std::string pp) {
        if (ss.empty() && pp.empty()) return true;
        else if (pp.empty()) return false;
        int ppLen = pp.length();
        int ssLen = ss.length();
        if (ppLen > 1 && pp[1] == '*')
        {
            if (rec(ss, pp.substr(2)) == true) return true;
            if (ssLen > 0 && (ss[0] == pp[0] || pp[0] == '.')) return rec(ss.substr(1), pp);
        } else 
        {
            if (ssLen > 0 && (ss[0] == pp[0] || pp[0] == '.')) return rec(ss.substr(1), pp.substr(1));
        }
        return false;
    }

    bool isMatch(string s, string p) {
        return rec(s, p);
    }
};