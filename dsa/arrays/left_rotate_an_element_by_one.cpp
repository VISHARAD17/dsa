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
    void LeftRotateByOne(vector<int>&nums){
        const int n = nums.size();
        int tmp = nums[0];
        for(int i=0; i<n-1; i++) nums[i] = nums[i+1];
        nums[n-1] = tmp;

        cout << "array -- ";
        for(int &x: nums) cout << x << " ";
    }

};

int main()
{
    vector<int>nums = {1, 2, 3, 4, 5};
    Solution st;
    st.LeftRotateByOne(nums);
    return 0;
}
