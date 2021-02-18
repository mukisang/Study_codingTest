#include <string>
#include <vector>
#include <algorithm>
#include <iostream>


using namespace std;
using ull = unsigned long long;




ull solution(int n, vector<int> times) {
	ull time;
	ull s = 0, l = 0, mid = 0;
	ull cnt = 0;
	sort(times.begin(), times.end());
	s = 1;
	l = times[times.size() - 1] * n;
	time = l;
	//cout << s <<endl;
	while (s <= l)
	{
		cnt = 0;
		mid = (s + l) / 2;
		//cout << "mid : "<<mid <<endl;
		for (auto per : times)
			cnt += mid / per;
		if (cnt < n)//ÃæºÐ
			s = mid + 1;
		else
		{
			l = mid - 1;
			time = min(time, mid);
		}

	}


	return time;
}