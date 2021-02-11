#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000000

int n, m, a[100001];

int Count(int size) {
    int cnt=1;
    int i, sum=0;

    for(i=1; i<=n; i++) {
        if (a[i] > size) {
            return 100001;
        }
        if (sum+a[i] > size) {
            cnt++;
            sum=a[i];
        }
        else sum = sum + a[i];
    }
    //cout << cnt << " ";
    return cnt;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n;
    cin >> m;
    int i, j, sum=0, max_length=-1;
    for(i=1; i<=n; i++) {
        cin >> a[i];
        sum = sum + a[i];
        max_length = max(max_length, a[i]);
    }

    // l 이면 조건 불만족, r이면 조건 만족
    int l = 1, r = sum, mid;
    int ans;
    while(l <= r) {
        mid = (l+r) / 2;

        //cout << l << " " << r << " " << mid << endl;
        
        if (Count(mid) <= m && max_length <= mid) {
            r = mid-1;
            ans = mid;
        }
        else {
            l = mid+1;
        }
    }
    cout << ans << endl;


    return 0;
}