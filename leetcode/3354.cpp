#include <vector>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h> 
#include<iostream>
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;
#define all(x) (x).begin(), (x).end()

class Solution{

public:
    int countValidSelections(vector<int>& nums) {
        int ans = 0;
        const int n = nums.size();
        vector<int>rightSum(n, 0), leftSum(n, 0);

        for(int i=1; i<n; i++) leftSum[i] = leftSum[i-1]+ nums[i-1];
        for(int i=n-2; i>=0; i--) rightSum[i] = rightSum[i+1] + nums[i+1];

        for(int i=0; i<n; i++){
            if(nums[i] == 0){
                if(leftSum[i] == rightSum[i]) ans += 2;
                else if(abs(leftSum[i] - rightSum[i]) == 1) ans++;
            }
        }

        return ans;
    }

};

int main()
{
    Solution st;
    vector<int>nums = {1,0,2,0,3};
    cout << st.countValidSelections(nums);
    // for(auto &x: nums) cout << x << " ";
    return 0;
}
