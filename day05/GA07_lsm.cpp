/*
작성코드 : 그리디 알고리즘 대회 or 인턴
작성자 : 이상묵
작성일 : 2019-12-18
*/
#include<iostream>
using namespace std;
int main() {
	int N = 0, M = 0, K = 0, result = 0;
	cin >> N >> M >> K;
	if (N >= 2 * M)
	{
		K -= N - (2 * M);
		result = M;
	}
	else
	{
		K -= M - (N/2)+N%2;
		result = N / 2;
	}
	if (K > 0)
	{
		if (K % 3 == 0)result -= (K / 3);
		else result -= ((K / 3) + 1);
	}
	cout << "정답" << result << endl;
}