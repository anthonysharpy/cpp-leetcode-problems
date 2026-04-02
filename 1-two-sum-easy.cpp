class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size()-1;

        while (true) {
            if (nums[start] + nums[end] == target) {
                return {start, end};
            }

            end--;

            if (end == start) {
                start++;
                end = nums.size()-1;
            }
        }

        throw "No solution found";
    }
};