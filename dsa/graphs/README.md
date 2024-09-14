## Graphs

- Representation of graphs:
    - ``vector<vector<int>> g(_size_)``
    - `vector<int> g[]` - can be represented as an array of vectors or as a vector of vectors.

- degree of a node is the number of edges at that node

- cyclic path in a graph starts and ends on a same node(vertex) in graph

- directed cyclic graph ( DAG )

### Adjacency matrix

```
    0 
     \
      2 -- 3  
     /
    1

total no. of vertices - 4
```
 
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

- # Adjacency array 
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
- Problems :
    - Detect cycle in directed graph 
    - Detect cycle in un-directed graph 
    - shortest path in un-weighted graph
    - topological sorting ( kahn's BFS based algorithm )
    - Topological sorting ( DFS based ) 
    - shortest path in DAG 
    - Prim algorithm / minimum spanning tree 
    - Dijkstra algorithm - shortest path algorithm
    - Kosaraju'a algorithm 
    - Bellman ford shortest path algorithm 
    - Articulation point 
    - Bridges in graph 
    - Tarjans algorithm 
    - Kruskals algorithm
