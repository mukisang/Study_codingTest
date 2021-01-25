#include <string>
#include <vector>
#include <math.h>

using namespace std;

vector<int> solution(int brown, int yellow) {
	vector<int> answer;
	int mPn = (brown - 4) / 2;
	int mMn = yellow;
	int mNn = sqrt(mPn * mPn - (4 * mMn));


	int m = max((mPn + mNn) / 2, mPn - ((mPn + mNn) / 2));
	int n = mPn - m;

	answer.push_back(m + 2);
	answer.push_back(n + 2);


	return answer;
}