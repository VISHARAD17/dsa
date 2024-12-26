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
    // check if strings are permutations of each other or not
    void checkAnagram(string s1, string s2){
        /*
         * naive solution would be to sort both the string and compare
         * time - O(n long n) and no extra space
         * */

        /*
         * time -  O(n) and space - O(1)
         * */
        cout << "s1=" << s1 << " and s2=" << s2 << " ";
        if(s1.size() != s2.size()){
            cout << "no\n";
            return;
        }
        const int n = s1.size();
        vector<int>count(256, 0);
        
        for(int i=0; i<n; i++){
            count[s1[i]]++;
            count[s2[i]]--;
        }

        for(int i=0; i<256; i++){
            if(count[i] < 0){
                cout << "NO\n";
                return;
            }
        }
        cout << "YES\n";

    }

};

int main()
{
    Solution st;
    string s1 = "aabca", s2 = "acaba";
    st.checkAnagram(s1, s2);
    return 0;
}
