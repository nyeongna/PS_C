#include <bits/stdc++.h>
using namespace std;
#define endl "\n";

/*
    ��ǥ���� ���� �׸��� �����̴�.

    ������ ������ "���ΰ� ���" �� �����̹Ƿ� �׸���� Ǯ �� �ִ�.
    ���� ����� �������� ū ����� ������ ������̱� ������,
    ������ ���� ����� ������ ū ������ ǥ���� �� �ִ�.
    ����, ���� �������� ǥ���� �����ϴٸ� ū �������ε� ǥ���� �����ϴٴ� ���̱� ������
    ���� ū �������� ǥ���� �غ��� ���� ���� ���� ������ ǥ���� �ϴ� ������ ������ �ϸ� �ּ��� ���� ������ ã�� �� �ִ�.
*/


int N, K;
int coin[11];

void getInput() {
    cin >> N >> K;
    int i, j;
    for(i=0; i<N; i++) {
        cin >> coin[i];
    }
}

void Solve() {
    int i, j;
    int cnt=0;
    for(i=N-1; i>=0; i--) {
        if (K / coin[i] > 0) {
            cnt = cnt + K / coin[i];
            K = K % coin[i];
        }
        if (K==0) break;
    }
    cout << cnt << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    getInput();
    Solve();
    return 0;
}