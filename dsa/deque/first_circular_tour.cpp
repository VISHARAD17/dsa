/* 
 * we have n pertol pumps arrange in circular manner and petrol[i] represents the amount of 
 * petrol available at i_th petrol pump
 * and dist[i] represented distanct between i+1_th petrol pump and i_th petrol pump
 *
 * we have a truck that consumes 1 unit of petrol per unit of distance
 *
 * so, find out the petrol pump, if we start from that petrol pump we can visit all petrol pump
 * and come back to the starting petrol pump
 *
 * */


#include <iostream>
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
    int naive_startingPetrolPump(vector<int>&petrol, vector<int>&dist){
        const int p = petrol.size(), d = dist.size();

        for(int start=0; start<p; start++){
            int curPetrol = 0, end=start;

            while(true){
                curPetrol += petrol[end]; // fill petrol
                curPetrol -= dist[end]; // go to next pump

                if(curPetrol < 0){
                    break;
                }

                end = (end + 1) % p;
                if(end == start){
                    return start;
                }
            }
        }
        return -1;
    }
    
    /*
     * 1. idea is to keep adding to the end of queue while cur petrol is greater than of equal to 0
     * 2. Keep removing items from the front of queue while cur petrol is negative
     * */
    int startingPetrolPump(vector<int>&petrol, vector<int>&dist){
        const int n =petrol.size();
        int curPetrol = 0, prevPetrol = 0, start = 0;

        for(int i=0; i<n; i++){
            curPetrol += (petrol[i] - dist[i]);
            if(curPetrol < 0){
                prevPetrol += curPetrol;
                start = i+1;
                curPetrol = 0;
            }
        }

        return (prevPetrol + curPetrol > 0 ? start: -1);
    }

    int otherSol(vector<int>&petrol, vector<int>&dist){
        const int n = petrol.size();
        vector<int>curVal(n, 0), afterVal(n, 0), beforeVal(n, 0);
        for(int i=0; i<n; i++) curVal[i] = petrol[i] - dist[i];

        beforeVal[0] = curVal[0];
        for(int i=0; i<n; i++) beforeVal[i] = curVal[i-1] + beforeVal[i];
        afterVal[n-1] = curVal[n-1];
        for(int i=n-2; i>=0; i--) afterVal[i] = curVal[i] + afterVal[i+1];


        for(int i=0; i<n; i++){
            if(curVal[i] >= 0 and afterVal[i] + beforeVal[i] >= 0) return i;
        }
        return -1;
    }

};

int main()
{
    Solution st;
    vector<int>petrol = {4, 8, 7, 4}, dist = {6, 5, 3, 5};
    cout << "naive sol : " << st.naive_startingPetrolPump(petrol, dist) << "\n";
    cout << "opt sol : " << st.startingPetrolPump(petrol, dist) << "\n";
    cout << "other sol : " << st.otherSol(petrol, dist) << "\n";
    return 0;
}
