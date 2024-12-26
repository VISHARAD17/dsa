#include <climits>
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
const ll MOD = 1e9+7;
#define all(x) (x).begin(), (x).end()

class Solution{
public:
    /*
     * for a given string return the leftmost char that is repeating, print its index
     * if all chars are unique return -1
     * */
    void leftMostRepeatingChar(string s){
        // time - O(n) and space - O(1)
        const int n = s.size();
        vector<int>chr(256, 0);

        for(int i=0; i<n; i++) chr[s[i]]++;

        for(int i=0; i<n; i++){
            if(chr[s[i]] > 1){
                cout << "index = " << i << "\n";
                return;
            }
        }
        cout << "-1\n";
    }

    // more efficient solution
    void leftMostRepeatingChar_eff(string s){
        const int n = s.size();
        // this sol is exactly theta(n)
        vector<int>chr(256, -1); // top store only the first index of each char
        int res = INT_MAX;
        for(int i=0; i<n; i++){
            int firstIdx = chr[s[i]];
            if(firstIdx == -1){
                chr[s[i]] = i;
            }
            else{
                res = min(res, firstIdx);
            }
        }
        cout << "index = " << (res == INT_MAX ? -1 : res) << "\n";
    }

    void naive_leftMostRepeatingChar(string s){
        // time - O(n^2) and no extra space
        const int n = s.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(s[i] == s[j]){
                    cout << "index = " << i << "\n";
                    return;
                }
            }
        }
        cout << "-1\n";
    }

};

int main()
{
    Solution st;
    cout << "naive sol:";
    st.naive_leftMostRepeatingChar("cabbad");
    cout << "opt sol:";
    st.leftMostRepeatingChar("cabbad");
    cout << "more_eff:";
    st.leftMostRepeatingChar_eff("cabbad");
    return 0;
}
