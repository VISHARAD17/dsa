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
    /* in the given array there are two odd occuring numbers, print those*/
    void twoOddOccurringNums(vector<int>nums){
        // use xor
        const int n = nums.size();
        int x = nums[0];
        for(int i=1; i<n; i++) x ^= nums[i];

        int k = (x & ~(x-1));

        int res1 = 0, res2 = 0;

        for(int i=0; i<n; i++){
            if((nums[i] & k) == 0) res1 ^= nums[i];
            else res2 ^= nums[i];
        }
        cout << res1 << " " << res2;
    }

};

int main()
{
    vector<int>nums = {3, 4, 3, 4, 5, 4, 4, 6, 7, 7};
    Solution st;
    st.twoOddOccurringNums(nums);
    return 0;
}
