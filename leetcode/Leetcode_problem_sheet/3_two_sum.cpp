/* 
 * 1. Two Sum
 * Easy
 * */



#include <iostream>
#include <unordered_map>
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
    vector<int> twoSum(vector<int>& nums, int target){
        const int n = nums.size();
        unordered_map<int, int>mp;

        for(int i=0; i<n; i++){
            if(mp.find(target - nums[i]) != mp.end()) return {i, mp[target-nums[i]]};
            else mp[nums[i]] = i;
        }

        return {-1, -1};
    }

};

int main()
{
    Solution st;
    vector<int>nums = {2,7,11,15};
    int target = 9;
    vector<int>res = st.twoSum(nums, target);
    cout << "test 1: " << res[0] << " " << res[1] << "\n";
    return 0;
}
