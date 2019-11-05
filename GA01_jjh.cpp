#include<iostream>
using namespace std;

int main(void)
{
	int input;    //N명
	cin >> input;

	int P[input];

	int input2;
	for (int i = 0; i < input; i++)
	{
		cin >> input2;
		P[i] = input2;
	}

	int temp;

	for (int j = 0; j < input; j++)
	{
		for (int i = j + 1; i < input; i++)
		{
			if (P[j] > P[i])
			{
				temp = P[j];
				P[j] = P[i];
				P[i] = temp;
			}
		}
	}

	for (int i = 0; i < input; i++)
	{
		cout << P[i];
		cout << endl;
	}

	int array[input];
	for (int j = 0; j < input; j++)
	{
		array[j] = 0;
		for (int i = 0; i <= j; i++)
		{
			array[j] += P[i];
		}
	}

	for (int i = 0; i < input; i++)
	{
		cout << array[i];
		cout << endl;
	}

	int result = 0;
	for (int i = 0; i < input; i++)
	{
		result += array[i];
	}
	cout << "결과 값은 : " << result << endl;
	return 0;
}
