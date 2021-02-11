#include <bits/stdc++.h>
using namespace std;
#define endl "\n";

/*
    �׸��� ����.
    �׸��� ������ ���̵�� ������ ������, ��� �������� Sort�ϴ� ���� "����"

    "ȸ�ǽ�"�� ����� �� �ִ� "ȸ���� �ִ� ����"�� ã�� �����̴�.
    -��, ������ �ð��� �������� �������� SORT �ϰ� ���ʴ�� �����غ���.
*/


pair<int, int> a[100003];

bool Comp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int N;
    cin >> N;
    int i, j;
    for (i = 1; i <= N; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a + 1, a + 1 + N, Comp);

    int cnt = 0;
    int Time = 0;

    for (i = 1; i <= N; i++) {
        if (a[i].first >= Time) {
            Time = a[i].second;
            cnt++;
        }
    }
    cout << cnt << endl;

    return 0;
}