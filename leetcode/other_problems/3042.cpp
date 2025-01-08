/* 3042.Count prefix and suffix pairs I */

#include <iostream>
#include <string>
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
private:
    bool isPrefixAndSuffix(string s1, string s2){
        const int n1 = s1.size(), n2 = s2.size();
        if(n2 < n1) return false;
        if(s1 == s2) return true;

        if(s2.substr(0, n1) == s1 and s1 == s2.substr(n2-n1, n1)) return true;
        return false;
    }
public:
   int countPrefixSuffixPairs(vector<string>& words){
        const int n = words.size();
        int count = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(isPrefixAndSuffix(words[i], words[j])) count++;
            }
        }
        return count;
    }
        
};

int main()
{
    Solution st;
    vector<string>words = {"a","aba","ababa","aa"}, w = {"abab","ab"};
    cout << st.countPrefixSuffixPairs(words) << "\n";
    cout << st.countPrefixSuffixPairs(w) << "\n";
    return 0;
}
