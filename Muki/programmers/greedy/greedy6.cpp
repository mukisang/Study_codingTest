#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare(vector<int>& a, vector<int>& b)
{
	if (a[1] < b[1])
		return true;
	else
		return false;
}

int solution(vector<vector<int>> routes) {
	int answer = 0, camera = -30001;
	bool flag = false;
	sort(routes.begin(), routes.end(), compare);
	for (const auto& car : routes)
	{
		if (camera < car[0])
		{
			answer++;
			camera = car[1];
		}

	}

	return answer;
}