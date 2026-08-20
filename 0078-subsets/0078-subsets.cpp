class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int subsets = (1 << nums.size());
        vector<vector<int>> arr;

        for (int i = 0; i < subsets; i++) {
            vector<int> arr2;
            for (int j = 0; j < nums.size(); j++) {
                if (i & (1 << j)) {
                    arr2.push_back(nums[j]);
                }
            }
            arr.push_back(arr2);
        }
        return arr;
    }
};