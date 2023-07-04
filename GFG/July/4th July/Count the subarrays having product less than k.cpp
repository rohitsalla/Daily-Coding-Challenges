class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        long long int j=0;
        long long int count=0;
        long long int sum=1;
        int i=0;
        if(k<=1)
            return 0;
       while(i<a.size()){
            sum=sum*a[i];
                while(sum>=k)
                    sum=sum/a[j++];
           count=count+i-j+1;
           i++;
        }
        return count;
    }
};