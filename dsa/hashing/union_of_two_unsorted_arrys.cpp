/*
 * count the elements in union of two unsorted arrays
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
    int countEleInUnion(vector<int>arr1, vector<int>arr2){
        unordered_map<int, int>hashMap; /* we can use unordered_set also */

        for(int &x: arr1) hashMap[x]++;
        for(int &x: arr2) hashMap[x]++;

        return hashMap.size();
    }

};

int main()
{
    vector<int>arr1 = {15, 20, 5, 15}, arr2 = {15, 15, 15, 20, 10};
    Solution st;
    cout << st.countEleInUnion(arr1, arr2);
    return 0;
}
