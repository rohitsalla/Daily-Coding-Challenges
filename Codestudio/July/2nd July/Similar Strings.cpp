#include <bits/stdc++.h> 
vector<int> similarStrings(int n, string a, string b, string c) {
  // Write your code here.
  // Declare two variables mx and mn
  int mn = INT_MAX;
  int mx = INT_MIN;
  // Run a loop from 0 to n-1
  for(int i=0;i<n;i++){
    // Diff var to store the cur diff
    int diff = 0;
    // cal func val for string a and b
    for(int j=0;j<n;j++){
      diff += abs(a[j]-b[j]);
    }
    // cal fun val for string a and c
    for(int j=0;j<n;j++){
      diff += abs(a[j]-c[j]);
    }
    // update mn and mx values
    mn = min(mn,diff);
    mx = max(mx,diff);

    // Rotate the string to left by 1
    reverse(a.begin(),a.begin()+1);
    reverse(a.begin()+1,a.end());
    reverse(a.begin(),a.end());
  }
  vector<int> ans;
  ans.push_back(mx);
  ans.push_back(mn);

  return ans;
  
}