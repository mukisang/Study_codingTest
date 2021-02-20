#include <string>
#include <vector>
//너무 더럽게 품 다시 풀 예정
#include <algorithm>
#include <iostream>
#include <queue>


using namespace std;

void dfs(string current, vector<vector<string>>& tickets, vector<bool>& check, vector<string>& stack, int& cnt, vector<string>& answer)
{
	for (int i = 0; i < tickets.size(); i++)
	{
		if (!check[i] && tickets[i][0] == current)//다음 티켓 고르기
		{
			stack.push_back(tickets[i][1]);
			check[i] = true;
			dfs(tickets[i][1], tickets, check, stack, ++cnt, answer);
			check[i] = false;
			stack.pop_back();
			cnt--;
		}
	}
	if (cnt == tickets.size())//종료
	{

		bool flag = false;
		if (answer.size() == 1)
		{
			for (int i = 0; i < cnt; i++)
			{
				answer.push_back(stack[i]);
			}
		}
		else
		{
			for (int i = 0; i < cnt; i++)
			{
				if (answer[i + 1] > stack[i])
					flag = true;
				else if (answer[i + 1] < stack[i])
					flag = false;
				else
					continue;
				break;
			}
			if (flag)//바꿔야 함
			{
				for (int i = 0; i < cnt; i++)
				{
					answer[i + 1] = stack[i];
				}
			}
		}
	}

}

vector<string> solution(vector<vector<string>> tickets) {
	vector<string> answer;
	vector<string> stack;
	int cnt = 0;
	vector<bool> check(tickets.size());
	answer.push_back("ICN");
	dfs("ICN", tickets, check, stack, cnt, answer);


	return answer;
}