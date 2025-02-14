#include <iostream>
#include <string>
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
    string removeOccurrences(string s, string part){
        const int n = s.size();
        vector<char>a;

        for(int i=0; i<n; i++){
            a.push_back(s[i]);
            if(a.size() >= part.size() and a.back() == part.back()){
                string tmp(a.end()-part.size(), a.end());
                if(tmp == part){
                    a.erase(a.end()-part.size(), a.end());
                }
            } 
        }
        string ans = "";
        for(auto &x: a) ans += x;
        return ans;
    }
};

int main()
{
    Solution st;
    cout << "1st tc : " << st.removeOccurrences("daabcbaabcbc", "abc") << "\n";
    cout << "1st tc : " << st.removeOccurrences("axxxxyyyyb", "xy") << "\n";
    return 0;
}
