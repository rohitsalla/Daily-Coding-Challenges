#include <bits/stdc++.h> 
using namespace std;
int groupsOfK(vector<string> &strList, int k)
{
    int n = strList.size();
    unordered_map<string,int> umap;
    for(int i=0;i<n;i++){
        for(int j=0;j<strList[i].size();j++){
            umap[strList[i].substr(0,j+1)]++;
        }
    }
    int ans = 0;
    for(auto &it :umap){
        ans+=(it.second)/k;
    }
    return ans;
    // Write your code here.
}