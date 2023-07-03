#include <bits/stdc++.h> 
using namespace std;

vector<int> CountingSort(int n,vector<int>&arr,int pow10){
    vector<int> temp(n,0);
    vector<int> bin(10,0);
    for(int i=0;i<n;i++){
        bin[int(arr[i]/pow10)%10] +=1;
    }
    for(int i=1;i<10;i++){
        bin[i] += bin[i-1];
    }
    for(int i=n-1;i>=0;i--){
        temp[bin[int(arr[i]/pow10)%10]-1] = arr[i];
        bin[int(arr[i]/pow10)%10] -=1;
    }
    return temp;
}


vector<int> radixSort(int n, vector<int>& arr) {
    // cal max elememt in the Input array
    int maxElement = INT_MIN;
    for(int u: arr){
        maxElement = max(maxElement,u);
    }
    // Initialise the pow10 is equal to 1
    int pow10 = 1;
    // Iterate over all digits from 0th position to the max pow 10th pos
    while(maxElement>=pow10){
        // call the helper function to sort the array based on pow10 digit
        arr = CountingSort(n,arr,pow10);
        // pow10 is multiplies by 10
        pow10 *= 10;
    }
    // return array
    return arr;
}
