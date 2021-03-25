//�Ϻη� bfs�� �����Ϸ��� ǰ
//��Ʈ��ũ
#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
	int answer = 0, cursor = 0, visitCnt = 0;
	bool visited[200] = { false };
	queue<int> q;
	while (visitCnt < n)
	{
		for (int i = 0; i < n; i++)
		{
			if (!visited[i])
			{
				q.push(i);
				visitCnt++;
				visited[i] = true;
				break;
			}
		}

		while (!q.empty())
		{
			cursor = q.front();
			q.pop();
			for (int i = 0; i < n; i++)
			{
				if (!visited[i] && computers[cursor][i] == 1)//�Ȱ��� + ����Ǿ� ����
				{
					q.push(i);
					visited[i] = true;
					visitCnt++;
				}
			}
		}
		answer++;
	}


	return answer;
}