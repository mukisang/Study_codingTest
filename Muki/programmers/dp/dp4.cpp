#include <string>
#include <vector>

using namespace std;
using lld = long long;

vector<lld> dp[2];
vector<bool> visited[2];

lld getDP(vector<int>& money, int check, int idx) {
	if (idx >= money.size()) return 0;
	if (visited[check][idx]) return dp[check][idx];
	visited[check][idx] = true;
	if (idx == money.size() - 1) {
		if (!check) dp[check][idx] = money[money.size() - 1];
		else dp[check][idx] = 0;
		return dp[check][idx];
	}
	dp[check][idx] = max(getDP(money, check, idx + 2) + money[idx],
		getDP(money, check, idx + 1));
	return dp[check][idx];
}
int solution(vector<int> money) {
	dp[0].assign(money.size(), 0);
	dp[1].assign(money.size(), 0);
	visited[0].assign(money.size(), false);
	visited[1].assign(money.size(), false);
	int answer = max(getDP(money, 1, 0), getDP(money, 0, 1));
	return answer;
}
