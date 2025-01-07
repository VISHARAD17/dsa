/*
 * Problem : Index of first occurence in the sorted array
 *
 * find the first occurent of x in an given sorted array (using binary search) / if not present return -1
 *
 * ex. arr = [1, 10, 10, 10, 20, 20, 40]    x = 20
 * ans = 4
 *
 * time complexity for iterative : 0(log2(n)) and space : O(1)
 * time complexity for recursive : O(log2(n)) and space : height of binray tree  O(log2(n))
 * 
 * variation : 
 * 1. count number of occurences : last_occurence - first_occurence + 1;
 * 2. count no. of 1s in soted array : get first occurence of 1, then count = n - first_occurence;
 *
 * */

#include<iostream>
#include<vector>
using namespace std;

// index of first occurence
int indexOfFirstOccurence(vector<int>a, int x){
    const int n = a.size();
    int low = 0, high = n-1;

    while(low <= high){
        int mid = (low+high)/2;

        if(a[mid]>x) high = mid-1;
        else if(a[mid]<x) low = mid+1;
        else{
            // first occurence
            if(mid == 0 or a[mid-1] != a[mid]) return mid;
            else high = mid-1;
        }
    }
    return -1;
}

int indexOfLastOccurence(vector<int>a, int x){
    const int n = a.size();
    int low = 0, high = n-1;

    while(low <= high){
        int mid = (low+high)/2;

        if(a[mid]>x) high = mid-1;
        else if(a[mid]<x) low = mid+1;
        else{
            // difference from the above first occurence code
            // last occurence
            if(mid == n-1 or a[mid+1] != a[mid]) return mid;
            else low = mid+1;
        }
    }
    return -1;

}

int countOoccurences(vector<int>&nums, int x){
    int first = indexOfFirstOccurence(nums, x);
    if(first == -1) return 0;
    
    int last = indexOfLastOccurence(nums, x);
    return last-first+1;
}

int firstOccRecur(vector<int> a, int x, int low, int high){
    if(low < high) return -1;

    int mid = (low+high)/2;
    if(a[mid] < x) firstOccRecur(a, x, low+1, high);
    else if(a[mid] > x) firstOccRecur(a, x, low, mid-1);

    if(mid == 0 or a[mid-1] != a[mid]) return mid;
    return firstOccRecur(a, x, low, mid-1);
} 


int main(){
    vector<int>nums ={1, 10, 10, 10, 20, 30, 40, 40, 50};
    cout << "for array :";
    for(auto &x: nums) cout << x << " ";
    cout << "\n";
    cout << "index of first occurence: " << indexOfFirstOccurence(nums, 10) << "\n";
    cout << "index of last occurence: " << indexOfLastOccurence(nums, 10) << "\n";
    cout << "number of occurence " << countOoccurences(nums, 10) << "\n";
}
