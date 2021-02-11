#include <bits/stdc++.h>
using namespace std;

/*
    스위핑 알고리즘. 
    1. naive한 탐색 O(n*m).
    2. 동물의 위치를 고정하고 O(n*logm) 으로 구할 수 있다.
    3. 동물의 위치 1개당 이분탐색 1번하면 되면 동물이 잡히는지 안잡히는지 알 수 있다!
*/


int m, n, l;
int shot[100001];

void getInput() {
    cin >> m >> n >> l;
    int i, j;
    for(i=0; i<m; i++) {
        cin >> shot[i];
    }
    // 이분탐색을 쓰려면 "사대의 위치"가 정렬되어 있어야함.
    sort(shot, shot+m);
}
void Solve() {
    int i, j, cnt=0;
    int x, y;
    for(i=0; i<n; i++) {
        // 동물의 좌표(x,y)를 받고
        cin >> x >> y;
        // 동물의 높이가 사정거리 "l"보다 높으면 잡기가 아예 불가능!
        if (y - l >0) continue;
        // 동물기준 왼쪽 범위내에 사대가 있다면
        int lower = x - abs(y-l);
        // 동물기준 오른쪽 범위내에 사대가 있다면
        int upper = x + abs(y-l);
        int start = 0, end = m-1, mid;
        // 이분탐색 시작
        while(start <= end) {
            mid = (start + end) / 2;
            // 사대의 위치 중 하나가 "동물 기준 왼쪽 or 오른쪽" 기준 내에 포함되어 있다면 cnt++
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