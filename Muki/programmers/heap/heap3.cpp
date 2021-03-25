#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

vector<int> solution(vector<string> operations) {
	priority_queue<int, vector<int>> pq1;
	priority_queue<int, vector<int>, greater<int>> pq2;
	int length = 0;
	vector<int> answer;
	for (const auto opr : operations)
	{
		if (!length)
		{
			pq1 = priority_queue <int, vector<int>>();
			pq2 = priority_queue <int, vector<int>, greater<int>>();
		}
		char ch = opr[0];
		int num = stoi(opr.substr(2, opr.length()));
		if (ch == 'I')
		{
			pq1.push(num);
			pq2.push(num);
			length++;
		}
		else
		{
			if (length == 0)
				continue;
			if (num < 0)//작은 수 삭제
			{
				length--;
				pq2.pop();
			}
			else
			{
				length--;
				pq1.pop();
			}
		}
	}
	if (length)
	{
		answer.push_back(pq1.top());
		if (length == 1)
			answer.push_back(pq1.top());
		else
			answer.push_back(pq2.top());
	}
	else
		answer = { 0, 0 };
	return answer;
}