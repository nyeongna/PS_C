#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000000

int n, m, a[100001];

int Count(int size) {
    int cnt=1;
    int i, sum=0;

    for(i=1; i<=n; i++) {
        if (sum+a[i] > size) {
            cnt++;
            sum=a[i];
        }
        else sum = sum + a[i];
    }
    //cout << cnt << " ";
    return cnt;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n;
    cin >> m;
    int i, j, sum=0, max_length=-1;
    for(i=1; i<=n; i++) {
        cin >> a[i];
        sum = sum + a[i];
        max_length = max(max_length, a[i]);
    }

    // l �̸� ���� �Ҹ���, r�̸� ���� ����
    int l = 1, r = sum, mid;
    int ans;

    // l �� �Ҹ��� �� ���� ũ��, r�� ���� �� ���� ���� ������ Ǯ �� �ִ�.
    // ������ l = 1 �ε� r = sum = 2���� ���°�� �ٷ� while loop�� Ǯ���� ��찡 �ִ�.
    // �� ���� m�� ��ü �뷡�� ���̰� ���� �� �ε� (���� ���, 3 3 , 1 1 1) �̷� ��츸 ���� ó���Ͽ� 1 ����ϸ� �ȴ�.
    // �� r = 1 �� �� �� �ִ� ��Ȳ�� (l+1 <r)������ �ȸ�������Ƿ� �� Ư���� ��Ȳ�� ó���ϸ� �ȴ�.
    // ������ ���� (l + 1 < r) �� �����Ѵ�.
    if (m==sum) {
        cout << m/sum << endl;
        return 0;
    }
    while(l +1 < r) {
        mid = (l+r) / 2;       
        if (Count(mid) <= m && max_length <= mid) {
            r = mid;
        }
        else {
            l = mid;
        }
    }

    cout << r << endl;


    return 0;
}