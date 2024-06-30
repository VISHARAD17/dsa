/*
 * detect cycle in a undirected graph
 *
 *
 *   1 --- 3 
 *  /       \
 * 0 ------- 5
 *  \       /
 *   2 --- 4
 * 
 * this graph has a cycle
 * */


#include<iostream>
#include <vector>
using namespace std;

bool DFSRec(vector<vector<int>> adj, int s, vector<bool> &vis, int parent){
    vis[s] = true;
    for(auto &v: adj[s]){
        if(vis[v] == false){
            if(DFSRec(adj, v, vis, s) == true) return true;
        }
        // if visted and its not a parent then its a cycle
        else if(v != parent) return true;
    }
    return false;
}

bool detectCycleDFS(vector<vector<int>>&adj){
    // time : 0(v+e)
    const int n = adj.size();
    vector<bool>vis(n, false);

    for(int i=0; i<n; i++){
        if(vis[i] == false){
            if(DFSRec(adj, i, vis, -1) == true) return true;
        }
    } 
    return false;
}

void addEdge(vector<vector<int>> &adj, int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main(){
    int n = 6; // using 2nd example
    vector<vector<int>> adj(n); // adjacency matrix representation

    // add edges
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 0, 5);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 4);
    addEdge(adj, 3, 5);
    addEdge(adj, 5, 4);
    
    cout << detectCycleDFS(adj);

    return 0;

}
