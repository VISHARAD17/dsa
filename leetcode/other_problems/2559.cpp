/* 2559 - count vowel strings in ranges */
#include <cstdlib>
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
    bool isVowel(char c){
        if(c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u') return true;
        else return false;
    }
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries){
        const int w = words.size(), q = queries.size();
        vector<int>ans(q, 1), prefix(w, 0);

        prefix[0] = (isVowel(*words[0].begin()) and isVowel(words[0].back()) ? 1: 0);

        for(int i=1; i<w; i++){
            if(isVowel(*words[i].begin()) and isVowel(words[i].back())) prefix[i] = prefix[i-1] + 1;
            else prefix[i] = prefix[i-1];
        }

        // cout << "prefix arr: ";
        // for(int &x: prefix) cout << x << " ";
        // cout << "\n";
        
        for(int i=0; i<q; i++){
            int cnt = 0, left = queries[i][0], right = queries[i][1];
            if(left == 0) ans[i] = prefix[right];
            else ans[i] = prefix[right] - prefix[left-1];
        }

        return ans;
    }


};

int main()
{
    vector<string>words = {"aba","bcb","ece","aa","e"};
    vector<vector<int>> queries = {{0,2},{1,4},{1,1}};
    Solution st;
    vector<int> res = st.vowelStrings(words, queries);
    for(auto &x: res) cout << x << " ";
    cout << "\n";
    return 0;
}
