#include <bits/stdc++.h>
using namespace std;
#define endl "\n";

/*
    �׸��� �˰���
    �г�Ƽ T + 20V ���� Ʋ�� Ƚ�� V�� ������ �Ȱ����Ƿ� �����ص� �ȴ�.
    �߿��Ѱ��� T(�帥 �ð�)�̴�. ��, ���� �ɸ��� ������ ���� Ǯ������� ���߿� ���� �ɸ��� ������ Ǯ� ���Ƽ�� ũ�� �Դ´�.
    ���� ���� �ɸ��� ������ ���� Ǯ� ���߿� ���� �ɸ��� ������ Ǯ� "���Ƽ�� ���� �Դ� ��"���� �ؾ���.
*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int i, j;
    int D,V;
    pair<int,int> a[11];
    for(i=0; i<11; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a, a+11);
    int total=0;
    int Time=0;
    for(i=0; i<11; i++) {
        total = total + (a[i].first+Time) + a[i].second * 20;
        Time = Time + a[i].first;
    }
    cout << total << endl;
    return 0;
}