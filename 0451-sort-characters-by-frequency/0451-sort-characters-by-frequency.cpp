class Solution {
public:
    static bool compare(pair<char, int> a, pair<char, int> b) {
        return a.second > b.second;
    }
    string frequencySort(string s) {

        unordered_map<char, int> mpp;

        vector<pair<char, int>> vpp;

        for (auto it : s) {
            mpp[it]++;
        }

        for (auto it : mpp) {
            vpp.push_back(it);
        }

        sort(vpp.begin(), vpp.end(), compare);

        string ans = "";

        for (auto it : vpp) {
            for (int i = 0; i < it.second; i++) {

                ans += it.first;
            }
        }
        return ans;
    }
};