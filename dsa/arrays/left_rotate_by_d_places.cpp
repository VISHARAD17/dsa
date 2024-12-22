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
    void letRotateByDPlaces(vector<int>&nums, int d){
        const int n = nums.size();
        d %= n; 
        vector<int>tmp(nums.begin(), nums.begin()+d);

        for(int i=d; i<n; i++) nums[i-d] = nums[i];

        for(int i=n-d; i<n; i++) nums[i] = tmp[i-n+d];

        tmp.clear();
        for(int &x: nums) cout << x << " ";
    }

};

int main()
{
    Solution st;
    vector<int>nums = {1, 2, 3, 4, 5};
    st.letRotateByDPlaces(nums, 2);
    return 0;
}
