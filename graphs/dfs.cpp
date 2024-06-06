/*
 * 
 * DFS - Depth first search
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
 *  to read this tree using dfs output will be A a c b d 
 *
 *
 * */


#include<iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>> &g, vector<bool> &vis, int source){
    // DFS
    vis[source] =  true;
    cout << source << " ";

    for(int u : g[source]){
        if(!vis[u]) dfs(g, vis, u);
    }
}

void addEdge(vector<vector<int>> &g, int u, int v){
    // adds an edge between u and v
    // by adding u in v's vector and vice versa
    g[u].push_back(v);
    g[v].push_back(u);
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
