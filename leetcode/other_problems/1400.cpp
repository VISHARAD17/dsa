/* 1400. Construct k palindrome String */

#include <iostream>
#include <string>
#include <unordered_map>
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
    /* idea is to count odd occuring elements
     * cause one palindrome can have only one odd occurring elements 
     * so, n odd occuring elements means min n palindrome we have to make
     * */
    bool canConstruct(string s, int k){
        const int n = s.size();
        if(n < k) return false;
        if(n == k) return true;

        unordered_map<char, int>mp;
        for(char &c: s) mp[c]++;

        int oddCount = 0;
        for(auto &x: mp) if(x.second % 2 == 1) oddCount++;
        return oddCount > k ? false: true;
    }
};

int main()
{
    Solution st;
    cout << "test 1:" << st.canConstruct("annabelle", 2) << "\n";
    cout << "test 2:" << st.canConstruct("leetcode", 3) << "\n";
    return 0;
}
