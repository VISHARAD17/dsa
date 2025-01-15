/* 2270. Number of ways to split array */

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

class Solution{
public:
    int waysToSplitArray(vector<int>& nums){
        const int n = nums.size();
        vector<long long>prefixSum(n, 0);
        
        prefixSum[0] = nums[0];
        for(int i=1; i<n; i++) prefixSum[i] = prefixSum[i-1] + nums[i];

        int ans = 0;

        for(int i=0; i<n-1; i++){
            long long left = prefixSum[i], right = prefixSum[n-1] - prefixSum[i];
            // cout << i << " " << left << " " << right << "\n";
            if(left >= right) ans++;
        }

        return ans;
    }

};

int main()
{
    Solution st;
    vector<int>nums = {2, 3, 1, 0};
    cout << st.waysToSplitArray(nums);
    return 0;
}
