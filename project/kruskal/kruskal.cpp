#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "string"

using namespace std;

struct Edge {
    int u;
    int v;
    int weight;
};

class DSU {
private:
    vector<int> parent;
    vector<int> rank;

public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    bool unite(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);

        if (rootU == rootV)
            return false;

        if (rank[rootU] < rank[rootV]) {
            swap(rootU, rootV);
        }

        parent[rootV] = rootU;

        if (rank[rootU] == rank[rootV]) {
            rank[rootU]++;
        }

        return true;
    }
};

bool compareEdges(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

void printLine(int length = 60) {
    cout << string(length, '=') << '\n';
}

void kruskal(int vertices, vector<Edge> edges) {

    sort(edges.begin(), edges.end(), compareEdges);

    DSU dsu(vertices);

    vector<Edge> mst;

    int totalWeight = 0;

    printLine();
    cout << "                 KRUSKAL'S ALGORITHM\n";
    printLine();

    cout << "\n[1] Sorted Edges\n\n";

    cout << left
         << setw(10) << "Edge"
         << setw(10) << "Weight"
         << '\n';

    cout << "--------------------\n";

    for (const Edge& edge : edges) {
        cout << left
             << setw(5) << edge.u
             << "-"
             << setw(4) << edge.v
             << setw(10) << edge.weight
             << '\n';
    }

    cout << "\n[2] Constructing Minimum Spanning Tree\n\n";

    cout << left
         << setw(12) << "Edge"
         << setw(12) << "Weight"
         << setw(20) << "Decision"
         << '\n';

    cout << "---------------------------------------------\n";

    for (const Edge& edge : edges) {

        bool added = dsu.unite(edge.u, edge.v);

        if (added) {

            mst.push_back(edge);
            totalWeight += edge.weight;

            cout << left
                 << setw(12) << (to_string(edge.u) + " - " +
                                  to_string(edge.v))
                 << setw(12) << edge.weight
                 << setw(20) << "ACCEPTED"
                 << '\n';

        } else {

            cout << left
                 << setw(12) << (to_string(edge.u) + " - " +
                                  to_string(edge.v))
                 << setw(12) << edge.weight
                 << setw(20) << "REJECTED (Cycle)"
                 << '\n';
        }

        if (mst.size() == vertices - 1)
            break;
    }

    cout << "\n";

    printLine();
    cout << "                 MINIMUM SPANNING TREE\n";
    printLine();

    cout << "\n";

    cout << left
         << setw(12) << "Edge"
         << setw(12) << "Weight"
         << '\n';

    cout << "------------------------\n";

    for (const Edge& edge : mst) {
        cout << left
             << setw(12) << (to_string(edge.u) + " - " +
                              to_string(edge.v))
             << setw(12) << edge.weight
             << '\n';
    }

    cout << "\n";

    printLine();
    cout << "Total MST Weight : " << totalWeight << '\n';
    cout << "Edges in MST     : " << mst.size() << '\n';
    printLine();
}

int main() {

    int vertices, edgesCount;

    printLine();
    cout << "              MINIMUM SPANNING TREE\n";
    cout << "                 KRUSKAL'S ALGORITHM\n";
    printLine();

    cout << "\nEnter number of vertices: ";
    cin >> vertices;

    cout << "Enter number of edges: ";
    cin >> edgesCount;

    vector<Edge> edges;

    cout << "\nEnter edges in the format:\n";
    cout << "Source Destination Weight\n\n";

    for (int i = 0; i < edgesCount; i++) {

        Edge edge;

        cout << "Edge " << i + 1 << ": ";
        cin >> edge.u >> edge.v >> edge.weight;

        edges.push_back(edge);
    }

    cout << "\n";

    kruskal(vertices, edges);

    return 0;
}