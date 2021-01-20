#include <string>
#include <vector>
#include <iostream>


using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	vector<int> day;
	for (int i = 0; i < progresses.size(); i++)
		day.push_back((100 - progresses[i] + speeds[i] - 1) / speeds[i]);

	int st = 1;
	int max = day[0];

	for (int i = 1; i < progresses.size(); i++)
	{
		if (day[i] <= max)//½×±â
		{
			st++;
			continue;
		}
		answer.push_back(st);//release
		max = day[i];
		st = 1;
	}
	answer.push_back(st);


	return answer;
}