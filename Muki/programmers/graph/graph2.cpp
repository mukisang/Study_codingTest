#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<vector<int>> results) {
	int answer = 0;
	vector<vector<bool>> v(n, vector<bool>(n, false));

	for (auto result : results)
	{
		v[result[0] - 1][result[1] - 1] = true;
	}
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{

				if (v[i][k] && v[k][j])
					v[i][j] = true;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		int cnt = 0;
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				continue;
			if (v[i][j] || v[j][i])
				cnt++;
		}
		if (cnt == n - 1)
			answer++;
	}
	return answer;
}