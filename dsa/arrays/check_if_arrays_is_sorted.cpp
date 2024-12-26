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
    bool checkIfArrayIsSorted(vector<int>&nums){
        const int n = nums.size();
        for(int i=1; i<n; i++){
            if(nums[i] < nums[i-1]) return false;
        }
        return true;
    }

};

int main()
{
    vector<int>nums = {3, 4, 5, 7};
    Solution st;
    cout << st.checkIfArrayIsSorted(nums);
    return 0;
}
