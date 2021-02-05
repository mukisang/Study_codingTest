#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;

	
	queue<int> q;

	int size = progresses.size();
	for(int i = 0; i < progresses.size(); i++)
		if ((100 - progresses[i]) % speeds[i] == 0) {
			q.push((100 - progresses[i]) / speeds[i]);
		}
		else {
			q.push(((100 - progresses[i]) / speeds[i]) + 1);
		}

	while (!q.empty()) {
		int count = 1;
		auto temp = q.front();
		q.pop();
		
		while (!q.empty() && temp >= q.front()) {
			q.pop();
			count++;
		}
		answer.push_back(count);
		
	}


	return answer;
}