#include <iostream>
#include <queue>
#include <unordered_set>
#include <string>
using namespace std;

struct Position {
    int x, y, moves;
};

bool isValid(int x, int y) {
    return x >= 0 && x < 8 && y >= 0 && y < 8;
}

int bfs(string start, string destination) {
    int startX = start[0] - 'a';
    int startY = start[1] - '1';
    int destX = destination[0] - 'a';
    int destY = destination[1] - '1';

    if (startX == destX && startY == destY) return 0;

    int knightMoves[8][2] = {
        {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
        {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
    };

    queue<Position> q;
    bool visited[8][8] = {false};
    q.push({startX, startY, 0});
    visited[startX][startY] = true;

    while (!q.empty()) {
        Position current = q.front();
        q.pop();

        for (int i = 0; i < 8; i++) {
            int newX = current.x + knightMoves[i][0];
            int newY = current.y + knightMoves[i][1];

            if (isValid(newX, newY) && !visited[newX][newY]) {
                if (newX == destX && newY == destY) {
                    return current.moves + 1;
                }

                q.push({newX, newY, current.moves + 1});
                visited[newX][newY] = true;
            }
        }
    }
    return -1;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        string start, destination;
        cin >> start >> destination;
        cout << bfs(start, destination) << endl;
    }

    return 0;
}
