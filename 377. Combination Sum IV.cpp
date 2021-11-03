class Solution {
    int* dp;
    bool isInit = false;
public:
    int combinationSum4(vector<int>& nums, int target) {
        if (!isInit) {
            dp = new int[target + 1];
            for (int i = 0; i<target + 1; i++) {
                dp[i] = -1;
            }
            isInit = true;
        }
        
        if (dp[target] >= 0) {
            return dp[target];
        }

        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (target - nums[i] > 0) {
                res += combinationSum4(nums, target - nums[i]);
            }
            else if (target - nums[i] == 0) {
                res += 1;
            }
        }
        
        dp[target] = res;
        
        return res;
    }
};
