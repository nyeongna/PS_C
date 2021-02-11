#include <bits/stdc++.h>
using namespace std;

/*
    1. ������ Ʈ�� �����̴�. A -> B�� ���� ���� �����ϴ� (��, cycle�� ����)
    2. Single Source Shortest Path�� ���ϸ� �ȴ�.
    3. ������ ���� �� ���� �־ ����� �ǹǷ� (Shortest path - longest edge)�� �ϸ� �ȴ�.
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