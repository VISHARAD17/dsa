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
public:
    /*
     * all arr elements except one appears in the array only once
     * 0 is present in the array
     * all elements from 0 to max(arr) are present in the array
     * ex. nums = {0, 2, 1, 3, 2, 2} --> here max is 3 means 0, 1, 2, 3 must be present in the array 
     * hence, 0 <= max(arr) <= n-2 ( using above condition )
     * given these conditions, find out the repeating element
     * */
    void repeatingEleEffSol(vector<int>&nums){
        // time - O(n) and space - O(n)
        const int n = nums.size();
        // use the idea that max(arr) is between 0 and n-2 wher n is the size of the array 
        vector<bool>vis(n, false);

        for(int i=0; i<n; i++){
            if(!vis[nums[i]]) vis[nums[i]] = true;
            else{
                cout << "rep ele using efficient sol: " << nums[i] << "\n";
                return;
            }
        }
        cout << "not found\n";
    }

    // problem : this modifies the given array
    void naiveSol(vector<int>&nums){
        // sort the array and check for repeating ele
        const int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++){
            if(nums[i] == nums[i+1]){
                cout << "rep ele using naive sol: " << nums[i] << "\n";
                return;
            }
        }
        cout << "not found\n";
    }

};

int main()
{
    vector<int>nums = {0, 2, 1, 3, 2, 2};
    Solution st;
    st.naiveSol(nums);
    st.repeatingEleEffSol(nums);
    return 0;
}
