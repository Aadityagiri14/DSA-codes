#include <iostream>
#define V 4
bool isSafe(int v, bool graph[V][V], int color[], int c) {
  for (int i = 0; i < V; i++)
    if (graph[v][i] && c == color[i])
      return false;
  return true;
}
bool graphColoringUtil(bool graph[V][V], int m, int color[], int v) {
  if (v == V)
    return true;
  for (int c = 1; c <= m; c++) {
    if (isSafe(v, graph, color, c)) {
      color[v] = c;
      if (graphColoringUtil(graph, m, color, v + 1))
        return true;
      color[v] = 0;
    }
  }
  return false;
}
void graphColoring(bool graph[V][V], int m) {
  int color[V];
  for (int i = 0; i < V; i++)
    color[i] = 0;
  if (!graphColoringUtil(graph, m, color, 0))
    std::cout << "Solution does not exist";
  else {
    std::cout << "Solution exists: Following are the assigned colors\n";
    for (int i = 0; i < V; i++)
      std::cout << "Vertex " << i << " ---> Color " << color[i] << '\n';
  }
}
int main() {
  bool graph[V][V] = {
  {0, 1, 1, 1},
  {1, 0, 1, 0},
  {1, 1, 0, 1},
  {1, 0, 1, 0}
  };
  int m = 3;
  graphColoring(graph, m);
  return 0;
}