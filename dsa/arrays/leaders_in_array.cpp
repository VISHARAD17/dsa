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

/*
 * print leaders in the array [ an element in an array is leader if there is not greater element on its right]
 * ex. arr = [7, 10, 4, 3, 6, 5, 2]  O/P - 10, 6, 5, 2 ( any order )
 * */
class Solution{
public:
    void leadersInArray(vector<int>&nums){
        const int n = nums.size();
        // check if the current element is greater than the 
        // prev leader
        int curLeader = nums[n-1]; // last element always current leader
        cout << curLeader << " ";
        for(int i=n-2; i>=0; i--){
            if(nums[i] > curLeader){
                cout << nums[i] << " ";
                curLeader = nums[i];
            }
        }
    }

};

int main()
{
    vector<int>nums = {7, 10, 4, 3, 6, 5, 2};
    Solution st;
    st.leadersInArray(nums);
    return 0;
}
