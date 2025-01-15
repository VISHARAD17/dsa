/* 
 * 242. Valid anagrams
 * Easy
 * Hash table, string, sorting
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
    bool isAnagram(string s, string t){
        unordered_map<char, int> mp1, mp2;
        for(char &c: s) mp1[c]++;
        for(char &c: t) mp2[c]++;

        return (mp1 == mp2 ? true : false);
    }
};

int main()
{
    Solution st;
    cout << "test 1: " << st.isAnagram("anagram", "nagaram") << "\n";
    cout << "test 2: " << st.isAnagram("rat", "car") << "\n";
    return 0;
}
