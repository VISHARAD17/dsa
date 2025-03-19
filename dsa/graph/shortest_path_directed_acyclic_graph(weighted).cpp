/*
 * Shortest path in directed acyclic graph ( weighted )
 *
 *      1     3     4
 *   0 --* 1 --* 2 ----*3
 *         |            *
 *         *____________|
 *               2
 *
 *   source : 1
 *
 *   O/P : INF 0 3 2
 * */

#include <climits>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
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
    /*
     * idea is to get the toplogical sorting and find the distances
     * slightly modified version of toplogical sorting using BFS
     * */
    void shortestDistanctInWeightedAcyclicGraph(vector<vector<pair<int, int>>> &g, int n, int source){
        vector<int>dist(n, INT_MAX);
        dist[source] = 0;

        vector<int>inDegre(n, 0);
        for(int i=0; i<n; i++){
            for(auto &v: g[i]){
                inDegre[v.first]++;
            }
        }

        queue<int>q;
        for(int i=0; i<n; i++){
            if(inDegre[i] == 0) q.push(i);
        }
        vector<int>topologicalOrder;

        while(!q.empty()){
            int ele = q.front();
            q.pop();
            cout << ele << " ";
            for(auto &v: g[ele]){
                for(auto &v: g[ele]){
                    if(dist[ele] != INT_MAX){
                        dist[v.first] = min(dist[ele]+v.second, dist[v.first]);
                    }
                }
                inDegre[v.first]--;
                if(inDegre[v.first] == 0) q.push(v.first);
            }
        }

        cout << "dist arr : " << " ";
        for(auto &x: dist) cout << x << " ";
        cout << "\n";
    }

};

int main()
{
    Solution st;
    // build graph
    int n = 4;
    vector<vector<pair<int, int>>> g(n);
    g[0].push_back({1, 1}); // {v, weight}
    g[1].push_back({2, 3});
    g[1].push_back({3, 2});
    g[2].push_back({3, 4});
    st.shortestDistanctInWeightedAcyclicGraph(g, 4, 1);
    return 0;
}
