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
 
int main(){
    
}
