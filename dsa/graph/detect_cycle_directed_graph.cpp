/*
 * Detect cycle in directed graph
 *
 *                     ----- 5
 *                     |     ^
 *                     +     | 
 *   0 --> 1 <-- 2 --> 3 --> 4
 *
 *    there is a cycle in 3, 4 & 5
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
private:
    bool dfsRec(vector<vector<int>> &g, vector<bool>&vis, vector<bool>&recur, int s){
        vis[s] = true; // marked visited
        recur[s] = true; // no present in recursion stack 

        for(int u : g[s]){
            if(!vis[u]){
                if(dfsRec(g, vis, recur, u) == true){
                    return true;
                }
            }
            else if(recur[u]) {
                return true;
            }
        }
        recur[s] = false;
        return false;
    }
public:
    bool detectCycleInDirectedGraph(vector<vector<int>>&g, int n){
        vector<bool>vis(n, false), recur(n, false); // visited check and if_present_in_recursion_call_stack check array
        for(int i=0; i<n; i++){
            if(dfsRec(g, vis, recur, i)) return true;
        }
        return false;
    }

};
/*
 * here we need a recur array in order to find a back edge which forms a circular form 
 * for ex. if there was an edge going from 3 to 5, then 3-4-5 would not be a cycle, edge has to go from 5 to 3 not the other way around
 * */

int main()
{

    int n=6;
    vector<vector<int>> g(n);
    // add edges 
    g[0].push_back(1);
    g[2].push_back(1);
    g[2].push_back(3);
    g[3].push_back(4);
    g[4].push_back(5);
    g[5].push_back(3);

    Solution st;
    cout << st.detectCycleInDirectedGraph(g, n) << "\n";

    return 0;
}
