class Solution {
public:
    bool rotateString(string s, string goal) {
        string sum = s + s;

        if (s.size() != goal.size()) {
            return false;
        }

        if (sum.find(goal) !=string::npos) {
            return true;
        }
        return false;
    }
};