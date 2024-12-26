#include <iostream>
#include <vector>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h> 
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;
#define all(x) (x).begin(), (x).end()

/*
 * given sorted array return the size of unique elements and keep them in the start
 * and rest of the elements in any order
 * ex. nums = {10, 20, 30, 30, 40, 50, 50}, O/P - 5, {10, 20, 30, 40, 50, _, _}
 * */
class Solution{
public:
    int removeDuplicatedFromSortedArray(vector<int>&nums){
        const int n = nums.size();
        int res = 1;
        for(int i=1; i<n; i++){
            if(nums[i-1] != nums[i]){
                nums[res] = nums[i];
                res++;
            }
        }
        return res;
    }

};

int main()
{
    vector<int>nums = {10, 20, 30, 30, 40, 50, 50};
    Solution st;
    int res = st.removeDuplicatedFromSortedArray(nums);
    cout << res;
    cout << "\narray -- ";
    for(int i=0; i<res; i++) cout << nums[i] << " ";
    return 0;
}
