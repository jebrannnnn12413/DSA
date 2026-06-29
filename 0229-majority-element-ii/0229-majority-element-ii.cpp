class Solution {
public:
    vector<int> majorityElement(vector<int>& arr) {
        int n = arr.size();
        int count1 = 0;
        int count2 = 0;
        int element1 = INT_MIN;
        int element2 = INT_MIN;

        for (int i = 0; i < n; i++) {
            if (count1 == 0 && arr[i] != element2) {
                count1 = 1;
                element1 = arr[i];
            } else if (count2 == 0 && arr[i] != element1) {
                count2 = 1;
                element2 = arr[i];
            } else if (arr[i] == element1) {
                count1++;
            } else if (arr[i] == element2) {
                count2++;
            } else
                count1--, count2--;
        }
        vector<int>lst;
        int cnt1=0,cnt2=0;
        for(int i=0;i<n;i++){
            if(arr[i]==element1){
                cnt1++;
            }
            if(arr[i]==element2){
                cnt2++;
            }
        }
        if(cnt1>(n/3))
        lst.push_back(element1);
        if(cnt2>(n/3))
        lst.push_back(element2);
        sort(lst.begin(),lst.end());

        return lst;
    }
};