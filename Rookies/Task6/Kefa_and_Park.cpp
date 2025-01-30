#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> hasCat;
int n, m;
int validRestaurants = 0;

void dfs(int node, int consecutiveCats) {
    visited[node] = true;
    if (consecutiveCats > m)
        return;
    bool isLeaf = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            isLeaf = false;
            dfs(neighbor, hasCat[neighbor] ? consecutiveCats + 1 : 0);
        }
    }
    if (isLeaf)
        validRestaurants++;
}

int main() {
    cin >> n >> m;
    adj.resize(n + 1);
    visited.resize(n + 1, false);
    hasCat.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> hasCat[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, hasCat[1] ? 1 : 0);
    cout << validRestaurants << endl;
    return 0;
}
