#include <bits/stdc++.h>
using namespace std;
#define endl "\n";

/*
    �׸��� �����̴�.
    ��ǻ�� �����층�� �Ȱ��� �˰����̴�.
    1. ���� �ܼ�Ʈ�� ��� ���� ���¶��,
       �ܼ�Ʈ�� ���� ��� �߿��� ���� �������� ���̴� '���'�� ������ �ȴ�.
*/

int N, K;
int Order[101];
int socket[101];
int use[101];
int cnt;

void getInput() {
    cin >> N >> K;
    int i, j;
    for (i = 0; i < K; i++) {
        cin >> Order[i];
    }
}
void Print() {
    int i;
    for (i = 0; i < N; i++) {
        cout << socket[i] << " ";
    }
    cout << endl;
}
void Solve() {
    int i, j, k, idx = 0;
    int ans = 0;
    // K�� ��ŭ loop
    for (i = 0; i < K; i++) {
        // ��Ⱑ �ܼ�Ʈ�� �̹� ���� �ִٸ� continue
        if (use[Order[i]] == 1) {
            int a = 1;
        }
        // �ܼ�Ʈ�� ���ڸ��� �ִٸ�
        else if (idx < N) {
            socket[idx] = Order[i];
            use[Order[i]] = 1;
            idx++;
            //continue;
        }
        // �ܼ�Ʈ���� ��� ��ü�� �ؾ���. �� ans++
        else {
            ans++;
            int FarDist = 0;
            int device = 0;

            // �ܼ�Ʈ�� ���� �ִ� ��� ��⿡ ���ؼ� "���� �������� ���̴� ���"�� ã�ƾ���.
            for (j = 0; j < N; j++) {
                // ���� ������ ��� �� �Ⱦ��δٸ� dist = INF �� �Ǿ���.
                int dist = 2147000000;
                for (k = i + 1; k < K; k++) {
                    // ��Ⱑ �� ���δٸ� dist�� ����
                    if (socket[j] == Order[k]) {
                        dist = k;
                        break;
                    }
                }
                // ���� dist�� ���ݱ��� �߰��� �ִ� �Ÿ����� ��ٸ� FarDist�� ����
                if (dist > FarDist) {
                    FarDist = dist;
                    // �ܼ�Ʈ�� ��ü �Ǿ���� �ڸ��� "j" �̹Ƿ� ������ش�.
                    device = j;
                }
            }

            // ���� �ʰ� ����(�Ÿ��� ����) ��⸦ �̰�
            use[socket[device]] = 0;

            // ���ο� ��⸦ �ȴ´�.
            use[Order[i]] = 1;
            socket[device] = Order[i];

        }
        //Print();
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