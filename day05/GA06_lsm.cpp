/* 
작성자 : 이상묵
작성일 : 2019-12-18
*/
#include <iostream>
#include<algorithm>

using namespace std;

int main() {
	//수를 받는 과정
	int num=0,result=0;
	do{
		cout << "수 입력";
		cin >> num;
		if (num <= 0)
		{
			cout << "범위 오류입니다."<<endl;
			num = 0;
		}
	} while (!num);
	cout << "N : " << num << endl;

	//받은 수의 자리수만큼의 배열 할당
	int length = 0, temp=num;
	while (temp)
	{
		temp = temp / 10;
		length++;
	}
	int* ar = new int[length];
	for (int i = 0; i < length; i++)
	{
		ar[i] = num % 10;
		num /= 10;
	}
	        
	//받은 숫자가 30의 배수가 맞나 판단하는 과정.
	sort(ar, ar + length, greater<int>());
	for (int i = 0; i < length; i++)
	{
		result *= 10;
		result += ar[i];
	}
	if (!(result/30))result = -1;
	
	//정답 출력
	cout << "정답은 " << result << endl;
}