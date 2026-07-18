class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        // Traverse from rightmost digit
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                // No carry will happen, just increment and done
                digits[i]++;
                return digits;
            }
            // Current digit is 9 → becomes 0, carry propagates
            digits[i] = 0;
        }

        // If we're here, all digits were 9 (e.g. 999 → 1000)
        digits.insert(digits.begin(), 1);
        return digits;

        
    }
};