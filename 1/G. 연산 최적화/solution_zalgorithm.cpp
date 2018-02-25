// by jwvg0425
#include <stdio.h>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <iostream>

using namespace std;

using i64 = long long int;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;

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

    vector<int> z;
    z.resize(str.size(), 0);
    int l = 0, r = 0;

    for (int i = 1; i < n; i++)
    {
        if (i > r)
        {
            l = r = i;
            while (r < n && str[r - l] == str[r])
                r++;
            
            z[i] = r - l;
            r--;
        }
        else
        {
            int k = i - l;
            if (z[k] < r - i + 1)
            {
                z[i] = z[k];
            }
            else
            {
                l = i;
                while (r < n && str[r - l] == str[r])
                    r++;

                z[i] = r - l;
                r--;
            }
        }
    }

    for (int i = 1; i < n; i += 2)
    {
        int half = (i + 1) / 2;

        table[i] = z[half] >= half;
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