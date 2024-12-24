#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h> 
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;
#define all(x) (x).begin(), (x).end()

/* nums_i represents the bar height in the container 
 * get the maximum water that can be trapped in such container or can be trapped in such structure
 * nums = {2, 0, 2}
 *
 * container = |   |
 *             |   |
 *             0 1 2
 *
 * so, total water = 2 x 2 = 4
 *
 * */

class Solution{
public:
    // time - O(n^2)
    int naive_trappingRainWater(vector<int>&nums){
        /* for a given bar maximum water that can be stored on top of it, 
         * will be the min(max_heigh_on_left, max_heigh_on_right) - cur_bar_heigh*/
        const int n = nums.size();
        int totalWater = 0;
        for(int i=1; i<n-1; i++){
            int curHeight = nums[i];
            int leftMax = curHeight, rightMax = curHeight;
            for(int left=0; left<i; left++) leftMax = max(leftMax, nums[left]);
            for(int right=i+1; right<n; right++) rightMax = max(rightMax, nums[right]);
            totalWater += min(leftMax, rightMax) - curHeight;
        }
        return totalWater;
    }

    // pre-compute the leftMax and rightMax before looping
    int trappingRainWater(vector<int>&nums){
        const int n = nums.size();
        int totalWater = 0;
        vector<int>leftMax(n, 0), rightMax(n, 0);
        leftMax[0] = nums[0], rightMax[n-1] = nums[n-1];

        for(int i=1; i<n; i++) leftMax[i] = max(leftMax[i-1], nums[i]);
        for(int i=n-2; i>=0; i--) rightMax[i] = max(rightMax[i+1], nums[i]);

        for(int i=1; i<n-1; i++) totalWater += min(leftMax[i], rightMax[i]) - nums[i];

        return totalWater;
    }

};

int main()
{
    Solution st;
    vector<int>nums = {3, 0, 1, 2, 5};
    cout << "expected : 6 \n";
    cout << "naive sol: " << st.naive_trappingRainWater(nums) << "\n";
    cout << "optimized sol : " << st.trappingRainWater(nums) << "\n";
    return 0;
}
