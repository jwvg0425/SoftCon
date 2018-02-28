#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <string>
#include <bitset>
#include <map>
#include <set>
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
#define INF (2<<29)

using namespace std;

using i64 = long long int;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;

vector<bool> table;
string str;

bool isRepeat(int k)
{
    if (k > table.size())
        return false;

    if (k == 0)
        return true;

    return table[k - 1];
}

int dp[21][1000001];

//C연산 전체 k개를 쓴다고 했을 때, 그 중에 c개 써서 앞 n글자 만들기
int minOp(int k, int c, int n)
{
    if (dp[c][n] != -1)
        return dp[c][n];

    int& res = dp[c][n];
    res = INF;

    if (n == 0 && c == 0)
    {
        res = 0;
    }
    else
    {
        int next = (k << c) + n;

        //A,B연산 쓰는 경우
        if (n > 0 && next <= str.size() && str[n - 1] == str[next - 1])
            res = 1 + minOp(k, c, n - 1);

        //C연산 쓰는 경우
        if (c > 0 && isRepeat(n) && isRepeat(next))
            res = min(res, 1 + minOp(k, c - 1, n / 2));
    }

    return res;
}

int main()
{
    int n;

    cin >> n >> str;

    int ans = INF;

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

    for (int c = 0; (1 << c) + 1 <= n; c++)
    {
        if (n % ((1 << c) + 1) != 0)
            continue;

        memset(dp, -1, sizeof(dp));

        int k = n / ((1 << c) + 1);
        ans = min(ans, minOp(k, c, k));
    }

    if (ans == INF)
        printf("-1");
    else
        printf("%d", ans);

    return 0;
}