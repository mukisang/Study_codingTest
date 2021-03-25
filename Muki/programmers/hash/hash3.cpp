#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

map <string, int> Cmap;
int solution(vector<vector<string>> clothes) {
	int answer = 0;

	for (const auto v : clothes) {
		Cmap[v[1]]++;
	}

	int tmp = 1;
	for (const auto index : Cmap)
		tmp *= (index.second + 1);
	answer += tmp;


	return answer - 1;
}