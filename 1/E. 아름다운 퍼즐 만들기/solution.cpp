// by jwvg0425
#include <stdio.h>
#include <algorithm>
#define MOD 1000000007

using namespace std;

using i64 = long long int;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;

int values[4][11][11];

// (maximum, count)
ii table[2][1 << 21];

int up(int state, int m)
{
    return (state >> (2 * (m - 1))) & 3;
}

int left(int state, int m)
{
    return state & 3;
}

int update(int state, int added, int m)
{
    return ((state << 2) + added) & ((1 << 2 * m) - 1);
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    for (int c = 0; c < 4; c++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                scanf("%d", &values[c][i][j]);

    table[1][0].second = 1;

    int now = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int state = 0; state < (1 << (2 * m)); state++)
            {
                table[now % 2][state] = ii(0, 0);
            }

            for (int state = 0; state < (1 << (2 * m)); state++)
            {
                int upColor = -1;
                int leftColor = -1;

                if (i > 0)
                    upColor = up(state, m);

                if (j > 0)
                    leftColor = left(state, m);

                ii prev = table[(now + 1) % 2][state];

                for (int color = 0; color < 4; color++)
                {
                    if (color == leftColor || color == upColor)
                        continue;

                    int val = values[color][i][j] + prev.first;
                    int nowState = update(state, color, m);

                    if (val > table[now % 2][nowState].first)
                    {
                        table[now % 2][nowState].first = val;
                        table[now % 2][nowState].second = prev.second;
                    }
                    else if (val == table[now % 2][nowState].first)
                    {
                        table[now % 2][nowState].second += prev.second;
                    }

                    table[now % 2][nowState].second %= MOD;
                }
            }

            now = (now + 1) % 2;
        }
    }

    int maxVal = 0;
    int maxCount = 0;

    now = (now + 1) % 2;

    for (int state = 0; state < (1 << (2 * m)); state++)
        maxVal = max(maxVal, table[now][state].first);

    for (int state = 0; state < (1 << (2 * m)); state++)
        if (table[now][state].first == maxVal)
            maxCount = (maxCount + table[now][state].second) % MOD;

    printf("%d %d", maxVal, maxCount);

    return 0;
}