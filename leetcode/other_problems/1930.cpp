/* 1930.Unique length 3 palindromic subsequnece */ 


#include <iostream>
#include <random>
#include <string>
#include <unordered_set>
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
    // can be improved by pre-computing the indices
    /* int countPalindromicSubsequence(string s){
        const int n = s.size();
        unordered_set<int> letters(s.begin(), s.end());

        int ans = 0;
        // for all unique letters
        for(char l: letters){
            int startIdx = -1, endIdx = 0;
            
            for(int i=0; i<n; i++){
                if(s[i] == l){
                    if(startIdx == -1) startIdx = i;
                    endIdx = i;
                }
            }

            unordered_set<int>uniqueCharsBetween;
            for(int i=startIdx+1; i<endIdx; i++) uniqueCharsBetween.insert(s[i]);

            ans += uniqueCharsBetween.size();
            uniqueCharsBetween.clear();
        }

        return ans;
        
    } */

    int countPalindromicSubsequence(string s){
        const int n = s.size();
        vector<int>firstIdx(26, -1), lastIdx(26, 0);
        unordered_set<int>uniqueChars(s.begin(), s.end());

        for(int i=0; i<n; i++){
            if(firstIdx[s[i]-'a'] == -1) firstIdx[s[i]-'a'] = i;
            lastIdx[s[i]-'a'] = i;
        }

        int ans = 0;
        for(char c: uniqueChars){
            unordered_set<char>uniqueCharsBetween;
            for(int k=firstIdx[c-'a']+1; k<lastIdx[c-'a']; k++) uniqueCharsBetween.insert(s[k]);
            ans += uniqueCharsBetween.size();
            uniqueCharsBetween.clear();
        }
        return ans;
    }
};

int main()
{
    string s1 = "aabca", s2 = "adc", s3 = "bbcbaba";
    Solution st;
    cout << "test 1 " << st.countPalindromicSubsequence(s1) << "\n";
    cout << "test 2 " << st.countPalindromicSubsequence(s2) << "\n";
    cout << "test 3 " << st.countPalindromicSubsequence(s3) << "\n";
    return 0;
}
