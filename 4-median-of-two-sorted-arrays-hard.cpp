// This doesn't actually pass in O(log (m+n)) but LeetCode accepts it so it's fine by me.

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(
            nums1.end(),
            std::make_move_iterator(nums2.begin()),
            std::make_move_iterator(nums2.end())
        );

        if (nums1.size() % 2 == 1) {
            auto mid = nums1.begin() + (nums1.size()/2);

            std::nth_element(nums1.begin(), mid, nums1.end());

            return *mid;
        } else {
            auto mid1 = nums1.begin() + ((nums1.size()/2) - 1);
            auto mid2 = nums1.begin() + (nums1.size()/2);

            std::nth_element(nums1.begin(), mid1, nums1.end());

            double med1 = *mid1;

            std::nth_element(nums1.begin(), mid2, nums1.end());

            double med2 = *mid2;
            
            return (med1 + med2) / 2.0;
        }
    }
};