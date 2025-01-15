/* 1769 minimum number of operations to move all balls to each box */

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
    vector<int> minOperations(string boxes){
        const int n = boxes.size();
        vector<int>ans(n, 0);

        for(int i=0; i<n; i++){
            if(boxes[i] == '1'){
                for(int j=0; j<n; j++){
                    ans[j] += abs(i-j);
                }
            }
        }

        return ans;
    }

};

int main()
{
    Solution st;
    vector<int>res = st.minOperations("110");
    for(auto &x: res) cout << x << " ";
    cout << "\n";
    return 0;
}
