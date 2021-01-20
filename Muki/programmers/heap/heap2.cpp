//ºÐ¼® ÇÊ

#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;
using piii = pair<int, pii>;
using vi = vector<int>;
int solution(vector<vector<int>> jobs) {
	int answer = 0;
	int cur = 0;
	size_t length = jobs.size();
	sort(jobs.begin(), jobs.end(), [](const vi& a, const vi& b) -> bool {
		return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
		});
	priority_queue<pii> pq;
	for (int i = 0; i < length; ++i) {
		while (!pq.empty() && cur < jobs[i][0]) {
			pii f = pq.top(); pq.pop();
			cur = max(cur, f.second) - f.first;
			answer += cur - f.second;
		}
		pq.push({ -jobs[i][1], jobs[i][0] });
	}
	while (!pq.empty()) {
		pii f = pq.top(); pq.pop();
		cur = max(cur, f.second) - f.first;
		answer += cur - f.second;
	}
	return answer / length;
}