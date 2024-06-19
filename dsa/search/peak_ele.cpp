/*
 *
 * find a peak element in an array ( peak ele is the element which not smaller ( can be equal ) than its neighbours )
 *
 *
 * ex. arr = [10, 20, 15, 5, 23, 90, 67]
 * ans = 20 or 90
 *
 * tip:  for left most and right most ele they need to be greater than their right and left elements respectively to be
 * considered as peak elements
 * */


#include<iostream>
#include <vector>
using namespace std;

int naiveSol(vector<int>a){
    const int n = a.size();
    if(n == 1) return *a.begin();
    if(a[0] > a[1]) return a[0];
    if(a[n-1] > a[n-2]) return a[n-1];

    for(int i=1; i<n-2; i++){
        if(a[i]>a[i-1] and a[i]>a[i+1]) return a[i];
    }
    return -1; // if not present any peak element
}

int peakEle(vector<int>a){

    return 0;
}

int main(){
    int n;
    cin >> n;
    
    vector<int>a(n);
    for(auto &x: a) cin >> x;

    cout << "peak element" << peakEle(a) << "\n";
    return 0;
}
