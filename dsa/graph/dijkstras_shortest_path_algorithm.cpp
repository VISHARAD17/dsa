/*
 * Dijkristra's Shortest path algorithm
 *
 * Given a weighted undirected graph, find the shortest distance from the source 
 * to all other vertices
 * print a dist array where dist[i] shows the distance of i fro the source
 *
 *       1
 * (5) / | \ (20)
 *    /  |  \
 *  0 (3)|   3
 *    \  |  /
 *(10) \ | / (2)
 *       2
 *  
 *  dist = {0, 5, 8, 10}
 * 
 *
 * */


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
public:
    void dijkristraAlgo(vector<vector<int>> &g, int n, int src){
        vector<int>dist(n, INT_MAX);
        dist[src] = 0;

        vector<bool>fin(n, false);

        for(int count=0; count<n-1; count++){
            int u=-1;
            for(int i=0; i<n; i++){
                if(!fin[i] and (u == -1 or dist[i] < dist[u])) u = i;
            }
            fin[u] = true;

            // go through all its adjecent vertices which are not finalized
            for(int v=0; v<n; v++){
                if(g[u][v] != 0 && fin[v] == false) dist[v] = min(dist[v], dist[u]+g[u][v]);
            }
        }
        for(int &d: dist) cout << d << " ";
        cout << "\n";
    }
};

int main()
{
    Solution st;
    // build graph if edge present g[i][j] represents the weight
    int n = 4;
    vector<vector<int>> g(n, vector<int>(n, 0));
    g[0][1] = 5, g[0][2] = 10;
    g[1][0] = 5, g[1][2] = 3, g[1][3] = 20;
    g[2][0] = 10, g[2][1] = 3, g[2][3] = 2;
    g[3][1] = 20, g[3][2] = 2;
    st.dijkristraAlgo(g, n, 0);
    return 0;
}
