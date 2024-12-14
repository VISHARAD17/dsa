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
    long long continuousSubarrays(vector<int>& nums) {
        const int n = nums.size();
        int ans = 0;
        for(int i=1; i<=n; i++) ans += (n - i + 1), cout << "ans = "<< ans << "\n";
        return ans;
    }
};

int main()
{
    Solution st;
    vector<int>num = {5, 4, 3, 2};
    cout << st.continuousSubarrays(num);
    return 0;
}
