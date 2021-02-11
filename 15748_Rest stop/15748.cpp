#include <bits/stdc++.h>
using namespace std;
#define endl "\n";

/*
    int ���� �� �ʰ��� ��������.
        int a = 2147000000;
        int b = 2147000000;
        long long int a = b + c;
    �� �ùٸ� ���� �ƴϴ�. (b+c)�� �̹� -9877232�� �Ǿ��ִ�.
    �ٸ��� �Ϸ���
        long long int a = 1LL*b+c; �̷������� �̸� lld�� ��������Ѵ�.
*/

int L, N, F, B;

struct Rest {
    int dist, point;
    bool operator<(const Rest& b) const {
        if (point == b.point) return dist > b.dist;
        return point > b.point;
    }
};

vector<Rest> a;

void getInput() {
    cin >> L >> N >> F >> B;
    int i, j, dist, point;

    for (i = 0; i < N; i++) {
        cin >> dist >> point;
        a.push_back({ dist, point });
    }
    sort(a.begin(), a.end());
}

void Solve() {
    int i, j;
    long long int ans = 0;
    int cur_dist = 0;
    for (i = 0; i < N;i++) {
        int dist = a[i].dist;
        int point = a[i].point;

        if (dist < cur_dist) continue;
        long long int B_time = (1LL * dist - cur_dist) * B;
        long long int F_time = (1LL * dist - cur_dist) * F;
        cur_dist = dist;

        ans = ans + (point * (F_time - B_time));
    }
    cout << ans << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    getInput();
    Solve();
    return 0;
}