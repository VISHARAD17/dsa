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

// NOTE: Prefix sum can be used when given a fix array and multiple range queries
// INFO: prefix sum for ith ele is the sum of elements before i_th ele including the ele
class Solution{
public:
    // given an array, return the sum between l and r
    void prefixSum(vector<int>nums, int l, int r){
        const int n = nums.size();
        vector<int>prefix(n, 0);
        prefix[0] = nums[0];

        for(int i=1; i<n; i++) prefix[i] = nums[i] + prefix[i-1];
        
        int sum = prefix[r];
        if(l != 0) sum -= prefix[l-1];
        /* cout << "predix sum array ";
        for(auto &x: prefix) cout << x << " ";
        cout << endl; */
        cout << "sum between l=" << l << " and " << "r= " << r << " is " << sum  << endl;
    }
};

int main()
{
    vector<int>nums = {2, 8, 3, 9, 6, 5, 4};
    Solution st;
    st.prefixSum(nums, 0, 2);
    st.prefixSum(nums, 1, 3);
    st.prefixSum(nums, 2, 6);
    return 0;
}
