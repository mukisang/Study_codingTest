#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

bool compare(string a, string b)
{
	if (a.length() >= b.length())
		return false;
	else
		return true;
}

bool solution(vector<string> phone_book) {
	bool answer = true;
	map<string, string> mmap;
	string key, value;
	map<string, string>::iterator itr;

	sort(phone_book.begin(), phone_book.end(), compare);
	int keyLen = phone_book[0].length();
	//�ϳ��� �ִ� ����
	for (auto const t : phone_book)
	{
		key = t.substr(0, keyLen);
		value = t.substr(keyLen);
		itr = mmap.find(key);
		if (!(itr == mmap.end()) && (!itr->second.compare(value.substr(0, itr->second.length()))))//Ű �� �ߺ�
			return false;
		else//Ű�� �ߺ�X
			mmap.insert({ key,value });

	}


	return answer;
}