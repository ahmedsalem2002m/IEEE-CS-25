#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm> // لإضافة الدالة reverse
using namespace std;

struct Position {
    int x, y;
};

bool isValid(int x, int y, int n, int m, const vector<string>& labyrinth, vector<vector<bool>>& visited) {
    return x >= 0 && x < n && y >= 0 && y < m && labyrinth[x][y] != '#' && !visited[x][y];
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> labyrinth(n);
    Position start, end;

    for (int i = 0; i < n; i++) {
        cin >> labyrinth[i];
        for (int j = 0; j < m; j++) {
            if (labyrinth[i][j] == 'A') start = {i, j};
            if (labyrinth[i][j] == 'B') end = {i, j};
        }
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<Position>> parent(n, vector<Position>(m, {-1, -1}));
    vector<vector<char>> direction(n, vector<char>(m, ' '));
    queue<Position> q;

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    char dir[] = {'U', 'D', 'L', 'R'};

    q.push(start);
    visited[start.x][start.y] = true;

    while (!q.empty()) {
        Position current = q.front();
        q.pop();

        if (current.x == end.x && current.y == end.y) {
            cout << "YES" << endl;

            string path;
            Position trace = end;

            while (trace.x != start.x || trace.y != start.y) {
                path += direction[trace.x][trace.y];
                trace = parent[trace.x][trace.y];
            }

            reverse(path.begin(), path.end());
            cout << path.size() << endl;
            cout << path << endl;
            return 0;
        }

        for (int i = 0; i < 4; i++) {
            int newX = current.x + dx[i];
            int newY = current.y + dy[i];

            if (isValid(newX, newY, n, m, labyrinth, visited)) {
                visited[newX][newY] = true;
                parent[newX][newY] = current;
                direction[newX][newY] = dir[i];
                q.push({newX, newY});
            }
        }
    }

    cout << "NO" << endl;
    return 0;
}
