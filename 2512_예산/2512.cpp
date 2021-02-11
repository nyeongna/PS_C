#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000000

int n;
int a[10001];
int m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n;
    int i, j, max_m = -1;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
        max_m = max(max_m, a[i]);
    }
    cin >> m;

    int l = 0;
    int r = max_m + 1;
    int mid;
    while (l + 1 < r) {
        mid = (l + r) / 2;
        long long sum = 0;
        for (i = 1; i <= n; i++) {
            if (a[i] >= mid) {
                sum = sum + mid;
            }
            else {
                sum = sum + a[i];
            }
        }
        // mid도 m보다 작아야함.
        // 왜냐하면 mid가 m보다 커버리면 그것또한 불만족하는 식이기 때문
        // l 만족하는 수 중 가장 큰 수, r 불만족하는 수 중 가장 작음.
        if (mid <= m && sum <= m) {
            l = mid;
        }
        else {
            r = mid;
        }
    }

    cout << l << endl;


    return 0;
}