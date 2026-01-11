#include <iostream>

using namespace std;

int main() {

	int n;

	cin >> n;



	int sum = 0 , n1,result;

	for (int i = 0; i < n; i++)

	{

		cin >> n1;

		

		result = n1 * (i + 1) - sum;

		cout  << result << "\n";

		sum =sum + result;

	}

}