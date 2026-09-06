class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        const long long MOD = 1e9 + 7;

        vector<int> left(n, -1);
        vector<int> right(n, n);

        stack<int> st;

        // Previous Smaller Element
        for (int i = 0; i < n; i++) {

            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            if (!st.empty()) {
                left[i] = st.top();
            }

            st.push(i);
        }

        while (!st.empty()) {
            st.pop();
        }

        // Next Smaller OR Equal Element
        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            if (!st.empty()) {
                right[i] = st.top();
            }

            st.push(i);
        }

        long long ans = 0;

        for (int i = 0; i < n; i++) {

            long long leftCount = i - left[i];
            long long rightCount = right[i] - i;

            long long contribution =
                arr[i] * leftCount % MOD * rightCount % MOD;

            ans = (ans + contribution) % MOD;
        }

        return ans;
    }
};