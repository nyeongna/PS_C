#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000000
#define lld long long int

int n, k, l;
int board[101][101];
list<pair<int, int>> snake;


int Check(int r, int c) {
    //cout << "r:" << r << "c:" << c << " " << board[r][c] << endl;
    // 벽이거나 몸통이면 -1
    if (r > n || r < 1 || c > n || c < 1 || board[r][c] == 2) {
        return -1;
    }
    // 사과면 2
    if (board[r][c] == 1) {
        return 2;
    }
    // 아무것도 없으면 0
    return 1;
}
int Move(char d) {
    int r_dir = snake.front().first, c_dir = snake.front().second;
    // 오른쪽으로 1칸
    if (d == 'R') {
        int res = Check(r_dir, c_dir + 1);
        // 벽이거나 몸통이면
        if (res == -1) return -1;
        // 사과면 길이 늘리고
        else if (res == 2) {
            snake.push_front({ r_dir, c_dir + 1 });
        }
        // 빈칸이면
        else if (res == 1) {
            snake.push_front({ r_dir, c_dir + 1 });
            snake.pop_back();
        }
        board[r_dir][c_dir + 1] = 2;
    }
    else if (d == 'L') {
        int res = Check(r_dir, c_dir - 1);
        // 벽이거나 몸통이면
        if (res == -1) return -1;
        // 사과면 길이 늘리고
        else if (res == 2) {
            snake.push_front({ r_dir, c_dir - 1 });
        }
        // 빈칸이면
        else if (res == 1) {
            snake.push_front({ r_dir, c_dir - 1 });
            snake.pop_back();
        }
        board[r_dir][c_dir - 1] = 2;

    }
    else if (d == 'U') {
        int res = Check(r_dir - 1, c_dir);
        // 벽이거나 몸통이면
        if (res == -1) return -1;
        // 사과면 길이 늘리고
        else if (res == 2) {
            snake.push_front({ r_dir - 1, c_dir });
        }
        // 빈칸이면
        else if (res == 1) {
            snake.push_front({ r_dir - 1, c_dir });
            snake.pop_back();
        }
        board[r_dir - 1][c_dir] = 2;

    }
    else if (d == 'D') {
        int res = Check(r_dir + 1, c_dir);
        // 벽이거나 몸통이면
        if (res == -1) return -1;
        // 사과면 길이 늘리고
        else if (res == 2) {
            snake.push_front({ r_dir + 1, c_dir });
        }
        // 빈칸이면
        else if (res == 1) {
            snake.push_front({ r_dir + 1, c_dir });
            snake.pop_back();
        }
        board[r_dir + 1][c_dir] = 2;
    }
    return 1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int i, j, r, c;
    int Time;
    char D = 'R';
    char Dir;
    // 초기 뱀 위치
    snake.push_back({ 1,1 });

    // 사과 위치 기록
    cin >> n >> k;
    for (i = 1; i <= k; i++) {
        cin >> r >> c;
        board[r][c] = 1;
    }
    // 방향 꺾기
    cin >> l;

    int t = 0;
    while (1) {
        for (i = 1; i <= l; i++) {
            cin >> Time >> Dir;
            while (t < Time) {
                int res = Move(D);
                cout << "t: " << t << " "<< "res: " << res << endl;
                if (res == 1) {
                    t++;
                }
                else {
                    cout << t+1 << endl;
                    return 0;
                }
            }
            D = Dir;
        }
        int res = Move(D);
        if (res==1) {
            t++;
        }
        else {
            cout << t+1 << endl;
            return 0;
        }

    }




    return 0;
}