#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000000

int n, m;
int a[100001];

int Count(int k) {
    int i, j, cnt = 1;
    int tmp = k;
    for (i = 1; i <= n; i++) {
        if (tmp < a[i]) {
            cnt++;
            tmp = k - a[i];
        }
        else tmp = tmp - a[i];
    }
    return cnt;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n >> m;
    int i, j, max_p = -1;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
        max_p = max(max_p, a[i]);
    }

    int l = max_p - 1, r = 100001, mid;
    int ans;

    while (l + 1 < r) {

        mid = (l + r) / 2;
        //cout << l << " " << r << " " << mid << endl;
        if (Count(mid) <= m && max_p <= mid) {
            r = mid;
            ans = mid;
        }
        else l = mid;
    }

    cout << r << endl;


    return 0;
}