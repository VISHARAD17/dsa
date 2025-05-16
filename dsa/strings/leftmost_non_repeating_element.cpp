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
    // prints the index of leftmost non repeating char
    void leftMostNonRepeatingChar(string s){
        // time - O(n), space - O(1)
        vector<int>chr(256, 0);
        const int n = s.size();
        for(int i=0; i<n; i++) chr[s[i]]++;

        for(int i=0; i<n; i++){
            if(chr[s[i]] == 1){
                cout << "i = " << i << "\n";
                return;
            }
        }
        cout << "-1\n";
    }

};

int main()
{
    Solution st;
    st.leftMostNonRepeatingChar("geeksforgeeks");
    return 0;
}
