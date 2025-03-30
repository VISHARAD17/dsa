/*
 * Kosaraju's Alogrithm ( use to solve strongly connected graph problem, DFS based)
 *
 * in the given graph find the strongly connected coponenets and print them each on a new line
 *
 * strongly connected component : given any vertex in the component we can reach any other vertex within the component
 * 
 *
 *   0 ---* 1 ---* 3
 *   *    /        |
 *   |   /         |
 *   | *           *
 *    2            4
 *
 * output :   0 1 2 
 *            3
 *            4
 *
 *
 * */


#include <iostream>
#include <vector>
#include <stack>
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
    /* normal dfs */
    void dfs(vector<vector<int>> &g, int s, vector<bool> &vis){
        vis[s] = true;
        cout << s << " ";
        for(auto &u: g[s]){
            if(!vis[u]) dfs(g, u, vis);
        }
    }
    /* to get the topological order using stack */
    void dfs_stk(vector<vector<int>> &g, stack<int> &stk, int s, vector<bool>&vis){
        vis[s] = true;
        for(auto &u: g[s]){
            if(!vis[u]) dfs_stk(g, stk, u, vis);
        }
        stk.push(s);
    }
public:
    /* Kosaraju algorithm */
    /*
     * 1. print vertices in order of their finish time ( topological sort)
     * 2. reverse the links
     * 3. DO normal DFS
     * */
    void printStronglyConnectedComponents(vector<vector<int>> &g, int n){
        vector<bool>vis(n, false);
        stack<int>stk;

        for(int i=0; i<n; i++){
            if(!vis[i]) dfs_stk(g, stk, i, vis);
        }

        // reverse the links
        vector<vector<int>> revG(n);
        for(int i=0; i<n; i++){
            for(int j=0; j<g[i].size(); j++){
                revG[g[i][j]].push_back(i);
            }
        }
        // do normal DFS for all the elements using stack order
        vis.assign(n, false); // reset the vector
        while(!stk.empty()){
            int ele = stk.top();
            stk.pop();
            if(!vis[ele]) {
                dfs(revG, ele, vis);
                cout << "\n";
            }
        }

    }
};

int main()
{
    Solution st;
    int n = 5;
    vector<vector<int>> g(n);
    g[0].push_back(1);
    g[1].push_back(2), g[1].push_back(3);
    g[2].push_back(0);
    g[3].push_back(4);
    st.printStronglyConnectedComponents(g, n);
    return 0;
}
