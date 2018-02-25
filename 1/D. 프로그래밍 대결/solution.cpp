//by onjo0127
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int A[333], H[333], L[333];

const int SRC = 601, SNK = 602;
int capa[666][666], cost[666][666], flow[666][666];
vector<int> adj[666];

void add_edge(int u, int v, int cp, int cs)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
    capa[u][v] = cp;
    cost[u][v] = -cs;
    cost[v][u] = cs;
}

int MCMF()
{
    int ret = 0;
    while(1) {
        vector<int> par(666, -1), dst(666, 1e9);
        vector<bool> chk(666, 0);
        queue<int> que;
        que.push(SRC);
        dst[SRC] = 0;
        par[SRC] = SRC;
        chk[SRC] = 1;

        while(!que.empty()) {
            int cur = que.front(); que.pop();
            chk[cur] = 0;
            for(int i=0; i<adj[cur].size(); i++) {
                int there = adj[cur][i], cst = cost[cur][there];
                if(capa[cur][there] - flow[cur][there] > 0 && dst[cur] + cst < dst[there]) {
                    dst[there] = dst[cur] + cst;
                    par[there] = cur;
                    if(!chk[there]) {
                        que.push(there);
                        chk[there] = 1;
                    }
                }
            }
        }
        if(par[SNK] == -1) break;

        int mn = 1e9;
        for(int i=SNK; i!=SRC; i=par[i]) mn = min(mn, capa[par[i]][i] - flow[par[i]][i]);
        for(int i=SNK; i!=SRC; i=par[i]) {
            ret += mn * cost[par[i]][i];
            flow[par[i]][i] += mn;
            flow[i][par[i]] -= mn;
        }
    }
    return ret;
}

int main()
{
    int N;
    scanf("%d",&N);
    for(int i=0; i<N; i++) scanf("%d",&A[i]);
    for(int i=0; i<N; i++) scanf("%d",&H[i]);
    for(int i=0; i<N; i++) scanf("%d",&L[i]);

    int mx = 0;
    for(int i=0; i<N; i++) {
        add_edge(SRC, i, L[i] - 1, -H[i]);
        if(A[mx] < A[i]) mx = i;
    }
    ++capa[SRC][mx];

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(A[i] > A[j]) {
                add_edge(i, N+j, 1, A[i] ^ A[j]);
            }
        }
    }

    for(int i=0; i<N; i++) {
        add_edge(N+i, SNK, 1, -H[i]);
    }

    printf("%d", -MCMF());
    return 0;
}
