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
private:
    // checks if all chars are disctinct between the given range
    bool areDistinct(string str, int start, int end){
        vector<bool>visited(256, false);

        for(int i=start; i<=end; i++){
            if(visited[str[i]]) return false;
            else visited[str[i]] = true;
        }
        return true;
    }

public:
    // time - O(n^3)
    void naiveSol(string s){
        const int n = s.size();
        int res = 1;

        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(areDistinct(s,i, j)){
                    res = max(res, j-i+1);
                }
            }
        }
        cout << res << "\n";
    }

    // time - O(n^2)
    void longestSubstringWithDistinctChars_betterTime(string s){
        const int n = s.size();
        int maxLen = 1;

        for(int i=0; i<n; i++){
            vector<bool>vis(256, false);
            for(int j=i; j<n; j++){
                if(vis[s[j]]) break;
                else{
                    maxLen = max(maxLen, j-i+1);
                    vis[s[j]] = true;
                }
            }
        }
        cout << maxLen << "\n";
    }
    
    // optimal sol: time - O(n)
    void longestSubstringWithDistinctChars(string s){
        const int n = s.size();

        int res = 1;
        vector<int>prev(256, -1);

        int startIdx=0;
        for(int endIdx=0; endIdx<n; endIdx++){
            startIdx = max(startIdx, prev[s[endIdx]]+1);
            int maxLen = endIdx-startIdx+1;
            res = max(maxLen, res);
            prev[s[endIdx]] = endIdx;
        }
        cout << res << "\n";

    }

};

int main()
{
    Solution st;
    string s = "abac";
    cout << "naive sol ";
    st.naiveSol(s);
    cout << "better than navie sol ";
    st.longestSubstringWithDistinctChars_betterTime(s);
    cout << "\n";
    return 0;
}
