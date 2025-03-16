/*
 * return true if sub Array with given sum exists else false
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
    /* use the idea of preFix sum, cause if preFixm sums with diff equal to sum exists mean subarray with that sum if present*/
    bool subArrayWithGivenSum(vector<int>&arr, int sum){
        const int n = arr.size();
        int curPrefixSum = 0;
        unordered_map<int, int>hashMap;

        for(int i=0; i<n; i++){
            curPrefixSum += arr[i];
            if(curPrefixSum == sum) return true;
            if(hashMap.find(curPrefixSum-sum) != hashMap.end()) return true;
            else hashMap[curPrefixSum]++;
        }
        return false;
    }
};

int main()
{
    vector<int>arr = {5, 8, 6, 13, 3, -1};
    Solution st;
    cout << st.subArrayWithGivenSum(arr, 22);
    return 0;
}
