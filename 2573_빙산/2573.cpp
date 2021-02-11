#include <bits/stdc++.h>
using namespace std;

int m, n;
int ice[301][301];
int tmp[301][301];
int visit[301][301];

int x_dir[] = { -1,0,1,0 };
int y_dir[] = { 0,1,0,-1 };

int x_last;
int y_last;

void getInput() {
    cin >> m >> n;
    int i, j;
    for (i = 1; i <= m;i++) {
        for (j = 1; j <= n; j++) {
            cin >> ice[i][j];
        }
    }
}
void Melt() {
    int i, j;
    memset(tmp, 0, sizeof(tmp));
    x_last = -1, y_last = -1;

    for (i = 1; i <= m; i++) {
        for (j = 1;j <= n; j++) {
            if (ice[i][j] != 0) {
                int cnt = 0;
                for (int k = 0; k < 4; k++) {
                    int dx = i + x_dir[k];
                    int dy = j + y_dir[k];
                    if (ice[dx][dy] == 0) cnt++;
                }
                tmp[i][j] = (ice[i][j] - cnt) < 0 ? 0 : ice[i][j] - cnt;
                if (tmp[i][j]!=0) {
                    x_last = i;
                    y_last = j;
                }
            }
        }
    }
}
int Check() {
    memset(visit, 0, sizeof(visit));
    int i, j;
    if (x_last==-1 && y_last==-1) return 2;
    queue<pair<int,int>> Q;
    Q.push({x_last, y_last});
    //cout << x_last << " " << y_last << endl;
    
    while(!Q.empty()) {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();

        for(i=0; i<4; i++) {
            int dx = x+ x_dir[i];
            int dy = y+ y_dir[i];
            if (tmp[dx][dy] != 0 && visit[dx][dy]==0) {
                visit[dx][dy]=1;
                Q.push({dx,dy});
            }
        }
    }
    for(i=1; i<=m; i++) {
        for(j=1; j<=n; j++) {
            if (tmp[i][j]!=0 && visit[i][j]==0) return 1;
        }
    }
    return 0;
}
void Change() {
    int i, j;
    for(i=1; i<=m; i++) {
        for(j=1; j<=n; j++) {
            ice[i][j] = tmp[i][j];
        }
    }
}
void Print() {
    int i, j;
    cout << endl;
    for(i=1; i<=m; i++) {
        for(j=1; j<=n; j++) {
            cout << tmp[i][j] << " ";
        }
        cout <<endl;
    }
}
void Solve() {
    int i, j, year = 0;
    int res;
    while (1) {
        year++;
        Melt();
        //Print();
        res = Check();
        // 모두 동시에 녹아버렸을 경우
        if (res==2) {
            year=0;
            break;
        }
        // 분리가되었을 경우
        else if (res==1) {
            break;
        }
        // 그대로 한덩이 유지한 경우
        Change();
    }
    cout << year << endl;
}
int main() {
    getInput();
    Solve();
    return 0;
}