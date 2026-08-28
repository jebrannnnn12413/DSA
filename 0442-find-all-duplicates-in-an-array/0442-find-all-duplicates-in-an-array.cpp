class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int j=0;
        vector<int>sve;

        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[j]){
                sve.push_back(nums[i]);
                j++;
            }else{
                j++;
            }
        }
        return sve;
        
    }
};