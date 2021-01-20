#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(string& a, string& b)
{
	int sizeA = a.length();
	int sizeB = b.length();
	char tmpA, tmpB;
	int size = sizeA > sizeB ? sizeA : sizeB;
	//cout << "a : "<< a <<" b : "<<b<<"size : "<<size <<endl;
	for (int i = 0; i < size; i++)
	{

		if (i > sizeA - 1)
		{
			tmpA = a[0];
			tmpB = b[i];
		}
		else if (i > sizeB - 1)
		{
			tmpA = a[i];
			tmpB = b[0];
		}
		else
		{
			tmpA = a[i];
			tmpB = b[i];
		}
		//cout << "comp A : "<<tmpA<<" comp B : "<<tmpB<<endl;
		if (tmpA > tmpB)
			return true;
		else if (tmpA < tmpB)
			return false;
		else
			continue;
	}
	return false;
}

string solution(vector<int> numbers) {
	string answer = "";
	vector<string> nums;
	for (auto& v : numbers)
		nums.push_back(to_string(v));

	sort(nums.begin(), nums.end(), compare);

	for (auto& n : nums)
		answer += n;

	if (answer[0] == '0')
		answer = "0";

	return answer;
}