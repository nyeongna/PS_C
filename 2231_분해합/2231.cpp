#include <bits/stdc++.h>
using namespace std;

int n;

int Check(int a) {
    int i;
    int total=a;
    while (a != 0) {
        total += a % 10;
        a /= 10;
    }
    if (total==n) return 1;
    return 0;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n;
    int i;
    for(i=1; i<=n; i++) {
        if (Check(i)) {
            cout << i << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}