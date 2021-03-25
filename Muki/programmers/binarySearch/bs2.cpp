#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
using ll = long long;

int solution(int distance, vector<int> rocks, int n) {
	int answer = 0, tmp, delRockCnt;
	int l = 1, r = distance;
	int mid = 0;
	sort(rocks.begin(), rocks.end());
	while (l <= r)
	{
		delRockCnt = 0;
		tmp = 0;
		mid = (l + r) / 2;
		for (auto rock : rocks)
		{
			if (mid > rock - tmp)
				delRockCnt++;
			else
				tmp = rock;
		}
		if (mid > distance - tmp)
			delRockCnt++;

		if (delRockCnt > n)
			r = mid - 1;
		else
		{
			l = mid + 1;
			answer = max(answer, mid);
		}
	}
	return answer;
}