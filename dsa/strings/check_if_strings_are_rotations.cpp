#include <iostream>
#include <string>
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
    /* check if s2 can be obtained by rotating s1 any number of times 
     * either left rotate or right rotate
     * print yes or no
     * */
    void checkIfStringsAreRotations(string s1, string s2){
        cout << "strings are s1=" << s1 << "and s2=" << s2 << " ";
        const int n1 = s1.size(), n2 = s2.size();
        /* idea is to concatinate string s1 with itself i.e. s1+ s1 and search s2 in it */
        if(n1 != n2){
            cout << "no\n";
            return;
        }
        s1 += s1;

        if(s1.find(s2) != string::npos) cout << "yes\n";
        else cout << "no\n";
    }

};

int main()
{
    Solution st;
    string s1 = "abcd", s2 = "cdab";
    st.checkIfStringsAreRotations(s1,s2);
    return 0;
}
