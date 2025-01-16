/* 2429. Minimize XOR */

#include <iostream>
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
private:
    bool isSet(int num, int bit){
        return num & (1 << bit);
    }

    void setBit(int &num, int bit){
        num |= (1 << bit);
    }

    void unSetBit(int &num, int bit){
        num &= ~(1 << bit);
    }
public:
    /*
     * use 1011 ( 11 ) , to check why remove from right side which is less significant
     * */
    int minimizeXor(int num1, int num2){
        int currentBits = __builtin_popcount(num1);
        int finalBits = __builtin_popcount(num2);

        int ans = num1;
        int curBit = 0;

        // if current greater than final reduce the count
        while(currentBits > finalBits){
            if(isSet(ans, curBit)){
                unSetBit(ans, curBit);
                currentBits--;
            }
            curBit++;
        }

        // if current is lessor than final then increase the count
        while(currentBits < finalBits){
            if(!isSet(ans, curBit)){
                setBit(ans, curBit);
                currentBits++;
            }
            curBit++;
        }
        return ans;
    }
};

int main()
{
    Solution st;
    cout << "tc 1: " << st.minimizeXor(3, 5) << "\n";
    cout << "tc 2: " << st.minimizeXor(1, 12) << "\n";
    return 0;
}
