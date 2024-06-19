/*
 * search in sorted rotated array (using binary array), how many times the original array is rotated
 * is not given
 *
 * thumb rule : whenever there is sorted array always use binray search to laverage the sorted pattern
 *
 * ex.
 * arr = [10, 20, 30, 40, 50, 8, 9], original array  = [8, 9, 10, 20 ,30, 40, 50]
 * val = 30
 * ans = 2
 * 
 * - compare middle element with the corner elements to decide which half is sorted ( one of the half either left or right will always be sorted)
 * - check the sorted half range to check whether ele lies in that half or not otherwise go to other half 
 *
 * time complexity is log2(n)
 * 
 *
 * */


#include <iostream>
#include<vector>
using namespace std;

int searchInRotatedArray(vector<int>nums, int x){
    const int n = nums.size();
    int low = 0, high = n-1;

    while(low <= high){
        int mid = (low+high)/2;
        if(nums[mid] == x) return mid;

        if(nums[low] <= nums[mid]){
            // left half sorted
            // check of x falls in that left half or not
            if(x>= nums[low] and x<= nums[mid]) high = mid-1;
            else low = mid+1;
        }
        else{
            // right half sorted
            if(x>nums[mid] and x<= nums[high]) low = mid+1;
            else high = mid-1;
        }
    }
    return 0;
}

int main(){
    int n, x;
    cin >> n >> x;
    vector<int>a(n);
    for(auto &x: a) cin >> x;

    /*
     * sample input
    6 5
    10 20 40 60 5 8
    * */

    cout << "searching in rotated array : " << searchInRotatedArray(a, x) << "\n";
}
