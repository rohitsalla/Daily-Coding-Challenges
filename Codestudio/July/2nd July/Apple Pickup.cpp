#include <bits/stdc++.h> 
int collectApples(vector<vector<int>>& matrix) 
{
    // Write your code here.
    int n = matrix.size();
    // Handling some test cases
    if(matrix[0][0]==-1 or matrix[n-1][n-1]==-1){
        return 0;
    }
    // Initialize DP table
    vector<vector<int>> dp(n,vector<int>(n,-1));
    
    dp[0][0] = matrix[0][0];
    int maxK = 2*n-2;
    for(int k=1;k<=maxK;k++){
        for(int i=min(n-1,k);i>=0;i--){
            if(k-i>=n){
                continue;
            }
            for(int j=min(n-1,k);j>=0;j--){
                if(k-j>=n or matrix[i][k-i]<0 or matrix[j][k-j]<0){
                    dp[i][j] =-1;
                    continue;
                }
                int count = dp[i][j];
                if(i>0){
                    count = max(count,dp[i-1][j]);
                }
                if(j>0){
                    count = max(count,dp[i][j-1]);
                }
                if(i>0 and j>0){
                    count = max(count,dp[i-1][j-1]);
                }
                if(count<0){
                    continue;
                }
                dp[i][j] = count + matrix[i][k-i];
                if(i!=j){
                    dp[i][j] += matrix[j][k-j];
                }
            }
        }
    }
    return max(dp[n-1][n-1],0);
}
