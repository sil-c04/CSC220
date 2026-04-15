class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        
        if (n < 2) return 0;

        // Find max and min values
        int min_num = nums[0];
        int max_num = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] < min_num) min_num = nums[i];
            if (nums[i] > max_num) max_num = nums[i];
        }

        if (min_num == max_num) return 0; // Gap is 0

        // Calculate bucket size and amount
        int range = max_num - min_num;
        int bucket_size = range / (n - 1); // (n - 1) to ensure one empty bucket
        if (bucket_size == 0) bucket_size = 1; // To prevent division by 0

        int buckets = (range / bucket_size) + 1;

        // Initialize buckets
        vector<int> bucket_min(buckets);
        vector<int> bucket_max(buckets);
        vector<bool> has_data(buckets, false);

        for (int x : nums) {
            int idx = (x - min_num) / bucket_size;
            if (!has_data[idx]) {
                bucket_min[idx] = x;
                bucket_max[idx] = x;
                has_data[idx] = true;
            } else {
                if (x < bucket_min[idx]) bucket_min[idx] = x;
                if (x > bucket_max[idx]) bucket_max[idx] = x;
            }
        }

        // Calculate the max gap between buckets
        int max_gap = 0;
        int prev_max = max_num; // Use for finding first bucket
        
        // Find the first filled bucket's max to start comparison
        for (int i = 0; i < buckets; i++) {
            if (has_data[i]) {
                prev_max = bucket_max[i];
                // Check if this first bucket's min creates a gap with the global min
                break;
            }
        }

        // Iteration to find gaps between non-empty buckets
        int current_prev_max = min_num; 
        for (int i = 0; i < buckets; i++) {
            if (!has_data[i]) continue;

            int current_gap = bucket_min[i] - current_prev_max;
            if (current_gap > max_gap) {
                max_gap = current_gap;
            }
            current_prev_max = bucket_max[i];
        }
        return max_gap;
    }
};