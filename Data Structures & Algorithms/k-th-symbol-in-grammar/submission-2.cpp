class Solution {
public:
    int kthGrammar(int n, int k) {
        n = pow(2, n-1);
        bool is_same = true;

        while (n != 1) {
            n /= 2;

            if (k > n) {
                k -= n;
                is_same = !is_same;
            }
        }

        return (is_same) ? 0 : 1;
    }
};
