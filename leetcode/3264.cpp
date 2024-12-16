// 3264.Final Array state after k multiplication
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
    vector<int> getFinalState(vector<int>& nums, int k, int m){
        const int n = nums.size();
        while(k--){
            int minEleIdx = min_element(nums.begin(), nums.end()) - nums.begin();
            nums[minEleIdx] *= m;
        }
        return nums;
    }

};

int main()
{
    vector<int>nums = {2,1,3,5,6};
    int k = 5, m = 2;
    Solution st;
    vector<int>res = st.getFinalState(nums, k, m);
    for(int &r: res) cout << r << " ";
    return 0;
}
