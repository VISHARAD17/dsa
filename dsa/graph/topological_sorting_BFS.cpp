/*
 * topological sorting - Kahn's BFS based algorithm
 *
 *
 *  idea is that if there is an edge from e_1 to e_2, then task e_1 has to be finished first then task e_2
 *
 *  ( Note: Here * represents the end of edge )
 *  ex.   0   1
 *       / \ / \
 *      *   *   *
 *      2   3   4
 *
 *      here, task 0 has to be finished to get to the task 2. task 0 & 1 has to be finished first to get to the task 3
 *
 *     This way of task sorting is called topological sorting
 *     for above tree : 0 1 2 3 4 or 1 0 2 3 4  ( in short 0, 1 has to be done before going to 2,3,4)
 *
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
    void printTopologicalSorting(vector<vector<int>> &g, int n){
        // store indegree for all vertices / nodes 
        // indegree --> no of edges ending at that vertex
        vector<int>inDegree(n, 0);
        for(int i=0; i<n; i++){
            for(int j=0; j<g[i].size(); j++) inDegree[g[i][j]]++;
        }
        cout << "indegree arr : ";
        for(int i=0; i<n; i++) cout << inDegree[i] << " ";
        cout << "\n";

        queue<int>q;
        // vertices with 0 indegree have to start first cause there are not dependent on anyone
        for(int i=0; i<n; i++){
            if(inDegree[i] == 0) q.push(i);
        }


        cout << "topological sort : ";
        while(!q.empty()){
            int top = q.front();
            q.pop();
            cout << top << " ";
            
            for(int u: g[top]){
                // since we have reached u mean, its one dependent is done, hence reduce one indegree
                inDegree[u]--;
                // no indegree mean all its dependents are done, so put it in the queue
                if(inDegree[u] == 0) q.push(u);
            }
        }
        cout << "\n";
    }

};

int main()
{
    Solution st;
    // build a directed graph
    int n = 5;
    vector<vector<int>> g(5);
    st.printTopologicalSorting(g, n);
    return 0;
}
