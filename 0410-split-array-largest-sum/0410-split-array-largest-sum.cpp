class Solution {
public:
    int canhave(vector<int> arr, int mid) {
        int v = 1;
        int canhave = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (canhave + arr[i] <= mid) {
                canhave += arr[i];
            } else {
                v++;
                canhave = arr[i];
            }
        }
        return v;
    }
    int splitArray(vector<int>& nums, int k) {

        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canhave(nums, mid) <= k) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};