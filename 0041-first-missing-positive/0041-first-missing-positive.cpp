class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int, int> arr;
        for (auto it : nums) {
            arr[it]++;
        }
        for (int i = 1; i <= nums.size(); i++) {
            if (arr[i] == 0) {
                return i;
            }
        }
        return nums.size()+1;
    }
};