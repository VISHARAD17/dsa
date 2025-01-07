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
private:
    bool twoSum(vector<int>&nums, int sum, int startIdx){
        const int n = nums.size();
        int left = startIdx, right = n-1;

        while(left < right){
            int curSum = nums[left] + nums[right];
            if(curSum == sum) return true;
            else if(curSum > sum) right--;
            else left++;
        }
        return false;
    }
public:
    /* find a triplet in a sorted array having given sum, print yes , otherwise no*/
    void tripletInSortedArray(vector<int>&nums, int sum){
        /* naive solution would to be make 3 for loops and compare all possible pairs of 3*/
        const int n = nums.size();
        // for eff solution fix one number and for other two use two pointers with reminder sum

        for(int i=0; i<n-2; i++){
            if(twoSum(nums, sum-nums[i], i+1)){
                cout << "yes\n";
                return;
            }
        }
        cout << "no\n";
    }

};

int main()
{
    vector<int>nums = {2, 5, 10, 15, 18};
    Solution st;
    st.tripletInSortedArray(nums,33);
    return 0;
}
