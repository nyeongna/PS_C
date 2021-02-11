#include <bits/stdc++.h>
using namespace std;

// directed graph
vector<int> graph[10001];
// scc num
int SN;
// i's sn_num
int sn[10001];
// visited �� ����� ����
int dfsn[10001];
// scc������ ���� node�� ���
int finished[10001];
// dfsn�� ����� �� ���°�� Ž���� node���� ���
int cnt=0;
stack<int> Stk;
vector<vector<int> > SCC;

// cur node�� ���� ������� ��ȯ�ϴ� DFS �Լ�
int DFS(int cur) {
    // dfsn[i]�� i��° node�� ���°�� Ž���Ǿ������ĸ� ����
    dfsn[cur] = ++cnt;
    // stack�� cur(�ڽ�) �߰�.
    Stk.push(cur);

    // �ڽ��� dfsn, �ڽĵ��� �����, �ڽĵ��� dfsn �� ���� ���� ������ result�� ������Ʈ
    int result = dfsn[cur];
    for (int next=0; next < graph[cur].size(); next++) {
        int nn = graph[cur][next];
        // ���� �湮���� ���� �̿��̸�
        if (dfsn[nn]==0) {
            result = min(result, DFS(nn));
        }
        // �湮�� ������ ���� scc ������ �ȳ��� node��
        else if (finished[nn]==0) {
            result = min(result, dfsn[nn]);
        }
    }
    // �ڽ��� dfsn, �ڽĵ��� �����, �ڽĵ��� dfsn �� ���� ���� ����, ���� cur�� dfsn�� ���ٸ�
    // �� �ڽŰ� �ڽĵ��� �ö� �� �ִ� �ִ� ������ ���� �ڽ��̶��,
    if (result == dfsn[cur]) {
        vector<int> Cscc;
        // stack���� �ڽ��� ���ö����� pop
        while(1) {
            int output = Stk.top();
            Stk.pop();
            Cscc.push_back(output);
            // scc�� ����Ǿ����Ƿ� finished�� 1�� üũ
            finished[output]=1;
            // �ش� node�� sn_num�� ������Ʈ
            sn[cur]=SN;
            if (output==cur) break;
        }
        // scc ������ ���� ����
        sort(Cscc.begin(), Cscc.end());
        // scc ����
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