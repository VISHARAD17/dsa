/*
 * given array print the frquencies of arrya elements
 *
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
    void printFrq(vector<int> &nums){
        unordered_map<int, int> hashMap;

        for(int &n: nums) hashMap[n]++;

        for(auto it: hashMap){
            cout << "frq of " << it.first << " = " << it.second << "\n";
        }
    }

};

int main()
{
    vector<int>nums = {50, 50, 10, 40, 10};
    Solution st;
    st.printFrq(nums);
    return 0;
}
