class Solution {
public:
    int numberOfSubstrings(string s) {
        int l = 0, r = 0;
        int count = 0;

        unordered_map<char, int> mp;

        while (r < s.size()) {
            mp[s[r]]++;

            while (mp.size() == 3) {
                count += s.size() - r;

                mp[s[l]]--;

                if (mp[s[l]] == 0) {
                    mp.erase(s[l]);
                }

                l++;
            }

            r++;
        }
        return count;
    }
};