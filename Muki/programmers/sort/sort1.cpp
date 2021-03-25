#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;

	for (const auto v : commands)
	{
		vector<int> tmp(array.begin() + v[0] - 1, array.begin() + v[1]);
		sort(tmp.begin(), tmp.end());
		answer.push_back(tmp[v[2] - 1]);
	}

	return answer;
}