#include <iostream>
#include <algorithm>

using namespace std;

int arr[3];
int sum = 0;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 3; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	if (sum >= 100) cout << "OK" << endl;
	else {
		if (arr[0] < arr[1] && arr[0] < arr[2]) cout << "Soongsil" << endl;
		else if(arr[1] < arr[0] && arr[1] < arr[2]) cout << "Korea" << endl;
		else cout << "Hanyang" << endl;
	}
}