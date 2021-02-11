#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000000

/*
    cnt >= c �� ������ �ɾ������ ������ '����'�ϴ� �� �� ���� ���� ���� ans�� ���Եȴ�!
*/
int n, c;
int a[200001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n >> c;
    int i, j;
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);

    int l = 1, r = 2000000000, mid;
    int ans;

    while (l <= r) {
        int mid = (l + r) / 2;
        int cnt = 1, dist = a[0];
        for (i = 1; i < n; i++) {
            if (a[i] - dist >= mid) {
                cnt++;
                dist = a[i];
            }
        }
        // cnt >= c �� ������ �ɾ������ ������ '����'�ϴ� �� �� ���� ���� ���� ans�� ���Եȴ�!
        if (cnt >= c) {
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout << ans << endl;

    return 0;
}