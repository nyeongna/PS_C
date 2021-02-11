#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000000

int k, n;
int a[10001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> k >> n;

    int i;
    for(i=1; i<=k; i++) {
        cin >> a[i];
    }

    long long int l = 1, r = 10000000000;
    long long mid, ans;

    
    while (l+1 < r) {
        mid  = (l+r) /2;
        long long int sum =0;
        for(i=1; i<=k; i++) {
            sum = sum + a[i]/mid;
        }
        if (sum < n) {
            r = mid;
        }
        else {
            ans = mid;
            l = mid;
        }
    }
    cout << l << endl;

    return 0;
}