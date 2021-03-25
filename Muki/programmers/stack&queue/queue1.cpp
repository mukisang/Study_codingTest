#include <string>
#include <vector>
#include <queue>


using namespace std;
//�ð��� �� �Ǹ� Ʈ�� �ٸ����� ��������
void check_end_truck(int& time, int& wl, int& bl, queue<pair<int, int>>& b)
{
	pair<int, int> tmp;
	time++;
	for (int i = 0; i < b.size(); i++)
	{
		tmp = b.front();
		b.pop();
		if (time - tmp.first >= bl)//Ʈ���� ������ �ϴ� ���
			wl += tmp.second;
		else
			b.push(tmp);
	}
}

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int weightLimit = weight, time = 0;
	queue<pair<int, int>> bridge;
	while (truck_weights.size())
	{
		check_end_truck(time, weightLimit, bridge_length, bridge);
		if (truck_weights[0] <= weightLimit)//Ʈ���� �� �� �ִ� ��Ȳ
		{
			weightLimit -= truck_weights[0];
			bridge.push(make_pair(time, truck_weights[0]));
			truck_weights.erase(truck_weights.begin());
		}

	}

	if (bridge.size())
		time += bridge_length - (time - bridge.back().first);


	return time;
}