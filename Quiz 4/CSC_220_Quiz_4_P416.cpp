class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        
        // Calculate total sum
        for (int i : nums) {
            totalSum += i;
        }

        // If total sum is odd, then false
        if (totalSum % 2 != 0) {
            return false;
        }

        int target = totalSum / 2;
        // Create dp table initially set to false.
        vector<bool> dp(target + 1, false);
        // Base case: Sum of 0.
        dp[0] = true; // empty subset.
        for (int i : nums) {
            for (int j = target; j >=i; j--) {
                dp[j] = dp[j] || dp[j - i];
           }
        }
        return dp[target];
    }
};