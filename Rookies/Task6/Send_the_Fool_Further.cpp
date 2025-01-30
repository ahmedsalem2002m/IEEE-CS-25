#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int v, cost;
};

vector<vector<Edge>> adj;
vector<bool> visited;
int max_cost = 0;

void dfs(int node, int current_cost) {
    visited[node] = true;
    max_cost = max(max_cost, current_cost);

    for (const Edge &e : adj[node]) {
        if (!visited[e.v]) {
            dfs(e.v, current_cost + e.cost);
        }
    }
}

int main() {
    int n;
    cin >> n;

    adj.resize(n);
    visited.resize(n, false);

    for (int i = 0; i < n - 1; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }

    dfs(0, 0);

    cout << max_cost << endl;

    return 0;
}
