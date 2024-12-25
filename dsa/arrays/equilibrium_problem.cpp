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
    int getSum(vector<int>&nums, int l, int r){
        const int n = nums.size();
        vector<int>prefix(n, 0);

        prefix[0] = nums[0];
        for(int i=1; i<n; i++) prefix[i] = prefix[i-1] + nums[i];

        int sum = prefix[r];
        if(l >= 1) sum -= prefix[l-1];
        return sum;
    }
public:
    /* find if any array has an equilibrium point
     * i_th ele is an equilibrium point if the sum of ele before and after the point are same
     * */ 
    // HINT: use prefix sum to precalculate all the sums
    void isEquilibrium(vector<int>&nums){
        const int n = nums.size();

        for(int i=1; i<n-1; i++){
            int sumBefore = getSum(nums, 0, i-1), sumAfter = getSum(nums, i+1, n-1);
            // cout << "for i=" << i << "before = "  << sumBefore << "and sumAfter = " << sumAfter << "\n";
            if(sumBefore == sumAfter){
                cout << "yes present at " << i << "\n";
                return;
            }
        }
        cout << "no\n";
    }
    
    void isEquilibriumWithOutPrefix(vector<int>&nums){
        const int n = nums.size();

        int leftSum = 0, rightSum = 0;
        for(int &x: nums) rightSum += x;

        for(int i=0; i<n; i++){
            rightSum -= nums[i];
            if(leftSum == rightSum){
                cout << "yes present at " << i << "\n";
                return;
            }
            leftSum += nums[i];
        }
        cout << "not present\n";
    }


};

int main()
{
    Solution st;
    vector<int>nums = {3, 4, 8, -9, 20, 6};
    st.isEquilibrium(nums);
    cout << "without prefix ";
    st.isEquilibriumWithOutPrefix(nums);
    return 0;
}
