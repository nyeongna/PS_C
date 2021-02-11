#include <bits/stdc++.h>
using namespace std;

int n;
int cnt[4];
int graph[2500][2500];

int Same(int n, int x, int y) {
    int i, j, minus=1, zero=1, one=1;

    for(i=x; i<=x + n-1; i++) {
        for(j=y; j<=y + n - 1; j++) {
            if (graph[i][j]==-1) {
                zero=0;
                one=0;
            }
            if (graph[i][j]==0) {
                minus=0;
                one=0;
            }
            if (graph[i][j]==1) {
                minus=0;
                zero=0;
            }
        }
    }

    if (minus==1) return 1;
    if (zero==1) return 2;
    if (one==1) return 3;
    return 0;
}

void Divide(int n, int x, int y) {
    int ch, i, j;
    if(n==1) {
        cnt[graph[x][y]+2]++;
        return;
    }

    if (ch=Same(n,x,y)) {
        cnt[ch]++;
    }
    else {
        int div = n/3;
        for(i=0; i<3; i++) {
            for(j=0; j<3; j++) {
                Divide(div, x+i*div, y+j*div);
            }
        }
    }
}
void Print() {
    cout << cnt[1] << endl;
    cout << cnt[2] << endl;
    cout << cnt[3] << endl;
}
int main() {
    cin >> n;
    int i, j;
    for(i=1; i<=n; i++) {
        for(j=1; j<=n; j++) {
            cin >> graph[i][j];
        }
    }

    Divide(n, 1, 1);
    Print();
    return 0;
}