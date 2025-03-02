/*
 * return the length of longest subArray with given some otherwise 0
 * */


#include <iostream>
#include <sys/wait.h>
#include <unordered_map>
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
    /* use prefix sum to find out whether subArray with given sum exists or not
     * and then get the max len
     * */
    int lenOfLongestSubArr(vector<int>&arr, int sum){
        const int n = arr.size();
        int curPrefixSum = 0;
        int maxLen = 0;
        unordered_map<int, int>hashMap;

        for(int i=0; i<n; i++){
            curPrefixSum += arr[i];
            if(curPrefixSum == sum){
                maxLen = max(maxLen, i+1);
            }
            if(hashMap.find(curPrefixSum-sum) != hashMap.end()){
                int len = abs(i-hashMap[curPrefixSum-sum]);
                maxLen = max(maxLen, len);
            }
            else hashMap[curPrefixSum] = i;
        }
        return maxLen;
    }

};

int main()
{
    Solution st;
    vector<int>arr = {5, 8, -4, -4, 9, -2, 2};
    cout << st.lenOfLongestSubArr(arr, 0);
    return 0;
}
