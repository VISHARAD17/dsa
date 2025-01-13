/*
 * Minimum length of string after operations
 * */

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
public:
    int minimumLength_using_map(string s){
        const int n = s.size();
        unordered_map<char, int>mp;
        
        for(char &c: s) mp[c]++;

        int ans = 0;
        for(auto &x: mp){
            while(x.second >= 3){
                x.second -= 2;
            }
            if(x.second >= 1) ans += x.second;
        }
        return ans;
    }

    int minimumLength(string s){
        int ans = 0;
        vector<int>chr(26, 0);
        for(char &c: s){
            chr[c-'a']++;

            if(chr[c-'a'] >= 3) chr[c-'a'] -= 2;
        }
        for(int &x: chr) ans += x;
        return ans;
    }
};

int main()
{
    Solution st;
    cout << "tc 1 : " << st.minimumLength("abaacbcbb") << "\n";
    cout << "tc 2 : " << st.minimumLength("aa") << "\n";
    return 0;
}
