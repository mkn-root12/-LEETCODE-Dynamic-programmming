class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0)
                    dp[i][j]=j;
                else if(j==0)
                    dp[i][j]=i;
                else if(word1[i-1]==word2[j-1])
                    dp[i][j]=dp[i-1][j-1];
                else
                    dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
                    
            }
        }
        return dp[n][m];
    }
};



/*another approach*/
//DP
//Runtime: 32 ms, faster than 17.80% of C++ online submissions for Edit Distance.
//Memory Usage: 8.9 MB, less than 87.50% of C++ online submissions for Edit Distance.
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        
        /*
        different from other problem,
        here dp[0][?] and dp[?][0] are meaningful.
        They represents the situation when word1 is "" and when word2 is ""
        */
        vector<vector<int>> dp(m+1, vector(n+1, 0));
        
        for(int i = 0; i <= m; i++){
            for(int j = 0; j <= n; j++){
                if(i == 0 && j == 0){
                    dp[i][j] = 0;
                }else if(j == 0){
                    /*
                    word1: [0, i-1] //i 's upper limit is m
                    word2: ""
                    
                    this means we need to delete i char from word1
                    */
                    dp[i][j] = i;
                }else if(i == 0){
                    /*
                    word1: ""
                    word2: [0, j-1] //j 's upper limit is n
                    */
                    dp[i][j] = j;
                }else if(word1[i-1] == word2[j-1]){
                    //no op
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = min({
                        //remove word1[i-1]
                        dp[i-1][j],
                        //insert word2[j-1]
                        dp[i][j-1],
                        //replace word1[i-1] to word2[j-1]
                        dp[i-1][j-1]
                        }) + 1;
                }
            }
        }
        
        return dp[m][n];
    }
};

//DP, O(1) space
//https://leetcode.com/problems/edit-distance/discuss/25846/C%2B%2B-O(n)-space-DP
//Runtime: 16 ms, faster than 61.68% of C++ online submissions for Edit Distance.
//Memory Usage: 6.3 MB, less than 100.00% of C++ online submissions for Edit Distance.
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        
        vector<int> dp(n+1, 0);
        int dp_is1_js1;
        
        for(int i = 0; i <= m; i++){
            for(int j = 0; j <= n; j++){
                int tmp = dp[j];
                if(i == 0 && j == 0){
                    dp[j] = 0;
                }else if(j == 0){
                    /*
                    word1: [0, i-1] //i 's upper limit is m
                    word2: ""
                    
                    this means we need to delete i char from word1
                    */
                    dp[j] = i;
                }else if(i == 0){
                    /*
                    word1: ""
                    word2: [0, j-1] //j 's upper limit is n
                    */
                    dp[j] = j;
                }else if(word1[i-1] == word2[j-1]){
                    //no op
                    dp[j] = dp_is1_js1;
                }else{
                    dp[j] = min({
                        //remove word1[i-1]
                        //dp[i-1][j]
                        dp[j],
                        //insert word2[j-1]
                        //dp[i][j-1]
                        dp[j-1],
                        //replace word1[i-1] to word2[j-1]
                        //dp[i-1][j-1]
                        dp_is1_js1
                        }) + 1;
                }
                dp_is1_js1 = tmp;
            }
        }
        
        return dp[n];
    }
};

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
    int min(int x, int y, int z) {
        return std::min(std::min(x, y), z);
    }

    int edit_distance(string s1, string s2, int m, int n) {
        // if first string is empty, only option is insert all chars in s2.
        if (m == 0) return n;
        // if second string is empty, only option is remove all chars in s1.
        if (n == 0) return m;

        // if the last chars are equal, ignore them, remove the distance for
        // remaining strings
        if (s1[m-1] == s2[n-1]) {
            return edit_distance(s1, s2, m - 1, n - 1);
        }
        // If last characters are not same, consider all three
        // operations on last character of first string, recursively
        // compute minimum cost for all three operations and take
        // minimum of three values.
        return 1 + min(edit_distance(s1, s2, m, n - 1), // insert, so s1[m+1] == s2[n]
                       edit_distance(s1, s2, m - 1, n), // remove
                       edit_distance(s1, s2, m - 1, n - 1) // replace
                        );
    }
public:
    // return the minimum number of operations to convert s1 to s2
    int edit_distance(string s1, string s2) {
        return edit_distance(s1, s2, s1.length(), s2.length());
    }

    int edit_distance_dp(string s1, string s2) {
        int m = s1.length(), n = s2.length();
        vector< vector<int> > dp(m+1, vector<int>(n+1, 0));

        for (int i = 0; i < m + 1; ++i) {
            for (int j = 0; j < n + 1; ++j) {
                if (i == 0) {
                    // if no chars in s1, insert all chars of s2
                    dp[i][j] = j;
                }
                else if (j == 0) {
                    // if no chars in s2, remove all chars in s1
                    dp[i][j] = i;
                }
                else if (s1[i-1] == s2[j-1]) {
                    // if last chars are same, ignore them and recur for remaining
                    dp[i][j] = dp[i-1][j-1];
                }
                else {
                    // if not same, consider all possibilities and find min
                    dp[i][j] = 1 + min(dp[i][j-1], // insert
                                       dp[i-1][j], // remove
                                       dp[i-1][j-1] // replace
                                   );
                }
            }
        }

        return dp[m][n];
    }
};

int main() {
    string str1 = "sunday";
    string str2 = "saturday";

    Solution sol;
    cout << "The edit distance between " << str1 << " and " << str2 << " is " <<
    sol.edit_distance( str1 , str2) << endl;

    cout << "The edit distance between " << str1 << " and " << str2 << " is " <<
    sol.edit_distance_dp( str1 , str2) << endl;
    return 0;
}
