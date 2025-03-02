/*
 * print elements which are occured more than n/k where n is the size of array
 * */

#include <iostream>
#include <unordered_map>
#include <vector>
#include <utility>
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
    void printEle(vector<int>&arr, int k){
        unordered_map<int, int>hashMap;
        for(int &x: arr) hashMap[x]++;
        const int n = arr.size();
        int num = n/k;
        for(auto &x: hashMap){
            if(x.second > num) cout << x.first << " ";
        }
        cout << "\n";
    }
};

int main()
{
    vector<int>arr = {10,10,10,10,20,20,30};
    int k=2;
    Solution st;
    st.printEle(arr, 2);
    return 0;
}
