// by jwvg0425
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);

	vector<int> pos(n + 1);
	vector<int> arr(n);
	vector<int> res(n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
		pos[arr[i]] = i;
	}

	for (int i = 0; i < n; i++)
		scanf("%d", &res[i]);

	auto rev = res;
	reverse(rev.begin(), rev.end());

	int off = n - pos[res[0]];
	int roff = off - 1;

	rotate(rev.begin(), rev.begin() + roff, rev.end());
	rotate(res.begin(), res.begin() + off, res.end());

	if (arr == res || arr == rev)
		printf("good puzzle\n");
	else
		printf("bad puzzle\n");

	return 0;
}