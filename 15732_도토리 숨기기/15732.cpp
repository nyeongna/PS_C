#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000000
#define lld long long int

struct Pattern {
    lld from, to, step;
};
vector<Pattern> a;
lld n, k, d;


lld Count(lld mid) {
    lld i, j;
    lld cnt = 0;
    for (i = 0; i < a.size(); i++) {
        /*
            반드시 high는 min(a[i].to, mid)를 해야한다.
            5000 2 15
            100 1000 100
            3000 4000 20
            사례를 보면 high를 mid로 고정시켜버리면 1~3905, mid=1953일때 19로 나오는데 19로 나와서 r이 줄어버린다. 하지만
                       high = min(to,mid)로 할 경우 10으로 나와서 l이 커진다.(이게 맞는 것이다)
            애초에 1~1953까지 상자갯수 채우는걸로 보면 안된다!! 1 ~1000 까지 채우고 3000~4000에서 마지막 5개를 채워넣어야함!!
        */

        lld high = min(a[i].to, mid);
        if (high >= a[i].from) {
            cnt += (high - a[i].from) / a[i].step + 1;
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n >> k >> d;
    lld i, j, from, to, step;

    for (i = 1; i <= k; i++) {
        cin >> from >> to >> step;
        a.push_back({ from,to,step });
    }

    lld l = 1, r = 2000001, mid;
    lld ans;
    lld cnt;

    while (l <= r) {
        // mid번째 상자가 마지막 도토리가 들어가는 상자라고 가정한다.
        // 1 ~ mid 번째까지의 상자에 'd'개의 도토리가 들어있으면 mid에 마지막 도토리가 있게 되는 것이 맞다!
        mid = (l + r) / 2;
        cnt = Count(mid);
        cout << l << " " << r << " " << mid << " " << cnt << endl;
        if (cnt < d) {
            l = mid + 1;
        }
        else {
            ans = mid;
            r = mid - 1;
        }
    }
    cout << ans << endl;

    return 0;
}