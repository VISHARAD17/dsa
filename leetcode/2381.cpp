/* shifting letters II */

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
    // TLE
    string naive_shiftingLetters(string s, vector<vector<int>>& shifts){
        const int n = shifts.size();

        for(int i=0; i<n; i++){
            int startIdx = shifts[i][0], endIdx = shifts[i][1], dir = shifts[i][2];
            for(int j=startIdx; j<=endIdx; j++){
                if(dir == 0){
                    // shift to left 
                    if(s[j] == 'a') s[j] = 'z';
                    else s[j] = (s[j] - 1);
                }
                else{
                    if(s[j] == 'z') s[j] = 'a';
                    else s[j] = (s[j] + 1);
                }
            }
            // cout << "after i " << i << "s = " << s << "\n";
        }
        return s;
    }
    
    string shiftingLetters(string s, vector<vector<int>> &shifts){
        const int n = shifts.size();
        const int s_size = s.size();

        // build prefix 
        vector<int>prefix(s_size, 0);
        for(int i=0; i<n; i++){
            int startIdx = shifts[i][0], endIdx = shifts[i][1], dir = shifts[i][2];
            if(dir == 0){
                prefix[startIdx]--;
                if(endIdx+1 < s_size) prefix[endIdx+1]++;
            }
            else{
                prefix[startIdx]++;
                if(endIdx+1 < s_size) prefix[endIdx+1]--;
            }
        }
        /* cout << "before co=ummulative sum";
        for(int &x: prefix) cout << x << " ";
        cout << "\n"; */

        // get cumulative sum 
        for(int i=1; i<s_size; i++) prefix[i] += prefix[i-1];
        /* cout << "prefix array " ;
        for(int &x: prefix) cout << x << " ";
        cout << "\n"; */

        for(int i=0; i<s_size; i++){
            int tmp = abs(prefix[i]) % 26;
            if(prefix[i] < 0){
                int val = s[i] - 'a' - tmp;
                if(val < 0) s[i] = 'a' + (26+val);
                else s[i] = s[i] - tmp;
            }
            else if(prefix[i] > 0){
                int val = (s[i] - 'a') + tmp;
                if(val >= 26) s[i] = 'a' + (val - 26);
                else s[i] = s[i] + tmp;
            }
        }
        return s;
    }
};

int main()
{
    Solution st;
    string s = "abc";
    vector<vector<int>> shifts = {{0, 1, 0}, {1, 2, 1},{0, 2, 1}};
    cout << "test 1:" << st.shiftingLetters(s, shifts) << "\n";
    string s1 = "dztz";
    vector<vector<int>> shifts_1 = {{0, 0, 0}, {1, 1, 1}};
    cout << "test 2:" << st.shiftingLetters(s1, shifts_1) << "\n";
    vector<vector<int>> shifts3 = {{4,8,0},{4,4,0},{2,4,0},{2,4,0},{6,7,1},{2,2,1},{0,2,1},{8,8,0},{1,3,1}};
    string s2 = "xuwdbdqik";
    cout << "test 3: " << st.shiftingLetters(s2, shifts3);
    return 0;
}
