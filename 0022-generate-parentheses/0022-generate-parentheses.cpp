class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(result, "", 0, 0, n);  // Počinjemo sa praznim stringom i nula otvorenih/zatvorenih zagrada
        return result;
    }

private:
    void backtrack(vector<string>& result, string current, int open, int close, int n) {
        // Ako smo dodali sve otvorene i zatvorene zagrade, dodajemo trenutnu kombinaciju u rezultat
        if (current.size() == 2 * n) {
            result.push_back(current);
            return;
        }

        // Dodajemo otvorenu zagradu ako je broj otvorenih manji od n
        if (open < n) {
            backtrack(result, current + "(", open + 1, close, n);
        }

        // Dodajemo zatvorenu zagradu ako je broj zatvorenih manji od broja otvorenih
        if (close < open) {
            backtrack(result, current + ")", open, close + 1, n);
        }
    }
};