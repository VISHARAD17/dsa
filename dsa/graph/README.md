## Graphs

- Representation of graphs:
    - ``vector<vector<int>> g(_size_)``
    - `vector<int> g[]` - can be represented as an array of vectors or as a vector of vectors.

- degree of a node is the number of edges at that node
- cyclic path in a graph starts and ends on a same node(vertex) in graph
- for `v` no. of vertices:
    - total no. of edges in Directed graph are `v * (v-1)`
    - total no. of edges in un-directed graph are `v * (v-1) / 2`
- directed cyclic graph ( DAG )

### Graph representation
```
    0 
     \
      2 -- 3  
     /
    1

total no. of vertices - 4
```
 
#### Adjacency matrix
Adjacency matrix- 
```
    0 1 2 3
  ----------
0 | 0 1 1 0
1 | 1 0 1 0
2 | 1 1 0 1
3 | 0 0 1 0

```

- properties of Adjacency matrix ( v x v)
    * space required : O(n)
    * operations ; 
        - check if u and v are adjacent : 0(1)
        - find all vertices adjacent to u : 0(1)
        - find degree of u : 0(v)
        - add/remove edge : 0(1)
        - add/remove vertice : 0(v^2)

#### Adjacency array 
stores only connected node unlike matrix Representation
```
0 -> 2
1 -> 2 
2 -> 0-1-3
3 -> 2
```

#### properties of Adjacency array/list:
* space : 0(v+e)
    - undirected : 0(v+2*e)
    - directed : 0(v+e)
* operations : 
    - check if there is an edge from u to v - 0(v)
    - find all adjacent to u - 0(degree(u))
    - find degree of u - 0(1)
    - add an edge - 0(1)
    - remove an edge - 0(v)

- Graph representation in c++
```c++

void addEdge(vector<int>adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main(){
    int v = 4;
    vector<int>adj[4]; // can use vector<vector<int>> adj
    addEdge(adj, 0, 1):
    addEdge(adj, 0, 2):
    addEdge(adj, 1, 2):
    addEdge(adj, 1, 3):
    return 0;
}

```
#### Applications of BFS :
- shortest path in an unweighted graph
- Crawlers in search engine 
- peer to peer network ex. bittorrent which is search among your neighbours then their neighbours
- Social networking search 
- In Garbage collection (finds memoery reacheble by variable then their variables and finds out which is not reacheble and deletes them)
- Cycle detection
- Ford Fulkerson algorithm - maximum flow algorithm
- Broadcasting ( send signal to your neighbour then their neighbours and so on)

#### DFS:
- Cycle detection
- Topological sorting ( make file utility - dependent files has to be run before the main file and so on)
- Strongly connected components
- solving puzzle
- Path finding ( mainly to print the path )

#### Problems: 
- [bfs](./bfs.cpp)
- [dfs](./dfs.cpp)
- [count connected components](./count_connected_components.cpp)
- [detect cycle in directed graph](./detect_cycle_directed_graph.cpp)
- [detect cycle in undirected graph](./detect_cycle_undirected_graph.cpp)
- [detect cycle using kahn algo](./detect_cycle_using_kahn_algo(topological_bfs).cpp)
- [shortest path in directed acyclic weighted graph](./shortest_path_directed_acyclic_graph(weighted).cpp)
- [Shortedt path in unweighted graph (Bidirectional)](./shortest_path_unweighted_graph.cpp)
- [prims algorithm](./prims_algorithm.cpp)
- [topological sorting BFS](./topological_sorting_BFS.cpp)
- [topological sorting DFS](./topological_sorting_DFS.cpp)

[go to main](../../README.md)
