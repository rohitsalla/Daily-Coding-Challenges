
// T.C : o(n*log(s))
// S.C : o(1) 
bool isPossible(vector<int>&arr,int n,int m,int curMin){
    int student = 1;
    int curSum = 0;
    for(int i=0;i<n;i++){
      if (arr[i] > curMin) {
        return false;
      }
      if (curSum + arr[i] > curMin){
          // Inc stu by 1
          student +=1;
          // update currsum
          curSum = arr[i];
          // if students required becomes greater than no. of students,return false
          if(student>m)
          {
              return false;
          }
      }
      else{
          curSum += arr[i];
      }
    }
    return true;
}


int findPages(vector<int>& arr, int n, int m) {
    // Write your code here.
    // if the number student is more than number of books
    if (n < m) {
      return -1;
    }
    // to count the total number of pages
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    // Initialize start as 0 page and End as Total Pages
    int start = 0,end = sum;
    int result = INT_MAX;

    // Traverse until start<=end, binary search
    while(start<=end){
        // check if possible to distribute books using mid as curr min
        int mid = (start+end)/2;
        if(isPossible(arr,n,m,mid)){
            // if yes then find minimum distribution
            result = min(result,mid);
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    } 
    return result;


}