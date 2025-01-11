/* 
 * 49. Group Anagram [ Medium ]
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
    vector<vector<string>> groupAnagrams(vector<string>& strs){
        const int n  = strs.size();
        unordered_map<string, vector<string>> mp;
        for(string &str: strs){
            string tmp = str;
            sort(tmp.begin(), tmp.end());
            mp[tmp].push_back(str);
        }

        vector<vector<string>> ans;
        for(auto &x: mp) ans.push_back(x.second);
        return ans;
    }
};

int main()
{
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    Solution st;
    vector<vector<string>> res = st.groupAnagrams(strs);
    cout << "[ ";
    for(vector<string> &str: res){
        cout << "[ ";
        for(string &s: str) cout << s << " ";
        cout << "]";
    }
    cout << " ]";
    return 0;
}
