#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n = 6;
    vector<int> adj[6];

    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(4);
    adj[4].push_back(5);

    bool visited[6] = {false};

    queue<int> q;

    int start = 0;
    visited[start] = true;
    q.push(start);

    while(!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";

        for(int v : adj[u]) {
            if(!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }

    return 0;
}
