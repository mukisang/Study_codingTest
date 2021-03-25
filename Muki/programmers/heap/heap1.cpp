#include <string>
#include <vector>
#include <queue>


using namespace std;

int solution(vector<int> scoville, int K) {
	int itr = 0, mix1, mix2;
	priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());


	while (!pq.empty())
	{
		if (pq.top() >= K)//���ں� ���� �� ����
			break;
		else//���ں� ������ ���� ���
		{
			mix1 = pq.top();
			pq.pop();
			if (pq.empty())//��� ���� X
				return -1;
			mix2 = pq.top();
			pq.pop();
			pq.push(mix1 + (mix2 * 2));
			itr++;
		}
	}

	return itr;
}