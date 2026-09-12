class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0, r=0, maxlen = 0;

        int freq[256] = {-1};
        fill(freq, freq + 256, -1);

        while (r < s.size()) {
            if (freq[s[r]] != -1) {
                if (freq[s[r]] >= l) {
                    l = freq[s[r]] + 1;
                }
            }
            int len = r - l + 1;

            maxlen = max(len, maxlen);
            freq[s[r]]=r;
            r++;
        }
        return maxlen;
    }
};