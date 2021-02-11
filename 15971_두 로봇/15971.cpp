#include <bits/stdc++.h>
using namespace std;

/*
    1. 문제는 트리 구조이다. A -> B로 가는 길은 유일하다 (즉, cycle이 없다)
    2. Single Source Shortest Path를 구하면 된다.
    3. 하지만 정점 양 끝에 있어도 통신이 되므로 (Shortest path - longest edge)를 하면 된다.
*/

int n, r1, r2;

typedef struct {
    int edge, dist, longest;
} Edge;

vector<pair<int, int>> graph[100001];
int visit[100001];

void getInput() {
    cin >> n >> r1 >> r2;
    int i, j;
    int from, to, weight;
    for (i = 1; i < n; i++) {
        cin >> from >> to >> weight;
        graph[from].push_back({ to, weight });
        graph[to].push_back({ from,weight });
    }
}

void Solve() {
    queue<Edge> Q;
    Q.push({ r1, 0, 0 });
    visit[r1] = 1;
    int i;
    while (!Q.empty()) {
        int now = Q.front().edge;
        int dist = Q.front().dist;
        int largest = Q.front().longest;
        Q.pop();

        if (now == r2) {
            cout << dist - largest << endl;
            return;
        }
        for (i = 0; i < graph[now].size(); i++) {
            if (visit[graph[now][i].first] != 0) continue;
            visit[graph[now][i].first] = 1;
            Q.push({ graph[now][i].first, dist + graph[now][i].second, max(largest, graph[now][i].second) });
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    getInput();
    Solve();
    return 0;
}