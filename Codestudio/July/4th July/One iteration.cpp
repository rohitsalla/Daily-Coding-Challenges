#include <bits/stdc++.h> 
int oneIteration(vector<int> A)
{
    // Write your code here.   
    int mx = INT_MIN;
    int smx = INT_MIN;
    int n = A.size();

    for(int i=0;i<n;i++){
        if(A[i]>mx){
            smx = mx;
            mx = A[i];
        }
        else if(A[i]>smx){
            smx = A[i];
        }
    }
    return smx+mx;
}