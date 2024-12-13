#include <climits>
#include <vector>
#include <algorithm>
#include <numeric>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h> 
#include <iostream>
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;
#define all(x) (x).begin(), (x).end()

class Solution{
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r){
        const int n = nums.size();
        int minSum = INT_MAX;
        for(int i=0; i<n; i++){
            for(int len = l; len<=r; len++){
                int startIdx = i, endIdx = i+len;
                
                if(endIdx-1 < n){
                    int sum = accumulate(nums.begin()+startIdx, nums.begin()+endIdx, 0);
                    if(sum > 0) minSum = min(minSum, sum), cout << "sum: " << sum << "\n";
                }
                
            }
        }

        return (minSum == INT_MAX ? -1 : minSum);
    }
};

int main()
{
    Solution st;
    vector<int>nums = {3, -2, 1, 4};
    int l = 2, r=3;
    cout << st.minimumSumSubarray(nums, l, r) << endl;
    return 0;
}
