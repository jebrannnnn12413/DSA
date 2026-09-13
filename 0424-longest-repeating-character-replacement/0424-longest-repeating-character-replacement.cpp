class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0;
        int maxlen = 0;
        int maxfreq = 0;

        int hash[26] = {0};
        while (r < s.size()) {
            hash[s[r] - 'A']++;
            maxfreq = max(maxfreq, hash[s[r] - 'A']);
            int len = r - l + 1;

            if (r - l + 1 - maxfreq > k) {
                hash[s[l] - 'A']--;
                maxfreq = 0;
                for (int i = 0; i < 25; i++) {
                    maxfreq = max(maxfreq, hash[i]);
                }
                l++;
            }
            if (len - maxfreq <= k) {
                maxlen = max(maxlen, len);
            }
            r++;
        }
        return maxlen;
    }
};