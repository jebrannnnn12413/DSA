class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int hash[101] = {0};

        for (auto it : nums) {
            hash[it]++;
        }

        for (int i = k; ; i+=k) {
            if (i>100) {
                return i;
            }
            if(hash[i]==0){
                return i;
            }
        }
        return -1;
    }
};