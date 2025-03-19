/*
 * Detect cycle using Kahn's alogrithm ( topological sorting using BFS )
 *
 *                     ----- 5
 *                     |     ^
 *                     +     | 
 *   0 --> 1 <-- 2 --> 3 --> 4
 *    there is a cycle in 3, 4 & 5
 * */
#include <iostream>
#include <vector>
#include <queue>
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
    /* idea is to maintain a count, if count is V means we are able to visit all the vertices, no cycle present
     * topological sorting algo works only for acyclic graphs
     * is count is less than V, means cycle is present
     * This happens because in a cycle there will never a vertex whose inDegree will become 0
     * */
    bool detectCycleUsingToplogicalSortingAlgo(vector<vector<int>>&g, int n){
        vector<int>inDegree(n, 0);
        for(int i=0; i<n; i++){
            for(int j=0; j<g[i].size(); j++){
                inDegree[g[i][j]]++;
            }
        }

        queue<int>q;
        for(int i=0; i<n; i++){
            if(inDegree[i] == 0) q.push(i);
        }

        int count = 0;
        while(!q.empty()){
            int frontEle = q.front();
            q.pop();
            cout << frontEle << " ";
            count++;

            for(int u: g[frontEle]){
                inDegree[u]--;
                if(inDegree[u] == 0) q.push(u);
            }
        }
        cout << "\n";
        return (count != n);
    }

};

int main()
{

    /* build a direct graph */
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
    /*it will not print all nodes, hence a cycle is present */
    cout << st.detectCycleUsingToplogicalSortingAlgo(g, 6) << "\n";
    return 0;
}
