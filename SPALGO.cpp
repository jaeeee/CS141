// C++ program for  
// the above approach 
// #include <bits/stdc++.h>
#include <stdlib.h> 
#include <iostream>
#include <cmath>

using namespace std; 
#define INFINITE 10000 
  
// Function to store the  
// length of shortest path  
// between all pairs of nodes 
void SPalgo(int n, int graph[V][V], int dis[V][V]) 
{ 
  for (int a = 0; a < n; a++) { 
      for (int b = 0; b < n; b++) { 
          dis[a][b] = graph[a][b]; 
      } 
  } 
  
  // Dijkstra's
	int length[V];
	bool set[V];
	for(int i = 0; i < V; ++i) {
		length[i] = INT_MAX, set[i] = false;
	}
	length[n] = 0;
	for(int j = 0; j < V - 1l ++j) {
		int k = minDist(length, set);
		set[k] = true;
		for(int m = 0; m < V; m++) {
			if(!set[m] && graph[k][m] && length[k] != INT_MAX && length[k] + graph[k][m] < length[m]) {
				length[m] = length[k] + length[k][m];
			}
		}
	}
	check(n,length,dis);
} 
  
bool check(int size, int path[], int dis[V][V]) 
{ 
  if (dis[path[0] - 1][path[size - 1] - 1] == size - 1) { 
      return true;
  } 
  else { 
      return false;
  } 
} 
  
// Driver code 
int main() 
{ 
    // Adjacency matrix representing the graph 
    const int n = 4; 
    int graph[n][n] = { { 0, 1, 1, INFINITE }, 
                        { INFINITE, 0, 1, INFINITE }, 
                        { INFINITE, INFINITE, 0, 1 }, 
                        { 1, INFINITE, INFINITE, 0 } }; 
    // A matrix to store the length of shortest 
    int dis[n][n]; 
  
    // path between all pairs of vertices 
    shortestPathLength(n, graph, dis); 
  
    int path1[] = { 1, 2, 3, 4 }; 
    checkShortestPath(n, path1, dis); 
  
    int path2[] = { 1, 3, 4 }; 
    checkShortestPath(3, path2, dis); 
  
    return 0; 
} 
