#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> answers) {
	vector<int> answer;
	vector<int> p1 = { 1, 2, 3, 4, 5 };
	vector<int> p2 = { 2, 1, 2, 3, 2, 4, 2, 5 };
	vector<int> p3 = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
	int length = answers.size();
	vector<int> score(3);
	int tmp = 0;
	for (int i = 0; i < length; i++)
	{
		tmp = answers[i];
		//1¹ø
		if (tmp == p1[i % 5])
			score[0] ++;
		//2¹ø
		if (tmp == p2[i % 8])
			score[1] ++;
		//3¹ø
		if (tmp == p3[i % 10])
			score[2] ++;
	}
	int maxScore = *max_element(score.begin(), score.end());
	for (int i = 0; i < 3; i++)
	{
		if (maxScore == score[i])
			answer.push_back(i + 1);
	}

	return answer;
}