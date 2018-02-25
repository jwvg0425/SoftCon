#include <stdio.h>
#include <vector>
#include <queue>
#include <iostream>
#include <string>
#include <bitset>
#include <map>
#include <set>
#include <tuple>
#include <stack>
#include <string.h>
#include <time.h>
#include <algorithm>

using namespace std;

using i64 = long long int;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;

i64 hash1[2000002];
i64 hash2[2000002];
i64 pw1[2000002], pw2[2000002];
i64 mod1 = 1e9 + 7;
i64 mod2 = 1e9 + 9;
i64 base = 256;

i64 getHash(int pos, int len, i64 hash[], i64 mod, i64 pw[])
{
    i64 r = hash[pos + len - 1];
    if (pos == 0)
        return r;

    i64 l = (hash[pos - 1] * pw[len]) % mod;
    i64 h = (r - l + 100000 * mod) % mod;

    return h;
}

void fillHash(const string& s, i64 hash[], i64 mod, i64 pw[])
{
    hash[0] = s[0];
    pw[0] = 1;
    for (int i = 1; i < s.length(); i++)
    {
        pw[i] = (pw[i - 1] * base) % mod;
    }

    for (int i = 1; i < s.length(); i++)
    {
        hash[i] = (hash[i - 1] * base + s[i]) % mod;
    }
}

vector<bool> table;

bool isRepeat(int k)
{
    if (k == 0)
        return true;

    return table[k - 1];
}

int main()
{
    int n;
    string str;

    cin >> n >> str;

    int ans = -1;

    table.resize(n + 1);

    fillHash(str, hash1, mod1, pw1);
    fillHash(str, hash2, mod2, pw2);

    for (int i = 1; i < n; i += 2)
    {
        int half = (i + 1) / 2;
        i64 p1 = getHash(0, half, hash1, mod1, pw1);
        i64 p2 = getHash(0, half, hash2, mod2, pw2);
        i64 p3 = getHash(half, half, hash1, mod1, pw1);
        i64 p4 = getHash(half, half, hash2, mod2, pw2);

        table[i] = (p1 == p3 && p2 == p4);
    }

    for (int c = 0, two = 1; two + 1 <= n; c++, two *= 2)
    {
        if (n % (two + 1) != 0)
            continue;

        int k = n / (two + 1);

        queue<ii> q;
        map<ii, int> s;

        q.emplace(0, k);
        s[q.front()] = 0;

        while (!q.empty())
        {
            auto now = q.front();
            int nk, nn;
            int dist = s[now];

            tie(nk, nn) = now;
            q.pop();

            if (nk == k && nn == n)
            {
                if (ans == -1 || dist < ans)
                    ans = dist;

                break;
            }

            if (nk + 1 <= k && nn + 1 <= n &&
                str[nk] == str[nn] &&
                s.find({ nk + 1, nn + 1 }) == s.end())
            {
                s[{nk + 1, nn + 1}] = dist + 1;
                q.emplace(nk + 1, nn + 1);
            }

            if (nk * 2 <= k && nn * 2 <= n && isRepeat(nk * 2) && isRepeat(nn * 2) &&
                s.find({ nk * 2, nn * 2 }) == s.end())
            {
                s[{nk * 2, nn * 2}] = dist + 1;
                q.emplace(nk * 2, nn * 2);
            }
        }
    }

    printf("%d", ans);

    return 0;
}