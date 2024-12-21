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
    void reverseArrayElements(vector<int>&nums){
        const int n = nums.size();
        int low = 0, high = n-1;

        while(low < high){
            // swap
            int tmp = nums[low];
            nums[low] = nums[high];
            nums[high] = tmp;
            low++;
            high--;
        }
        for(int &x: nums) cout << x << " ";
    }
};

int main()
{
    vector<int>num = {10, 20, 30};
    Solution st;
    st.reverseArrayElements(num);
    return 0;
}
