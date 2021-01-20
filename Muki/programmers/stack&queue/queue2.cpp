//시간이 없어서 좀 대충 짬 -> 추후에 다시 짤 예정
#include <string>
#include <vector>
#include <queue>
#include <utility>


using namespace std;

int solution(vector<int> priorities, int location) {
	int result[priorities.size()];
	int cnt = 0;
	pair<int, int> tmp;
	vector<pair<int, int>> q;
	bool flag = false;
	for (int i = 0; i < priorities.size(); i++)
		q.push_back(make_pair(i, priorities[i]));
	while (q.size())
	{
		tmp = q.front();
		for (int i = 1; i < q.size(); i++)
		{
			if (q[i].second > tmp.second)//뒤가 더 크다.
			{
				flag = true;
				break;
			}
		}
		if (flag) {
			q.erase(q.begin());
			q.push_back(tmp);
			flag = false;
		}
		else {
			q.erase(q.begin());
			result[tmp.first] = ++cnt;
		}
	}

	return result[location];
}