class Solution{
    public:
    int setSetBit(int x, int y, int l, int r){
        // code here
        for(int i=l-1;i<r;i++){
           if(1<<i & y){
               x = 1<<i | x;
           }
        }
        return x;
    }
};