#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000000
#define lld long long int

struct Pattern {
    lld from,to,step;
};
vector<Pattern> a;
lld n, k, d;


lld Count(lld mid) {
    lld i, j;
    lld cnt=0;
    for(i=0; i<a.size(); i++) {
        lld from = a[i].from;
        lld to = mid;
        lld step = a[i].step;
        if (from > to) continue;
        // 'mid'번째 상자까지의 도토리 갯수를 모두 더한다.
        cnt = cnt + ((to - from) / step + 1);
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n >> k >> d;
    lld i, j, from, to, step;

    for(i=1; i<=k; i++) {
        cin >> from >> to >> step;
        a.push_back({from,to,step});
    }

    lld l = 1, r=2000001, mid;
    lld ans;
    lld cnt;

    while (l <= r) {
        // mid번째 상자가 마지막 도토리가 들어가는 상자라고 가정한다.
        // 1 ~ mid 번째까지의 상자에 'd'개의 도토리가 들어있으면 mid에 마지막 도토리가 있게 되는 것이 맞다!
        mid = (l + r) / 2;
        cnt = Count(mid);
        
        cout << l << " " << r << " " << mid << " " << cnt << endl;
        // 도토리 갯수가 n보다 작으면 l = mid+1
        if (cnt < d) {
            l = mid + 1;
        }
        // 도토리 갯수가 n이랑 같거나 크면 r = mid-1;
        else {
            ans = mid;
            r = mid - 1;
        }
    }
    cout << ans << endl;

    return 0;
}