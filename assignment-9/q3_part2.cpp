#include<iostream>
using namespace std;

int findParent(int x, int parent[]) {
    if (parent[x] == x) return x;
    return parent[x] = findParent(parent[x], parent);
}

void unionSet(int a, int b, int parent[], int rankv[]) {
    a = findParent(a, parent);
    b = findParent(b, parent);
    if (a == b) return;
    if (rankv[a] < rankv[b]) swap(a, b);
    parent[b] = a;
    if (rankv[a] == rankv[b]) rankv[a]++;
}

int main() {
    int n = 5;   // number of vertices (0..n-1)
    int m = 7;   // number of edges

    // edges stored as parallel arrays
    int U[7] = {0, 0, 1, 1, 1, 2, 3};
    int V[7] = {1, 3, 2, 3, 4, 4, 4};
    int W[7] = {2, 6, 3, 8, 5, 7, 9};

    bool usedEdge[7];
    for (int i = 0; i < m; ++i) usedEdge[i] = false;

    int parent[100], rankv[100];
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
        rankv[i] = 0;
    }

    cout << "Greedy Kruskal MST (select min unused edge each step):\n";
    int edgesTaken = 0, totalWeight = 0;

    while (edgesTaken < n - 1) {
        int minWeight = INT_MAX;
        int minIdx = -1;
        for (int i = 0; i < m; ++i) {
            if (!usedEdge[i] && W[i] < minWeight) {
                minWeight = W[i];
                minIdx = i;
            }
        }
        if (minIdx == -1) break;

        usedEdge[minIdx] = true; 

        int u = U[minIdx];
        int v = V[minIdx];

        int pu = findParent(u, parent);
        int pv = findParent(v, parent);

        if (pu != pv) {
            unionSet(pu, pv, parent, rankv);
            cout << u << " - " << v << " (w=" << W[minIdx] << ")\n";
            totalWeight += W[minIdx];
            edgesTaken++;
        }
    }

    if (edgesTaken != n - 1) {
        cout << "Graph is disconnected — MST doesn't exist for all vertices.\n";
    } else {
        cout << "Total weight of MST = " << totalWeight << "\n";
    }

    return 0;
}