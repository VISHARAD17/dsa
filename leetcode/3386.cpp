// 3386.Button with longest push time 

#include <climits>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h> 
#include <map>
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;
#define all(x) (x).begin(), (x).end()

class Solution{
public:
    int buttonWithLongestTime(vector<vector<int>>& events){
        int ans = INT_MIN;

        map<int, int>mp;
        int prev = 0;
        
        for(auto &e: events){
            if(mp.find(e[0]) == mp.end()){
                mp[e[0]] = e[1] - prev;
            }
            else mp[e[0]] = max(e[1]-prev, mp[e[0]]);
            prev = e[1];
        }
        cout << "printing map\n";
        for(auto &x: mp) cout << x.first << "--" << x.second << "\n";

        int idx = -1;
        for(auto &x: mp){
            if(ans < x.second){
                idx = x.first;
                ans = x.second;
            }
        }
        return idx;
    }

};

int main()
{
    vector<vector<int>> nums = {{1,4},{18,5},{15,7},{12,9},{1,11},{18,13},{16,17}};
    Solution st;
    cout << st.buttonWithLongestTime(nums);
    return 0;
}
