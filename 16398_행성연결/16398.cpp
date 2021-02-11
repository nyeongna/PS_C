#include <bits/stdc++.h>
using namespace std;

int n;
int dist[1001][1001];
int visit[1001];
int check[1001];
int cnt;

typedef struct Edge {
    int from, to, weight;
    bool operator<(const Edge& b) const {
        return weight > b.weight;
    }
} Edge;

priority_queue<Edge> PQ;

int Find(int a) {
    if (check[a]==a) return a;
    return check[a] = Find(check[a]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if (a!=b) {
        check[a] = b;
    }
}

void getInput() {
    cin >> n;
    int i, j;
    for (i = 1; i <= n; i++) {
        check[i] = i;
        for (j = 1; j <= n; j++) {
            cin >> dist[i][j];
            if (i < j) {
                PQ.push({i, j, dist[i][j]});
                cnt++;
                //Union(i,j);
            }
        }
    }
}

int ans;
void Solve() {
    int edge=0;
    long long int total=0;
    
    while(!PQ.empty()) {
        int from = PQ.top().from;
        int to = PQ.top().to;
        int weight = PQ.top().weight;
        PQ.pop();

        if (Find(from) != Find(to)) {
            Union(from,to);
            edge++;
            total = total + weight;
        }
        if (edge==n-1) break;
    }
    cout << total << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    getInput();
    Solve();
    return 0;
}