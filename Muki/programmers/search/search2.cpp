#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

bool is_prime(int a)
{
	if (a == 0 || a == 1)
		return false;
	else if (a == 2)
		return true;
	for (int i = 2; i < a; i++)
	{
		if (a % i == 0)
			return false;
	}
	return true;
}

int pick_card(int num, vector<int>& nums, set<int>& set)
{
	vector<int> tmp;
	int length = nums.size();
	int result = 0;
	do {
		int number = 0;
		for (int i = 0; i < length - num; i++)
		{
			number *= 10;
			number += nums[i];
		}

		if (is_prime(number))
			set.insert(number);

	} while (next_permutation(nums.begin(), nums.end()));
	return result;
}


int solution(string numbers) {
	int answer = 0, check = 0;
	vector<int> nums;
	set<int> s;
	for (int i = 0; i < numbers.length(); i++)
		nums.push_back((int)numbers[i] - 48);
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size(); i++)
		pick_card(i, nums, s);


	return s.size();
}