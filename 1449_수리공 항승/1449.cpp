#include <bits/stdc++.h>
using namespace std;
#define endl "\n";

/*
    �׸��� �˰���
    ������ �߿��ϴ�. ���� ���� ���� ��ġ�� ������������ �����ϰ�. ���ʴ�� �����Ѹ�ŭ �������� �����ٺ���
    �̰��� �� �ּ����� ������ �ȴ�.
*/
int N, L;
int a[1001];

void Solve() {
    int i, j, cnt = 0;
    int init;

    for (i = 0; i < N; i++) {
        // �������� ���̴�.(a[i] �� ������ -0.5cm���� ����)
        cnt++;

        // �������� ���� ������ (a[i]�� ������ -0.5cm���� ����)
        init = a[i];

        // "���� �� ���� ����"���� �˻縦 �ؼ� �������� ���� L�ȿ� �����ϸ� ���Խ�Ų��.
        for (j = i + 1; j < N; j++) {
            if (a[j] - init <= L - 1) {
                i++;
            }
            // �� ���� ������ ������ ���Ծȵȴٸ� break�ϰ� ���ο� �������� ���� �غ� �Ѵ�.
            else break;
        }
    }
    cout << cnt << endl;
}
void getInput() {
    cin >> N >> L;
    int i, j;
    for (i = 0; i < N; i++) {
        cin >> a[i];
    }
    // ���� �� ���� ���� ��ġ�� ������������ �����Ѵ�.
    sort(a, a + N);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    getInput();
    Solve();

    return 0;
}