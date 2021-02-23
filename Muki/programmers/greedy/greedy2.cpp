#include <string>
#include <vector>
#include <iostream>

using namespace std;
int solution(string name) {
	int answer = 0, ck = 0, ckF = 0, ckE = 0, tmp = 0;
	int i = 0;
	while (true)
	{
		if (ck == name.length())
			break;
		if (name[i] != 'A')  //A로 바꾸는 과정
		{
			tmp = (int)name[i] - (int)'A';
			answer += min(tmp, 26 - tmp);
			name[i] = 'A';
			ck++;
		}
		else
			ck++;

		int cur = i;
		ckF = 0; ckE = 0;

		do
		{
			if (cur == name.length() - 1)
				cur = -1;
			ckF++;
			cur++;
			if (cur == i)
				return answer;
		} while (name[cur] == 'A');//앞 부터 탐색
		cur = i;

		do
		{
			if (cur == 0)
				cur = name.length();
			ckE++;
			cur--;
			if (cur == i)
				return answer;
		} while (name[cur] == 'A');//뒤 부터 탐색

		if (ckF > ckE)
			i--;
		else
			i++;

		if (i == -1)
			i = name.length() - 1;
		else if (i == name.length())
			i = 0;
		answer++;
	}


	return answer;
}

