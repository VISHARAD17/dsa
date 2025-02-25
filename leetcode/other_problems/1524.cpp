/*
 * 1524. Number of subarrys with odd sum 
 * */


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

class Solution{
private:
    const int MOD = 1e9+7;
    int getSumOfArr(int startIdx, int endIdx, vector<int>&arr){
        int ans = 0;
        for(int i=startIdx; i<=endIdx; i++) ans += arr[i];
        return ans;
    }
public:
    int numOfSubarrays(vector<int>& arr){
        const int n = arr.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                int curSum = getSumOfArr(i, j, arr);
                if(curSum % 2 == 1) ans = (ans + 1) % MOD;
            }
        }
        return ans % MOD;
    }


};

int main()
{
    vector<int>nums = {1, 3, 5}, nums2 = {2, 4, 6};
    Solution st;
    cout << "1st tc: " << st.numOfSubarrays(nums) << "\n";
    cout << "2st tc: " << st.numOfSubarrays(nums2) << "\n";
    return 0;
}
