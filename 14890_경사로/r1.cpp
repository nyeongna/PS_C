#include <bits/stdc++.h>
using namespace std;


int N, L;
int graph[101][101];
int graph_2[101][101];
int visit[101][101];
int ans;

void getInput() {
    cin >> N >> L;
    int i, j;
    for (i=1; i<=N;i++) {
        for (j=1; j<=N; j++) {
            cin >> graph[i][j];
            graph_2[j][i] = graph[i][j];
        }
    }
}

int RightLarge(int i, int j) {
    int k;
    if (j < L) {
        ans--;
        return 0;
    }
    for (k=j; k>=j-L+1; k--) {
        if (visit[k]==1) {
            ans--;
            return 0;
        }
    }
    for (k=j; k>=j-L+1; k--) {
        visit[k]=1;
    }
    return 1;
}
void Operation(int graph[][101]) {
    int i, j, k;
    for (i=1; i<=N; i++) {
        for (j=1; j<N; j++) {
            // 높이 차가 2이상이라면 break
            if (abs(graph[i][j]-graph[i][j+1] >= 2)) {
                ans--;
                break;
            }
            // 오른쪽 칸 1 더 크면
            if (graph[i][j] == graph[i][j+1]-1) {
                // 다리 길이 L보다 j가 짧다면 break
                RightLarge(i,j);
        
            }
        }
    }
}

int main() {
    getInput();
    Solve();
    return 0;
}