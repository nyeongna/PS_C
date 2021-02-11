#include <bits/stdc++.h>
using namespace std;
#define endl "\n";

/*
    그리디 문제이다.
    먼저 인접한 센서들끼리의 거리를 구해서 dist 배열에 저장한다.
    풀이법 (n = 5라고 가정)
    - k=1이라고 가정해보자. 인접한 센서들끼리의 거리를 "모두" 더한 것이 답이 된다.
    - k=2이라고 가정해보자. 인접한 센서들끼리의 거리 중 가장 긴 것은 빼도 된다. 왜냐하면
    집중국을 거리를 가장 길게 하는 센서의 위치에 넣으면 그 거리는 없어지기 때문.

    따라서 거리를 오름차순으로 정렬하고 마지막 K-1개 (1개는 남은 거리들을 더하는데 필요함)는 무시하고
    0번째 거리부터 ~ (N-K-1)번째 거리까지만 더해주면 그것이 "최소 거리의 합"이 됨.

*/

int a[10001];
int dist[10001];

int N, K;
void getInput() {
    int i;
    cin >> N >> K;
    for (i = 0; i < N; i++) {
        cin >> a[i];
    }
    sort(a, a + N);

}
void Solve() {
    int i, j, ans = 0;
    if (N <= K) {
        cout << 0 << endl;
        return;
    }
    for (i = 0; i < N - 1; i++) {
        dist[i] = a[i + 1] - a[i];
    }
    sort(dist, dist + N - 1);
    for (i = 0; i < N - K; i++) {
        ans = ans + dist[i];
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