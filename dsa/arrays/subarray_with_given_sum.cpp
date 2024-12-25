#include <iostream>
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
    /*
     * give a array of non-negative numbers, return if subarray with given sum exists or not
     * print yer or no
     * */
    void subarrayWithGivenSum(vector<int>&nums, int sum){
        const int n = nums.size(); 
        int start = 0, end = 0;
        int curSum = 0;
        while(start <= end and end<n){
            if(curSum < sum){
                curSum += nums[end];
                end++;
            }
            else if(curSum > sum){
                curSum -= nums[start];
                start++;
            }
            else{
                cout << "YES\n";
                return;
            }
        }
        cout << "NO\n";
    }

};

int main()
{
    Solution st;
    vector<int>nums = {1, 4, 20, 3, 10, 5};
    int sum = 33;
    st.subarrayWithGivenSum(nums,sum);
    return 0;
}
