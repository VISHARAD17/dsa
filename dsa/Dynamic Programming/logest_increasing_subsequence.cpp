/*
 * Logest Incresing subsequence
 * problem : pick zero or more elements of a give array which are in increasing or non-decreasing order (ele need not be consequent)
 *
 * */

#include <algorithm>
#include<iostream>
#include<vector>
using namespace std;

int iterative_lis(vector<int> a, int n){
    // time - O(n^2), space - O(n)
    vector<int>lis(n);
    lis[0] = 1; // base case 

    for(int i=1; i<n; i++){
        lis[i] = 1;
        for(int j=0; j<i; j++){
            // if strictly increasing then > or if non-decreasing then >=
            if(a[i] > a[j]) lis[i] = max(lis[i], lis[j]+1);
        }
    }
    for(auto &x: lis) cout << x << " ";
    cout << "\n";

    return *max_element(lis.begin(), lis.end());
}

int ceilIdx(int tail[], int l, int r, int x){
    while(r > l){
        int m = (l+r)/2;
        if(tail[m] >= x) r = m;
        else l = m+1;
    }
    return r;
}

int lis(vector<int> nums){
    const int n = nums.size();
    int tail[n], len = 1;
    
    for(int i=1; i<n; i++){
        if(nums[i] > tail[len-1]) tail[len] = nums[i], len++;
        else{
            int c = ceilIdx(tail, 0, len-1, nums[i]);
            tail[c] = nums[i];
        }
    }

    return len;
}


int main(){
    int n;
    cin >> n;

    vector<int>a(n);
    for(auto &x: a) cin >> x;

    int iterative_ans = iterative_lis(a, n);
    int improved_sol = lis(a);

    cout << "recursive sol: " << iterative_ans << "\n";
    cout << "improved sol: " << improved_sol << "\n";
    
    return 0;
}
