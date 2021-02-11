#include <bits/stdc++.h>
using namespace std;

int n;
int paper[129][129];

/*
    분할정복
    분할할때 범위지정을 어떻게 하냐에 따라 갈린다! 주의하자.
*/

void getInput() {
    cin >> n;
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            cin >> paper[i][j];
        }
    }
}
int color[2];


// x == 시작지점의 x, y == 시작지점의 y
// n == 확인해야할 거리
void Divide(int x, int y, int n) {
    int i, j, flag = 1;
    // i < x+n 까지 검사한다
    for (i = x; i < x + n; i++) {
        // j < y + n까지 검사한다.
        for (j = y; j < y + n; j++) {
            if (paper[x][y] != paper[i][j]) {
                flag = 0;
                break;
            }
        }
    }
    if (flag == 1) {
        color[paper[x][y]]++;
        return;
    }
    //왼쪽 위
    Divide(x, y, n / 2);
    //오른쪽 위
    Divide(x, y + n / 2, n / 2);
    //왼쪽 아래
    Divide(x + n / 2, y, n / 2);
    //오른쪽 아래
    Divide(x + n / 2, y + n / 2, n / 2);
}
void Print() {
    cout << color[0] << endl;
    cout << color[1] << endl;
}
int main() {
    getInput();
    // 시작지점의 (x,y)좌표로부터 n거리까지만 검사한다.
    Divide(1, 1, n);
    Print();

    return 0;
}