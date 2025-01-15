/* 1422. max score after splitting the string */
#include <iostream>
#include <string>
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
    int maxScore(string s){
        int ans = INT_MIN;
        const int n = s.size();
        int totalOnes = 0;
        for(char c: s){
            if(c == '1') totalOnes++;
        }
        int left = 0, right = totalOnes;
        for(int i=0; i<n-1; i++){
            if(s[i] == '0') left++;
            else right--;
            ans = max(ans, left+right);
        }
        return ans;
    }

};

int main()
{
    Solution st;
    cout << st.maxScore("011101") << "\n";
    cout << st.maxScore("00111") << "\n";
    cout << st.maxScore("1111") << "\n";
    return 0;
}
