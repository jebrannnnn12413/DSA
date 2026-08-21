class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        int subsets = 1 << n;
        set<vector<int>> st;

        for (int i = 0; i < subsets; i++) {
            vector<int> arr;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    arr.push_back(nums[j]);
                }
            }
            sort(arr.begin(), arr.end());
            st.insert(arr);
        }
        return vector<vector<int>>(st.begin(), st.end());
    }
};