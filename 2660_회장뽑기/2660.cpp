#include <bits/stdc++.h>
using namespace std;

int n;
int dist[51][51];

void getInput() {
    cin >> n;
    int i, j, from, to;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (i == j) dist[i][j] = 0;
            else dist[i][j] = 1000000000;
        }
    }
    while (1) {
        cin >> from >> to;
        if (from == -1 && to == -1) break;
        dist[from][to] = 1;
        dist[to][from] = 1;
    }
}

void Solve() {
    int i, j, k;
    for (k = 1; k <= n; k++) {
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (i == j) continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    
    int max_num = -2147000000;
    int real_max = 2147000000;
    int max_friend[51];
    for (i = 1; i <= n; i++) {
        max_num = -2147000000;
        for (j = 1; j <= n; j++) {
            max_num = max(max_num, dist[i][j]);
        }
        real_max = min(real_max, max_num);
        max_friend[i] = max_num;
    }
    vector<int> a;
    for (i = 1; i <= n; i++) {
        if (max_friend[i] == real_max) a.push_back(i);
    }
    cout << real_max << " " << a.size() << endl;
    for (auto i : a) {
        cout << i << " ";
    }
}

int main()
{
    getInput();
    Solve();

    return 0;
}