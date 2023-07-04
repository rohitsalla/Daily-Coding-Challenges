int kthElementHelper(vector<int> &arr1,vector<int> &arr2,int m,int n,int k,int st1 = 0, int st2 =0) {
  // Write your code here
  if(st1==m){
      return arr2[st2+k-1];
    }
  if(st2==n){
      return arr1[st1+k-1];
    }
  if(k==1){
      return(arr1[st1] < arr2[st2]) ? arr1[st1] : arr2[st2];
  }
  int cur = k/2;
  if(cur-1 >= m-st1){
      if(arr1[m-1] < arr2[st2+cur-1]){
          return arr2[st2+(k-(m-st1)-1)];
      }
      else{
          return kthElementHelper(arr1,arr2,m,n,k-cur,st1,st2+cur);
      }
  }
  if(cur-1>=n-st2){
      if(arr2[n-1] < arr1[st1+cur-1]){
          return arr1[st1+(k-(n-st2)-1)];    
      }
      else{
          return kthElementHelper(arr1,arr2,m,n,k-cur,st1+cur,st2);
      }
  }
  else{
      if(arr1[cur+st1-1]<arr2[cur+st2-1]){
          return kthElementHelper(arr1,arr2,m,n,k-cur,st1+cur,st2);
      }
      else{
          return kthElementHelper(arr1,arr2,m,n,k-cur,st1,st2+cur);
      }
  }
}


int kthElement(vector<int>&arr1,vector<int>&arr2,int n,int m,int k){
    return kthElementHelper(arr1,arr2,n,m,k);
}