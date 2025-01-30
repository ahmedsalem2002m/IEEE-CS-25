#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited) {
    visited[node] = true;
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited);
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> p(n + 1);
    vector<vector<int>> graph(n + 1);

    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        if (i != p[i]) {
            graph[i].push_back(p[i]);
            graph[p[i]].push_back(i);
        }
    }

    vector<bool> visited(n + 1, false);
    int treeCount = 0;

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            ++treeCount;
            dfs(i, graph, visited);
        }
    }

    cout << treeCount << endl;
    return 0;
}
