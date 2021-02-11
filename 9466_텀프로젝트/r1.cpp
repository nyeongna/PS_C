#include <bits/stdc++.h>
using namespace std;

int graph[100002];
int visited[100002];
int finished[100002];
int cnt;


void DFS(int n) {
    int next = graph[n];
    // next�� �ѹ��� �Ȱ������� DFS(next)
    if (visited[next]==0) {
        visited[next]=1;
        DFS(next);
    }
    // next�� ���ôµ� ���� finished[next]�� 0�̶�� cycle �ϼ�
    else if (visited[next]==1 && finished[next]==0) {
        cnt++;
        for(int cur=next; cur != n; cur=graph[cur]) {
            cnt++;
        }
    }
    finished[n]=1;
}
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int i, to;
        for(i=1; i<=n; i++) {
            cin >> to;
            graph[i]= to;
        }
        for(i=1; i<=n; i++) {
            if (visited[i]==0) {
                visited[i]=1;
                DFS(i);
            }
        }
    }
    return 0;
}