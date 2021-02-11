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
        // 'mid'��° ���ڱ����� ���丮 ������ ��� ���Ѵ�.
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
        // mid��° ���ڰ� ������ ���丮�� ���� ���ڶ�� �����Ѵ�.
        // 1 ~ mid ��°������ ���ڿ� 'd'���� ���丮�� ��������� mid�� ������ ���丮�� �ְ� �Ǵ� ���� �´�!
        mid = (l + r) / 2;
        cnt = Count(mid);
        
        cout << l << " " << r << " " << mid << " " << cnt << endl;
        // ���丮 ������ n���� ������ l = mid+1
        if (cnt < d) {
            l = mid + 1;
        }
        // ���丮 ������ n�̶� ���ų� ũ�� r = mid-1;
        else {
            ans = mid;
            r = mid - 1;
        }
    }
    cout << ans << endl;

    return 0;
}