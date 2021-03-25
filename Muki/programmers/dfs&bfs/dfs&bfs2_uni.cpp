//네트워크
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int root[200];
int find(int x) {
	if (root[x] == x)
		return x;
	else
		return find(root[x]);
}

void uni(int x, int y) {
	x = find(x);
	y = find(y);

	root[y] = x;
}

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;

	for (int i = 0; i < 200; i++)
		root[i] = i;

	for (int i = 0; i < computers.size(); i++)
	{
		for (int j = 0; j < computers[i].size(); j++)
		{
			if (computers[i][j])
			{
				uni(i, j);
			}
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		if (find(i) == i)
			answer++;
	}

	return answer;
}