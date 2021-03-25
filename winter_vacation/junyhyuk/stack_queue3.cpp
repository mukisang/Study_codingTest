#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int time1 = 0;

void example(int weight, int &qweight, int bridge_length, vector<int> truck_weights, int i, queue<pair<int, int>>& q) {
	
	if (weight >= (qweight + truck_weights[i]) && q.size() <= bridge_length) {
			time1++;	

			if (!q.empty()) {
				
				if (time1 == (q.front().first + bridge_length)) {
	            	qweight -= q.front().second;
					q.pop();
				}
			}
			q.push({ time1, truck_weights[i] });
		
			qweight += truck_weights[i];

	}
	else {
		
		time1 = q.front().first + bridge_length;
		qweight -= q.front().second;

		q.pop();
		time1--;
		example(weight, qweight, bridge_length, truck_weights, i, q);
	}

}

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;
	int qweight = 0;   //queue의 전체 무게
	queue<pair<int, int>> q;
	
    //마지막 트럭까지 다리를 지나가게 함
	for (int i = 0; i < truck_weights.size(); i++){
		example(weight, qweight, bridge_length, truck_weights, i, q);
	}

    
    //다리가 깨끗해질때까지
	while (!q.empty()) {
		
		while ((q.front().first + bridge_length) != time1) {
			time1++;
		}
		q.pop();
	}
	answer = time1;
	return answer;
}