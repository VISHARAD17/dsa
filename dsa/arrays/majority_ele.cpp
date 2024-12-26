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
    // print majority elements ( element appering in the array more than n/2 times)
    // not using any map here
    void majorityElement(vector<int>&nums){
        int res = 0, count = 1;

        const int n = nums.size();
        for(int i=1; i<n; i++){
            if(nums[res] == nums[i]) count++;
            else count--;

            if(count == 0){
                res = i;
                count = 1;
            }
        }

        count = 0;
        for(int i=0; i<n; i++){
            if(nums[res] == nums[i]) count++;
            if(count > (int)n/2){
                cout << "Majority ele index : " << res << "\n";
                return;
            }
        }
        cout << "no majority element\n";

    }

};

int main()
{
    vector<int>nums = {6, 8, 4, 8, 8};
    cout << "Expected : 1/3/4 \n";
    Solution st;
    st.majorityElement(nums);
    return 0;
}
