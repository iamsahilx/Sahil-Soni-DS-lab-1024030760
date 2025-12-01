#include<iostream>
using namespace std;

int main() {
    int n = 5;
    int INF = 1e9;
    int graph[5][5] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    int key[5];
    bool mstSet[5];
    int parent[5];
    for (int i = 0; i < n; i++) {
        key[i] = INF;
        mstSet[i] = false;
    }

    key[0] = 0;     
    parent[0] = -1;  

    for (int count = 0; count < n - 1; count++) {
        int u = -1;
        int minVal = INF;

        for (int v = 0; v < n; v++) {
            if (!mstSet[v] && key[v] < minVal) {
                minVal = key[v];
                u = v;
            }
        }

        mstSet[u] = true;
        for (int v = 0; v < n; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    cout << "Edges in MST:\n";
    for (int i = 1; i < n; i++) {
        cout << parent[i] << " - " << i << "\n";
    }

    return 0;
}