#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000000

int n;
int a[10001];
int m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n;
    int i, j, max_m = -1;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
        max_m = max(max_m, a[i]);
    }
    cin >> m;

    int l = 0;
    int r = max_m + 1;
    int mid;
    while (l + 1 < r) {
        mid = (l + r) / 2;
        long long sum = 0;
        for (i = 1; i <= n; i++) {
            if (a[i] >= mid) {
                sum = sum + mid;
            }
            else {
                sum = sum + a[i];
            }
        }
        // mid�� m���� �۾ƾ���.
        // �ֳ��ϸ� mid�� m���� Ŀ������ �װͶ��� �Ҹ����ϴ� ���̱� ����
        // l �����ϴ� �� �� ���� ū ��, r �Ҹ����ϴ� �� �� ���� ����.
        if (mid <= m && sum <= m) {
            l = mid;
        }
        else {
            r = mid;
        }
    }

    cout << l << endl;


    return 0;
}