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
    vector<int> constructTransformedArray(vector<int>& nums){
        const int n = nums.size();
        if(n <= 1) return nums;
        vector<int>res(n, 0);
        int  itr = n, idx = 0;
        while(itr--){
            int cur = idx;
            if(nums[idx] > 0){
                cur = (cur + nums[idx])%n;
            }
            else if(nums[idx] < 0){
                int minus = cur - (abs( nums[cur]))%n;
                if(minus >= 0) cur = minus;
                else cur = n + minus;
            }
            res[idx] = nums[cur];
            idx++;
        }
        return res;
    }

};

int main()
{
    Solution st;
    vector<int>nums = {-10};
    vector<int>res = st.constructTransformedArray(nums);
    for(int &x: res) cout << x << " ";
    return 0;
}
