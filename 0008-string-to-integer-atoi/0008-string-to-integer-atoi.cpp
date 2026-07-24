class Solution {
public:
    int myAtoi(string s) {
        long long num = 0;
        int sign = 1;
        int i = 0;

        while (i < s.size() && s[i] == ' ') {
            i++;
        }
        if (i == s.size()) {
            return 0;
        }

        if (s[i] == '-') {
            sign = -1;
            i++;
        } else if (s[i] == '+') {
            sign = 1;
            i++;
        }

        while (i < s.size() && s[i] >= '0' && s[i] <= '9') {
            int digits = s[i] - '0';
           if (num > INT_MAX / 10 ||
                (num == INT_MAX / 10 &&
                 digits > (sign == 1 ? 7 : 8))) {

                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            num = num * 10 + digits;
            i++;
        }
        if (sign == 1 && num > INT_MAX) {
            return INT_MAX;
        }

        if (sign == -1 && -num < INT_MIN) {
            return INT_MIN;
        }
        return sign * num;
    }
};