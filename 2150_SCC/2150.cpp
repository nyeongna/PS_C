#include <bits/stdc++.h>
using namespace std;

// directed graph
vector<int> graph[10001];
// scc num
int SN;
// i's sn_num
int sn[10001];
// visited 와 비슷한 역할
int dfsn[10001];
// scc추출이 끝난 node를 기록
int finished[10001];
// dfsn을 기록할 때 몇번째로 탐색된 node인지 기록
int cnt=0;
stack<int> Stk;
vector<vector<int> > SCC;

// cur node에 대한 결과값을 반환하는 DFS 함수
int DFS(int cur) {
    // dfsn[i]는 i번째 node가 몇번째로 탐색되어졌느냐를 뜻함
    dfsn[cur] = ++cnt;
    // stack에 cur(자신) 추가.
    Stk.push(cur);

    // 자신의 dfsn, 자식들의 결과값, 자식들의 dfsn 중 가장 작은 값으로 result를 업데이트
    int result = dfsn[cur];
    for (int next=0; next < graph[cur].size(); next++) {
        int nn = graph[cur][next];
        // 아직 방문하지 않은 이웃이면
        if (dfsn[nn]==0) {
            result = min(result, DFS(nn));
        }
        // 방문은 했지만 아직 scc 추출이 안끝난 node면
        else if (finished[nn]==0) {
            result = min(result, dfsn[nn]);
        }
    }
    // 자신의 dfsn, 자식들의 결과밧, 자식들의 dfsn 중 가장 작은 값이, 현재 cur의 dfsn과 같다면
    // 즉 자신과 자식들이 올라갈 수 있는 최대 정점이 현재 자신이라면,
    if (result == dfsn[cur]) {
        vector<int> Cscc;
        // stack에서 자신이 나올때까지 pop
        while(1) {
            int output = Stk.top();
            Stk.pop();
            Cscc.push_back(output);
            // scc로 추출되었으므로 finished를 1로 체크
            finished[output]=1;
            // 해당 node의 sn_num를 업데이트
            sn[cur]=SN;
            if (output==cur) break;
        }
        // scc 내에서 원소 정렬
        sort(Cscc.begin(), Cscc.end());
        // scc 추출
        SCC.push_back(Cscc);
        SN++;
    }

    return result;
}
int main() {
    int v, e;
    cin >> v >> e;
    int i, j, n;
    int from, to;

    for(i=0; i < e; i++) {
        cin >> from >> to;
        graph[from].push_back(to);
    }

    for (i=1; i <= v; i++) {
        if (dfsn[i]==0) {
            DFS(i);
        }
    }
    sort(SCC.begin(), SCC.end());
    cout << SCC.size() << endl;
    for(i=0; i < SCC.size(); i++) {
        for(j=0; j< SCC[i].size(); j++) {
            cout << SCC[i][j] << " ";
        }
        cout << -1 << endl;
    }

}