/*
 * return true if array contains a subArray with zero sum
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
    /* use the idea of prefix sum, if prefix sum if repeating i.e. its same, then we have a subarray with 0 sum in between*/
    bool subArrayWithZeroSum(vector<int>&arr){
        const int n = arr.size();
        unordered_map<int, int>hashMap;
        int curPrefixSum = 0;

        for(int i=0; i<n; i++){
            curPrefixSum += arr[i];
            if(curPrefixSum == 0) return true;
            if(hashMap.find(curPrefixSum) != hashMap.end()) return true;
            else hashMap[curPrefixSum]++;
        }
        return false;
    }

};

int main()
{
    vector<int>arr = {-3, 4, -3, -1, 1};
    Solution st;
    cout << st.subArrayWithZeroSum(arr);
    return 0;
}
