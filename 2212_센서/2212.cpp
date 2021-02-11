#include <bits/stdc++.h>
using namespace std;
#define endl "\n";

/*
    �׸��� �����̴�.
    ���� ������ �����鳢���� �Ÿ��� ���ؼ� dist �迭�� �����Ѵ�.
    Ǯ�̹� (n = 5��� ����)
    - k=1�̶�� �����غ���. ������ �����鳢���� �Ÿ��� "���" ���� ���� ���� �ȴ�.
    - k=2�̶�� �����غ���. ������ �����鳢���� �Ÿ� �� ���� �� ���� ���� �ȴ�. �ֳ��ϸ�
    ���߱��� �Ÿ��� ���� ��� �ϴ� ������ ��ġ�� ������ �� �Ÿ��� �������� ����.

    ���� �Ÿ��� ������������ �����ϰ� ������ K-1�� (1���� ���� �Ÿ����� ���ϴµ� �ʿ���)�� �����ϰ�
    0��° �Ÿ����� ~ (N-K-1)��° �Ÿ������� �����ָ� �װ��� "�ּ� �Ÿ��� ��"�� ��.

*/

int a[10001];
int dist[10001];

int N, K;
void getInput() {
    int i;
    cin >> N >> K;
    for (i = 0; i < N; i++) {
        cin >> a[i];
    }
    sort(a, a + N);

}
void Solve() {
    int i, j, ans = 0;
    if (N <= K) {
        cout << 0 << endl;
        return;
    }
    for (i = 0; i < N - 1; i++) {
        dist[i] = a[i + 1] - a[i];
    }
    sort(dist, dist + N - 1);
    for (i = 0; i < N - K; i++) {
        ans = ans + dist[i];
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