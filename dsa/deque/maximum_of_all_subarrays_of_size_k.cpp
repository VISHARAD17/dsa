/*
 * get the maximum of all subarray of size k, and print them 
 * ex. arr = [10, 8, 5, 12, 15, 7, 6], k = 3
 * subarrays of size 3 : 
 *   10 8 5 - 10
 *   8 5 12 - 12
 *   5 12 15 - 15
 *
 *   and so no
 *   lastly print all of them 
 * */


#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
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
    //  O(n)
    void printMaximumOfSubarrays(vector<int>&nums, int k){
        vector<int>ans;
        const int n = nums.size();
        deque<int>dq;

        for(int i=0; i<k; i++){
            while(!dq.empty() and nums[i] >= nums[dq.back()]) dq.pop_back();
            dq.push_back(i);
        }

        for(int i=k; i<n; i++){
            ans.push_back(dq.front());
            while(!dq.empty() and dq.front() <= i-k) dq.pop_front();
            while(!dq.empty() and nums[i] >= nums[dq.back()]) dq.pop_back();

            dq.push_back(i);
        }

        ans.push_back(dq.front());
        
        cout << "opt sol using deque : ";
        for(auto &x: ans) cout << nums[x] << " ";
        cout << "\n";
    }

    void naiveSol(vector<int> &nums, int k){
        vector<int>ans;
        const int n = nums.size();
        for(int i=0; i<=n-k; i++){
            int maxEle = nums[i];
            for(int j=i+1; j<i+k; j++) maxEle = max(maxEle, nums[j]);
            ans.push_back(maxEle);
        }
        cout << "naive sol : ";
        for(int &x: ans) cout << x << " ";
        cout << "\n";
    }

};

int main()
{
    Solution st;
    vector<int>nums = {10, 8, 5, 12, 15, 7, 6};
    int k = 3;
    st.printMaximumOfSubarrays(nums,k);
    st.naiveSol(nums, k);
    return 0;
}
