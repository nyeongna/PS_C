#include <bits/stdc++.h>
using namespace std;

char graph[13][7];
int visit[13][7];
int tmp[13][7];

int x_dir[] = { -1, 0, 1, 0 };
int y_dir[] = { 0, 1, 0, -1 };

void getInput() {
    int i, j;
    for (i = 1; i <= 12; i++) {
        for (j = 1; j <= 6; j++) {
            cin >> graph[i][j];
        }
    }
    for (j = 1; j <= 6; j++) {
        graph[0][j] = '.';
    }
}

int BFS(int x, int y, char target) {
    memset(visit, 0, sizeof(visit));
    queue<pair<int, int>> Q;
    Q.push({ x, y });
    visit[x][y] = 1;
    int i, j, cnt = 1;

    while (!Q.empty()) {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();

        for (i = 0; i < 4;i++) {
            int dx = x + x_dir[i];
            int dy = y + y_dir[i];
            if (dx >= 1 && dx <= 12 && dy >= 1 && dy <= 6 && visit[dx][dy] == 0 && graph[dx][dy] == target) {
                visit[dx][dy] = 1;
                Q.push({ dx, dy });
                cnt++;
            }
        }
    }

    if (cnt >= 4) {
        for (i = 1; i <= 12; i++) {
            for (j = 1; j <= 6; j++) {
                if (visit[i][j] == 1) {
                    graph[i][j] = '.';
                    tmp[i][j] = 1;
                }
            }
        }
        return 1;
    }
    return 0;

}

void DownCol(int x, int y) {
    // x=11, y = 1
    int i, j;
    for (i = x; i >= 1; i--) {
        graph[i][y] = graph[i - 1][y];
    }

}

void Down() {
    int i, j;
    for (i = 1; i <= 12; i++) {
        for (j = 1; j <= 6; j++) {
            if (tmp[i][j] == 1) {
                graph[i][j] = '.';
                DownCol(i, j);
            }
        }
    }
}

void Print() {
    int i, j;
    cout << endl;
    for (i = 1; i <= 12; i++) {
        for (j = 1; j <= 6; j++) {
            cout << graph[i][j];
        }
        cout << endl;
    }
}

int total = 0;

int Search() {
    int i, j, flag = 0;
    memset(tmp, 0, sizeof(tmp));
    for (i = 1; i <= 12; i++) {
        for (j = 1; j <= 6; j++) {
            if (graph[i][j] != '.') {
                if (BFS(i, j, graph[i][j]) == 1) flag = 1;
            }
        }
    }
    return flag;
}

void Solve() {
    int i, j, result;
    while (Search() == 1) {
        Down();
        //Print();
        total++;
    }
    cout << total << endl;
}

int main() {
    getInput();
    Solve();
    return 0;
}