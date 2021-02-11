#include <bits/stdc++.h>
using namespace std;


int n;
int a[100002];

long long int Find(int l, int r) {
    // ������� (base case)
    if (l == r) return a[l];

    long long int mid = (l + r) / 2;
    long long int ans = max(Find(l, mid), Find(mid + 1, r));



    // �߰��� �� ū ������׷��� ���� ���
    long long int p = mid, q = mid, w = 1, ph = a[mid], qh = a[mid + 1];
    int h = a[mid];

    while (p > l || q < r) {


        ph = p > l ? min(a[p - 1], h) : -1;
        qh = q < r ? min(a[q + 1], h) : -1;
        // ������ ���̰� ū ���
        if (ph >= qh) {
            w++;
            p--;
            h = ph;

        }
        // �������� ���̰� ū ���
        else {
            w++;
            q++;
            h = qh;
        }
        ans = max(ans, h * w);

    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, j;
    long long int ans = 0;

    while (1) {
        cin >> n;
        if (n == 0) break;
        for (i = 1; i <= n; i++) {
            cin >> a[i];
        }

        cout << Find(1, n) << endl;
    }

    return 0;
}