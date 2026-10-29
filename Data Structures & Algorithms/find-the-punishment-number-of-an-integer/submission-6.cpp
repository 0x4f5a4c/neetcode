class Solution {
private:
    static vector<int> memo;

    static bool check(int square, int curr_sum, int num) {
        if (square == 0) return curr_sum == num;
        if (curr_sum > num) return false;

        int d = 10;
        while (square >= d / 10) {
            if (check(square / d, (square % d) + curr_sum, num)) return true;
            if (d > square) break;
            d *= 10;
        }
        return false;
    }

    static void precompute() {
        if (!memo.empty()) return;
        memo.resize(1001, 0);
        int running_sum = 0;
        for (int i = 1; i <= 1000; ++i) {
            if (check(i * i, 0, i)) {
                running_sum += (i * i);
            }
            memo[i] = running_sum;
        }
    }

public:
    int punishmentNumber(int n) {
        precompute();
        return memo[n];
    }
};

vector<int> Solution::memo;
