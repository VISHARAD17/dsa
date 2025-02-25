/*
 * given arr count distinct elements 
 *
 * */


#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h> 
#include <iostream>
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;
#define all(x) (x).begin(), (x).end()

class Solution{
public:
    int countDistnctElements(vector<int>&nums){
        unordered_map<int, int>hashMap;
        for(int &x: nums) hashMap[x]++;
        return hashMap.size();
    }

    int countDistnctElementsUsingSet(vector<int>&nums){
        unordered_set<int> hashSet(nums.begin(), nums.end());
        return hashSet.size();
    }

};

int main()
{
    Solution st;
    vector<int>nums{  15, 12 ,13, 12, 13, 13, 18};
    cout << "using hash map: " << st.countDistnctElements(nums) << "\n";
    cout << "using set: " << st.countDistnctElementsUsingSet(nums) << "\n";
    return 0;
}
