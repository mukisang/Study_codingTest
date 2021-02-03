#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include<utility>
using namespace std;

bool compare(pair<int,int> a, pair<int, int> b) {
	
	if (a.first == b.first) {
		return a.second < b.second;
	}
	else {
		return a.first > b.first;
	}
}

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;

	unordered_map<string, int> gen;
	unordered_multimap<string, vector<int>> gmap;
	for (int i = 0; i < genres.size(); i++) {
		gmap.insert({ genres[i], {plays[i], i} });
		gen[genres[i]] += plays[i];
	
	}
	
	vector<pair<int, string>> reverse;
	for (auto x : gen) {
		reverse.push_back(make_pair(x.second, x.first));
	}
	sort(reverse.rbegin(), reverse.rend());
	

	
	for (auto i : reverse) {
		auto its = gmap.equal_range(i.second);
		
		
		vector<pair<int, int>> temp;
		for (auto it = its.first; it != its.second; ++it) {
			temp.push_back({ it->second[0], it->second[1] });
	
		sort(temp.begin(), temp.end(), compare);  //내림차순
	

		if (temp.size() == 1) { 
			answer.push_back(temp[0].second);
		}
		else {
			
			answer.push_back(temp[0].second);
			answer.push_back(temp[1].second);
		}
		
	}

	return answer;
}