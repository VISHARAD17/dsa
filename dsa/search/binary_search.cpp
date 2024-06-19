/*
 * Binaray Search : works on sorted list
 *
 * find an element in a given array and return its index
 *
 * time complexity : is heigh of the binary search tree ( log(N) with base 2)
 * space : constant space, o(1) -> iterative solution
 * 
 * */

#include<iostream>
#include <vector>
using namespace std;

// iterative solution
int binaray_search(vector<int>a, int x){
    const int n = a.size();
    int left = 0;
    int right = n-1;

    while(left <= right){
        int mid = (left+right)/2;
        if(a[mid] == x) return mid;
        else if(a[mid] < x) left = mid+1;
        else right = mid -1;
    }
     
    return -1;

}

//recursive solution
int binary_search_recur(vector<int>a, int x, int low, int high){
    if(low > high) return -1;

    int mid = (low+high)/2;
    if(a[mid] == x) return mid;
    else if(a[mid] > x) binary_search_recur(a, x, low, mid-1); 
    return binary_search_recur(a, x, mid+1, high); 
}

int main(){
    int n, x;
    cin >> n >> x;
    vector<int>a(n);
    for(auto &x: a) cin >> x;

    cout << "Binray search : " << binaray_search(a, x) << "\n";
    cout << "binary search using recursion : " << binary_search_recur(a, x, 0, n-1) << "\n";
}
