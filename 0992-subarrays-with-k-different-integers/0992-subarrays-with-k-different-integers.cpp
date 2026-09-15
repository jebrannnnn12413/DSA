class Solution {
public:
    int solve(vector<int>& arr, int k) {
        int r = 0, l = 0;
        int count = 0;
        unordered_map<int, int> mpp;

        while (r < arr.size()) {
            mpp[arr[r]]++;

            while (mpp.size() > k) {
                mpp[arr[l]]--;

                if (mpp[arr[l]] == 0) {
                    mpp.erase(arr[l]);
                }
                l++;
            }
            count+= r - l + 1;
            r++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k - 1);
    }
};