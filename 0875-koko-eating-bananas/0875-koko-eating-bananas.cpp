class Solution {
public:
    long long thours(vector<int>& arr, long long h) {
        long long total = 0;
        for (int i = 0; i < arr.size(); i++) {
            total += ceil((double)arr[i] / h);
        }
        return total;
    }
    int minEatingSpeed(vector<int>& arr, long long h) {
        int low = 1, high = *max_element(arr.begin(), arr.end());

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long totalhours = thours(arr, mid);
            if (totalhours<=h) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};