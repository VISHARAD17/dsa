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

/*
 * max diff i.e. arr_j - arr_i such that j > i
 * */
class Solution{
public:
    void maxDiffInOrder(vector<int>&nums){
        // INFO: keep track of min element so fat
        const int n = nums.size();
        int maxDiff = INT_MIN, minEleSoFar = nums[0];

        for(int i=1; i<n; i++){
            // maintain min element so far
            minEleSoFar = min(nums[i], minEleSoFar);
            maxDiff = max(maxDiff, nums[i] - minEleSoFar);
        }
        cout << "optimized: maxDiff " << maxDiff << "\n";
    }

    void naive_maxDiffInOrder(vector<int>&nums){
        const int n = nums.size();
        int maxDiff = INT_MIN;

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                maxDiff = max(maxDiff, nums[j] - nums[i]);
            }
        }
        cout << "naive: maxDiff " << maxDiff << "\n";
    }

};

int main()
{
    Solution st;
    vector<int>nums = {2, 3, 10, 6, 4, 8, 1};
    st.naive_maxDiffInOrder(nums);
    st.maxDiffInOrder(nums);
    return 0;
}
