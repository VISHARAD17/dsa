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
    // O(n)
    void findFrqiSortedArray(vector<int>&nums){
        const int n = nums.size();
        
        int curFrq = 1;
        for(int i=1; i<n; i++){
            if(nums[i] == nums[i-1]) curFrq++;
            else{
                cout << nums[i-1] << " : " << curFrq << "\n";
                curFrq = 1;
            }
        }
        cout << nums[n-1] << " : " << curFrq << "\n";

    }

};

int main()
{
    vector<int>nums = {10, 10, 10, 25, 30, 30};
    Solution st;
    st.findFrqiSortedArray(nums);
    return 0;
}
