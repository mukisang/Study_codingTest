#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
	int answer = 0, cursor = people.size() - 1;
	vector<int> check(people.size());
	sort(people.begin(), people.end());


	int i = 0;
	while (cursor > i)
	{
		if (people[i] + people[cursor] <= limit)
			i++;
		answer++;
		cursor--;
	}
	if (cursor == i)
		answer++;


	return answer;
}