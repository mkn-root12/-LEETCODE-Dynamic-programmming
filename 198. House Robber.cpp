class Solution {
public:
    public:
    int rob1(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        int n = nums.size();
        vector<int> dp(n, 0);
        
        for (int i = 0; i < n; ++i) {
            if (i >= 2) {
                dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
            } else if (i >= 1) {
                dp[i] = max(nums[i], dp[i - 1]);
            } else 
                dp[i] = nums[i];
        }
        return dp[n - 1];
    }
    
    int rob(vector<int>& nums) {
        int a = 0, b = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int first = max(b + nums[i], a);
            b = a;
            a = first;
        }
        return a;
    }
};
