class Solution {
public:
    int candy(vector<int>& rating) {
        int sum = 1;
        int i = 1;

        while (i < rating.size()) {
            if (rating[i] == rating[i - 1]) {
                sum += 1;
                i++;
                continue;
            }
            int peak = 1;
            while (i < rating.size() && rating[i] > rating[i - 1]) {
                peak += 1;
                sum += peak;
                i++;
            }
            int down = 1;
            while (i < rating.size() && rating[i] < rating[i - 1]) {
                sum += down;
                i++;
                down++;
            }

            if (down > peak) {
                sum += down - peak;
            }
        }
        return sum;
    }
};