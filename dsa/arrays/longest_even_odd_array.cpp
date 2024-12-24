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
    void longestEvenOddSubarray(vector<int>&nums){
        const int n = nums.size();
        int curLen = 1, maxLen = 1;

        for(int i=1; i<n; i++){
            if((nums[i]%2 == 0 and nums[i-1]%2 == 1) || (nums[i]%2 == 1 and nums[i-1]%2 == 0)){
                curLen++;
                maxLen = max(maxLen, curLen);
            }
            else{
                curLen = 1;
            }
        }
        cout << "maxLen : " << maxLen;

    }

};

int main()
{
    vector<int>nums = {5, 10, 20, 6, 3, 8};
    Solution st;
    st.longestEvenOddSubarray(nums);
    return 0;
}
