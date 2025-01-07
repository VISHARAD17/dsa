#include <iostream>
#include <pthread.h>
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
    void printArray(vector<int>&nums){
        cout << "array: ";
        for(int &x: nums) cout << x << " ";
        cout << "\n";
    }
public:
    /* given binary sorted array print the count of 1 ex. 00011, count - 2*/
    // this problem boils down to finding first occurence of 1, so count would be n-i
    void countOnes(vector<int>nums){
        const int n = nums.size();
        printArray(nums);

        int low =0, high = n-1;

        while(low <= high){
            int mid = (low + high)/2;
            if(nums[mid] == 0) low = mid+1;
            else{
                if(mid == 0 or nums[mid-1] == 0){
                    cout << n-mid << "\n";
                    return;
                }
                else high = mid-1;
            }
        }
        cout << "-1\n";
    }

};

int main()
{
    vector<int>nums = {0, 0, 0, 1, 1, 1, 1};
    Solution st;
    st.countOnes(nums);
    return 0;
}
