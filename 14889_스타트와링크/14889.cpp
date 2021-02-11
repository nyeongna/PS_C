#include <bits/stdc++.h>
using namespace std;

int n;
int graph[30][30];
int rec[30];
int rec_link[30];

int p_rec[30];
int p_visit[30];

int start=0;
int link=0;

int visit_start[30];
int c =0;

int p2_rec[30];
int p2_visit[30];

int ans = 2147000000;

void DFS_p(int level) {
    int i;
    if (level == 2) {
        start = start + graph[p_rec[0]][p_rec[1]]; 
    }
    else {
        for(i=0; i<n/2; i++) {
            if (p_visit[i]==0) {
                p_visit[i] = 1;
                p_rec[level] = rec[i];
                DFS_p(level+1);
                p_visit[i] = 0;
            }
        }
    }
}

void DFS_p2(int level) {
    int i;
    if (level == 2) {
        link = link + graph[p2_rec[0]][p2_rec[1]]; 
    }
    else {
        for(i=0; i<n/2; i++) {
            if (p2_visit[i]==0) {
                p2_visit[i] = 1;
                p2_rec[level] = rec_link[i];
                DFS_p2(level+1);
                p2_visit[i] = 0;
            }
        }
    }
}

void DFS(int s, int level) {
    int i , j;
    if (level==n/2) {
        // for(i=0; i<n/2; i++) {
        //     cout << rec[i] << " ";
        // }

        for(i=0; i<=26; i++) {
            visit_start[i]=0;
        }

        for(i=0; i<n/2; i++) {
            visit_start[rec[i]] = 1;
        }
        c=0;
        for(i=1; i<=n; i++) {
            if (visit_start[i]==0) {
                rec_link[c++] = i;
            }
        }

        //cout << endl;
        start=0;
        link =0;
        DFS_p(0);
        DFS_p2(0);
        // cout << "start: " << start << endl;
        // cout << "link: " << link << endl;
        int sub = abs(start-link);
        ans = min(ans, sub);
    }
    else {
        for(i=s; i<n; i++) {
            rec[level] = i+1;
            DFS(i+1, level+1);
        }
    }
}

int main()
{
    cin >> n;
    int i, j;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            cin >> graph[i][j];
        }
    }
    DFS(0, 0);

    cout << ans <<endl;
    return 0;
}