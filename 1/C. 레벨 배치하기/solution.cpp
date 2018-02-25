// by jwvg0425
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#define MOD 1000000007

using namespace std;

using i64 = long long int;
using ii = pair<int, int>;

int main()
{
    int n;
    scanf("%d", &n);

    //(Si, Ki)
    vector<ii> level(n);

    for (int i = 0; i < n; i++)
        scanf("%d", &level[i].first);

    for (int i = 0; i < n; i++)
        scanf("%d", &level[i].second);

    sort(level.begin(), level.end());

    if (level[0].first != level[0].second)
    {
        printf("0\n");
        return 0;
    }

    i64 ans = 1;
    int end = 0;

    map<int, int> sum;

    for (int i = 1; i < n; i++)
    {
        if (level[end].first != level[i].first)
        {
            for (int j = end; j < i; j++)
                sum[level[j].second]++;

            end = i;
        }

        ans = (ans * sum[level[i].second - level[i].first]) % MOD;
    }

    printf("%lld\n", ans);

    return 0;
}