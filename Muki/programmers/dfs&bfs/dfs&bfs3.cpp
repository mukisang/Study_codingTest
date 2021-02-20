#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool comparing(string a, string b)
{
	int cnt = 0;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] != b[i])
			cnt++;
	}
	if (cnt == 1)
		return true;
	else
		return false;
}

void dfs(string current, string target, vector<string>& words, vector<bool>& check, int cnt, int& answer)
{

	for (int i = 0; i < words.size(); i++)//단어 판별
	{
		if (!check[i] && comparing(words[i], current))//다음 이동 단어
		{
			check[i] = true;
			if (words[i] == target)//답 찾음
			{
				answer = min(++cnt, answer);
				check[i] = false;
				continue;
			}
			cnt++;
			dfs(words[i], target, words, check, cnt, answer);
			cnt--;
			check[i] = false;
		}
	}


}
int solution(string begin, string target, vector<string> words) {
	int answer = 51, cnt = 0;
	vector<bool> check(words.size());
	dfs(begin, target, words, check, cnt, answer);

	if (answer == 51)
		answer = 0;
	return answer;
}