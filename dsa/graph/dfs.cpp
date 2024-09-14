/*
 * 
 * DFS - Depth first search
 * it is recursive in nature
 * used when neccessory
 *
 * search one child then its hold connection of the child, then goes for the other one
 *
 * ex.  A
 *     /\
 *    a  b
 *   /    \
 *  c      d
 *
 *  ans -  A a c b d 
 *
 *  0 -- 1
 *  |    | \
 *  |    |   4
 *  |    | /
 *  2 -- 3
 *  
 *  ans : 0 1 3 2 4 or 0 1 4 3 2
 * */


#include<iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>> &g, vector<bool> &vis, int source){
    // visite the source
    vis[source] =  true;
    // print the source
    cout << source << " ";

    for(int u : g[source]){
        // if not visited then do dfs from that node 
        if(!vis[u]) dfs(g, vis, u);
    }
}

void addEdge(vector<vector<int>> &g, int u, int v){
    // adds an edge between u and v
    // by adding u in v's vector and vice versa
    g[u].push_back(v);
    g[v].push_back(u);
}

void dfs_for_disconnected_graph(vector<vector<int>> &g, vector<bool> &vis){
    for(int i=0; i<vis.size(); i++) 
        if(vis[i] == false) 
            dfs(g, vis, i); // only extra change is to add one more loop to check for all nodes
}

void show_graph(vector<vector<int>> &g){
    cout << "Printing graphs ---- \n";
    for(auto &x: g){
        for(auto &y: x) cout << y << " ";
        cout << "\n";
    }
    return;
}

int main(){
    vector<vector<int>> g(5);
    addEdge(g, 0, 1);
    addEdge(g, 0, 2);
    addEdge(g, 2, 3);
    addEdge(g, 1, 3);
    addEdge(g, 1, 4);
    addEdge(g, 3, 4);
    show_graph(g);
    vector<bool>visited(5, false);
    dfs(g, visited, 0);
    return 0;
}

// ans - 0, 1, 3, 2, 4
