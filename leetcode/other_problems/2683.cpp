/* 2683. Neighboring bitwise xor */


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
    bool doesValidArrayExist(vector<int>& derived){
        int x = derived[0];
        const int n = derived.size();
        for(int i=1; i<n; i++) x ^= derived[i];
        return (x == 0 ? true: false);
    }

};

int main()
{
    Solution st;
    vector<int>nums1 = {1, 1, 0}, nums2 = {1, 1}, nums3 = {1, 0};
    cout << "tc 1 : " << st.doesValidArrayExist(nums1) << "\n";
    cout << "tc 2 : " << st.doesValidArrayExist(nums2) << "\n";
    cout << "tc 3 : " << st.doesValidArrayExist(nums3) << "\n";
    return 0;
}
