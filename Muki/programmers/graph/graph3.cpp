#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

using pii = pair<int, int>;

pii move(pii cur, int d)
{
	if (d == 0)
		cur = { cur.first, cur.second + 1 };
	else if (d == 1)
		cur = { cur.first + 1, cur.second + 1 };
	else if (d == 2)
		cur = { cur.first + 1, cur.second };
	else if (d == 3)
		cur = { cur.first + 1, cur.second - 1 };
	else if (d == 4)
		cur = { cur.first, cur.second - 1 };
	else if (d == 5)
		cur = { cur.first - 1, cur.second - 1 };
	else if (d == 6)
		cur = { cur.first - 1, cur.second };
	else if (d == 7)
		cur = { cur.first - 1, cur.second + 1 };

	return cur;
}

int check_cross(pii cur, int dir, map<pair<pii, pii>, int>& edge)
{

	if (dir == 1 && (edge[{ {cur.first, cur.second + 1}, { cur.first + 1, cur.second }}] == 1 || edge[{ {cur.first + 1, cur.second}, { cur.first, cur.second + 1 }}] == 1))
		return 1;

	else if (dir == 3 && (edge[{ {cur.first + 1, cur.second}, { cur.first, cur.second - 1 }}] == 1 || edge[{ {cur.first, cur.second - 1}, { cur.first + 1, cur.second }}] == 1))
		return 1;
	else if (dir == 5 && (edge[{ {cur.first - 1, cur.second}, { cur.first, cur.second - 1 }}] == 1 || edge[{ {cur.first, cur.second - 1}, { cur.first - 1, cur.second }}] == 1))
		return 1;
	else if (dir == 7 && (edge[{ {cur.first, cur.second + 1}, { cur.first - 1, cur.second }}] == 1 || edge[{ {cur.first - 1, cur.second}, { cur.first, cur.second + 1 }}] == 1))
		return 1;
	return 0;
}

int solution(vector<int> arrows) {
	int answer = 0;
	pii cur = { 0, 0 };
	map<pair<pii, pii>, int> edge;
	map<pii, int> point;
	point[{0, 0}] = 1;
	for (int i = 0; i < arrows.size(); i++)
	{
		pii nextP = move(cur, arrows[i]);
		// cout << "현재 {"<<cur.first<<", "<<cur.second<<"}"<<endl;
		if (point[nextP] == 1 && (edge[{cur, nextP}] != 1))//이미 지난 점 지남 && 같은 edge가 아님 => 도형 생성
			answer++;
		if ((arrows[i] == 1 || arrows[i] == 3 || arrows[i] == 5 || arrows[i] == 7) && (edge[{cur, nextP}] != 1))
			answer += check_cross(cur, arrows[i], edge);

		edge[{cur, nextP}] = 1;//이동 edge 넣기
		edge[{nextP, cur}] = 1;
		point[nextP] = 1;
		cur = nextP;
	}

	// for(auto e : edge)
	// {
	//     cout << "{"<<e.first.first<<", "<<e.first.second<<"} -> "<<"{"<<e.second.first<<", "<<e.second.second<<"}"<<endl;
	// }
	// for(auto &p : point)
	// {
	//     cout << "{"<<p.first.first<<", "<<p.first.second<<"}"<<endl;
	// }



	return answer;
}