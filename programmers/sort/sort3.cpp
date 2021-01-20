#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


int solution(vector<int> citations) {
	int answer = 0, length = citations.size(), h = 0;
	sort(citations.begin(), citations.end());

	for (int i = 0; i < length; i++)
	{
		if (citations[i] > length - i)
			h = max(h, length - i);
		else
			h = max(h, citations[i]);
	}

	answer = h;

	return answer;
}