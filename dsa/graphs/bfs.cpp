/*
 * BFS - Breadth first search
 * 
 * ex. 
 * 1. here source/starting point is zero
 *    0
 *   /\
 *  1  2
 *    /\
 *   3  4
 * 
 * bfs - 0 1 2 3 4 
 *
 * 2. graph - here source/starting point is 0
 *   1 --- 3 
 *  /       \
 * 0 ------- 5
 *  \       /
 *   2 --- 4
 * 
 * bfs - 0 1 2 5 3 4 or 0 1 2 5 4 3
 *
 * */

#include<iostream>
#include <queue>
#include <vector>
using namespace std;

void bfs(vector<vector<int>>adj, int s){
    const int vertices = adj.size();
    vector<bool>visited(vertices+1, false);

    queue<int>q;
    visited[s] = true;
    q.push(s);
    
    // while queue is not empty
    while(q.empty() == false){
        int u = q.front();
        q.pop();
        cout << u << " ";
        for(auto &x: adj[u]){
            if(visited[x] == false){
                visited[x] = true;
                q.push(x);
            }
        }
    }

}

// bfs function for disconnected graph or source may not be given
// void bfs_disconnected_graph(vector<vector<int>> adj){
//     const int vertices = adj.size();
//     vector<bool>visited(vertices+1, false);
//     
//     for(int i=0; i<=vertices; i++){
//         // do bfs for all non visited 
//         if(visited[i] == false) bfs_recursive(adj, i, visited);
//     }
// }

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

    bfs(adj, 0); 

}
