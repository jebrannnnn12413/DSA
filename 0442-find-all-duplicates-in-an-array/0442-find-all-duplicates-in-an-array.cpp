class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int,int>mpp;
        vector<int>sve;

        for(auto it:nums){
            mpp[it]++;
        }

        for(auto x:mpp){
            if(x.second==2){
                sve.push_back(x.first);
            }
        }
        return sve;
    }
};