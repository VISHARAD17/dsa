#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
#include <algorithm> 
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        const int n = nums.size();
        unordered_map<int, int>mp;
        vector<int>ans;
        
        for(int i=0; i<n; i++){
            int x = nums[i];
            // if remaining exists in map
            if(mp.find(target-x) != mp.end()) return {i, mp[target-x]};
            else mp[x] = i;
        }
        return {-1, -1};

    }
};
#endif // SOLUTION_H
