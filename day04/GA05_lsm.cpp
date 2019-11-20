#include <iostream>
#include<algorithm>
using namespace std;

int main() {
	int n = 0, sum=0, ck=0, tp=0;
	cout << "로프수를 입력하세요" << endl;
	cin >> n;
	int* tmp = new int[n];
	
	for (int i = 0; i < n; i++)
	{
		cin >> tmp[i];
		sum += tmp[i];
	}
	
	//로프를 작은 순서대로 정렬한다.
	sort(tmp,tmp+n,greater<int>());
	//무게/개수로 분기점을 정한다.
	double check = (double)sum / n;
	for (int i = 0; i < n; i++)
	{
		if (tmp[i] >= check)
		{
			ck++;
			tp = tmp[i];
		}

	}

	cout << "최대로 들을 수 있는 무게: " <<tp*ck<<endl;






}