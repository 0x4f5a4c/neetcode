class Solution {
public:
    vector<int> memo[21][21];
    vector<int> solve(string exp, int i, int j) {
        if (!memo[i][j].empty()) return memo[i][j];

        vector<int> ans;
        for (int idx = i; idx <= j; ++idx) {

            if (exp[idx] == '+' || exp[idx] == '-' || exp[idx] == '*') {
                // now we have options
                vector<int> left  = solve(exp, i, idx-1);
                vector<int> right = solve(exp, idx+1, j);

                for (int x : left) {
                    for (int y : right) {
                        if (exp[idx] == '+') ans.push_back(x+y);
                        else if (exp[idx] == '-') ans.push_back(x-y);
                        else ans.push_back(x*y);
                    }
                }
            }
        }

        if (ans.empty()) ans.push_back(stoi(exp.substr(i, j-i+1)));
        return memo[i][j] = ans;
    }

    vector<int> diffWaysToCompute(string expression) {
        int n = expression.size();
        return solve(expression, 0, n-1);
    }
};
