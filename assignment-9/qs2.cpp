#include<iostream>
using namespace std;

vector<int> adj[100];
bool visited[100];
void dfs(int u) {
    visited[u] = true;
    cout << u << " ";
    for(int v : adj[u]) {
        if(!visited[v]) {
            dfs(v);
        }
    }
}

int main() {
    int n = 6;
    adj[0] = {1, 2};
    adj[1] = {3};
    adj[2] = {4};
    adj[4] = {5};

    for(int i = 0; i < n; i++) {
        visited[i] = false;
    }

    dfs(0);
}