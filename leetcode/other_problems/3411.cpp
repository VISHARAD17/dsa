/* 3411.Maximum Subarray with equal products */


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
private:
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    int lcm(int a, int b) {
        return (a / gcd(a, b)) * b;
    }
public:
    int maxLength(vector<int> &nums){
        const int n = nums.size();
        int len = INT_MIN;

        for(int i=0; i<n; i++){
            int curLcm = nums[i], curGcd = nums[i];
            double curProd = 1.0/nums[i];
            for(int j=i+1; j<n; j++){
                curProd /= nums[j];
                curGcd = gcd(nums[j], curGcd);
                curLcm = lcm(nums[j], curLcm);
                if(curProd * curLcm * curGcd > 0.99999999999) len = max(len, j-i+1);
            }
        }
        return len;
    }
};

int main()
{
    vector<int> nums = {1,2,1,2,1,1,1};
    Solution st;
    cout << st.maxLength(nums);
    return 0;
}
