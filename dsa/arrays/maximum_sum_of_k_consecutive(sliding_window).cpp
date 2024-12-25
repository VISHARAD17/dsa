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
    void maxSumOfKConsecutive(vector<int>&nums, int k){
        const int n = nums.size();
        int res = INT_MIN;
        int cur_sum = 0;
        for(int i=0; i<k; i++) cur_sum += nums[i];
        res = max(res, cur_sum);
        for(int i=k; i<n; i++){
            cur_sum -= nums[i-k];
            cur_sum += nums[i];
            res = max(res, cur_sum);
        }
        cout << "max consecutive sum " << res << "\n";
    }

};

int main()
{
    vector<int>nums = {10, 5, -2, 20, 1};
    Solution st;
    st.maxSumOfKConsecutive(nums, 3);
    return 0;
}
