/*
 * BellMan ford Shortest path algorithm
 *
 * Find shortest path in weighted graph ( weight can be negative ) from the source
 *
 *       B
 *      *| \
 *  1  / |  \ 2
 *    /  |   *
 *   A   |-3  D
 *    \  |    *
 *     \ |  / 3
 *      ** /
 *       C
 *
 * dist = {0, -1, 2, 1}
 *         A   B  C  D
 * */


#include <climits>
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
    void bellmanAlgo(vector<vector<int>> &edges, int n, int e, int src){
        vector<int>dist(n, INT_MAX);
        dist[src] = 0;
            
        for(int i=0; i<n-1; i++){
            for(int j=0; j<e; j++){
                int curSrc = edges[j][0], curdistination = edges[j][1], weight = edges[j][2];
                if(dist[curSrc] != INT_MAX and dist[curSrc] + weight < dist[curdistination]){
                    dist[curdistination] = dist[curSrc] + weight;
                }
            }
        }
        
        // run the same loop again one more time for all edges
        for(int j=0; j<e; j++){
            int curSrc = edges[j][0], curdistination = edges[j][1], weight = edges[j][2];
            if(dist[curSrc] != INT_MAX and dist[curSrc] + weight < dist[curdistination]){
                cout << "graphs has negative weight cycle";
                return;
            }
        }

        for(auto &x: dist) cout << x << " ";
        cout << "\n";
        return;
    }

};

int main()
{
    Solution st;
    int n = 4, e = 5; // no of vertices and edges
    // store all edges ( src, distination, weight)
    vector<vector<int>> edges;
    edges.push_back({0, 1, 1});
    edges.push_back({0, 2, 4});
    edges.push_back({1, 2, -3});
    edges.push_back({2, 3, 3});
    edges.push_back({1, 3, 2});
    st.bellmanAlgo(edges, n, e, 0);
    return 0;
}
