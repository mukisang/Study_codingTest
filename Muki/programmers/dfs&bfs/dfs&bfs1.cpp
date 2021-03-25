//Å¸°Ù ³Ñ¹ö
#include <string>
#include <vector>

using namespace std;

void dfs(vector<int>& numbers, int cursor, int target, int& answer)
{
	if (cursor >= numbers.size())
	{
		if (target == 0) answer++;
		return;
	}
	dfs(numbers, cursor + 1, target - numbers[cursor], answer);
	dfs(numbers, cursor + 1, target + numbers[cursor], answer);
}


int solution(vector<int> numbers, int target) {
	int answer = 0, cursor = 0;
	dfs(numbers, cursor, target, answer);
	return answer;
}