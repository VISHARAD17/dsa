#include <climits>
#include <iostream>
#include <vector>
#include <algorithm>
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

class Solution{
public:
    // maximum subarray sum for a given array ( contains both positive and negative elements )
    int maxSubarraySum(vector<int>&nums){
        const int n = nums.size();
        vector<int>maxSumArr(n, INT_MIN);
        maxSumArr[0] = nums[0];
        int maxSum = INT_MIN;
        for(int i=1; i<n; i++){
            // maintain maximum subarray sum ending with index i
            maxSumArr[i] = max(nums[i], maxSumArr[i-1] + nums[i]);
            maxSum = max(maxSum, maxSumArr[i]);
        }
        return maxSum;
    }

};

int main()
{
    vector<int>nums = {-5, 1, -2, 3, -1, 2, -2};
    Solution st;
    cout << "maxSum : " << st.maxSubarraySum(nums);
    return 0;
}
