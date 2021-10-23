class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int size = A.size();
        if(size < 3) return 0;
        int cur_diff = A[1]-A[0], straight = 0, res = 0;
        vector<int> dp(A.size(),0);
        for(int i = 2 ; i < A.size() ; i++)
        {
            if(cur_diff == A[i]-A[i-1])
                dp[i] = dp[i-1] + (++straight);
            else
            {
                res += dp[i-1]; 
                dp[i] = straight = 0;
                cur_diff = A[i] - A[i-1];
            }
        }
        res += dp[size-1];
        return res;
    }
};
