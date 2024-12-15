#include <iostream>
#include <map>
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
        map<int, int>frq;
        int left = 0, right = 0;
        long long ans = 0;

        while(right < n){
            frq[nums[right]]++; // add to the frq map 

            // in the map left will the least and right will be the largest 
            while(frq.rbegin()->first - frq.begin()->first > 2){
                // remove the left one 
                frq[nums[left]]--;
                if(frq[nums[left]] == 0) frq.erase(nums[left]);
                left++;
            }
            ans += ( right - left + 1);
            right++;
        }
        return ans;
    }
};

int main()
{
    Solution st;
    vector<int>num = {5, 4, 2, 4};
    cout << st.continuousSubarrays(num);
    return 0;
}
