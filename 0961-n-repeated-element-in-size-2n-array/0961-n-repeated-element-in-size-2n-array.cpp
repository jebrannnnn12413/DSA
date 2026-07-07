class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for(auto it:nums){
            mpp[it]++;
            if(mpp[it]==2){
                return it;
            }
        }
        return -1;
    }
};