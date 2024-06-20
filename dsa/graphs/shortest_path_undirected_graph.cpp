/*
 * shorted path in undirected path
 *
 * */


#include<iostream>
#include<vector>
using namespace std;

void addEdge(vector<vector<int>> &adj, int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main(){
    vector<vector<int>> adj(5);
    /// builg graph
    return 0; 
}
