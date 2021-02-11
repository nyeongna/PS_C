#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000000

int n;
int a[1001];
int dp[1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n;
    int i, j, sum;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (i = 1; i <= n; i++) {
        sum = a[i];
        for (j = i - 1; j >= 1; j--) {
            if (a[j] < a[i]) {
                sum = max(sum, a[i] + dp[j]);
            }
        }
        dp[i] = sum;
    }

    int ans2 = dp[1];
    for (i = 1; i <= n; i++) {
        ans2 = max(ans2, dp[i]);
    }

    int* ans = max_element(dp + 1, dp + n + 1);
    cout << *ans << endl;
    //cout << ans2 << endl;

    return 0;
}