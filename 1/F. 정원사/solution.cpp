// by onjo0127
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
using pli = pair<ll, int>;

struct info {
    int type, ti, x, y;
    //  1     ti  l  r
    //  2     ti  id val
};

const ll INF = 1LL * 1e18;

int N, M;
vector<pli> query[100009], upd[100009];
vector<info> stk;

ll seg[2222222];
int fen[100009];

void Update(int i, int s, int e, long long h, int ti) {
    if(s == e) {
        seg[i] = h;
        return;
    }
    int m = s+e >> 1;
    if(ti <= m) Update(i << 1, s, m, h, ti);
    else Update(i << 1 | 1, m+1, e, h, ti);
    seg[i] = min(seg[i << 1], seg[i << 1 | 1]);
}

int Find(int i, int s, int e, long long h, int ti) {
    if(seg[i] >= h || e <= ti) return -1;
    if(s == e) return s;
    int m = s+e >> 1;
    int ret = Find(i << 1, s, m, h, ti);
    if(ret != -1) return ret;
    return Find(i << 1 | 1, m + 1, e, h, ti);
}

void add(int x, int val) {
    for(int i=x; i<=N; i+=(i&-i)) fen[i] += val;
}

int sum(int x) {
    int ret = 0;
    for(int i=x; i>0; i-=(i&-i)) ret += fen[i];
    return ret;
}

int main() {
    int top=1; ll k;
    scanf("%d %d %lld",&N,&M,&k);
    while(M--) {
        int ty; scanf("%d",&ty);
        if(ty == 1) {
            int t,x,h; scanf("%d%d%d",&t,&x,&h);
            query[x].push_back({-k*t + h, top});
            ++top;
        }
        if(ty == 2) {
            int t,l,r,h; scanf("%d%d%d%d",&t,&l,&r,&h);
            upd[l].push_back({-k*t + h, top});
            upd[r+1].push_back({INF, top});
            ++top;
        }
        if(ty == 3) {
            int t,l,r; scanf("%d%d%d",&t,&l,&r);
            stk.push_back({1, top, l, r});
            ++top;
        }
    }

    for(int i=1; i<=2100000; i++) seg[i] = INF;
    Update(1, 1, top, -INF, top);
    for(int i=1; i<=N; i++) {
        for(int j=0; j<upd[i].size(); j++) {
            Update(1, 1, top, upd[i][j].first, upd[i][j].second);
        }
        for(int j=0; j<query[i].size(); j++) {
            stk.push_back({2, query[i][j].second,                                     i, +1});
            stk.push_back({2, Find(1, 1, top, query[i][j].first, query[i][j].second), i, -1});
        }
    }

    sort(stk.begin(), stk.end(), [&](info a, info b) {
        return a.ti < b.ti;
    });
    for(int i=0; i<stk.size(); i++) {
        if(stk[i].type == 1) {
            printf("%d\n", sum(stk[i].y) - sum(stk[i].x - 1));
        }
        if(stk[i].type == 2) {
            add(stk[i].x, stk[i].y);
        }
    }
    return 0;
}
