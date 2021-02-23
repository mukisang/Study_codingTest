#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

void bfs(vector<int>& v, queue<pii>& q, vector<vector<int>>& edge, vector<bool>& checkE, vector<bool>& checkN)
{
	while (!q.empty())
	{
		pii tmp = q.front();
		q.pop();
		if (checkN[tmp.first])
			continue;
		checkN[tmp.first] = true;
		// cout << tmp.first << "차례"<<endl;
		for (int i = 0; i < edge.size(); i++)
		{
			if ((edge[i][0] - 1 == tmp.first) && (!checkE[i]))
			{
				v[edge[i][1] - 1] = min(v[edge[i][1] - 1], tmp.second + 1);
				// cout << edge[i][1] - 1<< "넣기1 : "<<v[edge[i][1] - 1]<<endl;
				q.push({ edge[i][1] - 1, v[edge[i][1] - 1] });
				checkE[i] = true;
			}
			else if ((edge[i][1] - 1 == tmp.first) && (!checkE[i]))
			{
				v[edge[i][0] - 1] = min(v[edge[i][0] - 1], tmp.second + 1);
				// cout << edge[i][0] - 1<< "넣기2 : "<<v[edge[i][0] - 1]<<endl;
				q.push({ edge[i][0] - 1, v[edge[i][0] - 1] });
				checkE[i] = true;
			}
		}

	}
}

int solution(int n, vector<vector<int>> edge) {
	int answer = 0;
	vector<int> v(n);//0 번 노드부터 시작
	vector<bool> checkE(edge.size());
	vector<bool> checkN(n);
	queue<pii> q;

	q.push({ 0, 0 });
	for (int i = 0; i < n; i++)
		v[i] = 50000;
	v[0] = 0;

	bfs(v, q, edge, checkE, checkN);

	//     for(int i = 0; i < n; i ++)
	//         cout << i + 1 <<" : "<<v[i]<<endl;

	sort(v.begin(), v.end(), greater<>());
	int max = v[0];
	for (auto t : v)
	{
		// cout << t <<endl;
		if (t != max)
			break;
		answer++;
	}


	return answer;
}