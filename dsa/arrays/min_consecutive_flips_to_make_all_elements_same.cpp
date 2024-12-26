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
     * give a binary array, find out the min no. of flips required to make all elements same
     * we can flip same consecutive elements at one like 2 O's or 3 1's,
     * print the groups of indices to be flipped
     * */
    void minFlips(vector<int>&nums){
        const int n = nums.size();
        
        for(int i=0; i<n; i++){
            if(nums[i] != nums[i-1]){
                if(nums[i] != nums[0]) cout << "From " << i << " to ";
                else cout << i-1 << "\n";
            }
        }
        if(nums[n-1] != nums[0]) cout << n-1 << "\n";
    }

};

int main()
{
    Solution st;
    vector<int>nums = {0, 0, 1, 1, 0, 0, 1, 1, 0, 1};
    st.minFlips(nums);
    return 0;
}
