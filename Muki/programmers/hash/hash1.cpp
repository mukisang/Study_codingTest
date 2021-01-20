#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	map<string, int> Pmap;
	vector<string>::iterator itr = participant.begin();
	map<string, int>::iterator itr2;
	//처음 map에 삽입
	for (; itr != participant.end(); itr++)
	{
		
		if (Pmap.find(*itr) == Pmap.end())//없는 경우
		{
			Pmap.insert({ (*itr),1 });
		}
		else//있는 경우
		{
			Pmap[(*itr)] += 1;
		}
	}
	//map에서 추출
	for (itr = completion.begin(); itr != completion.end(); itr++)
	{
		if (Pmap[(*itr)] == 1)
		{
			Pmap.erase((*itr));
		}
		else
		{
			Pmap[(*itr)] -= 1;
		}
	}
	//남은거 반환
	for (itr2 = Pmap.begin(); itr2 != Pmap.end(); itr2++)
	{
		answer += itr2->first;
	}

	return answer;
}