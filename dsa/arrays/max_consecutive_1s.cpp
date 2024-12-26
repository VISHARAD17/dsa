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

/* for a given array return the length of maximum consecutive array */
class Solution{
public:
    void maxConsecutiveOnes(vector<int>&nums){
        const int n = nums.size();
        int curLen = 0;
        int maxLen = 0;

        for(int &x: nums){
            if(x == 0){
                maxLen = max(maxLen, curLen);
                curLen = 0;
            }
            else curLen++;
        }
        cout << "max consecutive One: " << maxLen << "\n";
    }

};

int main()
{
    vector<int>nums = {1, 0, 1, 1, 1, 1, 0, 1, 1};
    Solution st;
    st.maxConsecutiveOnes(nums);
    return 0;
}
