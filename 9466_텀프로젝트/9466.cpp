#include <bits/stdc++.h>
using namespace std;

int graph[100002];
int visited[100002];
int finished[100002];
int cnt=0;

void Cyclonize(int n) {
    int a = 4;
    int next = graph[n];
    cnt++;
    while (next != n) {
        cnt++;
        next = graph[next];
    }
    
}
void DFS(int n) {
    int i, j;
    int next = graph[n];
    // next°¡ visiteded & unfinished = ÆÀ ±¸¼º X
    if (visited[next]==0) {
        visited[next]=1;
        DFS(next);
    }
    else if (visited[next]==1 && finished[next]==0) {
        Cyclonize(n);
    }
    finished[n]=1;
}
int main() {
    int t, n, i, to;
    cin >> t;
    while(t--) {
        memset(graph, 0, sizeof(graph));
        memset(visited, 0, sizeof(visited));
        memset(finished, 0, sizeof(finished));
        cnt=0;
        cin >> n;
        for(i=1; i<=n; i++) {
            cin >> to;
            graph[i] = to;
        }
        for(i=1; i<=n; i++) {
            if (visited[i]==0) {
                visited[i]=1;
                DFS(i);
                
            }
        }
        cout << n - cnt << endl;

    }
    return 0;
}