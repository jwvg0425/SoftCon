// by onjo0127
#include <stdio.h>

const int MOD = 1e9 + 7;
int p[1009];

int root(int x) {
    if(p[x] == x) return x;
    return p[x] = root(p[x]);
}

void merg(int u, int v) {
    u = root(u), v = root(v);
    if(u != v) p[u] = v;
}

int main() {
    int N, M;
    scanf("%d%d",&N,&M);
    for(int i=1; i<=N; i++) p[i] = i;
    while(M--) {
        int l, r, k;
        scanf("%d%d%d",&l,&r,&k);
        for(int i=l; i<=r-k; i++) merg(i, i+k);
    }
    int ans = 1;
    for(int i=1; i<=N; i++) if(root(i) == i) ans = 2 * ans % MOD;
    printf("%d", ans);
    return 0;
}
