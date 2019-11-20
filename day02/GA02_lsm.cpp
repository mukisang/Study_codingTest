#include <iostream>
/*
	작성자: 이상묵
	작성일: 2019-11-06
*/
using namespace std;
int main()
{
	
	int price = 0, ck=0;//cn 은 동전의 갯수 price는 가치의 합, ck는 check변수
	int coin_count = 0;
	/*cn = 10; price = 28495;*/
	int co[6] = { 1,5,10,50,100,500};

	//값을 입력받는 과정 범위 내가 아닐 경우 프로그램 종료
	cin >> price;

	if (price < 1 || price>1000)
		return 0;
	//아래 지폐를 찾지 못할때 즉 가장 큰 동전보다 클때 가장 큰 동전으로 초기값 설정
	price = 1000 - price;
	
	
	//가장 가까운 지폐 찾는 과정
	for (int i = 0; i < 6; i++)
	{
		if (co[i] - price > 0)
		{
			ck = i;
			break;
		}
	}
	//동전개수 연산과정
	for (int i = ck;i>=0; i--)
	{
		coin_count += price / co[i];
		cout << co[i] << "원짜리 "<< price / co[i]<< "개 //현재 코인수" << coin_count << endl;
		price %= co[i];
		if (price == 0)break;
	}
	
	

	cout << "총 동전의 갯수: " << coin_count << endl;
	return 0;
}