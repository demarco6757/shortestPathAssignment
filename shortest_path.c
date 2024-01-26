/*
  Dijikstra’s algorithm for finding the shortest path (single-source shortest path).

  Example adapted from:

  https://www.tutorialspoint.com/c-cplusplus-program-for-dijkstra-s-shortest-path-algorithm

Demarco Anderson
 */

#include <limits.h>
#include <stdio.h>
#include <stdbool.h>

/* Number of vertices in the graph */
#define V 6

int minDistance(int dist[], bool sptSet[])
{
   int min = INT_MAX, min_index;
   for (int v = 0; v < V; v++)
      if (sptSet[v] == false && dist[v] <= min)
         min = dist[v], min_index = v;

   return min_index;
}

void printSolution(int dist[], int n)
{
   printf("Vertex Distance from Source\n");

   for (int i = 0; i < V; i++)
      printf("%d \t %d\n", i, dist[i]);
}

/* 
   This function just simulates the correct output. It is just here to test the 
   PASS condition in the test script. The actual solution uses variables to set 
   the values to be printed. 
*/
void printtestFormat()
{
   printf(" ============================================\n"); 
   printf("|           Dijkstra's algorithm             |\n");
   printf("|        (single-source shortest path)       |\n");
   printf("|                                            |\n");
   printf("|              Source vertex = 0             |\n");
   printf(" --------------------------------------------\n");
   printf("| Vertex | Distance | Path                   |\n");
   printf(" --------------------------------------------\n");
   printf("|      0 |        0 | 0 <- 0                 |\n");
   printf("|      1 |        5 | 1 <- 0                 |\n");
   printf("|      2 |        4 | 2 <- 0                 |\n");
   printf("|      3 |        8 | 3 <- 1 <- 0            |\n");
   printf("|      4 |       13 | 4 <- 2 <- 0            |\n");
   printf("|      5 |       12 | 5 <- 3 <- 1 <- 0       |\n");
   printf(" --------------------------------------------");
}


void dijkstra(int graph[V][V], int src)
{
   int dist[V];
   bool sptSet[V];
   int i;

   for (i = 0; i < V; i++)
      dist[i] = INT_MAX;
      sptSet[i] = false;
      dist[src] = 0;

   for (int count = 0; count < V - 1; count++) {
      int u = minDistance(dist, sptSet);
      sptSet[u] = true;
      for (int v = 0; v < V; v++)
         if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
            dist[v] = dist[u] + graph[u][v];
   }

   printSolution(dist, V);
   // printtestFormat();  // This function simulates the correct output (not a solution, of course).
}
int main()
{

   int graph[V][V] = {
      { 0,  5,  4,  0,  0, 0 },
      { 5,  0,  6,  3,  0, 0 },
      { 4,  6,  0, 10,  9, 0 },
      { 0,  3, 10,  0,  7, 4 },
      { 0,  0,  9,  7,  0, 8 },
      { 0,  0,  0,  4,  8, 0 }
   };


   dijkstra(graph, 0);

   return 0;
}







