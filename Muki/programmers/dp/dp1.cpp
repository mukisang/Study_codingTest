#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <set>

using namespace std;

void dp(int cnt, int N, map<int, set<int>>& results)
{
	if (cnt == 1)
		results[1] = { N };
	else if (cnt > 8)
		return;
	else
	{
		set<int> tmp;
		//연산할 두 op 값 i, cnt - i // i > cnt - i
		for (int i = cnt - 1; i >= ((cnt + 1) / 2); i--)
		{
			set<int>& op1 = results[i];
			set<int>& op2 = results[cnt - i];


			for (auto& p1 : op1)
			{
				for (auto& p2 : op2)
				{
					tmp.insert(p1 + p2);
					tmp.insert(p1 * p2);
					if (p2 != 0)
						tmp.insert(p1 / p2);
					if (p1 != 0)
						tmp.insert(p2 / p1);

					tmp.insert(p1 - p2);
					tmp.insert(p2 - p1);
					int tmp2 = N;
					for (int j = 1; j < cnt; j++)    //한 문자만 나열
						tmp2 = tmp2 * 10 + N;
					tmp.insert(tmp2);

				}
			}
		}//end of for
		results[cnt] = tmp;
		tmp.clear();
	}

	dp(++cnt, N, results);
}

int solution(int N, int number) {
	map<int, set<int>> results;

	dp(1, N, results);

	for (auto m : results)
	{
		for (auto n : m.second)
		{
			if (n == number)
				return m.first;
		}
	}

	return -1;
}