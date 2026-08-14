#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void prims(vector<vector<int>>& graph, int V) {

    vector<int> key(V, INT_MAX);
    vector<bool> visited(V, false);
    vector<int> parent(V, -1);

    // Start from vertex 0
    key[0] = 0;

    for (int i = 0; i < V; i++) {

        // Find minimum key unvisited vertex
        int u = -1;

        for (int j = 0; j < V; j++) {
            if (!visited[j] &&
                (u == -1 || key[j] < key[u])) {
                u = j;
            }
        }

        // Mark vertex as visited
        visited[u] = true;

        // Update adjacent vertices
        for (int v = 0; v < V; v++) {

            if (graph[u][v] != 0 &&
                !visited[v] &&
                graph[u][v] < key[v]) {

                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    // Print MST
    int totalWeight = 0;

    cout << "Edges in MST:\n";

    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i
             << " : " << graph[parent[i]][i] << endl;

        totalWeight += graph[parent[i]][i];
    }

    cout << "Total weight: " << totalWeight << endl;
}

int main() {

    int V = 5;

    vector<vector<int>> graph = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    prims(graph, V);

    return 0;
}