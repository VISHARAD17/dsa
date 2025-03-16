/*
 * print the intersection of two unsorted array , but print the array in order as they are in the first array
 *
 * */

#include <iostream>
#include <unordered_map>
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
    void getIntersection(vector<int> &nums1, vector<int> &nums2){
        unordered_map<int, int>hashMap;

        for(int &x: nums2) hashMap[x]++;

        for(int &x: nums1){
            if(hashMap.find(x) != hashMap.end()) cout << x << " ";
        }
        cout << "\n";
    }

};

int main()
{
    vector<int>nums1 = {10, 15, 20, 25, 30, 50}, nums2 = {30, 5, 15, 80};
    Solution st;
    st.getIntersection(nums1, nums2);
    return 0;
}
