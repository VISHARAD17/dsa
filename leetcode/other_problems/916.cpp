/*
 * 916. Word Subsets
 * Medium
 * */


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h> 
using namespace std;

typedef long long ll;
typedef long double ld;
const ll mod = 1e9+7;
#define all(x) (x).begin(), (x).end()

class Solution{
private:
    vector<int> getHash(string s){
        vector<int>frq(26, 0);
        for(char &c: s) frq[c-'a']++;
        return frq;
    }
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2){

        // get maxFrq i.e. max required frequency for each char in words2
        vector<int>maxFrq(26, 0);
        for(string &s: words2){
            vector<int>curFrqMap = getHash(s);
            for(int i=0; i<26; i++) maxFrq[i] = max(maxFrq[i], curFrqMap[i]);
        }

        vector<string>ans;
        for(string &s: words1){
            bool flag = true;
            vector<int>curFrqMap = getHash(s);

            for(int i=0; i<26; i++){
                if(maxFrq[i] > curFrqMap[i]){
                    flag = false;
                    break;
                }
            }

            if(flag) ans.push_back(s);
        }
        for(auto &x: ans) cout << x << " ";
        cout << "\n";
        return ans;
    }
};

int main()
{
    Solution st;
    vector<string> words1 = {"amazon","apple","facebook","google","leetcode"}, words2 = {"e","o"};
    st.wordSubsets(words1, words2);
    return 0;
}
