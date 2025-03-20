/*
 * Prims Algorithm - minimum spanning tree
 *
 * [ Note: this problem is only valid for undirected graph]
 *
 *     5
 *   A -- D
 *   |\   |
 * 9 | \10| 7
 *   |  \ |
 *   B -- C
 *     8
 *   Assume, A, B, C, B are computers and we want to connect them to each other. 
 *   5, 9, 10,etc. is the wire length required to connect two computers
 *
 *   Minimize the number of wire length and make sure that all computers are connected 
 *   to each other directly or may be through indermediate connection
 *
 *   here, total min length is the minimum span of this structure or tree or graph
 *   
 *   Ans:
 *   
 *      5
 *   A ---  D 
 *          | 7
 *   B ---  C
 *      8
 *
 *   hence, ans is 20
 *
 * */

#include <climits>
#include <iostream>
#include <vector>
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
/*
 *       1
 *  5 /  |  \ 15
 *   0 10|   3
 *  8 \  |  / 20
 *       2
 *  
 *  ans: 
 * */
public:
    /* here we are using adjacency matrix representation 0 is not edge, weight is edge is present*/
    /*
     * time- O(v^2)
     * */
    int minSpanningTree(vector<vector<int>> &g, int n){
        vector<int>key(n, INT_MAX);
        key[0] = 0; // starting from 0 as a source
        vector<bool>mstSet(n, false);
        int res = 0;

        for(int count = 0; count<n; count++){
            int u = -1;
            // pick a vertex with minium key value
            for(int i=0; i<n; i++){
                if(!mstSet[i] and (u == -1 or key[i] < key[u])){
                    u = i;
                }
            }
            // and then include it in the mst set and add its value into result
            mstSet[u] = true;
            res += key[u];
            // cout << res << " ";

            // update current key values of its neighbours
            for(int v=0; v<n; v++){
                if(g[u][v] != 0 and !mstSet[v]){
                    key[v] = min(key[v], g[u][v]);
                }
            }
        }
        return res;
    }

};

int main()
{
    int n;
    n = 4;
    vector<vector<int>> g(n, vector<int>(n));

    g[0][1] = 5;
    g[0][2] = 8;
    g[1][3] = 15;
    g[1][2] = 10;
    g[1][0] = 5;
    g[2][1] = 10;
    g[2][0] = 8;
    g[2][3] = 20;
    g[3][1] = 15;
    g[3][2] = 20;

    Solution st;
    cout << st.minSpanningTree(g, 4);
    return 0;
}
