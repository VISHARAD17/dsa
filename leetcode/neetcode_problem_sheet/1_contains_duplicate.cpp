/*
 * 217. Contains Duplicate [ Easy ]
 * */

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
    bool containsDuplicate(vector<int>& nums){
        const int n = nums.size();
        int x = nums[0];
        for(int i=1; i<n; i++) x ^= nums[i];
        return (x == 0 ? false: true);
    }

};

int main()
{
    Solution st;
    vector<int>nums = {1,1,1,3,3,4,3,2,4,2};
    cout << st.containsDuplicate(nums);
    return 0;
}
