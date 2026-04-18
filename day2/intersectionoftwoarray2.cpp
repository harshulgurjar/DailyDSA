class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
         sort(nums1.begin(), nums1.end());  // Sorting nums1
        sort(nums2.begin(), nums2.end());  // Sorting nums2

        vector<int> result;
        int i = 0, j = 0;

        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                i++;  // Move i to the next larger element
            } else if (nums1[i] > nums2[j]) {
                j++;  // Move j to the next larger element
            } else {
                result.push_back(nums1[i]); // Found a common element
                i++;
                j++;
            }
        }

        return result;
    }
};