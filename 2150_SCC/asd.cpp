#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
const int MAX = 10000;
 
// SN: SCC ����, sn[i]: i�� ���� SCC�� ��ȣ
int V, E, cnt, dfsn[MAX], SN, sn[MAX];
vector<int> adj[MAX];
bool finished[MAX]; // SCC �и��� ���� ������ true
stack<int> S;
vector<vector<int>> SCC;
 
// �ڽ��� ������� �����ϴ� DFS �Լ�
int DFS(int curr){
    dfsn[curr] = ++cnt; // dfsn ����
    S.push(curr); // ���ÿ� �ڽ��� push
 
    // �ڽ��� dfsn, �ڽĵ��� ����� dfsn �� ���� ���� ��ȣ�� result�� ����
    int result = dfsn[curr];
    for(int next: adj[curr]){
        // ���� �湮���� ���� �̿�
        if(dfsn[next] == 0) result = min(result, DFS(next));
        // �湮�� ������ ���� SCC�� ��������� ���� �̿�
        else if(!finished[next]) result = min(result, dfsn[next]);
    }
 
    // �ڽ�, �ڽ��� �ڼյ��� ���� ������ ���� ���� ������ �ڽ��� ��� SCC ����
    if(result == dfsn[curr]){
        vector<int> currSCC;
        // ���ÿ��� �ڽ��� ���� ������ pop
        while(1){
            int t = S.top();
            S.pop();
            currSCC.push_back(t);
            finished[t] = true;
            sn[t] = SN;
            if(t == curr) break;
        }
        // ����� ���� ���� ����
        sort(currSCC.begin(), currSCC.end());
        // SCC ����
        SCC.push_back(currSCC);
        SN++;
    }
    return result;
}
 
int main(){
    // �׷��� ���� �Է�
    scanf("%d %d", &V, &E);
    for(int i=0; i<E; i++){
        int A, B;
        scanf("%d %d", &A, &B);
        adj[A-1].push_back(B-1);
    }
 
    // DFS�� �ϸ� SCC ����
    for(int i=0; i<V; i++)
        if(dfsn[i] == 0) DFS(i);
    // ����� ���� SCC���� ����
    sort(SCC.begin(), SCC.end());
 
    // SCC ����
    printf("%d\n", SN);
    // �� SCC ���
    for(auto& currSCC: SCC){
        for(int curr: currSCC)
            printf("%d ", curr+1);
        puts("-1");
    }
}

