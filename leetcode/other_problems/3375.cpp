#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
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
    int minOperations(vector<int>& nums, int k) {
        int ans;
        int minEle = *min_element(nums.begin(), nums.end());
        if(minEle < k) return -1;
        set<int>s = set(nums.begin(), nums.end());
        ans = s.size();
        if(s.count(k) == 1) ans--;
        return ans;
    }

};

int main()
{
    Solution st;
    vector<int>nums = {};
    int k = 0;
    cout << st.minOperations(nums, k);
    return 0;
}
