#include <iostream>
#include <vector>
using namespace std;

bool isValid(int x, int y, int n, int m, vector<vector<bool>>& visited, const vector<string>& grid) {
    return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == '.' && !visited[x][y];
}

void dfs(int x, int y, int n, int m, vector<vector<bool>>& visited, const vector<string>& grid) {
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    visited[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int newX = x + dx[i];
        int newY = y + dy[i];
        if (isValid(newX, newY, n, m, visited, grid)) {
            dfs(newX, newY, n, m, visited, grid);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int roomCount = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.' && !visited[i][j]) {
                dfs(i, j, n, m, visited, grid);
                roomCount++;
            }
        }
    }
    cout << roomCount << endl;
    return 0;
}
