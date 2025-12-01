#include<iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 6; 
    const long long INF = (long long)1e15;
    vector<pair<int,long long>> adj[6];
    adj[0].push_back({1, 7});
    adj[0].push_back({2, 9});
    adj[0].push_back({5, 14});
    adj[1].push_back({2, 10});
    adj[1].push_back({3, 15});
    adj[2].push_back({3, 11});
    adj[2].push_back({5, 2});
    adj[3].push_back({4, 6});
    adj[4].push_back({5, 9});

    int src = 0; 
    vector<long long> dist(n, INF);
    vector<int> parent(n, -1);
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        long long d = top.first;
        int u = top.second;

        // stale entry check
        if (d != dist[u]) continue;

        for (auto &edge : adj[u]) {
            int v = edge.first;
            long long w = edge.second;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
    cout << "Distance from source " << src << ":\n";
    for (int i = 0; i < n; ++i) {
        if (dist[i] == INF) cout << i << ": INF\n";
        else cout << i << ": " << dist[i] << "\n";
    }
    int target = 4;
    if (dist[target] == INF) {
        cout << "No path to " << target << "\n";
    } else {
        vector<int> path;
        for (int v = target; v != -1; v = parent[v]) path.push_back(v);
        reverse(path.begin(), path.end());
        cout << "Shortest path to " << target << ": ";
        for (int i = 0; i < (int)path.size(); ++i) {
            if (i) cout << " -> ";
            cout << path[i];
        }
        cout << "\n";
    }

    return 0;
}