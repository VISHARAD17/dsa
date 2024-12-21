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
 * print the index of second largest element 
 * nums = {20, 10, 20, 8, 12}  o/p  = 4
 * nums = {10, 10, 10}   O/P = -1
 * */


class Solution{
public:
    int second_largest_element(vector<int>&nums){
        int secondLargestIdx = -1;
        int largestIdx = 0;
        const int n = nums.size();

        for(int i=1; i<n; i++){
            if(nums[largestIdx]< nums[i]){
                secondLargestIdx = largestIdx;
                largestIdx = i;
            }
            else if(nums[i] != nums[largestIdx]){
                if(secondLargestIdx == -1 or nums[i] > nums[secondLargestIdx]){
                    secondLargestIdx = i;
                }
            }
        }
        return secondLargestIdx;
    }
};

int main()
{
    Solution st;
    vector<int>nums = {20, 10, 20, 8, 12};
    cout << st.second_largest_element(nums);
    return 0;
}
