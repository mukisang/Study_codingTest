#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string number, int k) {
	string answer = "";
	int minIndex = 0;
	int length = number.length();
	if (length == 1)
		return number;


	while (k)
	{
		for (int i = 0; i < length - 1; i++)
		{
			if (number[i] < number[i + 1])
			{
				minIndex = i;
				break;
			}
			minIndex = length - 1;
		}
		number.erase(minIndex, 1);
		k--;
	}



	return number;
}