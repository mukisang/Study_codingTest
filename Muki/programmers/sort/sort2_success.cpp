#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(int a, int  b)
{
	string tmpA = to_string(a) + to_string(b);
	string tmpB = to_string(b) + to_string(a);

	if (stoi(tmpA) > stoi(tmpB))
		return true;
	else
		return false;

}

string solution(vector<int> numbers) {
	string answer = "";
	
	sort(numbers.begin(), numbers.end(), compare);

	for (auto& n : numbers)
		answer += to_string(n);

	if (answer[0] == '0')
		answer = "0";

	return answer;
}