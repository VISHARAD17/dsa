/*
 * maximum sum increasing subsequnce - max sum of increasing subsequence
 * - variation of LIS
 * - same logic as LIS, instead of computing len, using element value
 * */


#include <algorithm>
#include<iostream>
#include<vector>
using namespace std;


int maxSumSub(vector<int>arr){
    const int n = arr.size();
    vector<int>maxArr(n, 0);
    maxArr[0] = arr[0];

    for(int i=1; i<n; i++){
    maxArr[i] = arr[i];
        for(int j=0; j<i; j++){
            if(arr[i] > arr[j]) maxArr[i] = max(maxArr[i], maxArr[i]+arr[j]); 
        }
    }
    return *max_element(maxArr.begin(), maxArr.end());
}

int main(){
    vector<int>a =  {3, 20, 4, 6, 7, 30};
    // ans : 13
    cout << maxSumSub(a);
}
