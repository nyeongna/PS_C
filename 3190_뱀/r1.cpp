#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000000
#define lld long long int

int n, k, l;
// 0=��ĭ, 1=���, 2=����
int board[102][102];
list<pair<int, int>> snake;
int T = 0;
char D = 'R';

void ChangeDir(char dir) {
    if (D == 'R' && dir == 'D') {
        D = 'D';
    }
    else if (D == 'R' && dir == 'L') {
        D = 'U';
    }

    else if (D == 'L' && dir == 'D') {
        D = 'U';
    }
    else if (D == 'L' && dir == 'L') {
        D = 'D';
    }

    else if (D == 'U' && dir == 'D') {
        D = 'R';
    }
    else if (D == 'U' && dir == 'L') {
        D = 'L';
    }

    else if (D == 'D' && dir == 'D') {
        D = 'L';
    }
    else if (D == 'D' && dir == 'L') {
        D = 'R';
    }

}
void Print() {
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
int Move(char d) {
    int r = snake.front().first;
    int c = snake.front().second;
    if (d == 'R') c++;
    else if (d == 'L') c--;
    else if (d == 'U') r--;
    else if (d == 'D') r++;

    // �迭 ����ų� || ���� �ε����� -1
    if (r < 1 || r > n || c < 1 || c > n || board[r][c] == 2) return -1;
    // ����� ������
    else if (board[r][c] == 1) {
        snake.push_front({ r,c });
        board[r][c] = 2;
    }
    // ��ĭ�̾��ٸ�
    else if (board[r][c] == 0) {
        board[snake.back().first][snake.back().second] = 0;
        snake.pop_back();
        snake.push_front({ r,c });
        board[r][c] = 2;

    }
    return 1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n >> k;
    int i, j, r, c;
    int step;
    char dir;
    for (i = 1; i <= k; i++) {
        cin >> r >> c;
        board[r][c] = 1;
    }

    snake.push_front({ 1,1 });
    board[1][1] = 2;

    cin >> l;
    for (i = 1; i <= l; i++) {
        cin >> step >> dir;
        while (T < step) {
            int res = Move(D);

            if (res == -1) {
                cout << T + 1 << endl;
                return 0;
            }
            else {
                T++;
            }
        }
        ChangeDir(dir);
    }
    // ������ȯ�� ������ �ȳ������� ��� �����Ѵ�.
    while (1) {
        int res = Move(D);
        if (res == -1) {
            cout << T + 1 << endl;
            return 0;
        }
        else T++;
    }
    return 0;
}