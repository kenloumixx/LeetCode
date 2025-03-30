class Solution {
public:
    void dfs(int left, int right, int n, string& parenthesis, vector<string>& listParenthesis) 
    {
        if (parenthesis.length() == n * 2)
        {
            listParenthesis.push_back(parenthesis);
        }

        if (left < n)
        {
            string Lparenthesis = parenthesis + '(';
            dfs(left + 1, right, n, Lparenthesis, listParenthesis);
        }
        if (right < left)
        {
            string Rparenthesis = parenthesis + ')';
            dfs(left, right + 1, n, Rparenthesis, listParenthesis);
        }
        return;
    }

    vector<string> generateParenthesis(int n) {
        vector<string> listParenthesis;
        string startParenthesis = "";
        dfs(0, 0, n, startParenthesis, listParenthesis);
        return listParenthesis;
    }
};