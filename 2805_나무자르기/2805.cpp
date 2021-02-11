#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000000

int n, m;
int a[1000001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n >> m;
    int i, j, max_h=-1;
    for(i=1; i<=n; i++) {
        cin >> a[i];
        max_h = max(max_h, a[i]);
    }
    int l = 0;
    int r = max_h;
    int mid;
    while (l+1 < r) {
        mid = (l+r) / 2;
        long long int sum=0;
        for(i=1; i<=n; i++) {
            if (mid <= a[i]) sum = sum + a[i]-mid;
        }
        //cout << l << " " << r <<  " " << mid << " " << sum << endl;
        // 현재 mid(h)가 m과 똑같거나 크다면, 즉 조건을 만족한다면
        if (sum >= m) {
            l=mid;
        }
        else {
            r = mid;
        }
    }
    cout << l << endl;
    return 0;
}