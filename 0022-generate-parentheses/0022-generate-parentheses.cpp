class Solution {
public:
    void dfs(int left, int right, int n, string parenthesis, vector<string>& listParenthesis) 
    {
        if (parenthesis.length() == n * 2)
        {
            listParenthesis.push_back(parenthesis);
            return;
        }

        if (left < n)
        {
            dfs(left + 1, right, n, parenthesis + '(', listParenthesis);
        }
        if (right < left)
        {
            dfs(left, right + 1, n, parenthesis + ')', listParenthesis);
        }
        return;
    }

    vector<string> generateParenthesis(int n) {
        vector<string> listParenthesis;
        dfs(0, 0, n, "", listParenthesis);
        return listParenthesis;
    }
};