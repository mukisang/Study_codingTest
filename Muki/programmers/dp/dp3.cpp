#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
	int answer = 0;
	int water = -100000;

	int roads[n][m];
	//√ ±‚»≠
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			roads[i][j] = 1;
	}
	for (const auto p : puddles)//π∞ «•Ω√
	{

		if (p[1] == 1) //1«‡
		{
			for (int j = p[0] - 1; j < m; j++)
				roads[0][j] = water;
		}
		else if (p[0] == 1) //1ø≠
		{
			//cout << "p[0] : "<<p[0]<<" p[1]: "<<p[1]<<endl;
			for (int i = p[1] - 1; i < n; i++)
				roads[i][0] = water;
		}
		else
			roads[p[1] - 1][p[0] - 1] = water;

	}

	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			//øıµ¢¿Ã ¡÷∫Ø +≥™ øıµ¢¿ÃX
			if ((roads[i - 1][j] == water || roads[i][j - 1] == water) && roads[i][j] != water)
			{
				roads[i][j] = max(roads[i - 1][j], roads[i][j - 1]);
				if (roads[i - 1][j] == water && roads[i][j - 1] == water)//µ— ¥Ÿ øıµ¢¿Ã
					roads[i][j] = water;
			}
			else if (roads[i][j] == water)
				continue;
			else
				roads[i][j] = (roads[i - 1][j] + roads[i][j - 1]) % 1000000007;
		}
	}

	answer = roads[n - 1][m - 1];

	if (roads[n - 1][m - 1] == water)
		answer = 0 % 1000000007;


	return answer;
}