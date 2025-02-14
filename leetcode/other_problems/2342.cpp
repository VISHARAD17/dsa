#include <climits>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h> 
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;
#define all(x) (x).begin(), (x).end()

class Solution{
private:
    int getSumOfDigits(int num){
        int ans = 0;
        while(num != 0){
            int rem = num%10;
            num /= 10;
            ans += rem;
        }
        return ans;
    }
    int getSum(vector<int> &nums){
        int res = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                res = max(res, nums[i]+nums[j]);
            }
        }
        return res;
    }
public:
    int maximumSum_slow_solution(vector<int>& nums){
        const int n = nums.size();
        int res = -1;
        unordered_map<int, vector<int>>mp;
        for(int i=0; i<n; i++){
            int sumOfDigits = getSumOfDigits(nums[i]);
            mp[sumOfDigits].push_back(nums[i]);
        }
        for(auto &x: mp){
            if(x.second.size() >= 2){
                res = max(res, getSum(x.second));
            }
        }
        return res;
    }

    int maximumSum(vector<int> &nums){
        const int n = nums.size();
        int res = -1;
        // priority queue ( min heap ) 
        vector<priority_queue<int, vector<int>,greater<int>>> q(82);


        for(int num: nums){
            int sumOfDigits = getSumOfDigits(num);
            q[sumOfDigits].push(num);

            while(q[sumOfDigits].size() > 2) q[sumOfDigits].pop();
        }

        for(auto &minHeap: q){
            if(minHeap.size() > 1){
                int firstNum = minHeap.top();
                minHeap.pop();
                int secondNum = minHeap.top();
                minHeap.pop();
                res = max(res, firstNum+secondNum);
            }
        }
        return res;
    }

};

int main()
{
    vector<int>nums{18,43,36,13,7};
    vector<int>nums1{10,12,19,14};
    Solution st;
    cout << "1 tc : " << st.maximumSum_slow_solution(nums) << "\n";
    cout << "2 tc : " << st.maximumSum_slow_solution(nums1) << "\n";
    cout << "imp sol : -> \n";
    cout << "1 tc : " << st.maximumSum(nums) << "\n";
    cout << "2 tc : " << st.maximumSum(nums1) << "\n";
    return 0;
}
