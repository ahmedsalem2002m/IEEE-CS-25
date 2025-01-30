#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool isValid(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

int dfs(vector<vector<int>> &grid, int x, int y) {
    if (!isValid(x, y, grid.size(), grid[0].size()) || grid[x][y] == 0) {
        return 0;
    }

    
    int volume = grid[x][y];
    grid[x][y] = 0; 

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        volume += dfs(grid, nx, ny);
    }

    return volume;
}

int main() {
    int t;
    cin >> t; 

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        int maxVolume = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] > 0) {
                    maxVolume = max(maxVolume, dfs(grid, i, j));
                }
            }
        }

        cout << maxVolume <<"\n"; 
    }

    return 0;
}
