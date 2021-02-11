#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000000
#define lld long long int

/*
    A[i][j] = i * j 인 배열에서
    특정 수 k 보다 작거나 같은 수의 갯수를 찾는 문제가 핵심이다(N번 만에 찾아야함)
    1 2  3  4  5
    2 4  6  8  10
    3 6  9  12 15
    4 8  12 16 20
    5 10 15 20 25
    11 이하인 수 = 1행(11/1) + 2행(11/2) + 3행(11/3) + 4행(11/4) + 5행(11/5) 이다..
    각 행은 `i`의 배수이므로....
*/

int n, k;

int Count(int mid) {
    int i, sum = 0;
    for (i = 1; i <= n; i++) {
        sum = sum + min(n, mid / i);
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n;
    cin >> k;

    int l = 1, r = (1e9) + 1, mid;
    int ans;

    while (l <= r) {
        mid = (l + r) / 2;
        int cnt = Count(mid);
        //cout << l << " " << r << " " << mid << " " << cnt << endl;
        if (cnt >= k) {
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << ans << endl;


    return 0;
}