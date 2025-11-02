#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string s, ret;
int cnt[200], flag;
char mid;

int main() 
{
	cin >> s;
	for (char a : s)
		cnt[a]++;
	for (int i = 'Z'; i >= 'A'; i--)
	{
		if (cnt[i])
		{
			if (cnt[i] & 1) // 홀수인 경우 % 2 == 1 과 같음
			{
				mid = char(i);
				flag++;
				cnt[i]--; // 미드를 뽑았기 때문에 짝수로 만듬 -> 밑에서 붙이기 위함
			}
			if (flag == 2) // 홀수가 2개 이상
				break;
			for (int j = 0; j < cnt[i]; j += 2) // 앞뒤로 붙이기 때문에 2씩 증가
			{
				ret = char(i) + ret; // 앞에 붙이고
				ret += char(i); // 뒤에 붙이고
			}
		}

	}
	if (mid)
		ret.insert(ret.begin() + ret.size() / 2, mid); // 중앙에 mid를 넣음
	if (flag == 2)
		cout << "I'm Sorry Hansoo";
	else
		cout << ret;
	return 0;
}