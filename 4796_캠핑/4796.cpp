#include <bits/stdc++.h>
using namespace std;
#define endl "\n";

long long int L, P, V;
void getInput() {
    long long int total = 0;
    long long int cnt = 1;
    while (1) {
        total = 0;
        cin >> L >> P >> V;
        if (L == 0 && P == 0 && V == 0) break;

        // V ���� P�� "������ �ִ� ��ŭ �������� L�� ���� ��"�� ī��Ʈ�Ѵ�
        total = total + (V / P) * L;

        // ���� �ް��ϼ� V = (V�� P�� ���� ��) * (P)
        V = V - P * (V / P);

        // V�� �� ũ�ٸ� ���信 L��ŭ �����ش�.
        if (V >= L) {
            total = total + L;
        }
        // L�� �� ũ�ٸ� ���㿡 V��ŭ�� �����ش�.
        else {
            total = total + V;
        }
        cout << "Case " << cnt << ": " << total << endl;
        cnt++;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    getInput();
    return 0;
}