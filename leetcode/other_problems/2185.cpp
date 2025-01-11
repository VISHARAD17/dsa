/* 2185 [Easy] Couting Words with a given prefix */


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
public:
    int prefixCount(vector<string>& words, string pref){
        const int n = words.size(), m = pref.size();
        int count = 0;

        for(string &w: words){
            if(w.size() >= m){
                if(w.substr(0, m) == pref) count++;
            }
        }

        return count;
    }
};

int main()
{
    vector<string>words = {"pay","attention","practice","attend"};
    string pref = "at";
    Solution st;
    cout << st.prefixCount(words, pref) << "\n";
    return 0;
}
