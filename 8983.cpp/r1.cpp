#include <bits/stdc++.h>
using namespace std;

/*
    ������ �˰���. 
    1. naive�� Ž�� O(n*m).
    2. ������ ��ġ�� �����ϰ� O(n*logm) ���� ���� �� �ִ�.
    3. ������ ��ġ 1���� �̺�Ž�� 1���ϸ� �Ǹ� ������ �������� ���������� �� �� �ִ�!
*/


int m, n, l;
int shot[100001];

void getInput() {
    cin >> m >> n >> l;
    int i, j;
    for(i=0; i<m; i++) {
        cin >> shot[i];
    }
    // �̺�Ž���� ������ "����� ��ġ"�� ���ĵǾ� �־����.
    sort(shot, shot+m);
}
void Solve() {
    int i, j, cnt=0;
    int x, y;
    for(i=0; i<n; i++) {
        // ������ ��ǥ(x,y)�� �ް�
        cin >> x >> y;
        // ������ ���̰� �����Ÿ� "l"���� ������ ��Ⱑ �ƿ� �Ұ���!
        if (y - l >0) continue;
        // �������� ���� �������� ��밡 �ִٸ�
        int lower = x - abs(y-l);
        // �������� ������ �������� ��밡 �ִٸ�
        int upper = x + abs(y-l);
        int start = 0, end = m-1, mid;
        // �̺�Ž�� ����
        while(start <= end) {
            mid = (start + end) / 2;
            // ����� ��ġ �� �ϳ��� "���� ���� ���� or ������" ���� ���� ���ԵǾ� �ִٸ� cnt++
            if (shot[mid]>= lower && shot[mid] <= upper) {
                cnt++;
                break;
            }
            else if (shot[mid] > x) {
                end = mid-1;
            }
            else if (shot[mid] <= x) {
                start = mid+1;
            }
        }
    }
    cout << cnt <<endl;
}
int main() {
    getInput();
    Solve();
    return 0;
}