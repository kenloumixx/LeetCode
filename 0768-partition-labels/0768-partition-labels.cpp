class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> labels;
        int prev_rend = -1;
        int best_rend = 0;

        for (int lend = 0; lend < s.length(); lend++)
        {
            for (int rend = s.length()-1; rend >= best_rend; rend--)
            {
                if (lend == rend) 
                {
                    labels.push_back(rend - prev_rend);
                    prev_rend = rend;
                    best_rend = 0;
                    break;
                }
                if (s[lend] == s[rend])
                {
                    best_rend = max(rend, best_rend);
                    break;
                }
            }
        }
        return labels;
    }
};