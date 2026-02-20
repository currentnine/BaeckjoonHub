#include<iostream>
using namespace std;

long long int f[51];
int main(void) {
	f[0] = 1;
	f[1] = 1;
	int n;
	cin >> n;
	for (int i = 2; i <= 50; i++) {
		f[i] = f[i - 2] + f[i - 1] + 1;
	}
	cout << f[n] % 1000000007;
	return 0;
}