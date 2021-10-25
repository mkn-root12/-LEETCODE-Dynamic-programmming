class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>>tri;
        vector<int>ans;
        
        if(rowIndex == 0)
        {
            ans.push_back(1);
            return ans;
        }
        tri.push_back({1});
        int i,j;
        //dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
        for(i=1;i<rowIndex+1;i++)
        {
            vector<int>v;
            v.push_back(1);
            j=1;
            while(j<i)
            {
                v.push_back(tri[i-1][j-1]+tri[i-1][j]);
                j++;
            }
            v.push_back(1);
            tri.push_back(v);
        }
        ans = tri[rowIndex];
        return ans;
    }
};
   
