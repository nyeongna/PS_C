#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000000

int n, m, a[100001];

int Count(int size) {
    int cnt=1;
    int i, sum=0;

    for(i=1; i<=n; i++) {
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

    // l 이 불만족 중 가장 크고, r이 만족 중 가장 작은 식으로 풀 수 있다.
    // 하지만 l = 1 인데 r = sum = 2으로 나온경우 바로 while loop이 풀리는 경우가 있다.
    // 이 경우는 m가 전체 노래의 길이가 같을 때 인데 (예를 들어, 3 3 , 1 1 1) 이런 경우만 별로 처리하여 1 출력하면 된다.
    // 즉 r = 1 이 될 수 있는 상황이 (l+1 <r)에서는 안만들어지므로 이 특수한 상황만 처리하면 된다.
    // 나머지 경우는 (l + 1 < r) 이 성립한다.
    if (m==sum) {
        cout << m/sum << endl;
        return 0;
    }
    while(l +1 < r) {
        mid = (l+r) / 2;       
        if (Count(mid) <= m && max_length <= mid) {
            r = mid;
        }
        else {
            l = mid;
        }
    }

    cout << r << endl;


    return 0;
}