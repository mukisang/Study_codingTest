#include <string>
#include <vector>
#include <algorithm>


using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = n - lost.size(), cursor1 = 0, cursor2 = 0, tmpLo = 0, tmpRe = 0;
	for (int i = 0; i < lost.size(); i++)
	{
		for (int j = 0; j < reserve.size(); j++)
		{
			if (lost[i] == reserve[j])
			{
				lost[i] == 0;
				reserve[j] == 0;
				answer++;
			}
		}
	}

	int lostSize = lost.size(), resvSize = reserve.size();
	sort(lost.begin(), lost.end());
	sort(reserve.begin(), reserve.end());

	while (lostSize > cursor1&& resvSize > cursor2)
	{
		tmpLo = lost[cursor1];//lost ÇÐ»ý
		tmpRe = reserve[cursor2];

		if (tmpRe < tmpLo - 1)
			cursor2++;
		else if (tmpRe >= tmpLo - 1 && tmpRe <= tmpLo + 1)
		{
			cursor2++;
			cursor1++;
			answer++;
		}
		else
			cursor1++;
	}

	return answer;
}