class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;

        if (N < 0) {
            x = 1 / x;
            N = -N;
        }

        double ans = 1;

        for (; N > 0; N /= 2) {
            if (N % 2 == 1) {
                ans *= x;
            }

            x *= x;
        }

        return ans;
    }
};