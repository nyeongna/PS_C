#include <bits/stdc++.h>
using namespace std;
#define endl "\n";

/*
    ������׷� ����.
    - �پ��� Ǯ�̹��� ���������� ���⼭��, �������� (Divid and Conquer)�� �Ѵ�.
*/

long long int a[100001];

// [S, E] ������ ������׷����� �ִ� ���簢�� ã�� (S����, E����)
long long int Histogram(int S, int E) {

    // base case(�������)
    // ���簢�� 1���� ��, �ʺ�=1, ����=a[S]
    if (S == E) return a[S];
    // ���簢�� 0���� ��, �ʺ�=0, ����=0
    //if (S==E) return 0;

    long long int result = 0;
    int mid = (S + E) / 2;
    result = max(Histogram(S, mid), Histogram(mid + 1, E));

    // ������ ���� ����, ������ ���� �Ѵ� ������ ��
    long long int h = a[mid], l = mid, r = mid;
    while (r - l <= E - S) {
        // �������� Ȯ������ ��
        int p = l > S ? min(h, a[l - 1]) : -1;
        // ���������� Ȯ������ ��
        int q = r < E ? min(h, a[r + 1]) : -1;
        //�������� Ȯ���� ����� �� ū ���
        if (p >= q) {
            l--;
            h = p;
        }
        //���������� Ȯ���� ����� �� ū ���
        else {
            r++;
            h = q;
        }
        result = max(result, h * (r - l + 1));
    }
    return result;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);


    int n, i, j;
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cout << Histogram(1, n) << endl;

    return 0;
}