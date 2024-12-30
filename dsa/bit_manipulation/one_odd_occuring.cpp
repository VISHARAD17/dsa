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
    /* in a give array one number occurs odd number of times and other numbers occurs even numbers of time\
     * identiy than one number*/
    void oddOccuringNum(vector<int>&nums){
        // use xor, since it will remove the pairs for even occuring numbers
        // since, y ^ y = 0
        int ans = nums[0];
        const int n = nums.size();
        for(int i=1; i<n; i++){
            ans ^= nums[i];
        }
        cout << ans << "\n";
    }

};

int main()
{
    Solution st;
    vector<int>nums = {4, 3, 4, 4, 4, 5, 5};
    st.oddOccuringNum(nums);
    return 0;
}
