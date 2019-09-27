# LeetCode

## Graph

### Hamiltonian Path
A Hamiltonian path (or traceable path) is a path in an undirected or directed graph that visits each vertex exactly once. A Hamiltonian cycle (or Hamiltonian circuit) is a Hamiltonian path that is a cycle. 
NP Hard

### Eulerian Path
Eulerian Path is a path in graph that visits every edge exactly once. Eulerian Circuit is an Eulerian Path which starts and ends on the same vertex.
Solvable in O(V+E). Just another variation of topological sorting [Reconstruct Itinerary](https://leetcode.com/problems/reconstruct-itinerary/)

### Articulation Points
A vertex in an undirected connected graph is an articulation point (or cut vertex) iff removing it (and edges through it) disconnects the graph. For a disconnected undirected graph, an articulation point is a vertex removing which increases number of connected components.
Solvable in O(V+E)

### Bridges in a Graph
An edge in an undirected connected graph is a bridge iff removing it disconnects the graph. For a disconnected undirected graph, definition is similar, a bridge is an edge removing which increases number of disconnected components. 
Solvable in O(V+E) time
