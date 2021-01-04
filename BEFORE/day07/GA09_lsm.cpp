#include <iostream>
#include<string>
using namespace std;


int check_str(string s1, string s2)
{
	int cnt = 0;
	for(int i=0;i<s2.length();i++)
	{
		if (s1.at(i) == s2.at(i))
			cnt++;
	}
	return cnt;
}

int diff(string s1, string s2)
{
	int lgth1 = s1.length(), lgth2 = s2.length();
	int biggest=0,temp;
	for (int i = 0;i<=lgth2-lgth1;i++)
	{
		temp = check_str(s1, s2.substr(i, lgth1));
		if (temp >= biggest)
		{
			biggest = temp;
		}
	}
	return lgth1-biggest;
}



int main()
{
	string s1, s2;
	cout << "Insert s1 : ";
	cin >> s1;
	cout << "insert s2 : ";
	cin >> s2;
	int result = diff(s1, s2);
	cout << "result : " << result;



	return 0;
}