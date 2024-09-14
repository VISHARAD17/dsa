/*
 * shorted path in unweighted graph
 *
 * problem : shorted distance from source to every other vertex ( use bfs )
 *
 *   1 --- 3 
 *  /       \
 * 0 ------- 5
 *  \       /
 *   2 --- 4
 * 
 * dist - 0 1 1 2 2 1
 *
 * */


#include <climits>
#include<iostream>
#include <queue>
#include<vector>
using namespace std;

void shortedDist(vector<vector<int>> adj, int s){
    // time & space complexity : 0(v)
    const int n = adj.size();
    vector<int>dist(n, 0);
    vector<bool>vis(n, false);
    queue<int>q;
    dist[s] = 0;
    vis[s] = true;
    q.push(s);

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(auto v: adj[u]){
            if(vis[v] == false){
                // each neighbouring vertex is 1 edge away 
                // hence, add one to source distance
                dist[v] = dist[u]+1; 
                vis[v] = true;
                q.push(v);
            }
        }
    }
    
    // print dist array
    for(auto &x: dist) cout << x << " ";
    cout << "\n";
}

void addEdge(vector<vector<int>> &adj, int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main(){
    int n = 6; 
    vector<vector<int>> adj(n); // adjacency matrix representation

    // add edges
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 0, 5);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 4);
    addEdge(adj, 3, 5);
    addEdge(adj, 5, 4);

    shortedDist(adj, 0);

    return 0;
}
