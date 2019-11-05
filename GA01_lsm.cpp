//날짜: 2019-10-30
//작성자 이상묵
//그리디 알고리즘: ATM 

#include <iostream>
#include <stdlib.h>
using namespace std;

int compare(const void *a, const void *b)
{
	int num1 = *(int*)a;
	int num2 = *(int*)b;
	if (num1 > num2)
		return 1;
	else if (num1 < num2)
		return -1;
	else
		return 0;
}

int main() {

	string intro = "사람 수를 입력하세요.(1<=N<=1000) ";
	string intro2 = "각 사람의 인출시간을 띄어쓰기를 기준으로 입력하세요.";
	int pNum = 0;
	cout << intro;
	cin >> pNum;
	//배열 선언
	int *ar=new int[pNum];
	cout << intro2;
	for (int i = 0; i < pNum; i++)
	{
		cin >> ar[i];
	}
	//정렬
	qsort(ar, pNum, sizeof(int), compare);
	
	int result = 0;
	for (int i = 0; i < pNum; i++)
	{
		result += (pNum-i)*ar[i];
	}
	cout << result;
	return 0;
}