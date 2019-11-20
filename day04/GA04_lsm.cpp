#include <iostream>
/*
	작성자: 이상묵
	작성일: 2019-11-20
*/
using namespace std;
int main()
{

	int price = 0, ck = 0;
	int coin_count = 0;
	int co[6] = { 1,5,10,50,100,500 };
	cout << "가격을 입력하세요";
	cin >> price;

	if (price < 1 || price>1000)
		return 0;
	price = 1000 - price;


	//가장 가까운 동전 찾는 과정
	for (int i = 0; i < 6; i++)
	{
		if (co[i] - price > 0)
		{
			break;
		}
		ck = i;
	}
	//동전개수 연산과정
	for (int i = 5; i >= 0; i--)
	{
		coin_count += price / co[i];
		cout << co[i] << "원짜리 " << price / co[i] << "개 //현재 코인수" << coin_count << endl;
		price %= co[i];
		if (price == 0)break;
	}



	cout << "총 동전의 갯수: " << coin_count << endl;
	return 0;
}