#include <bits/stdc++.h>
using namespace std;
#define endl "\n";

int a[100010];
long long result = 0;

long long Divide(int Start, int End) {


    //���� ���
    // a �迭�� int �̹Ƿ� a[Start]=1000,000 �̸� a[Start] * a[Start] �� ���� �� �ִ�.
    // ���� 1LL�� �����ش�. 
    if (Start == End) return 1LL * a[Start] * a[Start];

    int mid = (Start + End) / 2;

    // ���� ���� �� �ִ� �̾ƾư�, ������ ���� �� �ִ� �̾ƿͼ� ��.
    result = max(Divide(Start, mid), Divide(mid + 1, End));

    int l = mid, r = mid;
    int min_value = a[mid];
    long long total = a[mid];

    int p, q;

    while (r - l <= End - Start) {
        int p = (l > Start) ? a[l - 1] : -1;
        int q = (r < End) ? a[r + 1] : -1;

        //�������� Ȯ���ϴ� ���� �� ���ٸ�
        if (p >= q) {
            min_value = min(min_value, a[l - 1]);
            total = total + a[l - 1];
            l--;
        }
        //���������� Ȯ���ϴ� ���� �� ���ٸ�
        else {
            min_value = min(min_value, a[r + 1]);
            total = total + a[r + 1];
            r++;
        }

        result = max(result, min_value * total);
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    // input�� �ޱ�
    int n, i;
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }

    // ���� ��� �Լ� Divideȣ��
    cout << Divide(1, n) << endl;

    return 0;
}