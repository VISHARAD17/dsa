/*
 * return true if pair having sum exists in array
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
    bool pairWithSum(vector<int>&nums, int sum){
        unordered_map<int, int>hashMap;
        for(int &x: nums){
            // if reminder key exists in map return true
            if(hashMap.find(sum-x) != hashMap.end()) return true;
            else hashMap[x]++;
        }
        return false;
    }
};

int main()
{
    vector<int>nums = {3, 2, 8, 15, -8};
    Solution st;
    cout << st.pairWithSum(nums, 17);
    return 0;
}
