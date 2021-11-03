class Solution {
public:
    int integerBreak(int n) {
        if(n == 2)
            return 1;
        else if(n == 3)
            return 2;
        else if(n%3 == 0)
            return pow(3, n/3);
        else if(n%3 == 1)
            return 2 * 2 * pow(3, (n - 4) / 3);
        else 
            return 2 * pow(3, n/3);
    }
};
/*second approach*/
class Solution {
public:
    int integerBreak(int n) {
        if(n == 2) return 1;
        if(n == 3) return 2;
        if(n == 4) return 4;
        if(n == 5) return 6;
        if(n == 6) return 9;
        
        int *dp = (int *)malloc(sizeof(int) * (n + 1));
        dp[2] = 1,dp[3] = 2,dp[4] = 4,dp[5] = 6,dp[6] = 9;
        for(int i=7;i<=n;i++){
            dp[i] = 2 * dp[i-2] >  3 * dp[i-3] ? 2 * dp[i-2] : 3 * dp[i-3];
        }
        int ans = dp[n];
        free(dp);
        return ans;
    }
};


int main(){
    Solution solve;
    
    for(int i=3;i<59;i++){
        cout<<i<<" : "<<solve.integerBreak(i)<<endl;
    }
    
    return 0;
}
