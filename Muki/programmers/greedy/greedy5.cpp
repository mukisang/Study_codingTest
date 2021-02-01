#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(vector<int>& a, vector<int>& b)
{
	if (a[2] < b[2])
		return true;
	else
		return false;
}

int getParent(int node, vector<int>& check) {
	if (check[node] == node) return node;
	return getParent(check[node], check);
}

//부모 연결
void unionParent(int node1, int node2, vector<int>& check) {
	node1 = getParent(node1, check);
	node2 = getParent(node2, check);
	if (node1 < node2) check[node2] = node1;
	else check[node1] = node2;
}

//싸이클이 존재하면 true, 아니면 false를 반환
bool isCycle(int node1, int node2, vector<int>& check) {
	node1 = getParent(node1, check);
	node2 = getParent(node2, check);
	if (node1 == node2) return true;
	else return false;
}



int solution(int n, vector<vector<int>> costs) {
	int answer = 0;
	vector<int> check(costs.size());

	sort(costs.begin(), costs.end(), compare);

	for (int i = 0; i < n; i++)
		check[i] = i;

	for (int i = 0; i < costs.size(); ++i) {
		//싸이클이 존재하지 않으면 비용을 더합니다. 
		if (!isCycle(costs[i][0], costs[i][1], check)) {
			answer += costs[i][2];
			unionParent(costs[i][0], costs[i][1], check);
		}
	}

	return answer;
}