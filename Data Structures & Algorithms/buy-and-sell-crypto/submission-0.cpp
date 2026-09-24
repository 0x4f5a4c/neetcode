class Solution {
public:
    void _compute_best_buy(vector<int> &arr, vector<int> &prices, int n) {
        arr.resize(n);
        arr[0] = INT_MAX;
        for (int i = 1; i < n; ++i) 
            arr[i] = min(arr[i-1], prices[i-1]);
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> best_buy;
        _compute_best_buy(best_buy, prices, n);

        // now compute the answer
        int curr_profit, maximum_profit = 0;
        for (int i = 0; i < n; ++i) {
            curr_profit = prices[i] - best_buy[i];
            maximum_profit = max(maximum_profit, curr_profit);
        }

        return maximum_profit;
    }
};
