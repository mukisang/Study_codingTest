#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 0;

	vector<int> array;  //최종 출력 순서를 담은 벡터

	int rem1, rem2, count = 0;
	queue<pair<int, int>> q;
	for (int i = 0; i < priorities.size(); i++) {
		q.push({i,priorities[i] });
	}
	while (!q.empty()) {
		count = 0;
		rem1 = q.front().first;
		rem2 = q.front().second;
		q.push(make_pair(q.front().first, q.front().second));
 		q.pop();
		
		while(rem1 != q.front().first){
			if (q.front().second > rem2) {
				count++;
			}
			q.push(make_pair(q.front().first, q.front().second));
			q.pop();
		}
		//count가 1이상이라는 의미는 queue에 더 큰 우선순윌르 가진 원소가 있다는 뜻
		if (count >= 1) {
			q.push(make_pair(q.front().first, q.front().second));
			q.pop();
			
		}
		else {	
			array.push_back(q.front().first);
			q.pop();
		}
	}

	for (int i = 0; i < array.size(); i++) {
		if (location == array[i]) {
			answer = i + 1;
			break;
		}
	}

	return answer;
}