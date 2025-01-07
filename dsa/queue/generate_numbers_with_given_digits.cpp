/* generate numbers with given digits */

#include <iostream>
#include <queue>
#include <set>
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
    /* given number n, print first n number in increasing order such that all the
     * numbers have digits in set {5, 6} */
    void generateNumbers(int n){
        set<int>s = {5, 6};
        queue<int>q;
        for(auto &x: s) q.push(x);

        int count = 0;
        while(count < n){
            int frontEle = q.front();
            cout << frontEle << " ";
            count++;
            q.pop();
            for(auto &x: s){
                int newEle = frontEle * 10 + x;
                q.push(newEle);
            }
        }
    }

};

int main()
{
    Solution st;
    st.generateNumbers(10);
    return 0;
}
