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
            �ݵ�� high�� min(a[i].to, mid)�� �ؾ��Ѵ�.
            5000 2 15
            100 1000 100
            3000 4000 20
            ��ʸ� ���� high�� mid�� �������ѹ����� 1~3905, mid=1953�϶� 19�� �����µ� 19�� ���ͼ� r�� �پ������. ������
                       high = min(to,mid)�� �� ��� 10���� ���ͼ� l�� Ŀ����.(�̰� �´� ���̴�)
            ���ʿ� 1~1953���� ���ڰ��� ä��°ɷ� ���� �ȵȴ�!! 1 ~1000 ���� ä��� 3000~4000���� ������ 5���� ä���־����!!
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
        // mid��° ���ڰ� ������ ���丮�� ���� ���ڶ�� �����Ѵ�.
        // 1 ~ mid ��°������ ���ڿ� 'd'���� ���丮�� ��������� mid�� ������ ���丮�� �ְ� �Ǵ� ���� �´�!
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