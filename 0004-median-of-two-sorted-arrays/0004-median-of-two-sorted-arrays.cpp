class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int n1 = nums1.size();
        int n2 = nums2.size();

        // Always binary search on smaller array
        if (n1 > n2)
            return findMedianSortedArrays(nums2, nums1);

        int low = 0;
        int high = n1;

        while (low <= high) {

            int cut1 = (low + high) / 2;

            // Total elements needed on left side
            int cut2 = (n1 + n2 + 1) / 2 - cut1;

            int l1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            int r1 = (cut1 == n1) ? INT_MAX : nums1[cut1];

            int l2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
            int r2 = (cut2 == n2) ? INT_MAX : nums2[cut2];

            // Correct partition found
            if (l1 <= r2 && l2 <= r1) {

                // Even total elements
                if ((n1 + n2) % 2 == 0) {
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                }

                // Odd total elements
                return max(l1, l2);
            }

            // Took too many elements from nums1
            else if (l1 > r2) {
                high = cut1 - 1;
            }

            // Took too few elements from nums1
            else {
                low = cut1 + 1;
            }
        }

        return 0;
    }
};