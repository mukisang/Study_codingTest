#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b)
{
	if (a.second > b.second)
		return true;
	else
		return false;
}

bool compare2(const pair<string, int> a, const pair<string, int>& b)
{
	if (a.second > b.second)
		return true;
	else
		return false;
}


vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	map<string, vector<pair<int, int>>> songs;
	map<string, int> genre;
	for (int i = 0; i < plays.size(); i++)
	{
		songs[genres[i]].push_back(make_pair(i, plays[i]));
		genre[genres[i]] += plays[i];//장르 많은 순
	}
	//map 내부 vector sorting
	for (auto& s : songs)
	{
		sort(s.second.begin(), s.second.end(), compare);
	}

	vector<pair<string, int>> tmp(genre.begin(), genre.end());
	sort(tmp.begin(), tmp.end(), compare2);

	for (const auto& t : tmp)
	{
		if (songs[t.first].size() == 1)
			answer.push_back(songs[t.first].at(0).first);
		else {
			answer.push_back(songs[t.first].at(0).first);
			answer.push_back(songs[t.first].at(1).first);
		}
	}

	return answer;
}