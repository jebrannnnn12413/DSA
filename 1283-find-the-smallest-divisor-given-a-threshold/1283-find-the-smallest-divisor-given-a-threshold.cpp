class Solution {
public:
    bool isthreshold(vector<int>& nums, int num, int threshold) {
        long long div = 0;
        for (int i = 0; i < nums.size(); i++) {
            div += ceil((double)nums[i] / num);
        }
        if (div <= threshold) {
            return true;
        } else
            return false;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxi = *max_element(nums.begin(), nums.end());
        int low = 1, high = maxi;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isthreshold(nums, mid, threshold) == true) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};