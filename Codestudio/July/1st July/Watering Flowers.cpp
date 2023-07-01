int totalSteps(int n, int k, vector<int> &flowers) {
    //    Write your code here
    int c = k;int s=0;
    for(int i=0;i<n;i++){
        if(flowers[i]<=c){
            c-=flowers[i];
        }
        else{
            s += (2*i);
            c = k - flowers[i];
        }
        ++s;
    }
    return s;
}