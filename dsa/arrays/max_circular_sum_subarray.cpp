#include <climits>
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

class Solution{
private:
    int normalMaxSum(vector<int>nums){
        const int n = nums.size();
        int res= nums[0];
        int maxEnding = nums[0];
        for(int i=1; i<n; i++){
            maxEnding = max(nums[i], maxEnding+nums[i]);
            res = max(res, maxEnding);
        }
       return res;
    }
public:
    void maxCircularSumSubarray(vector<int>nums){
        const int n = nums.size();
        int max_normal = normalMaxSum(nums);
        if(max_normal < 0){
            cout << "maxSum : " << max_normal << "\n";
            return;
        }
        int arr_sum = 0;
        for(int i=0; i<n; i++){
            arr_sum += nums[i];
            nums[i] *= -1;
        }
        int max_circular = arr_sum + normalMaxSum(nums);
        cout << "maxSum : " << max(max_normal, max_circular) << "\n";
    }

    void naive_maxCircularSumSubarray(vector<int>nums){
        const int n = nums.size();
        int ans = INT_MIN;
        for(int i=0; i<n; i++){
            int cur_max_sum = nums[i];
            int cur_sum = nums[i];

            for(int j=1; j<n; j++){
                int index = (i+j)%n;
                cur_sum += nums[index];
                cur_max_sum = max(cur_max_sum, cur_sum);
            }
            ans = max(ans, cur_max_sum);

        }
        cout << "naive solution : " << ans << "\n";
    }

};

int main()
{
    vector<int>nums = {5, -2, 3, 4};
    Solution st;
    st.maxCircularSumSubarray(nums);
    st.naive_maxCircularSumSubarray(nums);
    return 0;
}
