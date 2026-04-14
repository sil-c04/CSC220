class Solution {
public:
    void sortColors(vector<int>& nums) {
        int k = nums.size();
        vector<int> temp_nums(3,0); // Array with 3 elements: 0, 1, 2
        vector<int> sorted_nums(k); // Array same size as nums

        // Creates the frequency array
        for (int i : nums) {
            temp_nums[i]++;
        }
        // Transforms temp_nums for cumulative counts
        for (int j = 1; j < 3; j++) {
            temp_nums[j] += temp_nums[j - 1];
        }
        // Builds sorted array while decrementing to maintain stability
        for (int i = k - 1; i >= 0; i--) {
            int curr_num = nums[i];
            int position = temp_nums[curr_num] - 1;
            sorted_nums[position] = curr_num;
            temp_nums[curr_num]--;
        }
        nums = sorted_nums;
    }
};