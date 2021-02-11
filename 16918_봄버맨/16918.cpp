#include <bits/stdc++.h>
using namespace std;

int r, c, time_h;
char graph[201][201];
char tmp[201][201];

int x_dir[] = {-1,0,1,0};
int y_dir[] = {0,1,0,-1};

void getInput() {
    cin >> r >> c >> time_h;
    int i, j;
    for(i=1; i<=r; i++) {
        for(j=1;j<=c; j++) {
            cin >> graph[i][j];
            tmp[i][j] = graph[i][j];
        }
    }
}
void SetBomb() {
    int i, j, k;
    for(i=1; i<=r; i++) {
        for(j=1; j<=c; j++) {
            if (graph[i][j]=='.') graph[i][j]='O';
        }
    }
}

void Explode() {
    int i, j,k;
    for(i=1; i<=r; i++) {
        for(j=1; j<=c; j++) {
            if (tmp[i][j]=='O') {
                graph[i][j]='.';
                for(k=0; k<4; k++) {
                    int dx = i + x_dir[k];
                    int dy = j + y_dir[k];
                    if (dx>=1 && dx<=r && dy>=1 && dy<=c) {
                        graph[dx][dy] = '.';
                    }
                }
            }
        }
    }

    for(i=1; i<=r; i++) {
        for(j=1; j<=c; j++) {
            tmp[i][j] = graph[i][j];
        }
    }
}

void Print() {
    int i, j;
    //cout << endl;
    for(i=1; i<=r; i++) {
        for(j=1; j<=c; j++) {
            cout << graph[i][j];
        }
        cout <<endl;
    }
}
void Solve() {
    int t= 1;
    while(t != time_h) {
        t++;
        SetBomb();
        if (t == time_h) break;

        t++;
        Explode();
        if (t==time_h) break;
    }
    Print();

}
int main() {
    getInput();
    Solve();
    return 0;
}