/* 3412.Find Mirror score of a string */


#include <iostream>
#include <string>
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
    long long calculateScore(string s){
        long long ans = 0;
        const int n = s.size();
        unordered_map<int, vector<int>>mp;

        for(int i=0; i<n; i++){
            int cur = s[i] - 'a';
            if(mp.find(25-cur) != mp.end() and mp[25-cur].size() > 0){
                ans += (long long)i - (long long)( mp[25-cur].front());
                mp[25-cur].pop_back();
            }
            else{
                mp[cur].push_back(i);
            }
        }

        return ans;
    }


};

int main()
{
    Solution st;
    cout << st.calculateScore("aczzx");
    return 0;
}
