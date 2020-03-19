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
void shortestPathLength(int n, int graph[4][4], int dis[4][4]) 
{ 
  // Intialising dis matrix  
  // with current distance value   
  for (int i = 0; i < n; i++) { 
      for (int j = 0; j < n; j++) { 
          dis[i][j] = graph[i][j]; 
      } 
  } 
  
  // Floyd-Warshall Algorithm 
  for (int k = 0; k < n; k++) { 
    for (int i = 0; i < n; i++) { 
      for (int j = 0; j < n; j++) { 
          dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]); 
      } 
    } 
  } 
} 
  
// A function that prints YES if the 
// given path is the shortest path 
// and prints NO if the given path 
// is not shortest 
void checkShortestPath(int length, int path[], int dis[4][4]) 
{ 
  // Check if the given path 
  // is shortest or not 
  // as discussed in above approach 
  if (dis[path[0] - 1][path[length - 1] - 1] == length - 1) { 
      cout << "YES" << endl; 
  } 
  else { 
      cout << "NO" << endl; 
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