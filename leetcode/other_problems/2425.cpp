/* 2425. Bitwise XOR for all pairings */

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
    int xorAllNums(vector<int>& nums1, vector<int>& nums2){
        const int n1 = nums1.size(), n2 = nums2.size();
        if(n1%2 == 0 and n2%2 == 1){
            int ans = nums1[0];
            for(int i=1; i<n1; i++) ans ^= nums1[i];
            return ans;
        }
        else if(n1%2 == 1 and n2%2 == 0){
            int ans = nums2[0];
            for(int i=1; i<n2; i++) ans ^= nums2[i];
            return ans;
        }
        else if(n1%2 == 1 and n2%2 == 1){
            int ans = nums1[0];
            for(int i=1; i<n1; i++) ans ^= nums1[i];
            for(int i=0; i<n2; i++) ans ^= nums2[i];
            return ans;
        }
        return 0;
    }
};

int main()
{
    vector<int>nums1 = {2,1,3}, nums2 = {10,2,5,0};
    Solution st;
    cout << st.xorAllNums(nums1, nums2);
    return 0;
}
