#include <bits/stdc++.h>
using namespace std;
#define endl "\n";

int cnt;
int r, c;

void Div(int x, int y, int n) {
    int i, j;
    if (n == 2) {
        for (i = x; i < x + n; i++) {
            for (j = y; j < y + n; j++) {
                cnt++;
                if (i == r && j == c) {
                    cout << cnt - 1 << endl;
                    exit(0);
                }
            }
        }
        return;
    }

    Div(x, y, n / 2);
    Div(x, y + n / 2, n / 2);
    Div(x + n / 2, y, n / 2);
    Div(x + n / 2, y + n / 2, n / 2);

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n >> r >> c;
    r++, c++;

    Div(1, 1, (int)pow(2, n));


    return 0;
}