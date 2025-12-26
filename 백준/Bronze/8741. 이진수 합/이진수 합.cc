#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int K; cin >> K;
	for (int i = 0; i < K; i++) cout << '1';
	for (int i = 1; i < K; i++) cout << '0';
}