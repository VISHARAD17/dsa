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
     * check if pair exists with a given sum in the sorted array, return -1 otherwise
     * Two pointer approach
     * arr = [2, 5, 8, 12, 30] sum=17
     * ans = yes
     * */
    void pairExistsWithGivenSum(vector<int>&nums, int sum){
        const int n = nums.size();
        int left = 0, right = n-1;
        while(left < right){
            int curSum = nums[left] + nums[right];
            if(sum == curSum){
                cout << "yes\n";
                return;
            }
            // if current sum if greater then decrement the right pointer
            else if(curSum > sum) right--;
            else left++;
        }
        cout << "no\n";
    }
};

int main()
{
    Solution st;
    vector<int>nums = {2, 5, 8, 12, 30};
    st.pairExistsWithGivenSum(nums, 13);
    return 0;
}
